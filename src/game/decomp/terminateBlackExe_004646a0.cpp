// terminateBlackExe at 0x004646a0, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Until you do, every
// export rewrites it, so it follows what changes in Ghidra; once edited, an
// export only renames in it what was renamed in Ghidra. Its signature still
// belongs to Ghidra (functions.h, and the stub translated code calls it
// through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

undefined4 terminateBlackExe(void)
{
	if (g_blackExeProcessHandle)
	{
		win32::kernel32::TerminateProcess(g_blackExeProcessHandle, 0);
		g_blackExeProcessHandle = nullptr;
	}
	return 0;
}

}
