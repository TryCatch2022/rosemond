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
   - e.g. COM object's cursed "vtable". When the disassembled code calls a COM object's method then it goes through the native call path,
     unpacks all arguments from the CPU structure and the stack, and pass them to the real DirectX DLL for an actual call.
 - when native code calls disassembled code: register a trampoline in the WinApplication, and use the "function pointer" as a callback argument
   - e.g. the callback of RegisterWindowClass, EnumDevices, WindowProc, etc.


Decompiling functions to C++:
=============================

Functions move from translated assembly to C++ one at a time, using Ghidra's
decompiler on the annotated project (`ghidra project/RosemondHill`):

```
python decompile.py 0x407690 0x4098a0   # decompile these, refresh everything else
python decompile.py                     # only refresh what Ghidra owns
```

This runs `ghidra_scripts/ExportDecompiled.java` headless (read-only; nothing is
saved to the project) and then `disassemble_ghidra.py`. Headless Ghidra cannot
open a project the GUI has open: either close the GUI, or run
ExportDecompiled.java from the GUI's Script Manager (it exports the function
under the cursor; bind it to a key) and then run `python disassemble_ghidra.py`.

Each exported function carries its machine code in comments: the
instructions each line came from, above that line, every instruction listed
once. That is what to check the C against. Pass `--no-asm` to leave them out.

Who owns what:

 - `src/game/decomp/<name>_<address>.cpp`: the decompiled function. It belongs
   to the project: fix it up, rename things, edit it freely. Exporting the
   function again overwrites it only while it has no uncommitted changes in git;
   otherwise the fresh decompilation is written to `<file>.ghidra` to diff.
 - `src/game/decomp/registry.json`: which functions are C++. The disassembler
   does not translate those. To give a function back to the translator, delete
   its file and its entry -- also the quickest way to find which decompiled
   function broke something.
 - `src/game/ghidra/`: types (`types.h`), globals (`globals.h`), a prototype
   for every function (`functions.h`, `prototypes.json`). These belong to
   Ghidra and are rewritten on every run, so fix types and signatures in Ghidra.
   That includes the signatures of decompiled functions.

How the two worlds call each other (`disasm/cstubs.py`, generated into
`src/game/disassembly/game.cstubs.cpp`):

 - Translated code calling a decompiled function still calls `sub_xxx(app, cpu)`;
   that is now a stub which reads the arguments from the emulated registers and
   stack, calls the C++ function, puts the result in eax/edx:eax/st0, restores
   the other registers, and pops what the original pops.
 - Decompiled code calling a translated routine calls an ordinary C++ function
   with Ghidra's prototype; that is a stub which puts the arguments where the
   routine expects them and runs it on the CPU of the current thread
   (`win32::currentCpu()`, see `include/lib/cbridge.h`).
 - Where each argument lives comes from Ghidra's parameter storage, not from the
   calling convention's name. Fastcall with stack arguments, thiscall and so on
   all work, provided the signature in Ghidra is right.
 - Globals are references to their address in the image
   (`inline int &g_X = *reinterpret_cast<int *>(0x4abb20);`); the sections are
   mapped where the game expects them, so C++ and translated code share them.
 - A routine's address used as a value (a callback stored in a structure) is
   written `ghidra::code_address(0x401010)`: the address translated code calls
   through `dynamic_call`, not a C++ function pointer. Indirect calls the other
   way (`(**(code **)(*p + 8))(p)`) go through `win32::guestCall` /
   `win32::guestCallThis`.

Decompiled code is built with `-fpermissive -fno-strict-aliasing` and without
`-Werror`, because Ghidra's C converts between integers and pointers and
reinterprets memory the way the machine code did. With MSVC, which has no
`-fpermissive`, those conversions have to be cleaned up by hand.

The project is owned by its creator in `project.prp`; Ghidra refuses to open
someone else's project. Change OWNER there, or run headless with
`GHIDRA_HEADLESS_JAVA_OPTIONS=-Duser.name=<owner>`.


Current status:
===============

Ghidra export function ranges and data (jump tables, etc) into the disassembler.
Functions can be moved to decompiled C++ one at a time (see above).
Game appears to run.
Next step is converting assembly to C/C++ while still ensuring the game compiles and runs.
