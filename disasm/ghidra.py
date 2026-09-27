"""Drive the disassembler from Ghidra's analysis instead of a linear sweep.

ExportFunctionMap.java writes a JSON map of everything Ghidra worked out about
the binary: where each function starts, which address ranges make up its body
(possibly several, for functions the compiler split up), which bytes inside
those ranges are instructions rather than data, and where indirect jumps
actually go.  This module loads that map and decodes each function from it, so
boundaries come from Ghidra's analysis rather than from guessing at alignment
padding and hoping reduce/split fixes the rest.
"""

import json
import re
import sys

try:
    import capstone
except ImportError:
    print('Capstone not found; verify that the Capstone extension for Python is installed')
    print('%s -m pip show capstone' % sys.executable)
    sys.exit(1)

from .bounds import Bounds
from .subroutine import Subroutine
from .application import Application


class Range:
    """One contiguous piece of a function body, with its code/data map.

    ``items`` is the run-length map Ghidra exported: a positive entry is an
    instruction of that many bytes, a negative entry is that many bytes of
    non-code.  Replaying it from ``start`` reproduces every boundary Ghidra
    found.
    """

    def __init__(self, blob):
        self.start = blob['start']
        self.end = blob['end']
        self.items = blob['items']

    def walk(self):
        """Yield (address, length, is_code) for each item in address order."""
        at = self.start
        for item in self.items:
            length = abs(item)
            yield (at, length, item > 0)
            at += length


class FunctionInfo:
    def __init__(self, blob):
        self.entry = blob['entry']
        self.name = blob['name']
        self.default_name = blob['default_name']
        self.thunk = blob['thunk']
        self.noreturn = blob['noreturn']
        self.stack_purge = blob['stack_purge']
        self.calling_convention = blob['calling_convention']
        self.ranges = [Range(r) for r in blob['ranges']]
        self.callees = blob['callees']
        # JSON object keys are strings; addresses are more useful as ints.
        self.computed_jumps = {int(k): v for k, v in blob['computed_jumps'].items()}
        self.computed_calls = {int(k): v for k, v in blob['computed_calls'].items()}

    @property
    def start(self):
        return self.ranges[0].start

    @property
    def end(self):
        return self.ranges[-1].end

    def bounds(self):
        return Bounds([(r.start, r.end) for r in self.ranges])

    def __repr__(self):
        return '<%s @0x%08x, %d range(s)>' % (self.name, self.entry, len(self.ranges))


class FunctionMap:
    def __init__(self, path):
        with open(path) as f:
            blob = json.load(f)
        self.program = blob['program']
        self.image_base = blob['image_base']
        self.blocks = blob['blocks']
        self.functions = [FunctionInfo(f) for f in blob['functions']]
        self.functions.sort(key=lambda f: f.start)
        self.unclaimed = blob['unclaimed']

    # -- the hint lists disassemble.py used to carry by hand -----------------

    def known_subroutines(self):
        """Every function entry point Ghidra found."""
        return sorted(f.entry for f in self.functions)

    def data_segments(self, merge_gap=16):
        """Non-code bytes sitting in executable memory.

        This is DATA_SEGMENTS, derived.  Ghidra breaks a jump table into one
        item per entry, so adjacent runs within ``merge_gap`` bytes are joined
        back into a single segment.
        """
        raw = sorted((x['start'], x['end']) for x in self.unclaimed
                     if x['kind'] in ('data', 'undefined'))
        merged = []
        for start, end in raw:
            if merged and start - merged[-1][1] <= merge_gap:
                merged[-1] = (merged[-1][0], end)
            else:
                merged.append((start, end))
        return merged

    def function_names(self):
        """Names a human or a demangler supplied, keyed by entry point.

        Ghidra's own ``FUN_0040abcd`` placeholders are left out, so the
        generator falls back to its own ``sub_40abcd`` spelling for those.
        The rest are spelled as C++ identifiers: Ghidra keeps stdcall
        decoration (``__CallSettingFrame@12``) and disambiguates repeated names
        with an address suffix (``Unwind@00486020``), neither of which the
        generated header can declare.
        """
        names = {}
        taken = set()
        for f in self.functions:
            if f.default_name:
                # Reserve the generator's own spelling so a Ghidra name cannot
                # collide with it.
                taken.add('sub_%x' % f.entry)
        for f in self.functions:
            if f.default_name:
                continue
            name = _identifier(f.name)
            if name in taken:
                name = '%s_%x' % (name, f.entry)
            taken.add(name)
            names[f.entry] = name
        return names

    def padding(self):
        return [(x['start'], x['end']) for x in self.unclaimed
                if x['kind'] == 'padding']

    def report(self):
        text = [b for b in self.blocks if b['x']]
        total = sum(b['end'] - b['start'] for b in text)
        body = sum(r.end - r.start for f in self.functions for r in f.ranges)
        kinds = {}
        for x in self.unclaimed:
            kinds[x['kind']] = kinds.get(x['kind'], 0) + x['end'] - x['start']
        print('Ghidra map: %d functions, %d/%d executable bytes in bodies (%.1f%%)'
              % (len(self.functions), body, total, 100.0 * body / total))
        for kind in sorted(kinds, key=lambda k: -kinds[k]):
            print('  unclaimed %-10s %7d bytes' % (kind, kinds[kind]))
        leftover = kinds.get('code', 0)
        if leftover:
            print('  WARNING: %d bytes of decoded code belong to no function.'
                  % leftover)
            print('  Run RecoverMissingFunctions.java and re-export.')


def _identifier(name):
    """Spell a Ghidra symbol name as a C++ identifier."""
    name = re.sub(r'[^A-Za-z0-9_]', '_', name)
    if not name or name[0].isdigit():
        name = '_' + name
    return name


def _decode_range(disassembler, application, section, range_, subroutine):
    """Decode one body range, following Ghidra's code/data map exactly.

    Instruction boundaries are taken from the map rather than rediscovered, so
    capstone cannot drift into data and then resynchronise somewhere wrong.
    Data items are collected onto the subroutine's data blob.
    """
    data_blob = b''
    for address, length, is_code in range_.walk():
        blob = application.read_section_data(section, address, address + length)
        if not is_code:
            data_blob += blob
            continue
        # One Ghidra code unit can cover several capstone instructions: Ghidra
        # folds an FPU instruction's 0x9b WAIT prefix into the instruction,
        # capstone reports the two separately.  Decode until the item is used
        # up, which keeps the boundaries Ghidra gave without losing detail.
        consumed = 0
        for instruction in disassembler.disasm(blob, address):
            subroutine.add_instruction(instruction)
            consumed += instruction.size
            if consumed >= length:
                break
        if consumed != length:
            print('0x%08x: Ghidra says %d byte(s), capstone decoded %d: %s'
                  % (address, length, consumed,
                     ''.join('%02x' % c for c in blob)))
    return data_blob


def disassemble(name, exe_path, function_map, thread_routines=[],
                type=Application, rebase_after=None):
    """Build an Application from a Ghidra function map.

    Drop-in alternative to disassembler.disassemble.  There is no reduce or
    split pass and no hint lists: the boundaries are already right, so there is
    nothing to repair afterwards.
    """
    if not isinstance(function_map, FunctionMap):
        function_map = FunctionMap(function_map)
    function_map.report()

    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    disassembler.detail = True

    rebase_address = 0
    if rebase_after:
        rebase_address = rebase_after.sections[-1][1] + rebase_after.sections[-1][2]
    application = type(name, exe_path, rebase_address)

    sections = application.get_code_sections()

    def section_for(address):
        for section in sections:
            if application.get_address(section) <= address < application.get_address_end(section):
                return section
        return None

    skipped = 0
    for info in function_map.functions:
        section = section_for(info.start)
        if section is None:
            # Ghidra keeps blocks the loader dropped, e.g. discardable ones.
            skipped += 1
            continue

        subroutine = Subroutine(application, section, b'', b'', [],
                                info.entry in thread_routines)
        subroutine.bounds = info.bounds()
        # Ghidra's recovered switch-table and vtable destinations, which are
        # authoritative where add_instruction would otherwise walk dwords until
        # one stops looking like a code address.
        subroutine.computed = dict(info.computed_jumps)
        subroutine.computed.update(info.computed_calls)

        data_blob = b''
        for range_ in info.ranges:
            data_blob += _decode_range(disassembler, application, section,
                                       range_, subroutine)
        subroutine.data_blob = data_blob

        if not subroutine.instructions:
            skipped += 1
            continue
        if info.entry != subroutine.instructions[0].address:
            # Entry point is not the lowest address in the body; write() emits a
            # jump to it from the top of the generated function.
            subroutine.entry = info.entry

        application.add_subroutine(subroutine)

    application.subroutines.sort(key=lambda s: s.get_start_address())
    decoded = len(application.subroutines)

    # Ghidra lets one function jump into the middle of another -- compilers do
    # that for shared tails -- which C++ cannot express as a call.  The
    # existing split pass covers it by emitting a duplicate of the target
    # function entered at that address.  No merge pass: the bodies are already
    # right, so there is nothing to stitch back together.
    application.split_subroutines([])

    print('Decoded %d subroutines from Ghidra map (%d skipped); '
          '%d alternate entry point(s) added'
          % (decoded, skipped, len(application.subroutines) - decoded))
    return application
