// logError at 0x00424c10, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Until you do, every
// export rewrites it, so it follows what changes in Ghidra; once edited, an
// export only renames in it what was renamed in Ghidra. Its signature still
// belongs to Ghidra (functions.h, and the stub translated code calls it
// through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

void logError(LPCSTR errorMsg,...)

{
  va_list variadic;
  va_start(variadic, errorMsg);

  // 00424c10  833db4d34a0001         CMP dword ptr [0x004ad3b4],0x1
  // 00424c17  745f                   JZ 0x00424c78
  if (s_isLoggingError != 1) {
    // 00424c21  50                     PUSH EAX
    // 00424c22  51                     PUSH ECX
    // 00424c23  6848d24a00             PUSH 0x4ad248
    // 00424c28  c705b4d34a0001000000   MOV dword ptr [0x004ad3b4],0x1
    s_isLoggingError = 1;
    // 00424c19  8b4c2404               MOV ECX,dword ptr [ESP + 0x4]
    // 00424c1d  8d442408               LEA EAX,[ESP + 0x8]
    // 00424c32  e836370500             CALL 0x0047836d
    _vsprintf(s_buffer,errorMsg,variadic);
    // 00424c37  6848d24a00             PUSH 0x4ad248
    // 00424c3c  684c334900             PUSH 0x49334c
    // 00424c41  e871210500             CALL 0x00476db7
    printf(s_Error_s_0049334c,s_buffer);
    // 00424c46  68283d4a00             PUSH 0x4a3d28
    // 00424c4b  e8172d0500             CALL 0x00477967
    _fflush((FILE *)(_iob + 1));
    // 00424c50  83c418                 ADD ESP,0x18
    // 00424c53  e868feffff             CALL 0x00424ac0
    RestoreAll();
    // 00424c58  b948d24a00             MOV ECX,0x4ad248
    // 00424c5d  e8ce090400             CALL 0x00465630
    ShowErrorMessageBox(s_buffer);
    // 00424c62  e899fa0300             CALL 0x00464700
    CloseOnError();
    // 00424c67  6a01                   PUSH 0x1
    // 00424c69  c705b4d34a0000000000   MOV dword ptr [0x004ad3b4],0x0
    s_isLoggingError = 0;
    // 00424c73  e8e7390500             CALL 0x0047865f
    _exit_0047865f(1);
  }
  // 00424c78  c3                     RET
  return;
}

}
