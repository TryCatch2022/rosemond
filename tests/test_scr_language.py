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
        self.assertEqual(script.global_count, 8)
        self.assertEqual(len(script.descriptors), 1)
        self.assertEqual(scr_language.compile_source(scr_language.render_source(binary)), binary)

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


if __name__ == "__main__":
    unittest.main()