"""Write the stub executable that carries a recompiled program's segments.

The recompiled code reaches its data through the addresses the original binary
was linked for, so those addresses have to be mapped before anything else can
claim them.  They cannot be reserved at startup: the kernel maps the executable
image, then creates the initial thread -- allocating a stack of a megabyte or
more -- and only then does the loader resolve imports.  A range the image does
not occupy is gone before any code, or any dependency, gets a say.

So the segments go into the executable itself, which is generated here rather
than linked: no linker can be told to put a section at a chosen address.  GNU ld
can (--section-start) but link.exe cannot, and writing the file directly keeps
the choice of toolchain open for everything else.

The executable holds no code beyond a few bytes of entry stub.  Everything the
disassembler generates is compiled into a DLL, based wherever the linker likes,
and the stub calls one exported function in it through the import table -- an
ordinary indirect call that the loader has filled in before the entry point
runs.
"""

import struct
import time

MACHINE_I386 = 0x014c

FILE_RELOCS_STRIPPED = 0x0001
FILE_EXECUTABLE_IMAGE = 0x0002
FILE_32BIT_MACHINE = 0x0100

SCN_CNT_CODE = 0x00000020
SCN_CNT_INITIALIZED_DATA = 0x00000040
SCN_CNT_UNINITIALIZED_DATA = 0x00000080
SCN_MEM_EXECUTE = 0x20000000
SCN_MEM_READ = 0x40000000
SCN_MEM_WRITE = 0x80000000

SECTION_ALIGNMENT = 0x1000
FILE_ALIGNMENT = 0x200
SIZE_OF_OPTIONAL_HEADER = 0xe0

SUBSYSTEM_GUI = 2
SUBSYSTEM_CONSOLE = 3

# Console while the game is being brought up, so diagnostics from the code DLL
# are visible. The original is a GUI binary; switch to SUBSYSTEM_GUI when it no
# longer needs watching.
SUBSYSTEM = SUBSYSTEM_CONSOLE

# The translated code's stack is carved out of the thread's own stack, and the
# native frames its calls build up sit below that, so the main thread needs a
# good deal more than the megabyte the original ran on. Reserved, not committed,
# so it costs nothing until used.
STACK_RESERVE = 16 * 1024 * 1024
STACK_COMMIT = 0x10000

DOS_MESSAGE = b'This program needs its code DLL beside it.\r\n$'


def _align(value, alignment):
    return (value + alignment - 1) & ~(alignment - 1)


class Section:
    def __init__(self, name, rva, virtual_size, data, characteristics):
        assert len(name) <= 8, 'PE section names are capped at eight characters: %s' % name
        self.name = name
        self.rva = rva
        self.virtual_size = virtual_size
        self.data = data or b''
        self.characteristics = characteristics
        self.file_offset = 0

    @property
    def raw_size(self):
        return _align(len(self.data), FILE_ALIGNMENT)

    def header(self):
        return struct.pack('<8sIIIIIIHHI',
                           self.name.encode(),
                           self.virtual_size,
                           self.rva,
                           self.raw_size,
                           self.file_offset if self.data else 0,
                           0, 0, 0, 0,
                           self.characteristics)


def _dos_stub():
    code = b'\x0e\x1f\xba\x0e\x00\xb4\x09\xcd\x21\xb8\x01\x4c\xcd\x21'
    stub = code + DOS_MESSAGE
    stub += b'\x00' * (-len(stub) % 8)
    pe_offset = 0x40 + len(stub)
    header = struct.pack('<2s13H4H2H10HI',
                         b'MZ',
                         0x90, 0x03, 0, 0x04, 0, 0xffff, 0, 0xb8, 0, 0, 0, 0x40, 0,
                         0, 0, 0, 0,
                         0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         pe_offset)
    assert len(header) == 0x40
    return header + stub, pe_offset


def _import_table(rva, imports):
    """Import descriptors, lookup and address tables, and the name strings.

    Returns the blob, the size of the descriptor array (which is what the data
    directory measures), and the RVA of each import's address-table slot.
    """
    descriptors_size = (len(imports) + 1) * 20

    at = rva + descriptors_size
    lookup, address = {}, {}
    for dll, functions in imports:
        lookup[dll] = at
        at += (len(functions) + 1) * 4
        address[dll] = at
        at += (len(functions) + 1) * 4

    strings, hints = [], {}
    for dll, functions in imports:
        for function in functions:
            hints[(dll, function)] = at
            entry = struct.pack('<H', 0) + function.encode() + b'\x00'
            entry += b'\x00' * (len(entry) & 1)          # keep it word aligned
            strings.append(entry)
            at += len(entry)
    names = {}
    for dll, functions in imports:
        names[dll] = at
        entry = dll.encode() + b'\x00'
        entry += b'\x00' * (len(entry) & 1)
        strings.append(entry)
        at += len(entry)

    blob = b''
    for dll, functions in imports:
        blob += struct.pack('<IIIII', lookup[dll], 0, 0, names[dll], address[dll])
    blob += b'\x00' * 20                                 # terminating descriptor
    for dll, functions in imports:
        for table in (lookup[dll], address[dll]):
            assert rva + len(blob) == table
            for function in functions:
                blob += struct.pack('<I', hints[(dll, function)])
            blob += b'\x00' * 4                          # terminating thunk
    for entry in strings:
        blob += entry

    slots = {(dll, function): address[dll] + 4 * index
             for dll, functions in imports
             for index, function in enumerate(functions)}
    return blob, descriptors_size, slots


def _entry_stub(image_base, slots, code_dll, entry_symbol):
    """call [entry]; push eax; call [ExitProcess]; int3

    Absolute addressing is safe: the image is fixed at its base and carries no
    relocations, so these slot addresses are known now.  The loader fills the
    address table before the entry point runs, which is what makes this an
    ordinary indirect call rather than anything special.
    """
    entry = image_base + slots[(code_dll, entry_symbol)]
    exit_process = image_base + slots[('kernel32.dll', 'ExitProcess')]
    return (b'\xff\x15' + struct.pack('<I', entry)
            + b'\x50'
            + b'\xff\x15' + struct.pack('<I', exit_process)
            + b'\xcc')


def build(path, image_base, segments, code_dll, entry_symbol):
    """Write the stub executable.

    ``segments`` is what get_placed_segments() returns; an entry with no payload
    becomes an uninitialised section the loader zero-fills, so a bss tail costs
    nothing in the file.
    """
    sections = []
    for symbol, pe_section, address, size, writable, data in segments:
        characteristics = SCN_MEM_READ
        if writable:
            characteristics |= SCN_MEM_WRITE
        characteristics |= (SCN_CNT_INITIALIZED_DATA if data
                            else SCN_CNT_UNINITIALIZED_DATA)
        assert address >= image_base, 'segment 0x%x is below the image base' % address
        rva = address - image_base
        assert rva % SECTION_ALIGNMENT == 0, \
            'segment 0x%x is not on a section boundary' % address
        sections.append(Section(pe_section, rva, size, data, characteristics))
    sections.sort(key=lambda s: s.rva)

    top = _align(max(s.rva + s.virtual_size for s in sections), SECTION_ALIGNMENT)
    stub_rva = top
    imports_rva = top + SECTION_ALIGNMENT

    imports = [(code_dll, [entry_symbol]), ('kernel32.dll', ['ExitProcess'])]
    import_blob, descriptors_size, slots = _import_table(imports_rva, imports)
    stub = _entry_stub(image_base, slots, code_dll, entry_symbol)

    sections.append(Section('.stub', stub_rva, len(stub), stub,
                            SCN_CNT_CODE | SCN_MEM_EXECUTE | SCN_MEM_READ))
    # The loader writes the resolved addresses into the address table.
    sections.append(Section('.idata', imports_rva, len(import_blob), import_blob,
                            SCN_CNT_INITIALIZED_DATA | SCN_MEM_READ | SCN_MEM_WRITE))

    dos, pe_offset = _dos_stub()
    size_of_headers = _align(pe_offset + 4 + 20 + SIZE_OF_OPTIONAL_HEADER
                             + 40 * len(sections), FILE_ALIGNMENT)
    assert size_of_headers <= sections[0].rva, 'headers overlap the first segment'

    offset = size_of_headers
    for section in sections:
        if section.data:
            section.file_offset = offset
            offset += section.raw_size

    size_of_image = _align(max(s.rva + s.virtual_size for s in sections),
                           SECTION_ALIGNMENT)

    # RELOCS_STRIPPED says what is true: every address in the recompiled code
    # assumes this base, so the loader must honour it or refuse to start the
    # process.  Failing loudly is the outcome to want.
    coff = struct.pack('<HHIIIHH',
                       MACHINE_I386,
                       len(sections),
                       int(time.time()),
                       0, 0,
                       SIZE_OF_OPTIONAL_HEADER,
                       FILE_EXECUTABLE_IMAGE | FILE_32BIT_MACHINE
                       | FILE_RELOCS_STRIPPED)

    optional = struct.pack('<HBBIIIIIIIIIHHHHHHIIIIHHIIIIII',
                           0x010b,                      # PE32
                           0, 0,
                           len(stub),
                           sum(s.raw_size for s in sections if s.data),
                           sum(s.virtual_size for s in sections if not s.data),
                           stub_rva,                    # AddressOfEntryPoint
                           stub_rva,                    # BaseOfCode
                           sections[0].rva,             # BaseOfData
                           image_base,
                           SECTION_ALIGNMENT,
                           FILE_ALIGNMENT,
                           4, 0, 0, 0, 4, 0,
                           0,
                           size_of_image,
                           size_of_headers,
                           0,                           # CheckSum
                           SUBSYSTEM,
                           0,                           # DllCharacteristics: no ASLR
                           STACK_RESERVE, STACK_COMMIT,
                           0x100000, 0x1000,
                           0,
                           16)
    directories = [(0, 0)] * 16
    directories[1] = (imports_rva, descriptors_size)
    directories[12] = (slots[(code_dll, entry_symbol)] & ~0xf, 0)  # IAT, informational
    optional += b''.join(struct.pack('<II', rva, size) for rva, size in directories)
    assert len(optional) == SIZE_OF_OPTIONAL_HEADER

    out = bytearray()
    out += dos
    out += b'PE\x00\x00'
    out += coff
    out += optional
    for section in sections:
        out += section.header()
    out += b'\x00' * (size_of_headers - len(out))
    for section in sections:
        if section.data:
            assert len(out) == section.file_offset
            out += section.data
            out += b'\x00' * (section.raw_size - len(section.data))

    with open(path, 'wb') as f:
        f.write(out)

    return sections, image_base + stub_rva, len(out)
