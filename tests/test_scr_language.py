import struct
import unittest
from pathlib import Path

import scr_language
import scrtool


ROOT = Path(__file__).resolve().parents[1]


class ScriptLanguageTests(unittest.TestCase):
    def test_existing_scripts_round_trip_exactly(self):
        paths = sorted((ROOT / "gameScripts").glob("*.scr"))
        self.assertGreaterEqual(len(paths), 1)
        for path in paths:
            with self.subTest(script=path.name):
                binary = path.read_bytes()
                source = scr_language.render_source(binary)
                self.assertEqual(scr_language.compile_source(source), binary)

    def test_expression_precedence_emits_postfix_vm(self):
        source = """ROSEMOND-SCRIPT 1
globals 4
function startup {
    global[3] = global[0] + 2.0 * 3.0;
    return;
}
"""
        binary = scr_language.compile_source(source)
        script = scrtool.decode_binary(binary)
        self.assertEqual(
            [instruction.opcode for instruction in script.instructions],
            [0x06, 0x06, 0x07, 0x07, 0x01, 0x03, 0x05, 0x0B],
        )

    def test_branch_labels_resolve_to_instruction_indices(self):
        source = """ROSEMOND-SCRIPT 1
globals 1
function startup {
    if (global[0] > 0) goto Ldone;
    return;
Ldone:
    return;
}
"""
        script = scrtool.decode_binary(scr_language.compile_source(source))
        branch = script.instructions[1]
        self.assertEqual(branch.opcode, 0x0E)
        self.assertEqual(struct.unpack("<I", branch.payload)[0], 3)

    def test_new_script_has_parseable_function_table(self):
        source = """ROSEMOND-SCRIPT 1
globals 8
function startup {
    global[2] = global[1] + 1.5;
    return;
}
"""
        binary = scr_language.compile_source(source)
        script = scrtool.decode_binary(binary)
        self.assertEqual(script.global_bytes, 32)
        self.assertEqual(len(script.descriptors), 1)
        self.assertEqual(scr_language.compile_source(scr_language.render_source(binary)), binary)

    def test_source_global_count_is_float_slots(self):
        binary = (ROOT / "gameScripts" / "Mainscr.scr").read_bytes()
        script = scrtool.decode_binary(binary)
        source = scr_language.render_source(binary)
        self.assertEqual(script.global_bytes, 360)
        self.assertIn("globals 90\n", source)

    def test_raw_jump_operand_is_not_relocated(self):
        source = """ROSEMOND-SCRIPT 1
globals 0
function first {
    vm.raw 0x0C 02000000;
}
function second {
    return;
}
"""
        script = scrtool.decode_binary(scr_language.compile_source(source))
        self.assertEqual(struct.unpack("<I", script.instructions[0].payload)[0], 2)

    def test_simple_branch_becomes_editable_if_else(self):
        source = """ROSEMOND-SCRIPT 1
globals 2
function startup {
    if (global[0] != 0) goto Lelse;
    global[1] = 1.0;
    goto Lend;
Lelse:
    global[1] = 2.0;
Lend:
    return;
}
"""
        original = scr_language.compile_source(source)
        readable = scr_language.render_source(original)
        self.assertIn("if (global[0] == 0.0) {", readable)
        self.assertIn("} else {", readable)
        edited = readable.replace("global[1] = 1.0;", "global[1] = 3.0;")
        rebuilt = scr_language.compile_source(edited)
        self.assertNotEqual(rebuilt, original)
        self.assertIn("global[1] = 3.0;", scr_language.render_source(rebuilt))

    def test_nested_zero_comparison_is_simplified(self):
        source = """ROSEMOND-SCRIPT 1
globals 4
function startup {
    vm.push global[3];
    vm.push 1.0;
    vm.raw 0x04 -;
    vm.raw 0x09 -;
    vm.raw 0x0D 06000000;
    return;
L6:
    return;
}
"""
        readable = scr_language.render_source(scr_language.compile_source(source))
        self.assertIn("if (global[3] == 1.0) {", readable)
        self.assertNotIn("== 0.0 == 0", readable)


if __name__ == "__main__":
    unittest.main()