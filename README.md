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


How to:
=======

Step 1: extract the information from the ghidra project. Dump functions into
`afrh/functions.json`

```
analyzeHeadless <projdir> <projname> -process game.exe -noanalysis \
    -scriptPath ghidra_scripts \
    -postScript RecoverMissingFunctions.java

analyzeHeadless <projdir> <projname> -process game.exe -noanalysis \
    -scriptPath ghidra_scripts \
    -postScript ExportFunctionMap.java afrh/functions.json
```

Step 2: generate the reassembly files (the funny looking C++ code)

```
python disassemble_ghidra.py
```
requires Capstone installed for Python. This also creates a copy of the game
executable with the original sections - mapped at the address where the game
expects them.

Step 3: use the Cmakefile to build the whole thing for x86 Windows.
This explicitly requires an x86 compiler targeting windows 32bits as the
assembly-looking code calls the actual windows API and expects full ABI
compatibility.

Step 4: Running
Set the current working directory to the installed path (`C:\Program Files\Twister\...`)
run the recompiled game.exe from the build folder.
Alternatively copy the game.exe and the dll to the folder (rename the original
game.exe out of the way)


Internals:
==========

The python script converts the assembly routines discovered by Ghidra into
assembly-looking C++ code so that they can be compiled by a C++ compiler.

Each routine takes a WinApplication parameter (a list of functions, really)
and a CPU state (the registers).

The WinApplication is responsible mostly for kicking off the whole process -
allocate a "stack", initialize the "CPU" then call the entry point. After that
it goes into this weird emulation of x86 mode. Until it reaches the real
executable code barrier, where a trampoline transfers control to actual
executable (DLL or native function).

The disassembled/native code barrier can be crossed from both sides (ish):

 - When disassembled code calls disassembled code: just pass the winapp/cpu
   - e.g. almost all calls.
 - when disassembled code calls native code by dllimport: call the fancy pants wrapper
   - every imported method gets wrapped into a fancy template that will unpack all arguments from the WinApp/CPU and pass it to the native function
   - e.g. the disassembled code calls CreateWindowA, CreateMutex, etc etc
 - when disassembled code calls native code by callback/direct jump: call WinApplication::nativeCall/rosemondNativeCall
   - e.g. GetProcAddress
 - when native code calls disassembled code: register a trampoline in the WinApplication, and use the "function pointer" as a callback argument
   - e.g. the callback of RegisterWindowClass, EnumDevices, WindowProc, etc.


Current status:
===============

Ghidra export function ranges and data (jump tables, etc) into the disassembler.
No source export just yet.
Game appears to run.
Next step is converting assembly to C/C++ while still ensuring the game compiles and runs.
