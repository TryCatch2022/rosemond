import os
from . import pefile
from .subroutine import Subroutine
from . import codegen
from . import stubexe
import ordlookup


unknown = set([])
address = 0x400a00


def _unknown(instruction, *kl):
    if instruction.mnemonic not in unknown:
        unknown.add(instruction.mnemonic)
        print('Unhandled instruction: %s' % instruction.mnemonic)
    return ['NFS2_ASSERT(false);']


def _do_import(section, index, offset, base):
    global address
    # import directory
    def read_name(o):
        end = o
        while section[end] != 0: end += 1
        return section[o:end]
    def read_word(o):
        return section[o]         + \
                section[o+1] * 2**8
    def read_dword(o):
        return section[o]           + \
                section[o+1] * 2**8  + \
                section[o+2] * 2**16 + \
                section[o+3] * 2**24
    def write_dword(o, dword):
        return section[:o]               \
                + bytes([dword & 0xff, (dword >> 8) & 0xff, (dword >> 16) & 0xff, (dword >> 24) & 0xff]) \
                + section[o+4:]

    dlls = []
    while True:
        table_offset = read_dword(index + 0)
        ts = read_dword(index + 4)
        forwarder = read_dword(index + 8)
        dll_name_offset = read_dword(index + 12)
        thunk_table = read_dword(index + 16)
        index += 20
        if table_offset == 0:
            break
        dll_name_offset -= offset
        dll_name = read_name(dll_name_offset)[:-4].lower()
        table_offset -= offset
        thunk_table -= offset
        methods = []
        characteristics = read_dword(table_offset)
        while characteristics:
            if characteristics & 0x80000000:
                # print('index: %d' % (characteristics & 0xffff))
                funcname = ordlookup.ordLookup(dll_name + b'.dll', characteristics & 0xffff)
                print("%d->%s[%s]" % (characteristics & 0xFFFF, funcname, dll_name))
                methods.append((funcname, address))
            else:
                i = read_word(characteristics - offset)
                name = read_name(characteristics - offset + 2)
                decoration = name.find(b'@')
                if decoration != -1:
                    assert(name[0] == ord(b'_'))
                    name = name[1:decoration]
                methods.append((name, address))
                print('0x%x -> %s' % (offset + thunk_table + base, name))
            section = write_dword(thunk_table, address)
            address += 1
            table_offset += 4
            thunk_table += 4
            characteristics = read_dword(table_offset)
        # print(read_word(name_table_offset))
        dlls.append((dll_name, methods))
    return dlls, section


def _load_exe(path, rebase_address):
    nfs2exe = pefile.PE(path)
    if rebase_address:
        nfs2exe.relocate_image(rebase_address)
    import_data = nfs2exe.OPTIONAL_HEADER.DATA_DIRECTORY[1]
    image_base = rebase_address or nfs2exe.OPTIONAL_HEADER.ImageBase
    sections = []
    for s in nfs2exe.sections:
        if s.PointerToRawData:
            data = s.get_data()
            if s.contains_rva(import_data.VirtualAddress):
                dlls, data = _do_import(data, import_data.VirtualAddress-s.VirtualAddress, s.VirtualAddress, image_base)
            if s.Characteristics & 0x02000000:
                print('Discarding %s' % s.Name.rstrip(b'\x00'))
                continue
            read_only = 0 == s.Characteristics & 0x80000000
            code = 0 != s.Characteristics & 0x20000000
            print(s.Name.rstrip(b'\x00'), 'RO:', read_only,)
            print(s.Name.rstrip(b'\x00'), 'EXE:', code,)
            # A section's virtual size can exceed what is stored in the file:
            # .data carries a large zero-filled tail that the loader commits and
            # the executable writes to from its very first function, so the
            # placed segment has to span the virtual extent, not just the bytes.
            virtual_length = max(s.Misc_VirtualSize, len(data))
            sections.append((data, s.VirtualAddress + image_base, len(data), s.Name.rstrip(b'\x00').replace(b'.', b'_'), read_only, code, virtual_length))
        else:
            sections.append((None, s.VirtualAddress + image_base, s.SizeOfRawData, s.Name.rstrip(b'\x00').replace(b'.', b'_'), False, False, max(s.Misc_VirtualSize, s.SizeOfRawData)))
    entry_point = nfs2exe.OPTIONAL_HEADER.AddressOfEntryPoint + image_base
    exported_symbols = [(image_base+h['RVA'],h['Name']) for h in nfs2exe.dump_dict().get('Exported symbols', [])[1:]]
    return (sections, entry_point, dlls, exported_symbols)


def _reduce(subroutines, found_subroutines, merge_hints):
    index = 0
    result = subroutines[:]
    while index < len(result)-1:
        subroutine = result[index]
        subroutine2 = result[index+1]
        for m1, m2 in merge_hints:
            if subroutine.instructions[0].address == m1 and subroutine2.instructions[0].address == m2:
                result[index] = Subroutine.merge(subroutine, subroutine2)
                del result[index+1]
                break
        else:
            if subroutine2.instructions[0].address in found_subroutines:
                # call leading there, so can't merge with subroutine
                index += 1
            elif subroutine2.skipped_blob: #and sum(ord(x) for x in subroutine2.skipped_blob) == 0:
                # seems to have a skip alignment prefix, so should be legit call
                # TODO: catch?
                index += 1
            elif subroutine2.data_blob or subroutine2.jump_table:
                # seems to have a data prefix, so should be legit call
                # TODO: catch?
                index += 1
            else:
                for inst, label in subroutine.static_labels + subroutine.dynamic_labels:
                    if label in subroutine2:
                        result[index] = Subroutine.merge(subroutine, subroutine2)
                        del result[index+1]
                        break
                else:
                    for inst, label in subroutine2.static_labels + subroutine2.dynamic_labels:
                        if label in subroutine:
                            result[index] = Subroutine.merge(subroutine, subroutine2)
                            del result[index+1]
                            break
                    else:
                        index += 1
    return result


class Module:
    def __init__(self, application_name, exe_path, rebase_address):
        self.application_name = application_name
        self.sections, self.entry_point, self.dll_imports, self.exported_symbols = _load_exe(exe_path, rebase_address)
        self.subroutines = []
        for data, address, length, name, ro, code, virtual_length in self.sections:
            print('%s section 0x%08x - 0x%08x' % (name, address, address + length))
        print('Entry point: 0x%08x' % (self.entry_point))

    def _raw(self, section, instruction):
        if instruction.size:
            code_bytes = self.read_section_data(section, instruction.address, instruction.address + instruction.size)
            return ('%08x  ' % instruction.address) + ''.join('%02x'%c for c in code_bytes) + ' ' * (23 - instruction.size*2) + '%s%s %s' % ((instruction.precious_flags and '+' or '-'), instruction.mnemonic, instruction.op_str)
        else:
            return instruction.__class__.__name__

    def pe_section_name(self, name):
        """PE section name to place one of the executable's segments in.

        PE caps a section name at eight characters, so the original name is
        prefixed with 'g' and truncated, then disambiguated if two segments
        would collide.
        """
        name = name.decode() if isinstance(name, bytes) else name
        candidate = ('.g' + name.lstrip('._'))[:8]
        if getattr(self, '_pe_section_names', None) is None:
            self._pe_section_names = {}
        if self._pe_section_names.get(candidate) not in (None, name):
            index = 0
            while ('.g%d' % index) in self._pe_section_names:
                index += 1
            candidate = '.g%d' % index
        self._pe_section_names[candidate] = name
        return candidate

    def get_placed_segments(self):
        """The segments, as (symbol, pe_section, address, size, writable, data).

        Each entry becomes one section of the segment DLL, at the address the
        executable was built for.  A section whose virtual size exceeds its
        stored bytes contributes a second entry with no payload for the tail,
        which the loader zero-fills.
        """
        segments = []
        for data, address, length, name, ro, code, virtual_length in self.sections:
            if not data:
                continue
            name = name.decode()
            segments.append(('s_%sSegment' % name, self.pe_section_name(name),
                             address, length, not ro, data))
            if virtual_length > length:
                # No payload: the loader zero-fills an uninitialised section, so
                # the bss tail costs nothing in the file.
                segments.append(('s_%sTail' % name,
                                 self.pe_section_name(name + 'bss'),
                                 address + length, virtual_length - length,
                                 True, None))
        return segments

    def get_image_top(self):
        """First page above every placed segment.

        The executable's own code has to be linked above this, or it would land
        on top of the segments being placed.
        """
        top = 0
        for data, address, length, name, ro, code, virtual_length in self.sections:
            top = max(top, address + max(length, virtual_length))
        return (top + 0xfff) & ~0xfff

    def code_dll_name(self):
        """The DLL everything generated is compiled into."""
        return '%s_code.dll' % self.application_name

    def entry_symbol(self):
        """The one function the stub executable calls."""
        return '%sMain' % self.application_name

    def stub_name(self):
        return '%s.exe' % self.application_name

    def build_stub_exe(self):
        """Write the stub executable and the build settings that go with it."""
        directory = 'src/%s/disassembly' % self.application_name
        image_base = self.sections[0][1] & ~0xfffff
        stub = self.stub_name()

        sections, entry, size = stubexe.build(
            '%s/%s' % (directory, stub), image_base, self.get_placed_segments(),
            self.code_dll_name(), self.entry_symbol())

        top = self.get_image_top()
        with open('%s/%s.link.cmake' % (directory, self.application_name), 'w') as out:
            out.write('# Generated by the disassembler -- do not edit.\n'
                      '#\n'
                      '# %s is generated, not linked: it carries the segments at the\n'
                      '# addresses the original binary used, which no linker can be told to do.\n'
                      '# They have to be in the executable image rather than any dependency --\n'
                      '# the initial thread\'s stack is allocated before the loader resolves a\n'
                      '# single import, and it lands in this range if the image does not hold it.\n'
                      '#\n'
                      '# Everything generated therefore compiles into %s, which the\n'
                      '# stub calls through its import table. That DLL needs no fixed address and\n'
                      '# no linker-specific flags, so it builds with any toolchain.\n'
                      % (stub, self.code_dll_name()))
            out.write('set(%s_STUB_EXE "%s")\n' % (self.application_name, stub))
            out.write('set(%s_CODE_DLL "%s")\n' % (self.application_name, self.code_dll_name()))
            out.write('set(%s_ENTRY_SYMBOL "%s")\n' % (self.application_name, self.entry_symbol()))
            out.write('set(%s_SEGMENT_RANGE "0x%x-0x%x")\n'
                      % (self.application_name, image_base, top))
            out.write('\n# The export name has to match what the stub imports. If a toolchain\n'
                      '# decorates it differently, pin it with a module definition file listing\n'
                      '#     EXPORTS\n'
                      '#         %s\n' % self.entry_symbol())

        print('Wrote %s/%s (%d sections, entry 0x%08x, %d bytes)'
              % (directory, stub, len(sections), entry, size))
        for section in sections:
            print('  %-8s 0x%08x %8d bytes%s'
                  % (section.name, image_base + section.rva, section.virtual_size,
                     '' if section.data else '  (zero-filled by the loader)'))
        print('  entry stub calls %s in %s' % (self.entry_symbol(), self.code_dll_name()))

    def get_code_sections(self):
        return [s for s in self.sections if s[5]]

    def get_address(self, section):
        return section[1]

    def get_address_end(self, section):
        return section[1] + section[2]

    def add_subroutine(self, subroutine):
        self.subroutines.append(subroutine)

    def read_section_data(self, section, start, end=None):
        section_data, address, length, name, ro, code, virtual_length = section
        if end:
            return section_data[start-address : end-address]
        else:
            return section_data[start-address : ]

    def is_section_address(self, address):
        for section_data, section_address, section_length, section_name, ro, code, virtual_length in self.sections:
            if address >= section_address and address < section_address + section_length:
                return True

    def is_code_address(self, address):
        if address is None:
            return False
        for s in self.sections:
            if s[5]:
                if address >= self.sections[0][1] and address < self.sections[0][1] + self.sections[0][2]:
                    return True
        return False

    def get_dword(self, address):
        for section_data, section_address, section_length, section_name, ro, code, virtual_length in self.sections:
            if address >= section_address and address < section_address + section_length:
                if section_data:
                    dword_blob = section_data[address-section_address : address-section_address+4]
                    return (dword_blob[0])         + \
                            (dword_blob[1]) * 2**8  + \
                            (dword_blob[2]) * 2**16 + \
                            (dword_blob[3]) * 2**24
                else:
                    return 0

    def split_subroutines(self, known_subroutines):
        addresses = { }
        splits = set([])
        split_origin = { }
        for s in self.subroutines:
            addresses[s.get_entry_point()] = s
        for s in known_subroutines:
            if s not in addresses:
                splits.add(s)
        for s in self.subroutines:
            for c_address, c_dest in s.calls:
                if c_dest not in addresses:
                    if c_dest not in splits:
                        splits.add(c_dest)
                        split_origin[c_dest] = s
            for c_address, c_dest in s.dynamic_labels + s.static_labels:
                if c_dest not in s:
                    if c_dest not in addresses:
                        if c_dest not in splits:
                            splits.add(c_dest)
                            split_origin[c_dest] = s
        for split in splits:
            for index, s in enumerate(self.subroutines):
                if split in s:
                    m1, m2 = s.split(split)
                    self.subroutines[index] = m2
                    self.subroutines.insert(index, m1)
                    break
            else:
                print('oops: unknown split 0x%08x from 0x%08x' % (split, split_origin[split].instructions[0].address))

    def reduce_subroutines(self, merge_hints):
        print(merge_hints)
        print('reducing subroutines')
        found_subroutines = []
        for subroutine in self.subroutines:
            for call_address, call_dest in subroutine.calls:
                if call_dest not in found_subroutines:
                    found_subroutines.append(call_dest)
        reduced_subroutines = _reduce(self.subroutines, found_subroutines, merge_hints)
        while len(reduced_subroutines) != len(self.subroutines):
            self.subroutines = reduced_subroutines
            reduced_subroutines = _reduce(self.subroutines, found_subroutines, merge_hints)

    def generate(self, instruction, function_bounds, function_names):
        # Check for REP/REPNE prefix using Capstone's prefix array,
        # and also check the raw first byte for cases where Capstone
        # doesn't recognize undocumented F2 prefixes on string ops
        # (e.g., F2 A5 = "repne movsd", treated as rep movsd on real hardware)
        rep_prefix = None
        if instruction.bytes[0] not in (instruction.prefix[0], instruction.prefix[1], instruction.prefix[2], instruction.prefix[3], instruction.opcode[0]):
            print('Warning: Capstone did not recognize instruction prefix for instruction at 0x%08x: %s %s' % (instruction.address, instruction.mnemonic, instruction.op_str))
            rep_prefix = 'rep'
        try:
            prefix, mnemonic = instruction.mnemonic.split()
        except ValueError:
            mnemonic = instruction.mnemonic
            prefix = rep_prefix
        code = getattr(codegen, 'cg_%s'%mnemonic, _unknown)(instruction, function_bounds, function_names, *instruction.operands)
        if prefix:
            return getattr(codegen, 'cg_%s'%prefix, _unknown)(instruction, code)
        return code
