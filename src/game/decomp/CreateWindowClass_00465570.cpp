// CreateWindowClass at 0x00465570, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Until you do, every
// export rewrites it, so it follows what changes in Ghidra; once edited, an
// export only renames in it what was renamed in Ghidra. Its signature still
// belongs to Ghidra (functions.h, and the stub translated code calls it
// through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

  LONG WINAPI handleWindowsProcTrampoline(HWND param_1, uint param_2, UINT param_3, LONG param_4)
  {
    return handleWindowsProc(param_1, param_2, param_3, param_4);
  }

  BOOL CreateWindowClass(HINSTANCE hInstance)

  {
    ATOM windowAtom;
    WNDCLASSA wndClass;

    // 00465570  83ec28                 SUB ESP,0x28
    // 00465573  56                     PUSH ESI
    // 00465574  33f6                   XOR ESI,ESI
    // 00465576  68007f0000             PUSH 0x7f00
    // 0046557b  56                     PUSH ESI
    // 0046557c  8974240c               MOV dword ptr [ESP + 0xc],ESI
    wndClass.style = 0;
    // 00465580  c744241030524600       MOV dword ptr [ESP + 0x10],0x465230
    // jump back to assembly. Wil lfix soon
    wndClass.lpfnWndProc = reinterpret_cast<WNDPROC>(0x00465230);
    // 00465588  89742414               MOV dword ptr [ESP + 0x14],ESI
    wndClass.cbClsExtra = 0;
    // 0046558c  89742418               MOV dword ptr [ESP + 0x18],ESI
    wndClass.cbWndExtra = 0;
    // 00465590  894c241c               MOV dword ptr [ESP + 0x1c],ECX
    // 00465594  ff15f4714800           CALL dword ptr [0x004871f4]
    wndClass.hInstance = hInstance;
    wndClass.hIcon = win32::user32::LoadIconA((HINSTANCE)0x0, IDI_APPLICATION);
    // 0046559a  8974241c               MOV dword ptr [ESP + 0x1c],ESI
    wndClass.hCursor = (HCURSOR)0x0;
    // 0046559e  6a04                   PUSH 0x4
    // 004655a0  8944241c               MOV dword ptr [ESP + 0x1c],EAX
    // 004655a4  ff153c704800           CALL dword ptr [0x0048703c]
    wndClass.hbrBackground = (HBRUSH)win32::gdi32::GetStockObject(BLACK_BRUSH);
    // 004655aa  89742424               MOV dword ptr [ESP + 0x24],ESI
    wndClass.lpszMenuName = (LPCSTR)0x0;
    // 004655ae  c7442428ec104a00       MOV dword ptr [ESP + 0x28],0x4a10ec
    wndClass.lpszClassName = s_Comdlg32WClass_004a10ec;
    // 004655b6  89442420               MOV dword ptr [ESP + 0x20],EAX
    // 004655ba  8d442404               LEA EAX,[ESP + 0x4]
    // 004655be  50                     PUSH EAX
    // 004655bf  ff152c724800           CALL dword ptr [0x0048722c]
    windowAtom = win32::user32::RegisterClassA(&wndClass);
    // 004655c5  25ffff0000             AND EAX,0xffff
    // 004655ca  5e                     POP ESI
    // 004655cb  83c428                 ADD ESP,0x28
    // 004655ce  c3                     RET
    // 004655cf  90                     NOP
    return (uint)windowAtom;
  }

}
