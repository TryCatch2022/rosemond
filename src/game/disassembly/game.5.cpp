#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_41eb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041eb90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041eb91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041eb92  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041eb94  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 0041eb99  b9341a4900             -mov ecx, 0x491a34
    cpu.ecx = 4790836 /*0x491a34*/;
    // 0041eb9e  e89dde0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041eba3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041eba5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041eba7  750d                   -jne 0x41ebb6
    if (!cpu.flags.zf)
    {
        goto L_0x0041ebb6;
    }
    // 0041eba9  68181a4900             -push 0x491a18
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790808 /*0x491a18*/;
    cpu.esp -= 4;
    // 0041ebae  e85d600000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ebb3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041ebb6:
    // 0041ebb6  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041ebb8  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041ebba  e861000000             -call 0x41ec20
    cpu.esp -= 4;
    sub_41ec20(app, cpu);
    // 0041ebbf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ebc0  e8128a0500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041ebc5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ebc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ebc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ebca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ebd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ebd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ebd1  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041ebd3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ebd4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ebd5  8b8384000000           -mov eax, dword ptr [ebx + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(132) /* 0x84 */);
    // 0041ebdb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ebdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ebde  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0041ebe0  7439                   -je 0x41ec1b
    if (cpu.flags.zf)
    {
        goto L_0x0041ec1b;
    }
    // 0041ebe2  8bb380000000           -mov esi, dword ptr [ebx + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(128) /* 0x80 */);
    // 0041ebe8  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041ebea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ebec  7e2d                   -jle 0x41ec1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ec1b;
    }
L_0x0041ebee:
    // 0041ebee  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041ebf0  750d                   -jne 0x41ebff
    if (!cpu.flags.zf)
    {
        goto L_0x0041ebff;
    }
    // 0041ebf2  68441a4900             -push 0x491a44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790852 /*0x491a44*/;
    cpu.esp -= 4;
    // 0041ebf7  e814600000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ebfc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041ebff:
    // 0041ebff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ec00  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ec02  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0041ec04  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ec05  e8958b0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041ec0a  8b8384000000           -mov eax, dword ptr [ebx + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(132) /* 0x84 */);
    // 0041ec10  8b761c                 -mov esi, dword ptr [esi + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041ec13  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ec16  47                     -inc edi
    (cpu.edi)++;
    // 0041ec17  3bf8                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ec19  7cd3                   -jl 0x41ebee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ebee;
    }
L_0x0041ec1b:
    // 0041ec1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ec20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ec20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ec21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ec22  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041ec24  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0041ec26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ec27  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ec29  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041ec2f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ec31  83c048                 -add eax, 0x48
    (cpu.eax) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0041ec34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ec35  e8658b0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041ec3a  8b86fc020000           -mov eax, dword ptr [esi + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */);
    // 0041ec40  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ec43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ec45  750a                   -jne 0x41ec51
    if (!cpu.flags.zf)
    {
        goto L_0x0041ec51;
    }
    // 0041ec47  c786f802000000000000   -mov dword ptr [esi + 0x2f8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(760) /* 0x2f8 */) = 0 /*0x0*/;
L_0x0041ec51:
    // 0041ec51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ec52  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ec53  8dbef8020000           -lea edi, [esi + 0x2f8]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(760) /* 0x2f8 */);
    // 0041ec59  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ec5b  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041ec5d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ec5e  e83c8b0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041ec63  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0041ec65  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ec68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ec6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec6b  740f                   -je 0x41ec7c
    if (cpu.flags.zf)
    {
        goto L_0x0041ec7c;
    }
    // 0041ec6d  8b8efc020000           -mov ecx, dword ptr [esi + 0x2fc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */);
    // 0041ec73  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0041ec75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec76  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec77  e964230000             -jmp 0x420fe0
    return sub_420fe0(app, cpu);
L_0x0041ec7c:
    // 0041ec7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ec7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ec80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ec80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ec81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ec82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ec83  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 0041ec88  b9881a4900             -mov ecx, 0x491a88
    cpu.ecx = 4790920 /*0x491a88*/;
    // 0041ec8d  e8aedd0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041ec92  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041ec94  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041ec96  750d                   -jne 0x41eca5
    if (!cpu.flags.zf)
    {
        goto L_0x0041eca5;
    }
    // 0041ec98  686c1a4900             -push 0x491a6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790892 /*0x491a6c*/;
    cpu.esp -= 4;
    // 0041ec9d  e86e5f0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041eca2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041eca5:
    // 0041eca5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041eca6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041eca8  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041ecaa  686c185200             -push 0x52186c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380204 /*0x52186c*/;
    cpu.esp -= 4;
    // 0041ecaf  e8eb8a0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041ecb4  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 0041ecb9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ecbc  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041ecbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ecc0  7e4d                   -jle 0x41ed0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ed0f;
    }
L_0x0041ecc2:
    // 0041ecc2  8b04b560185200         -mov eax, dword ptr [esi*4 + 0x521860]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.esi * 4);
    // 0041ecc9  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041eccf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ecd0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ecd2  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0041ecd5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ecd7  8b82ec020000           -mov eax, dword ptr [edx + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 0041ecdd  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041ece1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041ece2  8a4848                 -mov cl, byte ptr [eax + 0x48]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0041ece5  884c2418               -mov byte ptr [esp + 0x18], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.cl;
    // 0041ece9  e8b18a0500             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0041ecee  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041ecf2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041ecf7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ecf8  685c1a4900             -push 0x491a5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790876 /*0x491a5c*/;
    cpu.esp -= 4;
    // 0041ecfd  e8b5800500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041ed02  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 0041ed07  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041ed0a  46                     -inc esi
    (cpu.esi)++;
    // 0041ed0b  3bf0                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ed0d  7cb3                   -jl 0x41ecc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ecc2;
    }
L_0x0041ed0f:
    // 0041ed0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ed10  e8c2880500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041ed15  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ed18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ed19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ed1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ed1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ed20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ed20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ed21  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041ed23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ed24  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0041ed29  b9341a4900             -mov ecx, 0x491a34
    cpu.ecx = 4790836 /*0x491a34*/;
    // 0041ed2e  e80ddd0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041ed33  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041ed35  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041ed37  7536                   -jne 0x41ed6f
    if (!cpu.flags.zf)
    {
        goto L_0x0041ed6f;
    }
    // 0041ed39  68981a4900             -push 0x491a98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790936 /*0x491a98*/;
    cpu.esp -= 4;
    // 0041ed3e  e874800500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041ed43  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ed46  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041ed48  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ed4a  e871030000             -call 0x41f0c0
    cpu.esp -= 4;
    sub_41f0c0(app, cpu);
    // 0041ed4f  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041ed51  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041ed53  89befc020000           -mov dword ptr [esi + 0x2fc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */) = cpu.edi;
    // 0041ed59  e802140000             -call 0x420160
    cpu.esp -= 4;
    sub_420160(app, cpu);
    // 0041ed5e  8b8730010000           -mov eax, dword ptr [edi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(304) /* 0x130 */);
    // 0041ed64  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0041ed66  898730010000           -mov dword ptr [edi + 0x130], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 0041ed6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ed6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ed6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ed6f:
    // 0041ed6f  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041ed71  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041ed73  e8c8000000             -call 0x41ee40
    cpu.esp -= 4;
    sub_41ee40(app, cpu);
    // 0041ed78  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041ed7a  e8e1130000             -call 0x420160
    cpu.esp -= 4;
    sub_420160(app, cpu);
    // 0041ed7f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ed80  e852880500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041ed85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ed88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ed89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ed8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ed90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ed90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ed91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ed92  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0041ed97  b9341a4900             -mov ecx, 0x491a34
    cpu.ecx = 4790836 /*0x491a34*/;
    // 0041ed9c  e89fdc0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041eda1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041eda3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041eda5  7515                   -jne 0x41edbc
    if (!cpu.flags.zf)
    {
        goto L_0x0041edbc;
    }
    // 0041eda7  68981a4900             -push 0x491a98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790936 /*0x491a98*/;
    cpu.esp -= 4;
    // 0041edac  e806800500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041edb1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041edb4  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0041edb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041edba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041edbb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041edbc:
    // 0041edbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041edbd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041edbf  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041edc3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041edc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041edc6  e8bd880500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041edcb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041edcc  e806880500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041edd1  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041edd5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041edd8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041eddd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041edde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eddf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ede0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ede1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ede2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ede3  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041ede5  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ede7  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0041ede9  8b8784000000           -mov eax, dword ptr [edi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 0041edef  899f80000000           -mov dword ptr [edi + 0x80], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */) = cpu.ebx;
    // 0041edf5  3bc3                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041edf7  7e3c                   -jle 0x41ee35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ee35;
    }
    // 0041edf9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0041edfa:
    // 0041edfa  e8e1080000             -call 0x41f6e0
    cpu.esp -= 4;
    sub_41f6e0(app, cpu);
    // 0041edff  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ee01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041ee02  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ee04  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0041ee06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ee07  e87c880500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041ee0c  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0041ee13  8b8f80000000           -mov ecx, dword ptr [edi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0041ee19  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ee1c  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041ee1e  e84d090000             -call 0x41f770
    cpu.esp -= 4;
    sub_41f770(app, cpu);
    // 0041ee23  898780000000           -mov dword ptr [edi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0041ee29  8b8784000000           -mov eax, dword ptr [edi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 0041ee2f  43                     -inc ebx
    (cpu.ebx)++;
    // 0041ee30  3bd8                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ee32  7cc6                   -jl 0x41edfa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041edfa;
    }
    // 0041ee34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041ee35:
    // 0041ee35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ee36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ee37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ee38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ee40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ee40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ee41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ee42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ee43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ee44  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041ee46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ee47  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ee49  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041ee4d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ee4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ee50  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041ee52  e831880500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041ee57  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041ee5b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041ee61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ee62  68dc1a4900             -push 0x491adc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791004 /*0x491adc*/;
    cpu.esp -= 4;
    // 0041ee67  e84b7f0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041ee6c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ee6d  8d9ef8020000           -lea ebx, [esi + 0x2f8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(760) /* 0x2f8 */);
    // 0041ee73  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ee75  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041ee77  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ee78  e80b880500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041ee7d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0041ee7f  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041ee82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ee84  7521                   -jne 0x41eea7
    if (!cpu.flags.zf)
    {
        goto L_0x0041eea7;
    }
    // 0041ee86  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041ee88  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ee8a  e831020000             -call 0x41f0c0
    cpu.esp -= 4;
    sub_41f0c0(app, cpu);
    // 0041ee8f  8986fc020000           -mov dword ptr [esi + 0x2fc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */) = cpu.eax;
    // 0041ee95  68c01a4900             -push 0x491ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4790976 /*0x491ac0*/;
    cpu.esp -= 4;
    // 0041ee9a  e8187f0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041ee9f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041eea2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eea3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eea4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eea5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eea6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041eea7:
    // 0041eea7  e884010000             -call 0x41f030
    cpu.esp -= 4;
    sub_41f030(app, cpu);
    // 0041eeac  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041eeae  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041eeb0  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0041eeb2  e8f9210000             -call 0x4210b0
    cpu.esp -= 4;
    sub_4210b0(app, cpu);
    // 0041eeb7  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041eeb9  899efc020000           -mov dword ptr [esi + 0x2fc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */) = cpu.ebx;
    // 0041eebf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eec0  89932c010000           -mov dword ptr [ebx + 0x12c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(300) /* 0x12c */) = cpu.edx;
    // 0041eec6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eec7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eec8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041eec9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41eed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041eed0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041eed3  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0041eed8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041eed9  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041eedb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041eedc  b9881a4900             -mov ecx, 0x491a88
    cpu.ecx = 4790920 /*0x491a88*/;
    // 0041eee1  e85adb0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0041eee6  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041eee8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041eeea  751e                   -jne 0x41ef0a
    if (!cpu.flags.zf)
    {
        goto L_0x0041ef0a;
    }
    // 0041eeec  680c1b4900             -push 0x491b0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791052 /*0x491b0c*/;
    cpu.esp -= 4;
    // 0041eef1  e8c17e0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041eef6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041eef9  c70309000000           -mov dword ptr [ebx], 9
    app->getMemory<x86::reg32>(cpu.ebx) = 9 /*0x9*/;
    // 0041eeff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041ef04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ef05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ef06  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ef09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ef0a:
    // 0041ef0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ef0b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ef0d  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041ef11  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0041ef13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ef14  e86f870500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041ef19  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041ef1d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ef20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ef22  7f12                   -jg 0x41ef36
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041ef36;
    }
    // 0041ef24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ef25  68ec1a4900             -push 0x491aec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791020 /*0x491aec*/;
    cpu.esp -= 4;
    // 0041ef2a  e8e15c0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ef2f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041ef33  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041ef36:
    // 0041ef36  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ef37  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041ef39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ef3b  7e28                   -jle 0x41ef65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ef65;
    }
L_0x0041ef3d:
    // 0041ef3d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ef3e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ef40  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041ef44  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ef46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ef47  e83c870500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041ef4c  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041ef50  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0041ef54  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041ef5a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041ef5d  8914b3                 -mov dword ptr [ebx + esi*4], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.esi * 4) = cpu.edx;
    // 0041ef60  46                     -inc esi
    (cpu.esi)++;
    // 0041ef61  3bf0                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ef63  7cd8                   -jl 0x41ef3d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ef3d;
    }
L_0x0041ef65:
    // 0041ef65  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ef66  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ef68  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041ef6c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ef6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ef6f  e814870500             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0041ef74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ef75  e85d860500             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0041ef7a  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041ef7e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041ef81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ef82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ef83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ef84  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041ef87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41ef90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041ef90  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 0041ef95  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041ef98  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041ef9d  48                     -dec eax
    (cpu.eax)--;
    // 0041ef9e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ef9f  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041efa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041efa3  7748                   -ja 0x41efed
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041efed;
    }
    // 0041efa5  ff2485f4ef4100         -jmp dword ptr [eax*4 + 0x41eff4]
    cpu.ip = app->getMemory<x86::reg32>(4321268 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041efac:
    // 0041efac  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0041efb1  e85ab3ffff             -call 0x41a310
    cpu.esp -= 4;
    sub_41a310(app, cpu);
    // 0041efb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041efb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041efb8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041efbb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041efbc:
    // 0041efbc  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041efc0  e80bffffff             -call 0x41eed0
    cpu.esp -= 4;
    sub_41eed0(app, cpu);
    // 0041efc5  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041efc7  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041efc9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041efcb  7e20                   -jle 0x41efed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041efed;
    }
L_0x0041efcd:
    // 0041efcd  8b4cb408               -mov ecx, dword ptr [esp + esi*4 + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    // 0041efd1  e83ab3ffff             -call 0x41a310
    cpu.esp -= 4;
    sub_41a310(app, cpu);
    // 0041efd6  46                     -inc esi
    (cpu.esi)++;
    // 0041efd7  3bf7                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041efd9  7cf2                   -jl 0x41efcd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041efcd;
    }
    // 0041efdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041efdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041efdd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041efe0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041efe1:
    // 0041efe1  e8aafdffff             -call 0x41ed90
    cpu.esp -= 4;
    sub_41ed90(app, cpu);
    // 0041efe6  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041efe8  e823b3ffff             -call 0x41a310
    cpu.esp -= 4;
    sub_41a310(app, cpu);
L_0x0041efed:
    // 0041efed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041efee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041efef  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041eff2  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41f010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f010  e80b120000             -call 0x420220
    cpu.esp -= 4;
    sub_420220(app, cpu);
    // 0041f015  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f017  750b                   -jne 0x41f024
    if (!cpu.flags.zf)
    {
        goto L_0x0041f024;
    }
    // 0041f019  68281b4900             -push 0x491b28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791080 /*0x491b28*/;
    cpu.esp -= 4;
    // 0041f01e  e8947d0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041f023  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041f024:
    // 0041f024  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f030  a1a4185200             -mov eax, dword ptr [0x5218a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */);
    // 0041f035  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f037  7555                   -jne 0x41f08e
    if (!cpu.flags.zf)
    {
        goto L_0x0041f08e;
    }
    // 0041f039  6880270000             -push 0x2780
    app->getMemory<x86::reg32>(cpu.esp-4) = 10112 /*0x2780*/;
    cpu.esp -= 4;
    // 0041f03e  e837820500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0041f043  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f046  a3a4185200             -mov dword ptr [0x5218a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */) = cpu.eax;
    // 0041f04b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f04d  7512                   -jne 0x41f061
    if (!cpu.flags.zf)
    {
        goto L_0x0041f061;
    }
    // 0041f04f  68401b4900             -push 0x491b40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791104 /*0x491b40*/;
    cpu.esp -= 4;
    // 0041f054  e8b75b0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f059  a1a4185200             -mov eax, dword ptr [0x5218a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */);
    // 0041f05e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f061:
    // 0041f061  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0041f063:
    // 0041f063  8d94013c010000         -lea edx, [ecx + eax + 0x13c]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(316) /* 0x13c */ + cpu.eax * 1);
    // 0041f06a  89940138010000         -mov dword ptr [ecx + eax + 0x138], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(312) /* 0x138 */ + cpu.eax * 1) = cpu.edx;
    // 0041f071  a1a4185200             -mov eax, dword ptr [0x5218a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */);
    // 0041f076  81c13c010000           -add ecx, 0x13c
    (cpu.ecx) += x86::reg32(x86::sreg32(316 /*0x13c*/));
    // 0041f07c  81f944260000           +cmp ecx, 0x2644
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9796 /*0x2644*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f082  7cdf                   -jl 0x41f063
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041f063;
    }
    // 0041f084  c7807c27000000000000   -mov dword ptr [eax + 0x277c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10108) /* 0x277c */) = 0 /*0x0*/;
L_0x0041f08e:
    // 0041f08e  8b15a4185200           -mov edx, dword ptr [0x5218a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */);
    // 0041f094  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f095  b94f000000             -mov ecx, 0x4f
    cpu.ecx = 79 /*0x4f*/;
    // 0041f09a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f09c  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041f09e  f3ab                   -rep stosd dword ptr es:[edi], eax
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
        }
        else
        {
            cpu.edi += 4;
        }
        --cpu.ecx;
    }
    // 0041f0a0  8b0da4185200           -mov ecx, dword ptr [0x5218a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */);
    // 0041f0a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f0a7  8b8138010000           -mov eax, dword ptr [ecx + 0x138]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(312) /* 0x138 */);
    // 0041f0ad  a3a4185200             -mov dword ptr [0x5218a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */) = cpu.eax;
    // 0041f0b2  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041f0b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f0c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041f0c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041f0c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f0c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f0c4  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041f0c6  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0041f0c8  e863ffffff             -call 0x41f030
    cpu.esp -= 4;
    sub_41f030(app, cpu);
    // 0041f0cd  8b0d98184900           -mov ecx, dword ptr [0x491898]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f0d3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041f0d5  8d44ad00               -lea eax, [ebp + ebp*4]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 4);
    // 0041f0d9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0041f0dc  8d5e06                 -lea ebx, [esi + 6]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0041f0df  8b540804               -mov edx, dword ptr [eax + ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
L_0x0041f0e3:
    // 0041f0e3  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0041f0e5  42                     -inc edx
    (cpu.edx)++;
    // 0041f0e6  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0041f0e8  43                     -inc ebx
    (cpu.ebx)++;
    // 0041f0e9  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0041f0eb  75f6                   -jne 0x41f0e3
    if (!cpu.flags.zf)
    {
        goto L_0x0041f0e3;
    }
    // 0041f0ed  c70610f04100           -mov dword ptr [esi], 0x41f010
    app->getMemory<x86::reg32>(cpu.esi) = 4321296 /*0x41f010*/;
    // 0041f0f3  66c746040100           -mov word ptr [esi + 4], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0041f0f9  896e48                 -mov dword ptr [esi + 0x48], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.ebp;
    // 0041f0fc  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f102  8b4c1008               -mov ecx, dword ptr [eax + edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.edx * 1);
    // 0041f106  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 0041f109  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f10f  8b4c100c               -mov ecx, dword ptr [eax + edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 1);
    // 0041f113  894e58                 -mov dword ptr [esi + 0x58], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.ecx;
    // 0041f116  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f11c  8b4c1010               -mov ecx, dword ptr [eax + edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */ + cpu.edx * 1);
    // 0041f120  894e60                 -mov dword ptr [esi + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0041f123  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f129  8b4c1014               -mov ecx, dword ptr [eax + edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */ + cpu.edx * 1);
    // 0041f12d  894e5c                 -mov dword ptr [esi + 0x5c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ecx;
    // 0041f130  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f136  8b4c1018               -mov ecx, dword ptr [eax + edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */ + cpu.edx * 1);
    // 0041f13a  894e6c                 -mov dword ptr [esi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0041f13d  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f143  8b4c101c               -mov ecx, dword ptr [eax + edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */ + cpu.edx * 1);
    // 0041f147  894e68                 -mov dword ptr [esi + 0x68], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.ecx;
    // 0041f14a  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f150  8b4c1020               -mov ecx, dword ptr [eax + edx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */ + cpu.edx * 1);
    // 0041f154  894e78                 -mov dword ptr [esi + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 0041f157  8b1598184900           -mov edx, dword ptr [0x491898]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4790424) /* 0x491898 */);
    // 0041f15d  8b441024               -mov eax, dword ptr [eax + edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */ + cpu.edx * 1);
    // 0041f161  894674                 -mov dword ptr [esi + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0041f164  8b8ff8020000           -mov ecx, dword ptr [edi + 0x2f8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(760) /* 0x2f8 */);
    // 0041f16a  83c908                 -or ecx, 8
    cpu.ecx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f16d  898ff8020000           -mov dword ptr [edi + 0x2f8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(760) /* 0x2f8 */) = cpu.ecx;
    // 0041f173  c786280100000000003f   -mov dword ptr [esi + 0x128], 0x3f000000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = 1056964608 /*0x3f000000*/;
    // 0041f17d  c78614010000ffffffff   -mov dword ptr [esi + 0x114], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */) = 4294967295 /*0xffffffff*/;
    // 0041f187  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041f189  898e2c010000           -mov dword ptr [esi + 0x12c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(300) /* 0x12c */) = cpu.ecx;
    // 0041f18f  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f191  e8ca0b0100             -call 0x42fd60
    cpu.esp -= 4;
    sub_42fd60(app, cpu);
    // 0041f196  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041f198  8b9380000000           -mov edx, dword ptr [ebx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(128) /* 0x80 */);
    // 0041f19e  89564c                 -mov dword ptr [esi + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0041f1a1  8b87ec020000           -mov eax, dword ptr [edi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(748) /* 0x2ec */);
    // 0041f1a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f1a9  750d                   -jne 0x41f1b8
    if (!cpu.flags.zf)
    {
        goto L_0x0041f1b8;
    }
    // 0041f1ab  68881b4900             -push 0x491b88
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791176 /*0x491b88*/;
    cpu.esp -= 4;
    // 0041f1b0  e85b5a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f1b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f1b8:
    // 0041f1b8  8b87ec020000           -mov eax, dword ptr [edi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(748) /* 0x2ec */);
    // 0041f1be  895828                 -mov dword ptr [eax + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0041f1c1  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 0041f1c4  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f1c7  7c0f                   -jl 0x41f1d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041f1d8;
    }
    // 0041f1c9  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f1cc  7f0a                   -jg 0x41f1d8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041f1d8;
    }
    // 0041f1ce  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0041f1d1  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041f1d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f1d8:
    // 0041f1d8  68581b4900             -push 0x491b58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791128 /*0x491b58*/;
    cpu.esp -= 4;
    // 0041f1dd  e8d57b0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041f1e2  8b4e4c                 -mov ecx, dword ptr [esi + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 0041f1e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f1e8  894e50                 -mov dword ptr [esi + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0041f1eb  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041f1ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f1f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0041f440;
    // 0041f200  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f201  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f202  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041f204  8bb7fc020000           -mov esi, dword ptr [edi + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(764) /* 0x2fc */);
    // 0041f20a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f20c  750d                   -jne 0x41f21b
    if (!cpu.flags.zf)
    {
        goto L_0x0041f21b;
    }
    // 0041f20e  68581c4900             -push 0x491c58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791384 /*0x491c58*/;
    cpu.esp -= 4;
    // 0041f213  e8f8590000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f218  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f21b:
    // 0041f21b  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0041f21e  48                     -dec eax
    (cpu.eax)--;
    // 0041f21f  83f816                 +cmp eax, 0x16
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22 /*0x16*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f222  0f87b2000000           -ja 0x41f2da
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        return sub_41f2da(app, cpu);
    }
    // 0041f228  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041f22a  8a882cf34100           -mov cl, byte ptr [eax + 0x41f32c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4322092) /* 0x41f32c */);
    // 0041f230  ff248d04f34100         -jmp dword ptr [ecx*4 + 0x41f304]
    return app->dynamic_call(app->getMemory<x86::reg32>(4322052 + cpu.ecx * 4), cpu);
L_entry_0x0041f440:
    // 0041f440  a104ca4a00             -mov eax, dword ptr [0x4aca04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901380) /* 0x4aca04 */);
    // 0041f445  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f446  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f448  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041f44a  750f                   -jne 0x41f45b
    if (!cpu.flags.zf)
    {
        goto L_0x0041f45b;
    }
    // 0041f44c  e85ff5ffff             -call 0x41e9b0
    cpu.esp -= 4;
    sub_41e9b0(app, cpu);
    // 0041f451  c70504ca4a0001000000   -mov dword ptr [0x4aca04], 1
    app->getMemory<x86::reg32>(x86::reg32(4901380) /* 0x4aca04 */) = 1 /*0x1*/;
L_0x0041f45b:
    // 0041f45b  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f461  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f463  750d                   -jne 0x41f472
    if (!cpu.flags.zf)
    {
        goto L_0x0041f472;
    }
    // 0041f465  68f01c4900             -push 0x491cf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791536 /*0x491cf0*/;
    cpu.esp -= 4;
    // 0041f46a  e8a1570000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f46f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f472:
    // 0041f472  8b86fc020000           -mov eax, dword ptr [esi + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */);
    // 0041f478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f47a  7544                   -jne 0x41f4c0
    if (!cpu.flags.zf)
    {
        goto L_0x0041f4c0;
    }
    // 0041f47c  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 0041f481  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f483  7333                   -jae 0x41f4b8
    if (!cpu.flags.cf)
    {
        goto L_0x0041f4b8;
    }
    // 0041f485  3c06                   +cmp al, 6
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f487  7227                   -jb 0x41f4b0
    if (cpu.flags.cf)
    {
        goto L_0x0041f4b0;
    }
    // 0041f489  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f48b  7423                   -je 0x41f4b0
    if (cpu.flags.zf)
    {
        goto L_0x0041f4b0;
    }
    // 0041f48d  e8fef8ffff             -call 0x41ed90
    cpu.esp -= 4;
    sub_41ed90(app, cpu);
    // 0041f492  8b8eec020000           -mov ecx, dword ptr [esi + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f498  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f49a  8a5148                 -mov dl, byte ptr [ecx + 0x48]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0041f49d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f49f  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f4a1  750f                   -jne 0x41f4b2
    if (!cpu.flags.zf)
    {
        goto L_0x0041f4b2;
    }
    // 0041f4a3  e878f8ffff             -call 0x41ed20
    cpu.esp -= 4;
    sub_41ed20(app, cpu);
    // 0041f4a8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f4aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4ab  e910ffffff             -jmp 0x41f3c0
    return sub_41f3c0(app, cpu);
L_0x0041f4b0:
    // 0041f4b0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0041f4b2:
    // 0041f4b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4b3  e918000000             -jmp 0x41f4d0
    goto L_0x0041f4d0;
L_0x0041f4b8:
    // 0041f4b8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f4ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4bb  e960f8ffff             -jmp 0x41ed20
    return sub_41ed20(app, cpu);
L_0x0041f4c0:
    // 0041f4c0  68b01c4900             -push 0x491cb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791472 /*0x491cb0*/;
    cpu.esp -= 4;
    // 0041f4c5  e846570000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f4ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f4cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f4d0:
    // 0041f4d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f4d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041f4d3  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f4d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f4db  750d                   -jne 0x41f4ea
    if (!cpu.flags.zf)
    {
        goto L_0x0041f4ea;
    }
    // 0041f4dd  68081d4900             -push 0x491d08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791560 /*0x491d08*/;
    cpu.esp -= 4;
    // 0041f4e2  e829570000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f4e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f4ea:
    // 0041f4ea  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f4f0  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041f4f2  8a4848                 -mov cl, byte ptr [eax + 0x48]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0041f4f5  e826000000             -call 0x41f520
    cpu.esp -= 4;
    sub_41f520(app, cpu);
    // 0041f4fa  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041f4fc  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041f4fe  e8bdfbffff             -call 0x41f0c0
    cpu.esp -= 4;
    sub_41f0c0(app, cpu);
    // 0041f503  8986fc020000           -mov dword ptr [esi + 0x2fc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */) = cpu.eax;
    // 0041f509  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f50b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f50c  e99ffeffff             -jmp 0x41f3b0
    return sub_41f3b0(app, cpu);
}

/* align: skip  */
void Application::sub_41f200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f200  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f201  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f202  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041f204  8bb7fc020000           -mov esi, dword ptr [edi + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(764) /* 0x2fc */);
    // 0041f20a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f20c  750d                   -jne 0x41f21b
    if (!cpu.flags.zf)
    {
        goto L_0x0041f21b;
    }
    // 0041f20e  68581c4900             -push 0x491c58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791384 /*0x491c58*/;
    cpu.esp -= 4;
    // 0041f213  e8f8590000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f218  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f21b:
    // 0041f21b  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0041f21e  48                     -dec eax
    (cpu.eax)--;
    // 0041f21f  83f816                 +cmp eax, 0x16
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22 /*0x16*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f222  0f87b2000000           -ja 0x41f2da
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        return sub_41f2da(app, cpu);
    }
    // 0041f228  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041f22a  8a882cf34100           -mov cl, byte ptr [eax + 0x41f32c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4322092) /* 0x41f32c */);
    // 0041f230  ff248d04f34100         -jmp dword ptr [ecx*4 + 0x41f304]
    return app->dynamic_call(app->getMemory<x86::reg32>(4322052 + cpu.ecx * 4), cpu);
    // 0041f440  a104ca4a00             -mov eax, dword ptr [0x4aca04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901380) /* 0x4aca04 */);
    // 0041f445  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f446  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f448  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041f44a  750f                   -jne 0x41f45b
    if (!cpu.flags.zf)
    {
        goto L_0x0041f45b;
    }
    // 0041f44c  e85ff5ffff             -call 0x41e9b0
    cpu.esp -= 4;
    sub_41e9b0(app, cpu);
    // 0041f451  c70504ca4a0001000000   -mov dword ptr [0x4aca04], 1
    app->getMemory<x86::reg32>(x86::reg32(4901380) /* 0x4aca04 */) = 1 /*0x1*/;
L_0x0041f45b:
    // 0041f45b  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f461  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f463  750d                   -jne 0x41f472
    if (!cpu.flags.zf)
    {
        goto L_0x0041f472;
    }
    // 0041f465  68f01c4900             -push 0x491cf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791536 /*0x491cf0*/;
    cpu.esp -= 4;
    // 0041f46a  e8a1570000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f46f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f472:
    // 0041f472  8b86fc020000           -mov eax, dword ptr [esi + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */);
    // 0041f478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f47a  7544                   -jne 0x41f4c0
    if (!cpu.flags.zf)
    {
        goto L_0x0041f4c0;
    }
    // 0041f47c  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 0041f481  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f483  7333                   -jae 0x41f4b8
    if (!cpu.flags.cf)
    {
        goto L_0x0041f4b8;
    }
    // 0041f485  3c06                   +cmp al, 6
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f487  7227                   -jb 0x41f4b0
    if (cpu.flags.cf)
    {
        goto L_0x0041f4b0;
    }
    // 0041f489  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f48b  7423                   -je 0x41f4b0
    if (cpu.flags.zf)
    {
        goto L_0x0041f4b0;
    }
    // 0041f48d  e8fef8ffff             -call 0x41ed90
    cpu.esp -= 4;
    sub_41ed90(app, cpu);
    // 0041f492  8b8eec020000           -mov ecx, dword ptr [esi + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f498  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f49a  8a5148                 -mov dl, byte ptr [ecx + 0x48]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0041f49d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f49f  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f4a1  750f                   -jne 0x41f4b2
    if (!cpu.flags.zf)
    {
        goto L_0x0041f4b2;
    }
    // 0041f4a3  e878f8ffff             -call 0x41ed20
    cpu.esp -= 4;
    sub_41ed20(app, cpu);
    // 0041f4a8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f4aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4ab  e910ffffff             -jmp 0x41f3c0
    return sub_41f3c0(app, cpu);
L_0x0041f4b0:
    // 0041f4b0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0041f4b2:
    // 0041f4b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4b3  e918000000             -jmp 0x41f4d0
    goto L_0x0041f4d0;
L_0x0041f4b8:
    // 0041f4b8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f4ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4bb  e960f8ffff             -jmp 0x41ed20
    return sub_41ed20(app, cpu);
L_0x0041f4c0:
    // 0041f4c0  68b01c4900             -push 0x491cb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791472 /*0x491cb0*/;
    cpu.esp -= 4;
    // 0041f4c5  e846570000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f4ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f4cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f4ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f4d0:
    // 0041f4d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f4d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041f4d3  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f4d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f4db  750d                   -jne 0x41f4ea
    if (!cpu.flags.zf)
    {
        goto L_0x0041f4ea;
    }
    // 0041f4dd  68081d4900             -push 0x491d08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791560 /*0x491d08*/;
    cpu.esp -= 4;
    // 0041f4e2  e829570000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f4e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f4ea:
    // 0041f4ea  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0041f4f0  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041f4f2  8a4848                 -mov cl, byte ptr [eax + 0x48]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0041f4f5  e826000000             -call 0x41f520
    cpu.esp -= 4;
    sub_41f520(app, cpu);
    // 0041f4fa  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041f4fc  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041f4fe  e8bdfbffff             -call 0x41f0c0
    cpu.esp -= 4;
    sub_41f0c0(app, cpu);
    // 0041f503  8986fc020000           -mov dword ptr [esi + 0x2fc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */) = cpu.eax;
    // 0041f509  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f50b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f50c  e99ffeffff             -jmp 0x41f3b0
    return sub_41f3b0(app, cpu);
}

/* align: skip  */
void Application::sub_41f237(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f237  682c1c4900             -push 0x491c2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791340 /*0x491c2c*/;
    cpu.esp -= 4;
    // 0041f23c  e8cf590000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f241  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041f244  e9a6000000             -jmp 0x41f2ef
    return sub_41f2ef(app, cpu);
}

/* align: skip  */
void Application::sub_41f249(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f249  68001c4900             -push 0x491c00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791296 /*0x491c00*/;
    cpu.esp -= 4;
    // 0041f24e  e8bd590000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f253  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041f256  e994000000             -jmp 0x41f2ef
    return sub_41f2ef(app, cpu);
}

/* align: skip  */
void Application::sub_41f25b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f25b  68d41b4900             -push 0x491bd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791252 /*0x491bd4*/;
    cpu.esp -= 4;
    // 0041f260  e8ab590000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f265  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041f268  e982000000             -jmp 0x41f2ef
    return sub_41f2ef(app, cpu);
}

/* align: skip  */
void Application::sub_41f26d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f26d  68a81b4900             -push 0x491ba8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791208 /*0x491ba8*/;
    cpu.esp -= 4;
    // 0041f272  e899590000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f277  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041f27a  eb73                   -jmp 0x41f2ef
    return sub_41f2ef(app, cpu);
}

/* align: skip  */
void Application::sub_41f27c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f27c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f27e  e89d100000             -call 0x420320
    cpu.esp -= 4;
    sub_420320(app, cpu);
    // 0041f283  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f289  0c05                   +or al, 5
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(5 /*0x5*/))));
    // 0041f28b  eb5c                   -jmp 0x41f2e9
    return sub_41f2e9(app, cpu);
}

/* align: skip  */
void Application::sub_41f28d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f28d  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f28f  e88c100000             -call 0x420320
    cpu.esp -= 4;
    sub_420320(app, cpu);
    // 0041f294  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f29a  0c03                   +or al, 3
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0041f29c  eb4b                   -jmp 0x41f2e9
    return sub_41f2e9(app, cpu);
}

/* align: skip  */
void Application::sub_41f29e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f29e  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f2a0  e87b100000             -call 0x420320
    cpu.esp -= 4;
    sub_420320(app, cpu);
    // 0041f2a5  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2ab  0c11                   +or al, 0x11
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(17 /*0x11*/))));
    // 0041f2ad  eb3a                   -jmp 0x41f2e9
    return sub_41f2e9(app, cpu);
}

/* align: skip  */
void Application::sub_41f2af(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f2af  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 0041f2b4  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f2b6  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f2b8  7222                   -jb 0x41f2dc
    if (cpu.flags.cf)
    {
        return sub_41f2dc(app, cpu);
    }
    // 0041f2ba  e8a10e0000             -call 0x420160
    cpu.esp -= 4;
    sub_420160(app, cpu);
    // 0041f2bf  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2c5  0c08                   +or al, 8
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0041f2c7  eb20                   -jmp 0x41f2e9
    return sub_41f2e9(app, cpu);
}

/* align: skip  */
void Application::sub_41f2c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f2c9  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f2cb  e8900e0000             -call 0x420160
    cpu.esp -= 4;
    sub_420160(app, cpu);
    // 0041f2d0  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2d6  0c08                   +or al, 8
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0041f2d8  eb0f                   -jmp 0x41f2e9
    return sub_41f2e9(app, cpu);
}

/* align: skip  */
void Application::sub_41f2da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f2da  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f2dc  e83f100000             -call 0x420320
    cpu.esp -= 4;
    sub_420320(app, cpu);
    // 0041f2e1  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2e7  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0041f2e9  898630010000           -mov dword ptr [esi + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 0041f2ef  8a8630010000           -mov al, byte ptr [esi + 0x130]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2f6  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0041f2f8  7408                   -je 0x41f302
    if (cpu.flags.zf)
    {
        goto L_0x0041f302;
    }
    // 0041f2fa  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f2fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2fd  e94e000000             -jmp 0x41f350
    goto L_0x0041f350;
L_0x0041f302:
    // 0041f302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f350:
    // 0041f350  8b8130010000           -mov eax, dword ptr [ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(304) /* 0x130 */);
    // 0041f356  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0041f358  7416                   -je 0x41f370
    if (cpu.flags.zf)
    {
        goto L_0x0041f370;
    }
    // 0041f35a  a1a41c4900             -mov eax, dword ptr [0x491ca4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791460) /* 0x491ca4 */);
    // 0041f35f  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f362  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f364  668b15a81c4900         -mov dx, word ptr [0x491ca8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791464) /* 0x491ca8 */);
    // 0041f36b  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f36f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f370:
    // 0041f370  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0041f372  7416                   -je 0x41f38a
    if (cpu.flags.zf)
    {
        goto L_0x0041f38a;
    }
    // 0041f374  a19c1c4900             -mov eax, dword ptr [0x491c9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791452) /* 0x491c9c */);
    // 0041f379  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f37c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f37e  668b15a01c4900         -mov dx, word ptr [0x491ca0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791456) /* 0x491ca0 */);
    // 0041f385  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f38a:
    // 0041f38a  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041f38c  7415                   -je 0x41f3a3
    if (cpu.flags.zf)
    {
        goto L_0x0041f3a3;
    }
    // 0041f38e  a1941c4900             -mov eax, dword ptr [0x491c94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791444) /* 0x491c94 */);
    // 0041f393  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f396  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f398  668b15981c4900         -mov dx, word ptr [0x491c98]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791448) /* 0x491c98 */);
    // 0041f39f  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x0041f3a3:
    // 0041f3a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f2ef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0041f2ef;
    // 0041f2da  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f2dc  e83f100000             -call 0x420320
    cpu.esp -= 4;
    sub_420320(app, cpu);
    // 0041f2e1  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2e7  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0041f2e9  898630010000           -mov dword ptr [esi + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */) = cpu.eax;
L_entry_0x0041f2ef:
    // 0041f2ef  8a8630010000           -mov al, byte ptr [esi + 0x130]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2f6  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0041f2f8  7408                   -je 0x41f302
    if (cpu.flags.zf)
    {
        goto L_0x0041f302;
    }
    // 0041f2fa  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f2fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2fd  e94e000000             -jmp 0x41f350
    goto L_0x0041f350;
L_0x0041f302:
    // 0041f302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f350:
    // 0041f350  8b8130010000           -mov eax, dword ptr [ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(304) /* 0x130 */);
    // 0041f356  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0041f358  7416                   -je 0x41f370
    if (cpu.flags.zf)
    {
        goto L_0x0041f370;
    }
    // 0041f35a  a1a41c4900             -mov eax, dword ptr [0x491ca4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791460) /* 0x491ca4 */);
    // 0041f35f  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f362  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f364  668b15a81c4900         -mov dx, word ptr [0x491ca8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791464) /* 0x491ca8 */);
    // 0041f36b  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f36f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f370:
    // 0041f370  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0041f372  7416                   -je 0x41f38a
    if (cpu.flags.zf)
    {
        goto L_0x0041f38a;
    }
    // 0041f374  a19c1c4900             -mov eax, dword ptr [0x491c9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791452) /* 0x491c9c */);
    // 0041f379  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f37c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f37e  668b15a01c4900         -mov dx, word ptr [0x491ca0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791456) /* 0x491ca0 */);
    // 0041f385  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f38a:
    // 0041f38a  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041f38c  7415                   -je 0x41f3a3
    if (cpu.flags.zf)
    {
        goto L_0x0041f3a3;
    }
    // 0041f38e  a1941c4900             -mov eax, dword ptr [0x491c94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791444) /* 0x491c94 */);
    // 0041f393  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f396  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f398  668b15981c4900         -mov dx, word ptr [0x491c98]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791448) /* 0x491c98 */);
    // 0041f39f  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x0041f3a3:
    // 0041f3a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f2e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0041f2e9;
    // 0041f2da  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f2dc  e83f100000             -call 0x420320
    cpu.esp -= 4;
    sub_420320(app, cpu);
    // 0041f2e1  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2e7  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_entry_0x0041f2e9:
    // 0041f2e9  898630010000           -mov dword ptr [esi + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 0041f2ef  8a8630010000           -mov al, byte ptr [esi + 0x130]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2f6  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0041f2f8  7408                   -je 0x41f302
    if (cpu.flags.zf)
    {
        goto L_0x0041f302;
    }
    // 0041f2fa  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f2fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2fd  e94e000000             -jmp 0x41f350
    goto L_0x0041f350;
L_0x0041f302:
    // 0041f302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f350:
    // 0041f350  8b8130010000           -mov eax, dword ptr [ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(304) /* 0x130 */);
    // 0041f356  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0041f358  7416                   -je 0x41f370
    if (cpu.flags.zf)
    {
        goto L_0x0041f370;
    }
    // 0041f35a  a1a41c4900             -mov eax, dword ptr [0x491ca4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791460) /* 0x491ca4 */);
    // 0041f35f  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f362  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f364  668b15a81c4900         -mov dx, word ptr [0x491ca8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791464) /* 0x491ca8 */);
    // 0041f36b  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f36f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f370:
    // 0041f370  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0041f372  7416                   -je 0x41f38a
    if (cpu.flags.zf)
    {
        goto L_0x0041f38a;
    }
    // 0041f374  a19c1c4900             -mov eax, dword ptr [0x491c9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791452) /* 0x491c9c */);
    // 0041f379  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f37c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f37e  668b15a01c4900         -mov dx, word ptr [0x491ca0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791456) /* 0x491ca0 */);
    // 0041f385  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f38a:
    // 0041f38a  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041f38c  7415                   -je 0x41f3a3
    if (cpu.flags.zf)
    {
        goto L_0x0041f3a3;
    }
    // 0041f38e  a1941c4900             -mov eax, dword ptr [0x491c94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791444) /* 0x491c94 */);
    // 0041f393  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f396  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f398  668b15981c4900         -mov dx, word ptr [0x491c98]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791448) /* 0x491c98 */);
    // 0041f39f  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x0041f3a3:
    // 0041f3a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f2dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0041f2dc;
    // 0041f2da  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_entry_0x0041f2dc:
    // 0041f2dc  e83f100000             -call 0x420320
    cpu.esp -= 4;
    sub_420320(app, cpu);
    // 0041f2e1  8b8630010000           -mov eax, dword ptr [esi + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2e7  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0041f2e9  898630010000           -mov dword ptr [esi + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 0041f2ef  8a8630010000           -mov al, byte ptr [esi + 0x130]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 0041f2f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2f6  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0041f2f8  7408                   -je 0x41f302
    if (cpu.flags.zf)
    {
        goto L_0x0041f302;
    }
    // 0041f2fa  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f2fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f2fd  e94e000000             -jmp 0x41f350
    goto L_0x0041f350;
L_0x0041f302:
    // 0041f302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f350:
    // 0041f350  8b8130010000           -mov eax, dword ptr [ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(304) /* 0x130 */);
    // 0041f356  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0041f358  7416                   -je 0x41f370
    if (cpu.flags.zf)
    {
        goto L_0x0041f370;
    }
    // 0041f35a  a1a41c4900             -mov eax, dword ptr [0x491ca4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791460) /* 0x491ca4 */);
    // 0041f35f  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f362  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f364  668b15a81c4900         -mov dx, word ptr [0x491ca8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791464) /* 0x491ca8 */);
    // 0041f36b  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f36f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f370:
    // 0041f370  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0041f372  7416                   -je 0x41f38a
    if (cpu.flags.zf)
    {
        goto L_0x0041f38a;
    }
    // 0041f374  a19c1c4900             -mov eax, dword ptr [0x491c9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791452) /* 0x491c9c */);
    // 0041f379  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f37c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f37e  668b15a01c4900         -mov dx, word ptr [0x491ca0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791456) /* 0x491ca0 */);
    // 0041f385  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0041f389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f38a:
    // 0041f38a  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0041f38c  7415                   -je 0x41f3a3
    if (cpu.flags.zf)
    {
        goto L_0x0041f3a3;
    }
    // 0041f38e  a1941c4900             -mov eax, dword ptr [0x491c94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4791444) /* 0x491c94 */);
    // 0041f393  83c106                 -add ecx, 6
    (cpu.ecx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041f396  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0041f398  668b15981c4900         -mov dx, word ptr [0x491c98]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4791448) /* 0x491c98 */);
    // 0041f39f  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x0041f3a3:
    // 0041f3a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f3b0  e94bfeffff             -jmp 0x41f200
    return sub_41f200(app, cpu);
}

/* align: skip  */
void Application::sub_41f3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f3c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041f3c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f3c2  8bb1fc020000           -mov esi, dword ptr [ecx + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041f3c8  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041f3cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f3cc  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041f3ce  898614010000           -mov dword ptr [esi + 0x114], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */) = cpu.eax;
    // 0041f3d4  898610010000           -mov dword ptr [esi + 0x110], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */) = cpu.eax;
    // 0041f3da  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0041f3df  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0041f3e4  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0041f3e7  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0041f3ea  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f3ec  8dbe8c000000           -lea edi, [esi + 0x8c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0041f3f2  899e1c010000           -mov dword ptr [esi + 0x11c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */) = cpu.ebx;
    // 0041f3f8  899e20010000           -mov dword ptr [esi + 0x120], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(288) /* 0x120 */) = cpu.ebx;
    // 0041f3fe  899e0c010000           -mov dword ptr [esi + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.ebx;
    // 0041f404  899e88000000           -mov dword ptr [esi + 0x88], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.ebx;
    // 0041f40a  f3ab                   -rep stosd dword ptr es:[edi], eax
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
        }
        else
        {
            cpu.edi += 4;
        }
        --cpu.ecx;
    }
    // 0041f40c  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0041f412  899e24010000           -mov dword ptr [esi + 0x124], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = cpu.ebx;
    // 0041f418  3bc3                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f41a  899e34010000           -mov dword ptr [esi + 0x134], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(308) /* 0x134 */) = cpu.ebx;
    // 0041f420  7417                   -je 0x41f439
    if (cpu.flags.zf)
    {
        goto L_0x0041f439;
    }
    // 0041f422  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0041f428  e8830d0000             -call 0x4201b0
    cpu.esp -= 4;
    sub_4201b0(app, cpu);
    // 0041f42d  899e80000000           -mov dword ptr [esi + 0x80], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.ebx;
    // 0041f433  899e84000000           -mov dword ptr [esi + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ebx;
L_0x0041f439:
    // 0041f439  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f43a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f43b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f43c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0041f520  83f918                 +cmp ecx, 0x18
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f523  0f8797000000           -ja 0x41f5c0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041f5c0;
    }
    // 0041f529  ff248dc4f54100         -jmp dword ptr [ecx*4 + 0x41f5c4]
    cpu.ip = app->getMemory<x86::reg32>(4322756 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0041f530:
    // 0041f530  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f535  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f536:
    // 0041f536  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0041f53b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f53c:
    // 0041f53c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0041f541  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f542:
    // 0041f542  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0041f547  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f548:
    // 0041f548  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0041f54d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f54e:
    // 0041f54e  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0041f553  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f554:
    // 0041f554  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0041f559  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f55a:
    // 0041f55a  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0041f55f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f560:
    // 0041f560  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0041f565  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f566:
    // 0041f566  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0041f56b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f56c:
    // 0041f56c  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0041f571  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f572:
    // 0041f572  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0041f577  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f578:
    // 0041f578  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0041f57d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f57e:
    // 0041f57e  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0041f583  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f584:
    // 0041f584  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0041f589  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f58a:
    // 0041f58a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0041f58f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f590:
    // 0041f590  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0041f595  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f596:
    // 0041f596  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0041f59b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f59c:
    // 0041f59c  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 0041f5a1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f5a2:
    // 0041f5a2  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0041f5a7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f5a8:
    // 0041f5a8  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 0041f5ad  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f5ae:
    // 0041f5ae  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 0041f5b3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f5b4:
    // 0041f5b4  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 0041f5b9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f5ba:
    // 0041f5ba  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0041f5bf  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041f5c0:
L_0x0041f5c0:
    // 0041f5c0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f5c2  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_41f630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f630  8b81fc020000           -mov eax, dword ptr [ecx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041f636  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f638  7507                   -jne 0x41f641
    if (!cpu.flags.zf)
    {
        goto L_0x0041f641;
    }
    // 0041f63a  d905ec724800           -fld dword ptr [0x4872ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    // 0041f640  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f641:
    // 0041f641  d94070                 -fld dword ptr [eax + 0x70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(112) /* 0x70 */)));
    // 0041f644  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f650  8b81fc020000           -mov eax, dword ptr [ecx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041f656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f658  7507                   -jne 0x41f661
    if (!cpu.flags.zf)
    {
        goto L_0x0041f661;
    }
    // 0041f65a  d905ec724800           -fld dword ptr [0x4872ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    // 0041f660  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f661:
    // 0041f661  d9407c                 -fld dword ptr [eax + 0x7c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */)));
    // 0041f664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f670  e84b060000             -call 0x41fcc0
    cpu.esp -= 4;
    sub_41fcc0(app, cpu);
    // 0041f675  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f678  7507                   -jne 0x41f681
    if (!cpu.flags.zf)
    {
        goto L_0x0041f681;
    }
    // 0041f67a  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0041f680  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f681:
    // 0041f681  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041f687  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0041f68a  d98244020000           -fld dword ptr [edx + 0x244]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(580) /* 0x244 */)));
    // 0041f690  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f6a0  e81b060000             -call 0x41fcc0
    cpu.esp -= 4;
    sub_41fcc0(app, cpu);
    // 0041f6a5  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f6a8  7507                   -jne 0x41f6b1
    if (!cpu.flags.zf)
    {
        goto L_0x0041f6b1;
    }
    // 0041f6aa  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0041f6b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f6b1:
    // 0041f6b1  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041f6b7  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0041f6ba  d98240020000           -fld dword ptr [edx + 0x240]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(576) /* 0x240 */)));
    // 0041f6c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f6d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041f6d2  7405                   -je 0x41f6d9
    if (cpu.flags.zf)
    {
        goto L_0x0041f6d9;
    }
    // 0041f6d4  e987000000             -jmp 0x41f760
    return sub_41f760(app, cpu);
L_0x0041f6d9:
    // 0041f6d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f6e0  a1a8185200             -mov eax, dword ptr [0x5218a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */);
    // 0041f6e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f6e7  754c                   -jne 0x41f735
    if (!cpu.flags.zf)
    {
        goto L_0x0041f735;
    }
    // 0041f6e9  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 0041f6ee  e8877b0500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0041f6f3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041f6f6  a3a8185200             -mov dword ptr [0x5218a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */) = cpu.eax;
    // 0041f6fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f6fd  7512                   -jne 0x41f711
    if (!cpu.flags.zf)
    {
        goto L_0x0041f711;
    }
    // 0041f6ff  68201d4900             -push 0x491d20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791584 /*0x491d20*/;
    cpu.esp -= 4;
    // 0041f704  e807550000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041f709  a1a8185200             -mov eax, dword ptr [0x5218a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */);
    // 0041f70e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0041f711:
    // 0041f711  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0041f713:
    // 0041f713  8d540120               -lea edx, [ecx + eax + 0x20]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */ + cpu.eax * 1);
    // 0041f717  8954011c               -mov dword ptr [ecx + eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */ + cpu.eax * 1) = cpu.edx;
    // 0041f71b  a1a8185200             -mov eax, dword ptr [0x5218a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */);
    // 0041f720  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041f723  81f9e0030000           +cmp ecx, 0x3e0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(992 /*0x3e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f729  7ce8                   -jl 0x41f713
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041f713;
    }
    // 0041f72b  c780fc03000000000000   -mov dword ptr [eax + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
L_0x0041f735:
    // 0041f735  8b15a8185200           -mov edx, dword ptr [0x5218a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */);
    // 0041f73b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f73c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0041f741  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f743  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041f745  f3ab                   -rep stosd dword ptr es:[edi], eax
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
        }
        else
        {
            cpu.edi += 4;
        }
        --cpu.ecx;
    }
    // 0041f747  8b0da8185200           -mov ecx, dword ptr [0x5218a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */);
    // 0041f74d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f74e  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0041f751  a3a8185200             -mov dword ptr [0x5218a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */) = cpu.eax;
    // 0041f756  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041f758  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f760  a1a8185200             -mov eax, dword ptr [0x5218a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */);
    // 0041f765  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041f768  890da8185200           -mov dword ptr [0x5218a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5380264) /* 0x5218a8 */) = cpu.ecx;
    // 0041f76e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f770  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041f772  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041f775  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f780  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f781  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f782  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041f784  e8f7040100             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0041f789  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041f78b  83feff                 +cmp esi, -1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f78e  0f84ce000000           -je 0x41f862
    if (cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f794  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f796  e895050000             -call 0x41fd30
    cpu.esp -= 4;
    sub_41fd30(app, cpu);
    // 0041f79b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f79d  e80e020000             -call 0x41f9b0
    cpu.esp -= 4;
    sub_41f9b0(app, cpu);
    // 0041f7a2  83fe02                 +cmp esi, 2
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f7a5  0f84b7000000           -je 0x41f862
    if (cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f7ab  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f7ae  0f84ae000000           -je 0x41f862
    if (cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f7b4  83fe01                 +cmp esi, 1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f7b7  0f84a5000000           -je 0x41f862
    if (cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f7bd  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 0041f7c2  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f7c4  0f8798000000           -ja 0x41f862
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f7ca  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f7cc  0f8290000000           -jb 0x41f862
    if (cpu.flags.cf)
    {
        goto L_0x0041f862;
    }
    // 0041f7d2  e849d6feff             -call 0x40ce20
    cpu.esp -= 4;
    sub_40ce20(app, cpu);
    // 0041f7d7  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f7d9  0f8483000000           -je 0x41f862
    if (cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f7df  8bb7fc020000           -mov esi, dword ptr [edi + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(764) /* 0x2fc */);
    // 0041f7e5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f7e7  7479                   -je 0x41f862
    if (cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f7e9  f6863001000001         +test byte ptr [esi + 0x130], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(304) /* 0x130 */) & 1 /*0x1*/));
    // 0041f7f0  7570                   -jne 0x41f862
    if (!cpu.flags.zf)
    {
        goto L_0x0041f862;
    }
    // 0041f7f2  e8395f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041f7f7  d8a624010000           -fsub dword ptr [esi + 0x124]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(292) /* 0x124 */));
    // 0041f7fd  dc1570744800           -fcom qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    // 0041f803  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041f805  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041f808  7a12                   -jp 0x41f81c
    if (cpu.flags.pf)
    {
        goto L_0x0041f81c;
    }
    // 0041f80a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041f80c  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0041f812  c7862401000000000000   -mov dword ptr [esi + 0x124], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = 0 /*0x0*/;
L_0x0041f81c:
    // 0041f81c  dc1d68734800           -fcomp qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    cpu.fpu.pop();
    // 0041f822  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041f824  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041f827  7b39                   -jnp 0x41f862
    if (!cpu.flags.pf)
    {
        goto L_0x0041f862;
    }
    // 0041f829  e8025f0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041f82e  d99e24010000           -fstp dword ptr [esi + 0x124]
    app->getMemory<float>(cpu.esi + x86::reg32(292) /* 0x124 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041f834  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f836  e855000000             -call 0x41f890
    cpu.esp -= 4;
    sub_41f890(app, cpu);
    // 0041f83b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f83d  e8ce010000             -call 0x41fa10
    cpu.esp -= 4;
    sub_41fa10(app, cpu);
    // 0041f842  a1dcc94a00             -mov eax, dword ptr [0x4ac9dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901340) /* 0x4ac9dc */);
    // 0041f847  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041f84d  3bc1                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f84f  7405                   -je 0x41f856
    if (cpu.flags.zf)
    {
        goto L_0x0041f856;
    }
    // 0041f851  e8da8effff             -call 0x418730
    cpu.esp -= 4;
    sub_418730(app, cpu);
L_0x0041f856:
    // 0041f856  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041f85c  890ddcc94a00           -mov dword ptr [0x4ac9dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(4901340) /* 0x4ac9dc */) = cpu.ecx;
L_0x0041f862:
    // 0041f862  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f863  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f864  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f870  e81b040000             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 0041f875  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f877  7501                   -jne 0x41f87a
    if (!cpu.flags.zf)
    {
        goto L_0x0041f87a;
    }
    // 0041f879  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f87a:
    // 0041f87a  0fbe8030010000         -movsx eax, byte ptr [eax + 0x130]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(304) /* 0x130 */)));
    // 0041f881  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f884  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0041f887  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f890  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f891  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f892  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041f894  7420                   -je 0x41f8b6
    if (cpu.flags.zf)
    {
        goto L_0x0041f8b6;
    }
    // 0041f896  8bb9fc020000           -mov edi, dword ptr [ecx + 0x2fc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041f89c  8bb780000000           -mov esi, dword ptr [edi + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0041f8a2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f8a4  7410                   -je 0x41f8b6
    if (cpu.flags.zf)
    {
        goto L_0x0041f8b6;
    }
L_0x0041f8a6:
    // 0041f8a6  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041f8a8  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f8aa  e811000000             -call 0x41f8c0
    cpu.esp -= 4;
    sub_41f8c0(app, cpu);
    // 0041f8af  8b761c                 -mov esi, dword ptr [esi + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041f8b2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f8b4  75f0                   -jne 0x41f8a6
    if (!cpu.flags.zf)
    {
        goto L_0x0041f8a6;
    }
L_0x0041f8b6:
    // 0041f8b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f8b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f8c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f8c1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0041f8c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f8c4  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041f8c6  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0041f8c9  dc2568734800           -fsub qword ptr [0x487368]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 0041f8cf  d95610                 -fst dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    // 0041f8d2  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041f8d8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041f8da  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041f8dd  7a7a                   -jp 0x41f959
    if (cpu.flags.pf)
    {
        goto L_0x0041f959;
    }
    // 0041f8df  d98728010000           -fld dword ptr [edi + 0x128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(296) /* 0x128 */)));
    // 0041f8e5  d86604                 -fsub dword ptr [esi + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */));
    // 0041f8e8  d99728010000           -fst dword ptr [edi + 0x128]
    app->getMemory<float>(cpu.edi + x86::reg32(296) /* 0x128 */) = float(cpu.fpu.st(0));
    // 0041f8ee  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0041f8f4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041f8f6  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0041f8f9  7a0a                   -jp 0x41f905
    if (cpu.flags.pf)
    {
        goto L_0x0041f905;
    }
    // 0041f8fb  c7872801000000000000   -mov dword ptr [edi + 0x128], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(296) /* 0x128 */) = 0 /*0x0*/;
L_0x0041f905:
    // 0041f905  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041f907  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041f909  e852000000             -call 0x41f960
    cpu.esp -= 4;
    sub_41f960(app, cpu);
    // 0041f90e  d95610                 -fst dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    // 0041f911  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041f914  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0041f917  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0041f91d  d95614                 -fst dword ptr [esi + 0x14]
    app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    // 0041f920  d81d68744800           -fcomp dword ptr [0x487468]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748392) /* 0x487468 */)));
    cpu.fpu.pop();
    // 0041f926  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041f928  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041f92d  7507                   -jne 0x41f936
    if (!cpu.flags.zf)
    {
        goto L_0x0041f936;
    }
    // 0041f92f  c7461400008040         -mov dword ptr [esi + 0x14], 0x40800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 1082130432 /*0x40800000*/;
L_0x0041f936:
    // 0041f936  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0041f939  e852740500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041f93e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f940  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0041f943  8984398c000000         -mov dword ptr [ecx + edi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */ + cpu.edi * 1) = cpu.eax;
    // 0041f94a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041f94c  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0041f94f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0041f952  c7043a02000000         -mov dword ptr [edx + edi], 2
    app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 1) = 2 /*0x2*/;
L_0x0041f959:
    // 0041f959  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f95a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f95b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f960  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f963  8b4154                 -mov eax, dword ptr [ecx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 0041f966  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f967  0faf02                 -imul eax, dword ptr [edx]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx))));
    // 0041f96a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f96b  8d3480                 -lea esi, [eax + eax*4]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0041f96e  a1a8144900             -mov eax, dword ptr [0x4914a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4789416) /* 0x4914a8 */);
    // 0041f973  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0041f976  d90406                 -fld dword ptr [esi + eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 1)));
    // 0041f979  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041f97d  e8d5740500             -call 0x476e57
    cpu.esp -= 4;
    _rand(app, cpu);
    // 0041f982  8b0da8144900           -mov ecx, dword ptr [0x4914a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4789416) /* 0x4914a8 */);
    // 0041f988  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041f98a  d9440e04               -fld dword ptr [esi + ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1)));
    // 0041f98e  e8fd730500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041f993  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041f995  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f997  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041f998  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0041f99a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f99b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f99c  89542400               -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0041f9a0  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0041f9a4  d8442404               -fadd dword ptr [esp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0041f9a8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041f9ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f9b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f9b1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041f9b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f9b4  7433                   -je 0x41f9e9
    if (cpu.flags.zf)
    {
        goto L_0x0041f9e9;
    }
    // 0041f9b6  8bb1fc020000           -mov esi, dword ptr [ecx + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041f9bc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041f9be  7429                   -je 0x41f9e9
    if (cpu.flags.zf)
    {
        goto L_0x0041f9e9;
    }
    // 0041f9c0  8b8628010000           -mov eax, dword ptr [esi + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */);
    // 0041f9c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f9c7  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041f9c9  8d4e5c                 -lea ecx, [esi + 0x5c]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 0041f9cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f9cd  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041f9d1  e81a000000             -call 0x41f9f0
    cpu.esp -= 4;
    sub_41f9f0(app, cpu);
    // 0041f9d6  8d4e68                 -lea ecx, [esi + 0x68]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0041f9d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f9da  e811000000             -call 0x41f9f0
    cpu.esp -= 4;
    sub_41f9f0(app, cpu);
    // 0041f9df  8d4e74                 -lea ecx, [esi + 0x74]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 0041f9e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f9e3  e808000000             -call 0x41f9f0
    cpu.esp -= 4;
    sub_41f9f0(app, cpu);
    // 0041f9e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041f9e9:
    // 0041f9e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41f9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f9f0  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0041f9f3  d821                   -fsub dword ptr [ecx]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0041f9f5  d84c2404               -fmul dword ptr [esp + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0041f9f9  d801                   -fadd dword ptr [ecx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx));
    // 0041f9fb  d95908                 -fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041f9fe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_41fa10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fa10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fa11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fa12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fa13  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0041fa15  3bcf                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fa17  7445                   -je 0x41fa5e
    if (cpu.flags.zf)
    {
        goto L_0x0041fa5e;
    }
    // 0041fa19  8bb1fc020000           -mov esi, dword ptr [ecx + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041fa1f  3bf7                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fa21  743b                   -je 0x41fa5e
    if (cpu.flags.zf)
    {
        goto L_0x0041fa5e;
    }
    // 0041fa23  8b8688000000           -mov eax, dword ptr [esi + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0041fa29  2bc7                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041fa2b  7456                   -je 0x41fa83
    if (cpu.flags.zf)
    {
        goto L_0x0041fa83;
    }
    // 0041fa2d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041fa2e  7432                   -je 0x41fa62
    if (cpu.flags.zf)
    {
        goto L_0x0041fa62;
    }
    // 0041fa30  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041fa31  752b                   -jne 0x41fa5e
    if (!cpu.flags.zf)
    {
        goto L_0x0041fa5e;
    }
    // 0041fa33  d9861c010000           -fld dword ptr [esi + 0x11c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */)));
    // 0041fa39  dc2568734800           -fsub qword ptr [0x487368]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 0041fa3f  d9961c010000           -fst dword ptr [esi + 0x11c]
    app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */) = float(cpu.fpu.st(0));
    // 0041fa45  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0041fa4b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041fa4d  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0041fa50  7a0c                   -jp 0x41fa5e
    if (cpu.flags.pf)
    {
        goto L_0x0041fa5e;
    }
    // 0041fa52  89be88000000           -mov dword ptr [esi + 0x88], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edi;
L_0x0041fa58:
    // 0041fa58  89be1c010000           -mov dword ptr [esi + 0x11c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */) = cpu.edi;
L_0x0041fa5e:
    // 0041fa5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fa62:
    // 0041fa62  d9861c010000           -fld dword ptr [esi + 0x11c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */)));
    // 0041fa68  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041fa6e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041fa70  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041fa73  7be9                   -jnp 0x41fa5e
    if (!cpu.flags.pf)
    {
        goto L_0x0041fa5e;
    }
    // 0041fa75  c7868800000002000000   -mov dword ptr [esi + 0x88], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = 2 /*0x2*/;
    // 0041fa7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fa83:
    // 0041fa83  39be0c010000           +cmp dword ptr [esi + 0x10c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fa89  751a                   -jne 0x41faa5
    if (!cpu.flags.zf)
    {
        goto L_0x0041faa5;
    }
    // 0041fa8b  803d1015520007         +cmp byte ptr [0x521510], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fa92  770b                   -ja 0x41fa9f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041fa9f;
    }
    // 0041fa94  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041fa96  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041fa98  e883000000             -call 0x41fb20
    cpu.esp -= 4;
    sub_41fb20(app, cpu);
    // 0041fa9d  eb06                   -jmp 0x41faa5
    goto L_0x0041faa5;
L_0x0041fa9f:
    // 0041fa9f  89be0c010000           -mov dword ptr [esi + 0x10c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edi;
L_0x0041faa5:
    // 0041faa5  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 0041faab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041faac  68341d4900             -push 0x491d34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791604 /*0x491d34*/;
    cpu.esp -= 4;
    // 0041fab1  e801730500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041fab6  8b8e10010000           -mov ecx, dword ptr [esi + 0x110]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 0041fabc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041fabf  3bcf                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fac1  7c09                   -jl 0x41facc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041facc;
    }
    // 0041fac3  e848000000             -call 0x41fb10
    cpu.esp -= 4;
    sub_41fb10(app, cpu);
    // 0041fac8  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041faca  eb04                   -jmp 0x41fad0
    goto L_0x0041fad0;
L_0x0041facc:
    // 0041facc  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0041fad0:
    // 0041fad0  3bd7                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fad2  7484                   -je 0x41fa58
    if (cpu.flags.zf)
    {
        goto L_0x0041fa58;
    }
    // 0041fad4  39be10010000           +cmp dword ptr [esi + 0x110], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fada  0f8c78ffffff           -jl 0x41fa58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fa58;
    }
    // 0041fae0  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0041fae6  e885fcffff             -call 0x41f770
    cpu.esp -= 4;
    sub_41f770(app, cpu);
    // 0041faeb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041faed  898680000000           -mov dword ptr [esi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0041faf3  e808010000             -call 0x41fc00
    cpu.esp -= 4;
    sub_41fc00(app, cpu);
    // 0041faf8  c7868800000001000000   -mov dword ptr [esi + 0x88], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = 1 /*0x1*/;
    // 0041fb02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fb10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fb11  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041fb13  e8c8fbffff             -call 0x41f6e0
    cpu.esp -= 4;
    sub_41f6e0(app, cpu);
    // 0041fb18  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0041fb1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fb20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fb21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fb22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fb23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fb24  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0041fb26  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0041fb28:
    // 0041fb28  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0041fb2a:
    // 0041fb2a  e828730500             -call 0x476e57
    cpu.esp -= 4;
    _rand(app, cpu);
    // 0041fb2f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fb31  81e607000080           +and esi, 0x80000007
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483655 /*0x80000007*/))));
    // 0041fb37  7905                   -jns 0x41fb3e
    if (!cpu.flags.sf)
    {
        goto L_0x0041fb3e;
    }
    // 0041fb39  4e                     -dec esi
    (cpu.esi)--;
    // 0041fb3a  83cef8                 -or esi, 0xfffffff8
    cpu.esi |= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0041fb3d  46                     -inc esi
    (cpu.esi)++;
L_0x0041fb3e:
    // 0041fb3e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041fb40  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041fb43  03c7                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0041fb45  8b888c000000           -mov ecx, dword ptr [eax + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 0041fb4b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041fb4d  7531                   -jne 0x41fb80
    if (!cpu.flags.zf)
    {
        goto L_0x0041fb80;
    }
    // 0041fb4f  8d4e09                 -lea ecx, [esi + 9]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0041fb52  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0041fb55  833c3900               +cmp dword ptr [ecx + edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + cpu.edi * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb59  7525                   -jne 0x41fb80
    if (!cpu.flags.zf)
    {
        goto L_0x0041fb80;
    }
    // 0041fb5b  39a894000000           +cmp dword ptr [eax + 0x94], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb61  751d                   -jne 0x41fb80
    if (!cpu.flags.zf)
    {
        goto L_0x0041fb80;
    }
    // 0041fb63  39b714010000           +cmp dword ptr [edi + 0x114], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(276) /* 0x114 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb69  7415                   -je 0x41fb80
    if (cpu.flags.zf)
    {
        goto L_0x0041fb80;
    }
    // 0041fb6b  393500114900           +cmp dword ptr [0x491100], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4788480) /* 0x491100 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb71  740d                   -je 0x41fb80
    if (cpu.flags.zf)
    {
        goto L_0x0041fb80;
    }
    // 0041fb73  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041fb75  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041fb77  e8d40b0000             -call 0x420750
    cpu.esp -= 4;
    sub_420750(app, cpu);
    // 0041fb7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fb7e  756b                   -jne 0x41fbeb
    if (!cpu.flags.zf)
    {
        goto L_0x0041fbeb;
    }
L_0x0041fb80:
    // 0041fb80  43                     -inc ebx
    (cpu.ebx)++;
    // 0041fb81  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb84  7ca4                   -jl 0x41fb2a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fb2a;
    }
    // 0041fb86  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041fb88  8d9f90000000           -lea ebx, [edi + 0x90]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(144) /* 0x90 */);
L_0x0041fb8e:
    // 0041fb8e  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0041fb91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fb93  7527                   -jne 0x41fbbc
    if (!cpu.flags.zf)
    {
        goto L_0x0041fbbc;
    }
    // 0041fb95  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb98  7522                   -jne 0x41fbbc
    if (!cpu.flags.zf)
    {
        goto L_0x0041fbbc;
    }
    // 0041fb9a  396b04                 +cmp dword ptr [ebx + 4], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb9d  751d                   -jne 0x41fbbc
    if (!cpu.flags.zf)
    {
        goto L_0x0041fbbc;
    }
    // 0041fb9f  39b714010000           +cmp dword ptr [edi + 0x114], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(276) /* 0x114 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fba5  7415                   -je 0x41fbbc
    if (cpu.flags.zf)
    {
        goto L_0x0041fbbc;
    }
    // 0041fba7  393500114900           +cmp dword ptr [0x491100], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4788480) /* 0x491100 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fbad  740d                   -je 0x41fbbc
    if (cpu.flags.zf)
    {
        goto L_0x0041fbbc;
    }
    // 0041fbaf  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041fbb1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041fbb3  e8980b0000             -call 0x420750
    cpu.esp -= 4;
    sub_420750(app, cpu);
    // 0041fbb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fbba  752f                   -jne 0x41fbeb
    if (!cpu.flags.zf)
    {
        goto L_0x0041fbeb;
    }
L_0x0041fbbc:
    // 0041fbbc  46                     -inc esi
    (cpu.esi)++;
    // 0041fbbd  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041fbc0  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fbc3  7cc9                   -jl 0x41fb8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fb8e;
    }
    // 0041fbc5  45                     -inc ebp
    (cpu.ebp)++;
    // 0041fbc6  c78710010000ffffffff   -mov dword ptr [edi + 0x110], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(272) /* 0x110 */) = 4294967295 /*0xffffffff*/;
    // 0041fbd0  83fd05                 +cmp ebp, 5
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fbd3  0f8e4fffffff           -jle 0x41fb28
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041fb28;
    }
    // 0041fbd9  68441d4900             -push 0x491d44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791620 /*0x491d44*/;
    cpu.esp -= 4;
    // 0041fbde  e8d4710500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041fbe3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fbe6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbe7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbe8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbe9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fbeb:
    // 0041fbeb  89b710010000           -mov dword ptr [edi + 0x110], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(272) /* 0x110 */) = cpu.esi;
    // 0041fbf1  893500114900           -mov dword ptr [0x491100], esi
    app->getMemory<x86::reg32>(x86::reg32(4788480) /* 0x491100 */) = cpu.esi;
    // 0041fbf7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbfa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fbfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fc01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fc02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fc03  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041fc05  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041fc09  8bb780000000           -mov esi, dword ptr [edi + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
    // 0041fc0f  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041fc11  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0041fc13  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0041fc16  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041fc19  c7043801000000         -mov dword ptr [eax + edi], 1
    app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 1) = 1 /*0x1*/;
    // 0041fc20  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041fc22  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0041fc25  8d843994000000         -lea eax, [ecx + edi + 0x94]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(148) /* 0x94 */ + cpu.edi * 1);
    // 0041fc2c  8b8c3994000000         -mov ecx, dword ptr [ecx + edi + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */ + cpu.edi * 1);
    // 0041fc33  41                     -inc ecx
    (cpu.ecx)++;
    // 0041fc34  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041fc36  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041fc38  e823fdffff             -call 0x41f960
    cpu.esp -= 4;
    sub_41f960(app, cpu);
    // 0041fc3d  d95610                 -fst dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    // 0041fc40  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041fc42  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041fc45  0faf4f54               -imul ecx, dword ptr [edi + 0x54]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */))));
    // 0041fc49  e822000000             -call 0x41fc70
    cpu.esp -= 4;
    sub_41fc70(app, cpu);
    // 0041fc4e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041fc50  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041fc53  0faf4f54               -imul ecx, dword ptr [edi + 0x54]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */))));
    // 0041fc57  e824000000             -call 0x41fc80
    cpu.esp -= 4;
    sub_41fc80(app, cpu);
    // 0041fc5c  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041fc5f  8b8784000000           -mov eax, dword ptr [edi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 0041fc65  40                     -inc eax
    (cpu.eax)++;
    // 0041fc66  898784000000           -mov dword ptr [edi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0041fc6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc70  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0041fc73  8b0da8144900           -mov ecx, dword ptr [0x4914a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4789416) /* 0x4914a8 */);
    // 0041fc79  d9448108               -fld dword ptr [ecx + eax*4 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.eax * 4)));
    // 0041fc7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc80  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0041fc83  8b0da8144900           -mov ecx, dword ptr [0x4914a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4789416) /* 0x4914a8 */);
    // 0041fc89  d944810c               -fld dword ptr [ecx + eax*4 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4)));
    // 0041fc8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc90  a1a0185200             -mov eax, dword ptr [0x5218a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */);
    // 0041fc95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fca0  a19c185200             -mov eax, dword ptr [0x52189c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */);
    // 0041fca5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fcb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fcb0  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 0041fcb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fcc0  e8dbffffff             -call 0x41fca0
    cpu.esp -= 4;
    sub_41fca0(app, cpu);
    // 0041fcc5  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fcc8  7503                   -jne 0x41fccd
    if (!cpu.flags.zf)
    {
        goto L_0x0041fccd;
    }
    // 0041fcca  0bc0                   -or eax, eax
    cpu.eax |= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fccc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fccd:
    // 0041fccd  3b056c185200           +cmp eax, dword ptr [0x52186c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fcd3  7c04                   -jl 0x41fcd9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fcd9;
    }
    // 0041fcd5  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041fcd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fcd9:
    // 0041fcd9  8b048560185200         -mov eax, dword ptr [eax*4 + 0x521860]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.eax * 4);
    // 0041fce0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fcf0  e89bffffff             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 0041fcf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fcf7  7504                   -jne 0x41fcfd
    if (!cpu.flags.zf)
    {
        goto L_0x0041fcfd;
    }
    // 0041fcf9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041fcfc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fcfd:
    // 0041fcfd  8b8030010000           -mov eax, dword ptr [eax + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(304) /* 0x130 */);
    // 0041fd03  83e03e                 -and eax, 0x3e
    cpu.eax &= x86::reg32(x86::sreg32(62 /*0x3e*/));
    // 0041fd06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fd10  e87bffffff             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 0041fd15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fd17  7504                   -jne 0x41fd1d
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd1d;
    }
    // 0041fd19  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041fd1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fd1d:
    // 0041fd1d  8b8030010000           -mov eax, dword ptr [eax + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(304) /* 0x130 */);
    // 0041fd23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fd30  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0041fd35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fd37  0f84cf000000           -je 0x41fe0c
    if (cpu.flags.zf)
    {
        goto L_0x0041fe0c;
    }
    // 0041fd3d  a19c184900             -mov eax, dword ptr [0x49189c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4790428) /* 0x49189c */);
    // 0041fd42  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041fd48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fd49  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fd4c  7509                   -jne 0x41fd57
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd57;
    }
    // 0041fd4e  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd51  0f85a7000000           -jne 0x41fdfe
    if (!cpu.flags.zf)
    {
        goto L_0x0041fdfe;
    }
L_0x0041fd57:
    // 0041fd57  8b0d6c185200           -mov ecx, dword ptr [0x52186c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 0041fd5d  ba60185200             -mov edx, 0x521860
    cpu.edx = 5380192 /*0x521860*/;
    // 0041fd62  e839010000             -call 0x41fea0
    cpu.esp -= 4;
    sub_41fea0(app, cpu);
    // 0041fd67  8b0d98185200           -mov ecx, dword ptr [0x521898]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */);
    // 0041fd6d  8b1da0185200           -mov ebx, dword ptr [0x5218a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */);
    // 0041fd73  8b359c185200           -mov esi, dword ptr [0x52189c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */);
    // 0041fd79  ba70185200             -mov edx, 0x521870
    cpu.edx = 5380208 /*0x521870*/;
    // 0041fd7e  e81d010000             -call 0x41fea0
    cpu.esp -= 4;
    sub_41fea0(app, cpu);
    // 0041fd83  83feff                 +cmp esi, -1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd86  7476                   -je 0x41fdfe
    if (cpu.flags.zf)
    {
        goto L_0x0041fdfe;
    }
    // 0041fd88  833d9c185200ff         +cmp dword ptr [0x52189c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd8f  7461                   -je 0x41fdf2
    if (cpu.flags.zf)
    {
        goto L_0x0041fdf2;
    }
    // 0041fd91  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041fd97  8b0cb560185200         -mov ecx, dword ptr [esi*4 + 0x521860]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.esi * 4);
    // 0041fd9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fd9f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0041fda1  8bb880000000           -mov edi, dword ptr [eax + 0x80]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0041fda7  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041fdac  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0041fdaf  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0041fdb2  e859000000             -call 0x41fe10
    cpu.esp -= 4;
    sub_41fe10(app, cpu);
    // 0041fdb7  e8d46f0500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041fdbc  8b0d9c185200           -mov ecx, dword ptr [0x52189c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */);
    // 0041fdc2  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041fdc4  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0041fdc9  8b148d70185200         -mov edx, dword ptr [ecx*4 + 0x521870]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5380208) /* 0x521870 */ + cpu.ecx * 4);
    // 0041fdd0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041fdd2  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041fdd7  8b8980000000           -mov ecx, dword ptr [ecx + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 0041fddd  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0041fde0  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0041fde3  e828000000             -call 0x41fe10
    cpu.esp -= 4;
    sub_41fe10(app, cpu);
    // 0041fde8  e8a36f0500             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0041fded  3bf8                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fdef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fdf0  7d0c                   -jge 0x41fdfe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041fdfe;
    }
L_0x0041fdf2:
    // 0041fdf2  891da0185200           -mov dword ptr [0x5218a0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */) = cpu.ebx;
    // 0041fdf8  89359c185200           -mov dword ptr [0x52189c], esi
    app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */) = cpu.esi;
L_0x0041fdfe:
    // 0041fdfe  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041fe04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe05  89159c184900           -mov dword ptr [0x49189c], edx
    app->getMemory<x86::reg32>(x86::reg32(4790428) /* 0x49189c */) = cpu.edx;
    // 0041fe0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041fe0c:
    // 0041fe0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fe10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fe10  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0041fe13  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0041fe19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fe1a  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0041fe1c  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0041fe22  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0041fe26  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0041fe2c  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0041fe30  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0041fe34  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0041fe38  e873ee0300             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0041fe3d  8b8ed0000000           -mov ecx, dword ptr [esi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0041fe43  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041fe49  8b86d8000000           -mov eax, dword ptr [esi + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0041fe4f  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041fe53  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041fe57  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fe5b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041fe5d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0041fe61  e84aee0300             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0041fe66  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0041fe6a  d8642430               -fsub dword ptr [esp + 0x30]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */));
    // 0041fe6e  8d4c2454               -lea ecx, [esp + 0x54]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0041fe72  d95c2458               -fstp dword ptr [esp + 0x58]
    app->getMemory<float>(cpu.esp + x86::reg32(88) /* 0x58 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041fe76  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0041fe7a  d8642434               -fsub dword ptr [esp + 0x34]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 0041fe7e  d95c245c               -fstp dword ptr [esp + 0x5c]
    app->getMemory<float>(cpu.esp + x86::reg32(92) /* 0x5c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041fe82  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0041fe86  d8642438               -fsub dword ptr [esp + 0x38]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */));
    // 0041fe8a  d95c2460               -fstp dword ptr [esp + 0x60]
    app->getMemory<float>(cpu.esp + x86::reg32(96) /* 0x60 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041fe8e  e82dce0200             -call 0x44ccc0
    cpu.esp -= 4;
    sub_44ccc0(app, cpu);
    // 0041fe93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe94  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0041fe97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_41fea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fea0  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0041fea6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fea7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fea8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fea9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041feaa  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041feac  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0041feae  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041feb0  3bdd                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041feb2  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0041feb6  0f8454010000           -je 0x420010
    if (cpu.flags.zf)
    {
        goto L_0x00420010;
    }
    // 0041febc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0041febe:
    // 0041febe  896c0448               -mov dword ptr [esp + eax + 0x48], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */ + cpu.eax * 1) = cpu.ebp;
    // 0041fec2  896c0470               -mov dword ptr [esp + eax + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */ + cpu.eax * 1) = cpu.ebp;
    // 0041fec6  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fec9  83f8dc                 +cmp eax, -0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-36 /*-0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fecc  7df0                   -jge 0x41febe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041febe;
    }
    // 0041fece  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fed1  7e0e                   -jle 0x41fee1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041fee1;
    }
    // 0041fed3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fed4  68b81d4900             -push 0x491db8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791736 /*0x491db8*/;
    cpu.esp -= 4;
    // 0041fed9  e8324d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041fede  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0041fee1:
    // 0041fee1  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041fee3  3bdd                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fee5  7e40                   -jle 0x41ff27
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ff27;
    }
L_0x0041fee7:
    // 0041fee7  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041feeb  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041feef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fef1  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041fef3  e828010000             -call 0x420020
    cpu.esp -= 4;
    sub_420020(app, cpu);
    // 0041fef8  3bc5                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fefa  7d0f                   -jge 0x41ff0b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041ff0b;
    }
    // 0041fefc  68a81d4900             -push 0x491da8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791720 /*0x491da8*/;
    cpu.esp -= 4;
    // 0041ff01  e80a4d0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041ff06  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041ff09  eb17                   -jmp 0x41ff22
    goto L_0x0041ff22;
L_0x0041ff0b:
    // 0041ff0b  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0041ff0f  8944b474               -mov dword ptr [esp + esi*4 + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */ + cpu.esi * 4) = cpu.eax;
    // 0041ff13  c744b42401000000       -mov dword ptr [esp + esi*4 + 0x24], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */ + cpu.esi * 4) = 1 /*0x1*/;
    // 0041ff1b  d99c849c000000         -fstp dword ptr [esp + eax*4 + 0x9c]
    app->getMemory<float>(cpu.esp + x86::reg32(156) /* 0x9c */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041ff22:
    // 0041ff22  46                     -inc esi
    (cpu.esi)++;
    // 0041ff23  3bf3                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff25  7cc0                   -jl 0x41fee7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fee7;
    }
L_0x0041ff27:
    // 0041ff27  e854fd0000             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0041ff2c  3bdd                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff2e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041ff32  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0041ff36  0f8e81000000           -jle 0x41ffbd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041ffbd;
    }
    // 0041ff3c  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0041ff40  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0041ff42  2bc7                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0041ff44  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0041ff48:
    // 0041ff48  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0041ff4a  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041ff50  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0041ff53  8bb9fc020000           -mov edi, dword ptr [ecx + 0x2fc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 0041ff59  e8c2100100             -call 0x431020
    cpu.esp -= 4;
    sub_431020(app, cpu);
    // 0041ff5e  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff61  89474c                 -mov dword ptr [edi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0041ff64  743d                   -je 0x41ffa3
    if (cpu.flags.zf)
    {
        goto L_0x0041ffa3;
    }
    // 0041ff66  3b44241c               +cmp eax, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff6a  7513                   -jne 0x41ff7f
    if (!cpu.flags.zf)
    {
        goto L_0x0041ff7f;
    }
    // 0041ff6c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0041ff70  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0041ff78  c7043001000000         -mov dword ptr [eax + esi], 1
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1) = 1 /*0x1*/;
L_0x0041ff7f:
    // 0041ff7f  45                     -inc ebp
    (cpu.ebp)++;
    // 0041ff80  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ff83  3beb                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff85  7cc1                   -jl 0x41ff48
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ff48;
    }
    // 0041ff87  837c241001             +cmp dword ptr [esp + 0x10], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff8c  752d                   -jne 0x41ffbb
    if (!cpu.flags.zf)
    {
        goto L_0x0041ffbb;
    }
    // 0041ff8e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0041ff90:
    // 0041ff90  8b4c8474               -mov ecx, dword ptr [esp + eax*4 + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */ + cpu.eax * 4);
    // 0041ff94  8b548c4c               -mov edx, dword ptr [esp + ecx*4 + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */ + cpu.ecx * 4);
    // 0041ff98  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041ff9a  7528                   -jne 0x41ffc4
    if (!cpu.flags.zf)
    {
        goto L_0x0041ffc4;
    }
    // 0041ff9c  40                     -inc eax
    (cpu.eax)++;
    // 0041ff9d  3bc3                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff9f  7cef                   -jl 0x41ff90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ff90;
    }
    // 0041ffa1  eb21                   -jmp 0x41ffc4
    goto L_0x0041ffc4;
L_0x0041ffa3:
    // 0041ffa3  68741d4900             -push 0x491d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791668 /*0x491d74*/;
    cpu.esp -= 4;
    // 0041ffa8  e80a6e0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0041ffad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ffb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffb4  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0041ffba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ffbb:
    // 0041ffbb  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0041ffbd:
    // 0041ffbd  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0041ffc0  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041ffc2  eb41                   -jmp 0x420005
    goto L_0x00420005;
L_0x0041ffc4:
    // 0041ffc4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041ffc6  7d06                   -jge 0x41ffce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041ffce;
    }
    // 0041ffc8  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0041ffca  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041ffcc  eb37                   -jmp 0x420005
    goto L_0x00420005;
L_0x0041ffce:
    // 0041ffce  d9848c9c000000         -fld dword ptr [esp + ecx*4 + 0x9c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(156) /* 0x9c */ + cpu.ecx * 4)));
    // 0041ffd5  d81d88774800           -fcomp dword ptr [0x487788]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749192) /* 0x487788 */)));
    cpu.fpu.pop();
    // 0041ffdb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041ffdd  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0041ffe2  7504                   -jne 0x41ffe8
    if (!cpu.flags.zf)
    {
        goto L_0x0041ffe8;
    }
    // 0041ffe4  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041ffe6  eb1a                   -jmp 0x420002
    goto L_0x00420002;
L_0x0041ffe8:
    // 0041ffe8  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0041ffec  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0041ffef  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0041fff5  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0041fff8  8b80fc020000           -mov eax, dword ptr [eax + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(764) /* 0x2fc */);
    // 0041fffe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420000  7503                   -jne 0x420005
    if (!cpu.flags.zf)
    {
        goto L_0x00420005;
    }
L_0x00420002:
    // 00420002  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00420005:
    // 00420005  890d9c185200           -mov dword ptr [0x52189c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5380252) /* 0x52189c */) = cpu.ecx;
    // 0042000b  a3a0185200             -mov dword ptr [0x5218a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */) = cpu.eax;
L_0x00420010:
    // 00420010  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420011  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420012  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420013  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420014  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0042001a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420020  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 00420025  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420028  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042002a  7509                   -jne 0x420035
    if (!cpu.flags.zf)
    {
        goto L_0x00420035;
    }
    // 0042002c  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042002f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420032  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00420035:
    // 00420035  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00420039  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042003a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042003b  83cdff                 -or ebp, 0xffffffff
    cpu.ebp |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042003e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00420040  c744240800007ac4       -mov dword ptr [esp + 8], 0xc47a0000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 3296329728 /*0xc47a0000*/;
    // 00420048  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042004a  7e72                   -jle 0x4200be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004200be;
    }
    // 0042004c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042004d  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042004f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420050  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00420052  2bd9                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00420054:
    // 00420054  833c3b00               +cmp dword ptr [ebx + edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + cpu.edi * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420058  7556                   -jne 0x4200b0
    if (!cpu.flags.zf)
    {
        goto L_0x004200b0;
    }
    // 0042005a  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00420060  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00420062  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00420064  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0042006a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0042006e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420073  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00420076  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042007a  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0042007d  e88efdffff             -call 0x41fe10
    cpu.esp -= 4;
    sub_41fe10(app, cpu);
    // 00420082  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00420086  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042008c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042008e  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00420091  7a08                   -jp 0x42009b
    if (cpu.flags.pf)
    {
        goto L_0x0042009b;
    }
    // 00420093  d95c2410               +fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00420097  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00420099  eb15                   -jmp 0x4200b0
    goto L_0x004200b0;
L_0x0042009b:
    // 0042009b  d8542410               -fcom dword ptr [esp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042009f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004200a1  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 004200a4  7a08                   -jp 0x4200ae
    if (cpu.flags.pf)
    {
        goto L_0x004200ae;
    }
    // 004200a6  d95c2410               +fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004200aa  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004200ac  eb02                   -jmp 0x4200b0
    goto L_0x004200b0;
L_0x004200ae:
    // 004200ae  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004200b0:
    // 004200b0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004200b4  46                     -inc esi
    (cpu.esi)++;
    // 004200b5  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004200b8  3bf0                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004200ba  7c98                   -jl 0x420054
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420054;
    }
    // 004200bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004200be:
    // 004200be  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004200c2  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004200c6  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004200c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200ca  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004200cc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004200cf  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4200e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004200e0  3b0d6c185200           +cmp ecx, dword ptr [0x52186c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004200e6  7c03                   -jl 0x4200eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004200eb;
    }
    // 004200e8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004200ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004200eb:
    // 004200eb  8b048d60185200         -mov eax, dword ptr [ecx*4 + 0x521860]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.ecx * 4);
    // 004200f2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004200f8  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004200fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420100  3b0d6c185200           +cmp ecx, dword ptr [0x52186c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420106  7c03                   -jl 0x42010b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042010b;
    }
    // 00420108  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042010a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042010b:
    // 0042010b  8b048d60185200         -mov eax, dword ptr [ecx*4 + 0x521860]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.ecx * 4);
    // 00420112  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420118  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042011b  8b82fc020000           -mov eax, dword ptr [edx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(764) /* 0x2fc */);
    // 00420121  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420130  3b0d98185200           +cmp ecx, dword ptr [0x521898]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420136  7c03                   -jl 0x42013b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042013b;
    }
    // 00420138  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042013a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042013b:
    // 0042013b  8b048d70185200         -mov eax, dword ptr [ecx*4 + 0x521870]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380208) /* 0x521870 */ + cpu.ecx * 4);
    // 00420142  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420148  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042014b  8b82fc020000           -mov eax, dword ptr [edx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(764) /* 0x2fc */);
    // 00420151  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420160  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00420162  8b0d6c185200           -mov ecx, dword ptr [0x52186c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 00420168  89048d60185200         -mov dword ptr [ecx*4 + 0x521860], eax
    app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.ecx * 4) = cpu.eax;
    // 0042016f  a16c185200             -mov eax, dword ptr [0x52186c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */);
    // 00420174  40                     -inc eax
    (cpu.eax)++;
    // 00420175  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420178  a36c185200             -mov dword ptr [0x52186c], eax
    app->getMemory<x86::reg32>(x86::reg32(5380204) /* 0x52186c */) = cpu.eax;
    // 0042017d  7f13                   -jg 0x420192
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00420192;
    }
    // 0042017f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420181  7d0e                   -jge 0x420191
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420191;
    }
    // 00420183  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420184  68081e4900             -push 0x491e08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791816 /*0x491e08*/;
    cpu.esp -= 4;
    // 00420189  e8824a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042018e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420191:
    // 00420191  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420192:
    // 00420192  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00420194  68cc1d4900             -push 0x491dcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791756 /*0x491dcc*/;
    cpu.esp -= 4;
    // 00420199  e8724a0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042019e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004201a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4201b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004201b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004201b1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004201b3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004201b5  740e                   -je 0x4201c5
    if (cpu.flags.zf)
    {
        goto L_0x004201c5;
    }
L_0x004201b7:
    // 004201b7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004201b9  8b761c                 -mov esi, dword ptr [esi + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004201bc  e80ff5ffff             -call 0x41f6d0
    cpu.esp -= 4;
    sub_41f6d0(app, cpu);
    // 004201c1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004201c3  75f2                   -jne 0x4201b7
    if (!cpu.flags.zf)
    {
        goto L_0x004201b7;
    }
L_0x004201c5:
    // 004201c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004201c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4201d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004201d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004201d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004201d3  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 004201d9  e8d2ffffff             -call 0x4201b0
    cpu.esp -= 4;
    sub_4201b0(app, cpu);
    // 004201de  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004201e0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004201e2  898680000000           -mov dword ptr [esi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 004201e8  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 004201ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004201ef  e90c000000             -jmp 0x420200
    goto L_0x00420200;
L_0x00420200:
    // 00420200  a1a4185200             -mov eax, dword ptr [0x5218a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */);
    // 00420205  898138010000           -mov dword ptr [ecx + 0x138], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(312) /* 0x138 */) = cpu.eax;
    // 0042020b  890da4185200           -mov dword ptr [0x5218a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5380260) /* 0x5218a4 */) = cpu.ecx;
    // 00420211  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420221  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00420223  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420224  f686f802000008         +test byte ptr [esi + 0x2f8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(760) /* 0x2f8 */) & 8 /*0x8*/));
    // 0042022b  7512                   -jne 0x42023f
    if (!cpu.flags.zf)
    {
        goto L_0x0042023f;
    }
    // 0042022d  68701e4900             -push 0x491e70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791920 /*0x491e70*/;
    cpu.esp -= 4;
    // 00420232  e8806b0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00420237  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042023a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042023c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042023d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042023e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042023f:
    // 0042023f  8bbefc020000           -mov edi, dword ptr [esi + 0x2fc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */);
    // 00420245  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00420247  7512                   -jne 0x42025b
    if (!cpu.flags.zf)
    {
        goto L_0x0042025b;
    }
    // 00420249  68401e4900             -push 0x491e40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791872 /*0x491e40*/;
    cpu.esp -= 4;
    // 0042024e  e8646b0500             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00420253  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420256  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420258  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420259  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042025a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042025b:
    // 0042025b  6898185200             -push 0x521898
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380248 /*0x521898*/;
    cpu.esp -= 4;
    // 00420260  ba70185200             -mov edx, 0x521870
    cpu.edx = 5380208 /*0x521870*/;
    // 00420265  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420267  e854000000             -call 0x4202c0
    cpu.esp -= 4;
    sub_4202c0(app, cpu);
    // 0042026c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042026e  7511                   -jne 0x420281
    if (!cpu.flags.zf)
    {
        goto L_0x00420281;
    }
    // 00420270  686c185200             -push 0x52186c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380204 /*0x52186c*/;
    cpu.esp -= 4;
    // 00420275  ba60185200             -mov edx, 0x521860
    cpu.edx = 5380192 /*0x521860*/;
    // 0042027a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042027c  e83f000000             -call 0x4202c0
    cpu.esp -= 4;
    sub_4202c0(app, cpu);
L_0x00420281:
    // 00420281  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00420283  e848ffffff             -call 0x4201d0
    cpu.esp -= 4;
    sub_4201d0(app, cpu);
    // 00420288  8b86f8020000           -mov eax, dword ptr [esi + 0x2f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(760) /* 0x2f8 */);
    // 0042028e  c786fc02000000000000   -mov dword ptr [esi + 0x2fc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(764) /* 0x2fc */) = 0 /*0x0*/;
    // 00420298  24f7                   -and al, 0xf7
    cpu.al &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0042029a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0042029f  8986f8020000           -mov dword ptr [esi + 0x2f8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(760) /* 0x2f8 */) = cpu.eax;
    // 004202a5  c705a018520000000000   -mov dword ptr [0x5218a0], 0
    app->getMemory<x86::reg32>(x86::reg32(5380256) /* 0x5218a0 */) = 0 /*0x0*/;
    // 004202af  e87cfaffff             -call 0x41fd30
    cpu.esp -= 4;
    sub_41fd30(app, cpu);
    // 004202b4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004202b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4202c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004202c0  8a81f8020000           -mov al, byte ptr [ecx + 0x2f8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(760) /* 0x2f8 */);
    // 004202c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004202c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004202c8  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004202ca  7422                   -je 0x4202ee
    if (cpu.flags.zf)
    {
        goto L_0x004202ee;
    }
    // 004202cc  8b81fc020000           -mov eax, dword ptr [ecx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 004202d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004202d4  7418                   -je 0x4202ee
    if (cpu.flags.zf)
    {
        goto L_0x004202ee;
    }
    // 004202d6  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004202da  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004202dc  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 004202de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004202e0  7e0c                   -jle 0x4202ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004202ee;
    }
    // 004202e2  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
L_0x004202e4:
    // 004202e4  3b0c82                 +cmp ecx, dword ptr [edx + eax*4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004202e7  740c                   -je 0x4202f5
    if (cpu.flags.zf)
    {
        goto L_0x004202f5;
    }
    // 004202e9  40                     -inc eax
    (cpu.eax)++;
    // 004202ea  3bc6                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004202ec  7cf6                   -jl 0x4202e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004202e4;
    }
L_0x004202ee:
    // 004202ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202f0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004202f2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004202f5:
    // 004202f5  4e                     -dec esi
    (cpu.esi)--;
    // 004202f6  3bc6                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004202f8  7d0f                   -jge 0x420309
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420309;
    }
L_0x004202fa:
    // 004202fa  8b4c8204               -mov ecx, dword ptr [edx + eax*4 + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004202fe  890c82                 -mov dword ptr [edx + eax*4], ecx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = cpu.ecx;
    // 00420301  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00420303  40                     -inc eax
    (cpu.eax)++;
    // 00420304  49                     -dec ecx
    (cpu.ecx)--;
    // 00420305  3bc1                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420307  7cf1                   -jl 0x4202fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004202fa;
    }
L_0x00420309:
    // 00420309  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042030b  48                     -dec eax
    (cpu.eax)--;
    // 0042030c  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0042030e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042030f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420310  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420315  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_420320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420320  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00420322  8b0d98185200           -mov ecx, dword ptr [0x521898]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */);
    // 00420328  89048d70185200         -mov dword ptr [ecx*4 + 0x521870], eax
    app->getMemory<x86::reg32>(x86::reg32(5380208) /* 0x521870 */ + cpu.ecx * 4) = cpu.eax;
    // 0042032f  a198185200             -mov eax, dword ptr [0x521898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */);
    // 00420334  40                     -inc eax
    (cpu.eax)++;
    // 00420335  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420338  a398185200             -mov dword ptr [0x521898], eax
    app->getMemory<x86::reg32>(x86::reg32(5380248) /* 0x521898 */) = cpu.eax;
    // 0042033d  7f13                   -jg 0x420352
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00420352;
    }
    // 0042033f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420341  7d0e                   -jge 0x420351
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420351;
    }
    // 00420343  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420344  68dc1e4900             -push 0x491edc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792028 /*0x491edc*/;
    cpu.esp -= 4;
    // 00420349  e8c2480000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042034e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420351:
    // 00420351  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420352:
    // 00420352  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00420354  68981e4900             -push 0x491e98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4791960 /*0x491e98*/;
    cpu.esp -= 4;
    // 00420359  e8b2480000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042035e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420361  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420370  e81bf9ffff             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 00420375  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420377  7415                   -je 0x42038e
    if (cpu.flags.zf)
    {
        goto L_0x0042038e;
    }
    // 00420379  8b9080000000           -mov edx, dword ptr [eax + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0042037f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420381  740b                   -je 0x42038e
    if (cpu.flags.zf)
    {
        goto L_0x0042038e;
    }
L_0x00420383:
    // 00420383  3b0a                   +cmp ecx, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420385  740e                   -je 0x420395
    if (cpu.flags.zf)
    {
        goto L_0x00420395;
    }
    // 00420387  8b521c                 -mov edx, dword ptr [edx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0042038a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042038c  75f5                   -jne 0x420383
    if (!cpu.flags.zf)
    {
        goto L_0x00420383;
    }
L_0x0042038e:
    // 0042038e  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
L_0x00420394:
    // 00420394  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420395:
    // 00420395  d94210                 -fld dword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */)));
    // 00420398  d8720c                 -fdiv dword ptr [edx + 0xc]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0042039b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0042039d  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004203a0  8b94018c000000         -mov edx, dword ptr [ecx + eax + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */ + cpu.eax * 1);
    // 004203a7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004203a9  dc2d68734800           +fsubr qword ptr [0x487368]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)) - cpu.fpu.st(0);
    // 004203af  7ee3                   -jle 0x420394
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420394;
    }
    // 004203b1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004203b3  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 004203b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4203c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004203c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004203c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004203c2  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004203c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004203c7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004203c9  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004203cb  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004203cd  750d                   -jne 0x4203dc
    if (!cpu.flags.zf)
    {
        goto L_0x004203dc;
    }
    // 004203cf  68101f4900             -push 0x491f10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792080 /*0x491f10*/;
    cpu.esp -= 4;
    // 004203d4  e837480000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004203d9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004203dc:
    // 004203dc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004203de  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004203e0  7510                   -jne 0x4203f2
    if (!cpu.flags.zf)
    {
        goto L_0x004203f2;
    }
    // 004203e2  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004203e5  e8e6f2ffff             -call 0x41f6d0
    cpu.esp -= 4;
    sub_41f6d0(app, cpu);
    // 004203ea  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004203ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203ef  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004203f2:
    // 004203f2  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004203f5  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004203f8  e8d3f2ffff             -call 0x41f6d0
    cpu.esp -= 4;
    sub_41f6d0(app, cpu);
    // 004203fd  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004203ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420400  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420401  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420402  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_420410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420410  e87bf8ffff             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 00420415  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420417  7507                   -jne 0x420420
    if (!cpu.flags.zf)
    {
        goto L_0x00420420;
    }
    // 00420419  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0042041f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420420:
    // 00420420  d98028010000           -fld dword ptr [eax + 0x128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(296) /* 0x128 */)));
    // 00420426  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420430  e8cbfcffff             -call 0x420100
    cpu.esp -= 4;
    sub_420100(app, cpu);
    // 00420435  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420437  7507                   -jne 0x420440
    if (!cpu.flags.zf)
    {
        goto L_0x00420440;
    }
    // 00420439  d905ec724800           -fld dword ptr [0x4872ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    // 0042043f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420440:
    // 00420440  d98028010000           -fld dword ptr [eax + 0x128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(296) /* 0x128 */)));
    // 00420446  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420450  e84bf8ffff             -call 0x41fca0
    cpu.esp -= 4;
    sub_41fca0(app, cpu);
    // 00420455  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420457  7c25                   -jl 0x42047e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042047e;
    }
    // 00420459  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042045b  7c21                   -jl 0x42047e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042047e;
    }
    // 0042045d  83f908                 +cmp ecx, 8
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420460  7d1c                   -jge 0x42047e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042047e;
    }
    // 00420462  e839f8ffff             -call 0x41fca0
    cpu.esp -= 4;
    sub_41fca0(app, cpu);
    // 00420467  8b048560185200         -mov eax, dword ptr [eax*4 + 0x521860]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380192) /* 0x521860 */ + cpu.eax * 4);
    // 0042046e  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00420470  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420476  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00420479  e922000000             -jmp 0x4204a0
    return sub_4204a0(app, cpu);
L_0x0042047e:
    // 0042047e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420480  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00420481  7515                   -jne 0x420498
    if (!cpu.flags.zf)
    {
        goto L_0x00420498;
    }
    // 00420483  e8f8c8feff             -call 0x40cd80
    cpu.esp -= 4;
    sub_40cd80(app, cpu);
    // 00420488  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420489  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042048c  e86fc9feff             -call 0x40ce00
    cpu.esp -= 4;
    sub_40ce00(app, cpu);
    // 00420491  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420493  e8b8890000             -call 0x428e50
    cpu.esp -= 4;
    sub_428e50(app, cpu);
L_0x00420498:
    // 00420498  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4204a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004204a0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004204a3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004204a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004204a5  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004204a7  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004204a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004204aa  3bdd                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004204ad  0f8c75010000           -jl 0x420628
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420628;
    }
    // 004204b3  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204b6  0f8f6c010000           -jg 0x420628
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00420628;
    }
    // 004204bc  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204bf  0f8463010000           -je 0x420628
    if (cpu.flags.zf)
    {
        goto L_0x00420628;
    }
    // 004204c5  8bb1fc020000           -mov esi, dword ptr [ecx + 0x2fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 004204cb  3bf5                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204cd  0f8463010000           -je 0x420636
    if (cpu.flags.zf)
    {
        goto L_0x00420636;
    }
    // 004204d3  8bbe80000000           -mov edi, dword ptr [esi + 0x80]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 004204d9  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004204dd  3bfd                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204df  7416                   -je 0x4204f7
    if (cpu.flags.zf)
    {
        goto L_0x004204f7;
    }
L_0x004204e1:
    // 004204e1  391f                   +cmp dword ptr [edi], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204e3  740d                   -je 0x4204f2
    if (cpu.flags.zf)
    {
        goto L_0x004204f2;
    }
    // 004204e5  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004204e9  8b7f1c                 -mov edi, dword ptr [edi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004204ec  3bfd                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204ee  75f1                   -jne 0x4204e1
    if (!cpu.flags.zf)
    {
        goto L_0x004204e1;
    }
    // 004204f0  eb05                   -jmp 0x4204f7
    goto L_0x004204f7;
L_0x004204f2:
    // 004204f2  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x004204f7:
    // 004204f7  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004204f9  e882ffffff             -call 0x420480
    cpu.esp -= 4;
    sub_420480(app, cpu);
    // 004204fe  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420500  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00420503  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420506  0f85c8000000           -jne 0x4205d4
    if (!cpu.flags.zf)
    {
        goto L_0x004205d4;
    }
    // 0042050c  8d2c30                 -lea ebp, [eax + esi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0042050f  8d4b09                 -lea ecx, [ebx + 9]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(9) /* 0x9 */);
    // 00420512  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00420515  c7858c00000000000000   -mov dword ptr [ebp + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 0042051f  899e14010000           -mov dword ptr [esi + 0x114], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */) = cpu.ebx;
    // 00420525  c7043100000000         -mov dword ptr [ecx + esi], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 1) = 0 /*0x0*/;
    // 0042052c  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 00420531  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00420533  750c                   -jne 0x420541
    if (!cpu.flags.zf)
    {
        goto L_0x00420541;
    }
    // 00420535  c7861c01000000000040   -mov dword ptr [esi + 0x11c], 0x40000000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */) = 1073741824 /*0x40000000*/;
    // 0042053f  eb1b                   -jmp 0x42055c
    goto L_0x0042055c;
L_0x00420541:
    // 00420541  e86af7ffff             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 00420546  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00420549  8d1480                 -lea edx, [eax + eax*4]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042054c  03d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0042054e  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00420552  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00420556  d99e1c010000           -fstp dword ptr [esi + 0x11c]
    app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042055c:
    // 0042055c  83bd8c00000001         +cmp dword ptr [ebp + 0x8c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420563  7505                   -jne 0x42056a
    if (!cpu.flags.zf)
    {
        goto L_0x0042056a;
    }
    // 00420565  d94708                 +fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00420568  eb03                   -jmp 0x42056d
    goto L_0x0042056d;
L_0x0042056a:
    // 0042056a  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
L_0x0042056d:
    // 0042056d  d88628010000           -fadd dword ptr [esi + 0x128]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */));
    // 00420573  d99628010000           -fst dword ptr [esi + 0x128]
    app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */) = float(cpu.fpu.st(0));
    // 00420579  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0042057f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00420581  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00420586  750a                   -jne 0x420592
    if (!cpu.flags.zf)
    {
        goto L_0x00420592;
    }
    // 00420588  c786280100000000803f   -mov dword ptr [esi + 0x128], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = 1065353216 /*0x3f800000*/;
L_0x00420592:
    // 00420592  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00420596  8b8e80000000           -mov ecx, dword ptr [esi + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042059c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042059d  e81efeffff             -call 0x4203c0
    cpu.esp -= 4;
    sub_4203c0(app, cpu);
    // 004205a2  898680000000           -mov dword ptr [esi + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 004205a8  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004205ae  48                     -dec eax
    (cpu.eax)--;
    // 004205af  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004205b1  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 004205b7  c7859800000000000000   -mov dword ptr [ebp + 0x98], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 004205c1  e86a050000             -call 0x420b30
    cpu.esp -= 4;
    sub_420b30(app, cpu);
    // 004205c6  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004205c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205cc  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004205cf  e92ca3ffff             -jmp 0x41a900
    return sub_41a900(app, cpu);
L_0x004205d4:
    // 004205d4  8b8c3098000000         -mov ecx, dword ptr [eax + esi + 0x98]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */ + cpu.esi * 1);
    // 004205db  8d843098000000         -lea eax, [eax + esi + 0x98]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(152) /* 0x98 */ + cpu.esi * 1);
    // 004205e2  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004205e5  7d4f                   -jge 0x420636
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420636;
    }
    // 004205e7  41                     -inc ecx
    (cpu.ecx)++;
    // 004205e8  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004205ea  8b4e54                 -mov ecx, dword ptr [esi + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004205ed  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004205f0  e88bf6ffff             -call 0x41fc80
    cpu.esp -= 4;
    sub_41fc80(app, cpu);
    // 004205f5  dc0de0724800           -fmul qword ptr [0x4872e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748000) /* 0x4872e0 */));
    // 004205fb  d88628010000           -fadd dword ptr [esi + 0x128]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */));
    // 00420601  d99628010000           -fst dword ptr [esi + 0x128]
    app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */) = float(cpu.fpu.st(0));
    // 00420607  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0042060d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042060f  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00420614  7520                   -jne 0x420636
    if (!cpu.flags.zf)
    {
        goto L_0x00420636;
    }
    // 00420616  c786280100000000803f   -mov dword ptr [esi + 0x128], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(296) /* 0x128 */) = 1065353216 /*0x3f800000*/;
    // 00420620  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420621  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420623  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420624  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420627  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420628:
    // 00420628  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420629  68201f4900             -push 0x491f20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792096 /*0x491f20*/;
    cpu.esp -= 4;
    // 0042062e  e8dd450000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420633  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00420636:
    // 00420636  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420637  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420638  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420639  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042063a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042063d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420640  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420641  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420642  e879f6ffff             -call 0x41fcc0
    cpu.esp -= 4;
    sub_41fcc0(app, cpu);
    // 00420647  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00420649  e842f6ffff             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 0042064e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420650  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00420652  741e                   -je 0x420672
    if (cpu.flags.zf)
    {
        goto L_0x00420672;
    }
    // 00420654  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420657  7419                   -je 0x420672
    if (cpu.flags.zf)
    {
        goto L_0x00420672;
    }
    // 00420659  e822f60000             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 0042065e  3b464c                 +cmp eax, dword ptr [esi + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420661  750f                   -jne 0x420672
    if (!cpu.flags.zf)
    {
        goto L_0x00420672;
    }
    // 00420663  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420666  7c0a                   -jl 0x420672
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420672;
    }
    // 00420668  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042066b  7f05                   -jg 0x420672
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00420672;
    }
    // 0042066d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042066f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420670  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420671  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420672:
    // 00420672  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420673  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00420676  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420677  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420680  8b81fc020000           -mov eax, dword ptr [ecx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 00420686  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420688  7501                   -jne 0x42068b
    if (!cpu.flags.zf)
    {
        goto L_0x0042068b;
    }
    // 0042068a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042068b:
    // 0042068b  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0042068e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042068f  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00420692  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420694  3bce                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420696  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420697  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0042069a  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042069c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4206a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004206a0  8b81fc020000           -mov eax, dword ptr [ecx + 0x2fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(764) /* 0x2fc */);
    // 004206a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004206a8  7504                   -jne 0x4206ae
    if (!cpu.flags.zf)
    {
        goto L_0x004206ae;
    }
    // 004206aa  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004206ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004206ae:
    // 004206ae  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004206b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4206c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004206c0  e8dbffffff             -call 0x4206a0
    cpu.esp -= 4;
    sub_4206a0(app, cpu);
    // 004206c5  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004206c8  7503                   -jne 0x4206cd
    if (!cpu.flags.zf)
    {
        goto L_0x004206cd;
    }
    // 004206ca  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004206cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004206cd:
    // 004206cd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004206cf  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004206d1  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 004206d4  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004206d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4206e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004206e0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004206e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004206e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004206e5  e8c6f5ffff             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 004206ea  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004206ec  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004206ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004206f0  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004206f4  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004206f8  7e31                   -jle 0x42072b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042072b;
    }
    // 004206fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004206fb:
    // 004206fb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004206fd  e8fef9ffff             -call 0x420100
    cpu.esp -= 4;
    sub_420100(app, cpu);
    // 00420702  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00420704  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00420706  750d                   -jne 0x420715
    if (!cpu.flags.zf)
    {
        goto L_0x00420715;
    }
    // 00420708  68401f4900             -push 0x491f40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792128 /*0x491f40*/;
    cpu.esp -= 4;
    // 0042070d  e8fe440000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420712  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00420715:
    // 00420715  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00420719  d88728010000           -fadd dword ptr [edi + 0x128]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(296) /* 0x128 */));
    // 0042071f  46                     -inc esi
    (cpu.esi)++;
    // 00420720  3bf3                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420722  d95c240c               +fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00420726  7cd3                   -jl 0x4206fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004206fb;
    }
    // 00420728  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420729  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
L_0x0042072b:
    // 0042072b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042072c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042072d  750a                   -jne 0x420739
    if (!cpu.flags.zf)
    {
        goto L_0x00420739;
    }
    // 0042072f  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00420735  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420738  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420739:
    // 00420739  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0042073d  d87c2400               -fdivr dword ptr [esp]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp)) / cpu.fpu.st(0);
    // 00420741  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420744  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420750  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420753  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420754  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420755  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00420757  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420758  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042075a  833cb5e4c94a0001       +cmp dword ptr [esi*4 + 0x4ac9e4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4901348) /* 0x4ac9e4 */ + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420762  0f84c5000000           -je 0x42082d
    if (cpu.flags.zf)
    {
        goto L_0x0042082d;
    }
    // 00420768  e8838d0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 0042076d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042076f  e8ec010000             -call 0x420960
    cpu.esp -= 4;
    sub_420960(app, cpu);
    // 00420774  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420776  750d                   -jne 0x420785
    if (!cpu.flags.zf)
    {
        goto L_0x00420785;
    }
    // 00420778  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042077a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042077b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042077c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042077d  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420780  e91b020000             -jmp 0x4209a0
    return sub_4209a0(app, cpu);
L_0x00420785:
    // 00420785  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00420787  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00420789  e8b2000000             -call 0x420840
    cpu.esp -= 4;
    sub_420840(app, cpu);
    // 0042078e  8b4754                 -mov eax, dword ptr [edi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 00420791  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00420795  8d0cc6                 -lea ecx, [esi + eax*8]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 8);
    // 00420798  e8b3000000             -call 0x420850
    cpu.esp -= 4;
    sub_420850(app, cpu);
    // 0042079d  d9542410               -fst dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    // 004207a1  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004207a5  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004207ab  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004207ad  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 004207b0  7b36                   -jnp 0x4207e8
    if (!cpu.flags.pf)
    {
        goto L_0x004207e8;
    }
    // 004207b2  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004207b6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004207b8  dc1dd8744800           -fcomp qword ptr [0x4874d8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */)));
    cpu.fpu.pop();
    // 004207be  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004207c0  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004207c5  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004207c7  750c                   -jne 0x4207d5
    if (!cpu.flags.zf)
    {
        goto L_0x004207d5;
    }
    // 004207c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004207ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004207cb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004207d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004207d1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004207d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004207d5:
    // 004207d5  e87d660500             -call 0x476e57
    cpu.esp -= 4;
    _rand(app, cpu);
    // 004207da  2403                   -and al, 3
    cpu.al &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004207dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004207dd  f6d8                   +neg al
    {
        x86::reg8 tmp1 = 0;
        x86::reg8& tmp2 = cpu.al;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004207df  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004207e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004207e2  40                     -inc eax
    (cpu.eax)++;
    // 004207e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004207e4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004207e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004207e8:
    // 004207e8  dc1dd8744800           -fcomp qword ptr [0x4874d8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */)));
    cpu.fpu.pop();
    // 004207ee  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004207f0  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004207f3  7b38                   -jnp 0x42082d
    if (!cpu.flags.pf)
    {
        goto L_0x0042082d;
    }
    // 004207f5  e85d660500             -call 0x476e57
    cpu.esp -= 4;
    _rand(app, cpu);
    // 004207fa  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004207fb  b932000000             -mov ecx, 0x32
    cpu.ecx = 50 /*0x32*/;
    // 00420800  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00420802  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00420806  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0042080a  dc0d98744800           -fmul qword ptr [0x487498]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748440) /* 0x487498 */));
    // 00420810  dc05d8744800           -fadd qword ptr [0x4874d8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00420816  d85c2410               -fcomp dword ptr [esp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0042081a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042081c  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042081f  7a0c                   -jp 0x42082d
    if (cpu.flags.pf)
    {
        goto L_0x0042082d;
    }
    // 00420821  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420822  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420823  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420828  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420829  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042082c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042082d:
    // 0042082d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042082e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042082f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420831  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420832  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420835  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420840  8d04ca                 -lea eax, [edx + ecx*8]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 8);
    // 00420843  d90485c8114900         -fld dword ptr [eax*4 + 0x4911c8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4788680) /* 0x4911c8 */ + cpu.eax * 4)));
    // 0042084a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420850  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 00420853  8b0da8144900           -mov ecx, dword ptr [0x4914a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4789416) /* 0x4914a8 */);
    // 00420859  d9448110               -fld dword ptr [ecx + eax*4 + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 4)));
    // 0042085d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420860  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420865  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00420868  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420870  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00420875  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420876  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00420878  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420879  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0042087c  8bbafc020000           -mov edi, dword ptr [edx + 0x2fc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(764) /* 0x2fc */);
    // 00420882  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00420884  7514                   -jne 0x42089a
    if (!cpu.flags.zf)
    {
        goto L_0x0042089a;
    }
    // 00420886  e835f4ffff             -call 0x41fcc0
    cpu.esp -= 4;
    sub_41fcc0(app, cpu);
    // 0042088b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042088c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042088d  68481f4900             -push 0x491f48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792136 /*0x491f48*/;
    cpu.esp -= 4;
    // 00420892  e879430000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00420897  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042089a:
    // 0042089a  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0042089d  8b843e94000000         -mov eax, dword ptr [esi + edi + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */ + cpu.edi * 1);
    // 004208a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004208a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004208a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4208b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004208b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004208b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004208b2  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004208b4  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004208b6  e8f5f3ffff             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 004208bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004208bd  7e2a                   -jle 0x4208e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004208e9;
    }
L_0x004208bf:
    // 004208bf  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004208c1  e83af8ffff             -call 0x420100
    cpu.esp -= 4;
    sub_420100(app, cpu);
    // 004208c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004208c8  7415                   -je 0x4208df
    if (cpu.flags.zf)
    {
        goto L_0x004208df;
    }
    // 004208ca  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004208d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004208d2  740b                   -je 0x4208df
    if (cpu.flags.zf)
    {
        goto L_0x004208df;
    }
L_0x004208d4:
    // 004208d4  3b38                   +cmp edi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004208d6  7416                   -je 0x4208ee
    if (cpu.flags.zf)
    {
        goto L_0x004208ee;
    }
    // 004208d8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004208db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004208dd  75f5                   -jne 0x4208d4
    if (!cpu.flags.zf)
    {
        goto L_0x004208d4;
    }
L_0x004208df:
    // 004208df  46                     -inc esi
    (cpu.esi)++;
    // 004208e0  e8cbf3ffff             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 004208e5  3bf0                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004208e7  7cd6                   -jl 0x4208bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004208bf;
    }
L_0x004208e9:
    // 004208e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004208ea  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004208ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004208ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004208ee:
    // 004208ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004208ef  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004208f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004208f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420900  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420905  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420906  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420908  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420909  751e                   -jne 0x420929
    if (!cpu.flags.zf)
    {
        goto L_0x00420929;
    }
    // 0042090b  6808010000             -push 0x108
    app->getMemory<x86::reg32>(cpu.esp-4) = 264 /*0x108*/;
    cpu.esp -= 4;
    // 00420910  e865690500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00420915  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420918  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042091a  b942000000             -mov ecx, 0x42
    cpu.ecx = 66 /*0x42*/;
    // 0042091f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420921  893de0c94a00           -mov dword ptr [0x4ac9e0], edi
    app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */) = cpu.edi;
    // 00420927  f3ab                   -rep stosd dword ptr es:[edi], eax
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
        }
        else
        {
            cpu.edi += 4;
        }
        --cpu.ecx;
    }
L_0x00420929:
    // 00420929  e8c28b0000             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 0042092e  c1e005                 +shl eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00420931  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00420936  8db0e8104900           -lea esi, [eax + 0x4910e8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4788456) /* 0x4910e8 */);
    // 0042093c  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420941  8db880000000           -lea edi, [eax + 0x80]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00420947  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00420949  8b0de0c94a00           -mov ecx, dword ptr [0x4ac9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 0042094f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420950  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420951  c781a000000001000000   -mov dword ptr [ecx + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 0042095b  e920020000             -jmp 0x420b80
    return sub_420b80(app, cpu);
}

/* align: skip  */
void Application::sub_420960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420960  8b0de0c94a00           -mov ecx, dword ptr [0x4ac9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420966  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420967  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420969  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042096b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042096c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042096e:
    // 0042096e  8bbc8180000000         -mov edi, dword ptr [ecx + eax*4 + 0x80]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.eax * 4);
    // 00420975  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00420977  7409                   -je 0x420982
    if (cpu.flags.zf)
    {
        goto L_0x00420982;
    }
    // 00420979  8b3c81                 -mov edi, dword ptr [ecx + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042097c  42                     -inc edx
    (cpu.edx)++;
    // 0042097d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042097f  7401                   -je 0x420982
    if (cpu.flags.zf)
    {
        goto L_0x00420982;
    }
    // 00420981  46                     -inc esi
    (cpu.esi)++;
L_0x00420982:
    // 00420982  40                     -inc eax
    (cpu.eax)++;
    // 00420983  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420986  7ce6                   -jl 0x42096e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042096e;
    }
    // 00420988  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042098a  3bd6                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042098c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042098d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042098e  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00420991  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4209a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004209a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004209a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004209a2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004209a4  e867000000             -call 0x420a10
    cpu.esp -= 4;
    sub_420a10(app, cpu);
    // 004209a9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004209ab  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004209ae  7519                   -jne 0x4209c9
    if (!cpu.flags.zf)
    {
        goto L_0x004209c9;
    }
    // 004209b0  3bf0                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004209b2  7515                   -jne 0x4209c9
    if (!cpu.flags.zf)
    {
        goto L_0x004209c9;
    }
    // 004209b4  e817000000             -call 0x4209d0
    cpu.esp -= 4;
    sub_4209d0(app, cpu);
    // 004209b9  3bc7                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004209bb  750c                   -jne 0x4209c9
    if (!cpu.flags.zf)
    {
        goto L_0x004209c9;
    }
    // 004209bd  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004209bf  e8ec020000             -call 0x420cb0
    cpu.esp -= 4;
    sub_420cb0(app, cpu);
    // 004209c4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004209c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004209c9:
    // 004209c9  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004209cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4209d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004209d0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004209d3  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004209d7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004209db  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 004209df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004209e0  e88b72ffff             -call 0x417c70
    cpu.esp -= 4;
    sub_417c70(app, cpu);
    // 004209e5  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004209e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004209eb  7519                   -jne 0x420a06
    if (!cpu.flags.zf)
    {
        goto L_0x00420a06;
    }
    // 004209ed  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004209f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004209f3  7511                   -jne 0x420a06
    if (!cpu.flags.zf)
    {
        goto L_0x00420a06;
    }
    // 004209f5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004209f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004209fb  7509                   -jne 0x420a06
    if (!cpu.flags.zf)
    {
        goto L_0x00420a06;
    }
    // 004209fd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420a02  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00420a05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420a06:
    // 00420a06  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420a08  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00420a0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420a10  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420a15  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420a16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420a17  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420a18  8b90a0000000           -mov edx, dword ptr [eax + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 00420a1e  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00420a20  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a23  b9fe000000             -mov ecx, 0xfe
    cpu.ecx = 254 /*0xfe*/;
    // 00420a28  750d                   -jne 0x420a37
    if (!cpu.flags.zf)
    {
        goto L_0x00420a37;
    }
    // 00420a2a  398cb880000000         +cmp dword ptr [eax + edi*4 + 0x80], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */ + cpu.edi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a31  0f8490000000           -je 0x420ac7
    if (cpu.flags.zf)
    {
        goto L_0x00420ac7;
    }
L_0x00420a37:
    // 00420a37  e8c4000000             -call 0x420b00
    cpu.esp -= 4;
    sub_420b00(app, cpu);
    // 00420a3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420a3e  7406                   -je 0x420a46
    if (cpu.flags.zf)
    {
        goto L_0x00420a46;
    }
    // 00420a40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a42  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420a44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420a46:
    // 00420a46  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420a4b  8bb0a0000000           -mov esi, dword ptr [eax + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 00420a51  8d98a0000000           -lea ebx, [eax + 0xa0]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 00420a57  8d8880000000           -lea ecx, [eax + 0x80]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00420a5d  e86e000000             -call 0x420ad0
    cpu.esp -= 4;
    sub_420ad0(app, cpu);
    // 00420a62  8b0de0c94a00           -mov ecx, dword ptr [0x4ac9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420a68  40                     -inc eax
    (cpu.eax)++;
    // 00420a69  3bc6                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a6b  750d                   -jne 0x420a7a
    if (!cpu.flags.zf)
    {
        goto L_0x00420a7a;
    }
    // 00420a6d  81bcb980000000fd000000 +cmp dword ptr [ecx + edi*4 + 0x80], 0xfd
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.edi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a78  744d                   -je 0x420ac7
    if (cpu.flags.zf)
    {
        goto L_0x00420ac7;
    }
L_0x00420a7a:
    // 00420a7a  8b84b980000000         -mov eax, dword ptr [ecx + edi*4 + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.edi * 4);
    // 00420a81  3bf0                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a83  7438                   -je 0x420abd
    if (cpu.flags.zf)
    {
        goto L_0x00420abd;
    }
    // 00420a85  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a8a  743b                   -je 0x420ac7
    if (cpu.flags.zf)
    {
        goto L_0x00420ac7;
    }
    // 00420a8c  3dc8000000             +cmp eax, 0xc8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a91  7d24                   -jge 0x420ab7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420ab7;
    }
    // 00420a93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420a95  7e20                   -jle 0x420ab7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420ab7;
    }
    // 00420a97  833cb900               +cmp dword ptr [ecx + edi*4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + cpu.edi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a9b  751a                   -jne 0x420ab7
    if (!cpu.flags.zf)
    {
        goto L_0x00420ab7;
    }
    // 00420a9d  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00420aa3  e828000000             -call 0x420ad0
    cpu.esp -= 4;
    sub_420ad0(app, cpu);
    // 00420aa8  8b0de0c94a00           -mov ecx, dword ptr [0x4ac9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420aae  40                     -inc eax
    (cpu.eax)++;
    // 00420aaf  3b81a0000000           +cmp eax, dword ptr [ecx + 0xa0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420ab5  7410                   -je 0x420ac7
    if (cpu.flags.zf)
    {
        goto L_0x00420ac7;
    }
L_0x00420ab7:
    // 00420ab7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ab8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ab9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420abb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420abc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420abd:
    // 00420abd  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420ac2  7403                   -je 0x420ac7
    if (cpu.flags.zf)
    {
        goto L_0x00420ac7;
    }
    // 00420ac4  46                     -inc esi
    (cpu.esi)++;
    // 00420ac5  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
L_0x00420ac7:
    // 00420ac7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ac8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ac9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420ace  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420acf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420ad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420ad1  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00420ad4  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00420ad6:
    // 00420ad6  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00420ad9  81fafa000000           +cmp edx, 0xfa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(250 /*0xfa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420adf  7f06                   -jg 0x420ae7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00420ae7;
    }
    // 00420ae1  3bd0                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420ae3  7e02                   -jle 0x420ae7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420ae7;
    }
    // 00420ae5  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00420ae7:
    // 00420ae7  46                     -inc esi
    (cpu.esi)++;
    // 00420ae8  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420aeb  7ce9                   -jl 0x420ad6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420ad6;
    }
    // 00420aed  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420af0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420af1  7505                   -jne 0x420af8
    if (!cpu.flags.zf)
    {
        goto L_0x00420af8;
    }
    // 00420af3  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00420af8:
    // 00420af8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420b00  8b15e0c94a00           -mov edx, dword ptr [0x4ac9e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420b06  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00420b08:
    // 00420b08  398c8280000000         +cmp dword ptr [edx + eax*4 + 0x80], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420b0f  7506                   -jne 0x420b17
    if (!cpu.flags.zf)
    {
        goto L_0x00420b17;
    }
    // 00420b11  833c8200               +cmp dword ptr [edx + eax*4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420b15  7409                   -je 0x420b20
    if (cpu.flags.zf)
    {
        goto L_0x00420b20;
    }
L_0x00420b17:
    // 00420b17  40                     -inc eax
    (cpu.eax)++;
    // 00420b18  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420b1b  7ceb                   -jl 0x420b08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420b08;
    }
    // 00420b1d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420b1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420b20:
    // 00420b20  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420b25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420b30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420b31  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00420b33  e828feffff             -call 0x420960
    cpu.esp -= 4;
    sub_420960(app, cpu);
    // 00420b38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420b3a  7508                   -jne 0x420b44
    if (!cpu.flags.zf)
    {
        goto L_0x00420b44;
    }
    // 00420b3c  a1e0c94a00             -mov eax, dword ptr [0x4ac9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420b41  ff04b0                 -inc dword ptr [eax + esi*4]
    (app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4))++;
L_0x00420b44:
    // 00420b44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420b51  8d348d00000000         -lea esi, [ecx*4]
    cpu.esi = x86::reg32(cpu.ecx * 4);
    // 00420b58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420b59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420b5a  e81b670500             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00420b5f  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420b61  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420b63  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420b65  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00420b67  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00420b6a  f3ab                   -rep stosd dword ptr es:[edi], eax
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
        }
        else
        {
            cpu.edi += 4;
        }
        --cpu.ecx;
    }
    // 00420b6c  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00420b6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420b71  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00420b74  f3aa                   -rep stosb byte ptr es:[edi], al
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
    }
    // 00420b76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b77  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420b79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420b80  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00420b85  e8c6ffffff             -call 0x420b50
    cpu.esp -= 4;
    sub_420b50(app, cpu);
    // 00420b8a  a308ca4a00             -mov dword ptr [0x4aca08], eax
    app->getMemory<x86::reg32>(x86::reg32(4901384) /* 0x4aca08 */) = cpu.eax;
    // 00420b8f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00420b91:
    // 00420b91  8b0d08ca4a00           -mov ecx, dword ptr [0x4aca08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4901384) /* 0x4aca08 */);
    // 00420b97  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420b9a  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420b9d  c74408fcffffffff       -mov dword ptr [eax + ecx - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 1) = 4294967295 /*0xffffffff*/;
    // 00420ba5  7cea                   -jl 0x420b91
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420b91;
    }
    // 00420ba7  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420ba9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420baa  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00420bac  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
L_0x00420bb1:
    // 00420bb1  8b35e0c94a00           -mov esi, dword ptr [0x4ac9e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4901344) /* 0x4ac9e0 */);
    // 00420bb7  833c3000               +cmp dword ptr [eax + esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420bbb  740b                   -je 0x420bc8
    if (cpu.flags.zf)
    {
        goto L_0x00420bc8;
    }
    // 00420bbd  8b3508ca4a00           -mov esi, dword ptr [0x4aca08]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4901384) /* 0x4aca08 */);
    // 00420bc3  42                     -inc edx
    (cpu.edx)++;
    // 00420bc4  894c96fc               -mov dword ptr [esi + edx*4 - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.edx * 4) = cpu.ecx;
L_0x00420bc8:
    // 00420bc8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420bcb  41                     -inc ecx
    (cpu.ecx)++;
    // 00420bcc  3da0000000             +cmp eax, 0xa0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420bd1  7cde                   -jl 0x420bb1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420bb1;
    }
    // 00420bd3  89150cca4a00           -mov dword ptr [0x4aca0c], edx
    app->getMemory<x86::reg32>(x86::reg32(4901388) /* 0x4aca0c */) = cpu.edx;
    // 00420bd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420bda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_420be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420be0  a108ca4a00             -mov eax, dword ptr [0x4aca08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4901384) /* 0x4aca08 */);
    // 00420be5  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
