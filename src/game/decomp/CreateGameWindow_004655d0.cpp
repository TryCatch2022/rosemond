// CreateGameWindow at 0x004655d0, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Until you do, every
// export rewrites it, so it follows what changes in Ghidra; once edited, an
// export only renames in it what was renamed in Ghidra. Its signature still
// belongs to Ghidra (functions.h, and the stub translated code calls it
// through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

undefined4 CreateGameWindow(HINSTANCE hInstance,int nCmdShow)

{
  HWND hWnd;
  
  // 004655d0  56                     PUSH ESI
  // 004655d1  57                     PUSH EDI
  // 004655d2  6a00                   PUSH 0x0
  // 004655d4  51                     PUSH ECX
  // 004655d5  6a00                   PUSH 0x0
  // 004655d7  6a00                   PUSH 0x0
  // 004655d9  6a0a                   PUSH 0xa
  // 004655db  6a0a                   PUSH 0xa
  // 004655dd  6a00                   PUSH 0x0
  // 004655df  6a00                   PUSH 0x0
  // 004655e1  6800000080             PUSH 0x80000000
  // 004655e6  68fc104a00             PUSH 0x4a10fc
  // 004655eb  68ec104a00             PUSH 0x4a10ec
  // 004655f0  6a00                   PUSH 0x0
  // 004655f2  8bfa                   MOV EDI,EDX
  // 004655f4  890d00ef5100           MOV dword ptr [0x0051ef00],ECX
  // 004655fa  ff1524724800           CALL dword ptr [0x00487224]
  g_moduleHandle = hInstance;
  hWnd = win32::user32::CreateWindowExA(0,s_Comdlg32WClass_004a10ec,gHorse_WindowName,0x80000000,0,0,10,10,
                         (HWND)0x0,(HMENU)0x0,hInstance,(LPVOID)0x0);
  // 00465600  8bf0                   MOV ESI,EAX
  // 00465602  85f6                   TEST ESI,ESI
  // 00465604  7503                   JNZ 0x00465609
  if (hWnd == (HWND)0x0) {
    // 00465606  5f                     POP EDI
    // 00465607  5e                     POP ESI
    // 00465608  c3                     RET
    return 0;
  }
  // 00465609  57                     PUSH EDI
  // 0046560a  56                     PUSH ESI
  // 0046560b  893504ef5100           MOV dword ptr [0x0051ef04],ESI
  // 00465611  ff15f0714800           CALL dword ptr [0x004871f0]
  g_windowHandle = hWnd;
  win32::user32::ShowWindow(hWnd,nCmdShow);
  // 00465617  56                     PUSH ESI
  // 00465618  ff1528724800           CALL dword ptr [0x00487228]
  win32::user32::UpdateWindow(hWnd);
  // 0046561e  b801000000             MOV EAX,0x1
  // 00465623  5f                     POP EDI
  // 00465624  5e                     POP ESI
  // 00465625  c3                     RET
  return 1;
}

}
