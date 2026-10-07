#!/usr/bin/env python3
"""Lossless text decoder/encoder for Rosemond Hill .scr files."""

from __future__ import annotations

import argparse
import math
import re
import shlex
import struct
import sys
from dataclasses import dataclass
from pathlib import Path


DESCRIPTOR_SIZE = 40
MAX_STREAM_HEADER_GAP = 512
MAX_RECORD_COUNT = 100_000
MAGIC = "ROSEMOND-SCR-TEXT 1"

OPCODE_NAMES = {
    0x00: "xor",
    0x01: "multiply",
    0x02: "divide",
    0x03: "add",
    0x04: "subtract",
    0x05: "store.global",
    0x06: "push.u16",
    0x07: "push.f32",
    0x08: "push.text",
    0x10: "call",
}


@dataclass
class Instruction:
    opcode: int
    payload: bytes


@dataclass
class Script:
    global_count: int
    descriptors: list[bytes]
    gap: bytes
    instructions: list[Instruction]


def parse_instruction_stream(data: bytes, count_offset: int) -> tuple[list[Instruction], int] | None:
    if count_offset + 4 > len(data):
        return None

    count = struct.unpack_from("<I", data, count_offset)[0]
    if count > MAX_RECORD_COUNT:
        return None

    cursor = count_offset + 4
    instructions = []
    for _ in range(count):
        if cursor + 3 > len(data):
            return None
        opcode = data[cursor]
        payload_size = struct.unpack_from("<H", data, cursor + 1)[0]
        cursor += 3
        if cursor + payload_size > len(data):
            return None
        instructions.append(Instruction(opcode, data[cursor:cursor + payload_size]))
        cursor += payload_size
    return instructions, cursor


def find_stream(data: bytes, descriptor_end: int) -> tuple[int, list[Instruction]]:
    candidates = []
    last_offset = min(descriptor_end + MAX_STREAM_HEADER_GAP, len(data) - 4)
    for count_offset in range(descriptor_end, last_offset + 1):
        parsed = parse_instruction_stream(data, count_offset)
        if parsed is None:
            continue
        instructions, end = parsed
        if end == len(data) and all(item.opcode <= 0x10 for item in instructions):
            candidates.append((count_offset, instructions))

    if len(candidates) != 1:
        raise ValueError(
            f"expected one counted instruction stream after 0x{descriptor_end:X}; "
            f"found {len(candidates)}"
        )
    return candidates[0]


def descriptor_name(descriptor: bytes) -> tuple[str | None, int]:
    candidates = []
    for match in re.finditer(rb"[\x20-\x7e]{3,}\x00", descriptor):
        raw_name = match.group()[:-1]
        candidates.append((len(raw_name), match.start(), raw_name.decode("ascii")))
    if not candidates:
        return None, -1
    _, offset, name = max(candidates)
    return name, offset


def decode_binary(data: bytes) -> Script:
    if len(data) < 8:
        raise ValueError("file is shorter than the 8-byte script header")

    global_count, function_count = struct.unpack_from("<II", data)
    descriptor_end = 8 + function_count * DESCRIPTOR_SIZE
    if descriptor_end > len(data):
        raise ValueError("function descriptor table extends past end of file")

    descriptors = [
        data[offset:offset + DESCRIPTOR_SIZE]
        for offset in range(8, descriptor_end, DESCRIPTOR_SIZE)
    ]
    count_offset, instructions = find_stream(data, descriptor_end)
    return Script(
        global_count=global_count,
        descriptors=descriptors,
        gap=data[descriptor_end:count_offset],
        instructions=instructions,
    )


def instruction_text(instruction: Instruction) -> str:
    payload = instruction.payload
    if instruction.opcode == 0x06 and len(payload) == 2:
        return f"push.u16 {struct.unpack('<H', payload)[0]}"
    if instruction.opcode == 0x07 and len(payload) == 4:
        value = struct.unpack("<f", payload)[0]
        if not math.isnan(value):
            return f"push.f32 {value!r}"
    if instruction.opcode in (0x08, 0x10) and payload.endswith(b"\x00"):
        value = payload[:-1]
        if all(0x20 <= byte <= 0x7E for byte in value):
            keyword = "push.text" if instruction.opcode == 0x08 else "call"
            return f"{keyword} {shlex.quote(value.decode('ascii'))}"
    if not payload and instruction.opcode in OPCODE_NAMES:
        return OPCODE_NAMES[instruction.opcode]

    return f"raw 0x{instruction.opcode:02X} {payload.hex() or '-'}"


def render_text(script: Script) -> str:
    lines = [
        MAGIC,
        f"header {script.global_count} {len(script.descriptors)}",
        f"gap {script.gap.hex() or '-'}",
    ]
    for index, descriptor in enumerate(script.descriptors):
        name, name_offset = descriptor_name(descriptor)
        name_field = shlex.quote(name) if name is not None else "-"
        lines.append(
            f"function {index} {name_field} {name_offset} {descriptor.hex()}"
        )

    lines.append(f"stream {len(script.instructions)}")
    for instruction in script.instructions:
        lines.append(instruction_text(instruction))
    return "\n".join(lines) + "\n"


def parse_integer(value: str, field: str, maximum: int) -> int:
    try:
        number = int(value, 0)
    except ValueError as error:
        raise ValueError(f"invalid {field}: {value}") from error
    if not 0 <= number <= maximum:
        raise ValueError(f"{field} must be between 0 and {maximum}")
    return number


def parse_text(source: str) -> Script:
    magic_seen = False
    global_count = None
    expected_function_count = None
    gap = None
    expected_instruction_count = None
    descriptors = []
    names = []
    instructions = []

    for line_number, raw_line in enumerate(source.splitlines(), 1):
        try:
            fields = shlex.split(raw_line, comments=True, posix=True)
        except ValueError as error:
            raise ValueError(f"line {line_number}: {error}") from error
        if not fields:
            continue

        if not magic_seen:
            if fields != ["ROSEMOND-SCR-TEXT", "1"]:
                raise ValueError(f"line {line_number}: expected {MAGIC!r}")
            magic_seen = True
            continue

        command = fields[0]
        try:
            if command == "header" and len(fields) == 3:
                global_count = parse_integer(fields[1], "global count", 0xFFFFFFFF)
                expected_function_count = parse_integer(fields[2], "function count", 0xFFFFFFFF)
            elif command == "gap" and len(fields) == 2:
                gap = b"" if fields[1] == "-" else bytes.fromhex(fields[1])
            elif command == "function" and len(fields) == 5:
                index = parse_integer(fields[1], "function index", 0xFFFFFFFF)
                name = None if fields[2] == "-" else fields[2]
                name_offset = int(fields[3], 0)
                descriptor = bytes.fromhex(fields[4])
                if index != len(descriptors):
                    raise ValueError("function descriptors must be sequential")
                if len(descriptor) != DESCRIPTOR_SIZE:
                    raise ValueError(f"descriptor must be {DESCRIPTOR_SIZE} bytes")
                descriptors.append(descriptor)
                names.append((name, name_offset))
            elif command == "stream" and len(fields) == 2:
                expected_instruction_count = parse_integer(fields[1], "stream count", MAX_RECORD_COUNT)
            elif command in ("xor", "multiply", "divide", "add", "subtract", "store.global") and len(fields) == 1:
                opcode = next(code for code, name in OPCODE_NAMES.items() if name == command)
                payload = b""
                instructions.append(Instruction(opcode, payload))
            elif command == "push.u16" and len(fields) == 2:
                opcode = 0x06
                payload = struct.pack("<H", parse_integer(fields[1], "u16 operand", 0xFFFF))
                instructions.append(Instruction(opcode, payload))
            elif command == "push.f32" and len(fields) == 2:
                opcode = 0x07
                payload = struct.pack("<f", float(fields[1]))
                instructions.append(Instruction(opcode, payload))
            elif command in ("push.text", "call") and len(fields) == 2:
                opcode = 0x08 if command == "push.text" else 0x10
                payload = fields[1].encode("ascii") + b"\x00"
                instructions.append(Instruction(opcode, payload))
            elif command == "raw" and len(fields) == 3:
                opcode = parse_integer(fields[1], "opcode", 0xFF)
                payload = b"" if fields[2] == "-" else bytes.fromhex(fields[2])
                instructions.append(Instruction(opcode, payload))
            else:
                raise ValueError("unrecognized instruction or wrong number of operands")
        except (ValueError, OverflowError, UnicodeEncodeError, struct.error) as error:
            raise ValueError(f"line {line_number}: {error}") from error

    if not magic_seen or global_count is None or expected_function_count is None:
        raise ValueError("missing text format header")
    if gap is None or expected_instruction_count is None:
        raise ValueError("missing gap or stream directive")
    if len(descriptors) != expected_function_count:
        raise ValueError(
            f"header declares {expected_function_count} functions but "
            f"{len(descriptors)} descriptors were provided"
        )
    if len(instructions) != expected_instruction_count:
        raise ValueError(
            f"stream declares {expected_instruction_count} instructions but "
            f"{len(instructions)} were provided"
        )

    for index, (descriptor, (name, name_offset)) in enumerate(zip(descriptors, names)):
        if name is None:
            if name_offset != -1:
                raise ValueError("nameless descriptor must use name offset -1")
            continue
        original_name, original_offset = descriptor_name(descriptor)
        if original_name is None or name_offset != original_offset:
            raise ValueError("function name metadata does not match its descriptor")
        if name != original_name:
            encoded_name = name.encode("ascii")
            if len(encoded_name) != len(original_name):
                raise ValueError("renamed function must keep the original byte length")
            mutable = bytearray(descriptor)
            mutable[name_offset:name_offset + len(encoded_name)] = encoded_name
            descriptors[index] = bytes(mutable)

    return Script(global_count, descriptors, gap, instructions)


def encode_binary(script: Script) -> bytes:
    output = bytearray(struct.pack("<II", script.global_count, len(script.descriptors)))
    for descriptor in script.descriptors:
        if len(descriptor) != DESCRIPTOR_SIZE:
            raise ValueError("invalid descriptor size")
        output.extend(descriptor)
    output.extend(script.gap)
    output.extend(struct.pack("<I", len(script.instructions)))
    for instruction in script.instructions:
        if not 0 <= instruction.opcode <= 0xFF:
            raise ValueError("opcode is outside byte range")
        if len(instruction.payload) > 0xFFFF:
            raise ValueError("instruction payload exceeds 65535 bytes")
        output.append(instruction.opcode)
        output.extend(struct.pack("<H", len(instruction.payload)))
        output.extend(instruction.payload)
    return bytes(output)


def verified_text_round_trip(data: bytes) -> Script:
    script = decode_binary(data)
    text = render_text(script)
    rebuilt = encode_binary(parse_text(text))
    if rebuilt != data:
        mismatch = next(
            (index for index, (left, right) in enumerate(zip(data, rebuilt)) if left != right),
            min(len(data), len(rebuilt)),
        )
        raise ValueError(f"text round-trip changed the binary at offset 0x{mismatch:X}")
    return script


def default_decode_path(source: Path) -> Path:
    return source.with_name(source.name + ".txt")


def default_encode_path(source: Path) -> Path:
    return source.with_name(source.stem + ".rebuilt.scr")


def write_new_file(path: Path, content: bytes | str) -> None:
    if path.exists():
        raise FileExistsError(f"refusing to overwrite existing file: {path}")
    path.parent.mkdir(parents=True, exist_ok=True)
    if isinstance(content, str):
        path.write_text(content, encoding="utf-8", newline="\n")
    else:
        path.write_bytes(content)


def command_decode(source: Path, output: Path | None, legacy: bool = False) -> None:
    data = source.read_bytes()
    if legacy:
        text = render_text(verified_text_round_trip(data))
    else:
        from scr_language import render_source

        text = render_source(data)
    destination = output or default_decode_path(source)
    write_new_file(destination, text)
    print(f"decoded {source} -> {destination}")


def command_encode(source: Path, output: Path | None) -> None:
    text = source.read_text(encoding="utf-8")
    if text.lstrip().startswith("ROSEMOND-SCRIPT 1"):
        from scr_language import compile_source

        data = compile_source(text)
    else:
        script = parse_text(text)
        data = encode_binary(script)
    destination = output or default_encode_path(source)
    write_new_file(destination, data)
    print(f"encoded {source} -> {destination}")


def command_verify(paths: list[Path]) -> None:
    files = []
    for path in paths:
        if path.is_dir():
            files.extend(sorted(path.rglob("*.scr")))
        else:
            files.append(path)
    if not files:
        raise ValueError("no .scr files found")

    for path in files:
        data = path.read_bytes()
        from scr_language import compile_source, render_source

        source_text = render_source(data)
        rebuilt = compile_source(source_text)
        if rebuilt != data:
            mismatch = next(
                (index for index, (left, right) in enumerate(zip(data, rebuilt)) if left != right),
                min(len(data), len(rebuilt)),
            )
            raise ValueError(f"{path}: source round-trip changed byte at offset 0x{mismatch:X}")
        script = decode_binary(data)
        print(
            f"ok {path}: {len(script.descriptors)} functions, "
            f"{len(script.instructions)} instructions, {len(data)} bytes"
        )


def main() -> int:
    examples = "\n".join(
        [
            "Examples:",
            "  python scrtool.py decode gameScripts/haymove.scr -o build/scrtool/haymove.scr.txt",
            "  python scrtool.py encode build/scrtool/haymove.scr.txt -o build/scrtool/haymove.rebuilt.scr",
            "  python scrtool.py verify gameScripts/haymove.scr",
            "  python scrtool.py verify gameScripts",
            "",
            "Paths are resolved from the current working directory.",
        ]
    )
    parser = argparse.ArgumentParser(
        description=__doc__,
        epilog=examples,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    commands = parser.add_subparsers(dest="command", required=True, metavar="COMMAND")

    decode_parser = commands.add_parser(
        "decode",
        help="decompile a .scr file to editable source",
        description="Decompile a Rosemond .scr script into expressions, statements, and named function blocks.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    decode_parser.add_argument(
        "input",
        metavar="SCR_FILE",
        type=Path,
        help="Input .scr file.",
    )
    decode_parser.add_argument(
        "-o", "--output",
        metavar="TEXT_FILE",
        type=Path,
        help="Output text path (default: INPUT.scr.txt). Missing parent directories are created; existing files are never overwritten.",
    )
    decode_parser.add_argument(
        "--legacy",
        action="store_true",
        help="Write the older instruction-by-instruction representation instead of source-like text.",
    )

    encode_parser = commands.add_parser(
        "encode",
        help="compile editable text to .scr",
        description="Compile a scrtool text file back into a game .scr script.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    encode_parser.add_argument(
        "input",
        metavar="TEXT_FILE",
        type=Path,
        help="Input scrtool text file, usually ending in .scr.txt.",
    )
    encode_parser.add_argument(
        "-o", "--output",
        metavar="SCR_FILE",
        type=Path,
        help="Output .scr path (default: INPUT_STEM.rebuilt.scr, e.g. haymove.scr.rebuilt.scr). Missing parent directories are created; existing files are never overwritten.",
    )

    verify_parser = commands.add_parser(
        "verify",
        help="check exact decode/encode round-trips",
        description="Verify that each script decodes and re-encodes byte-for-byte without writing output files.",
    )
    verify_parser.add_argument(
        "inputs",
        metavar="PATH",
        nargs="+",
        type=Path,
        help="One or more .scr files or directories; directories are searched recursively for .scr files.",
    )

    args = parser.parse_args()
    try:
        if args.command == "decode":
            command_decode(args.input, args.output, args.legacy)
        elif args.command == "encode":
            command_encode(args.input, args.output)
        else:
            command_verify(args.inputs)
    except (OSError, ValueError) as error:
        print(f"scrtool: {error}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())