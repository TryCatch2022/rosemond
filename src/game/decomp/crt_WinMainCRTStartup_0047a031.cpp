// crt_WinMainCRTStartup at 0x0047a031, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Re-exporting the
// function overwrites it only while it is unchanged since the export. Its
// signature still belongs to Ghidra (functions.h, and the stub that
// translated code calls it through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

  static LONG WINAPI crtTopLevelFilter(EXCEPTION_POINTERS *pointers)
  {
    // What the original __except did: _XcptFilter (which handles a few
    // signal-style exceptions), then _exit with the exception code.
    _exit(int(pointers->ExceptionRecord->ExceptionCode));
  }

  void crt_WinMainCRTStartup(void)
  {
    SetUnhandledExceptionFilter(crtTopLevelFilter);
    DWORD Version;
    char *lpszCommandLine;
    uint showWindowMode;
    HMODULE moduleHandle;
    WPARAM WVar2;
    _STARTUPINFOA startupInfo;

    Version = win32::kernel32::GetVersion();
    _winminor = Version >> 8 & 0xff;
    _winmajor = Version & 0xff;
    _winver = _winmajor * 0x100 + _winminor;
    _osver = Version >> 0x10;

    if (crt_heap_init(1) == 0)
    {
      _fast_error_exit(0x1c);
    }

    if (_mtinit() == 0)
    {
      _fast_error_exit(0x10);
    }

    _ioinit();
    cmdArgs = win32::kernel32::GetCommandLineA();
    _aenvptr = (char*)_crtGetEnvironmentStringsA();
    _setargv();
    _setenvp();
    _cinit(0);

    startupInfo.dwFlags = 0;
    win32::kernel32::GetStartupInfoA(&startupInfo);

    lpszCommandLine = (char *)_wincmdln();
    if ((startupInfo.dwFlags & 1) == 0)
    {
      showWindowMode = 10;
    }
    else
    {
      showWindowMode = (uint)startupInfo.wShowWindow;
    }

    moduleHandle = win32::kernel32::GetModuleHandleA((LPCSTR)0x0);

    WVar2 = _WinMain(moduleHandle, 0, lpszCommandLine, showWindowMode);

    _exit_0047865f(WVar2);
    return;
  }
}
