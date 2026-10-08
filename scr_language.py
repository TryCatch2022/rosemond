"""Source-level decompiler and compiler for Rosemond Hill script bytecode."""

from __future__ import annotations

import base64
import json
import re
import struct
from dataclasses import dataclass, field

import scrtool


MAGIC = "ROSEMOND-SCRIPT 1"
DESCRIPTOR_SIZE = scrtool.DESCRIPTOR_SIZE


@dataclass(frozen=True)
class FunctionInfo:
    index: int
    name: str
    entry: int
    name_offset: int
    entry_offset: int
    original_name: str


@dataclass
class SourceFunction:
    index: int
    name: str
    body: list[str] = field(default_factory=list)
    info: FunctionInfo | None = None


@dataclass
class SourceProgram:
    global_count: int
    functions: list[SourceFunction]
    prefix: bytes | None
    preamble: SourceFunction | None = None


@dataclass(frozen=True)
class Expr:
    kind: str
    value: object = None
    left: Expr | None = None
    right: Expr | None = None
    args: tuple[Expr, ...] = ()


@dataclass
class CompiledFunction:
    function: SourceFunction
    entry: int
    instructions: list[scrtool.Instruction]
    labels: dict[str, int]
    relative_jumps: set[int]


TOKEN_RE = re.compile(
    r"\s*(?:(?P<number>(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?)"
    r"|(?P<string>\"(?:\\.|[^\"\\])*\")"
    r"|(?P<global>global\[\d+\])"
    r"|(?P<name>[A-Za-z_][A-Za-z0-9_.]*)"
    r"|(?P<operator>==|!=|<=|>=|[+\-*/^<>()>,]))"
)

PRECEDENCE = {"==": 4, "!=": 4, "<": 4, ">": 4, "+": 10, "-": 10, "^": 5, "*": 20, "/": 20}
ARITHMETIC_OPCODES = {"^": 0x00, "*": 0x01, "/": 0x02, "+": 0x03, "-": 0x04}
OPCODE_OPERATORS = {value: key for key, value in ARITHMETIC_OPCODES.items()}


def _candidate_functions(data: bytes, script: scrtool.Script) -> list[FunctionInfo]:
    prefix_size = 8 + len(script.descriptors) * DESCRIPTOR_SIZE + len(script.gap)
    candidates_by_record = []
    for index in range(len(script.descriptors)):
        record_start = 8 + index * DESCRIPTOR_SIZE
        by_entry = {}
        for relative in range(DESCRIPTOR_SIZE):
            name_offset = record_start + relative
            entry_offset = name_offset + 32
            if entry_offset + 2 > prefix_size:
                continue
            terminator = data.find(b"\0", name_offset, min(entry_offset, len(data)))
            if terminator < 0:
                continue
            raw_name = data[name_offset:terminator]
            if not 3 <= len(raw_name) <= 31 or any(byte < 0x20 or byte > 0x7E for byte in raw_name):
                continue
            entry = struct.unpack_from("<H", data, entry_offset)[0]
            if entry >= len(script.instructions):
                continue
            candidate = FunctionInfo(
                index=index,
                name=raw_name.decode("ascii"),
                entry=entry,
                name_offset=name_offset,
                entry_offset=entry_offset,
                original_name=raw_name.decode("ascii"),
            )
            previous = by_entry.get(entry)
            if previous is None or (len(candidate.name), -relative) > (len(previous.name), -(previous.name_offset - record_start)):
                by_entry[entry] = candidate
        candidates_by_record.append(
            sorted(by_entry.values(), key=lambda candidate: (-len(candidate.name), candidate.name_offset))
        )

    if not candidates_by_record or any(not candidates for candidates in candidates_by_record):
        raise ValueError("at least one function descriptor has no plausible name/entry pair")

    entry_owner: dict[int, int] = {}
    selected_by_record: dict[int, FunctionInfo] = {}

    def assign(index: int, visited: set[int]) -> bool:
        for candidate in candidates_by_record[index]:
            if candidate.entry in visited:
                continue
            visited.add(candidate.entry)
            owner = entry_owner.get(candidate.entry)
            if owner is None or assign(owner, visited):
                entry_owner[candidate.entry] = index
                selected_by_record[index] = candidate
                return True
        return False

    record_order = sorted(range(len(candidates_by_record)), key=lambda index: len(candidates_by_record[index]))
    for index in record_order:
        if not assign(index, set()):
            raise ValueError(f"cannot resolve a unique function entry for descriptor {index}")
    if len(selected_by_record) != len(script.descriptors):
        raise ValueError("function entry matching did not cover every descriptor")
    selected = [selected_by_record[index] for index in range(len(script.descriptors))]
    entries = [function.entry for function in selected]
    if len(set(entries)) != len(entries):
        raise ValueError("function entry matching produced duplicate starts")
    return selected


def _format_expr(expression: Expr, parent_precedence: int = 0) -> str:
    if expression.kind == "global":
        return f"global[{expression.value}]"
    if expression.kind == "number":
        return repr(expression.value)
    if expression.kind == "string":
        return json.dumps(expression.value, ensure_ascii=True)
    if expression.kind == "call":
        return f"{expression.value}({', '.join(_format_expr(arg) for arg in expression.args)})"
    if expression.kind == "unary":
        text = f"-{_format_expr(expression.left, 30)}"
        return f"({text})" if parent_precedence > 30 else text
    if expression.kind == "binary":
        operator = str(expression.value)
        precedence = PRECEDENCE[operator]
        text = f"{_format_expr(expression.left, precedence)} {operator} {_format_expr(expression.right, precedence + 1)}"
        return f"({text})" if parent_precedence > precedence else text
    raise ValueError(f"unsupported expression kind: {expression.kind}")


def _branch_target(instruction: scrtool.Instruction) -> int | None:
    if len(instruction.payload) >= 4:
        return struct.unpack_from("<I", instruction.payload)[0]
    if len(instruction.payload) == 2:
        return struct.unpack_from("<H", instruction.payload)[0]
    return None


def _decompile_function(instructions: list[scrtool.Instruction], start: int, end: int) -> list[str]:
    block = instructions[start:end]
    targets = set()
    for offset, instruction in enumerate(block):
        if instruction.opcode in (0x0C, 0x0D, 0x0E):
            target = _branch_target(instruction)
            if target is not None and start <= target < end:
                targets.add(target)

    lines = []
    stack: list[Expr] = []
    opaque = False

    def flush_stack() -> None:
        while stack:
            lines.append(f"vm.push {_format_expr(stack.pop(0))};")

    for local_index, instruction in enumerate(block):
        position = start + local_index
        if position in targets:
            lines.append(f"L{position}:")
        if opaque:
            lines.append(_raw_instruction(instruction))
            continue

        opcode = instruction.opcode
        payload = instruction.payload
        if opcode == 0x06 and len(payload) == 2:
            stack.append(Expr("global", struct.unpack("<H", payload)[0]))
        elif opcode == 0x07 and len(payload) == 4:
            value = struct.unpack("<f", payload)[0]
            if value != value:
                flush_stack()
                lines.append(_raw_instruction(instruction))
                opaque = True
            else:
                stack.append(Expr("number", value))
        elif opcode == 0x08 and payload.endswith(b"\0") and all(0x20 <= value <= 0x7E for value in payload[:-1]):
            stack.append(Expr("string", payload[:-1].decode("ascii")))
        elif opcode in OPCODE_OPERATORS and len(stack) >= 2:
            right = stack.pop()
            left = stack.pop()
            stack.append(Expr("binary", OPCODE_OPERATORS[opcode], left, right))
        elif opcode == 0x05 and len(stack) >= 2:
            value = stack.pop()
            target = stack.pop()
            if target.kind == "global":
                lines.append(f"global[{target.value}] = {_format_expr(value)};")
            else:
                flush_stack()
                lines.append(_raw_instruction(instruction))
                opaque = True
        elif opcode in (0x09, 0x0A) and stack:
            value = stack.pop()
            operator = "==" if opcode == 0x09 else "<"
            stack.append(Expr("binary", operator, value, Expr("number", 0.0)))
        elif opcode == 0x10 and payload.endswith(b"\0") and all(0x20 <= value <= 0x7E for value in payload[:-1]):
            name = payload[:-1].decode("ascii")
            arguments = tuple(reversed(stack))
            stack.clear()
            lines.append(f"{_format_expr(Expr('call', name, args=arguments))};")
        elif opcode == 0x0B and not payload:
            flush_stack()
            lines.append("return;")
        elif opcode == 0x0F and not payload:
            lines.append("nop;")
        elif opcode == 0x0C and _branch_target(instruction) is not None:
            target = _branch_target(instruction)
            if target in targets:
                flush_stack()
                lines.append(f"goto L{target};")
            else:
                flush_stack()
                lines.append(_raw_instruction(instruction))
                opaque = True
        elif opcode in (0x0D, 0x0E) and stack and _branch_target(instruction) is not None:
            target = _branch_target(instruction)
            if target in targets:
                condition = stack.pop()
                operator = "==" if opcode == 0x0D else ">"
                lines.append(f"if ({_format_expr(condition)} {operator} 0) goto L{target};")
            else:
                flush_stack()
                lines.append(_raw_instruction(instruction))
                opaque = True
        else:
            flush_stack()
            lines.append(_raw_instruction(instruction))
            opaque = True

    flush_stack()
    return lines


def _raw_instruction(instruction: scrtool.Instruction) -> str:
    return f"vm.raw 0x{instruction.opcode:02X} {instruction.payload.hex() or '-'};"


def render_source(data: bytes) -> str:
    script = scrtool.decode_binary(data)
    functions = _candidate_functions(data, script)
    prefix_size = 8 + len(script.descriptors) * DESCRIPTOR_SIZE + len(script.gap)
    prefix = data[:prefix_size]
    by_entry = sorted(functions, key=lambda function: function.entry)
    end_by_index = {}
    for index, function in enumerate(by_entry):
        end_by_index[function.index] = by_entry[index + 1].entry if index + 1 < len(by_entry) else len(script.instructions)

    lines = [
        MAGIC,
        f"globals {script.global_count}",
        f"meta.prefix {base64.b64encode(prefix).decode('ascii')}",
    ]
    for function in functions:
        lines.append(
            f"meta.function {function.index} {function.entry} {function.name_offset} "
            f"{function.entry_offset} {json.dumps(function.name, ensure_ascii=True)}"
        )
    first_entry = min(function.entry for function in functions)
    if first_entry:
        lines.append("preamble {")
        lines.extend(_indent_source(_decompile_function(script.instructions, 0, first_entry)))
        lines.append("}")
    for function in sorted(functions, key=lambda item: item.index):
        lines.append(f"function {function.index} {json.dumps(function.name, ensure_ascii=True)} {{")
        body = _decompile_function(script.instructions, function.entry, end_by_index[function.index])
        lines.extend(_indent_source(body))
        lines.append("}")
    return "\n".join(lines) + "\n"


def _indent_source(lines: list[str]) -> list[str]:
    return [f"    {line}" if not line.endswith(":") else line for line in lines]


def _tokenize_expression(text: str) -> list[tuple[str, str]]:
    tokens = []
    position = 0
    while position < len(text):
        match = TOKEN_RE.match(text, position)
        if not match:
            raise ValueError(f"invalid expression near {text[position:]!r}")
        position = match.end()
        kind = match.lastgroup
        value = match.group(kind)
        if kind == "operator" and value == " ":
            continue
        tokens.append((kind, value))
    return tokens


class ExpressionParser:
    def __init__(self, text: str):
        self.tokens = _tokenize_expression(text)
        self.position = 0

    def peek(self) -> tuple[str, str] | None:
        return self.tokens[self.position] if self.position < len(self.tokens) else None

    def take(self) -> tuple[str, str]:
        token = self.peek()
        if token is None:
            raise ValueError("unexpected end of expression")
        self.position += 1
        return token

    def parse(self, minimum_precedence: int = 0) -> Expr:
        kind, value = self.take()
        if kind == "operator" and value == "-":
            left = Expr("unary", "-", self.parse(30))
        elif kind == "operator" and value == "(":
            left = self.parse()
            if self.take() != ("operator", ")"):
                raise ValueError("expected closing parenthesis")
        elif kind == "number":
            left = Expr("number", float(value))
        elif kind == "string":
            left = Expr("string", json.loads(value))
        elif kind == "global":
            left = Expr("global", int(value[7:-1]))
        elif kind == "name":
            if self.peek() == ("operator", "("):
                self.take()
                args = []
                if self.peek() != ("operator", ")"):
                    while True:
                        args.append(self.parse())
                        if self.peek() != ("operator", ","):
                            break
                        self.take()
                if self.take() != ("operator", ")"):
                    raise ValueError("expected closing call parenthesis")
                left = Expr("call", value, args=tuple(args))
            else:
                raise ValueError(f"unbound identifier {value!r}")
        else:
            raise ValueError(f"unexpected token {value!r}")

        while True:
            next_token = self.peek()
            if next_token is None or next_token[0] != "operator":
                break
            operator = next_token[1]
            precedence = PRECEDENCE.get(operator, -1)
            if precedence < minimum_precedence:
                break
            self.take()
            right = self.parse(precedence + 1)
            left = Expr("binary", operator, left, right)
        return left


def _parse_expression(text: str) -> Expr:
    parser = ExpressionParser(text)
    expression = parser.parse()
    if parser.peek() is not None:
        raise ValueError(f"unexpected token {parser.peek()[1]!r}")
    return expression


def _compile_expression(expression: Expr, output: list[scrtool.Instruction]) -> None:
    if expression.kind == "global":
        output.append(scrtool.Instruction(0x06, struct.pack("<H", int(expression.value))))
    elif expression.kind == "number":
        output.append(scrtool.Instruction(0x07, struct.pack("<f", float(expression.value))))
    elif expression.kind == "string":
        output.append(scrtool.Instruction(0x08, str(expression.value).encode("ascii") + b"\0"))
    elif expression.kind == "unary":
        if expression.left.kind == "number":
            output.append(scrtool.Instruction(0x07, struct.pack("<f", -float(expression.left.value))))
        else:
            output.append(scrtool.Instruction(0x07, struct.pack("<f", 0.0)))
            _compile_expression(expression.left, output)
            output.append(scrtool.Instruction(0x04, b""))
    elif expression.kind == "binary":
        operator = str(expression.value)
        if operator in ARITHMETIC_OPCODES:
            _compile_expression(expression.left, output)
            _compile_expression(expression.right, output)
            output.append(scrtool.Instruction(ARITHMETIC_OPCODES[operator], b""))
        elif operator in ("==", "<") and expression.right.kind == "number" and expression.right.value == 0:
            _compile_expression(expression.left, output)
            output.append(scrtool.Instruction(0x09 if operator == "==" else 0x0A, b""))
        else:
            raise ValueError(f"comparison {operator!r} is only supported against zero")
    elif expression.kind == "call":
        raise ValueError("calls are statements, not nested expressions")
    else:
        raise ValueError(f"unsupported expression kind: {expression.kind}")


def _compile_function(function: SourceFunction) -> CompiledFunction:
    instructions = []
    labels = {}
    pending_jumps = []
    relative_jumps = set()

    def compile_expression(text: str) -> Expr:
        expression = _parse_expression(text)
        _compile_expression(expression, instructions)
        return expression

    for raw_line in function.body:
        line = raw_line.strip()
        if not line:
            continue
        if line.startswith("//") or line.startswith("#"):
            continue
        label_match = re.fullmatch(r"([A-Za-z_][A-Za-z0-9_]*):", line)
        if label_match:
            if label_match.group(1) in labels:
                raise ValueError(f"duplicate label {label_match.group(1)}")
            labels[label_match.group(1)] = len(instructions)
            continue
        if line == "return;":
            instructions.append(scrtool.Instruction(0x0B, b""))
            continue
        if line == "nop;":
            instructions.append(scrtool.Instruction(0x0F, b""))
            continue
        raw_match = re.fullmatch(r"vm\.raw\s+(0x[0-9A-Fa-f]+)\s+([0-9A-Fa-f]+|-)\s*;", line)
        if raw_match:
            opcode = int(raw_match.group(1), 16)
            payload = b"" if raw_match.group(2) == "-" else bytes.fromhex(raw_match.group(2))
            instructions.append(scrtool.Instruction(opcode, payload))
            continue
        push_match = re.fullmatch(r"vm\.push\s+(.+);", line)
        if push_match:
            compile_expression(push_match.group(1))
            continue
        goto_match = re.fullmatch(r"goto\s+([A-Za-z_][A-Za-z0-9_]*)\s*;", line)
        if goto_match:
            index = len(instructions)
            instructions.append(scrtool.Instruction(0x0C, b"\0\0\0\0"))
            pending_jumps.append((index, goto_match.group(1)))
            continue
        if_match = re.fullmatch(r"if\s*\((.+)\)\s*goto\s+([A-Za-z_][A-Za-z0-9_]*)\s*;", line)
        if if_match:
            condition = _parse_expression(if_match.group(1))
            branch_opcode = None
            if condition.kind == "binary" and condition.value == "==" and condition.right.kind == "number" and condition.right.value == 0:
                _compile_expression(condition.left, instructions)
                branch_opcode = 0x0D
            elif condition.kind == "binary" and condition.value == ">" and condition.right.kind == "number" and condition.right.value == 0:
                _compile_expression(condition.left, instructions)
                branch_opcode = 0x0E
            elif condition.kind == "binary" and condition.value == "<" and condition.right.kind == "number" and condition.right.value == 0:
                _compile_expression(condition.left, instructions)
                instructions.append(scrtool.Instruction(0x0A, b""))
                branch_opcode = 0x0E
            if branch_opcode is None:
                raise ValueError("branch condition must compare an expression with zero")
            index = len(instructions)
            instructions.append(scrtool.Instruction(branch_opcode, b"\0\0\0\0"))
            pending_jumps.append((index, if_match.group(2)))
            continue
        assignment = re.fullmatch(r"global\[(\d+)\]\s*=\s*(.+);", line)
        if assignment:
            global_index = int(assignment.group(1))
            if not 0 <= global_index <= 0xFFFF:
                raise ValueError("global index must fit in 16 bits")
            instructions.append(scrtool.Instruction(0x06, struct.pack("<H", global_index)))
            compile_expression(assignment.group(2))
            instructions.append(scrtool.Instruction(0x05, b""))
            continue
        expression = _parse_expression(line[:-1] if line.endswith(";") else line)
        if expression.kind != "call":
            raise ValueError(f"unsupported statement: {line}")
        if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_.]*", str(expression.value)):
            raise ValueError("native call name must be an identifier")
        for argument in reversed(expression.args):
            _compile_expression(argument, instructions)
        instructions.append(scrtool.Instruction(0x10, str(expression.value).encode("ascii") + b"\0"))

    for instruction_index, label in pending_jumps:
        if label not in labels:
            raise ValueError(f"undefined label {label}")
        target = labels[label]
        instructions[instruction_index].payload = struct.pack("<I", target)
        relative_jumps.add(instruction_index)
    return CompiledFunction(function, 0, instructions, labels, relative_jumps)


def parse_source(text: str) -> SourceProgram:
    lines = text.splitlines()
    if not lines or lines[0].strip() != MAGIC:
        raise ValueError(f"source must start with {MAGIC}")
    global_count = None
    prefix = None
    metadata = {}
    functions = []
    current = None
    preamble = None
    current_is_preamble = False

    for line_number, raw_line in enumerate(lines[1:], 2):
        line = raw_line.strip()
        if not line or line.startswith("//") or line.startswith("#"):
            continue
        fields = __import__("shlex").split(line, comments=True)
        if not fields:
            continue
        if current is not None:
            if fields == ["}"]:
                if current_is_preamble:
                    preamble = current
                current_is_preamble = False
                current = None
            else:
                current.body.append(line)
            continue
        if fields[0] == "globals" and len(fields) == 2:
            global_count = scrtool.parse_integer(fields[1], "global count", 0xFFFFFFFF)
        elif fields[0] == "meta.prefix" and len(fields) == 2:
            prefix = base64.b64decode(fields[1], validate=True)
        elif fields[0] == "meta.function" and len(fields) == 6:
            index = scrtool.parse_integer(fields[1], "function index", 0xFFFF)
            entry = scrtool.parse_integer(fields[2], "function entry", 0xFFFF)
            name_offset = scrtool.parse_integer(fields[3], "name offset", 0xFFFFFFFF)
            entry_offset = scrtool.parse_integer(fields[4], "entry offset", 0xFFFFFFFF)
            metadata[index] = FunctionInfo(index, fields[5], entry, name_offset, entry_offset, fields[5])
        elif fields == ["preamble", "{"]:
            if preamble is not None or current_is_preamble:
                raise ValueError("source has more than one preamble block")
            current = SourceFunction(-1, "__preamble")
            current_is_preamble = True
        elif fields[0] == "function" and fields[-1] == "{":
            if len(fields) == 4:
                index = scrtool.parse_integer(fields[1], "function index", 0xFFFF)
                name = fields[2]
                info = metadata.get(index)
            elif len(fields) == 3:
                index = len(functions)
                name = fields[1]
                info = None
            else:
                raise ValueError(f"line {line_number}: malformed function declaration")
            current = SourceFunction(index, name, info=info)
            functions.append(current)
        else:
            raise ValueError(f"line {line_number}: unexpected source directive")

    if current is not None:
        raise ValueError("unterminated function block")
    if global_count is None:
        raise ValueError("missing globals declaration")
    if not functions:
        raise ValueError("source has no functions")
    if prefix is not None and (len(metadata) != len(functions) or any(function.info is None for function in functions)):
        raise ValueError("template metadata must describe every function")
    return SourceProgram(global_count, functions, prefix, preamble)


def compile_source(text: str) -> bytes:
    program = parse_source(text)
    if program.prefix is None:
        prefix = bytearray(struct.pack("<II", program.global_count, len(program.functions)))
        for function in program.functions:
            name = function.name.encode("ascii")
            if not name or len(name) > 31:
                raise ValueError("new function names must be 1-31 ASCII bytes")
            record_start = len(prefix)
            record = bytearray(DESCRIPTOR_SIZE)
            record[:len(name)] = name
            record[len(name)] = 0
            prefix.extend(record)
            function.info = FunctionInfo(
                function.index,
                function.name,
                0,
                record_start,
                record_start + 32,
                function.name,
            )
    else:
        prefix = bytearray(program.prefix)
        if len(prefix) < 8:
            raise ValueError("template metadata is shorter than the script header")
        stored_globals, stored_functions = struct.unpack_from("<II", prefix)
        if stored_functions != len(program.functions):
            raise ValueError("editing a template must preserve its function count")
        struct.pack_into("<I", prefix, 0, program.global_count)
        for function in program.functions:
            if function.info is None:
                raise ValueError("template function metadata is missing")
            new_name = function.name.encode("ascii")
            old_name = function.info.original_name.encode("ascii")
            if len(new_name) != len(old_name):
                raise ValueError("renamed template functions must keep their original byte length")
            prefix[function.info.name_offset:function.info.name_offset + len(new_name)] = new_name

    ordered = sorted(program.functions, key=lambda function: function.info.entry if function.info else function.index)
    compiled = []
    instruction_total = 0
    if program.preamble is not None:
        preamble = _compile_function(program.preamble)
        preamble.entry = 0
        compiled.append(preamble)
        instruction_total = len(preamble.instructions)
    for function in ordered:
        result = _compile_function(function)
        result.entry = instruction_total
        compiled.append(result)
        instruction_total += len(result.instructions)

    prefix_size = len(prefix)
    instructions = []
    for result in compiled:
        function = result.function
        info = function.info
        if function.index == -1:
            instructions.extend(result.instructions)
            continue
        if info is None or info.entry_offset + 2 > prefix_size:
            raise ValueError(f"function entry field for {function.name!r} is outside template metadata")
        struct.pack_into("<H", prefix, info.entry_offset, result.entry)
        for index, instruction in enumerate(result.instructions):
            if index in result.relative_jumps:
                local_target = _branch_target(instruction)
                if local_target is not None:
                    instruction.payload = struct.pack("<I", result.entry + local_target)
            instructions.append(instruction)

    output = bytearray(prefix)
    output.extend(struct.pack("<I", len(instructions)))
    for instruction in instructions:
        if len(instruction.payload) > 0xFFFF:
            raise ValueError("instruction payload exceeds 65535 bytes")
        output.append(instruction.opcode)
        output.extend(struct.pack("<H", len(instruction.payload)))
        output.extend(instruction.payload)
    return bytes(output)
