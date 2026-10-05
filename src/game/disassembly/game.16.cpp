#include "game.h"
namespace game
{

/* align: skip  */
void Application::asm_sub_467b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467b40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467b41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467b42  8bb118030000           -mov esi, dword ptr [ecx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 00467b48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467b49  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00467b4b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467b4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467b4e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467b50  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467b52  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00467b56  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00467b59  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00467b5b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467b5c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00467b60  e83afc0000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00467b65  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00467b68  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467b6a  7442                   -je 0x467bae
    if (cpu.flags.zf)
    {
        goto L_0x00467bae;
    }
    // 00467b6c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467b6d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467b6f  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00467b72  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00467b74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467b75  e825fc0000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00467b7a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00467b7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467b7d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467b7f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467b82  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00467b84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467b85  e815fc0000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00467b8a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00467b8c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467b8e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467b90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467b91  668b5104               -mov dx, word ptr [ecx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00467b95  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00467b99  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467b9f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467ba1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467ba2  8d1481                 -lea edx, [ecx + eax*4]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 00467ba5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467ba6  e8f4fb0000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00467bab  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x00467bae:
    // 00467bae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467baf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467bb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467bb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_467bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467bc0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00467bc3  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00467bc7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467bc8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467bc9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467bca  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00467bcc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467bcd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467bcf  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00467bd1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467bd2  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00467bd4  e8affa0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00467bd9  8bb318030000           -mov esi, dword ptr [ebx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(792) /* 0x318 */);
    // 00467bdf  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00467be3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00467be6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467be8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467bea  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00467bed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00467bef  0f84a3000000           -je 0x467c98
    if (cpu.flags.zf)
    {
        goto L_0x00467c98;
    }
    // 00467bf5  3bc1                   +cmp eax, ecx
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
    // 00467bf7  7423                   -je 0x467c1c
    if (cpu.flags.zf)
    {
        goto L_0x00467c1c;
    }
    // 00467bf9  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00467bfb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467bfc  8b8bb4020000           -mov ecx, dword ptr [ebx + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(692) /* 0x2b4 */);
    // 00467c02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467c03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467c04  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467c05  680c2c4a00             -push 0x4a2c0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860940 /*0x4a2c0c*/;
    cpu.esp -= 4;
    // 00467c0a  e8a8f10000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00467c0f  68f82b4a00             -push 0x4a2bf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860920 /*0x4a2bf8*/;
    cpu.esp -= 4;
    // 00467c14  e8f7cffbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467c19  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x00467c1c:
    // 00467c1c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467c1e  7478                   -je 0x467c98
    if (cpu.flags.zf)
    {
        goto L_0x00467c98;
    }
    // 00467c20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467c21  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467c23  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00467c26  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00467c28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467c29  e85afa0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00467c2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467c2f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467c31  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00467c35  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00467c37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467c38  e84bfa0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00467c3d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00467c3f  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00467c43  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00467c46  668b4a04               -mov cx, word ptr [edx + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00467c4a  663bc1                 +cmp ax, cx
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.cx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00467c4d  7428                   -je 0x467c77
    if (cpu.flags.zf)
    {
        goto L_0x00467c77;
    }
    // 00467c4f  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00467c55  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00467c5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467c5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467c5c  68cc2b4a00             -push 0x4a2bcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860876 /*0x4a2bcc*/;
    cpu.esp -= 4;
    // 00467c61  e851f10000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00467c66  68ac2b4a00             -push 0x4a2bac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860844 /*0x4a2bac*/;
    cpu.esp -= 4;
    // 00467c6b  e8a0cffbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467c70  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00467c74  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00467c77:
    // 00467c77  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467c7d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467c7e  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00467c83  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00467c85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467c86  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467c88  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00467c8c  8d1481                 -lea edx, [ecx + eax*4]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 00467c8f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467c90  e8f3f90000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00467c95  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00467c98:
    // 00467c98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467c99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467c9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467c9b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00467c9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_467ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467ca0  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00467ca3  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00467ca7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467ca8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467ca9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467caa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467cab  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467cad  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00467caf  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00467cb1  3bc3                   +cmp eax, ebx
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
    // 00467cb3  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00467cb7  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00467cbb  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00467cc0  752c                   -jne 0x467cee
    if (!cpu.flags.zf)
    {
        goto L_0x00467cee;
    }
    // 00467cc2  39af14030000           +cmp dword ptr [edi + 0x314], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(788) /* 0x314 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467cc8  7524                   -jne 0x467cee
    if (!cpu.flags.zf)
    {
        goto L_0x00467cee;
    }
    // 00467cca  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00467ccc  3ac3                   +cmp al, bl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467cce  7416                   -je 0x467ce6
    if (cpu.flags.zf)
    {
        goto L_0x00467ce6;
    }
L_0x00467cd0:
    // 00467cd0  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467cd2  7412                   -je 0x467ce6
    if (cpu.flags.zf)
    {
        goto L_0x00467ce6;
    }
    // 00467cd4  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00467cd7  41                     -inc ecx
    (cpu.ecx)++;
    // 00467cd8  3ac3                   +cmp al, bl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467cda  75f4                   -jne 0x467cd0
    if (!cpu.flags.zf)
    {
        goto L_0x00467cd0;
    }
    // 00467cdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467cdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467cde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467cdf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467ce0  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00467ce3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00467ce6:
    // 00467ce6  3819                   +cmp byte ptr [ecx], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467ce8  0f844b020000           -je 0x467f39
    if (cpu.flags.zf)
    {
        goto L_0x00467f39;
    }
L_0x00467cee:
    // 00467cee  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467cf2  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00467cf4  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00467cf6:
    // 00467cf6  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00467cf8  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 00467cfb  40                     -inc eax
    (cpu.eax)++;
    // 00467cfc  3acb                   +cmp cl, bl
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467cfe  75f6                   -jne 0x467cf6
    if (!cpu.flags.zf)
    {
        goto L_0x00467cf6;
    }
    // 00467d00  8a4c2418               -mov cl, byte ptr [esp + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467d04  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00467d06  3acb                   +cmp cl, bl
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d08  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467d0c  7413                   -je 0x467d21
    if (cpu.flags.zf)
    {
        goto L_0x00467d21;
    }
L_0x00467d0e:
    // 00467d0e  80f92e                 +cmp cl, 0x2e
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d11  740a                   -je 0x467d1d
    if (cpu.flags.zf)
    {
        goto L_0x00467d1d;
    }
    // 00467d13  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00467d16  40                     -inc eax
    (cpu.eax)++;
    // 00467d17  3acb                   +cmp cl, bl
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d19  75f3                   -jne 0x467d0e
    if (!cpu.flags.zf)
    {
        goto L_0x00467d0e;
    }
    // 00467d1b  eb04                   -jmp 0x467d21
    goto L_0x00467d21;
L_0x00467d1d:
    // 00467d1d  3818                   +cmp byte ptr [eax], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d1f  7514                   -jne 0x467d35
    if (!cpu.flags.zf)
    {
        goto L_0x00467d35;
    }
L_0x00467d21:
    // 00467d21  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
    // 00467d24  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00467d25  c60073                 -mov byte ptr [eax], 0x73
    app->getMemory<x86::reg8>(cpu.eax) = 115 /*0x73*/;
    // 00467d28  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00467d29  c60063                 -mov byte ptr [eax], 0x63
    app->getMemory<x86::reg8>(cpu.eax) = 99 /*0x63*/;
    // 00467d2c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00467d2d  c60072                 -mov byte ptr [eax], 0x72
    app->getMemory<x86::reg8>(cpu.eax) = 114 /*0x72*/;
    // 00467d30  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00467d33  eb06                   -jmp 0x467d3b
    goto L_0x00467d3b;
L_0x00467d35:
    // 00467d35  80780173               +cmp byte ptr [eax + 1], 0x73
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d39  7502                   -jne 0x467d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00467d3d;
    }
L_0x00467d3b:
    // 00467d3b  8bf5                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x00467d3d:
    // 00467d3d  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467d41  e8ba080000             -call 0x468600
    cpu.esp -= 4;
    sub_468600(app, cpu);
    // 00467d46  3bf5                   +cmp esi, ebp
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
    // 00467d48  751e                   -jne 0x467d68
    if (!cpu.flags.zf)
    {
        goto L_0x00467d68;
    }
    // 00467d4a  3bc3                   +cmp eax, ebx
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
L_0x00467d4c:
    // 00467d4c  7553                   -jne 0x467da1
    if (!cpu.flags.zf)
    {
        goto L_0x00467da1;
    }
    // 00467d4e  395c243c               +cmp dword ptr [esp + 0x3c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467d52  0f85e1010000           -jne 0x467f39
    if (!cpu.flags.zf)
    {
        goto L_0x00467f39;
    }
    // 00467d58  89af14030000           -mov dword ptr [edi + 0x314], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(788) /* 0x314 */) = cpu.ebp;
    // 00467d5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467d5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467d60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467d61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467d62  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00467d65  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00467d68:
    // 00467d68  3bc3                   +cmp eax, ebx
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
    // 00467d6a  7535                   -jne 0x467da1
    if (!cpu.flags.zf)
    {
        goto L_0x00467da1;
    }
    // 00467d6c  8a4c2418               -mov cl, byte ptr [esp + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467d70  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467d74  3acb                   +cmp cl, bl
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d76  740d                   -je 0x467d85
    if (cpu.flags.zf)
    {
        goto L_0x00467d85;
    }
L_0x00467d78:
    // 00467d78  80f92e                 +cmp cl, 0x2e
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d7b  7408                   -je 0x467d85
    if (cpu.flags.zf)
    {
        goto L_0x00467d85;
    }
    // 00467d7d  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00467d80  40                     -inc eax
    (cpu.eax)++;
    // 00467d81  3acb                   +cmp cl, bl
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467d83  75f3                   -jne 0x467d78
    if (!cpu.flags.zf)
    {
        goto L_0x00467d78;
    }
L_0x00467d85:
    // 00467d85  40                     -inc eax
    (cpu.eax)++;
    // 00467d86  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467d8a  c60073                 -mov byte ptr [eax], 0x73
    app->getMemory<x86::reg8>(cpu.eax) = 115 /*0x73*/;
    // 00467d8d  40                     -inc eax
    (cpu.eax)++;
    // 00467d8e  c60063                 -mov byte ptr [eax], 0x63
    app->getMemory<x86::reg8>(cpu.eax) = 99 /*0x63*/;
    // 00467d91  40                     -inc eax
    (cpu.eax)++;
    // 00467d92  c60072                 -mov byte ptr [eax], 0x72
    app->getMemory<x86::reg8>(cpu.eax) = 114 /*0x72*/;
    // 00467d95  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00467d98  e863080000             -call 0x468600
    cpu.esp -= 4;
    sub_468600(app, cpu);
    // 00467d9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467d9f  ebab                   -jmp 0x467d4c
    goto L_0x00467d4c;
L_0x00467da1:
    // 00467da1  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467da5  e8b6080000             -call 0x468660
    cpu.esp -= 4;
    sub_468660(app, cpu);
    // 00467daa  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467dac  3bfb                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467dae  751c                   -jne 0x467dcc
    if (!cpu.flags.zf)
    {
        goto L_0x00467dcc;
    }
    // 00467db0  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467db4  e877090000             -call 0x468730
    cpu.esp -= 4;
    sub_468730(app, cpu);
    // 00467db9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467dbb  3bfb                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467dbd  750d                   -jne 0x467dcc
    if (!cpu.flags.zf)
    {
        goto L_0x00467dcc;
    }
    // 00467dbf  68382c4a00             -push 0x4a2c38
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860984 /*0x4a2c38*/;
    cpu.esp -= 4;
    // 00467dc4  e847cefbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467dc9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00467dcc:
    // 00467dcc  8b358cbe5100           -mov esi, dword ptr [0x51be8c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357196) /* 0x51be8c */);
    // 00467dd2  3bf3                   +cmp esi, ebx
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
    // 00467dd4  7416                   -je 0x467dec
    if (cpu.flags.zf)
    {
        goto L_0x00467dec;
    }
L_0x00467dd6:
    // 00467dd6  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00467dd9  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00467ddb  3bc3                   +cmp eax, ebx
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
    // 00467ddd  7504                   -jne 0x467de3
    if (!cpu.flags.zf)
    {
        goto L_0x00467de3;
    }
    // 00467ddf  393e                   +cmp dword ptr [esi], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467de1  747d                   -je 0x467e60
    if (cpu.flags.zf)
    {
        goto L_0x00467e60;
    }
L_0x00467de3:
    // 00467de3  8b7618                 -mov esi, dword ptr [esi + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00467de6  3bf3                   +cmp esi, ebx
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
    // 00467de8  75ec                   -jne 0x467dd6
    if (!cpu.flags.zf)
    {
        goto L_0x00467dd6;
    }
    // 00467dea  eb04                   -jmp 0x467df0
    goto L_0x00467df0;
L_0x00467dec:
    // 00467dec  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
L_0x00467df0:
    // 00467df0  a190be5100             -mov eax, dword ptr [0x51be90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357200) /* 0x51be90 */);
    // 00467df5  3bc3                   +cmp eax, ebx
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
    // 00467df7  7f28                   -jg 0x467e21
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00467e21;
    }
    // 00467df9  68002a0000             -push 0x2a00
    app->getMemory<x86::reg32>(cpu.esp-4) = 10752 /*0x2a00*/;
    cpu.esp -= 4;
    // 00467dfe  e877f40000             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 00467e03  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467e06  3bc3                   +cmp eax, ebx
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
    // 00467e08  a394be5100             -mov dword ptr [0x51be94], eax
    app->getMemory<x86::reg32>(x86::reg32(5357204) /* 0x51be94 */) = cpu.eax;
    // 00467e0d  750d                   -jne 0x467e1c
    if (!cpu.flags.zf)
    {
        goto L_0x00467e1c;
    }
    // 00467e0f  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00467e14  e8f7cdfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467e19  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00467e1c:
    // 00467e1c  b880010000             -mov eax, 0x180
    cpu.eax = 384 /*0x180*/;
L_0x00467e21:
    // 00467e21  48                     -dec eax
    (cpu.eax)--;
    // 00467e22  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467e24  a390be5100             -mov dword ptr [0x51be90], eax
    app->getMemory<x86::reg32>(x86::reg32(5357200) /* 0x51be90 */) = cpu.eax;
    // 00467e29  a194be5100             -mov eax, dword ptr [0x51be94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357204) /* 0x51be94 */);
    // 00467e2e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00467e30  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00467e33  a394be5100             -mov dword ptr [0x51be94], eax
    app->getMemory<x86::reg32>(x86::reg32(5357204) /* 0x51be94 */) = cpu.eax;
    // 00467e38  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00467e3a  668b4f04               -mov cx, word ptr [edi + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467e3e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00467e41  e86a0c0000             -call 0x468ab0
    cpu.esp -= 4;
    sub_468ab0(app, cpu);
    // 00467e46  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00467e4a  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00467e4d  391d8cbe5100           +cmp dword ptr [0x51be8c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5357196) /* 0x51be8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467e53  7508                   -jne 0x467e5d
    if (!cpu.flags.zf)
    {
        goto L_0x00467e5d;
    }
    // 00467e55  89358cbe5100           -mov dword ptr [0x51be8c], esi
    app->getMemory<x86::reg32>(x86::reg32(5357196) /* 0x51be8c */) = cpu.esi;
    // 00467e5b  eb03                   -jmp 0x467e60
    goto L_0x00467e60;
L_0x00467e5d:
    // 00467e5d  897518                 -mov dword ptr [ebp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x00467e60:
    // 00467e60  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00467e64  895e14                 -mov dword ptr [esi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00467e67  3beb                   +cmp ebp, ebx
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
    // 00467e69  66895e08               -mov word ptr [esi + 8], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 00467e6d  885e06                 -mov byte ptr [esi + 6], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.bl;
    // 00467e70  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00467e73  7409                   -je 0x467e7e
    if (cpu.flags.zf)
    {
        goto L_0x00467e7e;
    }
    // 00467e75  89b518030000           -mov dword ptr [ebp + 0x318], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(792) /* 0x318 */) = cpu.esi;
    // 00467e7b  896e14                 -mov dword ptr [esi + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x00467e7e:
    // 00467e7e  391d60ba5100           +cmp dword ptr [0x51ba60], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467e84  0f85a0000000           -jne 0x467f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00467f2a;
    }
    // 00467e8a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00467e8c  b9447d4900             -mov ecx, 0x497d44
    cpu.ecx = 4816196 /*0x497d44*/;
    // 00467e91  e87aedffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00467e96  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467e98  3bfb                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467e9a  0f848a000000           -je 0x467f2a
    if (cpu.flags.zf)
    {
        goto L_0x00467f2a;
    }
    // 00467ea0  66837f2201             +cmp word ptr [edi + 0x22], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00467ea5  7568                   -jne 0x467f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00467f0f;
    }
    // 00467ea7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00467eab  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00467ead  3ac3                   +cmp al, bl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467eaf  7424                   -je 0x467ed5
    if (cpu.flags.zf)
    {
        goto L_0x00467ed5;
    }
L_0x00467eb1:
    // 00467eb1  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467eb3  7420                   -je 0x467ed5
    if (cpu.flags.zf)
    {
        goto L_0x00467ed5;
    }
    // 00467eb5  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00467eb8  41                     -inc ecx
    (cpu.ecx)++;
    // 00467eb9  3ac3                   +cmp al, bl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467ebb  75f4                   -jne 0x467eb1
    if (!cpu.flags.zf)
    {
        goto L_0x00467eb1;
    }
    // 00467ebd  c744243c000080bf       -mov dword ptr [esp + 0x3c], 0xbf800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 3212836864 /*0xbf800000*/;
    // 00467ec5  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00467ec7  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00467ecb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467ecd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467ece  e81dfaffff             -call 0x4678f0
    cpu.esp -= 4;
    sub_4678f0(app, cpu);
    // 00467ed3  eb43                   -jmp 0x467f18
    goto L_0x00467f18;
L_0x00467ed5:
    // 00467ed5  3819                   +cmp byte ptr [ecx], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467ed7  7518                   -jne 0x467ef1
    if (!cpu.flags.zf)
    {
        goto L_0x00467ef1;
    }
    // 00467ed9  c744243c000080bf       -mov dword ptr [esp + 0x3c], 0xbf800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 3212836864 /*0xbf800000*/;
    // 00467ee1  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00467ee3  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00467ee7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467ee9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467eea  e801faffff             -call 0x4678f0
    cpu.esp -= 4;
    sub_4678f0(app, cpu);
    // 00467eef  eb27                   -jmp 0x467f18
    goto L_0x00467f18;
L_0x00467ef1:
    // 00467ef1  41                     -inc ecx
    (cpu.ecx)++;
    // 00467ef2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467ef3  e8ac140100             -call 0x4793a4
    cpu.esp -= 4;
    sub_4793a4(app, cpu);
    // 00467ef8  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467efc  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00467f00  83c404                 +add esp, 4
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
    // 00467f03  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00467f05  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467f07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467f08  e8e3f9ffff             -call 0x4678f0
    cpu.esp -= 4;
    sub_4678f0(app, cpu);
    // 00467f0d  eb09                   -jmp 0x467f18
    goto L_0x00467f18;
L_0x00467f0f:
    // 00467f0f  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00467f11  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467f13  e808e8ffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
L_0x00467f18:
    // 00467f18  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00467f1a  6683790601             +cmp word ptr [ecx + 6], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00467f1f  7509                   -jne 0x467f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00467f2a;
    }
    // 00467f21  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467f23  e868020000             -call 0x468190
    cpu.esp -= 4;
    sub_468190(app, cpu);
    // 00467f28  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00467f2a:
    // 00467f2a  3beb                   +cmp ebp, ebx
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
    // 00467f2c  750b                   -jne 0x467f39
    if (!cpu.flags.zf)
    {
        goto L_0x00467f39;
    }
    // 00467f2e  3bf3                   +cmp esi, ebx
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
    // 00467f30  7407                   -je 0x467f39
    if (cpu.flags.zf)
    {
        goto L_0x00467f39;
    }
    // 00467f32  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467f34  e857020000             -call 0x468190
    cpu.esp -= 4;
    sub_468190(app, cpu);
L_0x00467f39:
    // 00467f39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f3d  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00467f40  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_467f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467f51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467f52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467f53  8b358cbe5100           -mov esi, dword ptr [0x51be8c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357196) /* 0x51be8c */);
    // 00467f59  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467f5a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00467f5c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467f5e  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00467f60  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00467f62  7425                   -je 0x467f89
    if (cpu.flags.zf)
    {
        goto L_0x00467f89;
    }
L_0x00467f64:
    // 00467f64  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00467f66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467f67  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00467f69  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467f6a  e841cc0100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00467f6f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00467f72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467f74  750c                   -jne 0x467f82
    if (!cpu.flags.zf)
    {
        goto L_0x00467f82;
    }
    // 00467f76  3bef                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467f78  7507                   -jne 0x467f81
    if (!cpu.flags.zf)
    {
        goto L_0x00467f81;
    }
    // 00467f7a  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00467f7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467f7f  750f                   -jne 0x467f90
    if (!cpu.flags.zf)
    {
        goto L_0x00467f90;
    }
L_0x00467f81:
    // 00467f81  47                     -inc edi
    (cpu.edi)++;
L_0x00467f82:
    // 00467f82  8b7618                 -mov esi, dword ptr [esi + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00467f85  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467f87  75db                   -jne 0x467f64
    if (!cpu.flags.zf)
    {
        goto L_0x00467f64;
    }
L_0x00467f89:
    // 00467f89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f8c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467f8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467f90:
    // 00467f90  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00467f92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467f96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_467fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467fa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467fa1  8b358cbe5100           -mov esi, dword ptr [0x51be8c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357196) /* 0x51be8c */);
    // 00467fa7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467fa8  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00467faa  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467fac  7419                   -je 0x467fc7
    if (cpu.flags.zf)
    {
        goto L_0x00467fc7;
    }
L_0x00467fae:
    // 00467fae  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00467fb0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467fb1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00467fb3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467fb4  e8f7cb0100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00467fb9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00467fbc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467fbe  740c                   -je 0x467fcc
    if (cpu.flags.zf)
    {
        goto L_0x00467fcc;
    }
    // 00467fc0  8b7618                 -mov esi, dword ptr [esi + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00467fc3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467fc5  75e7                   -jne 0x467fae
    if (!cpu.flags.zf)
    {
        goto L_0x00467fae;
    }
L_0x00467fc7:
    // 00467fc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467fc8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467fca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467fcb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467fcc:
    // 00467fcc  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00467fce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467fcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467fd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_467fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467fe0  8b158cbe5100           -mov edx, dword ptr [0x51be8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357196) /* 0x51be8c */);
    // 00467fe6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467fe8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467fe9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467fea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00467fec  741b                   -je 0x468009
    if (cpu.flags.zf)
    {
        goto L_0x00468009;
    }
L_0x00467fee:
    // 00467fee  3bd1                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467ff0  7507                   -jne 0x467ff9
    if (!cpu.flags.zf)
    {
        goto L_0x00467ff9;
    }
    // 00467ff2  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00467ff5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467ff7  7513                   -jne 0x46800c
    if (!cpu.flags.zf)
    {
        goto L_0x0046800c;
    }
L_0x00467ff9:
    // 00467ff9  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00467ffb  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00467ffd  3bf7                   +cmp esi, edi
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
    // 00467fff  7501                   -jne 0x468002
    if (!cpu.flags.zf)
    {
        goto L_0x00468002;
    }
    // 00468001  40                     -inc eax
    (cpu.eax)++;
L_0x00468002:
    // 00468002  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00468005  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00468007  75e5                   -jne 0x467fee
    if (!cpu.flags.zf)
    {
        goto L_0x00467fee;
    }
L_0x00468009:
    // 00468009  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0046800c:
    // 0046800c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046800d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046800e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468010  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468013  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468014  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468016  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046801a  e841e5ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046801f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468021  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468023  e838e5ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00468028  e863ed0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046802d  83f8ff                 +cmp eax, -1
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
    // 00468030  7505                   -jne 0x468037
    if (!cpu.flags.zf)
    {
        goto L_0x00468037;
    }
    // 00468032  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00468035  eb09                   -jmp 0x468040
    goto L_0x00468040;
L_0x00468037:
    // 00468037  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046803d  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x00468040:
    // 00468040  8b8018030000           -mov eax, dword ptr [eax + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 00468046  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468047  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468049  741f                   -je 0x46806a
    if (cpu.flags.zf)
    {
        goto L_0x0046806a;
    }
    // 0046804b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046804d  e88effffff             -call 0x467fe0
    cpu.esp -= 4;
    sub_467fe0(app, cpu);
    // 00468052  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00468056  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046805a  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0046805e  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00468063  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468066  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468069  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046806a:
    // 0046806a  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046806e  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00468074  c7048a000080bf         -mov dword ptr [edx + ecx*4], 0xbf800000
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = 3212836864 /*0xbf800000*/;
    // 0046807b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046807e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468080  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00468083  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00468087  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468088  e8d3e4ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046808d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046808f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468091  e8cae4ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00468096  e8f5ec0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046809b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046809d  e85ee6ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 004680a2  83fe0a                 +cmp esi, 0xa
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004680a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004680a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004680a7  7d0c                   -jge 0x4680b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004680b5;
    }
    // 004680a9  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004680ad  683c2a4a00             -push 0x4a2a3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860476 /*0x4a2a3c*/;
    cpu.esp -= 4;
    // 004680b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004680b3  eb0a                   -jmp 0x4680bf
    goto L_0x004680bf;
L_0x004680b5:
    // 004680b5  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004680b9  68342a4a00             -push 0x4a2a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860468 /*0x4a2a34*/;
    cpu.esp -= 4;
    // 004680be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x004680bf:
    // 004680bf  e834ed0000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004680c4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004680c7  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004680cb  e8c0a8fcff             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 004680d0  83f8ff                 +cmp eax, -1
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
    // 004680d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004680d4  7514                   -jne 0x4680ea
    if (!cpu.flags.zf)
    {
        goto L_0x004680ea;
    }
    // 004680d6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004680da  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004680df  c70490000080bf         -mov dword ptr [eax + edx*4], 0xbf800000
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = 3212836864 /*0xbf800000*/;
    // 004680e6  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004680e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004680ea:
    // 004680ea  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004680f0  c7442400ffffffff       -mov dword ptr [esp], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp) = 4294967295 /*0xffffffff*/;
    // 004680f8  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004680fb  8b8a18030000           -mov ecx, dword ptr [edx + 0x318]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(792) /* 0x318 */);
    // 00468101  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00468103  7409                   -je 0x46810e
    if (cpu.flags.zf)
    {
        goto L_0x0046810e;
    }
    // 00468105  e8d6feffff             -call 0x467fe0
    cpu.esp -= 4;
    sub_467fe0(app, cpu);
    // 0046810a  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0046810e:
    // 0046810e  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00468112  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00468116  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046811c  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046811f  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00468122  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468131  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468132  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00468136  e825e4ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046813b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046813d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046813f  e81ce4ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00468144  e847ec0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468149  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046814b  e8b0e5ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00468150  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00468152  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00468154  e8f7fdffff             -call 0x467f50
    cpu.esp -= 4;
    sub_467f50(app, cpu);
    // 00468159  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046815b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046815c  7513                   -jne 0x468171
    if (!cpu.flags.zf)
    {
        goto L_0x00468171;
    }
    // 0046815e  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00468162  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00468168  c7048100000000         -mov dword ptr [ecx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = 0 /*0x0*/;
    // 0046816f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468170  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468171:
    // 00468171  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00468175  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046817a  c704900000803f         -mov dword ptr [eax + edx*4], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = 1065353216 /*0x3f800000*/;
    // 00468181  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468182  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468190  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468191  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468193  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468195  7431                   -je 0x4681c8
    if (cpu.flags.zf)
    {
        goto L_0x004681c8;
    }
    // 00468197  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00468199  b9a4034900             -mov ecx, 0x4903a4
    cpu.ecx = 4785060 /*0x4903a4*/;
    // 0046819e  e86deaffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 004681a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004681a5  7409                   -je 0x4681b0
    if (cpu.flags.zf)
    {
        goto L_0x004681b0;
    }
    // 004681a7  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004681a9  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004681ab  e870e5ffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
L_0x004681b0:
    // 004681b0  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004681b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004681b5  740a                   -je 0x4681c1
    if (cpu.flags.zf)
    {
        goto L_0x004681c1;
    }
    // 004681b7  c7801803000000000000   -mov dword ptr [eax + 0x318], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */) = 0 /*0x0*/;
L_0x004681c1:
    // 004681c1  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004681c8:
    // 004681c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004681c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4681d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004681d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004681d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004681d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004681d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004681d4  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004681d8  8a5c2414               -mov bl, byte ptr [esp + 0x14]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004681dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004681dd  0fbe2e                 -movsx ebp, byte ptr [esi]
    cpu.ebp = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 004681e0  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004681e2  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004681e6  8a042f                 -mov al, byte ptr [edi + ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1);
    // 004681e9  8d0c2f                 -lea ecx, [edi + ebp]
    cpu.ecx = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 004681ec  3ac3                   +cmp al, bl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004681ee  7417                   -je 0x468207
    if (cpu.flags.zf)
    {
        goto L_0x00468207;
    }
L_0x004681f0:
    // 004681f0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004681f2  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004681f5  803c3a00               +cmp byte ptr [edx + edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004681f9  740c                   -je 0x468207
    if (cpu.flags.zf)
    {
        goto L_0x00468207;
    }
    // 004681fb  fec0                   -inc al
    (cpu.al)++;
    // 004681fd  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004681ff  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00468202  381c38                 +cmp byte ptr [eax + edi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00468205  75e9                   -jne 0x4681f0
    if (!cpu.flags.zf)
    {
        goto L_0x004681f0;
    }
L_0x00468207:
    // 00468207  0fbe16                 -movsx edx, byte ptr [esi]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0046820a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046820e  2bd5                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00468210  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468212  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468213  e8a8fb0000             -call 0x477dc0
    cpu.esp -= 4;
    sub_477dc0(app, cpu);
    // 00468218  0fbe0e                 -movsx ecx, byte ptr [esi]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0046821b  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046821f  2bcd                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00468221  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468224  c6041100               -mov byte ptr [ecx + edx], 0
    app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 00468228  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046822a  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0046822d  381c39                 +cmp byte ptr [ecx + edi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00468230  7504                   -jne 0x468236
    if (!cpu.flags.zf)
    {
        goto L_0x00468236;
    }
    // 00468232  fec0                   -inc al
    (cpu.al)++;
    // 00468234  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x00468236:
    // 00468236  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 00468239  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046823a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046823b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046823c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046823d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046823e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_468250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468250  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468251  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468253  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468254  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00468256  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00468259  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046825b  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046825d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046825f  49                     -dec ecx
    (cpu.ecx)--;
    // 00468260  83f97e                 +cmp ecx, 0x7e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(126 /*0x7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468263  760d                   -jbe 0x468272
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00468272;
    }
    // 00468265  685c2c4a00             -push 0x4a2c5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861020 /*0x4a2c5c*/;
    cpu.esp -= 4;
    // 0046826a  e8a1c9fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046826f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468272:
    // 00468272  ba80ee5100             -mov edx, 0x51ee80
    cpu.edx = 5369472 /*0x51ee80*/;
    // 00468277  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00468279  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046827b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046827c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046827d:
    // 0046827d  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046827f  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 00468282  40                     -inc eax
    (cpu.eax)++;
    // 00468283  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00468285  75f6                   -jne 0x46827d
    if (!cpu.flags.zf)
    {
        goto L_0x0046827d;
    }
    // 00468287  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468290  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468293  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 00468298  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468299  e8a247feff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0046829e  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004682a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004682a2  0f848c000000           -je 0x468334
    if (cpu.flags.zf)
    {
        goto L_0x00468334;
    }
    // 004682a8  a198c05100             -mov eax, dword ptr [0x51c098]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357720) /* 0x51c098 */);
    // 004682ad  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004682b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004682b7  7410                   -je 0x4682c9
    if (cpu.flags.zf)
    {
        goto L_0x004682c9;
    }
L_0x004682b9:
    // 004682b9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004682bd  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004682c0  42                     -inc edx
    (cpu.edx)++;
    // 004682c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004682c3  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004682c7  75f0                   -jne 0x4682b9
    if (!cpu.flags.zf)
    {
        goto L_0x004682b9;
    }
L_0x004682c9:
    // 004682c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004682ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004682cb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004682cd  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004682d1  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004682d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004682d4  e8c6f40000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 004682d9  8b3598c05100           -mov esi, dword ptr [0x51c098]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357720) /* 0x51c098 */);
    // 004682df  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004682e2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004682e4  7444                   -je 0x46832a
    if (cpu.flags.zf)
    {
        goto L_0x0046832a;
    }
    // 004682e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004682e7:
    // 004682e7  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004682e9  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004682ec  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004682ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004682ef  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 004682f1  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004682f3  49                     -dec ecx
    (cpu.ecx)--;
    // 004682f4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004682f6  fec1                   -inc cl
    (cpu.cl)++;
    // 004682f8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004682fa  884c241b               -mov byte ptr [esp + 0x1b], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(27) /* 0x1b */) = cpu.cl;
    // 004682fe  8d4c241b               -lea ecx, [esp + 0x1b]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(27) /* 0x1b */);
    // 00468302  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468303  e897f40000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00468308  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046830a  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046830d  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046830f  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00468311  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00468313  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468314  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468316  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00468318  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468319  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046831a  e880f40000             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0046831f  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00468322  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00468325  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468327  75be                   -jne 0x4682e7
    if (!cpu.flags.zf)
    {
        goto L_0x004682e7;
    }
    // 00468329  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046832a:
    // 0046832a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046832b  e8a7f20000             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00468330  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00468333  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00468334:
    // 00468334  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468335  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468338  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468340  a198c05100             -mov eax, dword ptr [0x51c098]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357720) /* 0x51c098 */);
    // 00468345  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00468348  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046834a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046834b  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046834d  740d                   -je 0x46835c
    if (cpu.flags.zf)
    {
        goto L_0x0046835c;
    }
    // 0046834f  68b82c4a00             -push 0x4a2cb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861112 /*0x4a2cb8*/;
    cpu.esp -= 4;
    // 00468354  e8b7c8fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468359  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046835c:
    // 0046835c  e8cfd3ffff             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00468361  dd5c240c               -fstp qword ptr [esp + 0xc]
    app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468365  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 0046836a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046836c  e8cf46feff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00468371  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468373  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468375  747f                   -je 0x4683f6
    if (cpu.flags.zf)
    {
        goto L_0x004683f6;
    }
    // 00468377  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468378  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046837a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046837e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00468380  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468381  e802f30000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00468386  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046838a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046838d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046838f  745c                   -je 0x4683ed
    if (cpu.flags.zf)
    {
        goto L_0x004683ed;
    }
L_0x00468391:
    // 00468391  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468392  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468394  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00468398  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046839a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046839b  e8e8f20000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004683a0  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004683a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004683a5  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004683ab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004683ad  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004683b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004683b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004683b3  e8d0f20000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004683b8  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004683bb  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004683bf  e83c020000             -call 0x468600
    cpu.esp -= 4;
    sub_468600(app, cpu);
    // 004683c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004683c6  741a                   -je 0x4683e2
    if (cpu.flags.zf)
    {
        goto L_0x004683e2;
    }
    // 004683c8  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004683cc  e85f030000             -call 0x468730
    cpu.esp -= 4;
    sub_468730(app, cpu);
    // 004683d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004683d3  750d                   -jne 0x4683e2
    if (!cpu.flags.zf)
    {
        goto L_0x004683e2;
    }
    // 004683d5  68942c4a00             -push 0x4a2c94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861076 /*0x4a2c94*/;
    cpu.esp -= 4;
    // 004683da  e831c8fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004683df  83c404                 +add esp, 4
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
L_0x004683e2:
    // 004683e2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004683e6  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004683e7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004683eb  75a4                   -jne 0x468391
    if (!cpu.flags.zf)
    {
        goto L_0x00468391;
    }
L_0x004683ed:
    // 004683ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004683ee  e8e4f10000             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 004683f3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004683f6:
    // 004683f6  e835d3ffff             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004683fb  dc64240c               -fsub qword ptr [esp + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004683ff  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468402  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468405  686c2c4a00             -push 0x4a2c6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861036 /*0x4a2c6c*/;
    cpu.esp -= 4;
    // 0046840a  e8a8e90000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046840f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468412  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468413  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00468416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468420  81ec98010000           -sub esp, 0x198
    (cpu.esp) -= x86::reg32(x86::sreg32(408 /*0x198*/));
    // 00468426  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 0046842b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046842d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046842e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046842f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468430  bf98be5100             -mov edi, 0x51be98
    cpu.edi = 5357208 /*0x51be98*/;
    // 00468435  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00468437  6880ee5100             -push 0x51ee80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5369472 /*0x51ee80*/;
    cpu.esp -= 4;
    // 0046843c  8d842428010000         -lea eax, [esp + 0x128]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00468443  68042d4a00             -push 0x4a2d04
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861188 /*0x4a2d04*/;
    cpu.esp -= 4;
    // 00468448  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468449  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046844b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046844d  e8a6e90000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00468452  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468456  8d942430010000         -lea edx, [esp + 0x130]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 0046845d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046845e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046845f  e881110100             -call 0x4795e5
    cpu.esp -= 4;
    sub_4795e5(app, cpu);
    // 00468464  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468466  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00468469  83feff                 +cmp esi, -1
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
    // 0046846c  0f8477010000           -je 0x4685e9
    if (cpu.flags.zf)
    {
        goto L_0x004685e9;
    }
L_0x00468472:
    // 00468472  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00468476  47                     -inc edi
    (cpu.edi)++;
    // 00468477  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468478  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468479  e834120100             -call 0x4796b2
    cpu.esp -= 4;
    sub_4796b2(app, cpu);
    // 0046847e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468481  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468483  74ed                   -je 0x468472
    if (cpu.flags.zf)
    {
        goto L_0x00468472;
    }
    // 00468485  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468486  e8ef120100             -call 0x47977a
    cpu.esp -= 4;
    sub_47977a(app, cpu);
    // 0046848b  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046848f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468490  68f82c4a00             -push 0x4a2cf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861176 /*0x4a2cf8*/;
    cpu.esp -= 4;
    // 00468495  e84b110100             -call 0x4795e5
    cpu.esp -= 4;
    sub_4795e5(app, cpu);
    // 0046849a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046849c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046849f  83feff                 +cmp esi, -1
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
    // 004684a2  741c                   -je 0x4684c0
    if (cpu.flags.zf)
    {
        goto L_0x004684c0;
    }
L_0x004684a4:
    // 004684a4  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004684a8  47                     -inc edi
    (cpu.edi)++;
    // 004684a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004684aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004684ab  e802120100             -call 0x4796b2
    cpu.esp -= 4;
    sub_4796b2(app, cpu);
    // 004684b0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004684b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004684b5  74ed                   -je 0x4684a4
    if (cpu.flags.zf)
    {
        goto L_0x004684a4;
    }
    // 004684b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004684b8  e8bd120100             -call 0x47977a
    cpu.esp -= 4;
    sub_47977a(app, cpu);
    // 004684bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004684c0:
    // 004684c0  8d04bf                 -lea eax, [edi + edi*4]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 4);
    // 004684c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004684c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004684c7  e8aeed0000             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 004684cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004684cf  3bc3                   +cmp eax, ebx
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
    // 004684d1  a39cc05100             -mov dword ptr [0x51c09c], eax
    app->getMemory<x86::reg32>(x86::reg32(5357724) /* 0x51c09c */) = cpu.eax;
    // 004684d6  7512                   -jne 0x4684ea
    if (!cpu.flags.zf)
    {
        goto L_0x004684ea;
    }
    // 004684d8  68d82c4a00             -push 0x4a2cd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861144 /*0x4a2cd8*/;
    cpu.esp -= 4;
    // 004684dd  e82ec7fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004684e2  a19cc05100             -mov eax, dword ptr [0x51c09c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357724) /* 0x51c09c */);
    // 004684e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004684ea:
    // 004684ea  6880ee5100             -push 0x51ee80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5369472 /*0x51ee80*/;
    cpu.esp -= 4;
    // 004684ef  8d8c2428010000         -lea ecx, [esp + 0x128]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004684f6  68042d4a00             -push 0x4a2d04
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861188 /*0x4a2d04*/;
    cpu.esp -= 4;
    // 004684fb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004684fc  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004684fe  e8f5e80000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00468503  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468507  8d842430010000         -lea eax, [esp + 0x130]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 0046850e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046850f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468510  e8d0100100             -call 0x4795e5
    cpu.esp -= 4;
    sub_4795e5(app, cpu);
    // 00468515  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00468517  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046851a  83ffff                 +cmp edi, -1
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
    // 0046851d  0f84c6000000           -je 0x4685e9
    if (cpu.flags.zf)
    {
        goto L_0x004685e9;
    }
L_0x00468523:
    // 00468523  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468527  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00468529  7435                   -je 0x468560
    if (cpu.flags.zf)
    {
        goto L_0x00468560;
    }
    // 0046852b  3c5c                   +cmp al, 0x5c
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046852d  7431                   -je 0x468560
    if (cpu.flags.zf)
    {
        goto L_0x00468560;
    }
    // 0046852f  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468533  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00468535  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468536  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468537  e884f80000             -call 0x477dc0
    cpu.esp -= 4;
    sub_477dc0(app, cpu);
    // 0046853c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046853f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00468541  885e0c                 -mov byte ptr [esi + 0xc], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00468544  e8c76effff             -call 0x45f410
    cpu.esp -= 4;
    sub_45f410(app, cpu);
    // 00468549  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0046854c  8b148598be5100         -mov edx, dword ptr [eax*4 + 0x51be98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357208) /* 0x51be98 */ + cpu.eax * 4);
    // 00468553  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00468556  89348598be5100         -mov dword ptr [eax*4 + 0x51be98], esi
    app->getMemory<x86::reg32>(x86::reg32(5357208) /* 0x51be98 */ + cpu.eax * 4) = cpu.esi;
    // 0046855d  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00468560:
    // 00468560  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00468564  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468565  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468566  e847110100             -call 0x4796b2
    cpu.esp -= 4;
    sub_4796b2(app, cpu);
    // 0046856b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046856e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468570  74b1                   -je 0x468523
    if (cpu.flags.zf)
    {
        goto L_0x00468523;
    }
    // 00468572  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468573  e802120100             -call 0x47977a
    cpu.esp -= 4;
    sub_47977a(app, cpu);
    // 00468578  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046857c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046857d  68f82c4a00             -push 0x4a2cf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861176 /*0x4a2cf8*/;
    cpu.esp -= 4;
    // 00468582  e85e100100             -call 0x4795e5
    cpu.esp -= 4;
    sub_4795e5(app, cpu);
    // 00468587  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00468589  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046858c  83ffff                 +cmp edi, -1
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
    // 0046858f  7458                   -je 0x4685e9
    if (cpu.flags.zf)
    {
        goto L_0x004685e9;
    }
L_0x00468591:
    // 00468591  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468595  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00468597  7435                   -je 0x4685ce
    if (cpu.flags.zf)
    {
        goto L_0x004685ce;
    }
    // 00468599  3c5c                   +cmp al, 0x5c
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046859b  7431                   -je 0x4685ce
    if (cpu.flags.zf)
    {
        goto L_0x004685ce;
    }
    // 0046859d  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004685a1  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 004685a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004685a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004685a5  e816f80000             -call 0x477dc0
    cpu.esp -= 4;
    sub_477dc0(app, cpu);
    // 004685aa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004685ad  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004685af  885e0c                 -mov byte ptr [esi + 0xc], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004685b2  e8596effff             -call 0x45f410
    cpu.esp -= 4;
    sub_45f410(app, cpu);
    // 004685b7  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004685ba  8b0c8598be5100         -mov ecx, dword ptr [eax*4 + 0x51be98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357208) /* 0x51be98 */ + cpu.eax * 4);
    // 004685c1  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004685c4  89348598be5100         -mov dword ptr [eax*4 + 0x51be98], esi
    app->getMemory<x86::reg32>(x86::reg32(5357208) /* 0x51be98 */ + cpu.eax * 4) = cpu.esi;
    // 004685cb  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x004685ce:
    // 004685ce  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004685d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004685d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004685d4  e8d9100100             -call 0x4796b2
    cpu.esp -= 4;
    sub_4796b2(app, cpu);
    // 004685d9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004685dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004685de  74b1                   -je 0x468591
    if (cpu.flags.zf)
    {
        goto L_0x00468591;
    }
    // 004685e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004685e1  e894110100             -call 0x47977a
    cpu.esp -= 4;
    sub_47977a(app, cpu);
    // 004685e6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004685e9:
    // 004685e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004685ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004685eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004685ec  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004685f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468600  a19cc05100             -mov eax, dword ptr [0x51c09c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357724) /* 0x51c09c */);
    // 00468605  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468606  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468607  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00468609  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046860b  750e                   -jne 0x46861b
    if (!cpu.flags.zf)
    {
        goto L_0x0046861b;
    }
    // 0046860d  e80efeffff             -call 0x468420
    cpu.esp -= 4;
    sub_468420(app, cpu);
    // 00468612  a19cc05100             -mov eax, dword ptr [0x51c09c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357724) /* 0x51c09c */);
    // 00468617  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468619  742a                   -je 0x468645
    if (cpu.flags.zf)
    {
        goto L_0x00468645;
    }
L_0x0046861b:
    // 0046861b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046861d  e8ee6dffff             -call 0x45f410
    cpu.esp -= 4;
    sub_45f410(app, cpu);
    // 00468622  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00468625  8b348598be5100         -mov esi, dword ptr [eax*4 + 0x51be98]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357208) /* 0x51be98 */ + cpu.eax * 4);
    // 0046862c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046862e  7415                   -je 0x468645
    if (cpu.flags.zf)
    {
        goto L_0x00468645;
    }
L_0x00468630:
    // 00468630  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468631  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468632  e879c50100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00468637  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046863a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046863c  740c                   -je 0x46864a
    if (cpu.flags.zf)
    {
        goto L_0x0046864a;
    }
    // 0046863e  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00468641  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468643  75eb                   -jne 0x468630
    if (!cpu.flags.zf)
    {
        goto L_0x00468630;
    }
L_0x00468645:
    // 00468645  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468646  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468648  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468649  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046864a:
    // 0046864a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046864b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00468650  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468651  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468660  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468661  8b3598c05100           -mov esi, dword ptr [0x51c098]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357720) /* 0x51c098 */);
    // 00468667  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468668  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046866a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046866c  7417                   -je 0x468685
    if (cpu.flags.zf)
    {
        goto L_0x00468685;
    }
L_0x0046866e:
    // 0046866e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00468670  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468671  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468672  e839c50100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00468677  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046867a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046867c  740c                   -je 0x46868a
    if (cpu.flags.zf)
    {
        goto L_0x0046868a;
    }
    // 0046867e  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00468681  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468683  75e9                   -jne 0x46866e
    if (!cpu.flags.zf)
    {
        goto L_0x0046866e;
    }
L_0x00468685:
    // 00468685  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468686  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468688  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468689  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046868a:
    // 0046868a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046868c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046868d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046868e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468691  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468693  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468695  7f04                   -jg 0x46869b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046869b;
    }
    // 00468697  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468699  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046869a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046869b:
    // 0046869b  81fe00800000           +cmp esi, 0x8000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004686a1  7f61                   -jg 0x468704
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00468704;
    }
    // 004686a3  a1a4c05100             -mov eax, dword ptr [0x51c0a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357732) /* 0x51c0a4 */);
    // 004686a8  3bf0                   +cmp esi, eax
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
    // 004686aa  7e30                   -jle 0x4686dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004686dc;
    }
    // 004686ac  81fe00080000           +cmp esi, 0x800
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004686b2  7f50                   -jg 0x468704
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00468704;
    }
    // 004686b4  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004686b9  e8bceb0000             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 004686be  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004686c1  a3a0c05100             -mov dword ptr [0x51c0a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5357728) /* 0x51c0a0 */) = cpu.eax;
    // 004686c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004686c8  750d                   -jne 0x4686d7
    if (!cpu.flags.zf)
    {
        goto L_0x004686d7;
    }
    // 004686ca  6850d34900             -push 0x49d350
    app->getMemory<x86::reg32>(cpu.esp-4) = 4838224 /*0x49d350*/;
    cpu.esp -= 4;
    // 004686cf  e83cc5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004686d4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004686d7:
    // 004686d7  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
L_0x004686dc:
    // 004686dc  2bc6                   +sub eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004686de  a3a4c05100             -mov dword ptr [0x51c0a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5357732) /* 0x51c0a4 */) = cpu.eax;
    // 004686e3  790d                   -jns 0x4686f2
    if (!cpu.flags.sf)
    {
        goto L_0x004686f2;
    }
    // 004686e5  6800d34900             -push 0x49d300
    app->getMemory<x86::reg32>(cpu.esp-4) = 4838144 /*0x49d300*/;
    cpu.esp -= 4;
    // 004686ea  e821c5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004686ef  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004686f2:
    // 004686f2  8b0da0c05100           -mov ecx, dword ptr [0x51c0a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357728) /* 0x51c0a0 */);
    // 004686f8  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004686fa  03ce                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004686fc  890da0c05100           -mov dword ptr [0x51c0a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357728) /* 0x51c0a0 */) = cpu.ecx;
    // 00468702  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468704:
    // 00468704  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468705  e870eb0000             -call 0x47727a
    cpu.esp -= 4;
    sub_47727a(app, cpu);
    // 0046870a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046870c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046870f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468711  750d                   -jne 0x468720
    if (!cpu.flags.zf)
    {
        goto L_0x00468720;
    }
    // 00468713  6850d34900             -push 0x49d350
    app->getMemory<x86::reg32>(cpu.esp-4) = 4838224 /*0x49d350*/;
    cpu.esp -= 4;
    // 00468718  e8f3c4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046871d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468720:
    // 00468720  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00468722  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468723  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468730  81ec1c010000           -sub esp, 0x11c
    (cpu.esp) -= x86::reg32(x86::sreg32(284 /*0x11c*/));
    // 00468736  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468737  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468738  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468739  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046873a  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046873c  bf80ee5100             -mov edi, 0x51ee80
    cpu.edi = 5369472 /*0x51ee80*/;
    // 00468741  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00468744  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00468746  f2ae                   +repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00468748  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046874a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046874b  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 0046874f  7514                   -jne 0x468765
    if (!cpu.flags.zf)
    {
        goto L_0x00468765;
    }
    // 00468751  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468755  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00468757  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00468759:
    // 00468759  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046875b  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0046875e  40                     -inc eax
    (cpu.eax)++;
    // 0046875f  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00468761  75f6                   -jne 0x468759
    if (!cpu.flags.zf)
    {
        goto L_0x00468759;
    }
    // 00468763  eb18                   -jmp 0x46877d
    goto L_0x0046877d;
L_0x00468765:
    // 00468765  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468766  6880ee5100             -push 0x51ee80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5369472 /*0x51ee80*/;
    cpu.esp -= 4;
    // 0046876b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046876f  68842d4a00             -push 0x4a2d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861316 /*0x4a2d84*/;
    cpu.esp -= 4;
    // 00468774  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468775  e87ee60000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046877a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0046877d:
    // 0046877d  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 00468782  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468786  e8b542feff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 0046878b  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046878d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046878f  7534                   -jne 0x4687c5
    if (!cpu.flags.zf)
    {
        goto L_0x004687c5;
    }
    // 00468791  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468792  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00468796  68782d4a00             -push 0x4a2d78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861304 /*0x4a2d78*/;
    cpu.esp -= 4;
    // 0046879b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046879c  e857e60000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004687a1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004687a4  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 004687a9  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004687ad  e88e42feff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 004687b2  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004687b4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004687b6  750d                   -jne 0x4687c5
    if (!cpu.flags.zf)
    {
        goto L_0x004687c5;
    }
    // 004687b8  68542d4a00             -push 0x4a2d54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861268 /*0x4a2d54*/;
    cpu.esp -= 4;
    // 004687bd  e84ec4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004687c2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004687c5:
    // 004687c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004687c6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004687c8  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004687cc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004687ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004687cf  e8b4ee0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004687d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004687d5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004687d7  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004687db  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004687dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004687de  e8a5ee0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004687e3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004687e6  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 004687eb  e8a0feffff             -call 0x468690
    cpu.esp -= 4;
    sub_468690(app, cpu);
    // 004687f0  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004687f2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004687f4  750d                   -jne 0x468803
    if (!cpu.flags.zf)
    {
        goto L_0x00468803;
    }
    // 004687f6  683c2d4a00             -push 0x4a2d3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861244 /*0x4a2d3c*/;
    cpu.esp -= 4;
    // 004687fb  e810c4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468800  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468803:
    // 00468803  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00468805  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00468808  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046880a  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046880c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046880e  e87dfeffff             -call 0x468690
    cpu.esp -= 4;
    sub_468690(app, cpu);
    // 00468813  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00468815  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00468817  3bc7                   +cmp eax, edi
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
    // 00468819  750d                   -jne 0x468828
    if (!cpu.flags.zf)
    {
        goto L_0x00468828;
    }
    // 0046881b  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00468820  e8ebc3fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468825  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468828:
    // 00468828  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046882a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0046882c:
    // 0046882c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046882e  41                     -inc ecx
    (cpu.ecx)++;
    // 0046882f  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00468831  42                     -inc edx
    (cpu.edx)++;
    // 00468832  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00468834  75f6                   -jne 0x46882c
    if (!cpu.flags.zf)
    {
        goto L_0x0046882c;
    }
    // 00468836  668b4c2424             -mov cx, word ptr [esp + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046883b  66894b04               -mov word ptr [ebx + 4], cx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.cx;
    // 0046883f  668b542420             -mov dx, word ptr [esp + 0x20]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468844  66895306               -mov word ptr [ebx + 6], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 00468848  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046884c  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0046884f  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 00468852  e839feffff             -call 0x468690
    cpu.esp -= 4;
    sub_468690(app, cpu);
    // 00468857  3bc7                   +cmp eax, edi
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
    // 00468859  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046885c  750d                   -jne 0x46886b
    if (!cpu.flags.zf)
    {
        goto L_0x0046886b;
    }
    // 0046885e  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00468863  e8a8c3fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468868  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046886b:
    // 0046886b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046886f  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00468873  3bc7                   +cmp eax, edi
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
    // 00468875  0f8e93000000           -jle 0x46890e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046890e;
    }
    // 0046887b  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
L_0x0046887f:
    // 0046887f  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00468882  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468883  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468885  03c7                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00468887  6a28                   -push 0x28
    app->getMemory<x86::reg32>(cpu.esp-4) = 40 /*0x28*/;
    cpu.esp -= 4;
    // 00468889  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046888a  e8f9ed0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046888f  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00468892  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00468894  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00468897  668b740f22             -mov si, word ptr [edi + ecx + 0x22]
    cpu.si = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */ + cpu.ecx * 1);
    // 0046889c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046889e  7452                   -je 0x4688f2
    if (cpu.flags.zf)
    {
        goto L_0x004688f2;
    }
    // 004688a0  8d0c36                 -lea ecx, [esi + esi]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004688a3  e8e8fdffff             -call 0x468690
    cpu.esp -= 4;
    sub_468690(app, cpu);
    // 004688a8  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004688ab  89441724               -mov dword ptr [edi + edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */ + cpu.edx * 1) = cpu.eax;
    // 004688af  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004688b2  8b4c0724               -mov ecx, dword ptr [edi + eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */ + cpu.eax * 1);
    // 004688b6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004688b8  750d                   -jne 0x4688c7
    if (!cpu.flags.zf)
    {
        goto L_0x004688c7;
    }
    // 004688ba  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 004688bf  e84cc3fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004688c4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004688c7:
    // 004688c7  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004688c9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004688cb  7e21                   -jle 0x4688ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004688ee;
    }
L_0x004688cd:
    // 004688cd  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004688d0  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004688d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004688d5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004688d7  8b440a24               -mov eax, dword ptr [edx + ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */ + cpu.ecx * 1);
    // 004688db  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004688dd  8d0c78                 -lea ecx, [eax + edi*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edi * 2);
    // 004688e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004688e1  e8a2ed0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004688e6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004688e9  47                     -inc edi
    (cpu.edi)++;
    // 004688ea  3bfe                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004688ec  7cdf                   -jl 0x4688cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004688cd;
    }
L_0x004688ee:
    // 004688ee  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x004688f2:
    // 004688f2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004688f6  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004688fa  40                     -inc eax
    (cpu.eax)++;
    // 004688fb  83c728                 -add edi, 0x28
    (cpu.edi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004688fe  3bc1                   +cmp eax, ecx
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
    // 00468900  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00468904  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00468908  0f8c71ffffff           -jl 0x46887f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046887f;
    }
L_0x0046890e:
    // 0046890e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046890f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468911  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468915  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00468917  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468918  e86bed0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046891d  668b442428             -mov ax, word ptr [esp + 0x28]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00468922  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00468925  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 00468929  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046892d  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 00468930  e85bfdffff             -call 0x468690
    cpu.esp -= 4;
    sub_468690(app, cpu);
    // 00468935  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468937  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046893a  750d                   -jne 0x468949
    if (!cpu.flags.zf)
    {
        goto L_0x00468949;
    }
    // 0046893c  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00468941  e8cac2fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468946  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468949:
    // 00468949  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046894d  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046894f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468951  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00468955  0f8ee2000000           -jle 0x468a3d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468a3d;
    }
L_0x0046895b:
    // 0046895b  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0046895e  8d3cf500000000         -lea edi, [esi*8]
    cpu.edi = x86::reg32(cpu.esi * 8);
    // 00468965  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468966  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468968  03d7                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046896a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046896c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046896d  e816ed0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00468972  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468973  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468975  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468979  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0046897b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046897c  e807ed0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00468981  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00468985  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00468988  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0046898b  0f849b000000           -je 0x468a2c
    if (cpu.flags.zf)
    {
        goto L_0x00468a2c;
    }
    // 00468991  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468992  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00468997  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468999  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046899d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046899e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046899f  e8e4ec0000             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004689a4  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004689a7  668b442424             -mov ax, word ptr [esp + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004689ac  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004689af  6689443a02             -mov word ptr [edx + edi + 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */ + cpu.edi * 1) = cpu.ax;
    // 004689b4  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004689b7  803c0f10               +cmp byte ptr [edi + ecx], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.ecx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004689bb  751a                   -jne 0x4689d7
    if (!cpu.flags.zf)
    {
        goto L_0x004689d7;
    }
    // 004689bd  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004689c1  e8fae1ffff             -call 0x466bc0
    cpu.esp -= 4;
    sub_466bc0(app, cpu);
    // 004689c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004689c8  0f8494000000           -je 0x468a62
    if (cpu.flags.zf)
    {
        goto L_0x00468a62;
    }
    // 004689ce  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004689d1  89443a04               -mov dword ptr [edx + edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.edi * 1) = cpu.eax;
    // 004689d5  eb55                   -jmp 0x468a2c
    goto L_0x00468a2c;
L_0x004689d7:
    // 004689d7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004689db  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004689e1  e8aafcffff             -call 0x468690
    cpu.esp -= 4;
    sub_468690(app, cpu);
    // 004689e6  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004689e9  89443904               -mov dword ptr [ecx + edi + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 1) = cpu.eax;
    // 004689ed  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004689f0  8b443a04               -mov eax, dword ptr [edx + edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 004689f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004689f6  750d                   -jne 0x468a05
    if (!cpu.flags.zf)
    {
        goto L_0x00468a05;
    }
    // 004689f8  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 004689fd  e80ec2fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468a02  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468a05:
    // 00468a05  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00468a09  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00468a0c  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00468a12  8d74242c               -lea esi, [esp + 0x2c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468a16  8b7c3804               -mov edi, dword ptr [eax + edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 00468a1a  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00468a1c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00468a1f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468a21  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00468a23  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00468a26  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
    }
    // 00468a28  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00468a2c:
    // 00468a2c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468a30  46                     -inc esi
    (cpu.esi)++;
    // 00468a31  3bf0                   +cmp esi, eax
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
    // 00468a33  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00468a37  0f8c1effffff           -jl 0x46895b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046895b;
    }
L_0x00468a3d:
    // 00468a3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468a3e  e894eb0000             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00468a43  8b0d98c05100           -mov ecx, dword ptr [0x51c098]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357720) /* 0x51c098 */);
    // 00468a49  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00468a4c  894b14                 -mov dword ptr [ebx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00468a4f  891d98c05100           -mov dword ptr [0x51c098], ebx
    app->getMemory<x86::reg32>(x86::reg32(5357720) /* 0x51c098 */) = cpu.ebx;
    // 00468a55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a57  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00468a59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a5b  81c41c010000           -add esp, 0x11c
    (cpu.esp) += x86::reg32(x86::sreg32(284 /*0x11c*/));
    // 00468a61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468a62:
    // 00468a62  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468a66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468a67  68202d4a00             -push 0x4a2d20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861216 /*0x4a2d20*/;
    cpu.esp -= 4;
    // 00468a6c  e846e30000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00468a71  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468a72  e83de90000             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00468a77  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00468a7b  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00468a7f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468a80  680c2d4a00             -push 0x4a2d0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861196 /*0x4a2d0c*/;
    cpu.esp -= 4;
    // 00468a85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468a86  e86de30000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00468a8b  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00468a8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468a90  e87bc1fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468a95  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00468a98  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468a9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a9e  81c41c010000           -add esp, 0x11c
    (cpu.esp) += x86::reg32(x86::sreg32(284 /*0x11c*/));
    // 00468aa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468ab0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468ab1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468ab2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468ab4  8b0da8c05100           -mov ecx, dword ptr [0x51c0a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357736) /* 0x51c0a8 */);
    // 00468aba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468abc  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00468abe  7e67                   -jle 0x468b27
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468b27;
    }
    // 00468ac0  a1b0c05100             -mov eax, dword ptr [0x51c0b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357744) /* 0x51c0b0 */);
    // 00468ac5  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00468acb  03ce                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00468acd  3bc8                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468acf  890da8c05100           -mov dword ptr [0x51c0a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357736) /* 0x51c0a8 */) = cpu.ecx;
    // 00468ad5  7e45                   -jle 0x468b1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468b1c;
    }
L_0x00468ad7:
    // 00468ad7  0500080000             -add eax, 0x800
    (cpu.eax) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 00468adc  a3b0c05100             -mov dword ptr [0x51c0b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5357744) /* 0x51c0b0 */) = cpu.eax;
    // 00468ae1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468ae4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468ae5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468ae6  e860e40000             -call 0x476f4b
    cpu.esp -= 4;
    sub_476f4b(app, cpu);
    // 00468aeb  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00468aed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468af0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00468af2  8915acc05100           -mov dword ptr [0x51c0ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */) = cpu.edx;
    // 00468af8  7513                   -jne 0x468b0d
    if (!cpu.flags.zf)
    {
        goto L_0x00468b0d;
    }
    // 00468afa  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00468aff  e80cc1fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468b04  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00468b0a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468b0d:
    // 00468b0d  a1b0c05100             -mov eax, dword ptr [0x51c0b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357744) /* 0x51c0b0 */);
    // 00468b12  8b0da8c05100           -mov ecx, dword ptr [0x51c0a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357736) /* 0x51c0a8 */);
    // 00468b18  3bc8                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468b1a  7fbb                   -jg 0x468ad7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00468ad7;
    }
L_0x00468b1c:
    // 00468b1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468b1d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00468b1f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468b21  8d3c9a                 -lea edi, [edx + ebx*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 4);
    // 00468b24  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00468b26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00468b27:
    // 00468b27  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00468b29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468b2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468b2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468b30  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 00468b35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468b36  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468b37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468b38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468b39  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00468b3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468b3d  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00468b3f  0f8ea0000000           -jle 0x468be5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468be5;
    }
    // 00468b45  8b1d4c845100           -mov ebx, dword ptr [0x51844c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
L_0x00468b4b:
    // 00468b4b  8b04bb                 -mov eax, dword ptr [ebx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.edi * 4);
    // 00468b4e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00468b54  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00468b5a  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00468b5d  8b81e8020000           -mov eax, dword ptr [ecx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 00468b63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468b65  740c                   -je 0x468b73
    if (cpu.flags.zf)
    {
        goto L_0x00468b73;
    }
L_0x00468b67:
    // 00468b67  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00468b69  8b81e8020000           -mov eax, dword ptr [ecx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 00468b6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468b71  75f4                   -jne 0x468b67
    if (!cpu.flags.zf)
    {
        goto L_0x00468b67;
    }
L_0x00468b73:
    // 00468b73  8bb1ec020000           -mov esi, dword ptr [ecx + 0x2ec]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(748) /* 0x2ec */);
    // 00468b79  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468b7b  7513                   -jne 0x468b90
    if (!cpu.flags.zf)
    {
        goto L_0x00468b90;
    }
    // 00468b7d  68942d4a00             -push 0x4a2d94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861332 /*0x4a2d94*/;
    cpu.esp -= 4;
    // 00468b82  e889c0fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468b87  8b1d4c845100           -mov ebx, dword ptr [0x51844c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00468b8d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00468b90:
    // 00468b90  8b8e80020000           -mov ecx, dword ptr [esi + 0x280]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(640) /* 0x280 */);
    // 00468b96  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468b98  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00468b9a  7e12                   -jle 0x468bae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468bae;
    }
    // 00468b9c  8d9680000000           -lea edx, [esi + 0x80]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(128) /* 0x80 */);
L_0x00468ba2:
    // 00468ba2  392a                   +cmp dword ptr [edx], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468ba4  7408                   -je 0x468bae
    if (cpu.flags.zf)
    {
        goto L_0x00468bae;
    }
    // 00468ba6  40                     -inc eax
    (cpu.eax)++;
    // 00468ba7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00468baa  3bc1                   +cmp eax, ecx
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
    // 00468bac  7cf4                   -jl 0x468ba2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468ba2;
    }
L_0x00468bae:
    // 00468bae  3bc1                   +cmp eax, ecx
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
    // 00468bb0  7c33                   -jl 0x468be5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468be5;
    }
    // 00468bb2  8b14bb                 -mov edx, dword ptr [ebx + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + cpu.edi * 4);
    // 00468bb5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468bb7  8b8a80020000           -mov ecx, dword ptr [edx + 0x280]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */);
    // 00468bbd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00468bbf  7e12                   -jle 0x468bd3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468bd3;
    }
    // 00468bc1  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
L_0x00468bc7:
    // 00468bc7  3b2a                   +cmp ebp, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468bc9  7408                   -je 0x468bd3
    if (cpu.flags.zf)
    {
        goto L_0x00468bd3;
    }
    // 00468bcb  40                     -inc eax
    (cpu.eax)++;
    // 00468bcc  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00468bcf  3bc1                   +cmp eax, ecx
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
    // 00468bd1  7cf4                   -jl 0x468bc7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468bc7;
    }
L_0x00468bd3:
    // 00468bd3  3bc1                   +cmp eax, ecx
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
    // 00468bd5  7c0e                   -jl 0x468be5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468be5;
    }
    // 00468bd7  a1c0f35100             -mov eax, dword ptr [0x51f3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 00468bdc  47                     -inc edi
    (cpu.edi)++;
    // 00468bdd  3bf8                   +cmp edi, eax
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
    // 00468bdf  0f8c66ffffff           -jl 0x468b4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468b4b;
    }
L_0x00468be5:
    // 00468be5  3b3dc0f35100           +cmp edi, dword ptr [0x51f3c0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468beb  7508                   -jne 0x468bf5
    if (!cpu.flags.zf)
    {
        goto L_0x00468bf5;
    }
    // 00468bed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bf0  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00468bf3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bf4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468bf5:
    // 00468bf5  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00468bf7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bfa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468bfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468c00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468c01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468c02  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468c04  e877daffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468c09  e882e10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468c0e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468c10  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00468c12  e869daffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468c17  e874e10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468c1c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468c1e  83feff                 +cmp esi, -1
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
    // 00468c21  7464                   -je 0x468c87
    if (cpu.flags.zf)
    {
        goto L_0x00468c87;
    }
    // 00468c23  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00468c25  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00468c27  e8948cfcff             -call 0x4318c0
    cpu.esp -= 4;
    sub_4318c0(app, cpu);
    // 00468c2c  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00468c31  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00468c34  8b81e8020000           -mov eax, dword ptr [ecx + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 00468c3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468c3c  7449                   -je 0x468c87
    if (cpu.flags.zf)
    {
        goto L_0x00468c87;
    }
    // 00468c3e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00468c40  7523                   -jne 0x468c65
    if (!cpu.flags.zf)
    {
        goto L_0x00468c65;
    }
    // 00468c42  b96f128339             -mov ecx, 0x3983126f
    cpu.ecx = 964891247 /*0x3983126f*/;
    // 00468c47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468c48  898864020000           -mov dword ptr [eax + 0x264], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(612) /* 0x264 */) = cpu.ecx;
    // 00468c4e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00468c54  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00468c57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468c58  8b90e8020000           -mov edx, dword ptr [eax + 0x2e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(744) /* 0x2e8 */);
    // 00468c5e  898a68020000           -mov dword ptr [edx + 0x268], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(616) /* 0x268 */) = cpu.ecx;
    // 00468c64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468c65:
    // 00468c65  c780640200000ad7233c   -mov dword ptr [eax + 0x264], 0x3c23d70a
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(612) /* 0x264 */) = 1008981770 /*0x3c23d70a*/;
    // 00468c6f  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00468c74  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00468c77  8b91e8020000           -mov edx, dword ptr [ecx + 0x2e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(744) /* 0x2e8 */);
    // 00468c7d  c78268020000cdcc4c3d   -mov dword ptr [edx + 0x268], 0x3d4ccccd
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(616) /* 0x268 */) = 1028443341 /*0x3d4ccccd*/;
L_0x00468c87:
    // 00468c87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468c88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468c89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468c90  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468c92  e8e9d9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468c97  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468c99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468ca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468ca1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468ca2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468ca3  e858daffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00468ca8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468caa  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468cac  e8cfd9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468cb1  e8dae00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468cb6  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00468cb8  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00468cba  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00468cbd  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00468cbf  f2ae                   +repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00468cc1  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00468cc3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00468cc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468cc5  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00468cc7  7509                   -jne 0x468cd2
    if (!cpu.flags.zf)
    {
        goto L_0x00468cd2;
    }
    // 00468cc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468cca  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00468ccc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468ccd  e99e41fcff             -jmp 0x42ce70
    return sub_42ce70(app, cpu);
L_0x00468cd2:
    // 00468cd2  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00468cd4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468cd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468cd6  e99541fcff             -jmp 0x42ce70
    return sub_42ce70(app, cpu);
}

/* align: skip  */
void Application::asm_sub_468ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468ce1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468ce2  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00468ce4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468ce5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468ce7  e894d9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468cec  e89fe00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468cf1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468cf3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00468cf5  e886d9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468cfa  e891e00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468cff  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468d01  83feff                 +cmp esi, -1
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
    // 00468d04  750c                   -jne 0x468d12
    if (!cpu.flags.zf)
    {
        goto L_0x00468d12;
    }
    // 00468d06  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00468d09  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00468d0b  e820feffff             -call 0x468b30
    cpu.esp -= 4;
    sub_468b30(app, cpu);
    // 00468d10  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00468d12:
    // 00468d12  83ffff                 +cmp edi, -1
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
    // 00468d15  7505                   -jne 0x468d1c
    if (!cpu.flags.zf)
    {
        goto L_0x00468d1c;
    }
    // 00468d17  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00468d1a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
L_0x00468d1c:
    // 00468d1c  3b35c0f35100           +cmp esi, dword ptr [0x51f3c0]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468d22  7d04                   -jge 0x468d28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00468d28;
    }
    // 00468d24  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468d26  7d0e                   -jge 0x468d36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00468d36;
    }
L_0x00468d28:
    // 00468d28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468d29  68b82d4a00             -push 0x4a2db8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861368 /*0x4a2db8*/;
    cpu.esp -= 4;
    // 00468d2e  e8ddbefbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468d33  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00468d36:
    // 00468d36  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00468d3c  8b04ba                 -mov eax, dword ptr [edx + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 4);
    // 00468d3f  8b88e8020000           -mov ecx, dword ptr [eax + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(744) /* 0x2e8 */);
    // 00468d45  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00468d47  750c                   -jne 0x468d55
    if (!cpu.flags.zf)
    {
        goto L_0x00468d55;
    }
    // 00468d49  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00468d4b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00468d4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d50  e99b8ffbff             -jmp 0x421cf0
    return sub_421cf0(app, cpu);
L_0x00468d55:
    // 00468d55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468d60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468d61  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00468d63  e818d9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468d68  e823e00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468d6d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468d6f  e88cd9ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00468d74  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00468d76  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00468d78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468d79  e942edfeff             -jmp 0x457ac0
    return sub_457ac0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_468d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468d80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468d81  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468d83  e8f8d8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468d88  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468d8c  e86fd9ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00468d91  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00468d95  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468d98  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468d9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468d9c  68c82d4a00             -push 0x4a2dc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861384 /*0x4a2dc8*/;
    cpu.esp -= 4;
    // 00468da1  e811e00000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00468da6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00468da9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468db0  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00468db3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468db5  e8c6d8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468dba  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468dbe  e83dd9ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00468dc3  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00468dc7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468dca  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468dcd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468dce  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00468dd2  68e02d4a00             -push 0x4a2de0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861408 /*0x4a2de0*/;
    cpu.esp -= 4;
    // 00468dd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468dd8  e81be00000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00468ddd  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468de1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468de2  e84943fbff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 00468de7  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 00468ded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468df0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468df1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468df3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468df5  e886d8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468dfa  e891df0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468dff  83f8ff                 +cmp eax, -1
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
    // 00468e02  750b                   -jne 0x468e0f
    if (!cpu.flags.zf)
    {
        goto L_0x00468e0f;
    }
    // 00468e04  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00468e07  8bb0ec020000           -mov esi, dword ptr [eax + 0x2ec]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 00468e0d  eb09                   -jmp 0x468e18
    goto L_0x00468e18;
L_0x00468e0f:
    // 00468e0f  8b0d54845100           -mov ecx, dword ptr [0x518454]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342292) /* 0x518454 */);
    // 00468e15  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x00468e18:
    // 00468e18  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468e1a  e861d8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468e1f  e86cdf0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468e24  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00468e2a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00468e2c  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00468e2e  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00468e31  e81adefeff             -call 0x456c50
    cpu.esp -= 4;
    sub_456c50(app, cpu);
    // 00468e36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468e37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468e40  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468e43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468e44  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468e46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468e47  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00468e4b  e830d8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468e50  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468e52  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468e54  e827d8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468e59  e832df0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468e5e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468e60  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00468e62  e819d8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00468e67  e824df0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00468e6c  83f8ff                 +cmp eax, -1
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
    // 00468e6f  750a                   -jne 0x468e7b
    if (!cpu.flags.zf)
    {
        goto L_0x00468e7b;
    }
    // 00468e71  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00468e74  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00468e76  e8b5fcffff             -call 0x468b30
    cpu.esp -= 4;
    sub_468b30(app, cpu);
L_0x00468e7b:
    // 00468e7b  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00468e7d  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00468e7f  e85c90fbff             -call 0x421ee0
    cpu.esp -= 4;
    sub_421ee0(app, cpu);
    // 00468e84  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00468e88  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00468e8e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00468e92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468e93  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00468e97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468e98  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00468e9b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468e9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468ea0  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00468ea3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468ea5  7413                   -je 0x468eba
    if (cpu.flags.zf)
    {
        goto L_0x00468eba;
    }
    // 00468ea7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00468ea9  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00468eaf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468eb0  bac0ab4000             -mov edx, 0x40abc0
    cpu.edx = 4238272 /*0x40abc0*/;
    // 00468eb5  e8667efeff             -call 0x450d20
    cpu.esp -= 4;
    sub_450d20(app, cpu);
L_0x00468eba:
    // 00468eba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468ec1  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00468ec3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468ec4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468ec5  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00468ec8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00468eca  e8c19dfcff             -call 0x432c90
    cpu.esp -= 4;
    sub_432c90(app, cpu);
    // 00468ecf  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468ed1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468ed3  0f84e4000000           -je 0x468fbd
    if (cpu.flags.zf)
    {
        goto L_0x00468fbd;
    }
    // 00468ed9  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00468edb  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00468ede  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00468ee0  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00468ee2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00468ee4  49                     -dec ecx
    (cpu.ecx)--;
    // 00468ee5  83f903                 +cmp ecx, 3
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
    // 00468ee8  0f82cf000000           -jb 0x468fbd
    if (cpu.flags.cf)
    {
        goto L_0x00468fbd;
    }
    // 00468eee  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00468ef0  683c2e4a00             -push 0x4a2e3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861500 /*0x4a2e3c*/;
    cpu.esp -= 4;
    // 00468ef5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468ef6  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00468ef8  e833100100             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00468efd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468f00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468f02  7505                   -jne 0x468f09
    if (!cpu.flags.zf)
    {
        goto L_0x00468f09;
    }
    // 00468f04  bf342e4a00             -mov edi, 0x4a2e34
    cpu.edi = 4861492 /*0x4a2e34*/;
L_0x00468f09:
    // 00468f09  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00468f0b  68302e4a00             -push 0x4a2e30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861488 /*0x4a2e30*/;
    cpu.esp -= 4;
    // 00468f10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468f11  e81a100100             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00468f16  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468f19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468f1b  7505                   -jne 0x468f22
    if (!cpu.flags.zf)
    {
        goto L_0x00468f22;
    }
    // 00468f1d  bf282e4a00             -mov edi, 0x4a2e28
    cpu.edi = 4861480 /*0x4a2e28*/;
L_0x00468f22:
    // 00468f22  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00468f24  68242e4a00             -push 0x4a2e24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861476 /*0x4a2e24*/;
    cpu.esp -= 4;
    // 00468f29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468f2a  e801100100             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00468f2f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468f32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468f34  7505                   -jne 0x468f3b
    if (!cpu.flags.zf)
    {
        goto L_0x00468f3b;
    }
    // 00468f36  bf182e4a00             -mov edi, 0x4a2e18
    cpu.edi = 4861464 /*0x4a2e18*/;
L_0x00468f3b:
    // 00468f3b  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00468f3d  68142e4a00             -push 0x4a2e14
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861460 /*0x4a2e14*/;
    cpu.esp -= 4;
    // 00468f42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468f43  e8e80f0100             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00468f48  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468f4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468f4d  7505                   -jne 0x468f54
    if (!cpu.flags.zf)
    {
        goto L_0x00468f54;
    }
    // 00468f4f  bf0c2e4a00             -mov edi, 0x4a2e0c
    cpu.edi = 4861452 /*0x4a2e0c*/;
L_0x00468f54:
    // 00468f54  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00468f56  68082e4a00             -push 0x4a2e08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861448 /*0x4a2e08*/;
    cpu.esp -= 4;
    // 00468f5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468f5c  e8cf0f0100             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00468f61  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468f64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468f66  7505                   -jne 0x468f6d
    if (!cpu.flags.zf)
    {
        goto L_0x00468f6d;
    }
    // 00468f68  bf002e4a00             -mov edi, 0x4a2e00
    cpu.edi = 4861440 /*0x4a2e00*/;
L_0x00468f6d:
    // 00468f6d  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00468f6f  68fc2d4a00             -push 0x4a2dfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861436 /*0x4a2dfc*/;
    cpu.esp -= 4;
    // 00468f74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468f75  e8b60f0100             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00468f7a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468f7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468f7f  7505                   -jne 0x468f86
    if (!cpu.flags.zf)
    {
        goto L_0x00468f86;
    }
    // 00468f81  bff42d4a00             -mov edi, 0x4a2df4
    cpu.edi = 4861428 /*0x4a2df4*/;
L_0x00468f86:
    // 00468f86  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00468f88  68f02d4a00             -push 0x4a2df0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861424 /*0x4a2df0*/;
    cpu.esp -= 4;
    // 00468f8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468f8e  e89d0f0100             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 00468f93  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468f96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468f98  7512                   -jne 0x468fac
    if (!cpu.flags.zf)
    {
        goto L_0x00468fac;
    }
    // 00468f9a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00468f9d  bfe82d4a00             -mov edi, 0x4a2de8
    cpu.edi = 4861416 /*0x4a2de8*/;
    // 00468fa2  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00468fa4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fa5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fa6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fa7  e92488fbff             -jmp 0x4217d0
    return sub_4217d0(app, cpu);
L_0x00468fac:
    // 00468fac  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00468fae  740d                   -je 0x468fbd
    if (cpu.flags.zf)
    {
        goto L_0x00468fbd;
    }
    // 00468fb0  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00468fb3  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00468fb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fb8  e91388fbff             -jmp 0x4217d0
    return sub_4217d0(app, cpu);
L_0x00468fbd:
    // 00468fbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468fc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_468fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468fd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468fd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468fd2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00468fd4  e827d7ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00468fd9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00468fdb  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00468fde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468fe0  750d                   -jne 0x468fef
    if (!cpu.flags.zf)
    {
        goto L_0x00468fef;
    }
    // 00468fe2  68402e4a00             -push 0x4a2e40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861504 /*0x4a2e40*/;
    cpu.esp -= 4;
    // 00468fe7  e824bcfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00468fec  83c404                 +add esp, 4
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
L_0x00468fef:
    // 00468fef  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00468ff2  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00468ff4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468ff5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468ff6  e9d587fbff             -jmp 0x4217d0
    return sub_4217d0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_469000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469000  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00469003  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469004  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469006  c74424040c2e4a00       -mov dword ptr [esp + 4], 0x4a2e0c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 4861452 /*0x4a2e0c*/;
    // 0046900e  c7442408182e4a00       -mov dword ptr [esp + 8], 0x4a2e18
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 4861464 /*0x4a2e18*/;
    // 00469016  c744240c282e4a00       -mov dword ptr [esp + 0xc], 0x4a2e28
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 4861480 /*0x4a2e28*/;
    // 0046901e  c7442410342e4a00       -mov dword ptr [esp + 0x10], 0x4a2e34
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 4861492 /*0x4a2e34*/;
    // 00469026  e8a546feff             -call 0x44d6d0
    cpu.esp -= 4;
    sub_44d6d0(app, cpu);
    // 0046902b  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046902c  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00469031  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00469033  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469036  7f42                   -jg 0x46907a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046907a;
    }
    // 00469038  e89346feff             -call 0x44d6d0
    cpu.esp -= 4;
    sub_44d6d0(app, cpu);
    // 0046903d  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046903e  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00469043  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00469045  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469048  7d19                   -jge 0x469063
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00469063;
    }
    // 0046904a  e88146feff             -call 0x44d6d0
    cpu.esp -= 4;
    sub_44d6d0(app, cpu);
    // 0046904f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00469052  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00469055  8b4c8404               -mov ecx, dword ptr [esp + eax*4 + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 00469059  e87287fbff             -call 0x4217d0
    cpu.esp -= 4;
    sub_4217d0(app, cpu);
    // 0046905e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046905f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00469062  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469063:
    // 00469063  e86846feff             -call 0x44d6d0
    cpu.esp -= 4;
    sub_44d6d0(app, cpu);
    // 00469068  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046906b  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0046906e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00469071  8b4c8404               -mov ecx, dword ptr [esp + eax*4 + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 00469075  e85687fbff             -call 0x4217d0
    cpu.esp -= 4;
    sub_4217d0(app, cpu);
L_0x0046907a:
    // 0046907a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046907b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046907e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469081  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469082  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469083  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469084  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00469086  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469088  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046908a  e8f1d5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046908f  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469093  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469095  e8e6d5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046909a  e8f1dc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046909f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004690a1  83feff                 +cmp esi, -1
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
    // 004690a4  7505                   -jne 0x4690ab
    if (!cpu.flags.zf)
    {
        goto L_0x004690ab;
    }
    // 004690a6  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004690a9  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x004690ab:
    // 004690ab  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004690af  e8dcdc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004690b4  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004690b7  66898124030000         -mov word ptr [ecx + 0x324], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(804) /* 0x324 */) = cpu.ax;
    // 004690be  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004690c4  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 004690c7  8b810c030000           -mov eax, dword ptr [ecx + 0x30c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(780) /* 0x30c */);
    // 004690cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004690cf  7419                   -je 0x4690ea
    if (cpu.flags.zf)
    {
        goto L_0x004690ea;
    }
    // 004690d1  833dc0f3510001         +cmp dword ptr [0x51f3c0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004690d8  7e03                   -jle 0x4690dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004690dd;
    }
    // 004690da  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
L_0x004690dd:
    // 004690dd  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004690e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004690e3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004690e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004690e6  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004690e8  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004690ea:
    // 004690ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004690eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004690ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004690ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004690ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4690f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004690f0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004690f3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004690f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004690f8  e883d5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004690fd  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004690ff  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469101  e87ad5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469106  e885dc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046910b  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046910d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046910f  e86cd5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469114  e877dc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469119  83fe05                 +cmp esi, 5
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046911c  0f87fa000000           -ja 0x46921c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046921c;
    }
    // 00469122  ff24b534924600         -jmp dword ptr [esi*4 + 0x469234]
    cpu.ip = app->getMemory<x86::reg32>(4624948 + cpu.esi * 4); goto dynamic_jump;
  case 0x00469129:
    // 00469129  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046912f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469130  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00469133  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469137  0fbf828a020000         -movsx eax, word ptr [edx + 0x28a]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(650) /* 0x28a */)));
    // 0046913e  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469144  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00469148  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046914c  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046914f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469152  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00469153:
    // 00469153  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00469159  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046915a  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046915d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469161  0fbf8298020000         -movsx eax, word ptr [edx + 0x298]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(664) /* 0x298 */)));
    // 00469168  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046916e  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00469172  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00469176  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469179  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046917c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046917d:
    // 0046917d  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 00469183  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469184  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00469187  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046918b  0fbf828c020000         -movsx eax, word ptr [edx + 0x28c]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(652) /* 0x28c */)));
    // 00469192  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469198  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046919c  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004691a0  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004691a3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004691a6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004691a7:
    // 004691a7  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004691ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004691ae  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004691b1  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004691b5  d98290020000           -fld dword ptr [edx + 0x290]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(656) /* 0x290 */)));
    // 004691bb  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004691c1  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004691c4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004691c7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004691c8:
    // 004691c8  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004691ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004691cf  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004691d2  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004691d6  0fbf8294020000         -movsx eax, word ptr [edx + 0x294]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(660) /* 0x294 */)));
    // 004691dd  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004691e3  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004691e7  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004691eb  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004691ee  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004691f1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004691f2:
    // 004691f2  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004691f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004691f9  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004691fc  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469200  0fbf8296020000         -movsx eax, word ptr [edx + 0x296]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(662) /* 0x296 */)));
    // 00469207  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046920d  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00469211  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00469215  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469218  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046921b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046921c:
    // 0046921c  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00469220  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469224  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046922a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046922b  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046922e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469231  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_469250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00469250  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469253  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469254  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469255  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469257  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469258  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046925a  e821d4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046925f  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469263  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469265  e816d4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046926a  e821db0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046926f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469271  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00469273  e808d4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469278  e813db0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046927d  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046927f  83ffff                 +cmp edi, -1
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
    // 00469282  7505                   -jne 0x469289
    if (!cpu.flags.zf)
    {
        goto L_0x00469289;
    }
    // 00469284  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00469287  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
L_0x00469289:
    // 00469289  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046928f  8b14b9                 -mov edx, dword ptr [ecx + edi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edi * 4);
    // 00469292  8b82ec020000           -mov eax, dword ptr [edx + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 00469298  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046929a  0f845f010000           -je 0x4693ff
    if (cpu.flags.zf)
    {
        goto L_0x004693ff;
    }
    // 004692a0  e8bbc9feff             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 004692a5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004692a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004692a9  7419                   -je 0x4692c4
    if (cpu.flags.zf)
    {
        goto L_0x004692c4;
    }
    // 004692ab  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004692ad:
    // 004692ad  84464a                 -test byte ptr [esi + 0x4a], al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(74) /* 0x4a */) & cpu.al));
    // 004692b0  7408                   -je 0x4692ba
    if (cpu.flags.zf)
    {
        goto L_0x004692ba;
    }
    // 004692b2  39be80000000           +cmp dword ptr [esi + 0x80], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004692b8  742b                   -je 0x4692e5
    if (cpu.flags.zf)
    {
        goto L_0x004692e5;
    }
L_0x004692ba:
    // 004692ba  8bb630030000           -mov esi, dword ptr [esi + 0x330]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(816) /* 0x330 */);
    // 004692c0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004692c2  75e9                   -jne 0x4692ad
    if (!cpu.flags.zf)
    {
        goto L_0x004692ad;
    }
L_0x004692c4:
    // 004692c4  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004692c9  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 004692cc  8b89b4020000           -mov ecx, dword ptr [ecx + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */);
    // 004692d2  e83965ffff             -call 0x45f810
    cpu.esp -= 4;
    sub_45f810(app, cpu);
    // 004692d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004692d8  68642e4a00             -push 0x4a2e64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861540 /*0x4a2e64*/;
    cpu.esp -= 4;
    // 004692dd  e82eb9fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004692e2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004692e5:
    // 004692e5  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004692e8  83f806                 +cmp eax, 6
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
    // 004692eb  0f870e010000           -ja 0x4693ff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004693ff;
    }
    // 004692f1  ff248508944600         -jmp dword ptr [eax*4 + 0x469408]
    cpu.ip = app->getMemory<x86::reg32>(4625416 + cpu.eax * 4); goto dynamic_jump;
  case 0x004692f8:
    // 004692f8  0fbf9698020000         -movsx edx, word ptr [esi + 0x298]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(664) /* 0x298 */)));
    // 004692ff  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00469303  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 00469307  d844240c               -fadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0046930b  e880da0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469310  66898698020000         -mov word ptr [esi + 0x298], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(664) /* 0x298 */) = cpu.ax;
    // 00469317  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469318  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469319  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046931a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046931d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046931e:
    // 0046931e  0fbf868c020000         -movsx eax, word ptr [esi + 0x28c]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(652) /* 0x28c */)));
    // 00469325  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00469329  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0046932d  d844240c               -fadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00469331  e85ada0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469336  668b8e8e020000         -mov cx, word ptr [esi + 0x28e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(654) /* 0x28e */);
    // 0046933d  6689868c020000         -mov word ptr [esi + 0x28c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(652) /* 0x28c */) = cpu.ax;
    // 00469344  663bc1                 +cmp ax, cx
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.cx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00469347  0f8eb2000000           -jle 0x4693ff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004693ff;
    }
    // 0046934d  66898e8c020000         -mov word ptr [esi + 0x28c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(652) /* 0x28c */) = cpu.cx;
    // 00469354  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469355  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469356  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469357  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046935a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046935b:
    // 0046935b  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046935f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469360  898e90020000           -mov dword ptr [esi + 0x290], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(656) /* 0x290 */) = cpu.ecx;
    // 00469366  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469367  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469368  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046936b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046936c:
    // 0046936c  0fbf9694020000         -movsx edx, word ptr [esi + 0x294]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(660) /* 0x294 */)));
    // 00469373  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00469377  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0046937b  d844240c               -fadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0046937f  e80cda0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469384  66898694020000         -mov word ptr [esi + 0x294], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(660) /* 0x294 */) = cpu.ax;
    // 0046938b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046938c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046938d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046938e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469391  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00469392:
    // 00469392  0fbf8696020000         -movsx eax, word ptr [esi + 0x296]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(662) /* 0x296 */)));
    // 00469399  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046939d  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004693a1  d844240c               -fadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004693a5  e8e6d90000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004693aa  66898696020000         -mov word ptr [esi + 0x296], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(662) /* 0x296 */) = cpu.ax;
    // 004693b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004693b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004693b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004693b4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004693b7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004693b8:
    // 004693b8  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004693bc  d8869c020000           -fadd dword ptr [esi + 0x29c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(668) /* 0x29c */));
    // 004693c2  d9969c020000           -fst dword ptr [esi + 0x29c]
    app->getMemory<float>(cpu.esi + x86::reg32(668) /* 0x29c */) = float(cpu.fpu.st(0));
    // 004693c8  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 004693ce  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004693d0  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004693d5  7528                   -jne 0x4693ff
    if (!cpu.flags.zf)
    {
        goto L_0x004693ff;
    }
    // 004693d7  c7869c0200000000803f   -mov dword ptr [esi + 0x29c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(668) /* 0x29c */) = 1065353216 /*0x3f800000*/;
    // 004693e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004693e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004693e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004693e4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004693e7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004693e8:
    // 004693e8  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004693ec  e89fd90000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004693f1  6689868e020000         -mov word ptr [esi + 0x28e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(654) /* 0x28e */) = cpu.ax;
    // 004693f8  6689868c020000         -mov word ptr [esi + 0x28c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(652) /* 0x28c */) = cpu.ax;
L_0x004693ff:
    // 004693ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469400  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469401  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469402  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469405  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_469430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469430  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469433  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469434  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469435  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469436  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00469438  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046943c  e83fd2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469441  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469443  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469445  e836d2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046944a  e841d90000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046944f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469451  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00469453  e828d2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469458  e833d90000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046945d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046945f  83feff                 +cmp esi, -1
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
    // 00469462  7505                   -jne 0x469469
    if (!cpu.flags.zf)
    {
        goto L_0x00469469;
    }
    // 00469464  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469467  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x00469469:
    // 00469469  e8f2c7feff             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 0046946e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00469470  7419                   -je 0x46948b
    if (cpu.flags.zf)
    {
        goto L_0x0046948b;
    }
    // 00469472  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00469474:
    // 00469474  84484a                 -test byte ptr [eax + 0x4a], cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(74) /* 0x4a */) & cpu.cl));
    // 00469477  7408                   -je 0x469481
    if (cpu.flags.zf)
    {
        goto L_0x00469481;
    }
    // 00469479  39b080000000           +cmp dword ptr [eax + 0x80], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046947f  7422                   -je 0x4694a3
    if (cpu.flags.zf)
    {
        goto L_0x004694a3;
    }
L_0x00469481:
    // 00469481  8b8030030000           -mov eax, dword ptr [eax + 0x330]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(816) /* 0x330 */);
    // 00469487  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00469489  75e9                   -jne 0x469474
    if (!cpu.flags.zf)
    {
        goto L_0x00469474;
    }
L_0x0046948b:
    // 0046948b  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046948f  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469497  c7048a00000000         -mov dword ptr [edx + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = 0 /*0x0*/;
    // 0046949e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046949f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004694a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004694a3:
    // 004694a3  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004694a5  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004694a8  741f                   -je 0x4694c9
    if (cpu.flags.zf)
    {
        goto L_0x004694c9;
    }
    // 004694aa  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004694ad  754c                   -jne 0x4694fb
    if (!cpu.flags.zf)
    {
        goto L_0x004694fb;
    }
    // 004694af  d9809c020000           -fld dword ptr [eax + 0x29c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(668) /* 0x29c */)));
    // 004694b5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004694b9  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004694bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004694c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004694c1  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004694c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004694c5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004694c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004694c9:
    // 004694c9  0fbf888c020000         -movsx ecx, word ptr [eax + 0x28c]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(652) /* 0x28c */)));
    // 004694d0  0fbf908e020000         -movsx edx, word ptr [eax + 0x28e]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(654) /* 0x28e */)));
    // 004694d7  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004694db  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004694df  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004694e3  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004694e7  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004694ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004694ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004694ef  da742408               -fidiv dword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004694f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004694f4  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004694f7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004694fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004694fb:
    // 004694fb  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004694ff  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00469503  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469509  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046950a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046950b  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046950e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046950f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469512  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469520  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469523  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469524  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469526  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046952a  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00469532  e849d1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469537  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046953a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046953c  8b80ec020000           -mov eax, dword ptr [eax + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 00469542  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469543  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00469545  7436                   -je 0x46957d
    if (cpu.flags.zf)
    {
        goto L_0x0046957d;
    }
    // 00469547  6683b88a02000000       +cmp word ptr [eax + 0x28a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(650) /* 0x28a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046954f  7f17                   -jg 0x469568
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00469568;
    }
    // 00469551  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00469557  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046955b  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469561  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469564  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469567  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469568:
    // 00469568  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046956c  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00469570  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469576  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469579  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046957c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046957d:
    // 0046957d  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00469581  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00469585  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046958a  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046958d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469590  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4695a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004695a0  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004695a5  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004695a8  e99354ffff             -jmp 0x45ea40
    return sub_45ea40(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4695b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004695b0  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004695b3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004695b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004695b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004695b9  e8c2d0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004695be  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004695c0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004695c2  e8b9d0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004695c7  e8c4d70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004695cc  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004695ce  e82dd1ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 004695d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004695d5  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004695d7  7c16                   -jl 0x4695ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004695ef;
    }
    // 004695d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004695da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004695db  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004695df  68342a4a00             -push 0x4a2a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860468 /*0x4a2a34*/;
    cpu.esp -= 4;
    // 004695e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004695e5  e80ed80000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004695ea  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004695ed  eb13                   -jmp 0x469602
    goto L_0x00469602;
L_0x004695ef:
    // 004695ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004695f0  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004695f4  68c40e4900             -push 0x490ec4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4787908 /*0x490ec4*/;
    cpu.esp -= 4;
    // 004695f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004695fa  e8f9d70000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004695ff  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00469602:
    // 00469602  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469606  e88593fcff             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0046960b  83f8ff                 +cmp eax, -1
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
    // 0046960e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00469612  7562                   -jne 0x469676
    if (!cpu.flags.zf)
    {
        goto L_0x00469676;
    }
    // 00469614  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469615  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469616  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046961a  683c2a4a00             -push 0x4a2a3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860476 /*0x4a2a3c*/;
    cpu.esp -= 4;
    // 0046961f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00469620  e8d3d70000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00469625  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00469628  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046962c  e85f93fcff             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 00469631  83f8ff                 +cmp eax, -1
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
    // 00469634  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00469638  7526                   -jne 0x469660
    if (!cpu.flags.zf)
    {
        goto L_0x00469660;
    }
    // 0046963a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046963b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046963c  687c2e4a00             -push 0x4a2e7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861564 /*0x4a2e7c*/;
    cpu.esp -= 4;
    // 00469641  e8cab5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00469646  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0046964a  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046964e  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469654  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00469657  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046965a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046965b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046965c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046965f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469660:
    // 00469660  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 00469664  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00469668  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046966d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046966e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046966f  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469672  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00469675  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469676:
    // 00469676  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0046967a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046967e  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469684  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469685  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469686  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469689  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046968c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469690  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469693  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469694  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469696  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046969a  e8e1cfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046969f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004696a1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004696a3  e8d8cfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004696a8  e8e3d60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004696ad  83f8ff                 +cmp eax, -1
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
    // 004696b0  7505                   -jne 0x4696b7
    if (!cpu.flags.zf)
    {
        goto L_0x004696b7;
    }
    // 004696b2  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004696b5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004696b7:
    // 004696b7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004696b9  e8d295fcff             -call 0x432c90
    cpu.esp -= 4;
    sub_432c90(app, cpu);
    // 004696be  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004696c0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004696c2  750d                   -jne 0x4696d1
    if (!cpu.flags.zf)
    {
        goto L_0x004696d1;
    }
    // 004696c4  68bc2e4a00             -push 0x4a2ebc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861628 /*0x4a2ebc*/;
    cpu.esp -= 4;
    // 004696c9  e842b5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004696ce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004696d1:
    // 004696d1  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004696d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004696d6  6844384900             -push 0x493844
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798532 /*0x493844*/;
    cpu.esp -= 4;
    // 004696db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004696dc  e873df0000             -call 0x477654
    cpu.esp -= 4;
    sub_477654(app, cpu);
    // 004696e1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004696e4  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004696e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004696e8  7421                   -je 0x46970b
    if (cpu.flags.zf)
    {
        goto L_0x0046970b;
    }
    // 004696ea  68942e4a00             -push 0x4a2e94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861588 /*0x4a2e94*/;
    cpu.esp -= 4;
    // 004696ef  e81cb5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004696f4  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004696f8  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004696fc  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469701  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00469704  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469707  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046970a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046970b:
    // 0046970b  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0046970f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469713  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469719  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046971c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046971f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469720  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469723  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469724  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469725  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469726  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469728  e853cfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046972d  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469731  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469733  e848cfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469738  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046973c  e8bfcfffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00469741  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00469743  e8b8cfffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00469748  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046974a  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046974c  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046974f  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00469751  f2ae                   +repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00469753  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00469755  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00469756  751a                   -jne 0x469772
    if (!cpu.flags.zf)
    {
        goto L_0x00469772;
    }
    // 00469758  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046975c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469760  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469761  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469762  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00469764  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00469766  e85590feff             -call 0x4527c0
    cpu.esp -= 4;
    sub_4527c0(app, cpu);
    // 0046976b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046976c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046976d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046976e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469771  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469772:
    // 00469772  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00469776  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046977a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046977b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046977c  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046977e  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00469780  e83b90feff             -call 0x4527c0
    cpu.esp -= 4;
    sub_4527c0(app, cpu);
    // 00469785  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469786  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469787  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469788  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046978b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469790  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469791  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469792  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469793  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469795  e8e6ceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046979a  e8f1d50000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046979f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004697a1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004697a3  e8d8ceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004697a8  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004697ac  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004697ae  e8cdceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004697b3  e8d8d50000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004697b8  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004697ba  e841cfffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 004697bf  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004697c3  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004697c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004697c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004697c7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004697c9  e8524efdff             -call 0x43e620
    cpu.esp -= 4;
    sub_43e620(app, cpu);
    // 004697ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004697cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004697d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004697d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4697e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004697e0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004697e3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004697e5  e896ceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004697ea  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004697ee  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004697f0  e88bceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004697f5  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004697f9  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004697fd  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469801  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469802  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469803  e8b883feff             -call 0x451bc0
    cpu.esp -= 4;
    sub_451bc0(app, cpu);
    // 00469808  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046980b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469810  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469813  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469817  e864ceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046981c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046981e  e8ddceffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00469823  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00469825  e8565fffff             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0046982a  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469830  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00469834  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00469838  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046983c  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046983f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469850  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469851  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00469855  e826ceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046985a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046985c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046985e  e81dceffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469863  e828d50000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469868  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046986e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00469871  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00469875  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046987b  db82b4020000           -fild dword ptr [edx + 0x2b4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(692) /* 0x2b4 */))));
    // 00469881  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469884  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469885  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469890  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469893  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469894  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469896  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046989a  e8e1cdffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046989f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004698a1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004698a3  e8d8cdffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004698a8  e8e3d40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004698ad  83f8ff                 +cmp eax, -1
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
    // 004698b0  7505                   -jne 0x4698b7
    if (!cpu.flags.zf)
    {
        goto L_0x004698b7;
    }
    // 004698b2  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004698b5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004698b7:
    // 004698b7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004698b9  e872f2ffff             -call 0x468b30
    cpu.esp -= 4;
    sub_468b30(app, cpu);
    // 004698be  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004698c2  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004698c8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004698cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004698cd  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004698d1  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004698d4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004698d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4698e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004698e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004698e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004698e2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004698e4  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004698e8  e893cdffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 004698ed  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004698f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004698f2  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004698f4  740a                   -je 0x469900
    if (cpu.flags.zf)
    {
        goto L_0x00469900;
    }
    // 004698f6  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 004698fc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004698fe  750d                   -jne 0x46990d
    if (!cpu.flags.zf)
    {
        goto L_0x0046990d;
    }
L_0x00469900:
    // 00469900  68d82e4a00             -push 0x4a2ed8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861656 /*0x4a2ed8*/;
    cpu.esp -= 4;
    // 00469905  e806b3fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046990a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046990d:
    // 0046990d  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00469910  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469914  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469915  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 0046991b  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469920  db8180000000           -fild dword ptr [ecx + 0x80]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */))));
    // 00469926  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469929  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046992a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469931  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00469935  e846cdffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046993a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046993c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046993e  e83dcdffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469943  e848d40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469948  8b0d4c845100           -mov ecx, dword ptr [0x51844c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 0046994e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00469951  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00469955  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046995b  db8280000000           -fild dword ptr [edx + 0x80]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */))));
    // 00469961  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469964  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469965  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469970  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469975  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00469977  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046997b  e800cdffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469980  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469982  e879cdffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00469987  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00469989  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046998b  e8804affff             -call 0x45e410
    cpu.esp -= 4;
    sub_45e410(app, cpu);
    // 00469990  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469996  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00469998  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046999b  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0046999f  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 004699a2  8b80d0000000           -mov eax, dword ptr [eax + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */);
    // 004699a8  8982d0000000           -mov dword ptr [edx + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 004699ae  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004699b4  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004699b7  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 004699ba  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 004699c0  8988d4000000           -mov dword ptr [eax + 0xd4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */) = cpu.ecx;
    // 004699c6  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004699cb  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004699ce  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004699d1  8b92d8000000           -mov edx, dword ptr [edx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 004699d7  8991d8000000           -mov dword ptr [ecx + 0xd8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */) = cpu.edx;
    // 004699dd  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004699e3  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004699e6  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 004699e9  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004699ec  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004699ef  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004699f5  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004699f8  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 004699fb  8b4928                 -mov ecx, dword ptr [ecx + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004699fe  894828                 -mov dword ptr [eax + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00469a01  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a06  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469a09  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469a0c  8b522c                 -mov edx, dword ptr [edx + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00469a0f  89512c                 -mov dword ptr [ecx + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00469a12  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a18  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469a1b  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469a1e  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00469a21  89424c                 -mov dword ptr [edx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00469a24  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a2a  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469a2d  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00469a30  8b4950                 -mov ecx, dword ptr [ecx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 00469a33  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 00469a36  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a3b  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469a3e  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469a41  8b5254                 -mov edx, dword ptr [edx + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 00469a44  895154                 -mov dword ptr [ecx + 0x54], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00469a47  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a4d  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469a50  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469a53  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00469a56  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 00469a59  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a5f  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469a62  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00469a65  8b4978                 -mov ecx, dword ptr [ecx + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 00469a68  894878                 -mov dword ptr [eax + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 00469a6b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a70  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469a73  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469a76  8b527c                 -mov edx, dword ptr [edx + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 00469a79  89517c                 -mov dword ptr [ecx + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 00469a7c  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a81  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469a84  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00469a8a  83e1fb                 -and ecx, 0xfffffffb
    cpu.ecx &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
    // 00469a8d  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 00469a93  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469a99  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469a9c  e87f0afeff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00469aa1  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469aa7  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00469aaa  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00469ab0  83e2f7                 -and edx, 0xfffffff7
    cpu.edx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 00469ab3  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 00469ab9  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469abe  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469ac1  e85a0afeff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 00469ac6  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469acc  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469acf  e81c5bfeff             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    // 00469ad4  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469ad7  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00469add  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00469adf  baa0954600             -mov edx, 0x4695a0
    cpu.edx = 4625824 /*0x4695a0*/;
    // 00469ae4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469ae5  e83672feff             -call 0x450d20
    cpu.esp -= 4;
    sub_450d20(app, cpu);
    // 00469aea  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469af0  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 00469af4  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00469af8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469af9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469afa  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469afd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469b00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469b10  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469b13  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469b17  e864cbffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469b1c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469b1e  e8ad3bfeff             -call 0x44d6d0
    cpu.esp -= 4;
    sub_44d6d0(app, cpu);
    // 00469b23  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00469b24  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 00469b29  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00469b2b  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469b30  89542400               -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00469b34  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469b38  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00469b3c  d91c90                 -fstp dword ptr [eax + edx*4]
    app->getMemory<float>(cpu.eax + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469b3f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469b42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469b50  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00469b53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469b54  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469b56  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469b58  e823cbffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469b5d  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469b61  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469b63  e818cbffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469b68  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469b6c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469b6e  e80dcbffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469b73  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469b77  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469b79  e802cbffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469b7e  e80dd20000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469b83  83f8ff                 +cmp eax, -1
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
    // 00469b86  7505                   -jne 0x469b8d
    if (!cpu.flags.zf)
    {
        goto L_0x00469b8d;
    }
    // 00469b88  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00469b8b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00469b8d:
    // 00469b8d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469b93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469b94  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00469b97  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00469b9b  898a6c020000           -mov dword ptr [edx + 0x26c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(620) /* 0x26c */) = cpu.ecx;
    // 00469ba1  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469ba7  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00469baa  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469bae  899168020000           -mov dword ptr [ecx + 0x268], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(616) /* 0x268 */) = cpu.edx;
    // 00469bb4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469bba  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00469bbd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469bc1  898264020000           -mov dword ptr [edx + 0x264], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */) = cpu.eax;
    // 00469bc7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00469bca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00469bd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469bd1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469bd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00469bd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469bd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469bd5  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00469bd7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469bd9  e8a2caffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469bde  e8add10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469be3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469be5  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00469be7  e894caffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469bec  e89fd10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469bf1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469bf3  8ad8                   -mov bl, al
    cpu.bl = cpu.al;
    // 00469bf5  e886caffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469bfa  e891d10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469bff  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469c01  88442411               -mov byte ptr [esp + 0x11], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */) = cpu.al;
    // 00469c05  e876caffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469c0a  e881d10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469c0f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469c11  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00469c15  e866caffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469c1a  e871d10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469c1f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00469c21  83feff                 +cmp esi, -1
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
    // 00469c24  7505                   -jne 0x469c2b
    if (!cpu.flags.zf)
    {
        goto L_0x00469c2b;
    }
    // 00469c26  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00469c29  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x00469c2b:
    // 00469c2b  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469c2e  0f878f010000           -ja 0x469dc3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469dc3;
    }
    // 00469c34  ff24adcc9d4600         -jmp dword ptr [ebp*4 + 0x469dcc]
    cpu.ip = app->getMemory<x86::reg32>(4627916 + cpu.ebp * 4); goto dynamic_jump;
  case 0x00469c3b:
    // 00469c3b  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469c41  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469c44  f780a802000000000100   +test dword ptr [eax + 0x2a8], 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) & 65536 /*0x10000*/));
    // 00469c4e  0f856f010000           -jne 0x469dc3
    if (!cpu.flags.zf)
    {
        goto L_0x00469dc3;
    }
    // 00469c54  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469c58  889000030000           -mov byte ptr [eax + 0x300], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(768) /* 0x300 */) = cpu.dl;
    // 00469c5e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469c63  8a542411               -mov dl, byte ptr [esp + 0x11]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 00469c67  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469c6a  889101030000           -mov byte ptr [ecx + 0x301], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(769) /* 0x301 */) = cpu.dl;
    // 00469c70  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469c75  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469c78  889902030000           -mov byte ptr [ecx + 0x302], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(770) /* 0x302 */) = cpu.bl;
    // 00469c7e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469c84  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00469c87  f681a802000004         +test byte ptr [ecx + 0x2a8], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) & 4 /*0x4*/));
    // 00469c8e  7505                   -jne 0x469c95
    if (!cpu.flags.zf)
    {
        goto L_0x00469c95;
    }
    // 00469c90  e8dbbbfeff             -call 0x455870
    cpu.esp -= 4;
    sub_455870(app, cpu);
L_0x00469c95:
    // 00469c95  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469c9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469c9b  8b34b0                 -mov esi, dword ptr [eax + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469c9e  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 00469ca4  0d00000d00             -or eax, 0xd0000
    cpu.eax |= x86::reg32(x86::sreg32(851968 /*0xd0000*/));
    // 00469ca9  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 00469caf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469cb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469cb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469cb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469cb3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00469cb4:
    // 00469cb4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469cba  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469cbd  f780a802000000000100   +test dword ptr [eax + 0x2a8], 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) & 65536 /*0x10000*/));
    // 00469cc7  0f85f6000000           -jne 0x469dc3
    if (!cpu.flags.zf)
    {
        goto L_0x00469dc3;
    }
    // 00469ccd  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469cd1  889000030000           -mov byte ptr [eax + 0x300], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(768) /* 0x300 */) = cpu.dl;
    // 00469cd7  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469cdc  8a542411               -mov dl, byte ptr [esp + 0x11]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 00469ce0  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469ce3  889101030000           -mov byte ptr [ecx + 0x301], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(769) /* 0x301 */) = cpu.dl;
    // 00469ce9  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469cee  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469cf1  889902030000           -mov byte ptr [ecx + 0x302], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(770) /* 0x302 */) = cpu.bl;
    // 00469cf7  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469cfd  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00469d00  e86bbbfeff             -call 0x455870
    cpu.esp -= 4;
    sub_455870(app, cpu);
    // 00469d05  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469d0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d0b  8b34b0                 -mov esi, dword ptr [eax + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469d0e  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 00469d14  0d00000500             -or eax, 0x50000
    cpu.eax |= x86::reg32(x86::sreg32(327680 /*0x50000*/));
    // 00469d19  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 00469d1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d23  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00469d24:
    // 00469d24  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469d2a  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469d2d  f781a802000000000100   +test dword ptr [ecx + 0x2a8], 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) & 65536 /*0x10000*/));
    // 00469d37  0f8486000000           -je 0x469dc3
    if (cpu.flags.zf)
    {
        goto L_0x00469dc3;
    }
    // 00469d3d  e82ebcfeff             -call 0x455970
    cpu.esp -= 4;
    sub_455970(app, cpu);
    // 00469d42  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469d48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d49  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00469d4c  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 00469d52  81e1fffffbff           -and ecx, 0xfffbffff
    cpu.ecx &= x86::reg32(x86::sreg32(4294705151 /*0xfffbffff*/));
    // 00469d58  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 00469d5e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469d63  8b34b0                 -mov esi, dword ptr [eax + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469d66  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 00469d6c  25fffffeff             -and eax, 0xfffeffff
    cpu.eax &= x86::reg32(x86::sreg32(4294901759 /*0xfffeffff*/));
    // 00469d71  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 00469d77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d7b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00469d7c:
    // 00469d7c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469d82  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469d86  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469d89  888200030000           -mov byte ptr [edx + 0x300], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(768) /* 0x300 */) = cpu.al;
    // 00469d8f  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469d95  8a442411               -mov al, byte ptr [esp + 0x11]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 00469d99  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469d9c  888201030000           -mov byte ptr [edx + 0x301], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(769) /* 0x301 */) = cpu.al;
    // 00469da2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469da8  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00469dab  889a02030000           -mov byte ptr [edx + 0x302], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(770) /* 0x302 */) = cpu.bl;
    // 00469db1  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00469db6  8b34b0                 -mov esi, dword ptr [eax + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00469db9  818ea802000000008500   -or dword ptr [esi + 0x2a8], 0x850000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) |= x86::reg32(x86::sreg32(8716288 /*0x850000*/));
L_0x00469dc3:
    // 00469dc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469dc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469dc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469dc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469dc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469dc8  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_469de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469de0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469de2  e899c8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469de7  d91d2cd24900           -fstp dword ptr [0x49d22c]
    app->getMemory<float>(x86::reg32(4837932) /* 0x49d22c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469ded  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469def  e88cc8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469df4  d91d28d24900           -fstp dword ptr [0x49d228]
    app->getMemory<float>(x86::reg32(4837928) /* 0x49d228 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469dfa  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469dfc  e87fc8ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469e01  d91d24d24900           -fstp dword ptr [0x49d224]
    app->getMemory<float>(x86::reg32(4837924) /* 0x49d224 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469e07  d9052cd24900           -fld dword ptr [0x49d22c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837932) /* 0x49d22c */)));
    // 00469e0d  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00469e13  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00469e15  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00469e1a  742a                   -je 0x469e46
    if (cpu.flags.zf)
    {
        goto L_0x00469e46;
    }
    // 00469e1c  d90524d24900           -fld dword ptr [0x49d224]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837924) /* 0x49d224 */)));
    // 00469e22  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00469e28  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00469e2a  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00469e2f  7415                   -je 0x469e46
    if (cpu.flags.zf)
    {
        goto L_0x00469e46;
    }
    // 00469e31  d90528d24900           -fld dword ptr [0x49d228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837928) /* 0x49d228 */)));
    // 00469e37  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00469e3d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00469e3f  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00469e44  7536                   -jne 0x469e7c
    if (!cpu.flags.zf)
    {
        goto L_0x00469e7c;
    }
L_0x00469e46:
    // 00469e46  d90524d24900           -fld dword ptr [0x49d224]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837924) /* 0x49d224 */)));
    // 00469e4c  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00469e52  d91d24d24900           -fstp dword ptr [0x49d224]
    app->getMemory<float>(x86::reg32(4837924) /* 0x49d224 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469e58  d90528d24900           -fld dword ptr [0x49d228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837928) /* 0x49d228 */)));
    // 00469e5e  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00469e64  d91d28d24900           -fstp dword ptr [0x49d228]
    app->getMemory<float>(x86::reg32(4837928) /* 0x49d228 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469e6a  d9052cd24900           -fld dword ptr [0x49d22c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4837932) /* 0x49d22c */)));
    // 00469e70  d80d90784800           -fmul dword ptr [0x487890]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749456) /* 0x487890 */));
    // 00469e76  d91d2cd24900           -fstp dword ptr [0x49d22c]
    app->getMemory<float>(x86::reg32(4837932) /* 0x49d22c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00469e7c:
    // 00469e7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469e80  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469e82  e8f9c7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469e87  d91dacfc5100           -fstp dword ptr [0x51fcac]
    app->getMemory<float>(x86::reg32(5373100) /* 0x51fcac */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469e8d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469e8f  e8ecc7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469e94  d91da8fc5100           -fstp dword ptr [0x51fca8]
    app->getMemory<float>(x86::reg32(5373096) /* 0x51fca8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469e9a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469e9c  e8dfc7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469ea1  d91da4fc5100           -fstp dword ptr [0x51fca4]
    app->getMemory<float>(x86::reg32(5373092) /* 0x51fca4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469ea7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469eb0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469eb3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469eb5  e8c6c7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469eba  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469ebe  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469ec0  e8bbc7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469ec5  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469ec9  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469ecb  e8b0c7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469ed0  d81594744800           -fcom dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00469ed6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00469ed8  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00469edb  7a44                   -jp 0x469f21
    if (cpu.flags.pf)
    {
        goto L_0x00469f21;
    }
    // 00469edd  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00469ee1  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00469ee7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00469ee9  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00469eec  7a33                   -jp 0x469f21
    if (cpu.flags.pf)
    {
        goto L_0x00469f21;
    }
    // 00469eee  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00469ef2  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00469ef8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00469efa  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00469efd  7a22                   -jp 0x469f21
    if (cpu.flags.pf)
    {
        goto L_0x00469f21;
    }
    // 00469eff  d80de8724800           -fmul dword ptr [0x4872e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748008) /* 0x4872e8 */));
    // 00469f05  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00469f09  d80de8724800           -fmul dword ptr [0x4872e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748008) /* 0x4872e8 */));
    // 00469f0f  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469f13  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00469f17  d80de8724800           -fmul dword ptr [0x4872e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748008) /* 0x4872e8 */));
    // 00469f1d  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00469f21:
    // 00469f21  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00469f25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469f26  e865ce0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469f2b  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00469f2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469f30  e85bce0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469f35  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00469f37  e854ce0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469f3c  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00469f3e  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00469f40  e8ab36feff             -call 0x44d5f0
    cpu.esp -= 4;
    sub_44d5f0(app, cpu);
    // 00469f45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469f46  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469f49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469f50  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469f52  e829c7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469f57  d91d38d24900           -fstp dword ptr [0x49d238]
    app->getMemory<float>(x86::reg32(4837944) /* 0x49d238 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469f5d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469f5f  e81cc7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469f64  d91d34d24900           -fstp dword ptr [0x49d234]
    app->getMemory<float>(x86::reg32(4837940) /* 0x49d234 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469f6a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469f6c  e80fc7ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469f71  d91d30d24900           -fstp dword ptr [0x49d230]
    app->getMemory<float>(x86::reg32(4837936) /* 0x49d230 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469f77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_469f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469f80  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469f83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469f84  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469f86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469f87  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469f8b  e8f0c6ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469f90  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00469f92  e869c7ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00469f97  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469f99  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00469f9b  e8e0c6ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 00469fa0  e8ebcd0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00469fa5  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469fa9  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469faf  83f8ff                 +cmp eax, -1
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
    // 00469fb2  c7048a00000000         -mov dword ptr [edx + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = 0 /*0x0*/;
    // 00469fb9  752d                   -jne 0x469fe8
    if (!cpu.flags.zf)
    {
        goto L_0x00469fe8;
    }
    // 00469fbb  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00469fbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00469fc0  744a                   -je 0x46a00c
    if (cpu.flags.zf)
    {
        goto L_0x0046a00c;
    }
    // 00469fc2  8b0dc0f35100           -mov ecx, dword ptr [0x51f3c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 00469fc8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00469fca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00469fcc  7e16                   -jle 0x469fe4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469fe4;
    }
    // 00469fce  8bb6ec020000           -mov esi, dword ptr [esi + 0x2ec]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 00469fd4  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
L_0x00469fda:
    // 00469fda  393482                 +cmp dword ptr [edx + eax*4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469fdd  7405                   -je 0x469fe4
    if (cpu.flags.zf)
    {
        goto L_0x00469fe4;
    }
    // 00469fdf  40                     -inc eax
    (cpu.eax)++;
    // 00469fe0  3bc1                   +cmp eax, ecx
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
    // 00469fe2  7cf6                   -jl 0x469fda
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469fda;
    }
L_0x00469fe4:
    // 00469fe4  3bc1                   +cmp eax, ecx
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
    // 00469fe6  7424                   -je 0x46a00c
    if (cpu.flags.zf)
    {
        goto L_0x0046a00c;
    }
L_0x00469fe8:
    // 00469fe8  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00469fea  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00469fec  e8cf84fbff             -call 0x4224c0
    cpu.esp -= 4;
    sub_4224c0(app, cpu);
    // 00469ff1  f7d8                   +neg eax
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.eax;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00469ff3  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00469ff9  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00469ffb  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00469ffd  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046a001  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a005  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046a009  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046a00c:
    // 0046a00c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a00d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a00e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046a011  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a020  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046a023  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a024  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a026  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a027  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a02b  e850c6ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a030  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a032  e8c9c6ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046a037  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a039  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046a03b  e840c6ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a040  e84bcd0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a045  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a049  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a04f  83f8ff                 +cmp eax, -1
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
    // 0046a052  c7048a00000000         -mov dword ptr [edx + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = 0 /*0x0*/;
    // 0046a059  752d                   -jne 0x46a088
    if (!cpu.flags.zf)
    {
        goto L_0x0046a088;
    }
    // 0046a05b  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a05e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046a060  7444                   -je 0x46a0a6
    if (cpu.flags.zf)
    {
        goto L_0x0046a0a6;
    }
    // 0046a062  8b0dc0f35100           -mov ecx, dword ptr [0x51f3c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5370816) /* 0x51f3c0 */);
    // 0046a068  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046a06a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046a06c  7e16                   -jle 0x46a084
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a084;
    }
    // 0046a06e  8bb6ec020000           -mov esi, dword ptr [esi + 0x2ec]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0046a074  8b154c845100           -mov edx, dword ptr [0x51844c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
L_0x0046a07a:
    // 0046a07a  393482                 +cmp dword ptr [edx + eax*4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a07d  7405                   -je 0x46a084
    if (cpu.flags.zf)
    {
        goto L_0x0046a084;
    }
    // 0046a07f  40                     -inc eax
    (cpu.eax)++;
    // 0046a080  3bc1                   +cmp eax, ecx
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
    // 0046a082  7cf6                   -jl 0x46a07a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a07a;
    }
L_0x0046a084:
    // 0046a084  3bc1                   +cmp eax, ecx
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
    // 0046a086  741e                   -je 0x46a0a6
    if (cpu.flags.zf)
    {
        goto L_0x0046a0a6;
    }
L_0x0046a088:
    // 0046a088  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046a08a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046a08c  e82f84fbff             -call 0x4224c0
    cpu.esp -= 4;
    sub_4224c0(app, cpu);
    // 0046a091  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a097  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046a09b  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0046a09f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a0a3  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046a0a6:
    // 0046a0a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a0a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a0a8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046a0ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a0b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a0b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a0b2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a0b4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a0b6  e8c5c5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a0bb  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a0bf  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a0c1  e8bac5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a0c6  e8c5cc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a0cb  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a0cf  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a0d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a0d2  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a0d5  e846edf9ff             -call 0x408e20
    cpu.esp -= 4;
    sub_408e20(app, cpu);
    // 0046a0da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a0db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a0dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a0e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a0e1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a0e3  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046a0e5  e896c5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a0ea  e8a1cc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a0ef  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a0f2  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046a0f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a0f5  e9b6ecf9ff             -jmp 0x408db0
    return sub_408db0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46a100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a100  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a101  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a103  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a104  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a106  e875c5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a10b  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 0046a111  e87acc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a116  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a118  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046a11a  e861c5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a11f  e86ccc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a124  83f8ff                 +cmp eax, -1
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
    // 0046a127  7505                   -jne 0x46a12e
    if (!cpu.flags.zf)
    {
        goto L_0x0046a12e;
    }
    // 0046a129  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a12c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046a12e:
    // 0046a12e  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a134  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a137  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0046a13d  898ad0020000           -mov dword ptr [edx + 0x2d0], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(720) /* 0x2d0 */) = cpu.ecx;
    // 0046a143  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a149  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0046a14c  89b9d4020000           -mov dword ptr [ecx + 0x2d4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */) = cpu.edi;
    // 0046a152  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a158  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a159  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a15a  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0046a15d  e9be03feff             -jmp 0x44a520
    return sub_44a520(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46a170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a170  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a173  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a174  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a176  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a178  e803c5ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a17d  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a181  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a183  e8f8c4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a188  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a18c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a18e  e8edc4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a193  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a197  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a199  e8e2c4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a19e  e8edcb0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a1a3  83f8ff                 +cmp eax, -1
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
    // 0046a1a6  7505                   -jne 0x46a1ad
    if (!cpu.flags.zf)
    {
        goto L_0x0046a1ad;
    }
    // 0046a1a8  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a1ab  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046a1ad:
    // 0046a1ad  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a1b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a1b4  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a1b7  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046a1bb  898a20010000           -mov dword ptr [edx + 0x120], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(288) /* 0x120 */) = cpu.ecx;
    // 0046a1c1  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a1c7  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0046a1ca  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a1ce  899124010000           -mov dword ptr [ecx + 0x124], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(292) /* 0x124 */) = cpu.edx;
    // 0046a1d4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a1da  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a1dd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a1e1  898228010000           -mov dword ptr [edx + 0x128], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 0046a1e7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a1ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a1f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a1f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a1f2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a1f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a1f5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a1f7  e884c4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a1fc  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a200  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a202  e879c4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a207  e884cb0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a20c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a20e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046a210  e86bc4ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a215  e876cb0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a21a  83f8ff                 +cmp eax, -1
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
    // 0046a21d  7505                   -jne 0x46a224
    if (!cpu.flags.zf)
    {
        goto L_0x0046a224;
    }
    // 0046a21f  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a222  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046a224:
    // 0046a224  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a226  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a227  83e900                 +sub ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a22a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a22b  7430                   -je 0x46a25d
    if (cpu.flags.zf)
    {
        goto L_0x0046a25d;
    }
    // 0046a22d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046a22e  7418                   -je 0x46a248
    if (cpu.flags.zf)
    {
        goto L_0x0046a248;
    }
    // 0046a230  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046a231  753d                   -jne 0x46a270
    if (!cpu.flags.zf)
    {
        goto L_0x0046a270;
    }
    // 0046a233  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a239  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a23c  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046a240  898228010000           -mov dword ptr [edx + 0x128], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 0046a246  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a247  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046a248:
    // 0046a248  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a24e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a251  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046a255  898224010000           -mov dword ptr [edx + 0x124], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(292) /* 0x124 */) = cpu.eax;
    // 0046a25b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a25c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046a25d:
    // 0046a25d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a263  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a266  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046a26a  898220010000           -mov dword ptr [edx + 0x120], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(288) /* 0x120 */) = cpu.eax;
L_0x0046a270:
    // 0046a270  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a271  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a280  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a283  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a284  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a286  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046a28a  e8f1c3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a28f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a291  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a295  e8e6c3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a29a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a29c  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a2a0  e8dbc3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a2a5  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a2a7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a2a9  e8d2c3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a2ae  e8ddca0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a2b3  83f8ff                 +cmp eax, -1
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
    // 0046a2b6  7505                   -jne 0x46a2bd
    if (!cpu.flags.zf)
    {
        goto L_0x0046a2bd;
    }
    // 0046a2b8  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a2bb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046a2bd:
    // 0046a2bd  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a2c3  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a2c7  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a2ca  8b8a20010000           -mov ecx, dword ptr [edx + 0x120]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(288) /* 0x120 */);
    // 0046a2d0  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a2d6  890cb2                 -mov dword ptr [edx + esi*4], ecx
    app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4) = cpu.ecx;
    // 0046a2d9  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a2df  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a2e3  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a2e6  8b8a24010000           -mov ecx, dword ptr [edx + 0x124]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(292) /* 0x124 */);
    // 0046a2ec  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a2f2  890cb2                 -mov dword ptr [edx + esi*4], ecx
    app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4) = cpu.ecx;
    // 0046a2f5  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a2fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a2fc  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a2ff  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a303  8b8228010000           -mov eax, dword ptr [edx + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(296) /* 0x128 */);
    // 0046a309  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a30f  89048a                 -mov dword ptr [edx + ecx*4], eax
    app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4) = cpu.eax;
    // 0046a312  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a315  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a320  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a324  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a326  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a328  e853c3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a32d  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a331  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a333  e848c3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a338  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a33c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a33e  e83dc3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a343  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a347  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a349  e832c3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a34e  e83dca0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a353  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a359  83f8ff                 +cmp eax, -1
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
    // 0046a35c  7505                   -jne 0x46a363
    if (!cpu.flags.zf)
    {
        goto L_0x0046a363;
    }
    // 0046a35e  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a361  eb03                   -jmp 0x46a366
    goto L_0x0046a366;
L_0x0046a363:
    // 0046a363  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
L_0x0046a366:
    // 0046a366  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046a368  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a369  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046a36d  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0046a370  d84874                 -fmul dword ptr [eax + 0x74]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */));
    // 0046a373  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046a377  d8484c                 -fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0046a37a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046a37c  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046a380  d84824                 -fmul dword ptr [eax + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0046a383  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046a385  d9982c010000           -fstp dword ptr [eax + 0x12c]
    app->getMemory<float>(cpu.eax + x86::reg32(300) /* 0x12c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a38b  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046a38d  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a392  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046a396  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0046a399  d84878                 -fmul dword ptr [eax + 0x78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */));
    // 0046a39c  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046a3a0  d84850                 -fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0046a3a3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046a3a5  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046a3a9  d84828                 -fmul dword ptr [eax + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0046a3ac  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046a3ae  d99830010000           -fstp dword ptr [eax + 0x130]
    app->getMemory<float>(cpu.eax + x86::reg32(304) /* 0x130 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a3b4  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046a3b6  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a3bc  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046a3c0  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0046a3c3  d8487c                 -fmul dword ptr [eax + 0x7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */));
    // 0046a3c6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046a3ca  d84854                 -fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0046a3cd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046a3cf  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046a3d3  d8482c                 -fmul dword ptr [eax + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 0046a3d6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046a3d8  d99834010000           -fstp dword ptr [eax + 0x134]
    app->getMemory<float>(cpu.eax + x86::reg32(308) /* 0x134 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a3de  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a3e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a3f0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a3f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a3f4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a3f6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a3f8  e883c2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a3fd  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a401  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a403  e878c2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a408  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a40c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a40e  e86dc2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a413  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a417  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a419  e862c2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a41e  e86dc90000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a423  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a429  83f8ff                 +cmp eax, -1
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
    // 0046a42c  7505                   -jne 0x46a433
    if (!cpu.flags.zf)
    {
        goto L_0x0046a433;
    }
    // 0046a42e  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a431  eb03                   -jmp 0x46a436
    goto L_0x0046a436;
L_0x0046a433:
    // 0046a433  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046a436:
    // 0046a436  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046a438  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a439  8b0c91                 -mov ecx, dword ptr [ecx + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0046a43c  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046a440  89912c010000           -mov dword ptr [ecx + 0x12c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(300) /* 0x12c */) = cpu.edx;
    // 0046a446  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046a448  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a44e  8b0c8a                 -mov ecx, dword ptr [edx + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0046a451  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a455  899130010000           -mov dword ptr [ecx + 0x130], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(304) /* 0x130 */) = cpu.edx;
    // 0046a45b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046a45d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a463  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046a466  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a46a  898234010000           -mov dword ptr [edx + 0x134], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 0046a470  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a473  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a480  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046a483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a484  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a486  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a488  e8f3c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a48d  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a491  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a493  e8e8c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a498  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a49c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a49e  e8ddc1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a4a3  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a4a7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a4a9  e8d2c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a4ae  d95c2438               -fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a4b2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a4b4  e8c7c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a4b9  d95c2434               -fstp dword ptr [esp + 0x34]
    app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a4bd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a4bf  e8bcc1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a4c4  d95c2430               -fstp dword ptr [esp + 0x30]
    app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a4c8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a4ca  e8b1c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a4cf  e8bcc80000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a4d4  83f8ff                 +cmp eax, -1
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
    // 0046a4d7  7505                   -jne 0x46a4de
    if (!cpu.flags.zf)
    {
        goto L_0x0046a4de;
    }
    // 0046a4d9  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a4dc  eb09                   -jmp 0x46a4e7
    goto L_0x0046a4e7;
L_0x0046a4de:
    // 0046a4de  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a4e4  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046a4e7:
    // 0046a4e7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a4eb  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046a4ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a4ee  8d542430               -lea edx, [esp + 0x30]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046a4f2  e8f90bfeff             -call 0x44b0f0
    cpu.esp -= 4;
    sub_44b0f0(app, cpu);
    // 0046a4f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a4f8  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046a4fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a500  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a503  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a504  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a506  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a507  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046a50b  e870c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a510  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a512  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046a516  e865c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a51b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a51d  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a521  e85ac1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a526  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a528  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a52a  e851c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a52f  e85cc80000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a534  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a536  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046a538  e843c1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a53d  e84ec80000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a542  83f8ff                 +cmp eax, -1
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
    // 0046a545  7505                   -jne 0x46a54c
    if (!cpu.flags.zf)
    {
        goto L_0x0046a54c;
    }
    // 0046a547  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a54a  eb09                   -jmp 0x46a555
    goto L_0x0046a555;
L_0x0046a54c:
    // 0046a54c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a552  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046a555:
    // 0046a555  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a557  83e900                 +sub ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a55a  7410                   -je 0x46a56c
    if (cpu.flags.zf)
    {
        goto L_0x0046a56c;
    }
    // 0046a55c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046a55d  7408                   -je 0x46a567
    if (cpu.flags.zf)
    {
        goto L_0x0046a567;
    }
    // 0046a55f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046a560  750f                   -jne 0x46a571
    if (!cpu.flags.zf)
    {
        goto L_0x0046a571;
    }
    // 0046a562  83c070                 +add eax, 0x70
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a565  eb0e                   -jmp 0x46a575
    goto L_0x0046a575;
L_0x0046a567:
    // 0046a567  83c048                 +add eax, 0x48
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a56a  eb09                   -jmp 0x46a575
    goto L_0x0046a575;
L_0x0046a56c:
    // 0046a56c  83c020                 +add eax, 0x20
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a56f  eb04                   -jmp 0x46a575
    goto L_0x0046a575;
L_0x0046a571:
    // 0046a571  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0046a575:
    // 0046a575  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a57b  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a57f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046a582  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a583  8914b1                 -mov dword ptr [ecx + esi*4], edx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4) = cpu.edx;
    // 0046a586  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a58c  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a590  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046a593  8914b1                 -mov dword ptr [ecx + esi*4], edx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4) = cpu.edx;
    // 0046a596  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046a599  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046a59d  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a5a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a5a4  891481                 -mov dword ptr [ecx + eax*4], edx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = cpu.edx;
    // 0046a5a7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a5aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a5b0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a5b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a5b4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a5b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a5b7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a5b9  e8c2c0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a5be  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a5c2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a5c4  e8b7c0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a5c9  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a5cd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a5cf  e8acc0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a5d4  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a5d8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a5da  e8a1c0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a5df  e8acc70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a5e4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a5e6  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046a5e8  e893c0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a5ed  e89ec70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a5f2  83f8ff                 +cmp eax, -1
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
    // 0046a5f5  7505                   -jne 0x46a5fc
    if (!cpu.flags.zf)
    {
        goto L_0x0046a5fc;
    }
    // 0046a5f7  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a5fa  eb09                   -jmp 0x46a605
    goto L_0x0046a605;
L_0x0046a5fc:
    // 0046a5fc  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a602  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046a605:
    // 0046a605  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a608  83e900                 +sub ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a60b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a60c  7410                   -je 0x46a61e
    if (cpu.flags.zf)
    {
        goto L_0x0046a61e;
    }
    // 0046a60e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046a60f  7408                   -je 0x46a619
    if (cpu.flags.zf)
    {
        goto L_0x0046a619;
    }
    // 0046a611  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046a612  750f                   -jne 0x46a623
    if (!cpu.flags.zf)
    {
        goto L_0x0046a623;
    }
    // 0046a614  83c070                 +add eax, 0x70
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a617  eb0e                   -jmp 0x46a627
    goto L_0x0046a627;
L_0x0046a619:
    // 0046a619  83c048                 +add eax, 0x48
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a61c  eb09                   -jmp 0x46a627
    goto L_0x0046a627;
L_0x0046a61e:
    // 0046a61e  83c020                 +add eax, 0x20
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a621  eb04                   -jmp 0x46a627
    goto L_0x0046a627;
L_0x0046a623:
    // 0046a623  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0046a627:
    // 0046a627  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046a62b  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a62f  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046a632  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a636  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0046a639  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046a63c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a63f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a640  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046a643  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a644  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a646  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046a64a  e831c0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a64f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a651  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a655  e826c0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a65a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a65c  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a660  e81bc0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a665  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a667  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a669  e812c0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a66e  e81dc70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a673  83f8ff                 +cmp eax, -1
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
    // 0046a676  7505                   -jne 0x46a67d
    if (!cpu.flags.zf)
    {
        goto L_0x0046a67d;
    }
    // 0046a678  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a67b  eb09                   -jmp 0x46a686
    goto L_0x0046a686;
L_0x0046a67d:
    // 0046a67d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a683  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046a686:
    // 0046a686  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0046a68c  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046a690  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0046a696  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046a69a  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0046a6a0  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046a6a4  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046a6a8  e80346ffff             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0046a6ad  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0046a6b1  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a6b6  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a6ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a6bb  d91c88                 -fstp dword ptr [eax + ecx*4]
    app->getMemory<float>(cpu.eax + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a6be  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0046a6c2  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a6c8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a6cc  d91c82                 -fstp dword ptr [edx + eax*4]
    app->getMemory<float>(cpu.edx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a6cf  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0046a6d3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a6d7  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a6dd  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a6e0  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046a6e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a6f0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a6f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a6f4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a6f6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a6f8  e883bfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a6fd  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a701  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a703  e878bfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a708  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a70c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a70e  e86dbfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a713  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a717  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a719  e862bfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a71e  e86dc60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a723  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a729  83f8ff                 +cmp eax, -1
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
    // 0046a72c  7505                   -jne 0x46a733
    if (!cpu.flags.zf)
    {
        goto L_0x0046a733;
    }
    // 0046a72e  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046a731  eb03                   -jmp 0x46a736
    goto L_0x0046a736;
L_0x0046a733:
    // 0046a733  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046a736:
    // 0046a736  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a73a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a73e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a73f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046a743  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a744  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046a746  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a747  8b0c91                 -mov ecx, dword ptr [ecx + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0046a74a  e8b14ffeff             -call 0x44f700
    cpu.esp -= 4;
    sub_44f700(app, cpu);
    // 0046a74f  e8dc85feff             -call 0x452d30
    cpu.esp -= 4;
    sub_452d30(app, cpu);
    // 0046a754  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a759  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046a75b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046a75d  8981c8020000           -mov dword ptr [ecx + 0x2c8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */) = cpu.eax;
    // 0046a763  8986c8020000           -mov dword ptr [esi + 0x2c8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(712) /* 0x2c8 */) = cpu.eax;
    // 0046a769  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a76a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a76d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a770  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046a773  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a774  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a775  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a777  e804bfffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a77c  e80fc60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a781  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046a783  e878bfffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046a788  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046a78c  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046a78e  e8edbeffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a793  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046a795  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a797  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a799  e8723cffff             -call 0x45e410
    cpu.esp -= 4;
    sub_45e410(app, cpu);
    // 0046a79e  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046a7a4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046a7a8  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0046a7ac  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046a7b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a7b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a7b2  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a7b5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046a7b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a7c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a7c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a7c2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a7c4  e8d73effff             -call 0x45e6a0
    cpu.esp -= 4;
    sub_45e6a0(app, cpu);
    // 0046a7c9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a7cf  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a7d1  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046a7d4  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046a7d7  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046a7da  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046a7dc  7e29                   -jle 0x46a807
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a807;
    }
L_0x0046a7de:
    // 0046a7de  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046a7e1  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0046a7e4  668b5010               -mov dx, word ptr [eax + 0x10]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046a7e8  81e2fffd0000           -and edx, 0xfdff
    cpu.edx &= x86::reg32(x86::sreg32(65023 /*0xfdff*/));
    // 0046a7ee  83ca04                 -or edx, 4
    cpu.edx |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a7f1  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a7f2  66895010               -mov word ptr [eax + 0x10], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 0046a7f6  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a7fc  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046a7ff  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046a802  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a805  7cd7                   -jl 0x46a7de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a7de;
    }
L_0x0046a807:
    // 0046a807  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046a80a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a80c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046a80f  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046a812  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046a814  7e29                   -jle 0x46a83f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a83f;
    }
L_0x0046a816:
    // 0046a816  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046a819  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0046a81c  668b5010               -mov dx, word ptr [eax + 0x10]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046a820  81e2fffd0000           -and edx, 0xfdff
    cpu.edx &= x86::reg32(x86::sreg32(65023 /*0xfdff*/));
    // 0046a826  83ca04                 -or edx, 4
    cpu.edx |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a829  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a82a  66895010               -mov word ptr [eax + 0x10], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 0046a82e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a834  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046a837  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046a83a  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a83d  7cd7                   -jl 0x46a816
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a816;
    }
L_0x0046a83f:
    // 0046a83f  8b14b2                 -mov edx, dword ptr [edx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046a842  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a844  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046a847  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046a84a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046a84c  7e28                   -jle 0x46a876
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a876;
    }
L_0x0046a84e:
    // 0046a84e  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046a851  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046a854  668b5010               -mov dx, word ptr [eax + 0x10]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046a858  81e2fffd0000           -and edx, 0xfdff
    cpu.edx &= x86::reg32(x86::sreg32(65023 /*0xfdff*/));
    // 0046a85e  83ca04                 -or edx, 4
    cpu.edx |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a861  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a862  66895010               -mov word ptr [eax + 0x10], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 0046a866  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a86b  8b14b0                 -mov edx, dword ptr [eax + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046a86e  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046a871  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a874  7cd8                   -jl 0x46a84e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a84e;
    }
L_0x0046a876:
    // 0046a876  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a877  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046a881  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046a882  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a883  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046a885  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a886  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046a888  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046a88a  e8113effff             -call 0x45e6a0
    cpu.esp -= 4;
    sub_45e6a0(app, cpu);
    // 0046a88f  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 0046a895  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a897  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0046a89a  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 0046a89c  8986a8020000           -mov dword ptr [esi + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 0046a8a2  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046a8a5  bdfffb0000             -mov ebp, 0xfbff
    cpu.ebp = 64511 /*0xfbff*/;
    // 0046a8aa  bb00040000             -mov ebx, 0x400
    cpu.ebx = 1024 /*0x400*/;
    // 0046a8af  394818                 +cmp dword ptr [eax + 0x18], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a8b2  7e22                   -jle 0x46a8d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a8d6;
    }
L_0x0046a8b4:
    // 0046a8b4  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046a8b7  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046a8ba  385018                 +cmp byte ptr [eax + 0x18], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046a8bd  730e                   -jae 0x46a8cd
    if (!cpu.flags.cf)
    {
        goto L_0x0046a8cd;
    }
    // 0046a8bf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046a8c1  7506                   -jne 0x46a8c9
    if (!cpu.flags.zf)
    {
        goto L_0x0046a8c9;
    }
    // 0046a8c3  66216810               +and word ptr [eax + 0x10], bp
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) &= x86::reg16(x86::sreg16(cpu.bp))));
    // 0046a8c7  eb04                   -jmp 0x46a8cd
    goto L_0x0046a8cd;
L_0x0046a8c9:
    // 0046a8c9  66095810               -or word ptr [eax + 0x10], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) |= x86::reg16(x86::sreg16(cpu.bx));
L_0x0046a8cd:
    // 0046a8cd  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046a8d0  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a8d1  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a8d4  7cde                   -jl 0x46a8b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a8b4;
    }
L_0x0046a8d6:
    // 0046a8d6  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046a8d9  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a8db  394818                 +cmp dword ptr [eax + 0x18], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a8de  7e22                   -jle 0x46a902
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a902;
    }
L_0x0046a8e0:
    // 0046a8e0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046a8e3  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046a8e6  385018                 +cmp byte ptr [eax + 0x18], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046a8e9  730e                   -jae 0x46a8f9
    if (!cpu.flags.cf)
    {
        goto L_0x0046a8f9;
    }
    // 0046a8eb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046a8ed  7506                   -jne 0x46a8f5
    if (!cpu.flags.zf)
    {
        goto L_0x0046a8f5;
    }
    // 0046a8ef  66216810               +and word ptr [eax + 0x10], bp
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) &= x86::reg16(x86::sreg16(cpu.bp))));
    // 0046a8f3  eb04                   -jmp 0x46a8f9
    goto L_0x0046a8f9;
L_0x0046a8f5:
    // 0046a8f5  66095810               -or word ptr [eax + 0x10], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) |= x86::reg16(x86::sreg16(cpu.bx));
L_0x0046a8f9:
    // 0046a8f9  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046a8fc  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a8fd  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a900  7cde                   -jl 0x46a8e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a8e0;
    }
L_0x0046a902:
    // 0046a902  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046a905  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a907  394818                 +cmp dword ptr [eax + 0x18], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a90a  7e22                   -jle 0x46a92e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a92e;
    }
L_0x0046a90c:
    // 0046a90c  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046a90f  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046a912  385018                 +cmp byte ptr [eax + 0x18], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046a915  730e                   -jae 0x46a925
    if (!cpu.flags.cf)
    {
        goto L_0x0046a925;
    }
    // 0046a917  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046a919  7506                   -jne 0x46a921
    if (!cpu.flags.zf)
    {
        goto L_0x0046a921;
    }
    // 0046a91b  66216810               +and word ptr [eax + 0x10], bp
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) &= x86::reg16(x86::sreg16(cpu.bp))));
    // 0046a91f  eb04                   -jmp 0x46a925
    goto L_0x0046a925;
L_0x0046a921:
    // 0046a921  66095810               -or word ptr [eax + 0x10], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) |= x86::reg16(x86::sreg16(cpu.bx));
L_0x0046a925:
    // 0046a925  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046a928  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a929  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a92c  7cde                   -jl 0x46a90c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a90c;
    }
L_0x0046a92e:
    // 0046a92e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a92f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a930  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a931  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a932  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46a940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a940  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046a942  741d                   -je 0x46a961
    if (cpu.flags.zf)
    {
        goto L_0x0046a961;
    }
    // 0046a944  8b82b4020000           -mov eax, dword ptr [edx + 0x2b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(692) /* 0x2b4 */);
    // 0046a94a  8b15b4c05100           -mov edx, dword ptr [0x51c0b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357748) /* 0x51c0b4 */);
    // 0046a950  3bc2                   +cmp eax, edx
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
    // 0046a952  7408                   -je 0x46a95c
    if (cpu.flags.zf)
    {
        goto L_0x0046a95c;
    }
    // 0046a954  3b05b8c05100           +cmp eax, dword ptr [0x51c0b8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5357752) /* 0x51c0b8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a95a  7505                   -jne 0x46a961
    if (!cpu.flags.zf)
    {
        goto L_0x0046a961;
    }
L_0x0046a95c:
    // 0046a95c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046a95e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0046a961:
    // 0046a961  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046a966  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_46a970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0046a970  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a971  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046a972  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a973  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a974  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046a976  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a978  e803bdffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a97d  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046a981  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a983  e8f8bcffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a988  e803c40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a98d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a98f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046a991  e8eabcffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046a996  e8f5c30000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046a99b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046a99d  83feff                 +cmp esi, -1
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
    // 0046a9a0  7505                   -jne 0x46a9a7
    if (!cpu.flags.zf)
    {
        goto L_0x0046a9a7;
    }
    // 0046a9a2  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046a9a5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x0046a9a7:
    // 0046a9a7  b980ad4800             -mov ecx, 0x48ad80
    cpu.ecx = 4763008 /*0x48ad80*/;
    // 0046a9ac  e8cf4dffff             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0046a9b1  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a9b7  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046a9ba  3982b4020000           +cmp dword ptr [edx + 0x2b4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(692) /* 0x2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a9c0  741b                   -je 0x46a9dd
    if (cpu.flags.zf)
    {
        goto L_0x0046a9dd;
    }
    // 0046a9c2  b968ad4800             -mov ecx, 0x48ad68
    cpu.ecx = 4762984 /*0x48ad68*/;
    // 0046a9c7  e8b44dffff             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0046a9cc  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046a9d2  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046a9d5  3982b4020000           +cmp dword ptr [edx + 0x2b4], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(692) /* 0x2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a9db  7530                   -jne 0x46aa0d
    if (!cpu.flags.zf)
    {
        goto L_0x0046aa0d;
    }
L_0x0046a9dd:
    // 0046a9dd  b9c8ad4800             -mov ecx, 0x48adc8
    cpu.ecx = 4763080 /*0x48adc8*/;
    // 0046a9e2  e8994dffff             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0046a9e7  b970ad4800             -mov ecx, 0x48ad70
    cpu.ecx = 4762992 /*0x48ad70*/;
    // 0046a9ec  a3b4c05100             -mov dword ptr [0x51c0b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5357748) /* 0x51c0b4 */) = cpu.eax;
    // 0046a9f1  e88a4dffff             -call 0x45f780
    cpu.esp -= 4;
    sub_45f780(app, cpu);
    // 0046a9f6  a3b8c05100             -mov dword ptr [0x51c0b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5357752) /* 0x51c0b8 */) = cpu.eax;
    // 0046a9fb  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aa00  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046aa03  c7810c03000040a94600   -mov dword ptr [ecx + 0x30c], 0x46a940
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(780) /* 0x30c */) = 4630848 /*0x46a940*/;
L_0x0046aa0d:
    // 0046aa0d  83fb16                 +cmp ebx, 0x16
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22 /*0x16*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046aa10  0f87f6070000           -ja 0x46b20c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046b20c;
    }
    // 0046aa16  ff249d20b24600         -jmp dword ptr [ebx*4 + 0x46b220]
    cpu.ip = app->getMemory<x86::reg32>(4633120 + cpu.ebx * 4); goto dynamic_jump;
  case 0x0046aa1d:
    // 0046aa1d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aa23  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046aa27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aa28  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aa2b  898880020000           -mov dword ptr [eax + 0x280], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.ecx;
    // 0046aa31  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aa37  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aa3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aa3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aa3c  83c404                 +add esp, 4
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
    // 0046aa3f  e9dcfafdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046aa44:
    // 0046aa44  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046aa48  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046aa4e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046aa50  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046aa53  7b17                   -jnp 0x46aa6c
    if (!cpu.flags.pf)
    {
        goto L_0x0046aa6c;
    }
    // 0046aa55  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aa5b  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aa5e  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046aa64  83c904                 +or ecx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0046aa67  e9c2030000             -jmp 0x46ae2e
    goto L_0x0046ae2e;
L_0x0046aa6c:
    // 0046aa6c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aa72  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046aa75  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046aa7b  83e1fb                 -and ecx, 0xfffffffb
    cpu.ecx &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
    // 0046aa7e  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046aa84  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aa8a  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aa8d  e88efafdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046aa92  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aa98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aa99  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aa9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aa9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aa9e  83c404                 +add esp, 4
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
    // 0046aaa1  e97afafdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046aaa6:
    // 0046aaa6  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046aaaa  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046aab0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046aab2  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046aab5  7b39                   -jnp 0x46aaf0
    if (!cpu.flags.pf)
    {
        goto L_0x0046aaf0;
    }
    // 0046aab7  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aabc  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046aabf  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046aac5  83c908                 -or ecx, 8
    cpu.ecx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046aac8  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046aace  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aad4  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046aad7  e844fafdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046aadc  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aae2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aae3  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aae6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aae7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aae8  83c404                 +add esp, 4
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
    // 0046aaeb  e930fafdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046aaf0:
    // 0046aaf0  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aaf6  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aaf9  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046aaff  83e1f7                 +and ecx, 0xfffffff7
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/))));
    // 0046ab02  e927030000             -jmp 0x46ae2e
    goto L_0x0046ae2e;
  case 0x0046ab07:
    // 0046ab07  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046ab0b  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046ab11  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046ab13  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046ab16  7b3a                   -jnp 0x46ab52
    if (!cpu.flags.pf)
    {
        goto L_0x0046ab52;
    }
    // 0046ab18  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ab1e  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046ab21  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046ab27  83c940                 -or ecx, 0x40
    cpu.ecx |= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046ab2a  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046ab30  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ab36  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ab39  e8e2f9fdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046ab3e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ab44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab45  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ab48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab4a  83c404                 +add esp, 4
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
    // 0046ab4d  e9cef9fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046ab52:
    // 0046ab52  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ab57  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046ab5a  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046ab60  83e1bf                 -and ecx, 0xffffffbf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 0046ab63  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046ab69  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ab6f  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046ab72  e8a9f9fdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046ab77  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ab7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab7e  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ab81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab83  83c404                 +add esp, 4
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
    // 0046ab86  e995f9fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046ab8b:
    // 0046ab8b  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046ab8f  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046ab95  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046ab97  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046ab9a  7b17                   -jnp 0x46abb3
    if (!cpu.flags.pf)
    {
        goto L_0x0046abb3;
    }
    // 0046ab9c  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aba2  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aba5  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046abab  83c920                 +or ecx, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 0046abae  e97b020000             -jmp 0x46ae2e
    goto L_0x0046ae2e;
L_0x0046abb3:
    // 0046abb3  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046abb9  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046abbc  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046abc2  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0046abc5  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046abcb  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046abd1  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046abd4  e847f9fdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046abd9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046abdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046abe0  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046abe3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046abe4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046abe5  83c404                 +add esp, 4
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
    // 0046abe8  e933f9fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046abed:
    // 0046abed  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046abf1  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046abf7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046abf9  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046abfc  7b2b                   -jnp 0x46ac29
    if (!cpu.flags.pf)
    {
        goto L_0x0046ac29;
    }
    // 0046abfe  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ac03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac04  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046ac07  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046ac0d  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046ac10  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046ac16  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ac1c  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ac1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac20  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac21  83c404                 +add esp, 4
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
    // 0046ac24  e9f7f8fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046ac29:
    // 0046ac29  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ac2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac30  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046ac33  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046ac39  83e1ef                 -and ecx, 0xffffffef
    cpu.ecx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0046ac3c  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046ac42  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ac48  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ac4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac4d  83c404                 +add esp, 4
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
    // 0046ac50  e9cbf8fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046ac55:
    // 0046ac55  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046ac57  e864fbffff             -call 0x46a7c0
    cpu.esp -= 4;
    sub_46a7c0(app, cpu);
    // 0046ac5c  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ac62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac63  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ac66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac68  83c404                 +add esp, 4
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
    // 0046ac6b  e9b0f8fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046ac70:
    // 0046ac70  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ac76  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ac7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac7b  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ac7e  89887c020000           -mov dword ptr [eax + 0x27c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(636) /* 0x27c */) = cpu.ecx;
    // 0046ac84  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ac8a  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ac8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac8f  83c404                 +add esp, 4
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
    // 0046ac92  e989f8fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046ac97:
    // 0046ac97  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046ac9b  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046aca1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046aca3  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046aca6  7b43                   -jnp 0x46aceb
    if (!cpu.flags.pf)
    {
        goto L_0x0046aceb;
    }
    // 0046aca8  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046acae  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046acb1  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046acb7  81c900000200           -or ecx, 0x20000
    cpu.ecx |= x86::reg32(x86::sreg32(131072 /*0x20000*/));
    // 0046acbd  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046acc3  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046acc8  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046accb  e850f8fdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046acd0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046acd2  e8a96afbff             -call 0x421780
    cpu.esp -= 4;
    sub_421780(app, cpu);
    // 0046acd7  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046acdd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acde  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ace1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ace2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ace3  83c404                 +add esp, 4
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
    // 0046ace6  e935f8fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046aceb:
    // 0046aceb  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046acf1  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046acf4  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046acfa  81e1fffffdff           -and ecx, 0xfffdffff
    cpu.ecx &= x86::reg32(x86::sreg32(4294836223 /*0xfffdffff*/));
    // 0046ad00  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046ad06  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ad0c  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ad0f  e80cf8fdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046ad14  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ad1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad1b  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ad1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad20  83c404                 +add esp, 4
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
    // 0046ad23  e9f8f7fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046ad28:
    // 0046ad28  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ad2d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ad31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad32  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046ad35  899170020000           -mov dword ptr [ecx + 0x270], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(624) /* 0x270 */) = cpu.edx;
    // 0046ad3b  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ad41  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ad44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad46  83c404                 +add esp, 4
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
    // 0046ad49  e9d2f7fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046ad4e:
    // 0046ad4e  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046ad52  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046ad58  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046ad5a  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046ad5d  7b26                   -jnp 0x46ad85
    if (!cpu.flags.pf)
    {
        goto L_0x0046ad85;
    }
    // 0046ad5f  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ad64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad65  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046ad68  c7810c03000030174100   -mov dword ptr [ecx + 0x30c], 0x411730
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(780) /* 0x30c */) = 4265776 /*0x411730*/;
    // 0046ad72  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ad78  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ad7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad7d  83c404                 +add esp, 4
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
    // 0046ad80  e99bf7fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046ad85:
    // 0046ad85  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ad8b  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ad8e  81b80c03000030174100   +cmp dword ptr [eax + 0x30c], 0x411730
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(780) /* 0x30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4265776 /*0x411730*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ad98  e910040000             -jmp 0x46b1ad
    goto L_0x0046b1ad;
  case 0x0046ad9d:
    // 0046ad9d  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046ada1  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046ada7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046ada9  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046adac  7b2e                   -jnp 0x46addc
    if (!cpu.flags.pf)
    {
        goto L_0x0046addc;
    }
    // 0046adae  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046adb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046adb4  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046adb7  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046adbd  81c900002000           -or ecx, 0x200000
    cpu.ecx |= x86::reg32(x86::sreg32(2097152 /*0x200000*/));
    // 0046adc3  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046adc9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046adcf  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046add2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046add3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046add4  83c404                 +add esp, 4
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
    // 0046add7  e944f7fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046addc:
    // 0046addc  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ade2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ade3  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046ade6  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046adec  81e1ffffdfff           -and ecx, 0xffdfffff
    cpu.ecx &= x86::reg32(x86::sreg32(4292870143 /*0xffdfffff*/));
    // 0046adf2  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046adf8  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046adfe  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ae01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae03  83c404                 +add esp, 4
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
    // 0046ae06  e915f7fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046ae0b:
    // 0046ae0b  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046ae0f  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046ae15  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046ae17  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046ae1a  7b39                   -jnp 0x46ae55
    if (!cpu.flags.pf)
    {
        goto L_0x0046ae55;
    }
    // 0046ae1c  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ae22  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ae25  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046ae2b  83c902                 -or ecx, 2
    cpu.ecx |= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0046ae2e:
    // 0046ae2e  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046ae34  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ae39  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
L_0x0046ae3c:
    // 0046ae3c  e8dff6fdff             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0046ae41  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ae47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae48  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ae4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae4d  83c404                 +add esp, 4
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
    // 0046ae50  e9cbf6fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046ae55:
    // 0046ae55  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ae5b  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046ae5e  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046ae64  83e1fd                 +and ecx, 0xfffffffd
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/))));
    // 0046ae67  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046ae6d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ae73  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046ae76  ebc4                   -jmp 0x46ae3c
    goto L_0x0046ae3c;
  case 0x0046ae78:
    // 0046ae78  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046ae7c  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046ae82  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046ae84  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046ae87  7b2e                   -jnp 0x46aeb7
    if (!cpu.flags.pf)
    {
        goto L_0x0046aeb7;
    }
    // 0046ae89  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ae8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae8f  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046ae92  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046ae98  81c900004000           -or ecx, 0x400000
    cpu.ecx |= x86::reg32(x86::sreg32(4194304 /*0x400000*/));
    // 0046ae9e  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046aea4  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aeaa  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aead  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aeae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aeaf  83c404                 +add esp, 4
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
    // 0046aeb2  e969f6fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046aeb7:
    // 0046aeb7  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aebd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aebe  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046aec1  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046aec7  81e1ffffbfff           -and ecx, 0xffbfffff
    cpu.ecx &= x86::reg32(x86::sreg32(4290772991 /*0xffbfffff*/));
    // 0046aecd  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046aed3  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aed9  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aedc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aedd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aede  83c404                 +add esp, 4
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
    // 0046aee1  e93af6fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046aee6:
    // 0046aee6  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046aeea  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046aef0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046aef2  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046aef5  7b2f                   -jnp 0x46af26
    if (!cpu.flags.pf)
    {
        goto L_0x0046af26;
    }
    // 0046aef7  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046aefd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aefe  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046af01  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046af07  81c900000001           -or ecx, 0x1000000
    cpu.ecx |= x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
    // 0046af0d  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046af13  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046af19  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046af1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af1e  83c404                 +add esp, 4
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
    // 0046af21  e9faf5fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046af26:
    // 0046af26  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046af2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af2c  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046af2f  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046af35  81e1fffffffe           -and ecx, 0xfeffffff
    cpu.ecx &= x86::reg32(x86::sreg32(4278190079 /*0xfeffffff*/));
    // 0046af3b  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046af41  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046af47  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046af4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af4c  83c404                 +add esp, 4
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
    // 0046af4f  e9ccf5fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046af54:
    // 0046af54  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046af58  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046af5e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046af60  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046af63  7b63                   -jnp 0x46afc8
    if (!cpu.flags.pf)
    {
        goto L_0x0046afc8;
    }
    // 0046af65  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046af6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af6c  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046af6f  c7820c030000f0214100   -mov dword ptr [edx + 0x30c], 0x4121f0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(780) /* 0x30c */) = 4268528 /*0x4121f0*/;
    // 0046af79  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046af7e  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046af81  66c781240300003200     -mov word ptr [ecx + 0x324], 0x32
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(804) /* 0x324 */) = 50 /*0x32*/;
    // 0046af8a  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046af90  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046af93  c680b102000003         -mov byte ptr [eax + 0x2b1], 3
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(689) /* 0x2b1 */) = 3 /*0x3*/;
    // 0046af9a  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046afa0  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046afa3  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046afa9  81c900000002           -or ecx, 0x2000000
    cpu.ecx |= x86::reg32(x86::sreg32(33554432 /*0x2000000*/));
    // 0046afaf  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046afb5  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046afbb  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046afbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afc0  83c404                 +add esp, 4
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
    // 0046afc3  e958f5fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046afc8:
    // 0046afc8  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046afce  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046afd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afd1  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046afd4  89810c030000           -mov dword ptr [ecx + 0x30c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(780) /* 0x30c */) = cpu.eax;
    // 0046afda  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046afe0  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046afe3  8881b1020000           -mov byte ptr [ecx + 0x2b1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(689) /* 0x2b1 */) = cpu.al;
    // 0046afe9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046afef  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046aff2  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046aff8  81e1fffffffd           -and ecx, 0xfdffffff
    cpu.ecx &= x86::reg32(x86::sreg32(4261412863 /*0xfdffffff*/));
    // 0046affe  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046b004  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b00a  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b00d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b00e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b00f  83c404                 +add esp, 4
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
    // 0046b012  e909f5fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046b017:
    // 0046b017  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b01b  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046b021  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046b023  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046b026  7b2e                   -jnp 0x46b056
    if (!cpu.flags.pf)
    {
        goto L_0x0046b056;
    }
    // 0046b028  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b02d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b02e  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046b031  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046b037  81c900000008           -or ecx, 0x8000000
    cpu.ecx |= x86::reg32(x86::sreg32(134217728 /*0x8000000*/));
    // 0046b03d  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046b043  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b049  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b04c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b04d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b04e  83c404                 +add esp, 4
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
    // 0046b051  e9caf4fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046b056:
    // 0046b056  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b05c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b05d  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046b060  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0046b066  81e1fffffff7           -and ecx, 0xf7ffffff
    cpu.ecx &= x86::reg32(x86::sreg32(4160749567 /*0xf7ffffff*/));
    // 0046b06c  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046b072  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b078  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b07b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b07c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b07d  83c404                 +add esp, 4
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
    // 0046b080  e99bf4fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046b085:
    // 0046b085  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b089  e802bd0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b08e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b094  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b095  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b098  8881b2020000           -mov byte ptr [ecx + 0x2b2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(690) /* 0x2b2 */) = cpu.al;
    // 0046b09e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b0a4  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b0a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b0a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b0a9  83c404                 +add esp, 4
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
    // 0046b0ac  e96ff4fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046b0b1:
    // 0046b0b1  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b0b5  e8d6bc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b0ba  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046b0bc  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b0c1  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046b0c4  e8b7f7ffff             -call 0x46a880
    cpu.esp -= 4;
    sub_46a880(app, cpu);
    // 0046b0c9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b0cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b0d0  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b0d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b0d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b0d5  83c404                 +add esp, 4
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
    // 0046b0d8  e943f4fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046b0dd:
    // 0046b0dd  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b0e1  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046b0e7  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b0eb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046b0ed  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046b0f0  7b38                   -jnp 0x46b12a
    if (!cpu.flags.pf)
    {
        goto L_0x0046b12a;
    }
    // 0046b0f2  e899bc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b0f7  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b0fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b0fe  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046b101  66898224030000         -mov word ptr [edx + 0x324], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(804) /* 0x324 */) = cpu.ax;
    // 0046b108  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b10d  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046b110  c681b102000001         -mov byte ptr [ecx + 0x2b1], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(689) /* 0x2b1 */) = 1 /*0x1*/;
    // 0046b117  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b11d  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b120  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b121  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b122  83c404                 +add esp, 4
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
    // 0046b125  e9f6f3fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046b12a:
    // 0046b12a  e861bc0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b12f  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b135  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b136  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b139  66898124030000         -mov word ptr [ecx + 0x324], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(804) /* 0x324 */) = cpu.ax;
    // 0046b140  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b146  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b149  c680b102000000         -mov byte ptr [eax + 0x2b1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(689) /* 0x2b1 */) = 0 /*0x0*/;
    // 0046b150  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b156  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b159  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b15a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b15b  83c404                 +add esp, 4
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
    // 0046b15e  e9bdf3fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046b163:
    // 0046b163  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b167  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046b16d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046b16f  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046b172  7b27                   -jnp 0x46b19b
    if (!cpu.flags.pf)
    {
        goto L_0x0046b19b;
    }
    // 0046b174  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b17a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b17b  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046b17e  c7820c030000c0184100   -mov dword ptr [edx + 0x30c], 0x4118c0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(780) /* 0x30c */) = 4266176 /*0x4118c0*/;
    // 0046b188  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b18e  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b191  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b192  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b193  83c404                 +add esp, 4
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
    // 0046b196  e985f3fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
L_0x0046b19b:
    // 0046b19b  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b1a0  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046b1a3  81b80c030000c0184100   +cmp dword ptr [eax + 0x30c], 0x4118c0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(780) /* 0x30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4266176 /*0x4118c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x0046b1ad:
    // 0046b1ad  755d                   -jne 0x46b20c
    if (!cpu.flags.zf)
    {
        goto L_0x0046b20c;
    }
    // 0046b1af  c7800c03000000000000   -mov dword ptr [eax + 0x30c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(780) /* 0x30c */) = 0 /*0x0*/;
    // 0046b1b9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b1bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1c0  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b1c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1c5  83c404                 +add esp, 4
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
    // 0046b1c8  e953f3fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046b1cd:
    // 0046b1cd  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b1d1  e8babb0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b1d6  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b1dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1dd  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046b1e0  668982f0020000         -mov word ptr [edx + 0x2f0], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(752) /* 0x2f0 */) = cpu.ax;
    // 0046b1e7  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b1ed  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b1f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1f2  83c404                 +add esp, 4
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
    // 0046b1f5  e926f3fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  case 0x0046b1fa:
    // 0046b1fa  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b1ff  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0046b202  c7811003000080124100   -mov dword ptr [ecx + 0x310], 0x411280
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(784) /* 0x310 */) = 4264576 /*0x411280*/;
L_0x0046b20c:
    // 0046b20c  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b212  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b213  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0046b216  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b217  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b218  83c404                 +add esp, 4
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
    // 0046b21b  e900f3fdff             -jmp 0x44a520
    return sub_44a520(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_46b280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b281  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 0046b285  e8f6b3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b28a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b28c  e89fa4ffff             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0046b291  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b295  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046b29b  d91c81                 -fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b29e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b29f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b2a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b2a1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b2a3  e8d8b3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b2a8  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b2ac  e84fb4ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046b2b1  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046b2b5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046b2b8  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b2bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b2bc  68002f4a00             -push 0x4a2f00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861696 /*0x4a2f00*/;
    cpu.esp -= 4;
    // 0046b2c1  e8f1ba0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046b2c6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046b2c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b2d0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b2d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b2d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b2d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b2d6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b2d8  e8a3b3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b2dd  e8aeba0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b2e2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b2e4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b2e6  e895b3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b2eb  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b2ef  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b2f1  e88ab3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b2f6  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b2fa  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b2fc  e87fb3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b301  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b305  e8f6b3ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046b30a  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046b30c  e8efb3ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046b311  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b315  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b316  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046b318  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046b31b  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b31f  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0046b323  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b327  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0046b32b  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b32e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b32f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b330  68082f4a00             -push 0x4a2f08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861704 /*0x4a2f08*/;
    cpu.esp -= 4;
    // 0046b335  e87dba0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046b33a  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046b33e  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046b342  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046b346  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046b349  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b34a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b34b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b34c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b34d  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046b34f  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046b351  e82a99fbff             -call 0x424c80
    cpu.esp -= 4;
    sub_424c80(app, cpu);
    // 0046b356  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b357  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b358  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b359  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b35c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b360  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b361  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b362  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b364  e817b3ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b369  e822ba0000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b36e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b370  e88bb3ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046b375  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046b377  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046b379  750d                   -jne 0x46b388
    if (!cpu.flags.zf)
    {
        goto L_0x0046b388;
    }
    // 0046b37b  68402f4a00             -push 0x4a2f40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861760 /*0x4a2f40*/;
    cpu.esp -= 4;
    // 0046b380  e88b98fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046b385  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046b388:
    // 0046b388  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b389  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b38a  68282f4a00             -push 0x4a2f28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861736 /*0x4a2f28*/;
    cpu.esp -= 4;
    // 0046b38f  e823ba0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046b394  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b397  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046b399  b94cbb4a00             -mov ecx, 0x4abb4c
    cpu.ecx = 4897612 /*0x4abb4c*/;
    // 0046b39e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b39f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046b3a1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046b3a3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046b3a5  e8d698fbff             -call 0x424c80
    cpu.esp -= 4;
    sub_424c80(app, cpu);
    // 0046b3aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b3ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b3ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b3b0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b3b3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b3b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b3b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b3b6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b3b8  e8c3b2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b3bd  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 0046b3c3  e8c8b90000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b3c8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b3ca  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046b3cc  e8afb2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b3d1  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b3d5  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b3d7  e8a4b2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b3dc  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b3e0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b3e2  e899b2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b3e7  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b3eb  e810b3ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046b3f0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b3f2  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046b3f5  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046b3f7  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046b3f9  f2ae                   +repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046b3fb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046b3fd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046b3fe  750b                   -jne 0x46b40b
    if (!cpu.flags.zf)
    {
        goto L_0x0046b40b;
    }
    // 0046b400  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b401  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b402  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b403  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046b406  e9c5a5fbff             -jmp 0x4259d0
    return sub_4259d0(app, cpu);
L_0x0046b40b:
    // 0046b40b  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046b40f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b410  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046b413  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b417  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0046b41b  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b41f  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0046b423  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b426  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b427  686c2f4a00             -push 0x4a2f6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861804 /*0x4a2f6c*/;
    cpu.esp -= 4;
    // 0046b42c  e886b90000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046b431  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046b435  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046b439  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046b43d  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046b440  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b443  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046b445  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046b447  e8e4a2fbff             -call 0x425730
    cpu.esp -= 4;
    sub_425730(app, cpu);
    // 0046b44c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b44d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b44e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b44f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b452  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b460  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0046b466  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b467  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b468  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b469  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046b46b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b46c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b46e  e80db2ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b473  e818b90000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b478  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b47a  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046b47c  e8ffb1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b481  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b485  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b487  e8f4b1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b48c  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b490  e86bb2ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046b495  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b497  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046b499  e8e2b1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b49e  e8edb80000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b4a3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b4a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b4a6  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046b4aa  68902f4a00             -push 0x4a2f90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861840 /*0x4a2f90*/;
    cpu.esp -= 4;
    // 0046b4af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b4b0  e843b90000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046b4b5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b4b8  83feff                 +cmp esi, -1
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
    // 0046b4bb  7505                   -jne 0x46b4c2
    if (!cpu.flags.zf)
    {
        goto L_0x0046b4c2;
    }
    // 0046b4bd  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046b4c0  eb09                   -jmp 0x46b4cb
    goto L_0x0046b4cb;
L_0x0046b4c2:
    // 0046b4c2  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b4c8  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
L_0x0046b4cb:
    // 0046b4cb  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046b4cf  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b4d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b4d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b4d5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046b4d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b4d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b4d9  7514                   -jne 0x46b4ef
    if (!cpu.flags.zf)
    {
        goto L_0x0046b4ef;
    }
    // 0046b4db  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046b4dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b4de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b4df  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b4e3  e8a883ffff             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0046b4e8  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0046b4ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b4ef:
    // 0046b4ef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046b4f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b4f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b4f3  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b4f7  e89483ffff             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 0046b4fc  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0046b502  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b510  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046b516  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b517  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b518  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b519  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046b51b  e8e0b1ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046b520  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b522  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046b524  e857b1ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b529  e862b80000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b52e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b530  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b531  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046b535  68902f4a00             -push 0x4a2f90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4861840 /*0x4a2f90*/;
    cpu.esp -= 4;
    // 0046b53a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b53b  e8b8b80000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0046b540  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b543  83feff                 +cmp esi, -1
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
    // 0046b546  7516                   -jne 0x46b55e
    if (!cpu.flags.zf)
    {
        goto L_0x0046b55e;
    }
    // 0046b548  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046b54b  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b54f  e8fc83ffff             -call 0x463950
    cpu.esp -= 4;
    sub_463950(app, cpu);
    // 0046b554  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b555  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b556  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b557  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046b55d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b55e:
    // 0046b55e  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b564  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0046b567  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b56b  e8e083ffff             -call 0x463950
    cpu.esp -= 4;
    sub_463950(app, cpu);
    // 0046b570  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b571  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b572  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b573  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046b579  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b580  e9dbbefaff             -jmp 0x417460
    return sub_417460(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46b590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b590  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b591  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b592  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b594  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b596  e8e5b0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b59b  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b59f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b5a1  e8dab0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b5a6  d815ec724800           -fcom dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    // 0046b5ac  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046b5af  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046b5b1  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046b5b4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b5b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b5b9  7a10                   -jp 0x46b5cb
    if (cpu.flags.pf)
    {
        goto L_0x0046b5cb;
    }
    // 0046b5bb  8d5148                 -lea edx, [ecx + 0x48]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0046b5be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b5bf  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b5c1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b5c3  e8983bfeff             -call 0x44f160
    cpu.esp -= 4;
    sub_44f160(app, cpu);
    // 0046b5c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b5cb:
    // 0046b5cb  83c148                 -add ecx, 0x48
    (cpu.ecx) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0046b5ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b5cf  e8bcb70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b5d4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b5da  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b5dc  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046b5df  e87c3bfeff             -call 0x44f160
    cpu.esp -= 4;
    sub_44f160(app, cpu);
    // 0046b5e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b5f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b5f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b5f2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b5f4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b5f6  e885b0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b5fb  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b5ff  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b601  e87ab0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b606  d815ec724800           -fcom dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    // 0046b60c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046b60f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046b611  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046b614  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b618  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b619  7a10                   -jp 0x46b62b
    if (cpu.flags.pf)
    {
        goto L_0x0046b62b;
    }
    // 0046b61b  8d5170                 -lea edx, [ecx + 0x70]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 0046b61e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b61f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b621  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b623  e8383bfeff             -call 0x44f160
    cpu.esp -= 4;
    sub_44f160(app, cpu);
    // 0046b628  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b629  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b62a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b62b:
    // 0046b62b  83c170                 -add ecx, 0x70
    (cpu.ecx) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0046b62e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b62f  e85cb70000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b634  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b63a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b63c  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046b63f  e81c3bfeff             -call 0x44f160
    cpu.esp -= 4;
    sub_44f160(app, cpu);
    // 0046b644  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b645  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b650  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b652  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b654  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b656  e825b0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b65b  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b65f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b661  e81ab0ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b666  d815ec724800           -fcom dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    // 0046b66c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046b66f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046b671  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046b674  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b678  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b679  7a10                   -jp 0x46b68b
    if (cpu.flags.pf)
    {
        goto L_0x0046b68b;
    }
    // 0046b67b  8d5120                 -lea edx, [ecx + 0x20]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046b67e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b67f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b681  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b683  e8d83afeff             -call 0x44f160
    cpu.esp -= 4;
    sub_44f160(app, cpu);
    // 0046b688  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b689  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b68a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b68b:
    // 0046b68b  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046b68e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b68f  e8fcb60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b694  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b69a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b69c  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046b69f  e8bc3afeff             -call 0x44f160
    cpu.esp -= 4;
    sub_44f160(app, cpu);
    // 0046b6a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b6a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b6a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b6b0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b6b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b6b4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b6b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b6b7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b6b9  e8c2afffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b6be  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b6c2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b6c4  e8b7afffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b6c9  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b6cd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b6cf  e8acafffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b6d4  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b6d8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b6da  e8a1afffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b6df  d815ec724800           -fcom dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    // 0046b6e5  8b3d30845100           -mov edi, dword ptr [0x518430]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b6eb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046b6ed  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046b6f0  7a07                   -jp 0x46b6f9
    if (cpu.flags.pf)
    {
        goto L_0x0046b6f9;
    }
    // 0046b6f2  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046b6f5  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b6f7  eb08                   -jmp 0x46b701
    goto L_0x0046b701;
L_0x0046b6f9:
    // 0046b6f9  e892b60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b6fe  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
L_0x0046b701:
    // 0046b701  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b705  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b709  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b70a  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b70e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b70f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046b711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b712  8b0c97                 -mov ecx, dword ptr [edi + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + cpu.edx * 4);
    // 0046b715  e8263ffeff             -call 0x44f640
    cpu.esp -= 4;
    sub_44f640(app, cpu);
    // 0046b71a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b71b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b71c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b71f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b720  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046b723  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b724  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b725  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046b727  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b728  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b72a  e851afffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b72f  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b733  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b735  e846afffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b73a  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b73e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b740  e83bafffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b745  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b749  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b74b  e830afffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b750  e83bb60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b755  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b757  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b759  e822afffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b75e  e82db60000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b763  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b769  83f8ff                 +cmp eax, -1
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
    // 0046b76c  7505                   -jne 0x46b773
    if (!cpu.flags.zf)
    {
        goto L_0x0046b773;
    }
    // 0046b76e  8b7b14                 -mov edi, dword ptr [ebx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046b771  eb03                   -jmp 0x46b776
    goto L_0x0046b776;
L_0x0046b773:
    // 0046b773  8b3c81                 -mov edi, dword ptr [ecx + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046b776:
    // 0046b776  83feff                 +cmp esi, -1
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
    // 0046b779  7505                   -jne 0x46b780
    if (!cpu.flags.zf)
    {
        goto L_0x0046b780;
    }
    // 0046b77b  8b7314                 -mov esi, dword ptr [ebx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0046b77e  eb03                   -jmp 0x46b783
    goto L_0x0046b783;
L_0x0046b780:
    // 0046b780  8b34b1                 -mov esi, dword ptr [ecx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
L_0x0046b783:
    // 0046b783  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046b787  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b78b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b78f  898ed4000000           -mov dword ptr [esi + 0xd4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */) = cpu.ecx;
    // 0046b795  8996d8000000           -mov dword ptr [esi + 0xd8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */) = cpu.edx;
    // 0046b79b  8d96cc000000           -lea edx, [esi + 0xcc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0046b7a1  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046b7a3  8986d0000000           -mov dword ptr [esi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 0046b7a9  e86245feff             -call 0x44fd10
    cpu.esp -= 4;
    sub_44fd10(app, cpu);
    // 0046b7ae  d987d0000000           -fld dword ptr [edi + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(208) /* 0xd0 */)));
    // 0046b7b4  d886d0000000           -fadd dword ptr [esi + 0xd0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */));
    // 0046b7ba  8b87e8020000           -mov eax, dword ptr [edi + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(744) /* 0x2e8 */);
    // 0046b7c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b7c2  d954241c               +fst dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    // 0046b7c6  d987d4000000           +fld dword ptr [edi + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(212) /* 0xd4 */)));
    // 0046b7cc  d886d4000000           +fadd dword ptr [esi + 0xd4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */));
    // 0046b7d2  d9542420               +fst dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    // 0046b7d6  d987d8000000           +fld dword ptr [edi + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(216) /* 0xd8 */)));
    // 0046b7dc  d886d8000000           +fadd dword ptr [esi + 0xd8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(216) /* 0xd8 */));
    // 0046b7e2  d9542424               +fst dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    // 0046b7e6  7432                   -je 0x46b81a
    if (cpu.flags.zf)
    {
        goto L_0x0046b81a;
    }
L_0x0046b7e8:
    // 0046b7e8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0046b7ea  d880d0000000           -fadd dword ptr [eax + 0xd0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */));
    // 0046b7f0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0046b7f2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046b7f4  d880d4000000           -fadd dword ptr [eax + 0xd4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */));
    // 0046b7fa  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046b7fc  d880d8000000           -fadd dword ptr [eax + 0xd8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */));
    // 0046b802  8b80e8020000           -mov eax, dword ptr [eax + 0x2e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(744) /* 0x2e8 */);
    // 0046b808  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b80a  75dc                   -jne 0x46b7e8
    if (!cpu.flags.zf)
    {
        goto L_0x0046b7e8;
    }
    // 0046b80c  d95c2424               +fstp dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b810  d95c2420               +fstp dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b814  d95c241c               +fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b818  eb06                   -jmp 0x46b820
    goto L_0x0046b820;
L_0x0046b81a:
    // 0046b81a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b81c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b81e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046b820:
    // 0046b820  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046b824  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046b828  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046b82c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b82d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046b82f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b830  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b836  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b837  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046b83a  e8c13efeff             -call 0x44f700
    cpu.esp -= 4;
    sub_44f700(app, cpu);
    // 0046b83f  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0046b842  895624                 -mov dword ptr [esi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0046b845  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0046b848  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0046b84b  8b4f2c                 -mov ecx, dword ptr [edi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 0046b84e  894e2c                 -mov dword ptr [esi + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0046b851  8b574c                 -mov edx, dword ptr [edi + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */);
    // 0046b854  89564c                 -mov dword ptr [esi + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0046b857  8b4750                 -mov eax, dword ptr [edi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 0046b85a  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0046b85d  8b4f54                 -mov ecx, dword ptr [edi + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 0046b860  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 0046b863  8b5774                 -mov edx, dword ptr [edi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */);
    // 0046b866  895674                 -mov dword ptr [esi + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0046b869  8b4778                 -mov eax, dword ptr [edi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0046b86c  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0046b86f  8b4f7c                 -mov ecx, dword ptr [edi + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(124) /* 0x7c */);
    // 0046b872  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 0046b875  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046b877  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b878  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b879  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b87a  83c434                 +add esp, 0x34
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046b87d  e96e3dfeff             -jmp 0x44f5f0
    return sub_44f5f0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46b890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b890  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b891  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b892  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b894  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b898  e8e3adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b89d  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046b8a0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b8a4  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046b8aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8ab  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b8ad  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 0046b8af  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b8b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46b8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b8c0  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046b8c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b8c4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b8c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b8c7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b8c9  e8b2adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b8ce  e8bdb40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b8d3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b8d5  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046b8d7  e8a4adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b8dc  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b8e0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b8e2  e899adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b8e7  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b8eb  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b8ed  e88eadffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b8f2  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b8f6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b8f8  e883adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b8fd  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b901  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b903  e878adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b908  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b90c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b90e  e86dadffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b913  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b917  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b919  e862adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b91e  e86db40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b923  83f8ff                 +cmp eax, -1
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
    // 0046b926  7505                   -jne 0x46b92d
    if (!cpu.flags.zf)
    {
        goto L_0x0046b92d;
    }
    // 0046b928  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046b92b  eb09                   -jmp 0x46b936
    goto L_0x0046b936;
L_0x0046b92d:
    // 0046b92d  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b933  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046b936:
    // 0046b936  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b93a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b93e  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046b942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b943  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046b947  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b948  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046b94c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b94d  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046b951  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b952  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b953  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b954  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046b956  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046b958  e8237dfaff             -call 0x413680
    cpu.esp -= 4;
    sub_413680(app, cpu);
    // 0046b95d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046b95f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b960  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b961  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046b964  e9877cfaff             -jmp 0x4135f0
    return sub_4135f0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46b970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b970  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046b973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b974  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b976  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b977  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b979  e802adffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b97e  e80db40000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b983  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b985  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046b987  e8f4acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b98c  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b990  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b992  e8e9acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b997  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b99b  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b99d  e8deacffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b9a2  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b9a6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b9a8  e8d3acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b9ad  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b9b1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b9b3  e8c8acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b9b8  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b9bc  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b9be  e8bdacffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b9c3  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046b9c7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b9c9  e8b2acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046b9ce  e8bdb30000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046b9d3  83f8ff                 +cmp eax, -1
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
    // 0046b9d6  7505                   -jne 0x46b9dd
    if (!cpu.flags.zf)
    {
        goto L_0x0046b9dd;
    }
    // 0046b9d8  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046b9db  eb09                   -jmp 0x46b9e6
    goto L_0x0046b9e6;
L_0x0046b9dd:
    // 0046b9dd  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046b9e3  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046b9e6:
    // 0046b9e6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b9ea  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b9ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b9ef  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b9f3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b9f4  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046b9f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b9f9  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046b9fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b9fe  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046ba02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ba03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ba04  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046ba06  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046ba08  e8437efaff             -call 0x413850
    cpu.esp -= 4;
    sub_413850(app, cpu);
    // 0046ba0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba0f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046ba12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46ba20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ba20  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046ba23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ba24  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046ba26  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ba28  e853acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ba2d  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ba31  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ba33  e848acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ba38  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ba3c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ba3e  e83dacffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ba43  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ba47  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ba49  e832acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ba4e  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ba52  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ba54  e827acffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046ba59  e832b30000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046ba5e  83f8ff                 +cmp eax, -1
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
    // 0046ba61  7505                   -jne 0x46ba68
    if (!cpu.flags.zf)
    {
        goto L_0x0046ba68;
    }
    // 0046ba63  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046ba66  eb09                   -jmp 0x46ba71
    goto L_0x0046ba71;
L_0x0046ba68:
    // 0046ba68  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046ba6e  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046ba71:
    // 0046ba71  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ba75  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ba79  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ba7a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ba7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ba7f  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046ba83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ba84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ba85  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046ba87  e8547afaff             -call 0x4134e0
    cpu.esp -= 4;
    sub_4134e0(app, cpu);
    // 0046ba8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba8d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046ba90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46baa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046baa0  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046baa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046baa4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046baa6  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046baa8  e8d3abffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046baad  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bab1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bab3  e8c8abffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bab8  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046babc  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046babe  e8bdabffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bac3  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bac7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bac9  e8b2abffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bace  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bad2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bad4  e8a7abffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bad9  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046badd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046badf  e89cabffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bae4  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bae8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046baea  e891abffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046baef  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046baf3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046baf5  e886abffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bafa  e891b20000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046baff  83f8ff                 +cmp eax, -1
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
    // 0046bb02  7505                   -jne 0x46bb09
    if (!cpu.flags.zf)
    {
        goto L_0x0046bb09;
    }
    // 0046bb04  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046bb07  eb09                   -jmp 0x46bb12
    goto L_0x0046bb12;
L_0x0046bb09:
    // 0046bb09  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bb0f  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046bb12:
    // 0046bb12  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046bb16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bb18  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046bb1a  e871b20000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bb1f  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0046bb23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046bb24  e867b20000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bb29  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046bb2d  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046bb31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bb32  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046bb36  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bb37  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046bb3b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bb3c  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046bb40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bb41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bb42  8ad0                   -mov dl, al
    cpu.dl = cpu.al;
    // 0046bb44  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046bb46  e86539faff             -call 0x40f4b0
    cpu.esp -= 4;
    sub_40f4b0(app, cpu);
    // 0046bb4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb4c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046bb4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46bb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bb50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bb51  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046bb53  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bb55  e826abffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bb5a  e831b20000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bb5f  83f8ff                 +cmp eax, -1
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
    // 0046bb62  750b                   -jne 0x46bb6f
    if (!cpu.flags.zf)
    {
        goto L_0x0046bb6f;
    }
    // 0046bb64  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046bb67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb68  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bb6a  e9413cfaff             -jmp 0x40f7b0
    return sub_40f7b0(app, cpu);
L_0x0046bb6f:
    // 0046bb6f  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bb75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb76  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0046bb79  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bb7b  e9303cfaff             -jmp 0x40f7b0
    return sub_40f7b0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_46bb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bb80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bb81  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046bb83  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bb85  e8f6aaffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bb8a  e801b20000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bb8f  83f8ff                 +cmp eax, -1
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
    // 0046bb92  7505                   -jne 0x46bb99
    if (!cpu.flags.zf)
    {
        goto L_0x0046bb99;
    }
    // 0046bb94  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046bb97  eb09                   -jmp 0x46bba2
    goto L_0x0046bba2;
L_0x0046bb99:
    // 0046bb99  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bb9f  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046bba2:
    // 0046bba2  8a86b1020000           -mov al, byte ptr [esi + 0x2b1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(689) /* 0x2b1 */);
    // 0046bba8  8b96a8020000           -mov edx, dword ptr [esi + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 0046bbae  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0046bbb0  81e2fffffff7           -and edx, 0xf7ffffff
    cpu.edx &= x86::reg32(x86::sreg32(4160749567 /*0xf7ffffff*/));
    // 0046bbb6  8886b1020000           -mov byte ptr [esi + 0x2b1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(689) /* 0x2b1 */) = cpu.al;
    // 0046bbbc  8b86ec020000           -mov eax, dword ptr [esi + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(748) /* 0x2ec */);
    // 0046bbc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bbc4  66c786240300006400     -mov word ptr [esi + 0x324], 0x64
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(804) /* 0x324 */) = 100 /*0x64*/;
    // 0046bbcd  8996a8020000           -mov dword ptr [esi + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0046bbd3  742f                   -je 0x46bc04
    if (cpu.flags.zf)
    {
        goto L_0x0046bc04;
    }
    // 0046bbd5  f6404a01               +test byte ptr [eax + 0x4a], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(74) /* 0x4a */) & 1 /*0x1*/));
    // 0046bbd9  7429                   -je 0x46bc04
    if (cpu.flags.zf)
    {
        goto L_0x0046bc04;
    }
    // 0046bbdb  8b860c030000           -mov eax, dword ptr [esi + 0x30c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(780) /* 0x30c */);
    // 0046bbe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bbe3  741f                   -je 0x46bc04
    if (cpu.flags.zf)
    {
        goto L_0x0046bc04;
    }
    // 0046bbe5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bbe7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bbe9  68003c1c46             -push 0x461c3c00
    app->getMemory<x86::reg32>(cpu.esp-4) = 1176255488 /*0x461c3c00*/;
    cpu.esp -= 4;
    // 0046bbee  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bbf0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046bbf2  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046bbf4  8a86b1020000           -mov al, byte ptr [esi + 0x2b1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(689) /* 0x2b1 */);
    // 0046bbfa  24fd                   -and al, 0xfd
    cpu.al &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0046bbfc  8886b1020000           -mov byte ptr [esi + 0x2b1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(689) /* 0x2b1 */) = cpu.al;
    // 0046bc02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bc04:
    // 0046bc04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bc06  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bc08  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bc0a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046bc0c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bc0d  e8de65faff             -call 0x4121f0
    cpu.esp -= 4;
    sub_4121f0(app, cpu);
    // 0046bc12  8a86b1020000           -mov al, byte ptr [esi + 0x2b1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(689) /* 0x2b1 */);
    // 0046bc18  24fd                   -and al, 0xfd
    cpu.al &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0046bc1a  8886b1020000           -mov byte ptr [esi + 0x2b1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(689) /* 0x2b1 */) = cpu.al;
    // 0046bc20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46bc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bc30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bc31  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046bc33  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bc35  e846aaffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bc3a  e851b10000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bc3f  83f8ff                 +cmp eax, -1
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
    // 0046bc42  7505                   -jne 0x46bc49
    if (!cpu.flags.zf)
    {
        goto L_0x0046bc49;
    }
    // 0046bc44  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046bc47  eb09                   -jmp 0x46bc52
    goto L_0x0046bc52;
L_0x0046bc49:
    // 0046bc49  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bc4f  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046bc52:
    // 0046bc52  8bb1a8020000           -mov esi, dword ptr [ecx + 0x2a8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0046bc58  8b81ec020000           -mov eax, dword ptr [ecx + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(748) /* 0x2ec */);
    // 0046bc5e  81e6fffffff7           -and esi, 0xf7ffffff
    cpu.esi &= x86::reg32(x86::sreg32(4160749567 /*0xf7ffffff*/));
    // 0046bc64  89b1a8020000           -mov dword ptr [ecx + 0x2a8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = cpu.esi;
    // 0046bc6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bc6d  741e                   -je 0x46bc8d
    if (cpu.flags.zf)
    {
        goto L_0x0046bc8d;
    }
    // 0046bc6f  f6404a01               +test byte ptr [eax + 0x4a], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(74) /* 0x4a */) & 1 /*0x1*/));
    // 0046bc73  7418                   -je 0x46bc8d
    if (cpu.flags.zf)
    {
        goto L_0x0046bc8d;
    }
    // 0046bc75  8b810c030000           -mov eax, dword ptr [ecx + 0x30c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(780) /* 0x30c */);
    // 0046bc7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bc7d  740e                   -je 0x46bc8d
    if (cpu.flags.zf)
    {
        goto L_0x0046bc8d;
    }
    // 0046bc7f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bc81  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bc83  6800381c46             -push 0x461c3800
    app->getMemory<x86::reg32>(cpu.esp-4) = 1176254464 /*0x461c3800*/;
    cpu.esp -= 4;
    // 0046bc88  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bc8a  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046bc8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bc8d:
    // 0046bc8d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bc8f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bc91  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046bc93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bc94  e85765faff             -call 0x4121f0
    cpu.esp -= 4;
    sub_4121f0(app, cpu);
    // 0046bc99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_46bca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bca0  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0046bca3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bca4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046bca6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bca7  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046bcab  e8d0a9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bcb0  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bcb2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bcb4  e8c7a9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bcb9  e8d2b00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bcbe  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bcc0  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046bcc2  e8b9a9ffff             -call 0x466680
    cpu.esp -= 4;
    sub_466680(app, cpu);
    // 0046bcc7  e8c4b00000             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0046bccc  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046bcd2  83f8ff                 +cmp eax, -1
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
    // 0046bcd5  7505                   -jne 0x46bcdc
    if (!cpu.flags.zf)
    {
        goto L_0x0046bcdc;
    }
    // 0046bcd7  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046bcda  eb03                   -jmp 0x46bcdf
    goto L_0x0046bcdf;
L_0x0046bcdc:
    // 0046bcdc  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
L_0x0046bcdf:
    // 0046bcdf  8b0cb9                 -mov ecx, dword ptr [ecx + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edi * 4);
    // 0046bce2  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0046bce8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046bcec  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0046bcf2  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046bcf6  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0046bcfc  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046bd00  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046bd04  e8a72fffff             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0046bd09  8b8ed0000000           -mov ecx, dword ptr [esi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 0046bd0f  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0046bd13  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0046bd19  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0046bd1d  8b86d8000000           -mov eax, dword ptr [esi + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 0046bd23  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046bd27  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046bd29  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0046bd2d  e87e2fffff             -call 0x45ecb0
    cpu.esp -= 4;
    sub_45ecb0(app, cpu);
    // 0046bd32  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0046bd36  d8642438               -fsub dword ptr [esp + 0x38]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */));
    // 0046bd3a  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046bd3e  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bd42  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0046bd46  d864243c               -fsub dword ptr [esp + 0x3c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */));
    // 0046bd4a  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bd4e  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0046bd52  d8642440               -fsub dword ptr [esp + 0x40]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */));
    // 0046bd56  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bd5a  e8310ffeff             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 0046bd5f  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046bd63  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046bd69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd6b  d91c8a                 -fstp dword ptr [edx + ecx*4]
    app->getMemory<float>(cpu.edx + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046bd6e  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0046bd71  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
