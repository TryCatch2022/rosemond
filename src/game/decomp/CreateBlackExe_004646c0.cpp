// CreateBlackExe at 0x004646c0, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Until you do, every
// export rewrites it, so it follows what changes in Ghidra; once edited, an
// export only renames in it what was renamed in Ghidra. Its signature still
// belongs to Ghidra (functions.h, and the stub translated code calls it
// through), so change that in Ghidra.

#include <process.h>
#include <decomp.h>

namespace game
{

undefined4 CreateBlackExe(void)
{
	return 0;
	
	if (g_blackExeProcessHandle) 
		return 0;
  
	int iVar1;
	if (iVar1 = _spawnl(_P_NOWAIT, s_black_exe_004a0280, 0), iVar1 == -1) 
		logError(s_black_exe_not_found_004a026c);

	g_blackExeProcessHandle = (HANDLE)iVar1;
	return 0;
}

}
