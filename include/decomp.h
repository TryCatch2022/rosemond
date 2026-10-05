#ifndef DECOMP_H_
#define DECOMP_H_

// Everything a decompiled function in src/game/decomp sees: Ghidra's types,
// globals and function prototypes (all generated into src/game/ghidra), the
// pseudo-operations the decompiler writes, the Win32 declarations translated
// code calls the API through, and guestCall for indirect calls into the game.

#include <ghidra_compat.h>
#include <lib/cbridge.h>

#include <winapi/kernel32.h>
#include <winapi/user32.h>
#include <winapi/gdi32.h>
#include <winapi/winmm.h>
#include <winapi/dinput.h>
#include <winapi/ddraw.h>
#include <winapi/dsound.h>
#include <winapi/binkw32.h>
#include <winapi/smackw32.h>

#include <types.h>
#include <globals.h>
#include <functions.h>

#endif /* !DECOMP_H_ */
