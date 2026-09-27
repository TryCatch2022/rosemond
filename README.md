How this works:
===============

This project leverages information dumped by Ghidra (dump in ghidra_scripts).
It find function names, function boundaries, and other useful informations to
drive a disassembler that converts binary instructions back to pseudo C++/ASM.

The disassembler also dumps the original content of the executable in an EXE so
the data segments are accessible from the recompiled executable (.text, .data,
.rodata, etc) at the exact same location (base address of the segment) as the
original executable.

The disassembler calls trampoline to external functions like Win32/directX API
(CreateMutex, etc), Bink and Smack.

The whole thing gets recompiled into a Win32 DLL for 32 bits windows in order to
preserve binary compatibility (the x86 assembly->Win32 API part).

The goal is to keep annotating the executable in Ghidra and dump actual source
code in C/C++. When there is no more disassembly left the whole disassembler
part could be scrapped and the whole game can be compiled from source in
Windows64. Maybe someday.


Current status:
===============

Ghidra export function ranges and data (jump tables, etc) into the disassembler.
No source export just yet.
