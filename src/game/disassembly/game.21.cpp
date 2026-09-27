#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_47d282(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047d282;
    // 0047d22d  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047d230  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d232  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d234  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047d238  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047d23b  3bdf                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d23d  74b4                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        return sub_47d1f3(app, cpu);
    }
    // 0047d23f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d241  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047d244  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d247  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d24a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d24d  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d253  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d255  749c                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        return sub_47d1f3(app, cpu);
    }
    // 0047d257  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d25a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d25b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d25c  7504                   -jne 0x47d262
    if (!cpu.flags.zf)
    {
        goto L_0x0047d262;
    }
    // 0047d25e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d25f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d260  eb06                   -jmp 0x47d268
    goto L_0x0047d268;
L_0x0047d262:
    // 0047d262  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047d265  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x0047d268:
    // 0047d268  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d269  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d26a  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 0047d26f  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047d272  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d278  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d27a  3bf7                   +cmp esi, edi
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
    // 0047d27c  0f8471ffffff           -je 0x47d1f3
    if (cpu.flags.zf)
    {
        return sub_47d1f3(app, cpu);
    }
L_entry_0x0047d282:
    // 0047d282  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d284  e96cffffff             -jmp 0x47d1f5
    return sub_47d1f5(app, cpu);
}

/* align: skip  */
void Application::sub_47d289(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d289  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d28a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047d28c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d28d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d290  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047d293  81f900010000           +cmp ecx, 0x100
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d299  770c                   -ja 0x47d2a7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047d2a7;
    }
    // 0047d29b  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d2a1  0fb70441               -movzx eax, word ptr [ecx + eax*2]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2));
    // 0047d2a5  eb52                   -jmp 0x47d2f9
    goto L_0x0047d2f9;
L_0x0047d2a7:
    // 0047d2a7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d2a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d2aa  8b350c624a00           -mov esi, dword ptr [0x4a620c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d2b0  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0047d2b3  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 0047d2b6  f644560180             +test byte ptr [esi + edx*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edx * 2) & 128 /*0x80*/));
    // 0047d2bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2bc  740e                   -je 0x47d2cc
    if (cpu.flags.zf)
    {
        goto L_0x0047d2cc;
    }
    // 0047d2be  8065fe00               +and byte ptr [ebp - 2], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-2) /* -0x2 */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0047d2c2  884dfc                 -mov byte ptr [ebp - 4], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.cl;
    // 0047d2c5  8845fd                 -mov byte ptr [ebp - 3], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 0047d2c8  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047d2ca  eb09                   -jmp 0x47d2d5
    goto L_0x0047d2d5;
L_0x0047d2cc:
    // 0047d2cc  8065fd00               -and byte ptr [ebp - 3], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d2d0  8845fc                 -mov byte ptr [ebp - 4], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0047d2d3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
L_0x0047d2d5:
    // 0047d2d5  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2d6  8d4d0a                 -lea ecx, [ebp + 0xa]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(10) /* 0xa */);
    // 0047d2d9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d2db  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d2dd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d2df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d2e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d2e1  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047d2e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d2e5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d2e7  e84e550000             -call 0x48283a
    cpu.esp -= 4;
    sub_48283a(app, cpu);
    // 0047d2ec  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047d2ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d2f1  7502                   -jne 0x47d2f5
    if (!cpu.flags.zf)
    {
        goto L_0x0047d2f5;
    }
    // 0047d2f3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d2f5:
    // 0047d2f5  0fb7450a               -movzx eax, word ptr [ebp + 0xa]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */));
L_0x0047d2f9:
    // 0047d2f9  23450c                 -and eax, dword ptr [ebp + 0xc]
    cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047d2fc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__freebuf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d2fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d2ff  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d303  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047d306  a883                   +test al, 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 131 /*0x83*/));
    // 0047d308  741d                   -je 0x47d327
    if (cpu.flags.zf)
    {
        goto L_0x0047d327;
    }
    // 0047d30a  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0047d30c  7419                   -je 0x47d327
    if (cpu.flags.zf)
    {
        goto L_0x0047d327;
    }
    // 0047d30e  ff7608                 -push dword ptr [esi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d311  e89ea0ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047d316  6681660cf7fb           -and word ptr [esi + 0xc], 0xfbf7
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(64503 /*0xfbf7*/));
    // 0047d31c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d31e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d31f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047d321  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047d324  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0047d327:
    // 0047d327  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d328  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d329(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d329  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d32a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047d32c  81ecc4010000           -sub esp, 0x1c4
    (cpu.esp) -= x86::reg32(x86::sreg32(452 /*0x1c4*/));
    // 0047d332  8065eb00               -and byte ptr [ebp - 0x15], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d336  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d337  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d338  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047d33b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d33d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d33e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d340  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0047d343  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047d345  895dcc                 -mov dword ptr [ebp - 0x34], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.ebx;
    // 0047d348  0f84e1090000           -je 0x47dd2f
    if (cpu.flags.zf)
    {
        goto L_0x0047dd2f;
    }
    // 0047d34e  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d351  eb05                   -jmp 0x47d358
    goto L_0x0047d358;
L_0x0047d353:
    // 0047d353  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d356  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047d358:
    // 0047d358  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d35f  7e0f                   -jle 0x47d370
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d370;
    }
    // 0047d361  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0047d364  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0047d366  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d367  e81dffffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047d36c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d36d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d36e  eb0f                   -jmp 0x47d37f
    goto L_0x0047d37f;
L_0x0047d370:
    // 0047d370  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d376  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0047d379  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0047d37c  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0047d37f:
    // 0047d37f  3bc3                   +cmp eax, ebx
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
    // 0047d381  7436                   -je 0x47d3b9
    if (cpu.flags.zf)
    {
        goto L_0x0047d3b9;
    }
    // 0047d383  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047d386  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d387  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047d38a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d38b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d38c  e8250a0000             -call 0x47ddb6
    cpu.esp -= 4;
    sub_47ddb6(app, cpu);
    // 0047d391  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d392  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d393  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d394  e8060a0000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047d399  0fb64601               -movzx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0047d39d  46                     -inc esi
    (cpu.esi)++;
    // 0047d39e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d39f  e8df550000             -call 0x482983
    cpu.esp -= 4;
    sub_482983(app, cpu);
    // 0047d3a4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0047d3a7:
    // 0047d3a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d3a9  740e                   -je 0x47d3b9
    if (cpu.flags.zf)
    {
        goto L_0x0047d3b9;
    }
    // 0047d3ab  0fb64601               -movzx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0047d3af  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d3b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d3b1  e8cd550000             -call 0x482983
    cpu.esp -= 4;
    sub_482983(app, cpu);
    // 0047d3b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d3b7  ebee                   -jmp 0x47d3a7
    goto L_0x0047d3a7;
L_0x0047d3b9:
    // 0047d3b9  803e25                 +cmp byte ptr [esi], 0x25
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d3bc  0f85d9080000           -jne 0x47dc9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc9b;
    }
    // 0047d3c2  8065cb00               -and byte ptr [ebp - 0x35], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-53) /* -0x35 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d3c6  8065e800               -and byte ptr [ebp - 0x18], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d3ca  8065e900               -and byte ptr [ebp - 0x17], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d3ce  8065f200               -and byte ptr [ebp - 0xe], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d3d2  8065f100               -and byte ptr [ebp - 0xf], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d3d6  8065ea00               -and byte ptr [ebp - 0x16], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d3da  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d3dc  8065fb00               -and byte ptr [ebp - 5], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d3e0  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 0047d3e3  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0047d3e6  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0047d3e9  c645f301               -mov byte ptr [ebp - 0xd], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */) = 1 /*0x1*/;
    // 0047d3ed  895dd0                 -mov dword ptr [ebp - 0x30], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.ebx;
L_0x0047d3f0:
    // 0047d3f0  0fb65e01               -movzx ebx, byte ptr [esi + 1]
    cpu.ebx = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0047d3f4  46                     -inc esi
    (cpu.esi)++;
    // 0047d3f5  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d3fc  7e0f                   -jle 0x47d40d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d40d;
    }
    // 0047d3fe  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0047d401  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047d403  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d404  e880feffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047d409  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d40a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d40b  eb0f                   -jmp 0x47d41c
    goto L_0x0047d41c;
L_0x0047d40d:
    // 0047d40d  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d413  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0047d416  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0047d419  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047d41c:
    // 0047d41c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d41e  7412                   -je 0x47d432
    if (cpu.flags.zf)
    {
        goto L_0x0047d432;
    }
    // 0047d420  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d423  ff45e0                 +inc dword ptr [ebp - 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d426  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047d429  8d4443d0               -lea eax, [ebx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0047d42d  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047d430  eb65                   -jmp 0x47d497
    goto L_0x0047d497;
L_0x0047d432:
    // 0047d432  83fb4e                 +cmp ebx, 0x4e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(78 /*0x4e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d435  7f3e                   -jg 0x47d475
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d475;
    }
    // 0047d437  745e                   -je 0x47d497
    if (cpu.flags.zf)
    {
        goto L_0x0047d497;
    }
    // 0047d439  83fb2a                 +cmp ebx, 0x2a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d43c  7432                   -je 0x47d470
    if (cpu.flags.zf)
    {
        goto L_0x0047d470;
    }
    // 0047d43e  83fb46                 +cmp ebx, 0x46
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(70 /*0x46*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d441  7454                   -je 0x47d497
    if (cpu.flags.zf)
    {
        goto L_0x0047d497;
    }
    // 0047d443  83fb49                 +cmp ebx, 0x49
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73 /*0x49*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d446  740a                   -je 0x47d452
    if (cpu.flags.zf)
    {
        goto L_0x0047d452;
    }
    // 0047d448  83fb4c                 +cmp ebx, 0x4c
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d44b  7537                   -jne 0x47d484
    if (!cpu.flags.zf)
    {
        goto L_0x0047d484;
    }
    // 0047d44d  fe45f3                 +inc byte ptr [ebp - 0xd]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047d450  eb45                   -jmp 0x47d497
    goto L_0x0047d497;
L_0x0047d452:
    // 0047d452  807e0136               +cmp byte ptr [esi + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d456  752c                   -jne 0x47d484
    if (!cpu.flags.zf)
    {
        goto L_0x0047d484;
    }
    // 0047d458  807e0234               +cmp byte ptr [esi + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d45c  8d4602                 -lea eax, [esi + 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047d45f  7523                   -jne 0x47d484
    if (!cpu.flags.zf)
    {
        goto L_0x0047d484;
    }
    // 0047d461  ff45d0                 -inc dword ptr [ebp - 0x30]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */))++;
    // 0047d464  8365d800               -and dword ptr [ebp - 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047d468  8365dc00               +and dword ptr [ebp - 0x24], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0047d46c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d46e  eb27                   -jmp 0x47d497
    goto L_0x0047d497;
L_0x0047d470:
    // 0047d470  fe45f2                 +inc byte ptr [ebp - 0xe]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047d473  eb22                   -jmp 0x47d497
    goto L_0x0047d497;
L_0x0047d475:
    // 0047d475  83fb68                 +cmp ebx, 0x68
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d478  7417                   -je 0x47d491
    if (cpu.flags.zf)
    {
        goto L_0x0047d491;
    }
    // 0047d47a  83fb6c                 +cmp ebx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d47d  740a                   -je 0x47d489
    if (cpu.flags.zf)
    {
        goto L_0x0047d489;
    }
    // 0047d47f  83fb77                 +cmp ebx, 0x77
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d482  7408                   -je 0x47d48c
    if (cpu.flags.zf)
    {
        goto L_0x0047d48c;
    }
L_0x0047d484:
    // 0047d484  fe45f1                 +inc byte ptr [ebp - 0xf]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047d487  eb0e                   -jmp 0x47d497
    goto L_0x0047d497;
L_0x0047d489:
    // 0047d489  fe45f3                 +inc byte ptr [ebp - 0xd]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
L_0x0047d48c:
    // 0047d48c  fe45fb                 +inc byte ptr [ebp - 5]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047d48f  eb06                   -jmp 0x47d497
    goto L_0x0047d497;
L_0x0047d491:
    // 0047d491  fe4df3                 -dec byte ptr [ebp - 0xd]
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */))--;
    // 0047d494  fe4dfb                 -dec byte ptr [ebp - 5]
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */))--;
L_0x0047d497:
    // 0047d497  807df100               +cmp byte ptr [ebp - 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d49b  0f844fffffff           -je 0x47d3f0
    if (cpu.flags.zf)
    {
        goto L_0x0047d3f0;
    }
    // 0047d4a1  807df200               +cmp byte ptr [ebp - 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d4a5  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047d4a8  7512                   -jne 0x47d4bc
    if (!cpu.flags.zf)
    {
        goto L_0x0047d4bc;
    }
    // 0047d4aa  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047d4ad  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
    // 0047d4b0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047d4b3  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047d4b6  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0047d4b9  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
L_0x0047d4bc:
    // 0047d4bc  8065f100               -and byte ptr [ebp - 0xf], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d4c0  807dfb00               +cmp byte ptr [ebp - 5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d4c4  7514                   -jne 0x47d4da
    if (!cpu.flags.zf)
    {
        goto L_0x0047d4da;
    }
    // 0047d4c6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d4c8  3c53                   +cmp al, 0x53
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d4ca  740a                   -je 0x47d4d6
    if (cpu.flags.zf)
    {
        goto L_0x0047d4d6;
    }
    // 0047d4cc  3c43                   +cmp al, 0x43
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d4ce  7406                   -je 0x47d4d6
    if (cpu.flags.zf)
    {
        goto L_0x0047d4d6;
    }
    // 0047d4d0  804dfbff               +or byte ptr [ebp - 5], 0xff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) |= x86::reg8(x86::sreg8(255 /*0xff*/))));
    // 0047d4d4  eb04                   -jmp 0x47d4da
    goto L_0x0047d4da;
L_0x0047d4d6:
    // 0047d4d6  c645fb01               -mov byte ptr [ebp - 5], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = 1 /*0x1*/;
L_0x0047d4da:
    // 0047d4da  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047d4dd  0fb633                 -movzx esi, byte ptr [ebx]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx));
    // 0047d4e0  83ce20                 -or esi, 0x20
    cpu.esi |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047d4e3  83fe6e                 +cmp esi, 0x6e
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d4e6  8975c4                 -mov dword ptr [ebp - 0x3c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.esi;
    // 0047d4e9  7428                   -je 0x47d513
    if (cpu.flags.zf)
    {
        goto L_0x0047d513;
    }
    // 0047d4eb  83fe63                 +cmp esi, 0x63
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d4ee  7414                   -je 0x47d504
    if (cpu.flags.zf)
    {
        goto L_0x0047d504;
    }
    // 0047d4f0  83fe7b                 +cmp esi, 0x7b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d4f3  740f                   -je 0x47d504
    if (cpu.flags.zf)
    {
        goto L_0x0047d504;
    }
    // 0047d4f5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d4f8  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047d4fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d4fc  e8b5080000             -call 0x47ddb6
    cpu.esp -= 4;
    sub_47ddb6(app, cpu);
    // 0047d501  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d502  eb0b                   -jmp 0x47d50f
    goto L_0x0047d50f;
L_0x0047d504:
    // 0047d504  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d507  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d50a  e876080000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
L_0x0047d50f:
    // 0047d50f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d510  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x0047d513:
    // 0047d513  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d515  3945e0                 +cmp dword ptr [ebp - 0x20], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d518  7409                   -je 0x47d523
    if (cpu.flags.zf)
    {
        goto L_0x0047d523;
    }
    // 0047d51a  3945f4                 +cmp dword ptr [ebp - 0xc], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d51d  0f84dc070000           -je 0x47dcff
    if (cpu.flags.zf)
    {
        goto L_0x0047dcff;
    }
L_0x0047d523:
    // 0047d523  83fe6f                 +cmp esi, 0x6f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d526  0f8f5e020000           -jg 0x47d78a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d78a;
    }
    // 0047d52c  0f840a050000           -je 0x47da3c
    if (cpu.flags.zf)
    {
        goto L_0x0047da3c;
    }
    // 0047d532  83fe63                 +cmp esi, 0x63
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d535  0f842c020000           -je 0x47d767
    if (cpu.flags.zf)
    {
        goto L_0x0047d767;
    }
    // 0047d53b  83fe64                 +cmp esi, 0x64
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d53e  0f84f8040000           -je 0x47da3c
    if (cpu.flags.zf)
    {
        goto L_0x0047da3c;
    }
    // 0047d544  0f8e6a020000           -jle 0x47d7b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d7b4;
    }
    // 0047d54a  83fe67                 +cmp esi, 0x67
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d54d  7e38                   -jle 0x47d587
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d587;
    }
    // 0047d54f  83fe69                 +cmp esi, 0x69
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d552  741b                   -je 0x47d56f
    if (cpu.flags.zf)
    {
        goto L_0x0047d56f;
    }
    // 0047d554  83fe6e                 +cmp esi, 0x6e
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d557  0f8557020000           -jne 0x47d7b4
    if (!cpu.flags.zf)
    {
        goto L_0x0047d7b4;
    }
    // 0047d55d  807df200               +cmp byte ptr [ebp - 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d561  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047d564  0f8400070000           -je 0x47dc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047dc6a;
    }
    // 0047d56a  e921070000             -jmp 0x47dc90
    goto L_0x0047dc90;
L_0x0047d56f:
    // 0047d56f  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 0047d571  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047d572:
    // 0047d572  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047d575  83fb2d                 +cmp ebx, 0x2d
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d578  0f857e020000           -jne 0x47d7fc
    if (!cpu.flags.zf)
    {
        goto L_0x0047d7fc;
    }
    // 0047d57e  c645e901               -mov byte ptr [ebp - 0x17], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) = 1 /*0x1*/;
    // 0047d582  e97a020000             -jmp 0x47d801
    goto L_0x0047d801;
L_0x0047d587:
    // 0047d587  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047d58a  8db53cfeffff           -lea esi, [ebp - 0x1c4]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-452) /* -0x1c4 */);
    // 0047d590  83fb2d                 +cmp ebx, 0x2d
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d593  750e                   -jne 0x47d5a3
    if (!cpu.flags.zf)
    {
        goto L_0x0047d5a3;
    }
    // 0047d595  889d3cfeffff           -mov byte ptr [ebp - 0x1c4], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-452) /* -0x1c4 */) = cpu.bl;
    // 0047d59b  8db53dfeffff           -lea esi, [ebp - 0x1c3]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-451) /* -0x1c3 */);
    // 0047d5a1  eb05                   -jmp 0x47d5a8
    goto L_0x0047d5a8;
L_0x0047d5a3:
    // 0047d5a3  83fb2b                 +cmp ebx, 0x2b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d5a6  7517                   -jne 0x47d5bf
    if (!cpu.flags.zf)
    {
        goto L_0x0047d5bf;
    }
L_0x0047d5a8:
    // 0047d5a8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d5ab  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d5ae  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d5b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d5b2  e8ce070000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d5b7  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d5b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d5ba  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047d5bd  eb03                   -jmp 0x47d5c2
    goto L_0x0047d5c2;
L_0x0047d5bf:
    // 0047d5bf  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047d5c2:
    // 0047d5c2  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d5c6  7409                   -je 0x47d5d1
    if (cpu.flags.zf)
    {
        goto L_0x0047d5d1;
    }
    // 0047d5c8  817df45d010000         +cmp dword ptr [ebp - 0xc], 0x15d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(349 /*0x15d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d5cf  7e07                   -jle 0x47d5d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d5d8;
    }
L_0x0047d5d1:
    // 0047d5d1  c745f45d010000         -mov dword ptr [ebp - 0xc], 0x15d
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 349 /*0x15d*/;
L_0x0047d5d8:
    // 0047d5d8  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d5df  7e0c                   -jle 0x47d5ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d5ed;
    }
    // 0047d5e1  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047d5e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d5e4  e8a0fcffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047d5e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d5ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d5eb  eb0b                   -jmp 0x47d5f8
    goto L_0x0047d5f8;
L_0x0047d5ed:
    // 0047d5ed  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d5f2  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0047d5f5  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047d5f8:
    // 0047d5f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d5fa  7421                   -je 0x47d61d
    if (cpu.flags.zf)
    {
        goto L_0x0047d61d;
    }
    // 0047d5fc  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d5ff  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047d602  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d604  7417                   -je 0x47d61d
    if (cpu.flags.zf)
    {
        goto L_0x0047d61d;
    }
    // 0047d606  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d609  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0047d60b  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d60c  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d60f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d610  e870070000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d615  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d617  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d618  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047d61b  ebbb                   -jmp 0x47d5d8
    goto L_0x0047d5d8;
L_0x0047d61d:
    // 0047d61d  381d1c644a00           +cmp byte ptr [0x4a641c], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d623  7566                   -jne 0x47d68b
    if (!cpu.flags.zf)
    {
        goto L_0x0047d68b;
    }
    // 0047d625  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d628  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047d62b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d62d  745c                   -je 0x47d68b
    if (cpu.flags.zf)
    {
        goto L_0x0047d68b;
    }
    // 0047d62f  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d632  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d633  e84d070000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d638  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d63a  a01c644a00             -mov al, byte ptr [0x4a641c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */);
    // 0047d63f  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0047d641  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d642  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047d645  46                     -inc esi
    (cpu.esi)++;
L_0x0047d646:
    // 0047d646  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d64d  7e0c                   -jle 0x47d65b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d65b;
    }
    // 0047d64f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047d651  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d652  e832fcffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047d657  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d658  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d659  eb0b                   -jmp 0x47d666
    goto L_0x0047d666;
L_0x0047d65b:
    // 0047d65b  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d660  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0047d663  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047d666:
    // 0047d666  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d668  7421                   -je 0x47d68b
    if (cpu.flags.zf)
    {
        goto L_0x0047d68b;
    }
    // 0047d66a  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d66d  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047d670  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d672  7417                   -je 0x47d68b
    if (cpu.flags.zf)
    {
        goto L_0x0047d68b;
    }
    // 0047d674  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d677  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0047d679  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d67a  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d67d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d67e  e802070000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d683  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d685  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d686  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047d689  ebbb                   -jmp 0x47d646
    goto L_0x0047d646;
L_0x0047d68b:
    // 0047d68b  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d68f  0f848e000000           -je 0x47d723
    if (cpu.flags.zf)
    {
        goto L_0x0047d723;
    }
    // 0047d695  83fb65                 +cmp ebx, 0x65
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d698  7409                   -je 0x47d6a3
    if (cpu.flags.zf)
    {
        goto L_0x0047d6a3;
    }
    // 0047d69a  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d69d  0f8580000000           -jne 0x47d723
    if (!cpu.flags.zf)
    {
        goto L_0x0047d723;
    }
L_0x0047d6a3:
    // 0047d6a3  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d6a6  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047d6a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d6ab  7476                   -je 0x47d723
    if (cpu.flags.zf)
    {
        goto L_0x0047d723;
    }
    // 0047d6ad  c60665                 -mov byte ptr [esi], 0x65
    app->getMemory<x86::reg8>(cpu.esi) = 101 /*0x65*/;
    // 0047d6b0  46                     -inc esi
    (cpu.esi)++;
    // 0047d6b1  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d6b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d6b5  e8cb060000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d6ba  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d6bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6bd  83fb2d                 +cmp ebx, 0x2d
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d6c0  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047d6c3  7505                   -jne 0x47d6ca
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6ca;
    }
    // 0047d6c5  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0047d6c7  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d6c8  eb05                   -jmp 0x47d6cf
    goto L_0x0047d6cf;
L_0x0047d6ca:
    // 0047d6ca  83fb2b                 +cmp ebx, 0x2b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d6cd  751e                   -jne 0x47d6ed
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6ed;
    }
L_0x0047d6cf:
    // 0047d6cf  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d6d2  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047d6d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d6d7  7505                   -jne 0x47d6de
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6de;
    }
    // 0047d6d9  2145f4                 +and dword ptr [ebp - 0xc], eax
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047d6dc  eb0f                   -jmp 0x47d6ed
    goto L_0x0047d6ed;
L_0x0047d6de:
    // 0047d6de  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d6e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d6e2  e89e060000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d6e7  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d6e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6ea  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0047d6ed:
    // 0047d6ed  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d6f4  7e0c                   -jle 0x47d702
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d702;
    }
    // 0047d6f6  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047d6f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d6f9  e88bfbffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047d6fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d700  eb0b                   -jmp 0x47d70d
    goto L_0x0047d70d;
L_0x0047d702:
    // 0047d702  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d707  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0047d70a  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047d70d:
    // 0047d70d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d70f  7412                   -je 0x47d723
    if (cpu.flags.zf)
    {
        goto L_0x0047d723;
    }
    // 0047d711  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d714  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047d717  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d719  7408                   -je 0x47d723
    if (cpu.flags.zf)
    {
        goto L_0x0047d723;
    }
    // 0047d71b  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d71e  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0047d720  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d721  ebbb                   -jmp 0x47d6de
    goto L_0x0047d6de;
L_0x0047d723:
    // 0047d723  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047d726  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d727  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d728  e872060000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047d72d  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d732  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d733  0f84f6050000           -je 0x47dd2f
    if (cpu.flags.zf)
    {
        goto L_0x0047dd2f;
    }
    // 0047d739  807df200               +cmp byte ptr [ebp - 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d73d  0f854d050000           -jne 0x47dc90
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc90;
    }
    // 0047d743  ff45cc                 -inc dword ptr [ebp - 0x34]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */))++;
    // 0047d746  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047d749  8d853cfeffff           -lea eax, [ebp - 0x1c4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-452) /* -0x1c4 */);
    // 0047d74f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d750  0fbe45f3               -movsx eax, byte ptr [ebp - 0xd]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */)));
    // 0047d754  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 0047d757  48                     -dec eax
    (cpu.eax)--;
    // 0047d758  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d759  ff15c03f4a00           -call dword ptr [0x4a3fc0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865984) /* 0x4a3fc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d75f  83c40c                 +add esp, 0xc
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
    // 0047d762  e929050000             -jmp 0x47dc90
    goto L_0x0047dc90;
L_0x0047d767:
    // 0047d767  3945e0                 +cmp dword ptr [ebp - 0x20], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d76a  750a                   -jne 0x47d776
    if (!cpu.flags.zf)
    {
        goto L_0x0047d776;
    }
    // 0047d76c  ff45f4                 -inc dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))++;
    // 0047d76f  c745e001000000         -mov dword ptr [ebp - 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 1 /*0x1*/;
L_0x0047d776:
    // 0047d776  807dfb00               +cmp byte ptr [ebp - 5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d77a  7e04                   -jle 0x47d780
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d780;
    }
    // 0047d77c  c645ea01               -mov byte ptr [ebp - 0x16], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 1 /*0x1*/;
L_0x0047d780:
    // 0047d780  bf2c644a00             -mov edi, 0x4a642c
    cpu.edi = 4875308 /*0x4a642c*/;
    // 0047d785  e90b010000             -jmp 0x47d895
    goto L_0x0047d895;
L_0x0047d78a:
    // 0047d78a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d78c  83e870                 +sub eax, 0x70
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d78f  0f84a3020000           -je 0x47da38
    if (cpu.flags.zf)
    {
        goto L_0x0047da38;
    }
    // 0047d795  83e803                 +sub eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d798  0f84e8000000           -je 0x47d886
    if (cpu.flags.zf)
    {
        goto L_0x0047d886;
    }
    // 0047d79e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d79f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d7a0  0f8496020000           -je 0x47da3c
    if (cpu.flags.zf)
    {
        goto L_0x0047da3c;
    }
    // 0047d7a6  83e803                 +sub eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d7a9  0f84c3fdffff           -je 0x47d572
    if (cpu.flags.zf)
    {
        goto L_0x0047d572;
    }
    // 0047d7af  83e803                 +sub eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d7b2  7424                   -je 0x47d7d8
    if (cpu.flags.zf)
    {
        goto L_0x0047d7d8;
    }
L_0x0047d7b4:
    // 0047d7b4  0fb603                 -movzx eax, byte ptr [ebx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx));
    // 0047d7b7  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d7ba  0f853f050000           -jne 0x47dcff
    if (!cpu.flags.zf)
    {
        goto L_0x0047dcff;
    }
    // 0047d7c0  fe4deb                 -dec byte ptr [ebp - 0x15]
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */))--;
    // 0047d7c3  807df200               +cmp byte ptr [ebp - 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d7c7  0f85c3040000           -jne 0x47dc90
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc90;
    }
    // 0047d7cd  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0047d7d0  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047d7d3  e9b8040000             -jmp 0x47dc90
    goto L_0x0047dc90;
L_0x0047d7d8:
    // 0047d7d8  807dfb00               +cmp byte ptr [ebp - 5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d7dc  7e04                   -jle 0x47d7e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d7e2;
    }
    // 0047d7de  c645ea01               -mov byte ptr [ebp - 0x16], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 1 /*0x1*/;
L_0x0047d7e2:
    // 0047d7e2  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047d7e5  47                     -inc edi
    (cpu.edi)++;
    // 0047d7e6  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0047d7e9  803f5e                 +cmp byte ptr [edi], 0x5e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d7ec  0f85a7000000           -jne 0x47d899
    if (!cpu.flags.zf)
    {
        goto L_0x0047d899;
    }
    // 0047d7f2  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047d7f4  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047d7f7  e999000000             -jmp 0x47d895
    goto L_0x0047d895;
L_0x0047d7fc:
    // 0047d7fc  83fb2b                 +cmp ebx, 0x2b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d7ff  7522                   -jne 0x47d823
    if (!cpu.flags.zf)
    {
        goto L_0x0047d823;
    }
L_0x0047d801:
    // 0047d801  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d804  750c                   -jne 0x47d812
    if (!cpu.flags.zf)
    {
        goto L_0x0047d812;
    }
    // 0047d806  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d80a  7406                   -je 0x47d812
    if (cpu.flags.zf)
    {
        goto L_0x0047d812;
    }
    // 0047d80c  c645f101               -mov byte ptr [ebp - 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) = 1 /*0x1*/;
    // 0047d810  eb11                   -jmp 0x47d823
    goto L_0x0047d823;
L_0x0047d812:
    // 0047d812  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d815  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d818  e868050000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d81d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d81f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d820  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0047d823:
    // 0047d823  83fb30                 +cmp ebx, 0x30
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d826  0f8545020000           -jne 0x47da71
    if (!cpu.flags.zf)
    {
        goto L_0x0047da71;
    }
    // 0047d82c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d82f  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d832  e84e050000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d837  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d839  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d83a  80fb78                 +cmp bl, 0x78
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d83d  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047d840  742f                   -je 0x47d871
    if (cpu.flags.zf)
    {
        goto L_0x0047d871;
    }
    // 0047d842  80fb58                 +cmp bl, 0x58
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d845  742a                   -je 0x47d871
    if (cpu.flags.zf)
    {
        goto L_0x0047d871;
    }
    // 0047d847  83fe78                 +cmp esi, 0x78
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d84a  c745e401000000         -mov dword ptr [ebp - 0x1c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 1 /*0x1*/;
    // 0047d851  7408                   -je 0x47d85b
    if (cpu.flags.zf)
    {
        goto L_0x0047d85b;
    }
    // 0047d853  6a6f                   -push 0x6f
    app->getMemory<x86::reg32>(cpu.esp-4) = 111 /*0x6f*/;
    cpu.esp -= 4;
L_0x0047d855:
    // 0047d855  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d856  e916020000             -jmp 0x47da71
    goto L_0x0047da71;
L_0x0047d85b:
    // 0047d85b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d85e  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d861  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d862  e838050000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047d867  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d868  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d869  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0047d86b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d86c  e9fd010000             -jmp 0x47da6e
    goto L_0x0047da6e;
L_0x0047d871:
    // 0047d871  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d874  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d877  e809050000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d87c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d87d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d87f  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047d882  6a78                   -push 0x78
    app->getMemory<x86::reg32>(cpu.esp-4) = 120 /*0x78*/;
    cpu.esp -= 4;
    // 0047d884  ebcf                   -jmp 0x47d855
    goto L_0x0047d855;
L_0x0047d886:
    // 0047d886  807dfb00               +cmp byte ptr [ebp - 5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d88a  7e04                   -jle 0x47d890
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d890;
    }
    // 0047d88c  c645ea01               -mov byte ptr [ebp - 0x16], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 1 /*0x1*/;
L_0x0047d890:
    // 0047d890  bf24644a00             -mov edi, 0x4a6424
    cpu.edi = 4875300 /*0x4a6424*/;
L_0x0047d895:
    // 0047d895  804de8ff               -or byte ptr [ebp - 0x18], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) |= x86::reg8(x86::sreg8(255 /*0xff*/));
L_0x0047d899:
    // 0047d899  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047d89b  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0047d89e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d8a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d8a1  e87a3e0000             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 0047d8a6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d8a9  837dc47b               +cmp dword ptr [ebp - 0x3c], 0x7b
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d8ad  750e                   -jne 0x47d8bd
    if (!cpu.flags.zf)
    {
        goto L_0x0047d8bd;
    }
    // 0047d8af  803f5d                 +cmp byte ptr [edi], 0x5d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d8b2  7509                   -jne 0x47d8bd
    if (!cpu.flags.zf)
    {
        goto L_0x0047d8bd;
    }
    // 0047d8b4  b25d                   -mov dl, 0x5d
    cpu.dl = 93 /*0x5d*/;
    // 0047d8b6  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d8b7  c645a720               -mov byte ptr [ebp - 0x59], 0x20
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-89) /* -0x59 */) = 32 /*0x20*/;
    // 0047d8bb  eb03                   -jmp 0x47d8c0
    goto L_0x0047d8c0;
L_0x0047d8bd:
    // 0047d8bd  8a55cb                 -mov dl, byte ptr [ebp - 0x35]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-53) /* -0x35 */);
L_0x0047d8c0:
    // 0047d8c0  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0047d8c2  3c5d                   +cmp al, 0x5d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d8c4  745f                   -je 0x47d925
    if (cpu.flags.zf)
    {
        goto L_0x0047d925;
    }
    // 0047d8c6  47                     -inc edi
    (cpu.edi)++;
    // 0047d8c7  3c2d                   +cmp al, 0x2d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d8c9  7541                   -jne 0x47d90c
    if (!cpu.flags.zf)
    {
        goto L_0x0047d90c;
    }
    // 0047d8cb  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047d8cd  743d                   -je 0x47d90c
    if (cpu.flags.zf)
    {
        goto L_0x0047d90c;
    }
    // 0047d8cf  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
    // 0047d8d1  80f95d                 +cmp cl, 0x5d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d8d4  7436                   -je 0x47d90c
    if (cpu.flags.zf)
    {
        goto L_0x0047d90c;
    }
    // 0047d8d6  47                     -inc edi
    (cpu.edi)++;
    // 0047d8d7  3ad1                   +cmp dl, cl
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d8d9  7304                   -jae 0x47d8df
    if (!cpu.flags.cf)
    {
        goto L_0x0047d8df;
    }
    // 0047d8db  8ac1                   -mov al, cl
    cpu.al = cpu.cl;
    // 0047d8dd  eb04                   -jmp 0x47d8e3
    goto L_0x0047d8e3;
L_0x0047d8df:
    // 0047d8df  8ac2                   -mov al, dl
    cpu.al = cpu.dl;
    // 0047d8e1  8ad1                   -mov dl, cl
    cpu.dl = cpu.cl;
L_0x0047d8e3:
    // 0047d8e3  3ad0                   +cmp dl, al
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d8e5  7721                   -ja 0x47d908
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047d908;
    }
    // 0047d8e7  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 0047d8ea  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 0047d8ed  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d8ef  46                     -inc esi
    (cpu.esi)++;
L_0x0047d8f0:
    // 0047d8f0  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047d8f2  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d8f4  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047d8f7  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0047d8f9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0047d8fc  d2e3                   -shl bl, cl
    cpu.bl <<= cpu.cl % 32;
    // 0047d8fe  8d44059c               -lea eax, [ebp + eax - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */ + cpu.eax * 1);
    // 0047d902  0818                   +or byte ptr [eax], bl
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.bl))));
    // 0047d904  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d905  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d906  75e8                   -jne 0x47d8f0
    if (!cpu.flags.zf)
    {
        goto L_0x0047d8f0;
    }
L_0x0047d908:
    // 0047d908  32d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 0047d90a  ebb4                   -jmp 0x47d8c0
    goto L_0x0047d8c0;
L_0x0047d90c:
    // 0047d90c  0fb6c8                 -movzx ecx, al
    cpu.ecx = x86::reg32(cpu.al);
    // 0047d90f  8ad0                   -mov dl, al
    cpu.dl = cpu.al;
    // 0047d911  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d913  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047d916  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0047d918  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0047d91b  d2e3                   -shl bl, cl
    cpu.bl <<= cpu.cl % 32;
    // 0047d91d  8d44059c               -lea eax, [ebp + eax - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */ + cpu.eax * 1);
    // 0047d921  0818                   +or byte ptr [eax], bl
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.bl))));
    // 0047d923  eb9b                   -jmp 0x47d8c0
    goto L_0x0047d8c0;
L_0x0047d925:
    // 0047d925  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d928  0f8401040000           -je 0x47dd2f
    if (cpu.flags.zf)
    {
        goto L_0x0047dd2f;
    }
    // 0047d92e  837dc47b               +cmp dword ptr [ebp - 0x3c], 0x7b
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d932  7503                   -jne 0x47d937
    if (!cpu.flags.zf)
    {
        goto L_0x0047d937;
    }
    // 0047d934  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0047d937:
    // 0047d937  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d93a  8b75d4                 -mov esi, dword ptr [ebp - 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0047d93d  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047d940  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d941  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 0047d944  8975d0                 -mov dword ptr [ebp - 0x30], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.esi;
    // 0047d947  e853040000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047d94c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d94d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047d94e:
    // 0047d94e  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d952  740e                   -je 0x47d962
    if (cpu.flags.zf)
    {
        goto L_0x0047d962;
    }
    // 0047d954  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047d957  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047d95a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d95c  0f849c000000           -je 0x47d9fe
    if (cpu.flags.zf)
    {
        goto L_0x0047d9fe;
    }
L_0x0047d962:
    // 0047d962  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d965  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d966  e81a040000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d96b  83f8ff                 +cmp eax, -1
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
    // 0047d96e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d96f  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0047d972  747e                   -je 0x47d9f2
    if (cpu.flags.zf)
    {
        goto L_0x0047d9f2;
    }
    // 0047d974  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d976  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d978  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047d97b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d97c  0fbe5de8               -movsx ebx, byte ptr [ebp - 0x18]
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0047d980  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0047d982  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d984  c1f903                 -sar ecx, 3
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (3 /*0x3*/ % 32));
    // 0047d987  0fbe4c0d9c             -movsx ecx, byte ptr [ebp + ecx - 0x64]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-100) /* -0x64 */ + cpu.ecx * 1)));
    // 0047d98c  33cb                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d98e  85d1                   +test ecx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.edx));
    // 0047d990  7460                   -je 0x47d9f2
    if (cpu.flags.zf)
    {
        goto L_0x0047d9f2;
    }
    // 0047d992  807df200               +cmp byte ptr [ebp - 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d996  7552                   -jne 0x47d9ea
    if (!cpu.flags.zf)
    {
        goto L_0x0047d9ea;
    }
    // 0047d998  807dea00               +cmp byte ptr [ebp - 0x16], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d99c  7441                   -je 0x47d9df
    if (cpu.flags.zf)
    {
        goto L_0x0047d9df;
    }
    // 0047d99e  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047d9a4  8845c8                 -mov byte ptr [ebp - 0x38], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.al;
    // 0047d9a7  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0047d9aa  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0047d9af  740d                   -je 0x47d9be
    if (cpu.flags.zf)
    {
        goto L_0x0047d9be;
    }
    // 0047d9b1  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047d9b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d9b5  e8cb030000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047d9ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9bb  8845c9                 -mov byte ptr [ebp - 0x37], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-55) /* -0x37 */) = cpu.al;
L_0x0047d9be:
    // 0047d9be  ff3518644a00           -push dword ptr [0x4a6418]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
    cpu.esp -= 4;
    // 0047d9c4  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0047d9c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d9c8  8d45c2                 -lea eax, [ebp - 0x3e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-62) /* -0x3e */);
    // 0047d9cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d9cc  e8adb8ffff             -call 0x47927e
    cpu.esp -= 4;
    sub_47927e(app, cpu);
    // 0047d9d1  668b45c2               -mov ax, word ptr [ebp - 0x3e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-62) /* -0x3e */);
    // 0047d9d5  83c40c                 +add esp, 0xc
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
    // 0047d9d8  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 0047d9db  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d9dc  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d9dd  eb03                   -jmp 0x47d9e2
    goto L_0x0047d9e2;
L_0x0047d9df:
    // 0047d9df  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0047d9e1  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0047d9e2:
    // 0047d9e2  8975d4                 -mov dword ptr [ebp - 0x2c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.esi;
    // 0047d9e5  e964ffffff             -jmp 0x47d94e
    goto L_0x0047d94e;
L_0x0047d9ea:
    // 0047d9ea  ff45d0                 +inc dword ptr [ebp - 0x30]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d9ed  e95cffffff             -jmp 0x47d94e
    goto L_0x0047d94e;
L_0x0047d9f2:
    // 0047d9f2  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047d9f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d9f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d9f7  e8a3030000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047d9fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047d9fe:
    // 0047d9fe  3975d0                 +cmp dword ptr [ebp - 0x30], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da01  0f8428030000           -je 0x47dd2f
    if (cpu.flags.zf)
    {
        goto L_0x0047dd2f;
    }
    // 0047da07  807df200               +cmp byte ptr [ebp - 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047da0b  0f857f020000           -jne 0x47dc90
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc90;
    }
    // 0047da11  ff45cc                 -inc dword ptr [ebp - 0x34]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */))++;
    // 0047da14  837dc463               +cmp dword ptr [ebp - 0x3c], 0x63
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da18  0f8472020000           -je 0x47dc90
    if (cpu.flags.zf)
    {
        goto L_0x0047dc90;
    }
    // 0047da1e  807dea00               +cmp byte ptr [ebp - 0x16], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047da22  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0047da25  7409                   -je 0x47da30
    if (cpu.flags.zf)
    {
        goto L_0x0047da30;
    }
    // 0047da27  66832000               +and word ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.eax) &= x86::reg16(x86::sreg16(0 /*0x0*/))));
    // 0047da2b  e960020000             -jmp 0x47dc90
    goto L_0x0047dc90;
L_0x0047da30:
    // 0047da30  802000                 +and byte ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0047da33  e958020000             -jmp 0x47dc90
    goto L_0x0047dc90;
L_0x0047da38:
    // 0047da38  c645f301               -mov byte ptr [ebp - 0xd], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */) = 1 /*0x1*/;
L_0x0047da3c:
    // 0047da3c  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047da3f  83fb2d                 +cmp ebx, 0x2d
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da42  7506                   -jne 0x47da4a
    if (!cpu.flags.zf)
    {
        goto L_0x0047da4a;
    }
    // 0047da44  c645e901               -mov byte ptr [ebp - 0x17], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) = 1 /*0x1*/;
    // 0047da48  eb05                   -jmp 0x47da4f
    goto L_0x0047da4f;
L_0x0047da4a:
    // 0047da4a  83fb2b                 +cmp ebx, 0x2b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da4d  7522                   -jne 0x47da71
    if (!cpu.flags.zf)
    {
        goto L_0x0047da71;
    }
L_0x0047da4f:
    // 0047da4f  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047da52  750c                   -jne 0x47da60
    if (!cpu.flags.zf)
    {
        goto L_0x0047da60;
    }
    // 0047da54  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da58  7406                   -je 0x47da60
    if (cpu.flags.zf)
    {
        goto L_0x0047da60;
    }
    // 0047da5a  c645f101               -mov byte ptr [ebp - 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) = 1 /*0x1*/;
    // 0047da5e  eb11                   -jmp 0x47da71
    goto L_0x0047da71;
L_0x0047da60:
    // 0047da60  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047da63  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047da66  e81a030000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047da6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047da6c  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0047da6e:
    // 0047da6e  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0047da71:
    // 0047da71  837dd000               +cmp dword ptr [ebp - 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da75  0f840f010000           -je 0x47db8a
    if (cpu.flags.zf)
    {
        goto L_0x0047db8a;
    }
    // 0047da7b  807df100               +cmp byte ptr [ebp - 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047da7f  0f85e3000000           -jne 0x47db68
    if (!cpu.flags.zf)
    {
        goto L_0x0047db68;
    }
L_0x0047da85:
    // 0047da85  83fe78                 +cmp esi, 0x78
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da88  754f                   -jne 0x47dad9
    if (!cpu.flags.zf)
    {
        goto L_0x0047dad9;
    }
    // 0047da8a  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da91  7e0f                   -jle 0x47daa2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047daa2;
    }
    // 0047da93  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0047da98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047da99  e8ebf7ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047da9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047da9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047daa0  eb0d                   -jmp 0x47daaf
    goto L_0x0047daaf;
L_0x0047daa2:
    // 0047daa2  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047daa7  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0047daaa  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
L_0x0047daaf:
    // 0047daaf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dab1  0f84a3000000           -je 0x47db5a
    if (cpu.flags.zf)
    {
        goto L_0x0047db5a;
    }
    // 0047dab7  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047daba  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0047dabd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047dabf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dac0  e8eb4e0000             -call 0x4829b0
    cpu.esp -= 4;
    __allshl(app, cpu);
    // 0047dac5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dac6  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0047dac9  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0047dacc  e87d020000             -call 0x47dd4e
    cpu.esp -= 4;
    sub_47dd4e(app, cpu);
    // 0047dad1  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047dad3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dad4  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047dad7  eb53                   -jmp 0x47db2c
    goto L_0x0047db2c;
L_0x0047dad9:
    // 0047dad9  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dae0  7e0c                   -jle 0x47daee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047daee;
    }
    // 0047dae2  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047dae4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dae5  e89ff7ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047daea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047daeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047daec  eb0b                   -jmp 0x47daf9
    goto L_0x0047daf9;
L_0x0047daee:
    // 0047daee  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047daf3  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0047daf6  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047daf9:
    // 0047daf9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dafb  745d                   -je 0x47db5a
    if (cpu.flags.zf)
    {
        goto L_0x0047db5a;
    }
    // 0047dafd  83fe6f                 +cmp esi, 0x6f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047db00  7515                   -jne 0x47db17
    if (!cpu.flags.zf)
    {
        goto L_0x0047db17;
    }
    // 0047db02  83fb38                 +cmp ebx, 0x38
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047db05  7d53                   -jge 0x47db5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047db5a;
    }
    // 0047db07  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047db0a  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0047db0d  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0047db0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db10  e89b4e0000             -call 0x4829b0
    cpu.esp -= 4;
    __allshl(app, cpu);
    // 0047db15  eb0f                   -jmp 0x47db26
    goto L_0x0047db26;
L_0x0047db17:
    // 0047db17  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047db19  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0047db1b  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047db1e  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 0047db21  e88a210000             -call 0x47fcb0
    cpu.esp -= 4;
    __allmul(app, cpu);
L_0x0047db26:
    // 0047db26  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0047db29  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x0047db2c:
    // 0047db2c  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
    // 0047db2f  8d43d0                 -lea eax, [ebx - 0x30]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-48) /* -0x30 */);
    // 0047db32  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047db33  0145d8                 +add dword ptr [ebp - 0x28], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047db36  1155dc                 -adc dword ptr [ebp - 0x24], edx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */)) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047db39  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047db3d  7405                   -je 0x47db44
    if (cpu.flags.zf)
    {
        goto L_0x0047db44;
    }
    // 0047db3f  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047db42  7424                   -je 0x47db68
    if (cpu.flags.zf)
    {
        goto L_0x0047db68;
    }
L_0x0047db44:
    // 0047db44  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047db47  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047db4a  e836020000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047db4f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047db51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db52  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047db55  e92bffffff             -jmp 0x47da85
    goto L_0x0047da85;
L_0x0047db5a:
    // 0047db5a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047db5d  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047db60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047db61  e839020000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047db66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047db68:
    // 0047db68  807de900               +cmp byte ptr [ebp - 0x17], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047db6c  0f84dc000000           -je 0x47dc4e
    if (cpu.flags.zf)
    {
        goto L_0x0047dc4e;
    }
    // 0047db72  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047db75  8b4ddc                 -mov ecx, dword ptr [ebp - 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0047db78  f7d8                   +neg eax
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
    // 0047db7a  83d100                 -adc ecx, 0
    (cpu.ecx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 0047db7d  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0047db80  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0047db82  894ddc                 -mov dword ptr [ebp - 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ecx;
    // 0047db85  e9c4000000             -jmp 0x47dc4e
    goto L_0x0047dc4e;
L_0x0047db8a:
    // 0047db8a  807df100               +cmp byte ptr [ebp - 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047db8e  0f85b2000000           -jne 0x47dc46
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc46;
    }
L_0x0047db94:
    // 0047db94  83fe78                 +cmp esi, 0x78
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047db97  743f                   -je 0x47dbd8
    if (cpu.flags.zf)
    {
        goto L_0x0047dbd8;
    }
    // 0047db99  83fe70                 +cmp esi, 0x70
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047db9c  743a                   -je 0x47dbd8
    if (cpu.flags.zf)
    {
        goto L_0x0047dbd8;
    }
    // 0047db9e  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dba5  7e0c                   -jle 0x47dbb3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047dbb3;
    }
    // 0047dba7  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047dba9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dbaa  e8daf6ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047dbaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dbb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dbb1  eb0b                   -jmp 0x47dbbe
    goto L_0x0047dbbe;
L_0x0047dbb3:
    // 0047dbb3  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047dbb8  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0047dbbb  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047dbbe:
    // 0047dbbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dbc0  7476                   -je 0x47dc38
    if (cpu.flags.zf)
    {
        goto L_0x0047dc38;
    }
    // 0047dbc2  83fe6f                 +cmp esi, 0x6f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dbc5  750a                   -jne 0x47dbd1
    if (!cpu.flags.zf)
    {
        goto L_0x0047dbd1;
    }
    // 0047dbc7  83fb38                 +cmp ebx, 0x38
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dbca  7d6c                   -jge 0x47dc38
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047dc38;
    }
    // 0047dbcc  c1e703                 +shl edi, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edi);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047dbcf  eb3f                   -jmp 0x47dc10
    goto L_0x0047dc10;
L_0x0047dbd1:
    // 0047dbd1  8d3cbf                 -lea edi, [edi + edi*4]
    cpu.edi = x86::reg32(cpu.edi + cpu.edi * 4);
    // 0047dbd4  d1e7                   +shl edi, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edi);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047dbd6  eb38                   -jmp 0x47dc10
    goto L_0x0047dc10;
L_0x0047dbd8:
    // 0047dbd8  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dbdf  7e0f                   -jle 0x47dbf0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047dbf0;
    }
    // 0047dbe1  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0047dbe6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dbe7  e89df6ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047dbec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dbed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dbee  eb0d                   -jmp 0x47dbfd
    goto L_0x0047dbfd;
L_0x0047dbf0:
    // 0047dbf0  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047dbf5  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0047dbf8  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
L_0x0047dbfd:
    // 0047dbfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dbff  7437                   -je 0x47dc38
    if (cpu.flags.zf)
    {
        goto L_0x0047dc38;
    }
    // 0047dc01  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dc02  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0047dc05  e844010000             -call 0x47dd4e
    cpu.esp -= 4;
    sub_47dd4e(app, cpu);
    // 0047dc0a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047dc0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc0d  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0047dc10:
    // 0047dc10  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
    // 0047dc13  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dc17  8d7c1fd0               -lea edi, [edi + ebx - 0x30]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(-48) /* -0x30 */ + cpu.ebx * 1);
    // 0047dc1b  7405                   -je 0x47dc22
    if (cpu.flags.zf)
    {
        goto L_0x0047dc22;
    }
    // 0047dc1d  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047dc20  7424                   -je 0x47dc46
    if (cpu.flags.zf)
    {
        goto L_0x0047dc46;
    }
L_0x0047dc22:
    // 0047dc22  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047dc25  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047dc28  e858010000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047dc2d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047dc2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc30  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047dc33  e95cffffff             -jmp 0x47db94
    goto L_0x0047db94;
L_0x0047dc38:
    // 0047dc38  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047dc3b  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047dc3e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dc3f  e85b010000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047dc44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047dc46:
    // 0047dc46  807de900               +cmp byte ptr [ebp - 0x17], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dc4a  7402                   -je 0x47dc4e
    if (cpu.flags.zf)
    {
        goto L_0x0047dc4e;
    }
    // 0047dc4c  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
L_0x0047dc4e:
    // 0047dc4e  83fe46                 +cmp esi, 0x46
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(70 /*0x46*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dc51  7504                   -jne 0x47dc57
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc57;
    }
    // 0047dc53  8365e400               -and dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047dc57:
    // 0047dc57  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dc5b  0f84ce000000           -je 0x47dd2f
    if (cpu.flags.zf)
    {
        goto L_0x0047dd2f;
    }
    // 0047dc61  807df200               +cmp byte ptr [ebp - 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dc65  7529                   -jne 0x47dc90
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc90;
    }
    // 0047dc67  ff45cc                 -inc dword ptr [ebp - 0x34]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */))++;
L_0x0047dc6a:
    // 0047dc6a  837dd000               +cmp dword ptr [ebp - 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dc6e  7410                   -je 0x47dc80
    if (cpu.flags.zf)
    {
        goto L_0x0047dc80;
    }
    // 0047dc70  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0047dc73  8b4dd8                 -mov ecx, dword ptr [ebp - 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047dc76  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047dc78  8b4ddc                 -mov ecx, dword ptr [ebp - 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0047dc7b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047dc7e  eb10                   -jmp 0x47dc90
    goto L_0x0047dc90;
L_0x0047dc80:
    // 0047dc80  807df300               +cmp byte ptr [ebp - 0xd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dc84  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0047dc87  7404                   -je 0x47dc8d
    if (cpu.flags.zf)
    {
        goto L_0x0047dc8d;
    }
    // 0047dc89  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0047dc8b  eb03                   -jmp 0x47dc90
    goto L_0x0047dc90;
L_0x0047dc8d:
    // 0047dc8d  668938                 -mov word ptr [eax], di
    app->getMemory<x86::reg16>(cpu.eax) = cpu.di;
L_0x0047dc90:
    // 0047dc90  fe45eb                 +inc byte ptr [ebp - 0x15]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047dc93  ff450c                 +inc dword ptr [ebp + 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047dc96  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047dc99  eb42                   -jmp 0x47dcdd
    goto L_0x0047dcdd;
L_0x0047dc9b:
    // 0047dc9b  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047dc9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dc9f  e8e1000000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047dca4  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047dca6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dca7  0fb606                 -movzx eax, byte ptr [esi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0047dcaa  46                     -inc esi
    (cpu.esi)++;
    // 0047dcab  3bc3                   +cmp eax, ebx
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
    // 0047dcad  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047dcb0  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047dcb3  7555                   -jne 0x47dd0a
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd0a;
    }
    // 0047dcb5  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047dcbb  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0047dcbe  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0047dcc3  7418                   -je 0x47dcdd
    if (cpu.flags.zf)
    {
        goto L_0x0047dcdd;
    }
    // 0047dcc5  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047dcc8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dcc9  e8b7000000             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047dcce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dccf  0fb60e                 -movzx ecx, byte ptr [esi]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0047dcd2  46                     -inc esi
    (cpu.esi)++;
    // 0047dcd3  3bc8                   +cmp ecx, eax
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
    // 0047dcd5  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047dcd8  753e                   -jne 0x47dd18
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd18;
    }
    // 0047dcda  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
L_0x0047dcdd:
    // 0047dcdd  837decff               +cmp dword ptr [ebp - 0x14], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dce1  7510                   -jne 0x47dcf3
    if (!cpu.flags.zf)
    {
        goto L_0x0047dcf3;
    }
    // 0047dce3  803e25                 +cmp byte ptr [esi], 0x25
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dce6  754d                   -jne 0x47dd35
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd35;
    }
    // 0047dce8  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047dceb  8078016e               +cmp byte ptr [eax + 1], 0x6e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dcef  7544                   -jne 0x47dd35
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd35;
    }
    // 0047dcf1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0047dcf3:
    // 0047dcf3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047dcf5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047dcf7  0f8556f6ffff           -jne 0x47d353
    if (!cpu.flags.zf)
    {
        goto L_0x0047d353;
    }
    // 0047dcfd  eb30                   -jmp 0x47dd2f
    goto L_0x0047dd2f;
L_0x0047dcff:
    // 0047dcff  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047dd02  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047dd05  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 0047dd08  eb05                   -jmp 0x47dd0f
    goto L_0x0047dd0f;
L_0x0047dd0a:
    // 0047dd0a  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047dd0d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dd0e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0047dd0f:
    // 0047dd0f  e88b000000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047dd14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd16  eb17                   -jmp 0x47dd2f
    goto L_0x0047dd2f;
L_0x0047dd18:
    // 0047dd18  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047dd1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dd1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047dd1d  e87d000000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047dd22  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0047dd25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dd26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dd27  e873000000             -call 0x47dd9f
    cpu.esp -= 4;
    sub_47dd9f(app, cpu);
    // 0047dd2c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047dd2f:
    // 0047dd2f  837decff               +cmp dword ptr [ebp - 0x14], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dd33  7511                   -jne 0x47dd46
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd46;
    }
L_0x0047dd35:
    // 0047dd35  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0047dd38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dd3a  750d                   -jne 0x47dd49
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd49;
    }
    // 0047dd3c  3845eb                 +cmp byte ptr [ebp - 0x15], al
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dd3f  7508                   -jne 0x47dd49
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd49;
    }
    // 0047dd41  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047dd44  eb03                   -jmp 0x47dd49
    goto L_0x0047dd49;
L_0x0047dd46:
    // 0047dd46  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
L_0x0047dd49:
    // 0047dd49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd4c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47dd4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dd4e  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dd55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dd56  7e10                   -jle 0x47dd68
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047dd68;
    }
    // 0047dd58  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047dd5c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047dd5e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dd5f  e825f5ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047dd64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd66  eb0f                   -jmp 0x47dd77
    goto L_0x0047dd77;
L_0x0047dd68:
    // 0047dd68  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047dd6c  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047dd71  8a0470                 -mov al, byte ptr [eax + esi*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.esi * 2);
    // 0047dd74  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047dd77:
    // 0047dd77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dd79  7506                   -jne 0x47dd81
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd81;
    }
    // 0047dd7b  83e6df                 -and esi, 0xffffffdf
    cpu.esi &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0047dd7e  83ee07                 -sub esi, 7
    (cpu.esi) -= x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x0047dd81:
    // 0047dd81  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047dd83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47dd85(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dd85  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047dd89  ff4a04                 +dec dword ptr [edx + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047dd8c  7809                   -js 0x47dd97
    if (cpu.flags.sf)
    {
        goto L_0x0047dd97;
    }
    // 0047dd8e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047dd90  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0047dd93  41                     -inc ecx
    (cpu.ecx)++;
    // 0047dd94  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0047dd96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dd97:
    // 0047dd97  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dd98  e8be000000             -call 0x47de5b
    cpu.esp -= 4;
    sub_47de5b(app, cpu);
    // 0047dd9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47dd9f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dd9f  837c2404ff             +cmp dword ptr [esp + 4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dda4  740f                   -je 0x47ddb5
    if (cpu.flags.zf)
    {
        goto L_0x0047ddb5;
    }
    // 0047dda6  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ddaa  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ddae  e81c4c0000             -call 0x4829cf
    cpu.esp -= 4;
    sub_4829cf(app, cpu);
    // 0047ddb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047ddb5:
    // 0047ddb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ddb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ddb6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ddb7  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ddbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047ddbc:
    // 0047ddbc  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047ddc0  ff06                   -inc dword ptr [esi]
    (app->getMemory<x86::reg32>(cpu.esi))++;
    // 0047ddc2  e8beffffff             -call 0x47dd85
    cpu.esp -= 4;
    sub_47dd85(app, cpu);
    // 0047ddc7  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047ddc9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ddca  e8b44b0000             -call 0x482983
    cpu.esp -= 4;
    sub_482983(app, cpu);
    // 0047ddcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ddd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddd3  75e7                   -jne 0x47ddbc
    if (!cpu.flags.zf)
    {
        goto L_0x0047ddbc;
    }
    // 0047ddd5  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ddd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_strlen(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dde0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047dde4  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047ddea  7414                   -je 0x47de00
    if (cpu.flags.zf)
    {
        goto L_0x0047de00;
    }
L_0x0047ddec:
    // 0047ddec  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047ddee  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ddef  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047ddf1  7440                   -je 0x47de33
    if (cpu.flags.zf)
    {
        goto L_0x0047de33;
    }
    // 0047ddf3  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047ddf9  75f1                   -jne 0x47ddec
    if (!cpu.flags.zf)
    {
        goto L_0x0047ddec;
    }
    // 0047ddfb  0500000000             -add eax, 0
    (cpu.eax) += x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047de00:
    // 0047de00  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047de02  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0047de07  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047de09  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047de0c  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047de0e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047de11  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0047de16  74e8                   -je 0x47de00
    if (cpu.flags.zf)
    {
        goto L_0x0047de00;
    }
    // 0047de18  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0047de1b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047de1d  7432                   -je 0x47de51
    if (cpu.flags.zf)
    {
        goto L_0x0047de51;
    }
    // 0047de1f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047de21  7424                   -je 0x47de47
    if (cpu.flags.zf)
    {
        goto L_0x0047de47;
    }
    // 0047de23  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 0047de28  7413                   -je 0x47de3d
    if (cpu.flags.zf)
    {
        goto L_0x0047de3d;
    }
    // 0047de2a  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0047de2f  7402                   -je 0x47de33
    if (cpu.flags.zf)
    {
        goto L_0x0047de33;
    }
    // 0047de31  ebcd                   -jmp 0x47de00
    goto L_0x0047de00;
L_0x0047de33:
    // 0047de33  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0047de36  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047de3a  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047de3d:
    // 0047de3d  8d41fe                 -lea eax, [ecx - 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0047de40  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047de44  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047de47:
    // 0047de47  8d41fd                 -lea eax, [ecx - 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 0047de4a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047de4e  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047de51:
    // 0047de51  8d41fc                 -lea eax, [ecx - 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0047de54  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047de58  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47de5b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047de5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047de5c  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047de60  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047de63  a883                   +test al, 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 131 /*0x83*/));
    // 0047de65  0f84c7000000           -je 0x47df32
    if (cpu.flags.zf)
    {
        goto L_0x0047df32;
    }
    // 0047de6b  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0047de6d  0f85bf000000           -jne 0x47df32
    if (!cpu.flags.zf)
    {
        goto L_0x0047df32;
    }
    // 0047de73  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0047de75  740a                   -je 0x47de81
    if (cpu.flags.zf)
    {
        goto L_0x0047de81;
    }
    // 0047de77  0c20                   +or al, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0047de79  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047de7c  e9b1000000             -jmp 0x47df32
    goto L_0x0047df32;
L_0x0047de81:
    // 0047de81  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047de83  66a90c01               +test ax, 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 268 /*0x10c*/));
    // 0047de87  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047de8a  7509                   -jne 0x47de95
    if (!cpu.flags.zf)
    {
        goto L_0x0047de95;
    }
    // 0047de8c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047de8d  e8e3440000             -call 0x482375
    cpu.esp -= 4;
    sub_482375(app, cpu);
    // 0047de92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047de93  eb05                   -jmp 0x47de9a
    goto L_0x0047de9a;
L_0x0047de95:
    // 0047de95  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047de98  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0047de9a:
    // 0047de9a  ff7618                 -push dword ptr [esi + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047de9d  ff7608                 -push dword ptr [esi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047dea0  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047dea3  e8bba9ffff             -call 0x478863
    cpu.esp -= 4;
    sub_478863(app, cpu);
    // 0047dea8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047deab  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047deae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047deb0  746f                   -je 0x47df21
    if (cpu.flags.zf)
    {
        goto L_0x0047df21;
    }
    // 0047deb2  83f8ff                 +cmp eax, -1
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
    // 0047deb5  746a                   -je 0x47df21
    if (cpu.flags.zf)
    {
        goto L_0x0047df21;
    }
    // 0047deb7  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047deba  f6c282                 +test dl, 0x82
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 130 /*0x82*/));
    // 0047debd  7537                   -jne 0x47def6
    if (!cpu.flags.zf)
    {
        goto L_0x0047def6;
    }
    // 0047debf  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047dec2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dec3  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dec6  7417                   -je 0x47dedf
    if (cpu.flags.zf)
    {
        goto L_0x0047dedf;
    }
    // 0047dec8  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047deca  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 0047decd  83e11f                 +and ecx, 0x1f
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/))));
    // 0047ded0  8b3cbde01e5200         -mov edi, dword ptr [edi*4 + 0x521ee0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.edi * 4);
    // 0047ded7  8d0cc9                 -lea ecx, [ecx + ecx*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 8);
    // 0047deda  8d3c8f                 -lea edi, [edi + ecx*4]
    cpu.edi = x86::reg32(cpu.edi + cpu.ecx * 4);
    // 0047dedd  eb05                   -jmp 0x47dee4
    goto L_0x0047dee4;
L_0x0047dedf:
    // 0047dedf  bf30644a00             -mov edi, 0x4a6430
    cpu.edi = 4875312 /*0x4a6430*/;
L_0x0047dee4:
    // 0047dee4  8a4f04                 -mov cl, byte ptr [edi + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047dee7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dee8  80e182                 -and cl, 0x82
    cpu.cl &= x86::reg8(x86::sreg8(130 /*0x82*/));
    // 0047deeb  80f982                 +cmp cl, 0x82
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(130 /*0x82*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047deee  7506                   -jne 0x47def6
    if (!cpu.flags.zf)
    {
        goto L_0x0047def6;
    }
    // 0047def0  80ce20                 -or dh, 0x20
    cpu.dh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0047def3  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0047def6:
    // 0047def6  817e1800020000         +cmp dword ptr [esi + 0x18], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047defd  7514                   -jne 0x47df13
    if (!cpu.flags.zf)
    {
        goto L_0x0047df13;
    }
    // 0047deff  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047df02  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0047df05  740c                   -je 0x47df13
    if (cpu.flags.zf)
    {
        goto L_0x0047df13;
    }
    // 0047df07  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0047df0a  7507                   -jne 0x47df13
    if (!cpu.flags.zf)
    {
        goto L_0x0047df13;
    }
    // 0047df0c  c7461800100000         -mov dword ptr [esi + 0x18], 0x1000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4096 /*0x1000*/;
L_0x0047df13:
    // 0047df13  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047df15  48                     -dec eax
    (cpu.eax)--;
    // 0047df16  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047df19  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0047df1c  41                     -inc ecx
    (cpu.ecx)++;
    // 0047df1d  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047df1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047df21:
    // 0047df21  f7d8                   +neg eax
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
    // 0047df23  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047df25  83e010                 -and eax, 0x10
    cpu.eax &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047df28  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047df2b  09460c                 -or dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047df2e  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047df32:
    // 0047df32  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047df35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47df37(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047df37  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047df38  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047df3c  3b1de01f5200           +cmp ebx, dword ptr [0x521fe0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047df42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047df43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047df44  7372                   -jae 0x47dfb8
    if (!cpu.flags.cf)
    {
        goto L_0x0047dfb8;
    }
    // 0047df46  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047df48  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047df4b  8d3c85e01e5200         -lea edi, [eax*4 + 0x521ee0]
    cpu.edi = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 0047df52  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047df54  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047df57  8d34c0                 -lea esi, [eax + eax*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047df5a  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047df5c  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047df5f  f644300401             +test byte ptr [eax + esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 1 /*0x1*/));
    // 0047df64  7452                   -je 0x47dfb8
    if (cpu.flags.zf)
    {
        goto L_0x0047dfb8;
    }
    // 0047df66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047df67  e814160000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 0047df6c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047df6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df6f  f644300401             +test byte ptr [eax + esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 1 /*0x1*/));
    // 0047df74  7429                   -je 0x47df9f
    if (cpu.flags.zf)
    {
        goto L_0x0047df9f;
    }
    // 0047df76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047df77  e8c2150000             -call 0x47f53e
    cpu.esp -= 4;
    sub_47f53e(app, cpu);
    // 0047df7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047df7e  ff1548714800           -call dword ptr [0x487148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747592) /* 0x487148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047df84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047df86  750a                   -jne 0x47df92
    if (!cpu.flags.zf)
    {
        goto L_0x0047df92;
    }
    // 0047df88  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047df8e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047df90  eb02                   -jmp 0x47df94
    goto L_0x0047df94;
L_0x0047df92:
    // 0047df92  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0047df94:
    // 0047df94  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047df96  7415                   -je 0x47dfad
    if (cpu.flags.zf)
    {
        goto L_0x0047dfad;
    }
    // 0047df98  e81e050000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047df9d  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x0047df9f:
    // 0047df9f  e80e050000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047dfa4  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 0047dfaa  83ceff                 +or esi, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
L_0x0047dfad:
    // 0047dfad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dfae  e82c160000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 0047dfb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dfb4  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047dfb6  eb0e                   -jmp 0x47dfc6
    goto L_0x0047dfc6;
L_0x0047dfb8:
    // 0047dfb8  e8f5040000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047dfbd  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 0047dfc3  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0047dfc6:
    // 0047dfc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dfc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dfc8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dfc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47dfca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dfca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047dfcb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047dfcd  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0047dfd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dfd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dfd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dfd3  6880040000             -push 0x480
    app->getMemory<x86::reg32>(cpu.esp-4) = 1152 /*0x480*/;
    cpu.esp -= 4;
    // 0047dfd8  e89d92ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047dfdd  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047dfdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dfe0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047dfe2  7508                   -jne 0x47dfec
    if (!cpu.flags.zf)
    {
        goto L_0x0047dfec;
    }
    // 0047dfe4  6a1b                   -push 0x1b
    app->getMemory<x86::reg32>(cpu.esp-4) = 27 /*0x1b*/;
    cpu.esp -= 4;
    // 0047dfe6  e84ec1ffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 0047dfeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047dfec:
    // 0047dfec  8935e01e5200           -mov dword ptr [0x521ee0], esi
    app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */) = cpu.esi;
    // 0047dff2  c705e01f520020000000   -mov dword ptr [0x521fe0], 0x20
    app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */) = 32 /*0x20*/;
    // 0047dffc  8d8680040000           -lea eax, [esi + 0x480]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1152) /* 0x480 */);
L_0x0047e002:
    // 0047e002  3bf0                   +cmp esi, eax
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
    // 0047e004  731e                   -jae 0x47e024
    if (!cpu.flags.cf)
    {
        goto L_0x0047e024;
    }
    // 0047e006  80660400               -and byte ptr [esi + 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047e00a  830eff                 -or dword ptr [esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047e00d  83660800               -and dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047e011  c646050a               -mov byte ptr [esi + 5], 0xa
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 0047e015  a1e01e5200             -mov eax, dword ptr [0x521ee0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */);
    // 0047e01a  83c624                 -add esi, 0x24
    (cpu.esi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047e01d  0580040000             +add eax, 0x480
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1152 /*0x480*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e022  ebde                   -jmp 0x47e002
    goto L_0x0047e002;
L_0x0047e024:
    // 0047e024  8d45b8                 -lea eax, [ebp - 0x48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 0047e027  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e028  ff1510714800           -call dword ptr [0x487110]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747536) /* 0x487110 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e02e  66837dea00             +cmp word ptr [ebp - 0x16], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e033  0f84d1000000           -je 0x47e10a
    if (cpu.flags.zf)
    {
        goto L_0x0047e10a;
    }
    // 0047e039  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047e03c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e03e  0f84c6000000           -je 0x47e10a
    if (cpu.flags.zf)
    {
        goto L_0x0047e10a;
    }
    // 0047e044  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e046  8d5804                 -lea ebx, [eax + 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047e049  8d043b                 -lea eax, [ebx + edi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 0047e04c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047e04f  b800080000             -mov eax, 0x800
    cpu.eax = 2048 /*0x800*/;
    // 0047e054  3bf8                   +cmp edi, eax
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
    // 0047e056  7c02                   -jl 0x47e05a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e05a;
    }
    // 0047e058  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047e05a:
    // 0047e05a  393de01f5200           +cmp dword ptr [0x521fe0], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e060  7d56                   -jge 0x47e0b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e0b8;
    }
    // 0047e062  bee41e5200             -mov esi, 0x521ee4
    cpu.esi = 5381860 /*0x521ee4*/;
L_0x0047e067:
    // 0047e067  6880040000             -push 0x480
    app->getMemory<x86::reg32>(cpu.esp-4) = 1152 /*0x480*/;
    cpu.esp -= 4;
    // 0047e06c  e80992ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047e071  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e073  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e074  743c                   -je 0x47e0b2
    if (cpu.flags.zf)
    {
        goto L_0x0047e0b2;
    }
    // 0047e076  8305e01f520020         -add dword ptr [0x521fe0], 0x20
    (app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */)) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047e07d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047e07f  8d8880040000           -lea ecx, [eax + 0x480]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1152) /* 0x480 */);
L_0x0047e085:
    // 0047e085  3bc1                   +cmp eax, ecx
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
    // 0047e087  731c                   -jae 0x47e0a5
    if (!cpu.flags.cf)
    {
        goto L_0x0047e0a5;
    }
    // 0047e089  80600400               -and byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047e08d  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047e090  83600800               -and dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047e094  c640050a               -mov byte ptr [eax + 5], 0xa
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 0047e098  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047e09a  83c024                 -add eax, 0x24
    (cpu.eax) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047e09d  81c180040000           +add ecx, 0x480
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1152 /*0x480*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e0a3  ebe0                   -jmp 0x47e085
    goto L_0x0047e085;
L_0x0047e0a5:
    // 0047e0a5  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047e0a8  393de01f5200           +cmp dword ptr [0x521fe0], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e0ae  7cb7                   -jl 0x47e067
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e067;
    }
    // 0047e0b0  eb06                   -jmp 0x47e0b8
    goto L_0x0047e0b8;
L_0x0047e0b2:
    // 0047e0b2  8b3de01f5200           -mov edi, dword ptr [0x521fe0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */);
L_0x0047e0b8:
    // 0047e0b8  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e0ba  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047e0bc  7e4c                   -jle 0x47e10a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e10a;
    }
L_0x0047e0be:
    // 0047e0be  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047e0c1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e0c3  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e0c6  7438                   -je 0x47e100
    if (cpu.flags.zf)
    {
        goto L_0x0047e100;
    }
    // 0047e0c8  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0047e0ca  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0047e0cc  7432                   -je 0x47e100
    if (cpu.flags.zf)
    {
        goto L_0x0047e100;
    }
    // 0047e0ce  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0047e0d0  750b                   -jne 0x47e0dd
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0dd;
    }
    // 0047e0d2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e0d3  ff15c8714800           -call dword ptr [0x4871c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747720) /* 0x4871c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e0d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e0db  7423                   -je 0x47e100
    if (cpu.flags.zf)
    {
        goto L_0x0047e100;
    }
L_0x0047e0dd:
    // 0047e0dd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047e0df  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e0e1  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047e0e4  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047e0e7  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047e0ee  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047e0f1  8d0481                 -lea eax, [ecx + eax*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 0047e0f4  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047e0f7  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047e0f9  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047e0fb  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0047e0fd  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
L_0x0047e100:
    // 0047e100  8345fc04               -add dword ptr [ebp - 4], 4
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047e104  46                     -inc esi
    (cpu.esi)++;
    // 0047e105  43                     -inc ebx
    (cpu.ebx)++;
    // 0047e106  3bf7                   +cmp esi, edi
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
    // 0047e108  7cb4                   -jl 0x47e0be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e0be;
    }
L_0x0047e10a:
    // 0047e10a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047e10c:
    // 0047e10c  8b0de01e5200           -mov ecx, dword ptr [0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */);
    // 0047e112  8d04db                 -lea eax, [ebx + ebx*8]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 8);
    // 0047e115  833c81ff               +cmp dword ptr [ecx + eax*4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e119  8d3481                 -lea esi, [ecx + eax*4]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 0047e11c  754d                   -jne 0x47e16b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e16b;
    }
    // 0047e11e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e120  c6460481               -mov byte ptr [esi + 4], 0x81
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 129 /*0x81*/;
    // 0047e124  7505                   -jne 0x47e12b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e12b;
    }
    // 0047e126  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 0047e128  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e129  eb0a                   -jmp 0x47e135
    goto L_0x0047e135;
L_0x0047e12b:
    // 0047e12b  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047e12d  48                     -dec eax
    (cpu.eax)--;
    // 0047e12e  f7d8                   +neg eax
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
    // 0047e130  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047e132  83c0f5                 -add eax, -0xb
    (cpu.eax) += x86::reg32(x86::sreg32(-11 /*-0xb*/));
L_0x0047e135:
    // 0047e135  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e136  ff1540714800           -call dword ptr [0x487140]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747584) /* 0x487140 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e13c  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047e13e  83ffff                 +cmp edi, -1
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
    // 0047e141  7417                   -je 0x47e15a
    if (cpu.flags.zf)
    {
        goto L_0x0047e15a;
    }
    // 0047e143  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e144  ff15c8714800           -call dword ptr [0x4871c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747720) /* 0x4871c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e14a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e14c  740c                   -je 0x47e15a
    if (cpu.flags.zf)
    {
        goto L_0x0047e15a;
    }
    // 0047e14e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047e153  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0047e155  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e158  7506                   -jne 0x47e160
    if (!cpu.flags.zf)
    {
        goto L_0x0047e160;
    }
L_0x0047e15a:
    // 0047e15a  804e0440               +or byte ptr [esi + 4], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0047e15e  eb0f                   -jmp 0x47e16f
    goto L_0x0047e16f;
L_0x0047e160:
    // 0047e160  83f803                 +cmp eax, 3
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
    // 0047e163  750a                   -jne 0x47e16f
    if (!cpu.flags.zf)
    {
        goto L_0x0047e16f;
    }
    // 0047e165  804e0408               +or byte ptr [esi + 4], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0047e169  eb04                   -jmp 0x47e16f
    goto L_0x0047e16f;
L_0x0047e16b:
    // 0047e16b  804e0480               -or byte ptr [esi + 4], 0x80
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0047e16f:
    // 0047e16f  43                     -inc ebx
    (cpu.ebx)++;
    // 0047e170  83fb03                 +cmp ebx, 3
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
    // 0047e173  7c97                   -jl 0x47e10c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e10c;
    }
    // 0047e175  ff35e01f5200           -push dword ptr [0x521fe0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */);
    cpu.esp -= 4;
    // 0047e17b  ff1544714800           -call dword ptr [0x487144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747588) /* 0x487144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e181  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e182  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e184  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e185  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e207(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e207  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e208  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047e20a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e20b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e20c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e20d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e20e  8b355ced5100           -mov esi, dword ptr [0x51ed5c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5369180) /* 0x51ed5c */);
    // 0047e214  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e215  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047e218  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e21a  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0047e21d  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0047e220  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0047e222  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e224  741a                   -je 0x47e240
    if (cpu.flags.zf)
    {
        goto L_0x0047e240;
    }
    // 0047e226  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e228  740f                   -je 0x47e239
    if (cpu.flags.zf)
    {
        goto L_0x0047e239;
    }
    // 0047e22a  3c77                   +cmp al, 0x77
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e22c  0f8522010000           -jne 0x47e354
    if (!cpu.flags.zf)
    {
        goto L_0x0047e354;
    }
    // 0047e232  b901030000             -mov ecx, 0x301
    cpu.ecx = 769 /*0x301*/;
    // 0047e237  eb0c                   -jmp 0x47e245
    goto L_0x0047e245;
L_0x0047e239:
    // 0047e239  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e23b  83ce01                 +or esi, 1
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0047e23e  eb08                   -jmp 0x47e248
    goto L_0x0047e248;
L_0x0047e240:
    // 0047e240  b909010000             -mov ecx, 0x109
    cpu.ecx = 265 /*0x109*/;
L_0x0047e245:
    // 0047e245  83ce02                 -or esi, 2
    cpu.esi |= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0047e248:
    // 0047e248  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047e24a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e24b:
    // 0047e24b  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0047e24e  47                     -inc edi
    (cpu.edi)++;
    // 0047e24f  3ac3                   +cmp al, bl
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
    // 0047e251  0f84e3000000           -je 0x47e33a
    if (cpu.flags.zf)
    {
        goto L_0x0047e33a;
    }
    // 0047e257  3bd3                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e259  0f84db000000           -je 0x47e33a
    if (cpu.flags.zf)
    {
        goto L_0x0047e33a;
    }
    // 0047e25f  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0047e262  83f854                 +cmp eax, 0x54
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e265  7f72                   -jg 0x47e2d9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047e2d9;
    }
    // 0047e267  7460                   -je 0x47e2c9
    if (cpu.flags.zf)
    {
        goto L_0x0047e2c9;
    }
    // 0047e269  83e82b                 +sub eax, 0x2b
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e26c  7445                   -je 0x47e2b3
    if (cpu.flags.zf)
    {
        goto L_0x0047e2b3;
    }
    // 0047e26e  83e819                 +sub eax, 0x19
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e271  7436                   -je 0x47e2a9
    if (cpu.flags.zf)
    {
        goto L_0x0047e2a9;
    }
    // 0047e273  83e80e                 +sub eax, 0xe
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e276  741c                   -je 0x47e294
    if (cpu.flags.zf)
    {
        goto L_0x0047e294;
    }
    // 0047e278  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e279  0f85ac000000           -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e27f  395dfc                 +cmp dword ptr [ebp - 4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e282  0f85a3000000           -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e288  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047e28f  83c920                 +or ecx, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 0047e292  ebb7                   -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e294:
    // 0047e294  395dfc                 +cmp dword ptr [ebp - 4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e297  0f858e000000           -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e29d  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047e2a4  83c910                 +or ecx, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/))));
    // 0047e2a7  eba2                   -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e2a9:
    // 0047e2a9  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 0047e2ac  757d                   -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e2ae  83c940                 +or ecx, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(64 /*0x40*/))));
    // 0047e2b1  eb98                   -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e2b3:
    // 0047e2b3  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0047e2b6  7573                   -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e2b8  83e1fe                 -and ecx, 0xfffffffe
    cpu.ecx &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 0047e2bb  83e6fc                 -and esi, 0xfffffffc
    cpu.esi &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 0047e2be  83c902                 -or ecx, 2
    cpu.ecx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047e2c1  81ce80000000           +or esi, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 0047e2c7  eb82                   -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e2c9:
    // 0047e2c9  b800100000             -mov eax, 0x1000
    cpu.eax = 4096 /*0x1000*/;
    // 0047e2ce  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 0047e2d0  7559                   -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e2d2  0bc8                   +or ecx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e2d4  e972ffffff             -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e2d9:
    // 0047e2d9  83e862                 +sub eax, 0x62
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98 /*0x62*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e2dc  7448                   -je 0x47e326
    if (cpu.flags.zf)
    {
        goto L_0x0047e326;
    }
    // 0047e2de  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e2df  742e                   -je 0x47e30f
    if (cpu.flags.zf)
    {
        goto L_0x0047e30f;
    }
    // 0047e2e1  83e80b                 +sub eax, 0xb
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e2e4  7412                   -je 0x47e2f8
    if (cpu.flags.zf)
    {
        goto L_0x0047e2f8;
    }
    // 0047e2e6  83e806                 +sub eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e2e9  7540                   -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e2eb  f6c5c0                 +test ch, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 192 /*0xc0*/));
    // 0047e2ee  753b                   -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e2f0  80cd40                 +or ch, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0047e2f3  e953ffffff             -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e2f8:
    // 0047e2f8  395df8                 +cmp dword ptr [ebp - 8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e2fb  752e                   -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e2fd  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 0047e304  81e6ffbfffff           +and esi, 0xffffbfff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(4294950911 /*0xffffbfff*/))));
    // 0047e30a  e93cffffff             -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e30f:
    // 0047e30f  395df8                 +cmp dword ptr [ebp - 8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e312  7517                   -jne 0x47e32b
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32b;
    }
    // 0047e314  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 0047e31b  81ce00400000           +or esi, 0x4000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(16384 /*0x4000*/))));
    // 0047e321  e925ffffff             -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e326:
    // 0047e326  f6c5c0                 +test ch, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 192 /*0xc0*/));
    // 0047e329  7407                   -je 0x47e332
    if (cpu.flags.zf)
    {
        goto L_0x0047e332;
    }
L_0x0047e32b:
    // 0047e32b  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e32d  e919ffffff             -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e332:
    // 0047e332  80cd80                 +or ch, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 0047e335  e911ffffff             -jmp 0x47e24b
    goto L_0x0047e24b;
L_0x0047e33a:
    // 0047e33a  68a4010000             -push 0x1a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 420 /*0x1a4*/;
    cpu.esp -= 4;
    // 0047e33f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047e342  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e343  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047e346  e8f7a7ffff             -call 0x478b42
    cpu.esp -= 4;
    sub_478b42(app, cpu);
    // 0047e34b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e34d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047e350  3bcb                   +cmp ecx, ebx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e352  7d04                   -jge 0x47e358
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e358;
    }
L_0x0047e354:
    // 0047e354  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e356  eb1a                   -jmp 0x47e372
    goto L_0x0047e372;
L_0x0047e358:
    // 0047e358  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047e35b  ff05e4ea5100           -inc dword ptr [0x51eae4]
    (app->getMemory<x86::reg32>(x86::reg32(5368548) /* 0x51eae4 */))++;
    // 0047e361  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047e364  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047e367  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047e369  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047e36c  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047e36f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x0047e372:
    // 0047e372  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e373  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e374  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e375  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e376  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e377(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e377  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e378  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e379  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e37a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047e37c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e37e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047e380  e844e7ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047e385  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e387  391d40305200           +cmp dword ptr [0x523040], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e38d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e38e  0f8e9d000000           -jle 0x47e431
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e431;
    }
L_0x0047e394:
    // 0047e394  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e399  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0047e39c  3bc3                   +cmp eax, ebx
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
    // 0047e39e  7437                   -je 0x47e3d7
    if (cpu.flags.zf)
    {
        goto L_0x0047e3d7;
    }
    // 0047e3a0  f6400c83               +test byte ptr [eax + 0xc], 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 131 /*0x83*/));
    // 0047e3a4  7521                   -jne 0x47e3c7
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3c7;
    }
    // 0047e3a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e3a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e3a8  e80b98ffff             -call 0x477bb8
    cpu.esp -= 4;
    sub_477bb8(app, cpu);
    // 0047e3ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3af  8b0d24205200           -mov ecx, dword ptr [0x522024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e3b5  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0047e3b8  f6400c83               +test byte ptr [eax + 0xc], 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 131 /*0x83*/));
    // 0047e3bc  7414                   -je 0x47e3d2
    if (cpu.flags.zf)
    {
        goto L_0x0047e3d2;
    }
    // 0047e3be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e3bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e3c0  e84598ffff             -call 0x477c0a
    cpu.esp -= 4;
    sub_477c0a(app, cpu);
    // 0047e3c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e3c7:
    // 0047e3c7  46                     -inc esi
    (cpu.esi)++;
    // 0047e3c8  3b3540305200           +cmp esi, dword ptr [0x523040]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e3ce  7cc4                   -jl 0x47e394
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e394;
    }
    // 0047e3d0  eb5f                   -jmp 0x47e431
    goto L_0x0047e431;
L_0x0047e3d2:
    // 0047e3d2  8b3cb1                 -mov edi, dword ptr [ecx + esi*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0047e3d5  eb44                   -jmp 0x47e41b
    goto L_0x0047e41b;
L_0x0047e3d7:
    // 0047e3d7  6a38                   -push 0x38
    app->getMemory<x86::reg32>(cpu.esp-4) = 56 /*0x38*/;
    cpu.esp -= 4;
    // 0047e3d9  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047e3dc  e8998effff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047e3e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3e2  8b0d24205200           -mov ecx, dword ptr [0x522024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e3e8  89040e                 -mov dword ptr [esi + ecx], eax
    app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1) = cpu.eax;
    // 0047e3eb  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e3f0  8b0406                 -mov eax, dword ptr [esi + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0047e3f3  3bc3                   +cmp eax, ebx
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
    // 0047e3f5  743a                   -je 0x47e431
    if (cpu.flags.zf)
    {
        goto L_0x0047e431;
    }
    // 0047e3f7  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047e3fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e3fb  ff15ec704800           -call dword ptr [0x4870ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747500) /* 0x4870ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e401  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e406  8b0406                 -mov eax, dword ptr [esi + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0047e409  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047e40c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e40d  ff15b0714800           -call dword ptr [0x4871b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747696) /* 0x4871b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e413  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e418  8b3c06                 -mov edi, dword ptr [esi + eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
L_0x0047e41b:
    // 0047e41b  3bfb                   +cmp edi, ebx
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
    // 0047e41d  7412                   -je 0x47e431
    if (cpu.flags.zf)
    {
        goto L_0x0047e431;
    }
    // 0047e41f  834f10ff               -or dword ptr [edi + 0x10], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047e423  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047e426  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047e429  895f08                 -mov dword ptr [edi + 8], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047e42c  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0047e42e  895f1c                 -mov dword ptr [edi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
L_0x0047e431:
    // 0047e431  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047e433  e8f2e6ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047e438  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e439  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047e43b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e43c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e43d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e43e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e43f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e43f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e440  e876000000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047e445  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e449  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e44b  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047e44d  b858644a00             -mov eax, 0x4a6458
    cpu.eax = 4875352 /*0x4a6458*/;
L_0x0047e452:
    // 0047e452  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e454  7422                   -je 0x47e478
    if (cpu.flags.zf)
    {
        goto L_0x0047e478;
    }
    // 0047e456  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e459  46                     -inc esi
    (cpu.esi)++;
    // 0047e45a  3dc0654a00             +cmp eax, 0x4a65c0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4875712 /*0x4a65c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e45f  7cf1                   -jl 0x47e452
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e452;
    }
    // 0047e461  83f913                 +cmp ecx, 0x13
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e464  7222                   -jb 0x47e488
    if (cpu.flags.cf)
    {
        goto L_0x0047e488;
    }
    // 0047e466  83f924                 +cmp ecx, 0x24
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e469  771d                   -ja 0x47e488
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047e488;
    }
    // 0047e46b  e842000000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047e470  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
    // 0047e476  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e477  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e478:
    // 0047e478  e835000000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047e47d  8b0cf55c644a00         -mov ecx, dword ptr [esi*8 + 0x4a645c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4875356) /* 0x4a645c */ + cpu.esi * 8);
    // 0047e484  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e485  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047e487  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e488:
    // 0047e488  81f9bc000000           +cmp ecx, 0xbc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(188 /*0xbc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e48e  7215                   -jb 0x47e4a5
    if (cpu.flags.cf)
    {
        goto L_0x0047e4a5;
    }
    // 0047e490  81f9ca000000           +cmp ecx, 0xca
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(202 /*0xca*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e496  770d                   -ja 0x47e4a5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047e4a5;
    }
    // 0047e498  e815000000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047e49d  c70008000000           -mov dword ptr [eax], 8
    app->getMemory<x86::reg32>(cpu.eax) = 8 /*0x8*/;
    // 0047e4a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e4a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e4a5:
    // 0047e4a5  e808000000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047e4aa  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 0047e4b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e4b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e4b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e4b2  e8b0cfffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 0047e4b7  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e4ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e4bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e4bb  e8a7cfffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 0047e4c0  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e4c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e4c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e4c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e4c5  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e4c9  3b35e01f5200           +cmp esi, dword ptr [0x521fe0]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e4cf  7340                   -jae 0x47e511
    if (!cpu.flags.cf)
    {
        goto L_0x0047e511;
    }
    // 0047e4d1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047e4d3  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e4d5  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047e4d8  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047e4db  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047e4e2  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047e4e5  f644810401             +test byte ptr [ecx + eax*4 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) & 1 /*0x1*/));
    // 0047e4ea  7425                   -je 0x47e511
    if (cpu.flags.zf)
    {
        goto L_0x0047e511;
    }
    // 0047e4ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e4ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e4ee  e88d100000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 0047e4f3  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047e4f7  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047e4fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e4fc  e828000000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 0047e501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e502  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047e504  e8d6100000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 0047e509  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047e50c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047e50e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e50f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e510  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e511:
    // 0047e511  e89cffffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047e516  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 0047e51c  e89affffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047e521  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047e524  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047e527  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e528  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e529(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e529  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e52a  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e52e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e52f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e530  e809100000             -call 0x47f53e
    cpu.esp -= 4;
    sub_47f53e(app, cpu);
    // 0047e535  83f8ff                 +cmp eax, -1
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
    // 0047e538  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e539  750d                   -jne 0x47e548
    if (!cpu.flags.zf)
    {
        goto L_0x0047e548;
    }
    // 0047e53b  e872ffffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047e540  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 0047e546  eb2d                   -jmp 0x47e575
    goto L_0x0047e575;
L_0x0047e548:
    // 0047e548  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047e54c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047e54e  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047e552  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e553  ff153c714800           -call dword ptr [0x48713c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747580) /* 0x48713c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e559  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047e55b  83ffff                 +cmp edi, -1
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
    // 0047e55e  7508                   -jne 0x47e568
    if (!cpu.flags.zf)
    {
        goto L_0x0047e568;
    }
    // 0047e560  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e566  eb02                   -jmp 0x47e56a
    goto L_0x0047e56a;
L_0x0047e568:
    // 0047e568  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047e56a:
    // 0047e56a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e56c  740c                   -je 0x47e57a
    if (cpu.flags.zf)
    {
        goto L_0x0047e57a;
    }
    // 0047e56e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e56f  e8cbfeffff             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 0047e574  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e575:
    // 0047e575  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047e578  eb1f                   -jmp 0x47e599
    goto L_0x0047e599;
L_0x0047e57a:
    // 0047e57a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047e57c  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047e57f  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047e582  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e584  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047e58b  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047e58e  80648104fd             -and byte ptr [ecx + eax*4 + 4], 0xfd
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047e593  8d448104               -lea eax, [ecx + eax*4 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 0047e597  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0047e599:
    // 0047e599  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e59a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e59b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e59c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047e59c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e59d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047e59f  81ec50040000           -sub esp, 0x450
    (cpu.esp) -= x86::reg32(x86::sreg32(1104 /*0x450*/));
    // 0047e5a5  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047e5a8  83450c02               -add dword ptr [ebp + 0xc], 2
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047e5ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e5ad  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e5af  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0047e5b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e5b3  663bd9                 +cmp bx, cx
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.cx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e5b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e5b7  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0047e5ba  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 0047e5bd  0f84fe060000           -je 0x47ecc1
    if (cpu.flags.zf)
    {
        goto L_0x0047ecc1;
    }
    // 0047e5c3  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047e5c5  eb03                   -jmp 0x47e5ca
    goto L_0x0047e5ca;
L_0x0047e5c7:
    // 0047e5c7  8b4dc8                 -mov ecx, dword ptr [ebp - 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
L_0x0047e5ca:
    // 0047e5ca  3975ec                 +cmp dword ptr [ebp - 0x14], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e5cd  0f8cee060000           -jl 0x47ecc1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ecc1;
    }
    // 0047e5d3  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047e5d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5d6  663bdf                 +cmp bx, di
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e5d9  7214                   -jb 0x47e5ef
    if (cpu.flags.cf)
    {
        goto L_0x0047e5ef;
    }
    // 0047e5db  6683fb78               +cmp bx, 0x78
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(120 /*0x78*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e5df  770e                   -ja 0x47e5ef
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047e5ef;
    }
    // 0047e5e1  0fb7c3                 -movzx eax, bx
    cpu.eax = x86::reg32(cpu.bx);
    // 0047e5e4  8a80307d4800           -mov al, byte ptr [eax + 0x487d30]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4750640) /* 0x487d30 */);
    // 0047e5ea  83e00f                 +and eax, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/))));
    // 0047e5ed  eb02                   -jmp 0x47e5f1
    goto L_0x0047e5f1;
L_0x0047e5ef:
    // 0047e5ef  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047e5f1:
    // 0047e5f1  0fbe84c1507d4800       -movsx eax, byte ptr [ecx + eax*8 + 0x487d50]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4750672) /* 0x487d50 */ + cpu.eax * 8)));
    // 0047e5f9  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0047e5fb  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047e5fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5ff  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 0047e602  3bc1                   +cmp eax, ecx
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
    // 0047e604  0f87a2060000           -ja 0x47ecac
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ecac;
    }
    // 0047e60a  ff2485c9ec4700         -jmp dword ptr [eax*4 + 0x47ecc9]
    cpu.ip = app->getMemory<x86::reg32>(4713673 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047e611:
    // 0047e611  834df0ff               +or dword ptr [ebp - 0x10], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047e615  8975cc                 -mov dword ptr [ebp - 0x34], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.esi;
    // 0047e618  8975d0                 -mov dword ptr [ebp - 0x30], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.esi;
    // 0047e61b  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0047e61e  8975e8                 -mov dword ptr [ebp - 0x18], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esi;
    // 0047e621  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0047e624  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 0047e627  e980060000             -jmp 0x47ecac
    goto L_0x0047ecac;
  case 0x0047e62c:
    // 0047e62c  0fb7c3                 -movzx eax, bx
    cpu.eax = x86::reg32(cpu.bx);
    // 0047e62f  2bc7                   +sub eax, edi
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
    // 0047e631  743b                   -je 0x47e66e
    if (cpu.flags.zf)
    {
        goto L_0x0047e66e;
    }
    // 0047e633  83e803                 +sub eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e636  742d                   -je 0x47e665
    if (cpu.flags.zf)
    {
        goto L_0x0047e665;
    }
    // 0047e638  83e808                 +sub eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e63b  741f                   -je 0x47e65c
    if (cpu.flags.zf)
    {
        goto L_0x0047e65c;
    }
    // 0047e63d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e63e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e63f  7412                   -je 0x47e653
    if (cpu.flags.zf)
    {
        goto L_0x0047e653;
    }
    // 0047e641  83e803                 +sub eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e644  0f8562060000           -jne 0x47ecac
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecac;
    }
    // 0047e64a  834dfc08               +or dword ptr [ebp - 4], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(8 /*0x8*/))));
    // 0047e64e  e959060000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e653:
    // 0047e653  834dfc04               +or dword ptr [ebp - 4], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0047e657  e950060000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e65c:
    // 0047e65c  834dfc01               +or dword ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0047e660  e947060000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e665:
    // 0047e665  804dfc80               +or byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 0047e669  e93e060000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e66e:
    // 0047e66e  834dfc02               +or dword ptr [ebp - 4], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0047e672  e935060000             -jmp 0x47ecac
    goto L_0x0047ecac;
  case 0x0047e677:
    // 0047e677  6683fb2a               +cmp bx, 0x2a
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(42 /*0x2a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e67b  7523                   -jne 0x47e6a0
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6a0;
    }
    // 0047e67d  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e680  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e681  e8ed060000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047e686  3bc6                   +cmp eax, esi
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
    // 0047e688  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e689  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0047e68c  0f8d1a060000           -jge 0x47ecac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ecac;
    }
    // 0047e692  834dfc04               -or dword ptr [ebp - 4], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047e696  f7d8                   +neg eax
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
L_0x0047e698:
    // 0047e698  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0047e69b  e90c060000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e6a0:
    // 0047e6a0  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047e6a3  0fb7cb                 -movzx ecx, bx
    cpu.ecx = x86::reg32(cpu.bx);
    // 0047e6a6  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047e6a9  8d4441d0               -lea eax, [ecx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0047e6ad  ebe9                   -jmp 0x47e698
    goto L_0x0047e698;
  case 0x0047e6af:
    // 0047e6af  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 0047e6b2  e9f5050000             -jmp 0x47ecac
    goto L_0x0047ecac;
  case 0x0047e6b7:
    // 0047e6b7  6683fb2a               +cmp bx, 0x2a
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(42 /*0x2a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e6bb  751e                   -jne 0x47e6db
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6db;
    }
    // 0047e6bd  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e6c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e6c1  e8ad060000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047e6c6  3bc6                   +cmp eax, esi
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
    // 0047e6c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e6c9  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0047e6cc  0f8dda050000           -jge 0x47ecac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ecac;
    }
    // 0047e6d2  834df0ff               +or dword ptr [ebp - 0x10], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047e6d6  e9d1050000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e6db:
    // 0047e6db  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047e6de  0fb7cb                 -movzx ecx, bx
    cpu.ecx = x86::reg32(cpu.bx);
    // 0047e6e1  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047e6e4  8d4441d0               -lea eax, [ecx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0047e6e8  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0047e6eb  e9bc050000             -jmp 0x47ecac
    goto L_0x0047ecac;
  case 0x0047e6f0:
    // 0047e6f0  0fb7c3                 -movzx eax, bx
    cpu.eax = x86::reg32(cpu.bx);
    // 0047e6f3  83f849                 +cmp eax, 0x49
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73 /*0x49*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e6f6  741f                   -je 0x47e717
    if (cpu.flags.zf)
    {
        goto L_0x0047e717;
    }
    // 0047e6f8  83f868                 +cmp eax, 0x68
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e6fb  7412                   -je 0x47e70f
    if (cpu.flags.zf)
    {
        goto L_0x0047e70f;
    }
    // 0047e6fd  83f877                 +cmp eax, 0x77
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e700  0f85a6050000           -jne 0x47ecac
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecac;
    }
    // 0047e706  804dfd08               +or byte ptr [ebp - 3], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0047e70a  e99d050000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e70f:
    // 0047e70f  097dfc                 +or dword ptr [ebp - 4], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047e712  e995050000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e717:
    // 0047e717  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047e71a  66833836               +cmp word ptr [eax], 0x36
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e71e  7514                   -jne 0x47e734
    if (!cpu.flags.zf)
    {
        goto L_0x0047e734;
    }
    // 0047e720  6683780234             +cmp word ptr [eax + 2], 0x34
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(52 /*0x34*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e725  750d                   -jne 0x47e734
    if (!cpu.flags.zf)
    {
        goto L_0x0047e734;
    }
    // 0047e727  83450c04               -add dword ptr [ebp + 0xc], 4
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047e72b  804dfd80               +or byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 0047e72f  e978050000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047e734:
    // 0047e734  8975c8                 -mov dword ptr [ebp - 0x38], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.esi;
  [[fallthrough]];
  case 0x0047e737:
    // 0047e737  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047e73a  c745e401000000         -mov dword ptr [ebp - 0x1c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 1 /*0x1*/;
    // 0047e741  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e742  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047e745  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e746  e89e050000             -call 0x47ece9
    cpu.esp -= 4;
    sub_47ece9(app, cpu);
    // 0047e74b  83c40c                 +add esp, 0xc
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
    // 0047e74e  e959050000             -jmp 0x47ecac
    goto L_0x0047ecac;
  case 0x0047e753:
    // 0047e753  0fb7c3                 -movzx eax, bx
    cpu.eax = x86::reg32(cpu.bx);
    // 0047e756  83f867                 +cmp eax, 0x67
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e759  0f8f39020000           -jg 0x47e998
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047e998;
    }
    // 0047e75f  83f865                 +cmp eax, 0x65
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e762  0f8daa000000           -jge 0x47e812
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e812;
    }
    // 0047e768  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e76b  0f8f10010000           -jg 0x47e881
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047e881;
    }
    // 0047e771  0f8499020000           -je 0x47ea10
    if (cpu.flags.zf)
    {
        goto L_0x0047ea10;
    }
    // 0047e777  83e843                 +sub eax, 0x43
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e77a  0f84b4000000           -je 0x47e834
    if (cpu.flags.zf)
    {
        goto L_0x0047e834;
    }
    // 0047e780  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e781  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e782  0f8481000000           -je 0x47e809
    if (cpu.flags.zf)
    {
        goto L_0x0047e809;
    }
    // 0047e788  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e789  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e78a  747d                   -je 0x47e809
    if (cpu.flags.zf)
    {
        goto L_0x0047e809;
    }
    // 0047e78c  83e80c                 +sub eax, 0xc
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e78f  0f850d040000           -jne 0x47eba2
    if (!cpu.flags.zf)
    {
        goto L_0x0047eba2;
    }
    // 0047e795  66f745fc3008           +test word ptr [ebp - 4], 0x830
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2096 /*0x830*/));
    // 0047e79b  7504                   -jne 0x47e7a1
    if (!cpu.flags.zf)
    {
        goto L_0x0047e7a1;
    }
    // 0047e79d  834dfc20               -or dword ptr [ebp - 4], 0x20
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0047e7a1:
    // 0047e7a1  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047e7a4  83feff                 +cmp esi, -1
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
    // 0047e7a7  7505                   -jne 0x47e7ae
    if (!cpu.flags.zf)
    {
        goto L_0x0047e7ae;
    }
    // 0047e7a9  beffffff7f             -mov esi, 0x7fffffff
    cpu.esi = 2147483647 /*0x7fffffff*/;
L_0x0047e7ae:
    // 0047e7ae  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e7b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e7b2  e8bc050000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047e7b7  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 0047e7bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7bc  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e7be  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0047e7c1  0f8412020000           -je 0x47e9d9
    if (cpu.flags.zf)
    {
        goto L_0x0047e9d9;
    }
    // 0047e7c7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e7c9  7509                   -jne 0x47e7d4
    if (!cpu.flags.zf)
    {
        goto L_0x0047e7d4;
    }
    // 0047e7cb  8b0dd03f4a00           -mov ecx, dword ptr [0x4a3fd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4866000) /* 0x4a3fd0 */);
    // 0047e7d1  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x0047e7d4:
    // 0047e7d4  8365f800               -and dword ptr [ebp - 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047e7d8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e7da  0f8ec2030000           -jle 0x47eba2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047eba2;
    }
L_0x0047e7e0:
    // 0047e7e0  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047e7e2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047e7e4  0f84b8030000           -je 0x47eba2
    if (cpu.flags.zf)
    {
        goto L_0x0047eba2;
    }
    // 0047e7ea  8b150c624a00           -mov edx, dword ptr [0x4a620c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047e7f0  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0047e7f3  f644420180             +test byte ptr [edx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0047e7f8  7401                   -je 0x47e7fb
    if (cpu.flags.zf)
    {
        goto L_0x0047e7fb;
    }
    // 0047e7fa  41                     -inc ecx
    (cpu.ecx)++;
L_0x0047e7fb:
    // 0047e7fb  41                     -inc ecx
    (cpu.ecx)++;
    // 0047e7fc  ff45f8                 -inc dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))++;
    // 0047e7ff  3975f8                 +cmp dword ptr [ebp - 8], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e802  7cdc                   -jl 0x47e7e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e7e0;
    }
    // 0047e804  e999030000             -jmp 0x47eba2
    goto L_0x0047eba2;
L_0x0047e809:
    // 0047e809  c745cc01000000         -mov dword ptr [ebp - 0x34], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = 1 /*0x1*/;
    // 0047e810  03df                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
L_0x0047e812:
    // 0047e812  834dfc40               -or dword ptr [ebp - 4], 0x40
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047e816  3975f0                 +cmp dword ptr [ebp - 0x10], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e819  8dbdb0fbffff           -lea edi, [ebp - 0x450]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1104) /* -0x450 */);
    // 0047e81f  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 0047e822  0f8ddb000000           -jge 0x47e903
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e903;
    }
    // 0047e828  c745f006000000         -mov dword ptr [ebp - 0x10], 6
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 6 /*0x6*/;
    // 0047e82f  e9de000000             -jmp 0x47e912
    goto L_0x0047e912;
L_0x0047e834:
    // 0047e834  66f745fc3008           +test word ptr [ebp - 4], 0x830
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2096 /*0x830*/));
    // 0047e83a  7503                   -jne 0x47e83f
    if (!cpu.flags.zf)
    {
        goto L_0x0047e83f;
    }
    // 0047e83c  097dfc                 -or dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047e83f:
    // 0047e83f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047e841  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e844  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e845  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e846  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 0047e849  e825050000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047e84e  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 0047e852  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e853  8945c4                 -mov dword ptr [ebp - 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.eax;
    // 0047e856  743f                   -je 0x47e897
    if (cpu.flags.zf)
    {
        goto L_0x0047e897;
    }
    // 0047e858  ff3518644a00           -push dword ptr [0x4a6418]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
    cpu.esp -= 4;
    // 0047e85e  8065df00               -and byte ptr [ebp - 0x21], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-33) /* -0x21 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047e862  8845de                 -mov byte ptr [ebp - 0x22], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-34) /* -0x22 */) = cpu.al;
    // 0047e865  8d45de                 -lea eax, [ebp - 0x22]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-34) /* -0x22 */);
    // 0047e868  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e869  8d85b0fbffff           -lea eax, [ebp - 0x450]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1104) /* -0x450 */);
    // 0047e86f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e870  e809aaffff             -call 0x47927e
    cpu.esp -= 4;
    sub_47927e(app, cpu);
    // 0047e875  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e878  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e87a  7d22                   -jge 0x47e89e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e89e;
    }
    // 0047e87c  8975d0                 -mov dword ptr [ebp - 0x30], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.esi;
    // 0047e87f  eb1d                   -jmp 0x47e89e
    goto L_0x0047e89e;
L_0x0047e881:
    // 0047e881  83e85a                 +sub eax, 0x5a
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e884  7429                   -je 0x47e8af
    if (cpu.flags.zf)
    {
        goto L_0x0047e8af;
    }
    // 0047e886  83e809                 +sub eax, 9
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e889  74b4                   -je 0x47e83f
    if (cpu.flags.zf)
    {
        goto L_0x0047e83f;
    }
    // 0047e88b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e88c  0f84e4010000           -je 0x47ea76
    if (cpu.flags.zf)
    {
        goto L_0x0047ea76;
    }
    // 0047e892  e90b030000             -jmp 0x47eba2
    goto L_0x0047eba2;
L_0x0047e897:
    // 0047e897  668985b0fbffff         -mov word ptr [ebp - 0x450], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-1104) /* -0x450 */) = cpu.ax;
L_0x0047e89e:
    // 0047e89e  8d85b0fbffff           -lea eax, [ebp - 0x450]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1104) /* -0x450 */);
    // 0047e8a4  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0047e8a7  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047e8aa  e9f3020000             -jmp 0x47eba2
    goto L_0x0047eba2;
L_0x0047e8af:
    // 0047e8af  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e8b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e8b3  e8bb040000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047e8b8  3bc6                   +cmp eax, esi
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
    // 0047e8ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e8bb  7435                   -je 0x47e8f2
    if (cpu.flags.zf)
    {
        goto L_0x0047e8f2;
    }
    // 0047e8bd  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047e8c0  3bce                   +cmp ecx, esi
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
    // 0047e8c2  742e                   -je 0x47e8f2
    if (cpu.flags.zf)
    {
        goto L_0x0047e8f2;
    }
    // 0047e8c4  f645fd08               +test byte ptr [ebp - 3], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 8 /*0x8*/));
    // 0047e8c8  7417                   -je 0x47e8e1
    if (cpu.flags.zf)
    {
        goto L_0x0047e8e1;
    }
    // 0047e8ca  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0047e8cd  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0047e8cf  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0047e8d2  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047e8d5  c745e401000000         -mov dword ptr [ebp - 0x1c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 1 /*0x1*/;
    // 0047e8dc  e9c1020000             -jmp 0x47eba2
    goto L_0x0047eba2;
L_0x0047e8e1:
    // 0047e8e1  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0047e8e4  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 0047e8e7  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x0047e8ea:
    // 0047e8ea  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047e8ed  e9b0020000             -jmp 0x47eba2
    goto L_0x0047eba2;
L_0x0047e8f2:
    // 0047e8f2  a1d03f4a00             -mov eax, dword ptr [0x4a3fd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4866000) /* 0x4a3fd0 */);
    // 0047e8f7  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047e8fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x0047e8fb:
    // 0047e8fb  e8e0f4ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047e900  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e901  ebe7                   -jmp 0x47e8ea
    goto L_0x0047e8ea;
L_0x0047e903:
    // 0047e903  750d                   -jne 0x47e912
    if (!cpu.flags.zf)
    {
        goto L_0x0047e912;
    }
    // 0047e905  6683fb67               +cmp bx, 0x67
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(103 /*0x67*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e909  7507                   -jne 0x47e912
    if (!cpu.flags.zf)
    {
        goto L_0x0047e912;
    }
    // 0047e90b  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
L_0x0047e912:
    // 0047e912  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e915  ff75cc                 -push dword ptr [ebp - 0x34]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    cpu.esp -= 4;
    // 0047e918  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e91b  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047e91e  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0047e921  8b48f8                 -mov ecx, dword ptr [eax - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0047e924  894db0                 -mov dword ptr [ebp - 0x50], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */) = cpu.ecx;
    // 0047e927  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0047e92a  8945b4                 -mov dword ptr [ebp - 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.eax;
    // 0047e92d  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047e930  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e931  8d85b0fbffff           -lea eax, [ebp - 0x450]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1104) /* -0x450 */);
    // 0047e937  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e938  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0047e93b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e93c  ff15b83f4a00           -call dword ptr [0x4a3fb8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865976) /* 0x4a3fb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e942  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047e945  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047e948  81e680000000           +and esi, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 0047e94e  7414                   -je 0x47e964
    if (cpu.flags.zf)
    {
        goto L_0x0047e964;
    }
    // 0047e950  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e954  750e                   -jne 0x47e964
    if (!cpu.flags.zf)
    {
        goto L_0x0047e964;
    }
    // 0047e956  8d85b0fbffff           -lea eax, [ebp - 0x450]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1104) /* -0x450 */);
    // 0047e95c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e95d  ff15c43f4a00           -call dword ptr [0x4a3fc4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865988) /* 0x4a3fc4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e963  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e964:
    // 0047e964  6683fb67               +cmp bx, 0x67
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(103 /*0x67*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e968  7512                   -jne 0x47e97c
    if (!cpu.flags.zf)
    {
        goto L_0x0047e97c;
    }
    // 0047e96a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e96c  750e                   -jne 0x47e97c
    if (!cpu.flags.zf)
    {
        goto L_0x0047e97c;
    }
    // 0047e96e  8d85b0fbffff           -lea eax, [ebp - 0x450]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1104) /* -0x450 */);
    // 0047e974  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e975  ff15bc3f4a00           -call dword ptr [0x4a3fbc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865980) /* 0x4a3fbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e97b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e97c:
    // 0047e97c  80bdb0fbffff2d         +cmp byte ptr [ebp - 0x450], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1104) /* -0x450 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e983  750d                   -jne 0x47e992
    if (!cpu.flags.zf)
    {
        goto L_0x0047e992;
    }
    // 0047e985  804dfd01               +or byte ptr [ebp - 3], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047e989  8dbdb1fbffff           -lea edi, [ebp - 0x44f]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1103) /* -0x44f */);
    // 0047e98f  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
L_0x0047e992:
    // 0047e992  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e993  e963ffffff             -jmp 0x47e8fb
    goto L_0x0047e8fb;
L_0x0047e998:
    // 0047e998  83e869                 +sub eax, 0x69
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e99b  0f84d5000000           -je 0x47ea76
    if (cpu.flags.zf)
    {
        goto L_0x0047ea76;
    }
    // 0047e9a1  83e805                 +sub eax, 5
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e9a4  0f84a2000000           -je 0x47ea4c
    if (cpu.flags.zf)
    {
        goto L_0x0047ea4c;
    }
    // 0047e9aa  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e9ab  0f8488000000           -je 0x47ea39
    if (cpu.flags.zf)
    {
        goto L_0x0047ea39;
    }
    // 0047e9b1  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e9b2  7455                   -je 0x47ea09
    if (cpu.flags.zf)
    {
        goto L_0x0047ea09;
    }
    // 0047e9b4  83e803                 +sub eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e9b7  0f84e4fdffff           -je 0x47e7a1
    if (cpu.flags.zf)
    {
        goto L_0x0047e7a1;
    }
    // 0047e9bd  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e9be  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047e9bf  0f84b5000000           -je 0x47ea7a
    if (cpu.flags.zf)
    {
        goto L_0x0047ea7a;
    }
    // 0047e9c5  83e803                 +sub eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e9c8  0f85d4010000           -jne 0x47eba2
    if (!cpu.flags.zf)
    {
        goto L_0x0047eba2;
    }
    // 0047e9ce  c745d427000000         -mov dword ptr [ebp - 0x2c], 0x27
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = 39 /*0x27*/;
    // 0047e9d5  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047e9d7  eb3a                   -jmp 0x47ea13
    goto L_0x0047ea13;
L_0x0047e9d9:
    // 0047e9d9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e9db  7509                   -jne 0x47e9e6
    if (!cpu.flags.zf)
    {
        goto L_0x0047e9e6;
    }
    // 0047e9dd  8b0dd43f4a00           -mov ecx, dword ptr [0x4a3fd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4866004) /* 0x4a3fd4 */);
    // 0047e9e3  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x0047e9e6:
    // 0047e9e6  c745e401000000         -mov dword ptr [ebp - 0x1c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 1 /*0x1*/;
    // 0047e9ed  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0047e9ef:
    // 0047e9ef  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047e9f1  4e                     -dec esi
    (cpu.esi)--;
    // 0047e9f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e9f4  740a                   -je 0x47ea00
    if (cpu.flags.zf)
    {
        goto L_0x0047ea00;
    }
    // 0047e9f6  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e9fa  7404                   -je 0x47ea00
    if (cpu.flags.zf)
    {
        goto L_0x0047ea00;
    }
    // 0047e9fc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047e9fd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047e9fe  ebef                   -jmp 0x47e9ef
    goto L_0x0047e9ef;
L_0x0047ea00:
    // 0047ea00  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ea02  d1f8                   +sar eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047ea04  e9e1feffff             -jmp 0x47e8ea
    goto L_0x0047e8ea;
L_0x0047ea09:
    // 0047ea09  c745f008000000         -mov dword ptr [ebp - 0x10], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 8 /*0x8*/;
L_0x0047ea10:
    // 0047ea10  894dd4                 -mov dword ptr [ebp - 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ecx;
L_0x0047ea13:
    // 0047ea13  f645fc80               +test byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 128 /*0x80*/));
    // 0047ea17  c745f810000000         -mov dword ptr [ebp - 8], 0x10
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 16 /*0x10*/;
    // 0047ea1e  7461                   -je 0x47ea81
    if (cpu.flags.zf)
    {
        goto L_0x0047ea81;
    }
    // 0047ea20  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0047ea23  66c745e03000           -mov word ptr [ebp - 0x20], 0x30
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 48 /*0x30*/;
    // 0047ea29  83c051                 +add eax, 0x51
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(81 /*0x51*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ea2c  c745e802000000         -mov dword ptr [ebp - 0x18], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = 2 /*0x2*/;
    // 0047ea33  668945e2               -mov word ptr [ebp - 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-30) /* -0x1e */) = cpu.ax;
    // 0047ea37  eb48                   -jmp 0x47ea81
    goto L_0x0047ea81;
L_0x0047ea39:
    // 0047ea39  f645fc80               +test byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 128 /*0x80*/));
    // 0047ea3d  c745f808000000         -mov dword ptr [ebp - 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 8 /*0x8*/;
    // 0047ea44  743b                   -je 0x47ea81
    if (cpu.flags.zf)
    {
        goto L_0x0047ea81;
    }
    // 0047ea46  804dfd02               +or byte ptr [ebp - 3], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0047ea4a  eb35                   -jmp 0x47ea81
    goto L_0x0047ea81;
L_0x0047ea4c:
    // 0047ea4c  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ea4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ea50  e81e030000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047ea55  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 0047ea59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea5a  7409                   -je 0x47ea65
    if (cpu.flags.zf)
    {
        goto L_0x0047ea65;
    }
    // 0047ea5c  668b4dec               -mov cx, word ptr [ebp - 0x14]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ea60  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0047ea63  eb05                   -jmp 0x47ea6a
    goto L_0x0047ea6a;
L_0x0047ea65:
    // 0047ea65  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ea68  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
L_0x0047ea6a:
    // 0047ea6a  c745d001000000         -mov dword ptr [ebp - 0x30], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = 1 /*0x1*/;
    // 0047ea71  e936020000             -jmp 0x47ecac
    goto L_0x0047ecac;
L_0x0047ea76:
    // 0047ea76  834dfc40               -or dword ptr [ebp - 4], 0x40
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x0047ea7a:
    // 0047ea7a  c745f80a000000         -mov dword ptr [ebp - 8], 0xa
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 10 /*0xa*/;
L_0x0047ea81:
    // 0047ea81  f645fd80               +test byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 128 /*0x80*/));
    // 0047ea85  740c                   -je 0x47ea93
    if (cpu.flags.zf)
    {
        goto L_0x0047ea93;
    }
    // 0047ea87  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ea8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ea8b  e8f0020000             -call 0x47ed80
    cpu.esp -= 4;
    sub_47ed80(app, cpu);
    // 0047ea90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea91  eb41                   -jmp 0x47ead4
    goto L_0x0047ead4;
L_0x0047ea93:
    // 0047ea93  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 0047ea97  7421                   -je 0x47eaba
    if (cpu.flags.zf)
    {
        goto L_0x0047eaba;
    }
    // 0047ea99  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 0047ea9d  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047eaa0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eaa1  740c                   -je 0x47eaaf
    if (cpu.flags.zf)
    {
        goto L_0x0047eaaf;
    }
    // 0047eaa3  e8cb020000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047eaa8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eaa9  0fbfc0                 -movsx eax, ax
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
L_0x0047eaac:
    // 0047eaac  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047eaad  eb25                   -jmp 0x47ead4
    goto L_0x0047ead4;
L_0x0047eaaf:
    // 0047eaaf  e8bf020000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047eab4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eab5  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 0047eab8  ebf2                   -jmp 0x47eaac
    goto L_0x0047eaac;
L_0x0047eaba:
    // 0047eaba  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 0047eabe  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047eac1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eac2  7408                   -je 0x47eacc
    if (cpu.flags.zf)
    {
        goto L_0x0047eacc;
    }
    // 0047eac4  e8aa020000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047eac9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eaca  ebe0                   -jmp 0x47eaac
    goto L_0x0047eaac;
L_0x0047eacc:
    // 0047eacc  e8a2020000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047ead1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ead2  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047ead4:
    // 0047ead4  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 0047ead8  741b                   -je 0x47eaf5
    if (cpu.flags.zf)
    {
        goto L_0x0047eaf5;
    }
    // 0047eada  3bd6                   +cmp edx, esi
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
    // 0047eadc  7f17                   -jg 0x47eaf5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047eaf5;
    }
    // 0047eade  7c04                   -jl 0x47eae4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047eae4;
    }
    // 0047eae0  3bc6                   +cmp eax, esi
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
    // 0047eae2  7311                   -jae 0x47eaf5
    if (!cpu.flags.cf)
    {
        goto L_0x0047eaf5;
    }
L_0x0047eae4:
    // 0047eae4  f7d8                   +neg eax
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
    // 0047eae6  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 0047eae9  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047eaeb  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0047eaed  804dfd01               +or byte ptr [ebp - 3], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047eaf1  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047eaf3  eb04                   -jmp 0x47eaf9
    goto L_0x0047eaf9;
L_0x0047eaf5:
    // 0047eaf5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047eaf7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x0047eaf9:
    // 0047eaf9  f645fd80               +test byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 128 /*0x80*/));
    // 0047eafd  7503                   -jne 0x47eb02
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb02;
    }
    // 0047eaff  83e700                 -and edi, 0
    cpu.edi &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047eb02:
    // 0047eb02  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eb06  7d09                   -jge 0x47eb11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047eb11;
    }
    // 0047eb08  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 0047eb0f  eb04                   -jmp 0x47eb15
    goto L_0x0047eb15;
L_0x0047eb11:
    // 0047eb11  8365fcf7               -and dword ptr [ebp - 4], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
L_0x0047eb15:
    // 0047eb15  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047eb17  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047eb19  7504                   -jne 0x47eb1f
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb1f;
    }
    // 0047eb1b  8365e800               -and dword ptr [ebp - 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047eb1f:
    // 0047eb1f  8d85affdffff           -lea eax, [ebp - 0x251]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-593) /* -0x251 */);
    // 0047eb25  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0047eb28:
    // 0047eb28  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047eb2b  ff4df0                 -dec dword ptr [ebp - 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))--;
    // 0047eb2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047eb30  7f06                   -jg 0x47eb38
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047eb38;
    }
    // 0047eb32  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047eb34  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047eb36  743b                   -je 0x47eb73
    if (cpu.flags.zf)
    {
        goto L_0x0047eb73;
    }
L_0x0047eb38:
    // 0047eb38  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047eb3b  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047eb3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eb3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eb3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047eb3f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eb40  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 0047eb43  8955bc                 -mov dword ptr [ebp - 0x44], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edx;
    // 0047eb46  e8b5370000             -call 0x482300
    cpu.esp -= 4;
    __aullrem(app, cpu);
    // 0047eb4b  ff75bc                 -push dword ptr [ebp - 0x44]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    cpu.esp -= 4;
    // 0047eb4e  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047eb50  83c330                 -add ebx, 0x30
    (cpu.ebx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047eb53  ff75b8                 -push dword ptr [ebp - 0x48]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    cpu.esp -= 4;
    // 0047eb56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047eb57  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eb58  e833370000             -call 0x482290
    cpu.esp -= 4;
    __aulldiv(app, cpu);
    // 0047eb5d  83fb39                 +cmp ebx, 0x39
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eb60  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047eb62  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047eb64  7e03                   -jle 0x47eb69
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047eb69;
    }
    // 0047eb66  035dd4                 +add ebx, dword ptr [ebp - 0x2c]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0047eb69:
    // 0047eb69  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047eb6c  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047eb6f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0047eb71  ebb5                   -jmp 0x47eb28
    goto L_0x0047eb28;
L_0x0047eb73:
    // 0047eb73  8d85affdffff           -lea eax, [ebp - 0x251]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-593) /* -0x251 */);
    // 0047eb79  2b45f4                 -sub eax, dword ptr [ebp - 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0047eb7c  ff45f4                 -inc dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))++;
    // 0047eb7f  f645fd02               +test byte ptr [ebp - 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 2 /*0x2*/));
    // 0047eb83  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047eb86  741a                   -je 0x47eba2
    if (cpu.flags.zf)
    {
        goto L_0x0047eba2;
    }
    // 0047eb88  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047eb8b  803830                 +cmp byte ptr [eax], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047eb8e  7506                   -jne 0x47eb96
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb96;
    }
    // 0047eb90  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eb94  750c                   -jne 0x47eba2
    if (!cpu.flags.zf)
    {
        goto L_0x0047eba2;
    }
L_0x0047eb96:
    // 0047eb96  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0047eb99  ff45f8                 -inc dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))++;
    // 0047eb9c  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047eb9f  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
L_0x0047eba2:
    // 0047eba2  837dd000               +cmp dword ptr [ebp - 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eba6  0f8500010000           -jne 0x47ecac
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecac;
    }
    // 0047ebac  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047ebaf  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047ebb2  742c                   -je 0x47ebe0
    if (cpu.flags.zf)
    {
        goto L_0x0047ebe0;
    }
    // 0047ebb4  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0047ebb7  7408                   -je 0x47ebc1
    if (cpu.flags.zf)
    {
        goto L_0x0047ebc1;
    }
    // 0047ebb9  66c745e02d00           -mov word ptr [ebp - 0x20], 0x2d
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 45 /*0x2d*/;
    // 0047ebbf  eb18                   -jmp 0x47ebd9
    goto L_0x0047ebd9;
L_0x0047ebc1:
    // 0047ebc1  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0047ebc4  7408                   -je 0x47ebce
    if (cpu.flags.zf)
    {
        goto L_0x0047ebce;
    }
    // 0047ebc6  66c745e02b00           -mov word ptr [ebp - 0x20], 0x2b
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 43 /*0x2b*/;
    // 0047ebcc  eb0b                   -jmp 0x47ebd9
    goto L_0x0047ebd9;
L_0x0047ebce:
    // 0047ebce  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0047ebd1  740d                   -je 0x47ebe0
    if (cpu.flags.zf)
    {
        goto L_0x0047ebe0;
    }
    // 0047ebd3  66c745e02000           -mov word ptr [ebp - 0x20], 0x20
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 32 /*0x20*/;
L_0x0047ebd9:
    // 0047ebd9  c745e801000000         -mov dword ptr [ebp - 0x18], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = 1 /*0x1*/;
L_0x0047ebe0:
    // 0047ebe0  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047ebe3  2b75e8                 -sub esi, dword ptr [ebp - 0x18]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0047ebe6  2b75f8                 -sub esi, dword ptr [ebp - 8]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047ebe9  f6c30c                 +test bl, 0xc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 12 /*0xc*/));
    // 0047ebec  7512                   -jne 0x47ec00
    if (!cpu.flags.zf)
    {
        goto L_0x0047ec00;
    }
    // 0047ebee  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ebf1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ebf2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ebf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ebf6  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047ebf8  e80c010000             -call 0x47ed09
    cpu.esp -= 4;
    sub_47ed09(app, cpu);
    // 0047ebfd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047ec00:
    // 0047ec00  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ec03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec04  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047ec07  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ec0a  ff75e8                 -push dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    // 0047ec0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec0e  e827010000             -call 0x47ed3a
    cpu.esp -= 4;
    sub_47ed3a(app, cpu);
    // 0047ec13  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047ec16  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0047ec19  7417                   -je 0x47ec32
    if (cpu.flags.zf)
    {
        goto L_0x0047ec32;
    }
    // 0047ec1b  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0047ec1e  7512                   -jne 0x47ec32
    if (!cpu.flags.zf)
    {
        goto L_0x0047ec32;
    }
    // 0047ec20  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ec23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec24  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ec27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ec28  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0047ec2a  e8da000000             -call 0x47ed09
    cpu.esp -= 4;
    sub_47ed09(app, cpu);
    // 0047ec2f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047ec32:
    // 0047ec32  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ec36  7547                   -jne 0x47ec7f
    if (!cpu.flags.zf)
    {
        goto L_0x0047ec7f;
    }
    // 0047ec38  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ec3c  7e41                   -jle 0x47ec7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ec7f;
    }
    // 0047ec3e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047ec41  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047ec44  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0047ec47:
    // 0047ec47  ff3518644a00           -push dword ptr [0x4a6418]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
    cpu.esp -= 4;
    // 0047ec4d  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0047ec50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ec51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec52  e827a6ffff             -call 0x47927e
    cpu.esp -= 4;
    sub_47927e(app, cpu);
    // 0047ec57  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ec5a  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 0047ec5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ec5f  7e33                   -jle 0x47ec94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ec94;
    }
    // 0047ec61  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ec64  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec65  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ec68  ff75c4                 -push dword ptr [ebp - 0x3c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    cpu.esp -= 4;
    // 0047ec6b  e879000000             -call 0x47ece9
    cpu.esp -= 4;
    sub_47ece9(app, cpu);
    // 0047ec70  037dc0                 -add edi, dword ptr [ebp - 0x40]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
    // 0047ec73  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ec76  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ec78  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047ec79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ec7b  7fca                   -jg 0x47ec47
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ec47;
    }
    // 0047ec7d  eb15                   -jmp 0x47ec94
    goto L_0x0047ec94;
L_0x0047ec7f:
    // 0047ec7f  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ec82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec83  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ec86  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0047ec89  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0047ec8c  e8a9000000             -call 0x47ed3a
    cpu.esp -= 4;
    sub_47ed3a(app, cpu);
    // 0047ec91  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047ec94:
    // 0047ec94  f645fc04               +test byte ptr [ebp - 4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4 /*0x4*/));
    // 0047ec98  7412                   -je 0x47ecac
    if (cpu.flags.zf)
    {
        goto L_0x0047ecac;
    }
    // 0047ec9a  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ec9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec9e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047eca1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eca2  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047eca4  e860000000             -call 0x47ed09
    cpu.esp -= 4;
    sub_47ed09(app, cpu);
    // 0047eca9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047ecac:
    // 0047ecac  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ecaf  83450c02               -add dword ptr [ebp + 0xc], 2
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047ecb3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047ecb5  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0047ecb8  663bde                 +cmp bx, si
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.si));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047ecbb  0f8506f9ffff           -jne 0x47e5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0047e5c7;
    }
L_0x0047ecc1:
    // 0047ecc1  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047ecc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecc7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecc8  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_47ece9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ece9  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047eced  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ecf1  e8473d0000             -call 0x482a3d
    cpu.esp -= 4;
    sub_482a3d(app, cpu);
    // 0047ecf6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecf7  663dffff               +cmp ax, 0xffff
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047ecfb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ecff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed00  7504                   -jne 0x47ed06
    if (!cpu.flags.zf)
    {
        goto L_0x0047ed06;
    }
    // 0047ed02  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047ed05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed06:
    // 0047ed06  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 0047ed08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ed09(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ed0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ed0b  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ed0f  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ed11  4f                     -dec edi
    (cpu.edi)--;
    // 0047ed12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ed14  7e21                   -jle 0x47ed37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ed37;
    }
    // 0047ed16  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0047ed1a:
    // 0047ed1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ed1b  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047ed1f  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047ed23  e8c1ffffff             -call 0x47ece9
    cpu.esp -= 4;
    sub_47ece9(app, cpu);
    // 0047ed28  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ed2b  833eff                 +cmp dword ptr [esi], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ed2e  7407                   -je 0x47ed37
    if (cpu.flags.zf)
    {
        goto L_0x0047ed37;
    }
    // 0047ed30  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ed32  4f                     -dec edi
    (cpu.edi)--;
    // 0047ed33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ed35  7fe3                   -jg 0x47ed1a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ed1a;
    }
L_0x0047ed37:
    // 0047ed37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ed3a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ed3b  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ed3f  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ed41  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047ed42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ed43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ed44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ed46  7e27                   -jle 0x47ed6f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ed6f;
    }
    // 0047ed48  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047ed4c  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047ed50:
    // 0047ed50  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0047ed53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ed54  ff74241c               -push dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047ed58  46                     -inc esi
    (cpu.esi)++;
    // 0047ed59  46                     -inc esi
    (cpu.esi)++;
    // 0047ed5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ed5b  e889ffffff             -call 0x47ece9
    cpu.esp -= 4;
    sub_47ece9(app, cpu);
    // 0047ed60  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ed63  833fff                 +cmp dword ptr [edi], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ed66  7407                   -je 0x47ed6f
    if (cpu.flags.zf)
    {
        goto L_0x0047ed6f;
    }
    // 0047ed68  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ed6a  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047ed6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ed6d  7fe1                   -jg 0x47ed50
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ed50;
    }
L_0x0047ed6f:
    // 0047ed6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ed73(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed73  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ed77  830004                 -add dword ptr [eax], 4
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ed7a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ed7c  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0047ed7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ed80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed80  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ed84  830008                 -add dword ptr [eax], 8
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047ed87  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ed89  8b41f8                 -mov eax, dword ptr [ecx - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-8) /* -0x8 */);
    // 0047ed8c  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0047ed8f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ed90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ed91  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047ed93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ed94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ed95  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ed96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ed97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ed98  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ed9a  397d08                 +cmp dword ptr [ebp + 8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ed9d  7454                   -je 0x47edf3
    if (cpu.flags.zf)
    {
        goto L_0x0047edf3;
    }
    // 0047ed9f  6a3d                   -push 0x3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 61 /*0x3d*/;
    cpu.esp -= 4;
    // 0047eda1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047eda4  e8f53d0000             -call 0x482b9e
    cpu.esp -= 4;
    sub_482b9e(app, cpu);
    // 0047eda9  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047edab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edac  3bf7                   +cmp esi, edi
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
    // 0047edae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edaf  7442                   -je 0x47edf3
    if (cpu.flags.zf)
    {
        goto L_0x0047edf3;
    }
    // 0047edb1  397508                 +cmp dword ptr [ebp + 8], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047edb4  743d                   -je 0x47edf3
    if (cpu.flags.zf)
    {
        goto L_0x0047edf3;
    }
    // 0047edb6  a110eb5100             -mov eax, dword ptr [0x51eb10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
    // 0047edbb  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047edbd  66397e02               +cmp word ptr [esi + 2], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047edc1  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 0047edc4  3b0514eb5100           +cmp eax, dword ptr [0x51eb14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5368596) /* 0x51eb14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047edca  750c                   -jne 0x47edd8
    if (!cpu.flags.zf)
    {
        goto L_0x0047edd8;
    }
    // 0047edcc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047edcd  e8ad010000             -call 0x47ef7f
    cpu.esp -= 4;
    sub_47ef7f(app, cpu);
    // 0047edd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edd3  a310eb5100             -mov dword ptr [0x51eb10], eax
    app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */) = cpu.eax;
L_0x0047edd8:
    // 0047edd8  3bc7                   +cmp eax, edi
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
    // 0047edda  7559                   -jne 0x47ee35
    if (!cpu.flags.zf)
    {
        goto L_0x0047ee35;
    }
    // 0047eddc  397d0c                 +cmp dword ptr [ebp + 0xc], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eddf  a108eb5100             -mov eax, dword ptr [0x51eb08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */);
    // 0047ede4  7415                   -je 0x47edfb
    if (cpu.flags.zf)
    {
        goto L_0x0047edfb;
    }
    // 0047ede6  3bc7                   +cmp eax, edi
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
    // 0047ede8  7411                   -je 0x47edfb
    if (cpu.flags.zf)
    {
        goto L_0x0047edfb;
    }
    // 0047edea  e8473d0000             -call 0x482b36
    cpu.esp -= 4;
    sub_482b36(app, cpu);
    // 0047edef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047edf1  7442                   -je 0x47ee35
    if (cpu.flags.zf)
    {
        goto L_0x0047ee35;
    }
L_0x0047edf3:
    // 0047edf3  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0047edf6:
    // 0047edf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edf9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047edfb:
    // 0047edfb  3bdf                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047edfd  0f8519010000           -jne 0x47ef1c
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef1c;
    }
    // 0047ee03  3bc7                   +cmp eax, edi
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
    // 0047ee05  751b                   -jne 0x47ee22
    if (!cpu.flags.zf)
    {
        goto L_0x0047ee22;
    }
    // 0047ee07  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047ee09  e86c84ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047ee0e  3bc7                   +cmp eax, edi
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
    // 0047ee10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee11  a308eb5100             -mov dword ptr [0x51eb08], eax
    app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */) = cpu.eax;
    // 0047ee16  74db                   -je 0x47edf3
    if (cpu.flags.zf)
    {
        goto L_0x0047edf3;
    }
    // 0047ee18  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0047ee1a  393d10eb5100           +cmp dword ptr [0x51eb10], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ee20  7513                   -jne 0x47ee35
    if (!cpu.flags.zf)
    {
        goto L_0x0047ee35;
    }
L_0x0047ee22:
    // 0047ee22  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047ee24  e85184ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047ee29  3bc7                   +cmp eax, edi
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
    // 0047ee2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee2c  a310eb5100             -mov dword ptr [0x51eb10], eax
    app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */) = cpu.eax;
    // 0047ee31  74c0                   -je 0x47edf3
    if (cpu.flags.zf)
    {
        goto L_0x0047edf3;
    }
    // 0047ee33  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0047ee35:
    // 0047ee35  2b7508                 -sub esi, dword ptr [ebp + 8]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0047ee38  8b3d10eb5100           -mov edi, dword ptr [0x51eb10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
    // 0047ee3e  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0047ee41  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0047ee43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ee44  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0047ee47  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ee4a  e8d4000000             -call 0x47ef23
    cpu.esp -= 4;
    sub_47ef23(app, cpu);
    // 0047ee4f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ee51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee52  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047ee54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee55  7c43                   -jl 0x47ee9a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ee9a;
    }
    // 0047ee57  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ee5a  743e                   -je 0x47ee9a
    if (cpu.flags.zf)
    {
        goto L_0x0047ee9a;
    }
    // 0047ee5c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047ee5e  7432                   -je 0x47ee92
    if (cpu.flags.zf)
    {
        goto L_0x0047ee92;
    }
    // 0047ee60  ff34b7                 -push dword ptr [edi + esi*4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    cpu.esp -= 4;
    // 0047ee63  8d3cb7                 -lea edi, [edi + esi*4]
    cpu.edi = x86::reg32(cpu.edi + cpu.esi * 4);
    // 0047ee66  e84985ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047ee6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047ee6c:
    // 0047ee6c  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ee6f  740b                   -je 0x47ee7c
    if (cpu.flags.zf)
    {
        goto L_0x0047ee7c;
    }
    // 0047ee71  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047ee74  46                     -inc esi
    (cpu.esi)++;
    // 0047ee75  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047ee77  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ee7a  ebf0                   -jmp 0x47ee6c
    goto L_0x0047ee6c;
L_0x0047ee7c:
    // 0047ee7c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ee7e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047ee81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ee82  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047ee85  e8c180ffff             -call 0x476f4b
    cpu.esp -= 4;
    sub_476f4b(app, cpu);
    // 0047ee8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ee8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee8e  743c                   -je 0x47eecc
    if (cpu.flags.zf)
    {
        goto L_0x0047eecc;
    }
    // 0047ee90  eb35                   -jmp 0x47eec7
    goto L_0x0047eec7;
L_0x0047ee92:
    // 0047ee92  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ee95  8904b7                 -mov dword ptr [edi + esi*4], eax
    app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4) = cpu.eax;
    // 0047ee98  eb32                   -jmp 0x47eecc
    goto L_0x0047eecc;
L_0x0047ee9a:
    // 0047ee9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047ee9c  757e                   -jne 0x47ef1c
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef1c;
    }
    // 0047ee9e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047eea0  7d02                   -jge 0x47eea4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047eea4;
    }
    // 0047eea2  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x0047eea4:
    // 0047eea4  8d04b508000000         -lea eax, [esi*4 + 8]
    cpu.eax = x86::reg32(x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    // 0047eeab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eeac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047eead  e89980ffff             -call 0x476f4b
    cpu.esp -= 4;
    sub_476f4b(app, cpu);
    // 0047eeb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eeb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047eeb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eeb6  0f8437ffffff           -je 0x47edf3
    if (cpu.flags.zf)
    {
        goto L_0x0047edf3;
    }
    // 0047eebc  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047eebf  890cb0                 -mov dword ptr [eax + esi*4], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4) = cpu.ecx;
    // 0047eec2  8364b00400             -and dword ptr [eax + esi*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047eec7:
    // 0047eec7  a310eb5100             -mov dword ptr [0x51eb10], eax
    app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */) = cpu.eax;
L_0x0047eecc:
    // 0047eecc  837d0c00               +cmp dword ptr [ebp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eed0  744a                   -je 0x47ef1c
    if (cpu.flags.zf)
    {
        goto L_0x0047ef1c;
    }
    // 0047eed2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047eed5  e8c38effff             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 0047eeda  8d440004               -lea eax, [eax + eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047eede  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eedf  e89683ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047eee4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047eee6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eee7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047eee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eeea  7430                   -je 0x47ef1c
    if (cpu.flags.zf)
    {
        goto L_0x0047ef1c;
    }
    // 0047eeec  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047eeef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eef0  e8838effff             -call 0x477d78
    cpu.esp -= 4;
    sub_477d78(app, cpu);
    // 0047eef5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047eef8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eef9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eefa  6683244600             -and word ptr [esi + eax*2], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2) &= x86::reg16(x86::sreg16(0 /*0x0*/));
    // 0047eeff  8d0446                 -lea eax, [esi + eax*2]
    cpu.eax = x86::reg32(cpu.esi + cpu.eax * 2);
    // 0047ef02  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047ef05  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0047ef07  1bdb                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 0047ef09  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047ef0b  23d8                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ef0d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ef0e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ef0f  ff1538714800           -call dword ptr [0x487138]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747576) /* 0x487138 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047ef15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ef16  e89984ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047ef1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047ef1c:
    // 0047ef1c  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047ef1e  e9d3feffff             -jmp 0x47edf6
    goto L_0x0047edf6;
}

/* align: skip  */
void Application::sub_47ef23(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ef23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ef24  8b3510eb5100           -mov esi, dword ptr [0x51eb10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
    // 0047ef2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ef2b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047ef2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ef2f  7431                   -je 0x47ef62
    if (cpu.flags.zf)
    {
        goto L_0x0047ef62;
    }
    // 0047ef31  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047ef35:
    // 0047ef35  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ef36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ef37  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047ef3b  e8873c0000             -call 0x482bc7
    cpu.esp -= 4;
    sub_482bc7(app, cpu);
    // 0047ef40  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ef43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ef45  7511                   -jne 0x47ef58
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef58;
    }
    // 0047ef47  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047ef49  668b0478               -mov ax, word ptr [eax + edi*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + cpu.edi * 2);
    // 0047ef4d  663d3d00               +cmp ax, 0x3d
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047ef51  741f                   -je 0x47ef72
    if (cpu.flags.zf)
    {
        goto L_0x0047ef72;
    }
    // 0047ef53  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0047ef56  741a                   -je 0x47ef72
    if (cpu.flags.zf)
    {
        goto L_0x0047ef72;
    }
L_0x0047ef58:
    // 0047ef58  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047ef5b  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ef60  75d3                   -jne 0x47ef35
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef35;
    }
L_0x0047ef62:
    // 0047ef62  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ef64  2b0510eb5100           -sub eax, dword ptr [0x51eb10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */)));
    // 0047ef6a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0047ef6d  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0047ef6f:
    // 0047ef6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ef72:
    // 0047ef72  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ef74  2b0510eb5100           -sub eax, dword ptr [0x51eb10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */)));
    // 0047ef7a  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047ef7d  ebf0                   -jmp 0x47ef6f
    goto L_0x0047ef6f;
}

/* align: skip  */
void Application::sub_47ef7f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ef7f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ef80  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ef84  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ef86  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047ef88  7504                   -jne 0x47ef8e
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef8e;
    }
    // 0047ef8a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ef8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ef8e:
    // 0047ef8e  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ef91  8d4704                 -lea eax, [edi + 4]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047ef94  740a                   -je 0x47efa0
    if (cpu.flags.zf)
    {
        goto L_0x0047efa0;
    }
L_0x0047ef96:
    // 0047ef96  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ef98  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ef99  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef9c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ef9e  75f6                   -jne 0x47ef96
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef96;
    }
L_0x0047efa0:
    // 0047efa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047efa1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047efa2  8d048d04000000         -lea eax, [ecx*4 + 4]
    cpu.eax = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 0047efa9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047efaa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047efab  e8ca82ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047efb0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047efb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047efb5  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047efb7  7508                   -jne 0x47efc1
    if (!cpu.flags.zf)
    {
        goto L_0x0047efc1;
    }
    // 0047efb9  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047efbb  e879b1ffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 0047efc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047efc1:
    // 0047efc1  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047efc3  8bdf                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0047efc5:
    // 0047efc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047efc7  7413                   -je 0x47efdc
    if (cpu.flags.zf)
    {
        goto L_0x0047efdc;
    }
    // 0047efc9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047efca  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047efcd  e8d63c0000             -call 0x482ca8
    cpu.esp -= 4;
    sub_482ca8(app, cpu);
    // 0047efd2  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047efd4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047efd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efd7  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047efda  ebe9                   -jmp 0x47efc5
    goto L_0x0047efc5;
L_0x0047efdc:
    // 0047efdc  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047efdf  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047efe1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efe2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efe3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efe5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47efe6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047efe6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047efe7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047efe9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047efea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047efeb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047efec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047efed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047efee  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047eff0  397d08                 +cmp dword ptr [ebp + 8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eff3  7455                   -je 0x47f04a
    if (cpu.flags.zf)
    {
        goto L_0x0047f04a;
    }
    // 0047eff5  6a3d                   -push 0x3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 61 /*0x3d*/;
    cpu.esp -= 4;
    // 0047eff7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047effa  e8d73c0000             -call 0x482cd6
    cpu.esp -= 4;
    sub_482cd6(app, cpu);
    // 0047efff  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f001  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f002  3bf7                   +cmp esi, edi
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
    // 0047f004  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f005  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0047f008  7440                   -je 0x47f04a
    if (cpu.flags.zf)
    {
        goto L_0x0047f04a;
    }
    // 0047f00a  397508                 +cmp dword ptr [ebp + 8], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f00d  743b                   -je 0x47f04a
    if (cpu.flags.zf)
    {
        goto L_0x0047f04a;
    }
    // 0047f00f  a108eb5100             -mov eax, dword ptr [0x51eb08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */);
    // 0047f014  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f016  385e01                 +cmp byte ptr [esi + 1], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f019  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 0047f01c  3b050ceb5100           +cmp eax, dword ptr [0x51eb0c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5368588) /* 0x51eb0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f022  750c                   -jne 0x47f030
    if (!cpu.flags.zf)
    {
        goto L_0x0047f030;
    }
    // 0047f024  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f025  e89b010000             -call 0x47f1c5
    cpu.esp -= 4;
    sub_47f1c5(app, cpu);
    // 0047f02a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f02b  a308eb5100             -mov dword ptr [0x51eb08], eax
    app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */) = cpu.eax;
L_0x0047f030:
    // 0047f030  3bc7                   +cmp eax, edi
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
    // 0047f032  7554                   -jne 0x47f088
    if (!cpu.flags.zf)
    {
        goto L_0x0047f088;
    }
    // 0047f034  397d0c                 +cmp dword ptr [ebp + 0xc], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f037  7419                   -je 0x47f052
    if (cpu.flags.zf)
    {
        goto L_0x0047f052;
    }
    // 0047f039  393d10eb5100           +cmp dword ptr [0x51eb10], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f03f  7411                   -je 0x47f052
    if (cpu.flags.zf)
    {
        goto L_0x0047f052;
    }
    // 0047f041  e8a2150000             -call 0x4805e8
    cpu.esp -= 4;
    sub_4805e8(app, cpu);
    // 0047f046  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f048  743e                   -je 0x47f088
    if (cpu.flags.zf)
    {
        goto L_0x0047f088;
    }
L_0x0047f04a:
    // 0047f04a  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0047f04d:
    // 0047f04d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f04e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f04f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f050  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f051  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f052:
    // 0047f052  3bdf                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f054  0f850c010000           -jne 0x47f166
    if (!cpu.flags.zf)
    {
        goto L_0x0047f166;
    }
    // 0047f05a  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047f05c  e81982ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047f061  3bc7                   +cmp eax, edi
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
    // 0047f063  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f064  a308eb5100             -mov dword ptr [0x51eb08], eax
    app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */) = cpu.eax;
    // 0047f069  74df                   -je 0x47f04a
    if (cpu.flags.zf)
    {
        goto L_0x0047f04a;
    }
    // 0047f06b  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0047f06d  393d10eb5100           +cmp dword ptr [0x51eb10], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f073  7513                   -jne 0x47f088
    if (!cpu.flags.zf)
    {
        goto L_0x0047f088;
    }
    // 0047f075  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047f077  e8fe81ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047f07c  3bc7                   +cmp eax, edi
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
    // 0047f07e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f07f  a310eb5100             -mov dword ptr [0x51eb10], eax
    app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */) = cpu.eax;
    // 0047f084  74c4                   -je 0x47f04a
    if (cpu.flags.zf)
    {
        goto L_0x0047f04a;
    }
    // 0047f086  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0047f088:
    // 0047f088  2b7508                 -sub esi, dword ptr [ebp + 8]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0047f08b  8b3d08eb5100           -mov edi, dword ptr [0x51eb08]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */);
    // 0047f091  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0047f094  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f095  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f098  e8d0000000             -call 0x47f16d
    cpu.esp -= 4;
    sub_47f16d(app, cpu);
    // 0047f09d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f09f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0a0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f0a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0a3  7c43                   -jl 0x47f0e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f0e8;
    }
    // 0047f0a5  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f0a8  743e                   -je 0x47f0e8
    if (cpu.flags.zf)
    {
        goto L_0x0047f0e8;
    }
    // 0047f0aa  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f0ac  7432                   -je 0x47f0e0
    if (cpu.flags.zf)
    {
        goto L_0x0047f0e0;
    }
    // 0047f0ae  ff34b7                 -push dword ptr [edi + esi*4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4);
    cpu.esp -= 4;
    // 0047f0b1  8d3cb7                 -lea edi, [edi + esi*4]
    cpu.edi = x86::reg32(cpu.edi + cpu.esi * 4);
    // 0047f0b4  e8fb82ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047f0b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f0ba:
    // 0047f0ba  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f0bd  740b                   -je 0x47f0ca
    if (cpu.flags.zf)
    {
        goto L_0x0047f0ca;
    }
    // 0047f0bf  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047f0c2  46                     -inc esi
    (cpu.esi)++;
    // 0047f0c3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047f0c5  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f0c8  ebf0                   -jmp 0x47f0ba
    goto L_0x0047f0ba;
L_0x0047f0ca:
    // 0047f0ca  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f0cc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047f0cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f0d0  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047f0d3  e8737effff             -call 0x476f4b
    cpu.esp -= 4;
    sub_476f4b(app, cpu);
    // 0047f0d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f0db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0dc  743c                   -je 0x47f11a
    if (cpu.flags.zf)
    {
        goto L_0x0047f11a;
    }
    // 0047f0de  eb35                   -jmp 0x47f115
    goto L_0x0047f115;
L_0x0047f0e0:
    // 0047f0e0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047f0e3  8904b7                 -mov dword ptr [edi + esi*4], eax
    app->getMemory<x86::reg32>(cpu.edi + cpu.esi * 4) = cpu.eax;
    // 0047f0e6  eb32                   -jmp 0x47f11a
    goto L_0x0047f11a;
L_0x0047f0e8:
    // 0047f0e8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f0ea  757a                   -jne 0x47f166
    if (!cpu.flags.zf)
    {
        goto L_0x0047f166;
    }
    // 0047f0ec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f0ee  7d02                   -jge 0x47f0f2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f0f2;
    }
    // 0047f0f0  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x0047f0f2:
    // 0047f0f2  8d04b508000000         -lea eax, [esi*4 + 8]
    cpu.eax = x86::reg32(x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    // 0047f0f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f0fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f0fb  e84b7effff             -call 0x476f4b
    cpu.esp -= 4;
    sub_476f4b(app, cpu);
    // 0047f100  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f101  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f103  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f104  0f8440ffffff           -je 0x47f04a
    if (cpu.flags.zf)
    {
        goto L_0x0047f04a;
    }
    // 0047f10a  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047f10d  890cb0                 -mov dword ptr [eax + esi*4], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4) = cpu.ecx;
    // 0047f110  8364b00400             -and dword ptr [eax + esi*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047f115:
    // 0047f115  a308eb5100             -mov dword ptr [0x51eb08], eax
    app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */) = cpu.eax;
L_0x0047f11a:
    // 0047f11a  837d0c00               +cmp dword ptr [ebp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f11e  7446                   -je 0x47f166
    if (cpu.flags.zf)
    {
        goto L_0x0047f166;
    }
    // 0047f120  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f123  e8b8ecffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047f128  40                     -inc eax
    (cpu.eax)++;
    // 0047f129  40                     -inc eax
    (cpu.eax)++;
    // 0047f12a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f12b  e84a81ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047f130  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f132  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f133  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f135  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f136  742e                   -je 0x47f166
    if (cpu.flags.zf)
    {
        goto L_0x0047f166;
    }
    // 0047f138  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f13b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f13c  e8ef000000             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 0047f141  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f143  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f144  2b4508                 -sub eax, dword ptr [ebp + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0047f147  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f148  0345f8                 -add eax, dword ptr [ebp - 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047f14b  802000                 -and byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047f14e  40                     -inc eax
    (cpu.eax)++;
    // 0047f14f  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0047f151  1bdb                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 0047f153  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047f155  23d8                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f157  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f158  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f159  ff1534714800           -call dword ptr [0x487134]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747572) /* 0x487134 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f15f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f160  e84f82ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047f165  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f166:
    // 0047f166  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f168  e9e0feffff             -jmp 0x47f04d
    goto L_0x0047f04d;
}

/* align: skip  */
void Application::sub_47f16d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f16d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f16e  8b3508eb5100           -mov esi, dword ptr [0x51eb08]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */);
    // 0047f174  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f175  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047f177  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f179  742d                   -je 0x47f1a8
    if (cpu.flags.zf)
    {
        goto L_0x0047f1a8;
    }
    // 0047f17b  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047f17f:
    // 0047f17f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f180  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f181  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047f185  e81f140000             -call 0x4805a9
    cpu.esp -= 4;
    __mbsnbicoll(app, cpu);
    // 0047f18a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f18d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f18f  750d                   -jne 0x47f19e
    if (!cpu.flags.zf)
    {
        goto L_0x0047f19e;
    }
    // 0047f191  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047f193  8a0438                 -mov al, byte ptr [eax + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.edi * 1);
    // 0047f196  3c3d                   +cmp al, 0x3d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f198  741e                   -je 0x47f1b8
    if (cpu.flags.zf)
    {
        goto L_0x0047f1b8;
    }
    // 0047f19a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047f19c  741a                   -je 0x47f1b8
    if (cpu.flags.zf)
    {
        goto L_0x0047f1b8;
    }
L_0x0047f19e:
    // 0047f19e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047f1a1  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f1a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f1a6  75d7                   -jne 0x47f17f
    if (!cpu.flags.zf)
    {
        goto L_0x0047f17f;
    }
L_0x0047f1a8:
    // 0047f1a8  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f1aa  2b0508eb5100           -sub eax, dword ptr [0x51eb08]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */)));
    // 0047f1b0  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0047f1b3  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0047f1b5:
    // 0047f1b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f1b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f1b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f1b8:
    // 0047f1b8  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f1ba  2b0508eb5100           -sub eax, dword ptr [0x51eb08]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */)));
    // 0047f1c0  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047f1c3  ebf0                   -jmp 0x47f1b5
    goto L_0x0047f1b5;
}

/* align: skip  */
void Application::sub_47f1c5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f1c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f1c6  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f1ca  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f1cc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f1ce  7504                   -jne 0x47f1d4
    if (!cpu.flags.zf)
    {
        goto L_0x0047f1d4;
    }
    // 0047f1d0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f1d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f1d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f1d4:
    // 0047f1d4  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f1d7  8d4704                 -lea eax, [edi + 4]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047f1da  740a                   -je 0x47f1e6
    if (cpu.flags.zf)
    {
        goto L_0x0047f1e6;
    }
L_0x0047f1dc:
    // 0047f1dc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047f1de  41                     -inc ecx
    (cpu.ecx)++;
    // 0047f1df  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f1e2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047f1e4  75f6                   -jne 0x47f1dc
    if (!cpu.flags.zf)
    {
        goto L_0x0047f1dc;
    }
L_0x0047f1e6:
    // 0047f1e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f1e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f1e8  8d048d04000000         -lea eax, [ecx*4 + 4]
    cpu.eax = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 0047f1ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f1f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f1f1  e88480ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047f1f6  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f1f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f1f9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f1fb  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047f1fd  7508                   -jne 0x47f207
    if (!cpu.flags.zf)
    {
        goto L_0x0047f207;
    }
    // 0047f1ff  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047f201  e833afffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 0047f206  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f207:
    // 0047f207  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047f209  8bdf                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0047f20b:
    // 0047f20b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f20d  7413                   -je 0x47f222
    if (cpu.flags.zf)
    {
        goto L_0x0047f222;
    }
    // 0047f20f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f210  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f213  e8553b0000             -call 0x482d6d
    cpu.esp -= 4;
    sub_482d6d(app, cpu);
    // 0047f218  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047f21a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047f21c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f21d  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f220  ebe9                   -jmp 0x47f20b
    goto L_0x0047f20b;
L_0x0047f222:
    // 0047f222  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047f225  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047f227  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f228  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f229  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f22a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f22b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f230  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f231  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f235  eb6a                   -jmp 0x47f2a1
    return sub_47f2a1(app, cpu);
}

/* align: skip  */
void Application::sub_47f240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f240  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f244  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f245  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f24b  740f                   -je 0x47f25c
    if (cpu.flags.zf)
    {
        goto L_0x0047f25c;
    }
L_0x0047f24d:
    // 0047f24d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047f24f  41                     -inc ecx
    (cpu.ecx)++;
    // 0047f250  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047f252  743b                   -je 0x47f28f
    if (cpu.flags.zf)
    {
        goto L_0x0047f28f;
    }
    // 0047f254  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f25a  75f1                   -jne 0x47f24d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f24d;
    }
L_0x0047f25c:
    // 0047f25c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047f25e  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0047f263  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047f265  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f268  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f26a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f26d  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0047f272  74e8                   -je 0x47f25c
    if (cpu.flags.zf)
    {
        goto L_0x0047f25c;
    }
    // 0047f274  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0047f277  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047f279  7423                   -je 0x47f29e
    if (cpu.flags.zf)
    {
        goto L_0x0047f29e;
    }
    // 0047f27b  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047f27d  741a                   -je 0x47f299
    if (cpu.flags.zf)
    {
        goto L_0x0047f299;
    }
    // 0047f27f  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 0047f284  740e                   -je 0x47f294
    if (cpu.flags.zf)
    {
        goto L_0x0047f294;
    }
    // 0047f286  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0047f28b  7402                   -je 0x47f28f
    if (cpu.flags.zf)
    {
        goto L_0x0047f28f;
    }
    // 0047f28d  ebcd                   -jmp 0x47f25c
    goto L_0x0047f25c;
L_0x0047f28f:
    // 0047f28f  8d79ff                 -lea edi, [ecx - 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0047f292  eb0d                   -jmp 0x47f2a1
    goto L_0x0047f2a1;
L_0x0047f294:
    // 0047f294  8d79fe                 -lea edi, [ecx - 2]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0047f297  eb08                   -jmp 0x47f2a1
    goto L_0x0047f2a1;
L_0x0047f299:
    // 0047f299  8d79fd                 -lea edi, [ecx - 3]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 0047f29c  eb03                   -jmp 0x47f2a1
    goto L_0x0047f2a1;
L_0x0047f29e:
    // 0047f29e  8d79fc                 -lea edi, [ecx - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
L_0x0047f2a1:
    // 0047f2a1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047f2a5  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f2ab  7419                   -je 0x47f2c6
    if (cpu.flags.zf)
    {
        goto L_0x0047f2c6;
    }
L_0x0047f2ad:
    // 0047f2ad  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047f2af  41                     -inc ecx
    (cpu.ecx)++;
    // 0047f2b0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047f2b2  7464                   -je 0x47f318
    if (cpu.flags.zf)
    {
        goto L_0x0047f318;
    }
    // 0047f2b4  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0047f2b6  47                     -inc edi
    (cpu.edi)++;
    // 0047f2b7  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f2bd  75ee                   -jne 0x47f2ad
    if (!cpu.flags.zf)
    {
        goto L_0x0047f2ad;
    }
    // 0047f2bf  eb05                   -jmp 0x47f2c6
    goto L_0x0047f2c6;
L_0x0047f2c1:
    // 0047f2c1  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0047f2c3  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047f2c6:
    // 0047f2c6  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0047f2cb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047f2cd  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047f2cf  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f2d2  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f2d4  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047f2d6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f2d9  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0047f2de  74e1                   -je 0x47f2c1
    if (cpu.flags.zf)
    {
        goto L_0x0047f2c1;
    }
    // 0047f2e0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047f2e2  7434                   -je 0x47f318
    if (cpu.flags.zf)
    {
        goto L_0x0047f318;
    }
    // 0047f2e4  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0047f2e6  7427                   -je 0x47f30f
    if (cpu.flags.zf)
    {
        goto L_0x0047f30f;
    }
    // 0047f2e8  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 0047f2ee  7412                   -je 0x47f302
    if (cpu.flags.zf)
    {
        goto L_0x0047f302;
    }
    // 0047f2f0  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 0047f2f6  7402                   -je 0x47f2fa
    if (cpu.flags.zf)
    {
        goto L_0x0047f2fa;
    }
    // 0047f2f8  ebc7                   -jmp 0x47f2c1
    goto L_0x0047f2c1;
L_0x0047f2fa:
    // 0047f2fa  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0047f2fc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f300  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f301  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f302:
    // 0047f302  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0047f305  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f309  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0047f30d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f30e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f30f:
    // 0047f30f  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0047f312  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f316  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f317  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f318:
    // 0047f318  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0047f31a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f31e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f31f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f2a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047f2a1;
    // 0047f240  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f244  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f245  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f24b  740f                   -je 0x47f25c
    if (cpu.flags.zf)
    {
        goto L_0x0047f25c;
    }
L_0x0047f24d:
    // 0047f24d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047f24f  41                     -inc ecx
    (cpu.ecx)++;
    // 0047f250  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047f252  743b                   -je 0x47f28f
    if (cpu.flags.zf)
    {
        goto L_0x0047f28f;
    }
    // 0047f254  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f25a  75f1                   -jne 0x47f24d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f24d;
    }
L_0x0047f25c:
    // 0047f25c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047f25e  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0047f263  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047f265  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f268  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f26a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f26d  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0047f272  74e8                   -je 0x47f25c
    if (cpu.flags.zf)
    {
        goto L_0x0047f25c;
    }
    // 0047f274  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0047f277  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047f279  7423                   -je 0x47f29e
    if (cpu.flags.zf)
    {
        goto L_0x0047f29e;
    }
    // 0047f27b  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047f27d  741a                   -je 0x47f299
    if (cpu.flags.zf)
    {
        goto L_0x0047f299;
    }
    // 0047f27f  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 0047f284  740e                   -je 0x47f294
    if (cpu.flags.zf)
    {
        goto L_0x0047f294;
    }
    // 0047f286  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0047f28b  7402                   -je 0x47f28f
    if (cpu.flags.zf)
    {
        goto L_0x0047f28f;
    }
    // 0047f28d  ebcd                   -jmp 0x47f25c
    goto L_0x0047f25c;
L_0x0047f28f:
    // 0047f28f  8d79ff                 -lea edi, [ecx - 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0047f292  eb0d                   -jmp 0x47f2a1
    goto L_0x0047f2a1;
L_0x0047f294:
    // 0047f294  8d79fe                 -lea edi, [ecx - 2]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0047f297  eb08                   -jmp 0x47f2a1
    goto L_0x0047f2a1;
L_0x0047f299:
    // 0047f299  8d79fd                 -lea edi, [ecx - 3]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 0047f29c  eb03                   -jmp 0x47f2a1
    goto L_0x0047f2a1;
L_0x0047f29e:
    // 0047f29e  8d79fc                 -lea edi, [ecx - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
L_0x0047f2a1:
L_entry_0x0047f2a1:
    // 0047f2a1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047f2a5  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f2ab  7419                   -je 0x47f2c6
    if (cpu.flags.zf)
    {
        goto L_0x0047f2c6;
    }
L_0x0047f2ad:
    // 0047f2ad  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047f2af  41                     -inc ecx
    (cpu.ecx)++;
    // 0047f2b0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047f2b2  7464                   -je 0x47f318
    if (cpu.flags.zf)
    {
        goto L_0x0047f318;
    }
    // 0047f2b4  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0047f2b6  47                     -inc edi
    (cpu.edi)++;
    // 0047f2b7  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0047f2bd  75ee                   -jne 0x47f2ad
    if (!cpu.flags.zf)
    {
        goto L_0x0047f2ad;
    }
    // 0047f2bf  eb05                   -jmp 0x47f2c6
    goto L_0x0047f2c6;
L_0x0047f2c1:
    // 0047f2c1  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0047f2c3  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047f2c6:
    // 0047f2c6  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0047f2cb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047f2cd  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047f2cf  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f2d2  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f2d4  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047f2d6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f2d9  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0047f2de  74e1                   -je 0x47f2c1
    if (cpu.flags.zf)
    {
        goto L_0x0047f2c1;
    }
    // 0047f2e0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047f2e2  7434                   -je 0x47f318
    if (cpu.flags.zf)
    {
        goto L_0x0047f318;
    }
    // 0047f2e4  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0047f2e6  7427                   -je 0x47f30f
    if (cpu.flags.zf)
    {
        goto L_0x0047f30f;
    }
    // 0047f2e8  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 0047f2ee  7412                   -je 0x47f302
    if (cpu.flags.zf)
    {
        goto L_0x0047f302;
    }
    // 0047f2f0  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 0047f2f6  7402                   -je 0x47f2fa
    if (cpu.flags.zf)
    {
        goto L_0x0047f2fa;
    }
    // 0047f2f8  ebc7                   -jmp 0x47f2c1
    goto L_0x0047f2c1;
L_0x0047f2fa:
    // 0047f2fa  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0047f2fc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f300  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f301  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f302:
    // 0047f302  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0047f305  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f309  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0047f30d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f30e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f30f:
    // 0047f30f  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0047f312  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f316  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f317  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f318:
    // 0047f318  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0047f31a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f31e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f31f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f322  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f323  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f324  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f325  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f326  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 0047f328  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f32b  e899d7ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047f330  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f332  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f333  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047f337  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047f33b  bde01e5200             -mov ebp, 0x521ee0
    cpu.ebp = 5381856 /*0x521ee0*/;
L_0x0047f340:
    // 0047f340  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047f343  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f345  0f8499000000           -je 0x47f3e4
    if (cpu.flags.zf)
    {
        goto L_0x0047f3e4;
    }
    // 0047f34b  8d8680040000           -lea eax, [esi + 0x480]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1152) /* 0x480 */);
L_0x0047f351:
    // 0047f351  3bf0                   +cmp esi, eax
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
    // 0047f353  7374                   -jae 0x47f3c9
    if (!cpu.flags.cf)
    {
        goto L_0x0047f3c9;
    }
    // 0047f355  f6460401               +test byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0047f359  7544                   -jne 0x47f39f
    if (!cpu.flags.zf)
    {
        goto L_0x0047f39f;
    }
    // 0047f35b  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f35f  7523                   -jne 0x47f384
    if (!cpu.flags.zf)
    {
        goto L_0x0047f384;
    }
    // 0047f361  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047f363  e861d7ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047f368  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f36c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f36d  750d                   -jne 0x47f37c
    if (!cpu.flags.zf)
    {
        goto L_0x0047f37c;
    }
    // 0047f36f  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047f372  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f373  ff15ec704800           -call dword ptr [0x4870ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747500) /* 0x4870ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f379  ff4608                 -inc dword ptr [esi + 8]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */))++;
L_0x0047f37c:
    // 0047f37c  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047f37e  e8a7d7ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047f383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f384:
    // 0047f384  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047f387  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f388  ff15b0714800           -call dword ptr [0x4871b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747696) /* 0x4871b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f38e  f6460401               +test byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0047f392  7418                   -je 0x47f3ac
    if (cpu.flags.zf)
    {
        goto L_0x0047f3ac;
    }
    // 0047f394  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f395  ff15b4714800           -call dword ptr [0x4871b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747700) /* 0x4871b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f39b  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047f39f:
    // 0047f39f  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047f3a2  83c624                 -add esi, 0x24
    (cpu.esi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047f3a5  0580040000             +add eax, 0x480
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1152 /*0x480*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f3aa  eba5                   -jmp 0x47f351
    goto L_0x0047f351;
L_0x0047f3ac:
    // 0047f3ac  830eff                 -or dword ptr [esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f3af  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f3b1  2b4500                 -sub eax, dword ptr [ebp]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
    // 0047f3b4  6a24                   -push 0x24
    app->getMemory<x86::reg32>(cpu.esp-4) = 36 /*0x24*/;
    cpu.esp -= 4;
    // 0047f3b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3b7  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047f3b8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047f3ba  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047f3bc  037c2414               -add edi, dword ptr [esp + 0x14]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0047f3c0  83ffff                 +cmp edi, -1
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
    // 0047f3c3  756d                   -jne 0x47f432
    if (!cpu.flags.zf)
    {
        goto L_0x0047f432;
    }
    // 0047f3c5  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047f3c9:
    // 0047f3c9  8344241420             -add dword ptr [esp + 0x14], 0x20
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047f3ce  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f3d1  43                     -inc ebx
    (cpu.ebx)++;
    // 0047f3d2  81fde01f5200           +cmp ebp, 0x521fe0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5382112 /*0x521fe0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f3d8  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047f3dc  0f8c5effffff           -jl 0x47f340
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f340;
    }
    // 0047f3e2  eb4e                   -jmp 0x47f432
    goto L_0x0047f432;
L_0x0047f3e4:
    // 0047f3e4  be80040000             -mov esi, 0x480
    cpu.esi = 1152 /*0x480*/;
    // 0047f3e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f3ea  e88b7effff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047f3ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f3f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3f2  743e                   -je 0x47f432
    if (cpu.flags.zf)
    {
        goto L_0x0047f432;
    }
    // 0047f3f4  8305e01f520020         -add dword ptr [0x521fe0], 0x20
    (app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */)) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047f3fb  8d0c9de01e5200         -lea ecx, [ebx*4 + 0x521ee0]
    cpu.ecx = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ebx * 4);
    // 0047f402  8d9080040000           -lea edx, [eax + 0x480]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1152) /* 0x480 */);
    // 0047f408  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0047f40a:
    // 0047f40a  3bc2                   +cmp eax, edx
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
    // 0047f40c  7318                   -jae 0x47f426
    if (!cpu.flags.cf)
    {
        goto L_0x0047f426;
    }
    // 0047f40e  80600400               -and byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047f412  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f415  83600800               -and dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047f419  c640050a               -mov byte ptr [eax + 5], 0xa
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 0047f41d  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047f41f  83c024                 -add eax, 0x24
    (cpu.eax) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047f422  03d6                   +add edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f424  ebe4                   -jmp 0x47f40a
    goto L_0x0047f40a;
L_0x0047f426:
    // 0047f426  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 0047f429  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047f42b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f42c  e84f010000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 0047f431  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f432:
    // 0047f432  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 0047f434  e8f1d6ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047f439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f43a  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047f43c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f43d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f43e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f43f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f440  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f441  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f442  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f443(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f443  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f447  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f448  3b0de01f5200           +cmp ecx, dword ptr [0x521fe0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f44e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f44f  7355                   -jae 0x47f4a6
    if (!cpu.flags.cf)
    {
        goto L_0x0047f4a6;
    }
    // 0047f451  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f453  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047f456  8d3c85e01e5200         -lea edi, [eax*4 + 0x521ee0]
    cpu.edi = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 0047f45d  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f45f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047f462  8d34c0                 -lea esi, [eax + eax*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047f465  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047f467  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047f46a  833c30ff               +cmp dword ptr [eax + esi], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f46e  7536                   -jne 0x47f4a6
    if (!cpu.flags.zf)
    {
        goto L_0x0047f4a6;
    }
    // 0047f470  833db43f4a0001         +cmp dword ptr [0x4a3fb4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4865972) /* 0x4a3fb4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f477  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f478  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047f47c  751e                   -jne 0x47f49c
    if (!cpu.flags.zf)
    {
        goto L_0x0047f49c;
    }
    // 0047f47e  83e900                 +sub ecx, 0
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
    // 0047f481  7410                   -je 0x47f493
    if (cpu.flags.zf)
    {
        goto L_0x0047f493;
    }
    // 0047f483  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047f484  7408                   -je 0x47f48e
    if (cpu.flags.zf)
    {
        goto L_0x0047f48e;
    }
    // 0047f486  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047f487  7513                   -jne 0x47f49c
    if (!cpu.flags.zf)
    {
        goto L_0x0047f49c;
    }
    // 0047f489  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f48a  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 0047f48c  eb08                   -jmp 0x47f496
    goto L_0x0047f496;
L_0x0047f48e:
    // 0047f48e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f48f  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 0047f491  eb03                   -jmp 0x47f496
    goto L_0x0047f496;
L_0x0047f493:
    // 0047f493  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f494  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
L_0x0047f496:
    // 0047f496  ff1530714800           -call dword ptr [0x487130]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747568) /* 0x487130 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047f49c:
    // 0047f49c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047f49e  891c30                 -mov dword ptr [eax + esi], ebx
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1) = cpu.ebx;
    // 0047f4a1  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f4a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4a4  eb16                   -jmp 0x47f4bc
    goto L_0x0047f4bc;
L_0x0047f4a6:
    // 0047f4a6  e807f0ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047f4ab  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 0047f4b1  e805f0ffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047f4b6  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047f4b9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0047f4bc:
    // 0047f4bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f4bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f4bf  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f4c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f4c4  3b0de01f5200           +cmp ecx, dword ptr [0x521fe0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f4ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f4cb  7358                   -jae 0x47f525
    if (!cpu.flags.cf)
    {
        goto L_0x0047f525;
    }
    // 0047f4cd  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f4cf  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047f4d2  8d3c85e01e5200         -lea edi, [eax*4 + 0x521ee0]
    cpu.edi = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 0047f4d9  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f4db  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047f4de  8d34c0                 -lea esi, [eax + eax*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047f4e1  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047f4e3  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047f4e6  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047f4e8  f6400401               +test byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0047f4ec  7437                   -je 0x47f525
    if (cpu.flags.zf)
    {
        goto L_0x0047f525;
    }
    // 0047f4ee  8338ff                 +cmp dword ptr [eax], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f4f1  7432                   -je 0x47f525
    if (cpu.flags.zf)
    {
        goto L_0x0047f525;
    }
    // 0047f4f3  833db43f4a0001         +cmp dword ptr [0x4a3fb4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4865972) /* 0x4a3fb4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f4fa  751f                   -jne 0x47f51b
    if (!cpu.flags.zf)
    {
        goto L_0x0047f51b;
    }
    // 0047f4fc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f4fe  2bc8                   +sub ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f500  7410                   -je 0x47f512
    if (cpu.flags.zf)
    {
        goto L_0x0047f512;
    }
    // 0047f502  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047f503  7408                   -je 0x47f50d
    if (cpu.flags.zf)
    {
        goto L_0x0047f50d;
    }
    // 0047f505  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047f506  7513                   -jne 0x47f51b
    if (!cpu.flags.zf)
    {
        goto L_0x0047f51b;
    }
    // 0047f508  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f509  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 0047f50b  eb08                   -jmp 0x47f515
    goto L_0x0047f515;
L_0x0047f50d:
    // 0047f50d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f50e  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 0047f510  eb03                   -jmp 0x47f515
    goto L_0x0047f515;
L_0x0047f512:
    // 0047f512  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f513  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
L_0x0047f515:
    // 0047f515  ff1530714800           -call dword ptr [0x487130]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747568) /* 0x487130 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047f51b:
    // 0047f51b  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047f51d  830c30ff               -or dword ptr [eax + esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f521  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f523  eb16                   -jmp 0x47f53b
    goto L_0x0047f53b;
L_0x0047f525:
    // 0047f525  e888efffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047f52a  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 0047f530  e886efffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047f535  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047f538  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0047f53b:
    // 0047f53b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f53c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f53d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f53e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f53e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f542  3b05e01f5200           +cmp eax, dword ptr [0x521fe0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382112) /* 0x521fe0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f548  731f                   -jae 0x47f569
    if (!cpu.flags.cf)
    {
        goto L_0x0047f569;
    }
    // 0047f54a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f54c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047f54f  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047f552  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047f555  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047f55c  f644810401             +test byte ptr [ecx + eax*4 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) & 1 /*0x1*/));
    // 0047f561  8d0481                 -lea eax, [ecx + eax*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 0047f564  7403                   -je 0x47f569
    if (cpu.flags.zf)
    {
        goto L_0x0047f569;
    }
    // 0047f566  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047f568  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f569:
    // 0047f569  e844efffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047f56e  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 0047f574  e842efffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047f579  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047f57c  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f57f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f580  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f584  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f585  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f587  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047f58a  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047f58d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f58e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f58f  8b348de01e5200         -mov esi, dword ptr [ecx*4 + 0x521ee0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047f596  8d1c8de01e5200         -lea ebx, [ecx*4 + 0x521ee0]
    cpu.ebx = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047f59d  8d3cc0                 -lea edi, [eax + eax*8]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047f5a0  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0047f5a3  03f7                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047f5a5  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f5a9  7523                   -jne 0x47f5ce
    if (!cpu.flags.zf)
    {
        goto L_0x0047f5ce;
    }
    // 0047f5ab  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047f5ad  e817d5ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047f5b2  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f5b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f5b7  750d                   -jne 0x47f5c6
    if (!cpu.flags.zf)
    {
        goto L_0x0047f5c6;
    }
    // 0047f5b9  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047f5bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f5bd  ff15ec704800           -call dword ptr [0x4870ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747500) /* 0x4870ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f5c3  ff4608                 -inc dword ptr [esi + 8]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */))++;
L_0x0047f5c6:
    // 0047f5c6  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047f5c8  e85dd5ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047f5cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f5ce:
    // 0047f5ce  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047f5d0  8d44380c               -lea eax, [eax + edi + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edi * 1);
    // 0047f5d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f5d5  ff15b0714800           -call dword ptr [0x4871b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747696) /* 0x4871b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f5db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f5dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f5dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f5de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f5df(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f5df  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f5e3  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f5e5  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047f5e8  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047f5eb  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047f5ee  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047f5f5  8d44810c               -lea eax, [ecx + eax*4 + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 0047f5f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f5fa  ff15b4714800           -call dword ptr [0x4871b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747700) /* 0x4871b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f601(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f601  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f602  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047f604  b804100000             -mov eax, 0x1004
    cpu.eax = 4100 /*0x1004*/;
    // 0047f609  e82287ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047f60e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f60f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f610  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047f612  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047f614  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f615  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f618  e80cefffff             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 0047f61d  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f620  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f623  3bc3                   +cmp eax, ebx
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
    // 0047f625  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047f628  0f84f2000000           -je 0x47f720
    if (cpu.flags.zf)
    {
        goto L_0x0047f720;
    }
    // 0047f62e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f630  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f631  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f634  e8f0eeffff             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 0047f639  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f63c  3bc3                   +cmp eax, ebx
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
    // 0047f63e  0f84dc000000           -je 0x47f720
    if (cpu.flags.zf)
    {
        goto L_0x0047f720;
    }
    // 0047f644  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f645  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047f648  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f64a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f64c  7e75                   -jle 0x47f6c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f6c3;
    }
    // 0047f64e  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0047f653  8d85fcefffff           -lea eax, [ebp - 0x1004]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4100) /* -0x1004 */);
    // 0047f659  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f65a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f65b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f65c  e8bf200000             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 0047f661  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0047f666  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f669  e82a370000             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    // 0047f66e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047f671  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0047f674:
    // 0047f674  3bfb                   +cmp edi, ebx
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
    // 0047f676  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f678  7d02                   -jge 0x47f67c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f67c;
    }
    // 0047f67a  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0047f67c:
    // 0047f67c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f67d  8d85fcefffff           -lea eax, [ebp - 0x1004]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4100) /* -0x1004 */);
    // 0047f683  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f684  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f687  e8f8a2ffff             -call 0x479984
    cpu.esp -= 4;
    sub_479984(app, cpu);
    // 0047f68c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f68f  83f8ff                 +cmp eax, -1
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
    // 0047f692  7408                   -je 0x47f69c
    if (cpu.flags.zf)
    {
        goto L_0x0047f69c;
    }
    // 0047f694  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f696  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f698  7e1a                   -jle 0x47f6b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f6b4;
    }
    // 0047f69a  ebd8                   -jmp 0x47f674
    goto L_0x0047f674;
L_0x0047f69c:
    // 0047f69c  e81aeeffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047f6a1  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f6a4  750b                   -jne 0x47f6b1
    if (!cpu.flags.zf)
    {
        goto L_0x0047f6b1;
    }
    // 0047f6a6  e807eeffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047f6ab  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
L_0x0047f6b1:
    // 0047f6b1  83ceff                 +or esi, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
L_0x0047f6b4:
    // 0047f6b4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047f6b7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f6ba  e8d9360000             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    // 0047f6bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f6c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f6c1  eb48                   -jmp 0x47f70b
    goto L_0x0047f70b;
L_0x0047f6c3:
    // 0047f6c3  7d46                   -jge 0x47f70b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f70b;
    }
    // 0047f6c5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f6c7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047f6ca  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f6cd  e857eeffff             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 0047f6d2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f6d5  e864feffff             -call 0x47f53e
    cpu.esp -= 4;
    sub_47f53e(app, cpu);
    // 0047f6da  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f6dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f6de  ff1528714800           -call dword ptr [0x487128]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747560) /* 0x487128 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f6e4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f6e6  f7de                   +neg esi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.esi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0047f6e8  1bf6                   -sbb esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 0047f6ea  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0047f6ec  4e                     -dec esi
    (cpu.esi)--;
    // 0047f6ed  3bf3                   +cmp esi, ebx
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
    // 0047f6ef  751a                   -jne 0x47f70b
    if (!cpu.flags.zf)
    {
        goto L_0x0047f70b;
    }
    // 0047f6f1  e8bcedffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047f6f6  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
    // 0047f6fc  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047f702  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047f704  e8b2edffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047f709  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0047f70b:
    // 0047f70b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f70d  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047f710  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f713  e811eeffff             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 0047f718  83c40c                 +add esp, 0xc
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
    // 0047f71b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f71d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f71e  eb02                   -jmp 0x47f722
    goto L_0x0047f722;
L_0x0047f720:
    // 0047f720  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047f722:
    // 0047f722  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f723  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f724  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f725  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f726(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f726  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f727  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047f729  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f72a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f72b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f72c  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047f72f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f730  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f731  6a5c                   -push 0x5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 92 /*0x5c*/;
    cpu.esp -= 4;
    // 0047f733  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f734  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047f736  e804370000             -call 0x482e3f
    cpu.esp -= 4;
    sub_482e3f(app, cpu);
    // 0047f73b  6a2f                   -push 0x2f
    app->getMemory<x86::reg32>(cpu.esp-4) = 47 /*0x2f*/;
    cpu.esp -= 4;
    // 0047f73d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f73e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f740  e8fa360000             -call 0x482e3f
    cpu.esp -= 4;
    sub_482e3f(app, cpu);
    // 0047f745  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f748  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f74a  7545                   -jne 0x47f791
    if (!cpu.flags.zf)
    {
        goto L_0x0047f791;
    }
    // 0047f74c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f74e  754b                   -jne 0x47f79b
    if (!cpu.flags.zf)
    {
        goto L_0x0047f79b;
    }
    // 0047f750  6a3a                   -push 0x3a
    app->getMemory<x86::reg32>(cpu.esp-4) = 58 /*0x3a*/;
    cpu.esp -= 4;
    // 0047f752  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f753  e87e350000             -call 0x482cd6
    cpu.esp -= 4;
    sub_482cd6(app, cpu);
    // 0047f758  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f75a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f75b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f75d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f75e  753b                   -jne 0x47f79b
    if (!cpu.flags.zf)
    {
        goto L_0x0047f79b;
    }
    // 0047f760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f761  e87ae6ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047f766  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047f769  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f76a  e80b7bffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047f76f  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047f771  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f772  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f775  747d                   -je 0x47f7f4
    if (cpu.flags.zf)
    {
        goto L_0x0047f7f4;
    }
    // 0047f777  68887e4800             -push 0x487e88
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750984 /*0x487e88*/;
    cpu.esp -= 4;
    // 0047f77c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f77d  e8aefaffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 0047f782  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f783  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f784  e8b7faffff             -call 0x47f240
    cpu.esp -= 4;
    sub_47f240(app, cpu);
    // 0047f789  83c410                 +add esp, 0x10
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
    // 0047f78c  8d7702                 -lea esi, [edi + 2]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0047f78f  eb0a                   -jmp 0x47f79b
    goto L_0x0047f79b;
L_0x0047f791:
    // 0047f791  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f793  7404                   -je 0x47f799
    if (cpu.flags.zf)
    {
        goto L_0x0047f799;
    }
    // 0047f795  3bc6                   +cmp eax, esi
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
    // 0047f797  7602                   -jbe 0x47f79b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f79b;
    }
L_0x0047f799:
    // 0047f799  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0047f79b:
    // 0047f79b  834df8ff               -or dword ptr [ebp - 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047f79f  6a2e                   -push 0x2e
    app->getMemory<x86::reg32>(cpu.esp-4) = 46 /*0x2e*/;
    cpu.esp -= 4;
    // 0047f7a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f7a2  e898360000             -call 0x482e3f
    cpu.esp -= 4;
    sub_482e3f(app, cpu);
    // 0047f7a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f7aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7ab  742d                   -je 0x47f7da
    if (cpu.flags.zf)
    {
        goto L_0x0047f7da;
    }
    // 0047f7ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f7af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f7b0  e844360000             -call 0x482df9
    cpu.esp -= 4;
    sub_482df9(app, cpu);
    // 0047f7b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7b6  83f8ff                 +cmp eax, -1
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
    // 0047f7b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7ba  0f849c000000           -je 0x47f85c
    if (cpu.flags.zf)
    {
        goto L_0x0047f85c;
    }
    // 0047f7c0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047f7c3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047f7c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f7c7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f7ca  e8a0000000             -call 0x47f86f
    cpu.esp -= 4;
    sub_47f86f(app, cpu);
    // 0047f7cf  83c410                 +add esp, 0x10
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
    // 0047f7d2  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047f7d5  e982000000             -jmp 0x47f85c
    goto L_0x0047f85c;
L_0x0047f7da:
    // 0047f7da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f7db  e800e6ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047f7e0  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0047f7e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f7e4  e8917affff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047f7e9  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f7eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7ec  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f7ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7ef  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0047f7f2  7505                   -jne 0x47f7f9
    if (!cpu.flags.zf)
    {
        goto L_0x0047f7f9;
    }
L_0x0047f7f4:
    // 0047f7f4  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047f7f7  eb71                   -jmp 0x47f86a
    goto L_0x0047f86a;
L_0x0047f7f9:
    // 0047f7f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f7fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f7fb  e830faffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 0047f800  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f801  e8dae5ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047f806  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f808  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f80b  03f3                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f80d  bbcc654a00             -mov ebx, 0x4a65cc
    cpu.ebx = 4875724 /*0x4a65cc*/;
L_0x0047f812:
    // 0047f812  ff33                   -push dword ptr [ebx]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx);
    cpu.esp -= 4;
    // 0047f814  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f815  e816faffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 0047f81a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f81c  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047f81f  e8d5350000             -call 0x482df9
    cpu.esp -= 4;
    sub_482df9(app, cpu);
    // 0047f824  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f827  83f8ff                 +cmp eax, -1
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
    // 0047f82a  750d                   -jne 0x47f839
    if (!cpu.flags.zf)
    {
        goto L_0x0047f839;
    }
    // 0047f82c  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f82f  81fbc0654a00           +cmp ebx, 0x4a65c0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4875712 /*0x4a65c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f835  7ddb                   -jge 0x47f812
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f812;
    }
    // 0047f837  eb17                   -jmp 0x47f850
    goto L_0x0047f850;
L_0x0047f839:
    // 0047f839  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047f83c  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047f83f  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047f842  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f845  e825000000             -call 0x47f86f
    cpu.esp -= 4;
    sub_47f86f(app, cpu);
    // 0047f84a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f84d  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x0047f850:
    // 0047f850  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047f853  e85c7bffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047f858  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047f85b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f85c:
    // 0047f85c  3bfb                   +cmp edi, ebx
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
    // 0047f85e  7407                   -je 0x47f867
    if (cpu.flags.zf)
    {
        goto L_0x0047f867;
    }
    // 0047f860  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f861  e84e7bffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047f866  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f867:
    // 0047f867  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x0047f86a:
    // 0047f86a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f86b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f86c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f86d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f86e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f86f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f86f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f870  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047f872  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047f875  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047f878  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f879  8d4514                 -lea eax, [ebp + 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047f87c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f87d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047f880  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047f883  e812380000             -call 0x48309a
    cpu.esp -= 4;
    sub_48309a(app, cpu);
    // 0047f888  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047f88b  83f8ff                 +cmp eax, -1
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
    // 0047f88e  7504                   -jne 0x47f894
    if (!cpu.flags.zf)
    {
        goto L_0x0047f894;
    }
    // 0047f890  0bc0                   -or eax, eax
    cpu.eax |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f892  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f893  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f894:
    // 0047f894  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f895  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047f898  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047f89b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047f89e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047f8a1  e80b360000             -call 0x482eb1
    cpu.esp -= 4;
    sub_482eb1(app, cpu);
    // 0047f8a6  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047f8a9  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f8ab  e8047bffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047f8b0  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047f8b3  e8fc7affff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047f8b8  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047f8bb  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f8bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f8c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f8c1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047f8c3  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047f8c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f8c7  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047f8ca  81eb6c070000           -sub ebx, 0x76c
    (cpu.ebx) -= x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 0047f8d0  83fb46                 +cmp ebx, 0x46
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(70 /*0x46*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f8d3  0f8ca3000000           -jl 0x47f97c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f97c;
    }
    // 0047f8d9  81fb8a000000           +cmp ebx, 0x8a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f8df  0f8f97000000           -jg 0x47f97c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047f97c;
    }
    // 0047f8e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f8e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f8e7  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047f8ea  8b34bdf4694a00         -mov esi, dword ptr [edi*4 + 0x4a69f4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4876788) /* 0x4a69f4 */ + cpu.edi * 4);
    // 0047f8f1  037510                 -add esi, dword ptr [ebp + 0x10]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    // 0047f8f4  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 0047f8f7  7506                   -jne 0x47f8ff
    if (!cpu.flags.zf)
    {
        goto L_0x0047f8ff;
    }
    // 0047f8f9  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f8fc  7e01                   -jle 0x47f8ff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f8ff;
    }
    // 0047f8fe  46                     -inc esi
    (cpu.esi)++;
L_0x0047f8ff:
    // 0047f8ff  e89c390000             -call 0x4832a0
    cpu.esp -= 4;
    sub_4832a0(app, cpu);
    // 0047f904  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f906  8d4bff                 -lea ecx, [ebx - 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0047f909  69c06d010000           -imul eax, eax, 0x16d
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(365 /*0x16d*/)));
    // 0047f90f  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0047f912  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047f914  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0047f917  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f919  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0047f91c  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047f91e  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047f921  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0047f924  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047f927  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0047f92a  8d0cc8                 -lea ecx, [eax + ecx*8]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ecx * 8);
    // 0047f92d  6bc93c                 -imul ecx, ecx, 0x3c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0047f930  034d18                 -add ecx, dword ptr [ebp + 0x18]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0047f933  6bc93c                 -imul ecx, ecx, 0x3c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0047f936  030d14694a00           -add ecx, dword ptr [0x4a6914]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4876564) /* 0x4a6914 */)));
    // 0047f93c  4f                     -dec edi
    (cpu.edi)--;
    // 0047f93d  837d2001               +cmp dword ptr [ebp + 0x20], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f941  897dec                 -mov dword ptr [ebp - 0x14], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edi;
    // 0047f944  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f945  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f946  8d8c118081557c         -lea ecx, [ecx + edx + 0x7c558180]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(2085978496) /* 0x7c558180 */ + cpu.edx * 1);
    // 0047f94d  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047f950  7420                   -je 0x47f972
    if (cpu.flags.zf)
    {
        goto L_0x0047f972;
    }
    // 0047f952  837d20ff               +cmp dword ptr [ebp + 0x20], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f956  7520                   -jne 0x47f978
    if (!cpu.flags.zf)
    {
        goto L_0x0047f978;
    }
    // 0047f958  833d18694a0000         +cmp dword ptr [0x4a6918], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4876568) /* 0x4a6918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f95f  7417                   -je 0x47f978
    if (cpu.flags.zf)
    {
        goto L_0x0047f978;
    }
    // 0047f961  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0047f964  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f965  e8eb3b0000             -call 0x483555
    cpu.esp -= 4;
    sub_483555(app, cpu);
    // 0047f96a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f96b  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047f96e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f970  7406                   -je 0x47f978
    if (cpu.flags.zf)
    {
        goto L_0x0047f978;
    }
L_0x0047f972:
    // 0047f972  030d1c694a00           +add ecx, dword ptr [0x4a691c]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4876572) /* 0x4a691c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0047f978:
    // 0047f978  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f97a  eb03                   -jmp 0x47f97f
    goto L_0x0047f97f;
L_0x0047f97c:
    // 0047f97c  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0047f97f:
    // 0047f97f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f980  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f981  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f982(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f982  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f983  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047f985  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047f988  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f989  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f98a  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047f98c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f98d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f98e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f98f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f990  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f991  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047f994  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047f997  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047f999  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f99a  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047f99d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f99e  e8bf3e0000             -call 0x483862
    cpu.esp -= 4;
    sub_483862(app, cpu);
    // 0047f9a3  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f9a5  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047f9a8  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0047f9ab  740d                   -je 0x47f9ba
    if (cpu.flags.zf)
    {
        goto L_0x0047f9ba;
    }
    // 0047f9ad  bf00020000             -mov edi, 0x200
    cpu.edi = 512 /*0x200*/;
    // 0047f9b2  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 0047f9b5  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0047f9b8  eb2e                   -jmp 0x47f9e8
    goto L_0x0047f9e8;
L_0x0047f9ba:
    // 0047f9ba  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047f9bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f9be  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047f9c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f9c2  e87d220000             -call 0x481c44
    cpu.esp -= 4;
    sub_481c44(app, cpu);
    // 0047f9c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9c8  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0047f9cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9cc  7505                   -jne 0x47f9d3
    if (!cpu.flags.zf)
    {
        goto L_0x0047f9d3;
    }
    // 0047f9ce  83f801                 +cmp eax, 1
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
    // 0047f9d1  7505                   -jne 0x47f9d8
    if (!cpu.flags.zf)
    {
        goto L_0x0047f9d8;
    }
L_0x0047f9d3:
    // 0047f9d3  bf80000000             -mov edi, 0x80
    cpu.edi = 128 /*0x80*/;
L_0x0047f9d8:
    // 0047f9d8  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0047f9db  7505                   -jne 0x47f9e2
    if (!cpu.flags.zf)
    {
        goto L_0x0047f9e2;
    }
    // 0047f9dd  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f9e0  7506                   -jne 0x47f9e8
    if (!cpu.flags.zf)
    {
        goto L_0x0047f9e8;
    }
L_0x0047f9e2:
    // 0047f9e2  81cf00010000           -or edi, 0x100
    cpu.edi |= x86::reg32(x86::sreg32(256 /*0x100*/));
L_0x0047f9e8:
    // 0047f9e8  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047f9eb  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047f9ee  2b4d0c                 -sub ecx, dword ptr [ebp + 0xc]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047f9f1  dd45f4                 -fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0047f9f4  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0047f9f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9f7  dd5810                 -fstp qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047f9fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9fb  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047f9fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9ff  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fa01(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fa01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fa02  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047fa04  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0047fa06  68c8814800             -push 0x4881c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4751816 /*0x4881c8*/;
    cpu.esp -= 4;
    // 0047fa0b  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0047fa10  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047fa16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa17  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0047fa1e  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047fa21  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fa23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa24  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047fa27  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fa29  391de4eb5100           +cmp dword ptr [0x51ebe4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368804) /* 0x51ebe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fa2f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fa31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa32  7540                   -jne 0x47fa74
    if (!cpu.flags.zf)
    {
        goto L_0x0047fa74;
    }
    // 0047fa34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa35  b8487e4800             -mov eax, 0x487e48
    cpu.eax = 4750920 /*0x487e48*/;
    // 0047fa3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa3d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa3e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa3f  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fa45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fa47  7408                   -je 0x47fa51
    if (cpu.flags.zf)
    {
        goto L_0x0047fa51;
    }
    // 0047fa49  893de4eb5100           -mov dword ptr [0x51ebe4], edi
    app->getMemory<x86::reg32>(x86::reg32(5368804) /* 0x51ebe4 */) = cpu.edi;
    // 0047fa4f  eb23                   -jmp 0x47fa74
    goto L_0x0047fa74;
L_0x0047fa51:
    // 0047fa51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa52  b8447e4800             -mov eax, 0x487e44
    cpu.eax = 4750916 /*0x487e44*/;
    // 0047fa57  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa5a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa5c  ff1520714800           -call dword ptr [0x487120]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747552) /* 0x487120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fa62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fa64  0f8400020000           -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fa6a  c705e4eb510002000000   -mov dword ptr [0x51ebe4], 2
    app->getMemory<x86::reg32>(x86::reg32(5368804) /* 0x51ebe4 */) = 2 /*0x2*/;
L_0x0047fa74:
    // 0047fa74  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047fa77  3bf3                   +cmp esi, ebx
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
    // 0047fa79  7e10                   -jle 0x47fa8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047fa8b;
    }
    // 0047fa7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fa7c  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047fa7f  e8fa010000             -call 0x47fc7e
    cpu.esp -= 4;
    sub_47fc7e(app, cpu);
    // 0047fa84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa86  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047fa88  897514                 -mov dword ptr [ebp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x0047fa8b:
    // 0047fa8b  395d1c                 +cmp dword ptr [ebp + 0x1c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fa8e  7e10                   -jle 0x47faa0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047faa0;
    }
    // 0047fa90  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047fa93  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fa96  e8e3010000             -call 0x47fc7e
    cpu.esp -= 4;
    sub_47fc7e(app, cpu);
    // 0047fa9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa9d  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0047faa0:
    // 0047faa0  a1e4eb5100             -mov eax, dword ptr [0x51ebe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368804) /* 0x51ebe4 */);
    // 0047faa5  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047faa8  751b                   -jne 0x47fac5
    if (!cpu.flags.zf)
    {
        goto L_0x0047fac5;
    }
    // 0047faaa  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047faad  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fab0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fab1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047fab4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047fab7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047faba  ff1520714800           -call dword ptr [0x487120]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747552) /* 0x487120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fac0  e9a7010000             -jmp 0x47fc6c
    return sub_47fc6c(app, cpu);
L_0x0047fac5:
    // 0047fac5  3bc7                   +cmp eax, edi
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
    // 0047fac7  0f859d010000           -jne 0x47fc6a
    if (!cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047facd  395d20                 +cmp dword ptr [ebp + 0x20], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fad0  7508                   -jne 0x47fada
    if (!cpu.flags.zf)
    {
        goto L_0x0047fada;
    }
    // 0047fad2  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 0047fad7  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0047fada:
    // 0047fada  3bf3                   +cmp esi, ebx
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
    // 0047fadc  7409                   -je 0x47fae7
    if (cpu.flags.zf)
    {
        goto L_0x0047fae7;
    }
    // 0047fade  395d1c                 +cmp dword ptr [ebp + 0x1c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fae1  0f8598000000           -jne 0x47fb7f
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb7f;
    }
L_0x0047fae7:
    // 0047fae7  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047faea  7508                   -jne 0x47faf4
    if (!cpu.flags.zf)
    {
        goto L_0x0047faf4;
    }
L_0x0047faec:
    // 0047faec  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
L_0x0047faee:
    // 0047faee  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047faef  e978010000             -jmp 0x47fc6c
    return sub_47fc6c(app, cpu);
L_0x0047faf4:
    // 0047faf4  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047faf7  7e07                   -jle 0x47fb00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047fb00;
    }
L_0x0047faf9:
    // 0047faf9  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047fafb  e96c010000             -jmp 0x47fc6c
    return sub_47fc6c(app, cpu);
L_0x0047fb00:
    // 0047fb00  3bf7                   +cmp esi, edi
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
    // 0047fb02  7f41                   -jg 0x47fb45
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047fb45;
    }
    // 0047fb04  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0047fb07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fb08  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fb0b  ff1524714800           -call dword ptr [0x487124]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747556) /* 0x487124 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fb11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fb13  0f8451010000           -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fb19  3bf3                   +cmp esi, ebx
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
    // 0047fb1b  7e2c                   -jle 0x47fb49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047fb49;
    }
    // 0047fb1d  837dc402               +cmp dword ptr [ebp - 0x3c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fb21  7222                   -jb 0x47fb45
    if (cpu.flags.cf)
    {
        goto L_0x0047fb45;
    }
    // 0047fb23  8d45ca                 -lea eax, [ebp - 0x36]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-54) /* -0x36 */);
    // 0047fb26  385dca                 +cmp byte ptr [ebp - 0x36], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-54) /* -0x36 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb29  741a                   -je 0x47fb45
    if (cpu.flags.zf)
    {
        goto L_0x0047fb45;
    }
L_0x0047fb2b:
    // 0047fb2b  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047fb2e  3ad3                   +cmp dl, bl
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb30  7413                   -je 0x47fb45
    if (cpu.flags.zf)
    {
        goto L_0x0047fb45;
    }
    // 0047fb32  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047fb35  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047fb37  3a08                   +cmp cl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb39  7204                   -jb 0x47fb3f
    if (cpu.flags.cf)
    {
        goto L_0x0047fb3f;
    }
    // 0047fb3b  3aca                   +cmp cl, dl
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb3d  76ad                   -jbe 0x47faec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047faec;
    }
L_0x0047fb3f:
    // 0047fb3f  40                     -inc eax
    (cpu.eax)++;
    // 0047fb40  40                     -inc eax
    (cpu.eax)++;
    // 0047fb41  3818                   +cmp byte ptr [eax], bl
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
    // 0047fb43  75e6                   -jne 0x47fb2b
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb2b;
    }
L_0x0047fb45:
    // 0047fb45  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0047fb47  eba5                   -jmp 0x47faee
    goto L_0x0047faee;
L_0x0047fb49:
    // 0047fb49  395d1c                 +cmp dword ptr [ebp + 0x1c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fb4c  7e31                   -jle 0x47fb7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047fb7f;
    }
    // 0047fb4e  837dc402               +cmp dword ptr [ebp - 0x3c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fb52  72a5                   -jb 0x47faf9
    if (cpu.flags.cf)
    {
        goto L_0x0047faf9;
    }
    // 0047fb54  8d45ca                 -lea eax, [ebp - 0x36]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-54) /* -0x36 */);
    // 0047fb57  385dca                 +cmp byte ptr [ebp - 0x36], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-54) /* -0x36 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb5a  749d                   -je 0x47faf9
    if (cpu.flags.zf)
    {
        goto L_0x0047faf9;
    }
L_0x0047fb5c:
    // 0047fb5c  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047fb5f  3ad3                   +cmp dl, bl
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb61  7496                   -je 0x47faf9
    if (cpu.flags.zf)
    {
        goto L_0x0047faf9;
    }
    // 0047fb63  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047fb66  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047fb68  3a08                   +cmp cl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb6a  7208                   -jb 0x47fb74
    if (cpu.flags.cf)
    {
        goto L_0x0047fb74;
    }
    // 0047fb6c  3aca                   +cmp cl, dl
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb6e  0f8678ffffff           -jbe 0x47faec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047faec;
    }
L_0x0047fb74:
    // 0047fb74  40                     -inc eax
    (cpu.eax)++;
    // 0047fb75  40                     -inc eax
    (cpu.eax)++;
    // 0047fb76  3818                   +cmp byte ptr [eax], bl
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
    // 0047fb78  75e2                   -jne 0x47fb5c
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb5c;
    }
    // 0047fb7a  e97affffff             -jmp 0x47faf9
    goto L_0x0047faf9;
L_0x0047fb7f:
    // 0047fb7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fb80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fb81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fb82  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047fb85  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047fb87  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fb8a  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fb90  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0047fb93  3bc3                   +cmp eax, ebx
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
    // 0047fb95  0f84cf000000           -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fb9b  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0047fb9e  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047fba0  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047fba3  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047fba5  e88681ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047fbaa  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047fbad  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047fbaf  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0047fbb2  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047fbb6  eb16                   -jmp 0x47fbce
    return sub_47fbce(app, cpu);
}

/* align: skip  */
void Application::sub_47fbb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fbb8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fbba  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fbbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fbbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fbbc  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047fbbf  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fbc1  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 0047fbc4  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047fbc8  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047fbcb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fbcd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fbce  395ddc                 +cmp dword ptr [ebp - 0x24], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fbd1  0f8493000000           -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fbd7  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047fbda  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047fbdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fbde  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047fbe1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fbe2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fbe5  8b35bc714800           -mov esi, dword ptr [0x4871bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    // 0047fbeb  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fbed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fbef  7479                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fbf1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fbf2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fbf3  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047fbf6  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fbf9  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047fbfb  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fbfe  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc00  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047fc02  8975e0                 -mov dword ptr [ebp - 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.esi;
    // 0047fc05  3bf3                   +cmp esi, ebx
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
    // 0047fc07  7461                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fc09  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0047fc0c  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0047fc0f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047fc12  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047fc14  e81781ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047fc19  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047fc1c  8bfc                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047fc1e  897dd8                 -mov dword ptr [ebp - 0x28], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edi;
    // 0047fc21  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047fc25  eb12                   -jmp 0x47fc39
    return sub_47fc39(app, cpu);
}

/* align: skip  */
void Application::sub_47fbce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047fbce;
    // 0047fbbc  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047fbbf  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fbc1  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 0047fbc4  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047fbc8  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047fbcb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fbcd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x0047fbce:
    // 0047fbce  395ddc                 +cmp dword ptr [ebp - 0x24], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fbd1  0f8493000000           -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fbd7  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047fbda  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047fbdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fbde  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047fbe1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fbe2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fbe5  8b35bc714800           -mov esi, dword ptr [0x4871bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    // 0047fbeb  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fbed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fbef  7479                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fbf1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fbf2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fbf3  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047fbf6  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fbf9  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047fbfb  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fbfe  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc00  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047fc02  8975e0                 -mov dword ptr [ebp - 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.esi;
    // 0047fc05  3bf3                   +cmp esi, ebx
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
    // 0047fc07  7461                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        return sub_47fc6a(app, cpu);
    }
    // 0047fc09  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0047fc0c  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0047fc0f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047fc12  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047fc14  e81781ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047fc19  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047fc1c  8bfc                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047fc1e  897dd8                 -mov dword ptr [ebp - 0x28], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edi;
    // 0047fc21  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047fc25  eb12                   -jmp 0x47fc39
    return sub_47fc39(app, cpu);
}

/* align: skip  */
void Application::sub_47fc27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fc27  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fc29  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fc2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fc2b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047fc2e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc30  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047fc32  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047fc36  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047fc39  3bfb                   +cmp edi, ebx
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
    // 0047fc3b  742d                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc3f  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047fc42  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fc45  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fc47  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fc4a  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fc52  7416                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc56  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047fc59  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047fc5c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047fc5f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fc62  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc68  eb02                   -jmp 0x47fc6c
    goto L_0x0047fc6c;
L_0x0047fc6a:
    // 0047fc6a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047fc6c:
    // 0047fc6c  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0047fc6f  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047fc72  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047fc79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fc6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047fc6c;
    // 0047fc2b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047fc2e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc30  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047fc32  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047fc36  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047fc39  3bfb                   +cmp edi, ebx
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
    // 0047fc3b  742d                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc3f  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047fc42  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fc45  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fc47  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fc4a  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fc52  7416                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc56  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047fc59  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047fc5c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047fc5f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fc62  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc68  eb02                   -jmp 0x47fc6c
    goto L_0x0047fc6c;
L_0x0047fc6a:
    // 0047fc6a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047fc6c:
L_entry_0x0047fc6c:
    // 0047fc6c  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0047fc6f  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047fc72  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047fc79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fc6a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047fc6a;
    // 0047fc2b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047fc2e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc30  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047fc32  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047fc36  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047fc39  3bfb                   +cmp edi, ebx
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
    // 0047fc3b  742d                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc3f  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047fc42  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fc45  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fc47  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fc4a  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fc52  7416                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc56  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047fc59  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047fc5c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047fc5f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fc62  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc68  eb02                   -jmp 0x47fc6c
    goto L_0x0047fc6c;
L_0x0047fc6a:
L_entry_0x0047fc6a:
    // 0047fc6a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047fc6c:
    // 0047fc6c  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0047fc6f  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047fc72  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047fc79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fc39(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047fc39;
    // 0047fc2b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047fc2e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc30  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047fc32  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047fc36  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
L_entry_0x0047fc39:
    // 0047fc39  3bfb                   +cmp edi, ebx
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
    // 0047fc3b  742d                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc3f  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047fc42  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047fc45  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fc47  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fc4a  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fc52  7416                   -je 0x47fc6a
    if (cpu.flags.zf)
    {
        goto L_0x0047fc6a;
    }
    // 0047fc54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc56  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047fc59  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047fc5c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047fc5f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fc62  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fc68  eb02                   -jmp 0x47fc6c
    goto L_0x0047fc6c;
L_0x0047fc6a:
    // 0047fc6a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047fc6c:
    // 0047fc6c  8d65b4                 -lea esp, [ebp - 0x4c]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0047fc6f  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047fc72  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047fc79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fc7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fc7e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047fc82  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fc86  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fc88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc89  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0047fc8c  740d                   -je 0x47fc9b
    if (cpu.flags.zf)
    {
        goto L_0x0047fc9b;
    }
L_0x0047fc8e:
    // 0047fc8e  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fc91  7408                   -je 0x47fc9b
    if (cpu.flags.zf)
    {
        goto L_0x0047fc9b;
    }
    // 0047fc93  40                     -inc eax
    (cpu.eax)++;
    // 0047fc94  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047fc96  49                     -dec ecx
    (cpu.ecx)--;
    // 0047fc97  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047fc99  75f3                   -jne 0x47fc8e
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc8e;
    }
L_0x0047fc9b:
    // 0047fc9b  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fc9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc9f  7505                   -jne 0x47fca6
    if (!cpu.flags.zf)
    {
        goto L_0x0047fca6;
    }
    // 0047fca1  2b442404               -sub eax, dword ptr [esp + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0047fca5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fca6:
    // 0047fca6  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fca8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__allmul(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fcb0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047fcb4  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fcb8  0bc8                   +or ecx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047fcba  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047fcbe  7509                   -jne 0x47fcc9
    if (!cpu.flags.zf)
    {
        goto L_0x0047fcc9;
    }
    // 0047fcc0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fcc4  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0047fcc6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0047fcc9:
    // 0047fcc9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fcca  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0047fccc  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047fcce  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047fcd2  f7642414               -mul dword ptr [esp + 0x14]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0047fcd6  03d8                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047fcd8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047fcdc  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0047fcde  03d3                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fce0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fce1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::__frnd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fce4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fce5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047fce7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fce8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fce9  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0047fcec  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 0047fcee  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047fcf1  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047fcf4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fcf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fcf6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fcf6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fcf7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047fcf9  833dc81e520000         +cmp dword ptr [0x521ec8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5381832) /* 0x521ec8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fd00  7529                   -jne 0x47fd2b
    if (!cpu.flags.zf)
    {
        goto L_0x0047fd2b;
    }
    // 0047fd02  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047fd05  dd450c                 -fld qword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047fd08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd0a  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047fd0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd0e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd0f  d9ee                   -fldz 
    cpu.fpu.push(0.0);
    // 0047fd11  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047fd14  dd450c                 -fld qword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047fd17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd19  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047fd1c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fd1f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fd21  e886050000             -call 0x4802ac
    cpu.esp -= 4;
    sub_4802ac(app, cpu);
    // 0047fd26  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047fd29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fd2b:
    // 0047fd2b  e882e7ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047fd30  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0047fd35  c70021000000           -mov dword ptr [eax], 0x21
    app->getMemory<x86::reg32>(cpu.eax) = 33 /*0x21*/;
    // 0047fd3b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047fd3e  e8ed070000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 0047fd43  dd450c                 -fld qword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047fd46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fd4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fd4a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fd4b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047fd4d  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0047fd50  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fd53  8d4518                 -lea eax, [ebp + 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047fd56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fd57  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fd5a  e836030000             -call 0x480095
    cpu.esp -= 4;
    sub_480095(app, cpu);
    // 0047fd5f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fd62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fd64  7522                   -jne 0x47fd88
    if (!cpu.flags.zf)
    {
        goto L_0x0047fd88;
    }
    // 0047fd66  8d4518                 -lea eax, [ebp + 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047fd69  8365e0fe               -and dword ptr [ebp - 0x20], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 0047fd6d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fd6e  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047fd71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fd72  8d4520                 -lea eax, [ebp + 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047fd75  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047fd78  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fd7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fd7c  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 0047fd7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fd80  e85d000000             -call 0x47fde2
    cpu.esp -= 4;
    sub_47fde2(app, cpu);
    // 0047fd85  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x0047fd88:
    // 0047fd88  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047fd8b  e8f1050000             -call 0x480381
    cpu.esp -= 4;
    sub_480381(app, cpu);
    // 0047fd90  833dc81e520000         +cmp dword ptr [0x521ec8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5381832) /* 0x521ec8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fd97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd98  752c                   -jne 0x47fdc6
    if (!cpu.flags.zf)
    {
        goto L_0x0047fdc6;
    }
    // 0047fd9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fd9c  7428                   -je 0x47fdc6
    if (cpu.flags.zf)
    {
        goto L_0x0047fdc6;
    }
    // 0047fd9e  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fda1  dd4518                 -fld qword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0047fda4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fda5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fda6  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047fda9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fdaa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fdab  d9ee                   -fldz 
    cpu.fpu.push(0.0);
    // 0047fdad  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047fdb0  dd4510                 -fld qword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    // 0047fdb3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fdb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fdb5  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047fdb8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047fdbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fdbc  e8eb040000             -call 0x4802ac
    cpu.esp -= 4;
    sub_4802ac(app, cpu);
    // 0047fdc1  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047fdc4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fdc6:
    // 0047fdc6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fdc7  e868050000             -call 0x480334
    cpu.esp -= 4;
    sub_480334(app, cpu);
    // 0047fdcc  c70424ffff0000         -mov dword ptr [esp], 0xffff
    app->getMemory<x86::reg32>(cpu.esp) = 65535 /*0xffff*/;
    // 0047fdd3  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047fdd6  e855070000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 0047fddb  dd4518                 -fld qword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0047fdde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fddf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fde0  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fde1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fde2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fde2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fde3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047fde5  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fde8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fdea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fdeb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fdec  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047fdef  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fdf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fdf3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047fdf5  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047fdf8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fdfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdfc  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047fdff  8a4d10                 -mov cl, byte ptr [ebp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047fe02  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0047fe05  740d                   -je 0x47fe14
    if (cpu.flags.zf)
    {
        goto L_0x0047fe14;
    }
    // 0047fe07  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe0a  c745108f0000c0         -mov dword ptr [ebp + 0x10], 0xc000008f
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 3221225615 /*0xc000008f*/;
    // 0047fe11  095804                 -or dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047fe14:
    // 0047fe14  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0047fe17  740e                   -je 0x47fe27
    if (cpu.flags.zf)
    {
        goto L_0x0047fe27;
    }
    // 0047fe19  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe1c  c74510930000c0         -mov dword ptr [ebp + 0x10], 0xc0000093
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 3221225619 /*0xc0000093*/;
    // 0047fe23  83480402               -or dword ptr [eax + 4], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0047fe27:
    // 0047fe27  84cb                   +test bl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.cl));
    // 0047fe29  740e                   -je 0x47fe39
    if (cpu.flags.zf)
    {
        goto L_0x0047fe39;
    }
    // 0047fe2b  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe2e  c74510910000c0         -mov dword ptr [ebp + 0x10], 0xc0000091
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 3221225617 /*0xc0000091*/;
    // 0047fe35  83480404               -or dword ptr [eax + 4], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047fe39:
    // 0047fe39  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0047fe3c  740e                   -je 0x47fe4c
    if (cpu.flags.zf)
    {
        goto L_0x0047fe4c;
    }
    // 0047fe3e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe41  c745108e0000c0         -mov dword ptr [ebp + 0x10], 0xc000008e
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 3221225614 /*0xc000008e*/;
    // 0047fe48  83480408               -or dword ptr [eax + 4], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0047fe4c:
    // 0047fe4c  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0047fe4f  740e                   -je 0x47fe5f
    if (cpu.flags.zf)
    {
        goto L_0x0047fe5f;
    }
    // 0047fe51  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe54  c74510900000c0         -mov dword ptr [ebp + 0x10], 0xc0000090
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 3221225616 /*0xc0000090*/;
    // 0047fe5b  83480410               -or dword ptr [eax + 4], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047fe5f:
    // 0047fe5f  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047fe62  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe65  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fe67  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047fe69  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047fe6c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047fe6e  23cb                   -and ecx, ebx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fe70  83e2ef                 -and edx, 0xffffffef
    cpu.edx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0047fe73  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0047fe76  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047fe78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe79  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047fe7c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047fe7e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe81  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047fe83  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047fe86  83e104                 -and ecx, 4
    cpu.ecx &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047fe89  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 0047fe8b  83e2f7                 -and edx, 0xfffffff7
    cpu.edx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 0047fe8e  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047fe90  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047fe93  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047fe95  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fe98  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047fe9a  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047fe9d  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0047fe9f  83e104                 -and ecx, 4
    cpu.ecx &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047fea2  83e2fb                 -and edx, 0xfffffffb
    cpu.edx &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
    // 0047fea5  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047fea7  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047feaa  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047feac  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047feaf  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047feb1  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047feb4  c1e903                 -shr ecx, 3
    cpu.ecx >>= 3 /*0x3*/ % 32;
    // 0047feb7  23cf                   -and ecx, edi
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edi));
    // 0047feb9  83e2fd                 -and edx, 0xfffffffd
    cpu.edx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
    // 0047febc  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047febe  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047fec1  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047fec3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fec6  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047fec8  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047fecb  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 0047fece  23cb                   -and ecx, ebx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fed0  83e2fe                 -and edx, 0xfffffffe
    cpu.edx &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 0047fed3  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047fed5  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047fed8  e836060000             -call 0x480513
    cpu.esp -= 4;
    sub_480513(app, cpu);
    // 0047fedd  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 0047fedf  7407                   -je 0x47fee8
    if (cpu.flags.zf)
    {
        goto L_0x0047fee8;
    }
    // 0047fee1  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fee4  83490c10               -or dword ptr [ecx + 0xc], 0x10
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047fee8:
    // 0047fee8  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0047feea  7407                   -je 0x47fef3
    if (cpu.flags.zf)
    {
        goto L_0x0047fef3;
    }
    // 0047feec  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047feef  83490c08               -or dword ptr [ecx + 0xc], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0047fef3:
    // 0047fef3  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0047fef5  7407                   -je 0x47fefe
    if (cpu.flags.zf)
    {
        goto L_0x0047fefe;
    }
    // 0047fef7  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fefa  83490c04               -or dword ptr [ecx + 0xc], 4
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047fefe:
    // 0047fefe  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0047ff00  7406                   -je 0x47ff08
    if (cpu.flags.zf)
    {
        goto L_0x0047ff08;
    }
    // 0047ff02  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff05  09790c                 -or dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047ff08:
    // 0047ff08  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0047ff0a  7406                   -je 0x47ff12
    if (cpu.flags.zf)
    {
        goto L_0x0047ff12;
    }
    // 0047ff0c  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff0f  09580c                 -or dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047ff12:
    // 0047ff12  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047ff14  b9000c0000             -mov ecx, 0xc00
    cpu.ecx = 3072 /*0xc00*/;
    // 0047ff19  23c1                   +and eax, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047ff1b  7434                   -je 0x47ff51
    if (cpu.flags.zf)
    {
        goto L_0x0047ff51;
    }
    // 0047ff1d  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ff22  741f                   -je 0x47ff43
    if (cpu.flags.zf)
    {
        goto L_0x0047ff43;
    }
    // 0047ff24  3d00080000             +cmp eax, 0x800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ff29  740c                   -je 0x47ff37
    if (cpu.flags.zf)
    {
        goto L_0x0047ff37;
    }
    // 0047ff2b  3bc1                   +cmp eax, ecx
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
    // 0047ff2d  7528                   -jne 0x47ff57
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff57;
    }
    // 0047ff2f  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff32  830803                 +or dword ptr [eax], 3
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0047ff35  eb20                   -jmp 0x47ff57
    goto L_0x0047ff57;
L_0x0047ff37:
    // 0047ff37  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff3a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ff3c  83e1fe                 -and ecx, 0xfffffffe
    cpu.ecx &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 0047ff3f  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047ff41  eb0a                   -jmp 0x47ff4d
    goto L_0x0047ff4d;
L_0x0047ff43:
    // 0047ff43  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff46  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ff48  83e1fd                 -and ecx, 0xfffffffd
    cpu.ecx &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
    // 0047ff4b  0bcb                   +or ecx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0047ff4d:
    // 0047ff4d  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047ff4f  eb06                   -jmp 0x47ff57
    goto L_0x0047ff57;
L_0x0047ff51:
    // 0047ff51  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff54  8320fc                 -and dword ptr [eax], 0xfffffffc
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
L_0x0047ff57:
    // 0047ff57  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047ff59  b900030000             -mov ecx, 0x300
    cpu.ecx = 768 /*0x300*/;
    // 0047ff5e  23c1                   +and eax, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047ff60  7420                   -je 0x47ff82
    if (cpu.flags.zf)
    {
        goto L_0x0047ff82;
    }
    // 0047ff62  3d00020000             +cmp eax, 0x200
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ff67  740c                   -je 0x47ff75
    if (cpu.flags.zf)
    {
        goto L_0x0047ff75;
    }
    // 0047ff69  3bc1                   +cmp eax, ecx
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
    // 0047ff6b  7522                   -jne 0x47ff8f
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff8f;
    }
    // 0047ff6d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff70  8320e3                 +and dword ptr [eax], 0xffffffe3
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(4294967267 /*0xffffffe3*/))));
    // 0047ff73  eb1a                   -jmp 0x47ff8f
    goto L_0x0047ff8f;
L_0x0047ff75:
    // 0047ff75  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff78  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ff7a  83e1e7                 -and ecx, 0xffffffe7
    cpu.ecx &= x86::reg32(x86::sreg32(4294967271 /*0xffffffe7*/));
    // 0047ff7d  83c904                 +or ecx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0047ff80  eb0b                   -jmp 0x47ff8d
    goto L_0x0047ff8d;
L_0x0047ff82:
    // 0047ff82  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff85  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ff87  83e1eb                 -and ecx, 0xffffffeb
    cpu.ecx &= x86::reg32(x86::sreg32(4294967275 /*0xffffffeb*/));
    // 0047ff8a  83c908                 -or ecx, 8
    cpu.ecx |= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0047ff8d:
    // 0047ff8d  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
L_0x0047ff8f:
    // 0047ff8f  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ff92  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047ff95  81e1ff0f0000           -and ecx, 0xfff
    cpu.ecx &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0047ff9b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ff9d  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0047ffa0  81e21f00feff           -and edx, 0xfffe001f
    cpu.edx &= x86::reg32(x86::sreg32(4294836255 /*0xfffe001f*/));
    // 0047ffa6  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ffa8  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047ffaa  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ffad  095820                 -or dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ffb0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ffb3  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047ffb6  83e1e3                 -and ecx, 0xffffffe3
    cpu.ecx &= x86::reg32(x86::sreg32(4294967267 /*0xffffffe3*/));
    // 0047ffb9  0bcf                   -or ecx, edi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ffbb  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0047ffbe  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047ffc1  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 0047ffc3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ffc6  dd5810                 -fstp qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ffc9  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ffcc  095850                 -or dword ptr [eax + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ffcf  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ffd2  8b4850                 -mov ecx, dword ptr [eax + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0047ffd5  83e1e3                 -and ecx, 0xffffffe3
    cpu.ecx &= x86::reg32(x86::sreg32(4294967267 /*0xffffffe3*/));
    // 0047ffd8  0bcf                   -or ecx, edi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ffda  8b7d1c                 -mov edi, dword ptr [ebp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047ffdd  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0047ffe0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ffe3  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 0047ffe5  dd5840                 -fstp qword ptr [eax + 0x40]
    app->getMemory<double>(cpu.eax + x86::reg32(64) /* 0x40 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ffe8  e834050000             -call 0x480521
    cpu.esp -= 4;
    sub_480521(app, cpu);
    // 0047ffed  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047fff0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fff1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fff2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047fff4  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047fff7  ff1518714800           -call dword ptr [0x487118]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747544) /* 0x487118 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047fffd  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00480000  f6400810               +test byte ptr [eax + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00480004  7403                   -je 0x480009
    if (cpu.flags.zf)
    {
        goto L_0x00480009;
    }
    // 00480006  8326fe                 -and dword ptr [esi], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
L_0x00480009:
    // 00480009  f6400808               +test byte ptr [eax + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 0048000d  7403                   -je 0x480012
    if (cpu.flags.zf)
    {
        goto L_0x00480012;
    }
    // 0048000f  8326fb                 -and dword ptr [esi], 0xfffffffb
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
L_0x00480012:
    // 00480012  f6400804               +test byte ptr [eax + 8], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 4 /*0x4*/));
    // 00480016  7403                   -je 0x48001b
    if (cpu.flags.zf)
    {
        goto L_0x0048001b;
    }
    // 00480018  8326f7                 -and dword ptr [esi], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
L_0x0048001b:
    // 0048001b  f6400802               +test byte ptr [eax + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 0048001f  7403                   -je 0x480024
    if (cpu.flags.zf)
    {
        goto L_0x00480024;
    }
    // 00480021  8326ef                 +and dword ptr [esi], 0xffffffef
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/))));
L_0x00480024:
    // 00480024  845808                 -test byte ptr [eax + 8], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & cpu.bl));
    // 00480027  7403                   -je 0x48002c
    if (cpu.flags.zf)
    {
        goto L_0x0048002c;
    }
    // 00480029  8326df                 -and dword ptr [esi], 0xffffffdf
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
L_0x0048002c:
    // 0048002c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048002e  bafff3ffff             -mov edx, 0xfffff3ff
    cpu.edx = 4294964223 /*0xfffff3ff*/;
    // 00480033  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00480036  83e900                 +sub ecx, 0
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
    // 00480039  7425                   -je 0x480060
    if (cpu.flags.zf)
    {
        goto L_0x00480060;
    }
    // 0048003b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048003c  7416                   -je 0x480054
    if (cpu.flags.zf)
    {
        goto L_0x00480054;
    }
    // 0048003e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048003f  7409                   -je 0x48004a
    if (cpu.flags.zf)
    {
        goto L_0x0048004a;
    }
    // 00480041  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480042  751e                   -jne 0x480062
    if (!cpu.flags.zf)
    {
        goto L_0x00480062;
    }
    // 00480044  804e010c               +or byte ptr [esi + 1], 0xc
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00480048  eb18                   -jmp 0x480062
    goto L_0x00480062;
L_0x0048004a:
    // 0048004a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048004c  80e5fb                 -and ch, 0xfb
    cpu.ch &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0048004f  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00480052  eb08                   -jmp 0x48005c
    goto L_0x0048005c;
L_0x00480054:
    // 00480054  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00480056  80e5f7                 -and ch, 0xf7
    cpu.ch &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00480059  80cd04                 +or ch, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/))));
L_0x0048005c:
    // 0048005c  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0048005e  eb02                   -jmp 0x480062
    goto L_0x00480062;
L_0x00480060:
    // 00480060  2116                   -and dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(cpu.edx));
L_0x00480062:
    // 00480062  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00480064  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00480067  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0048006a  83e900                 +sub ecx, 0
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
    // 0048006d  7413                   -je 0x480082
    if (cpu.flags.zf)
    {
        goto L_0x00480082;
    }
    // 0048006f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480070  7407                   -je 0x480079
    if (cpu.flags.zf)
    {
        goto L_0x00480079;
    }
    // 00480072  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480073  7516                   -jne 0x48008b
    if (!cpu.flags.zf)
    {
        goto L_0x0048008b;
    }
    // 00480075  2116                   +and dword ptr [esi], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00480077  eb12                   -jmp 0x48008b
    goto L_0x0048008b;
L_0x00480079:
    // 00480079  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048007b  23ca                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 0048007d  80cd02                 +or ch, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00480080  eb07                   -jmp 0x480089
    goto L_0x00480089;
L_0x00480082:
    // 00480082  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00480084  23ca                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 00480086  80cd03                 -or ch, 3
    cpu.ch |= x86::reg8(x86::sreg8(3 /*0x3*/));
L_0x00480089:
    // 00480089  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
L_0x0048008b:
    // 0048008b  dd4040                 -fld qword ptr [eax + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 0048008e  dd1f                   -fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480090  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480091  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480092  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480093  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480094  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480095(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480095  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480096  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480098  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048009b  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048009e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048009f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004800a0  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004800a2  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004800a5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004800a7  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004800a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800aa  7414                   -je 0x4800c0
    if (cpu.flags.zf)
    {
        goto L_0x004800c0;
    }
    // 004800ac  845d10                 -test byte ptr [ebp + 0x10], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */) & cpu.bl));
    // 004800af  740f                   -je 0x4800c0
    if (cpu.flags.zf)
    {
        goto L_0x004800c0;
    }
    // 004800b1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004800b2  e89c040000             -call 0x480553
    cpu.esp -= 4;
    sub_480553(app, cpu);
    // 004800b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800b8  83e7f7                 +and edi, 0xfffffff7
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/))));
    // 004800bb  e9ca010000             -jmp 0x48028a
    goto L_0x0048028a;
L_0x004800c0:
    // 004800c0  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004800c2  7416                   -je 0x4800da
    if (cpu.flags.zf)
    {
        goto L_0x004800da;
    }
    // 004800c4  f6451004               +test byte ptr [ebp + 0x10], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */) & 4 /*0x4*/));
    // 004800c8  7410                   -je 0x4800da
    if (cpu.flags.zf)
    {
        goto L_0x004800da;
    }
    // 004800ca  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004800cc  e882040000             -call 0x480553
    cpu.esp -= 4;
    sub_480553(app, cpu);
    // 004800d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800d2  83e7fb                 +and edi, 0xfffffffb
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/))));
    // 004800d5  e9b0010000             -jmp 0x48028a
    goto L_0x0048028a;
L_0x004800da:
    // 004800da  84c3                   +test bl, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.al));
    // 004800dc  0f84d2000000           -je 0x4801b4
    if (cpu.flags.zf)
    {
        goto L_0x004801b4;
    }
    // 004800e2  f6451008               +test byte ptr [ebp + 0x10], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */) & 8 /*0x8*/));
    // 004800e6  0f84c8000000           -je 0x4801b4
    if (cpu.flags.zf)
    {
        goto L_0x004801b4;
    }
    // 004800ec  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004800ee  e860040000             -call 0x480553
    cpu.esp -= 4;
    sub_480553(app, cpu);
    // 004800f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800f4  b8000c0000             -mov eax, 0xc00
    cpu.eax = 3072 /*0xc00*/;
    // 004800f9  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004800fc  23c8                   +and ecx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.eax))));
    // 004800fe  0f8488000000           -je 0x48018c
    if (cpu.flags.zf)
    {
        goto L_0x0048018c;
    }
    // 00480104  81f900040000           +cmp ecx, 0x400
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048010a  7458                   -je 0x480164
    if (cpu.flags.zf)
    {
        goto L_0x00480164;
    }
    // 0048010c  81f900080000           +cmp ecx, 0x800
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480112  7428                   -je 0x48013c
    if (cpu.flags.zf)
    {
        goto L_0x0048013c;
    }
    // 00480114  3bc8                   +cmp ecx, eax
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
    // 00480116  0f8590000000           -jne 0x4801ac
    if (!cpu.flags.zf)
    {
        goto L_0x004801ac;
    }
    // 0048011c  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048011f  dd01                   +fld qword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ecx)));
    // 00480121  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 00480127  dd0578674a00           +fld qword ptr [0x4a6778]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4876152) /* 0x4a6778 */)));
    // 0048012d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048012f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00480130  7702                   -ja 0x480134
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00480134;
    }
    // 00480132  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00480134:
    // 00480134  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480137  dd45f4                 +fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0048013a  eb6e                   -jmp 0x4801aa
    goto L_0x004801aa;
L_0x0048013c:
    // 0048013c  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048013f  dd01                   +fld qword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ecx)));
    // 00480141  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 00480147  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00480149  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0048014a  7608                   -jbe 0x480154
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480154;
    }
    // 0048014c  dd0568674a00           +fld qword ptr [0x4a6768]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4876136) /* 0x4a6768 */)));
    // 00480152  eb08                   -jmp 0x48015c
    goto L_0x0048015c;
L_0x00480154:
    // 00480154  dd0578674a00           +fld qword ptr [0x4a6778]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4876152) /* 0x4a6778 */)));
    // 0048015a  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x0048015c:
    // 0048015c  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048015f  dd45f4                 +fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00480162  eb46                   -jmp 0x4801aa
    goto L_0x004801aa;
L_0x00480164:
    // 00480164  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00480167  dd01                   +fld qword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ecx)));
    // 00480169  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 0048016f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00480171  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00480172  7608                   -jbe 0x48017c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048017c;
    }
    // 00480174  dd0578674a00           +fld qword ptr [0x4a6778]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4876152) /* 0x4a6778 */)));
    // 0048017a  eb08                   -jmp 0x480184
    goto L_0x00480184;
L_0x0048017c:
    // 0048017c  dd0568674a00           +fld qword ptr [0x4a6768]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4876136) /* 0x4a6768 */)));
    // 00480182  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00480184:
    // 00480184  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480187  dd45f4                 +fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0048018a  eb1e                   -jmp 0x4801aa
    goto L_0x004801aa;
L_0x0048018c:
    // 0048018c  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048018f  dd01                   +fld qword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ecx)));
    // 00480191  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 00480197  dd0568674a00           +fld qword ptr [0x4a6768]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4876136) /* 0x4a6768 */)));
    // 0048019d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048019f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004801a0  7702                   -ja 0x4801a4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004801a4;
    }
    // 004801a2  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004801a4:
    // 004801a4  dd5df4                 -fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004801a7  dd45f4                 -fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
L_0x004801aa:
    // 004801aa  dd19                   -fstp qword ptr [ecx]
    app->getMemory<double>(cpu.ecx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004801ac:
    // 004801ac  83e7fe                 +and edi, 0xfffffffe
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/))));
    // 004801af  e9d6000000             -jmp 0x48028a
    goto L_0x0048028a;
L_0x004801b4:
    // 004801b4  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004801b6  0f84ce000000           -je 0x48028a
    if (cpu.flags.zf)
    {
        goto L_0x0048028a;
    }
    // 004801bc  f6451010               +test byte ptr [ebp + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004801c0  0f84c4000000           -je 0x48028a
    if (cpu.flags.zf)
    {
        goto L_0x0048028a;
    }
    // 004801c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004801c7  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004801c9  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004801cb  7402                   -je 0x4801cf
    if (cpu.flags.zf)
    {
        goto L_0x004801cf;
    }
    // 004801cd  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x004801cf:
    // 004801cf  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004801d2  dd00                   +fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 004801d4  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004801d7  dd45f4                 +fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004801da  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 004801e0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004801e2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004801e3  0f848f000000           -je 0x480278
    if (cpu.flags.zf)
    {
        goto L_0x00480278;
    }
    // 004801e9  dd45f4                 -fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004801ec  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004801ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004801f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004801f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004801f2  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004801f5  e858020000             -call 0x480452
    cpu.esp -= 4;
    sub_480452(app, cpu);
    // 004801fa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004801fd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480200  dd5df4                 -fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480203  8d8800faffff           -lea ecx, [eax - 0x600]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1536) /* -0x600 */);
    // 00480209  81f9cefbffff           +cmp ecx, 0xfffffbce
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966222 /*0xfffffbce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048020f  7d09                   -jge 0x48021a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048021a;
    }
    // 00480211  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00480213  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00480215  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480218  eb54                   -jmp 0x48026e
    goto L_0x0048026e;
L_0x0048021a:
    // 0048021a  dd45f4                 +fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0048021d  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 00480223  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00480225  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00480226  7304                   -jae 0x48022c
    if (!cpu.flags.cf)
    {
        goto L_0x0048022c;
    }
    // 00480228  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048022a  eb02                   -jmp 0x48022e
    goto L_0x0048022e;
L_0x0048022c:
    // 0048022c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048022e:
    // 0048022e  8a45fa                 -mov al, byte ptr [ebp - 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00480231  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00480234  0c10                   -or al, 0x10
    cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00480236  668945fa               -mov word ptr [ebp - 6], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.ax;
    // 0048023a  b803fcffff             -mov eax, 0xfffffc03
    cpu.eax = 4294966275 /*0xfffffc03*/;
    // 0048023f  3bc8                   +cmp ecx, eax
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
    // 00480241  7d1f                   -jge 0x480262
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480262;
    }
    // 00480243  2bc1                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00480245:
    // 00480245  845df4                 -test byte ptr [ebp - 0xc], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */) & cpu.bl));
    // 00480248  7406                   -je 0x480250
    if (cpu.flags.zf)
    {
        goto L_0x00480250;
    }
    // 0048024a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048024c  7502                   -jne 0x480250
    if (!cpu.flags.zf)
    {
        goto L_0x00480250;
    }
    // 0048024e  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x00480250:
    // 00480250  d16df4                 +shr dword ptr [ebp - 0xc], 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */));
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00480253  845df8                 -test byte ptr [ebp - 8], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) & cpu.bl));
    // 00480256  7404                   -je 0x48025c
    if (cpu.flags.zf)
    {
        goto L_0x0048025c;
    }
    // 00480258  804df780               -or byte ptr [ebp - 9], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-9) /* -0x9 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0048025c:
    // 0048025c  d16df8                 +shr dword ptr [ebp - 8], 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0048025f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480260  75e3                   -jne 0x480245
    if (!cpu.flags.zf)
    {
        goto L_0x00480245;
    }
L_0x00480262:
    // 00480262  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480264  7408                   -je 0x48026e
    if (cpu.flags.zf)
    {
        goto L_0x0048026e;
    }
    // 00480266  dd45f4                 +fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00480269  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0048026b  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0048026e:
    // 0048026e  dd45f4                 +fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00480271  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00480274  dd18                   +fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480276  eb02                   -jmp 0x48027a
    goto L_0x0048027a;
L_0x00480278:
    // 00480278  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0048027a:
    // 0048027a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048027c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048027d  7408                   -je 0x480287
    if (cpu.flags.zf)
    {
        goto L_0x00480287;
    }
    // 0048027f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00480281  e8cd020000             -call 0x480553
    cpu.esp -= 4;
    sub_480553(app, cpu);
    // 00480286  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480287:
    // 00480287  83e7fd                 -and edi, 0xfffffffd
    cpu.edi &= x86::reg32(x86::sreg32(4294967293 /*0xfffffffd*/));
L_0x0048028a:
    // 0048028a  f6450810               +test byte ptr [ebp + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 0048028e  7411                   -je 0x4802a1
    if (cpu.flags.zf)
    {
        goto L_0x004802a1;
    }
    // 00480290  f6451020               +test byte ptr [ebp + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 00480294  740b                   -je 0x4802a1
    if (cpu.flags.zf)
    {
        goto L_0x004802a1;
    }
    // 00480296  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00480298  e8b6020000             -call 0x480553
    cpu.esp -= 4;
    sub_480553(app, cpu);
    // 0048029d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048029e  83e7ef                 -and edi, 0xffffffef
    cpu.edi &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
L_0x004802a1:
    // 004802a1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004802a3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004802a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802a7  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004802aa  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4802ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004802ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004802ad  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004802af  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004802b2  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004802b5  e8a2000000             -call 0x48035c
    cpu.esp -= 4;
    sub_48035c(app, cpu);
    // 004802ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004802bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802bd  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004802c0  7455                   -je 0x480317
    if (cpu.flags.zf)
    {
        goto L_0x00480317;
    }
    // 004802c2  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004802c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004802c6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004802c9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004802cc  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004802cf  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004802d2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004802d5  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004802d8  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004802db  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004802e0  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 004802e3  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004802e6  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004802e9  8975e0                 -mov dword ptr [ebp - 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.esi;
    // 004802ec  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004802ef  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004802f2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004802f5  e836020000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 004802fa  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004802fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004802fe  e82d4cfeff             -call 0x464f30
    cpu.esp -= 4;
    sub_464f30(app, cpu);
    // 00480303  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480306  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480308  7507                   -jne 0x480311
    if (!cpu.flags.zf)
    {
        goto L_0x00480311;
    }
    // 0048030a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048030b  e824000000             -call 0x480334
    cpu.esp -= 4;
    sub_480334(app, cpu);
    // 00480310  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480311:
    // 00480311  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00480314  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480315  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480316  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480317:
    // 00480317  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0048031c  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 0048031f  e80c020000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 00480324  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00480327  e808000000             -call 0x480334
    cpu.esp -= 4;
    sub_480334(app, cpu);
    // 0048032c  dd4520                 -fld qword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0048032f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480332  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480333  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480334(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480334  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480338  83f801                 +cmp eax, 1
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
    // 0048033b  7413                   -je 0x480350
    if (cpu.flags.zf)
    {
        goto L_0x00480350;
    }
    // 0048033d  7e1c                   -jle 0x48035b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048035b;
    }
    // 0048033f  83f803                 +cmp eax, 3
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
    // 00480342  7f17                   -jg 0x48035b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048035b;
    }
    // 00480344  e869e1ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00480349  c70022000000           -mov dword ptr [eax], 0x22
    app->getMemory<x86::reg32>(cpu.eax) = 34 /*0x22*/;
    // 0048034f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480350:
    // 00480350  e85de1ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00480355  c70021000000           -mov dword ptr [eax], 0x21
    app->getMemory<x86::reg32>(cpu.eax) = 33 /*0x21*/;
L_0x0048035b:
    // 0048035b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48035c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048035c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048035e  b890664a00             -mov eax, 0x4a6690
    cpu.eax = 4875920 /*0x4a6690*/;
L_0x00480363:
    // 00480363  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00480365  3b542404               +cmp edx, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480369  740e                   -je 0x480379
    if (cpu.flags.zf)
    {
        goto L_0x00480379;
    }
    // 0048036b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048036e  41                     -inc ecx
    (cpu.ecx)++;
    // 0048036f  3d68674a00             +cmp eax, 0x4a6768
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4876136 /*0x4a6768*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480374  7ced                   -jl 0x480363
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480363;
    }
    // 00480376  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480378  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480379:
    // 00480379  8b04cd94664a00         -mov eax, dword ptr [ecx*8 + 0x4a6694]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4875924) /* 0x4a6694 */ + cpu.ecx * 8);
    // 00480380  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480381(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480381  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480385  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00480387  7404                   -je 0x48038d
    if (cpu.flags.zf)
    {
        goto L_0x0048038d;
    }
    // 00480389  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0048038b  eb16                   -jmp 0x4803a3
    goto L_0x004803a3;
L_0x0048038d:
    // 0048038d  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0048038f  7404                   -je 0x480395
    if (cpu.flags.zf)
    {
        goto L_0x00480395;
    }
    // 00480391  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00480393  eb0e                   -jmp 0x4803a3
    goto L_0x004803a3;
L_0x00480395:
    // 00480395  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00480397  7404                   -je 0x48039d
    if (cpu.flags.zf)
    {
        goto L_0x0048039d;
    }
    // 00480399  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048039b  eb06                   -jmp 0x4803a3
    goto L_0x004803a3;
L_0x0048039d:
    // 0048039d  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0048039f  7404                   -je 0x4803a5
    if (cpu.flags.zf)
    {
        goto L_0x004803a5;
    }
    // 004803a1  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
L_0x004803a3:
    // 004803a3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004803a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803a5:
    // 004803a5  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 004803a8  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004803ab  d1e0                   -shl eax, 1
    cpu.eax <<= 1 /*0x1*/ % 32;
    // 004803ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__copysign(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004803ae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004803af  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004803b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004803b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004803b3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004803b6  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004803b9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004803bc  33450c                 -xor eax, dword ptr [ebp + 0xc]
    cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004803bf  25ffffff7f             -and eax, 0x7fffffff
    cpu.eax &= x86::reg32(x86::sreg32(2147483647 /*0x7fffffff*/));
    // 004803c4  334514                 -xor eax, dword ptr [ebp + 0x14]
    cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
    // 004803c7  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004803ca  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004803cd  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004803ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4803cf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004803cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004803d0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004803d2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004803d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004803d4  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004803d7  8b4d0e                 -mov ecx, dword ptr [ebp + 0xe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 004803da  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004803dd  05fe030000             -add eax, 0x3fe
    (cpu.eax) += x86::reg32(x86::sreg32(1022 /*0x3fe*/));
    // 004803e2  6681e10f80             -and cx, 0x800f
    cpu.cx &= x86::reg16(x86::sreg16(32783 /*0x800f*/));
    // 004803e7  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004803ea  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004803ed  0bc1                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004803ef  668945fe               -mov word ptr [ebp - 2], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004803f3  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004803f6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004803f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4803f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004803f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004803f9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004803fb  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004803fd  817d0c0000f07f         +cmp dword ptr [ebp + 0xc], 0x7ff00000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480404  7509                   -jne 0x48040f
    if (!cpu.flags.zf)
    {
        goto L_0x0048040f;
    }
    // 00480406  395508                 +cmp dword ptr [ebp + 8], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480409  7516                   -jne 0x480421
    if (!cpu.flags.zf)
    {
        goto L_0x00480421;
    }
    // 0048040b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048040d  eb3c                   -jmp 0x48044b
    goto L_0x0048044b;
L_0x0048040f:
    // 0048040f  817d0c0000f0ff         +cmp dword ptr [ebp + 0xc], 0xfff00000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480416  7509                   -jne 0x480421
    if (!cpu.flags.zf)
    {
        goto L_0x00480421;
    }
    // 00480418  395508                 +cmp dword ptr [ebp + 8], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048041b  7504                   -jne 0x480421
    if (!cpu.flags.zf)
    {
        goto L_0x00480421;
    }
    // 0048041d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048041f  eb2a                   -jmp 0x48044b
    goto L_0x0048044b;
L_0x00480421:
    // 00480421  8b4d0e                 -mov ecx, dword ptr [ebp + 0xe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 00480424  b8f87f0000             -mov eax, 0x7ff8
    cpu.eax = 32760 /*0x7ff8*/;
    // 00480429  23c8                   -and ecx, eax
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0048042b  663bc8                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048042e  7504                   -jne 0x480434
    if (!cpu.flags.zf)
    {
        goto L_0x00480434;
    }
    // 00480430  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00480432  eb17                   -jmp 0x48044b
    goto L_0x0048044b;
L_0x00480434:
    // 00480434  6681f9f07f             +cmp cx, 0x7ff0
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32752 /*0x7ff0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00480439  7513                   -jne 0x48044e
    if (!cpu.flags.zf)
    {
        goto L_0x0048044e;
    }
    // 0048043b  f7450cffff0700         +test dword ptr [ebp + 0xc], 0x7ffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) & 524287 /*0x7ffff*/));
    // 00480442  7505                   -jne 0x480449
    if (!cpu.flags.zf)
    {
        goto L_0x00480449;
    }
    // 00480444  395508                 +cmp dword ptr [ebp + 8], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480447  7405                   -je 0x48044e
    if (cpu.flags.zf)
    {
        goto L_0x0048044e;
    }
L_0x00480449:
    // 00480449  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
L_0x0048044b:
    // 0048044b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048044c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048044d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048044e:
    // 0048044e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480450  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480451  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480452(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480452  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480453  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480455  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480456  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480457  dd4508                 +fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0048045a  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 00480460  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480461  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00480463  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00480464  750c                   -jne 0x480472
    if (!cpu.flags.zf)
    {
        goto L_0x00480472;
    }
    // 00480466  d9ee                   -fldz 
    cpu.fpu.push(0.0);
    // 00480468  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0048046a  dd5df8                 +fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048046d  e996000000             -jmp 0x480508
    goto L_0x00480508;
L_0x00480472:
    // 00480472  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480474  66f7450ef07f           +test word ptr [ebp + 0xe], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(14) /* 0xe */) & 32752 /*0x7ff0*/));
    // 0048047a  7565                   -jne 0x4804e1
    if (!cpu.flags.zf)
    {
        goto L_0x004804e1;
    }
    // 0048047c  f7450cffff0f00         +test dword ptr [ebp + 0xc], 0xfffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) & 1048575 /*0xfffff*/));
    // 00480483  7505                   -jne 0x48048a
    if (!cpu.flags.zf)
    {
        goto L_0x0048048a;
    }
    // 00480485  394d08                 +cmp dword ptr [ebp + 8], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480488  7457                   -je 0x4804e1
    if (cpu.flags.zf)
    {
        goto L_0x004804e1;
    }
L_0x0048048a:
    // 0048048a  dd4508                 +fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0048048d  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 00480493  be03fcffff             -mov esi, 0xfffffc03
    cpu.esi = 4294966275 /*0xfffffc03*/;
    // 00480498  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048049a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0048049b  7305                   -jae 0x4804a2
    if (!cpu.flags.cf)
    {
        goto L_0x004804a2;
    }
    // 0048049d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048049f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004804a0  eb02                   -jmp 0x4804a4
    goto L_0x004804a4;
L_0x004804a2:
    // 004804a2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004804a4:
    // 004804a4  f6450e10               +test byte ptr [ebp + 0xe], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(14) /* 0xe */) & 16 /*0x10*/));
    // 004804a8  7513                   -jne 0x4804bd
    if (!cpu.flags.zf)
    {
        goto L_0x004804bd;
    }
    // 004804aa  d1650c                 -shl dword ptr [ebp + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) <<= 1 /*0x1*/ % 32;
    // 004804ad  f6450b80               +test byte ptr [ebp + 0xb], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) & 128 /*0x80*/));
    // 004804b1  7404                   -je 0x4804b7
    if (cpu.flags.zf)
    {
        goto L_0x004804b7;
    }
    // 004804b3  834d0c01               -or dword ptr [ebp + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004804b7:
    // 004804b7  d16508                 +shl dword ptr [ebp + 8], 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */));
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004804ba  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004804bb  ebe7                   -jmp 0x4804a4
    goto L_0x004804a4;
L_0x004804bd:
    // 004804bd  6681650eefff           -and word ptr [ebp + 0xe], 0xffef
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(14) /* 0xe */) &= x86::reg16(x86::sreg16(65519 /*0xffef*/));
    // 004804c3  3bc1                   +cmp eax, ecx
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
    // 004804c5  7404                   -je 0x4804cb
    if (cpu.flags.zf)
    {
        goto L_0x004804cb;
    }
    // 004804c7  804d0f80               -or byte ptr [ebp + 0xf], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004804cb:
    // 004804cb  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004804ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804d1  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004804d4  e8f6feffff             -call 0x4803cf
    cpu.esp -= 4;
    sub_4803cf(app, cpu);
    // 004804d9  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004804dc  83c40c                 +add esp, 0xc
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
    // 004804df  eb27                   -jmp 0x480508
    goto L_0x00480508;
L_0x004804e1:
    // 004804e1  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004804e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804e7  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004804ea  e8e0feffff             -call 0x4803cf
    cpu.esp -= 4;
    sub_4803cf(app, cpu);
    // 004804ef  8b450e                 -mov eax, dword ptr [ebp + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 004804f2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004804f5  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004804f8  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004804fb  6625ff07               -and ax, 0x7ff
    cpu.ax &= x86::reg16(x86::sreg16(2047 /*0x7ff*/));
    // 004804ff  0fbff0                 -movsx esi, ax
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00480502  81eefe030000           -sub esi, 0x3fe
    (cpu.esi) -= x86::reg32(x86::sreg32(1022 /*0x3fe*/));
L_0x00480508:
    // 00480508  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048050b  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0048050e  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00480510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480511  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480512  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480513(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480513  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480514  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480516  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480517  9b                     -wait 
    /*nothing*/;
    // 00480518  dd7dfe                 -fnstsw word ptr [ebp - 2]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.fpu.status.word;
    // 0048051b  0fbf45fe               -movsx eax, word ptr [ebp - 2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */)));
    // 0048051f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480520  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480521(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480521  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480522  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480524  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480525  dd7dfe                 -fnstsw word ptr [ebp - 2]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.fpu.status.word;
    // 00480528  dbe2                   -fnclex 
    /*nothing*/;
    // 0048052a  0fbf45fe               -movsx eax, word ptr [ebp - 2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */)));
    // 0048052e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048052f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480530  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480531  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480533  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480534  9b                     -wait 
    /*nothing*/;
    // 00480535  d97dfc                 -fnstcw word ptr [ebp - 4]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.control.word;
    // 00480538  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048053b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048053d  234508                 -and eax, dword ptr [ebp + 8]
    cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00480540  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00480542  234dfc                 -and ecx, dword ptr [ebp - 4]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00480545  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00480547  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048054a  d96d0c                 -fldcw word ptr [ebp + 0xc]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048054d  0fbf45fc               -movsx eax, word ptr [ebp - 4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00480551  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480553(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480553  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480554  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480556  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480557  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480558  8a4d08                 -mov cl, byte ptr [ebp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048055b  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0048055e  740a                   -je 0x48056a
    if (cpu.flags.zf)
    {
        goto L_0x0048056a;
    }
    // 00480560  db2d90674a00           -fld xword ptr [0x4a6790]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(4876176) /* 0x4a6790 */)));
    // 00480566  db5d08                 -fistp dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00480569  9b                     -wait 
    /*nothing*/;
L_0x0048056a:
    // 0048056a  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0048056d  7410                   -je 0x48057f
    if (cpu.flags.zf)
    {
        goto L_0x0048057f;
    }
    // 0048056f  9b                     -wait 
    /*nothing*/;
    // 00480570  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00480572  db2d90674a00           -fld xword ptr [0x4a6790]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(4876176) /* 0x4a6790 */)));
    // 00480578  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048057b  9b                     -wait 
    /*nothing*/;
    // 0048057c  9b                     -wait 
    /*nothing*/;
    // 0048057d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
L_0x0048057f:
    // 0048057f  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00480582  740a                   -je 0x48058e
    if (cpu.flags.zf)
    {
        goto L_0x0048058e;
    }
    // 00480584  db2d9c674a00           -fld xword ptr [0x4a679c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(4876188) /* 0x4a679c */)));
    // 0048058a  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048058d  9b                     -wait 
    /*nothing*/;
L_0x0048058e:
    // 0048058e  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00480591  7409                   -je 0x48059c
    if (cpu.flags.zf)
    {
        goto L_0x0048059c;
    }
    // 00480593  d9ee                   -fldz 
    cpu.fpu.push(0.0);
    // 00480595  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00480597  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00480599  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048059b  9b                     -wait 
    /*nothing*/;
L_0x0048059c:
    // 0048059c  f6c120                 +test cl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 32 /*0x20*/));
    // 0048059f  7406                   -je 0x4805a7
    if (cpu.flags.zf)
    {
        goto L_0x004805a7;
    }
    // 004805a1  d9eb                   -fldpi 
    cpu.fpu.push(3.1415926535897932);
    // 004805a3  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004805a6  9b                     -wait 
    /*nothing*/;
L_0x004805a7:
    // 004805a7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__mbsnbicoll(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004805a9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004805aa  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004805ac  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004805b0  7504                   -jne 0x4805b6
    if (!cpu.flags.zf)
    {
        goto L_0x004805b6;
    }
    // 004805b2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004805b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004805b6:
    // 004805b6  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 004805bc  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004805bf  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004805c2  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004805c5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004805c8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004805ca  ff35c41e5200           -push dword ptr [0x521ec4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */);
    cpu.esp -= 4;
    // 004805d0  e82cf4ffff             -call 0x47fa01
    cpu.esp -= 4;
    sub_47fa01(app, cpu);
    // 004805d5  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004805d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004805da  7507                   -jne 0x4805e3
    if (!cpu.flags.zf)
    {
        goto L_0x004805e3;
    }
    // 004805dc  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 004805e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004805e3:
    // 004805e3  83c0fe                 -add eax, -2
    (cpu.eax) += x86::reg32(x86::sreg32(-2 /*-0x2*/));
    // 004805e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4805e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004805e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004805e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004805ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004805eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004805ec  8b3510eb5100           -mov esi, dword ptr [0x51eb10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
    // 004805f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004805f3  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004805f5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004805f7  3bc7                   +cmp eax, edi
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
    // 004805f9  744e                   -je 0x480649
    if (cpu.flags.zf)
    {
        goto L_0x00480649;
    }
    // 004805fb  8b1da8714800           -mov ebx, dword ptr [0x4871a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
L_0x00480601:
    // 00480601  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480602  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480603  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480604  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480605  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00480607  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480608  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480609  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048060b  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048060d  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048060f  3bef                   +cmp ebp, edi
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
    // 00480611  743e                   -je 0x480651
    if (cpu.flags.zf)
    {
        goto L_0x00480651;
    }
    // 00480613  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480614  e8616cffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00480619  3bc7                   +cmp eax, edi
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
    // 0048061b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048061c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00480620  742f                   -je 0x480651
    if (cpu.flags.zf)
    {
        goto L_0x00480651;
    }
    // 00480622  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480623  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480624  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480626  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00480628  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0048062a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048062b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048062d  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048062f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480631  741e                   -je 0x480651
    if (cpu.flags.zf)
    {
        goto L_0x00480651;
    }
    // 00480633  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480634  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00480638  e8a9e9ffff             -call 0x47efe6
    cpu.esp -= 4;
    sub_47efe6(app, cpu);
    // 0048063d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00480640  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480643  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480644  3bc7                   +cmp eax, edi
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
    // 00480646  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480647  75b8                   -jne 0x480601
    if (!cpu.flags.zf)
    {
        goto L_0x00480601;
    }
L_0x00480649:
    // 00480649  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048064b:
    // 0048064b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048064c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048064d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048064e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048064f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480650  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480651:
    // 00480651  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00480654  ebf5                   -jmp 0x48064b
    goto L_0x0048064b;
}

/* align: skip  */
void Application::sub_480656(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480656  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480657  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480659  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048065a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048065b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048065c  e806aeffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00480661  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480663  ff7650                 -push dword ptr [esi + 0x50]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    // 00480666  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00480669  e826010000             -call 0x480794
    cpu.esp -= 4;
    sub_480794(app, cpu);
    // 0048066e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048066f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480671  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480672  0f840f010000           -je 0x480787
    if (cpu.flags.zf)
    {
        goto L_0x00480787;
    }
    // 00480678  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048067b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048067d  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00480680  0f8401010000           -je 0x480787
    if (cpu.flags.zf)
    {
        goto L_0x00480787;
    }
    // 00480686  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480689  750c                   -jne 0x480697
    if (!cpu.flags.zf)
    {
        goto L_0x00480697;
    }
    // 0048068b  83600800               +and dword ptr [eax + 8], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0048068f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00480691  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480692  e9f9000000             -jmp 0x480790
    goto L_0x00480790;
L_0x00480697:
    // 00480697  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048069a  0f84e2000000           -je 0x480782
    if (cpu.flags.zf)
    {
        goto L_0x00480782;
    }
    // 004806a0  8b4e54                 -mov ecx, dword ptr [esi + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004806a3  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004806a6  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004806a9  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 004806ac  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004806af  83f908                 +cmp ecx, 8
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
    // 004806b2  0f85bc000000           -jne 0x480774
    if (!cpu.flags.zf)
    {
        goto L_0x00480774;
    }
    // 004806b8  8b1520684a00           -mov edx, dword ptr [0x4a6820]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4876320) /* 0x4a6820 */);
    // 004806be  8b0d24684a00           -mov ecx, dword ptr [0x4a6824]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876324) /* 0x4a6824 */);
    // 004806c4  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004806c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004806c7  3bd1                   +cmp edx, ecx
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
    // 004806c9  7d27                   -jge 0x4806f2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004806f2;
    }
    // 004806cb  8d0c52                 -lea ecx, [edx + edx*2]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 2);
    // 004806ce  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
L_0x004806d1:
    // 004806d1  8b7e50                 -mov edi, dword ptr [esi + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004806d4  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004806d7  836439fc00             -and dword ptr [ecx + edi - 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004806dc  8b3d20684a00           -mov edi, dword ptr [0x4a6820]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4876320) /* 0x4a6820 */);
    // 004806e2  8b1d24684a00           -mov ebx, dword ptr [0x4a6824]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4876324) /* 0x4a6824 */);
    // 004806e8  42                     -inc edx
    (cpu.edx)++;
    // 004806e9  03df                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004806eb  3bd3                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004806ed  7ce2                   -jl 0x4806d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004806d1;
    }
    // 004806ef  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x004806f2:
    // 004806f2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004806f4  8b7e58                 -mov edi, dword ptr [esi + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004806f7  3d8e0000c0             +cmp eax, 0xc000008e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225614 /*0xc000008e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004806fc  7509                   -jne 0x480707
    if (!cpu.flags.zf)
    {
        goto L_0x00480707;
    }
    // 004806fe  c7465883000000         -mov dword ptr [esi + 0x58], 0x83
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 131 /*0x83*/;
    // 00480705  eb5e                   -jmp 0x480765
    goto L_0x00480765;
L_0x00480707:
    // 00480707  3d900000c0             +cmp eax, 0xc0000090
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225616 /*0xc0000090*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048070c  7509                   -jne 0x480717
    if (!cpu.flags.zf)
    {
        goto L_0x00480717;
    }
    // 0048070e  c7465881000000         -mov dword ptr [esi + 0x58], 0x81
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 129 /*0x81*/;
    // 00480715  eb4e                   -jmp 0x480765
    goto L_0x00480765;
L_0x00480717:
    // 00480717  3d910000c0             +cmp eax, 0xc0000091
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225617 /*0xc0000091*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048071c  7509                   -jne 0x480727
    if (!cpu.flags.zf)
    {
        goto L_0x00480727;
    }
    // 0048071e  c7465884000000         -mov dword ptr [esi + 0x58], 0x84
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 132 /*0x84*/;
    // 00480725  eb3e                   -jmp 0x480765
    goto L_0x00480765;
L_0x00480727:
    // 00480727  3d930000c0             +cmp eax, 0xc0000093
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225619 /*0xc0000093*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048072c  7509                   -jne 0x480737
    if (!cpu.flags.zf)
    {
        goto L_0x00480737;
    }
    // 0048072e  c7465885000000         -mov dword ptr [esi + 0x58], 0x85
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 133 /*0x85*/;
    // 00480735  eb2e                   -jmp 0x480765
    goto L_0x00480765;
L_0x00480737:
    // 00480737  3d8d0000c0             +cmp eax, 0xc000008d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225613 /*0xc000008d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048073c  7509                   -jne 0x480747
    if (!cpu.flags.zf)
    {
        goto L_0x00480747;
    }
    // 0048073e  c7465882000000         -mov dword ptr [esi + 0x58], 0x82
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 130 /*0x82*/;
    // 00480745  eb1e                   -jmp 0x480765
    goto L_0x00480765;
L_0x00480747:
    // 00480747  3d8f0000c0             +cmp eax, 0xc000008f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225615 /*0xc000008f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048074c  7509                   -jne 0x480757
    if (!cpu.flags.zf)
    {
        goto L_0x00480757;
    }
    // 0048074e  c7465886000000         -mov dword ptr [esi + 0x58], 0x86
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 134 /*0x86*/;
    // 00480755  eb0e                   -jmp 0x480765
    goto L_0x00480765;
L_0x00480757:
    // 00480757  3d920000c0             +cmp eax, 0xc0000092
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225618 /*0xc0000092*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048075c  7507                   -jne 0x480765
    if (!cpu.flags.zf)
    {
        goto L_0x00480765;
    }
    // 0048075e  c746588a000000         -mov dword ptr [esi + 0x58], 0x8a
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 138 /*0x8a*/;
L_0x00480765:
    // 00480765  ff7658                 -push dword ptr [esi + 0x58]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    // 00480768  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0048076a  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048076c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048076d  897e58                 -mov dword ptr [esi + 0x58], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.edi;
    // 00480770  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480771  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480772  eb08                   -jmp 0x48077c
    goto L_0x0048077c;
L_0x00480774:
    // 00480774  83600800               -and dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00480778  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480779  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048077b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048077c:
    // 0048077c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048077f  894654                 -mov dword ptr [esi + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.eax;
L_0x00480782:
    // 00480782  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00480785  eb09                   -jmp 0x480790
    goto L_0x00480790;
L_0x00480787:
    // 00480787  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048078a  ff152c714800           -call dword ptr [0x48712c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747564) /* 0x48712c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00480790:
    // 00480790  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480791  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480792  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480793  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480794(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480794  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480798  8b0d2c684a00           -mov ecx, dword ptr [0x4a682c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876332) /* 0x4a682c */);
    // 0048079e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048079f  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004807a3  3932                   +cmp dword ptr [edx], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004807a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004807a6  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004807a8  7411                   -je 0x4807bb
    if (cpu.flags.zf)
    {
        goto L_0x004807bb;
    }
    // 004807aa  8d3c49                 -lea edi, [ecx + ecx*2]
    cpu.edi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 004807ad  8d3cba                 -lea edi, [edx + edi*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.edi * 4);
L_0x004807b0:
    // 004807b0  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004807b3  3bc7                   +cmp eax, edi
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
    // 004807b5  7304                   -jae 0x4807bb
    if (!cpu.flags.cf)
    {
        goto L_0x004807bb;
    }
    // 004807b7  3930                   +cmp dword ptr [eax], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004807b9  75f5                   -jne 0x4807b0
    if (!cpu.flags.zf)
    {
        goto L_0x004807b0;
    }
L_0x004807bb:
    // 004807bb  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 004807be  8d0c8a                 -lea ecx, [edx + ecx*4]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ecx * 4);
    // 004807c1  3bc1                   +cmp eax, ecx
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
    // 004807c3  7304                   -jae 0x4807c9
    if (!cpu.flags.cf)
    {
        goto L_0x004807c9;
    }
    // 004807c5  3930                   +cmp dword ptr [eax], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004807c7  7402                   -je 0x4807cb
    if (cpu.flags.zf)
    {
        goto L_0x004807cb;
    }
L_0x004807c9:
    // 004807c9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004807cb:
    // 004807cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4807ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004807ce  833d1820520000         +cmp dword ptr [0x522018], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382168) /* 0x522018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004807d5  7505                   -jne 0x4807dc
    if (!cpu.flags.zf)
    {
        goto L_0x004807dc;
    }
    // 004807d7  e82f390000             -call 0x48410b
    cpu.esp -= 4;
    sub_48410b(app, cpu);
L_0x004807dc:
    // 004807dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004807dd  8b3510205200           -mov esi, dword ptr [0x522010]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5382160) /* 0x522010 */);
    // 004807e3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004807e5  3c22                   +cmp al, 0x22
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004807e7  7525                   -jne 0x48080e
    if (!cpu.flags.zf)
    {
        goto L_0x0048080e;
    }
L_0x004807e9:
    // 004807e9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004807ec  46                     -inc esi
    (cpu.esi)++;
    // 004807ed  3c22                   +cmp al, 0x22
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004807ef  7415                   -je 0x480806
    if (cpu.flags.zf)
    {
        goto L_0x00480806;
    }
    // 004807f1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004807f3  7411                   -je 0x480806
    if (cpu.flags.zf)
    {
        goto L_0x00480806;
    }
    // 004807f5  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 004807f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004807f9  e829390000             -call 0x484127
    cpu.esp -= 4;
    sub_484127(app, cpu);
    // 004807fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480800  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480801  74e6                   -je 0x4807e9
    if (cpu.flags.zf)
    {
        goto L_0x004807e9;
    }
    // 00480803  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480804  ebe3                   -jmp 0x4807e9
    goto L_0x004807e9;
L_0x00480806:
    // 00480806  803e22                 +cmp byte ptr [esi], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480809  750d                   -jne 0x480818
    if (!cpu.flags.zf)
    {
        goto L_0x00480818;
    }
L_0x0048080b:
    // 0048080b  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048080c  eb0a                   -jmp 0x480818
    goto L_0x00480818;
L_0x0048080e:
    // 0048080e  3c20                   +cmp al, 0x20
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
    // 00480810  7606                   -jbe 0x480818
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480818;
    }
L_0x00480812:
    // 00480812  46                     -inc esi
    (cpu.esi)++;
    // 00480813  803e20                 +cmp byte ptr [esi], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480816  77fa                   -ja 0x480812
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00480812;
    }
L_0x00480818:
    // 00480818  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048081a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048081c  7404                   -je 0x480822
    if (cpu.flags.zf)
    {
        goto L_0x00480822;
    }
    // 0048081e  3c20                   +cmp al, 0x20
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
    // 00480820  76e9                   -jbe 0x48080b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048080b;
    }
L_0x00480822:
    // 00480822  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480824  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480825  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480826(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480826  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480827  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480829  391d18205200           +cmp dword ptr [0x522018], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382168) /* 0x522018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048082f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480830  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480831  7505                   -jne 0x480838
    if (!cpu.flags.zf)
    {
        goto L_0x00480838;
    }
    // 00480833  e8d3380000             -call 0x48410b
    cpu.esp -= 4;
    sub_48410b(app, cpu);
L_0x00480838:
    // 00480838  8b352ceb5100           -mov esi, dword ptr [0x51eb2c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    // 0048083e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00480840:
    // 00480840  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00480842  3ac3                   +cmp al, bl
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
    // 00480844  7412                   -je 0x480858
    if (cpu.flags.zf)
    {
        goto L_0x00480858;
    }
    // 00480846  3c3d                   +cmp al, 0x3d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480848  7401                   -je 0x48084b
    if (cpu.flags.zf)
    {
        goto L_0x0048084b;
    }
    // 0048084a  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0048084b:
    // 0048084b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048084c  e88fd5ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00480851  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480852  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00480856  ebe8                   -jmp 0x480840
    goto L_0x00480840;
L_0x00480858:
    // 00480858  8d04bd04000000         -lea eax, [edi*4 + 4]
    cpu.eax = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.edi * 4);
    // 0048085f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480860  e8156affff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00480865  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480867  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480868  3bf3                   +cmp esi, ebx
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
    // 0048086a  893508eb5100           -mov dword ptr [0x51eb08], esi
    app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */) = cpu.esi;
    // 00480870  7508                   -jne 0x48087a
    if (!cpu.flags.zf)
    {
        goto L_0x0048087a;
    }
    // 00480872  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00480874  e8c098ffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 00480879  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048087a:
    // 0048087a  8b3d2ceb5100           -mov edi, dword ptr [0x51eb2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    // 00480880  381f                   +cmp byte ptr [edi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480882  7439                   -je 0x4808bd
    if (cpu.flags.zf)
    {
        goto L_0x004808bd;
    }
    // 00480884  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00480885:
    // 00480885  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480886  e855d5ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0048088b  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048088d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048088e  45                     -inc ebp
    (cpu.ebp)++;
    // 0048088f  803f3d                 +cmp byte ptr [edi], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480892  7422                   -je 0x4808b6
    if (cpu.flags.zf)
    {
        goto L_0x004808b6;
    }
    // 00480894  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480895  e8e069ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0048089a  3bc3                   +cmp eax, ebx
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
    // 0048089c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048089d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0048089f  7508                   -jne 0x4808a9
    if (!cpu.flags.zf)
    {
        goto L_0x004808a9;
    }
    // 004808a1  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004808a3  e89198ffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 004808a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004808a9:
    // 004808a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004808aa  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 004808ac  e87fe9ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 004808b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808b2  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004808b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004808b6:
    // 004808b6  03fd                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004808b8  381f                   +cmp byte ptr [edi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004808ba  75c9                   -jne 0x480885
    if (!cpu.flags.zf)
    {
        goto L_0x00480885;
    }
    // 004808bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004808bd:
    // 004808bd  ff352ceb5100           -push dword ptr [0x51eb2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */);
    cpu.esp -= 4;
    // 004808c3  e8ec6affff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 004808c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808c9  891d2ceb5100           -mov dword ptr [0x51eb2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */) = cpu.ebx;
    // 004808cf  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004808d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808d3  c7051420520001000000   -mov dword ptr [0x522014], 1
    app->getMemory<x86::reg32>(x86::reg32(5382164) /* 0x522014 */) = 1 /*0x1*/;
    // 004808dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4808df(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004808df  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004808e0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004808e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004808e3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004808e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004808e5  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004808e7  391d18205200           +cmp dword ptr [0x522018], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382168) /* 0x522018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004808ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004808ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004808ef  7505                   -jne 0x4808f6
    if (!cpu.flags.zf)
    {
        goto L_0x004808f6;
    }
    // 004808f1  e815380000             -call 0x48410b
    cpu.esp -= 4;
    sub_48410b(app, cpu);
L_0x004808f6:
    // 004808f6  bee8eb5100             -mov esi, 0x51ebe8
    cpu.esi = 5368808 /*0x51ebe8*/;
    // 004808fb  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00480900  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480901  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480902  ff1568714800           -call dword ptr [0x487168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747624) /* 0x487168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480908  a110205200             -mov eax, dword ptr [0x522010]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382160) /* 0x522010 */);
    // 0048090d  893518eb5100           -mov dword ptr [0x51eb18], esi
    app->getMemory<x86::reg32>(x86::reg32(5368600) /* 0x51eb18 */) = cpu.esi;
    // 00480913  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00480915  3818                   +cmp byte ptr [eax], bl
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
    // 00480917  7402                   -je 0x48091b
    if (cpu.flags.zf)
    {
        goto L_0x0048091b;
    }
    // 00480919  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0048091b:
    // 0048091b  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048091e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048091f  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480922  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480923  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480924  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480925  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480926  e84d000000             -call 0x480978
    cpu.esp -= 4;
    sub_480978(app, cpu);
    // 0048092b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048092e  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480931  8d0488                 -lea eax, [eax + ecx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 00480934  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480935  e84069ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0048093a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048093c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048093f  3bf3                   +cmp esi, ebx
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
    // 00480941  7508                   -jne 0x48094b
    if (!cpu.flags.zf)
    {
        goto L_0x0048094b;
    }
    // 00480943  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00480945  e8ef97ffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 0048094a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048094b:
    // 0048094b  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048094e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048094f  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480952  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480953  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480956  8d0486                 -lea eax, [esi + eax*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.eax * 4);
    // 00480959  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048095a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048095b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048095c  e817000000             -call 0x480978
    cpu.esp -= 4;
    sub_480978(app, cpu);
    // 00480961  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480964  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00480967  48                     -dec eax
    (cpu.eax)--;
    // 00480968  893500eb5100           -mov dword ptr [0x51eb00], esi
    app->getMemory<x86::reg32>(x86::reg32(5368576) /* 0x51eb00 */) = cpu.esi;
    // 0048096e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048096f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480970  a3fcea5100             -mov dword ptr [0x51eafc], eax
    app->getMemory<x86::reg32>(x86::reg32(5368572) /* 0x51eafc */) = cpu.eax;
    // 00480975  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480976  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480977  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480978  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480979  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048097b  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0048097e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00480981  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480982  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480983  832100                 -and dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00480986  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00480989  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048098a  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048098d  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 00480993  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00480996  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480998  7408                   -je 0x4809a2
    if (cpu.flags.zf)
    {
        goto L_0x004809a2;
    }
    // 0048099a  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0048099c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048099f  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x004809a2:
    // 004809a2  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004809a5  7544                   -jne 0x4809eb
    if (!cpu.flags.zf)
    {
        goto L_0x004809eb;
    }
L_0x004809a7:
    // 004809a7  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004809aa  40                     -inc eax
    (cpu.eax)++;
    // 004809ab  80fa22                 +cmp dl, 0x22
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004809ae  7429                   -je 0x4809d9
    if (cpu.flags.zf)
    {
        goto L_0x004809d9;
    }
    // 004809b0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004809b2  7425                   -je 0x4809d9
    if (cpu.flags.zf)
    {
        goto L_0x004809d9;
    }
    // 004809b4  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 004809b7  f682c11d520004         +test byte ptr [edx + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 004809be  740c                   -je 0x4809cc
    if (cpu.flags.zf)
    {
        goto L_0x004809cc;
    }
    // 004809c0  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 004809c2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004809c4  7406                   -je 0x4809cc
    if (cpu.flags.zf)
    {
        goto L_0x004809cc;
    }
    // 004809c6  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004809c8  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004809ca  46                     -inc esi
    (cpu.esi)++;
    // 004809cb  40                     -inc eax
    (cpu.eax)++;
L_0x004809cc:
    // 004809cc  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 004809ce  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004809d0  74d5                   -je 0x4809a7
    if (cpu.flags.zf)
    {
        goto L_0x004809a7;
    }
    // 004809d2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004809d4  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004809d6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004809d7  ebce                   -jmp 0x4809a7
    goto L_0x004809a7;
L_0x004809d9:
    // 004809d9  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 004809db  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004809dd  7404                   -je 0x4809e3
    if (cpu.flags.zf)
    {
        goto L_0x004809e3;
    }
    // 004809df  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 004809e2  46                     -inc esi
    (cpu.esi)++;
L_0x004809e3:
    // 004809e3  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004809e6  7546                   -jne 0x480a2e
    if (!cpu.flags.zf)
    {
        goto L_0x00480a2e;
    }
    // 004809e8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004809e9  eb43                   -jmp 0x480a2e
    goto L_0x00480a2e;
L_0x004809eb:
    // 004809eb  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 004809ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004809ef  7405                   -je 0x4809f6
    if (cpu.flags.zf)
    {
        goto L_0x004809f6;
    }
    // 004809f1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004809f3  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004809f5  46                     -inc esi
    (cpu.esi)++;
L_0x004809f6:
    // 004809f6  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004809f8  40                     -inc eax
    (cpu.eax)++;
    // 004809f9  0fb6da                 -movzx ebx, dl
    cpu.ebx = x86::reg32(cpu.dl);
    // 004809fc  f683c11d520004         +test byte ptr [ebx + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00480a03  740c                   -je 0x480a11
    if (cpu.flags.zf)
    {
        goto L_0x00480a11;
    }
    // 00480a05  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 00480a07  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480a09  7405                   -je 0x480a10
    if (cpu.flags.zf)
    {
        goto L_0x00480a10;
    }
    // 00480a0b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00480a0d  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 00480a0f  46                     -inc esi
    (cpu.esi)++;
L_0x00480a10:
    // 00480a10  40                     -inc eax
    (cpu.eax)++;
L_0x00480a11:
    // 00480a11  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a14  7409                   -je 0x480a1f
    if (cpu.flags.zf)
    {
        goto L_0x00480a1f;
    }
    // 00480a16  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00480a18  7409                   -je 0x480a23
    if (cpu.flags.zf)
    {
        goto L_0x00480a23;
    }
    // 00480a1a  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a1d  75cc                   -jne 0x4809eb
    if (!cpu.flags.zf)
    {
        goto L_0x004809eb;
    }
L_0x00480a1f:
    // 00480a1f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00480a21  7503                   -jne 0x480a26
    if (!cpu.flags.zf)
    {
        goto L_0x00480a26;
    }
L_0x00480a23:
    // 00480a23  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480a24  eb08                   -jmp 0x480a2e
    goto L_0x00480a2e;
L_0x00480a26:
    // 00480a26  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480a28  7404                   -je 0x480a2e
    if (cpu.flags.zf)
    {
        goto L_0x00480a2e;
    }
    // 00480a2a  8066ff00               -and byte ptr [esi - 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x00480a2e:
    // 00480a2e  83651800               -and dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00480a32:
    // 00480a32  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a35  0f84e0000000           -je 0x480b1b
    if (cpu.flags.zf)
    {
        goto L_0x00480b1b;
    }
L_0x00480a3b:
    // 00480a3b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00480a3d  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a40  7405                   -je 0x480a47
    if (cpu.flags.zf)
    {
        goto L_0x00480a47;
    }
    // 00480a42  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a45  7503                   -jne 0x480a4a
    if (!cpu.flags.zf)
    {
        goto L_0x00480a4a;
    }
L_0x00480a47:
    // 00480a47  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480a48  ebf1                   -jmp 0x480a3b
    goto L_0x00480a3b;
L_0x00480a4a:
    // 00480a4a  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a4d  0f84c8000000           -je 0x480b1b
    if (cpu.flags.zf)
    {
        goto L_0x00480b1b;
    }
    // 00480a53  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480a55  7408                   -je 0x480a5f
    if (cpu.flags.zf)
    {
        goto L_0x00480a5f;
    }
    // 00480a57  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 00480a59  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480a5c  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00480a5f:
    // 00480a5f  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00480a62  ff02                   -inc dword ptr [edx]
    (app->getMemory<x86::reg32>(cpu.edx))++;
L_0x00480a64:
    // 00480a64  c7450801000000         -mov dword ptr [ebp + 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00480a6b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00480a6d:
    // 00480a6d  80385c                 +cmp byte ptr [eax], 0x5c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a70  7504                   -jne 0x480a76
    if (!cpu.flags.zf)
    {
        goto L_0x00480a76;
    }
    // 00480a72  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480a73  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480a74  ebf7                   -jmp 0x480a6d
    goto L_0x00480a6d;
L_0x00480a76:
    // 00480a76  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a79  752c                   -jne 0x480aa7
    if (!cpu.flags.zf)
    {
        goto L_0x00480aa7;
    }
    // 00480a7b  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00480a7e  7525                   -jne 0x480aa5
    if (!cpu.flags.zf)
    {
        goto L_0x00480aa5;
    }
    // 00480a80  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00480a82  397d18                 +cmp dword ptr [ebp + 0x18], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480a85  740d                   -je 0x480a94
    if (cpu.flags.zf)
    {
        goto L_0x00480a94;
    }
    // 00480a87  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480a8b  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00480a8e  7504                   -jne 0x480a94
    if (!cpu.flags.zf)
    {
        goto L_0x00480a94;
    }
    // 00480a90  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480a92  eb03                   -jmp 0x480a97
    goto L_0x00480a97;
L_0x00480a94:
    // 00480a94  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x00480a97:
    // 00480a97  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00480a9a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480a9c  395518                 +cmp dword ptr [ebp + 0x18], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480a9f  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 00480aa2  895518                 -mov dword ptr [ebp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x00480aa5:
    // 00480aa5  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
L_0x00480aa7:
    // 00480aa7  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00480aa9  4b                     -dec ebx
    (cpu.ebx)--;
    // 00480aaa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480aac  740e                   -je 0x480abc
    if (cpu.flags.zf)
    {
        goto L_0x00480abc;
    }
    // 00480aae  43                     -inc ebx
    (cpu.ebx)++;
L_0x00480aaf:
    // 00480aaf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480ab1  7404                   -je 0x480ab7
    if (cpu.flags.zf)
    {
        goto L_0x00480ab7;
    }
    // 00480ab3  c6065c                 -mov byte ptr [esi], 0x5c
    app->getMemory<x86::reg8>(cpu.esi) = 92 /*0x5c*/;
    // 00480ab6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00480ab7:
    // 00480ab7  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480ab9  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480aba  75f3                   -jne 0x480aaf
    if (!cpu.flags.zf)
    {
        goto L_0x00480aaf;
    }
L_0x00480abc:
    // 00480abc  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00480abe  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00480ac0  744a                   -je 0x480b0c
    if (cpu.flags.zf)
    {
        goto L_0x00480b0c;
    }
    // 00480ac2  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ac6  750a                   -jne 0x480ad2
    if (!cpu.flags.zf)
    {
        goto L_0x00480ad2;
    }
    // 00480ac8  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480acb  743f                   -je 0x480b0c
    if (cpu.flags.zf)
    {
        goto L_0x00480b0c;
    }
    // 00480acd  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480ad0  743a                   -je 0x480b0c
    if (cpu.flags.zf)
    {
        goto L_0x00480b0c;
    }
L_0x00480ad2:
    // 00480ad2  837d0800               +cmp dword ptr [ebp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ad6  742e                   -je 0x480b06
    if (cpu.flags.zf)
    {
        goto L_0x00480b06;
    }
    // 00480ad8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480ada  7419                   -je 0x480af5
    if (cpu.flags.zf)
    {
        goto L_0x00480af5;
    }
    // 00480adc  0fb6da                 -movzx ebx, dl
    cpu.ebx = x86::reg32(cpu.dl);
    // 00480adf  f683c11d520004         +test byte ptr [ebx + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00480ae6  7406                   -je 0x480aee
    if (cpu.flags.zf)
    {
        goto L_0x00480aee;
    }
    // 00480ae8  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00480aea  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480aeb  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480aec  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00480aee:
    // 00480aee  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00480af0  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00480af2  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480af3  eb0f                   -jmp 0x480b04
    goto L_0x00480b04;
L_0x00480af5:
    // 00480af5  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 00480af8  f682c11d520004         +test byte ptr [edx + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00480aff  7403                   -je 0x480b04
    if (cpu.flags.zf)
    {
        goto L_0x00480b04;
    }
    // 00480b01  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480b02  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00480b04:
    // 00480b04  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00480b06:
    // 00480b06  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480b07  e958ffffff             -jmp 0x480a64
    goto L_0x00480a64;
L_0x00480b0c:
    // 00480b0c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480b0e  7404                   -je 0x480b14
    if (cpu.flags.zf)
    {
        goto L_0x00480b14;
    }
    // 00480b10  802600                 +and byte ptr [esi], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00480b13  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00480b14:
    // 00480b14  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480b16  e917ffffff             -jmp 0x480a32
    goto L_0x00480a32;
L_0x00480b1b:
    // 00480b1b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480b1d  7403                   -je 0x480b22
    if (cpu.flags.zf)
    {
        goto L_0x00480b22;
    }
    // 00480b1f  832700                 -and dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00480b22:
    // 00480b22  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00480b25  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b27  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b28  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 00480b2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480b2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480b2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480b2e  a1ecec5100             -mov eax, dword ptr [0x51ecec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369068) /* 0x51ecec */);
    // 00480b33  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480b34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480b35  8b2d90714800           -mov ebp, dword ptr [0x487190]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747664) /* 0x487190 */);
    // 00480b3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480b3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480b3d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480b3f  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00480b41  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00480b43  3bc3                   +cmp eax, ebx
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
    // 00480b45  7533                   -jne 0x480b7a
    if (!cpu.flags.zf)
    {
        goto L_0x00480b7a;
    }
    // 00480b47  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480b49  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480b4b  3bf3                   +cmp esi, ebx
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
    // 00480b4d  740c                   -je 0x480b5b
    if (cpu.flags.zf)
    {
        goto L_0x00480b5b;
    }
    // 00480b4f  c705ecec510001000000   -mov dword ptr [0x51ecec], 1
    app->getMemory<x86::reg32>(x86::reg32(5369068) /* 0x51ecec */) = 1 /*0x1*/;
    // 00480b59  eb28                   -jmp 0x480b83
    goto L_0x00480b83;
L_0x00480b5b:
    // 00480b5b  ff1594714800           -call dword ptr [0x487194]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747668) /* 0x487194 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480b61  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00480b63  3bfb                   +cmp edi, ebx
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
    // 00480b65  0f84ea000000           -je 0x480c55
    if (cpu.flags.zf)
    {
        goto L_0x00480c55;
    }
    // 00480b6b  c705ecec510002000000   -mov dword ptr [0x51ecec], 2
    app->getMemory<x86::reg32>(x86::reg32(5369068) /* 0x51ecec */) = 2 /*0x2*/;
    // 00480b75  e98f000000             -jmp 0x480c09
    goto L_0x00480c09;
L_0x00480b7a:
    // 00480b7a  83f801                 +cmp eax, 1
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
    // 00480b7d  0f8581000000           -jne 0x480c04
    if (!cpu.flags.zf)
    {
        goto L_0x00480c04;
    }
L_0x00480b83:
    // 00480b83  3bf3                   +cmp esi, ebx
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
    // 00480b85  750c                   -jne 0x480b93
    if (!cpu.flags.zf)
    {
        goto L_0x00480b93;
    }
    // 00480b87  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480b89  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480b8b  3bf3                   +cmp esi, ebx
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
    // 00480b8d  0f84c2000000           -je 0x480c55
    if (cpu.flags.zf)
    {
        goto L_0x00480c55;
    }
L_0x00480b93:
    // 00480b93  66391e                 +cmp word ptr [esi], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00480b96  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480b98  740e                   -je 0x480ba8
    if (cpu.flags.zf)
    {
        goto L_0x00480ba8;
    }
L_0x00480b9a:
    // 00480b9a  40                     -inc eax
    (cpu.eax)++;
    // 00480b9b  40                     -inc eax
    (cpu.eax)++;
    // 00480b9c  663918                 +cmp word ptr [eax], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00480b9f  75f9                   -jne 0x480b9a
    if (!cpu.flags.zf)
    {
        goto L_0x00480b9a;
    }
    // 00480ba1  40                     -inc eax
    (cpu.eax)++;
    // 00480ba2  40                     -inc eax
    (cpu.eax)++;
    // 00480ba3  663918                 +cmp word ptr [eax], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00480ba6  75f2                   -jne 0x480b9a
    if (!cpu.flags.zf)
    {
        goto L_0x00480b9a;
    }
L_0x00480ba8:
    // 00480ba8  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00480baa  8b3da8714800           -mov edi, dword ptr [0x4871a8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    // 00480bb0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00480bb2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bb3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bb4  40                     -inc eax
    (cpu.eax)++;
    // 00480bb5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bb6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bb7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480bb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480bb9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bbb  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00480bbf  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480bc1  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00480bc3  3beb                   +cmp ebp, ebx
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
    // 00480bc5  7432                   -je 0x480bf9
    if (cpu.flags.zf)
    {
        goto L_0x00480bf9;
    }
    // 00480bc7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480bc8  e8ad66ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00480bcd  3bc3                   +cmp eax, ebx
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
    // 00480bcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bd0  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00480bd4  7423                   -je 0x480bf9
    if (cpu.flags.zf)
    {
        goto L_0x00480bf9;
    }
    // 00480bd6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bd7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bd8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480bd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480bda  ff742424               -push dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00480bde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480bdf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480be0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480be1  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480be3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480be5  750e                   -jne 0x480bf5
    if (!cpu.flags.zf)
    {
        goto L_0x00480bf5;
    }
    // 00480be7  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00480beb  e8c467ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00480bf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bf1  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x00480bf5:
    // 00480bf5  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00480bf9:
    // 00480bf9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480bfa  ff1598714800           -call dword ptr [0x487198]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747672) /* 0x487198 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480c00  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480c02  eb53                   -jmp 0x480c57
    goto L_0x00480c57;
L_0x00480c04:
    // 00480c04  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480c07  754c                   -jne 0x480c55
    if (!cpu.flags.zf)
    {
        goto L_0x00480c55;
    }
L_0x00480c09:
    // 00480c09  3bfb                   +cmp edi, ebx
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
    // 00480c0b  750c                   -jne 0x480c19
    if (!cpu.flags.zf)
    {
        goto L_0x00480c19;
    }
    // 00480c0d  ff1594714800           -call dword ptr [0x487194]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747668) /* 0x487194 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480c13  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00480c15  3bfb                   +cmp edi, ebx
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
    // 00480c17  743c                   -je 0x480c55
    if (cpu.flags.zf)
    {
        goto L_0x00480c55;
    }
L_0x00480c19:
    // 00480c19  381f                   +cmp byte ptr [edi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480c1b  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00480c1d  740a                   -je 0x480c29
    if (cpu.flags.zf)
    {
        goto L_0x00480c29;
    }
L_0x00480c1f:
    // 00480c1f  40                     -inc eax
    (cpu.eax)++;
    // 00480c20  3818                   +cmp byte ptr [eax], bl
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
    // 00480c22  75fb                   -jne 0x480c1f
    if (!cpu.flags.zf)
    {
        goto L_0x00480c1f;
    }
    // 00480c24  40                     -inc eax
    (cpu.eax)++;
    // 00480c25  3818                   +cmp byte ptr [eax], bl
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
    // 00480c27  75f6                   -jne 0x480c1f
    if (!cpu.flags.zf)
    {
        goto L_0x00480c1f;
    }
L_0x00480c29:
    // 00480c29  2bc7                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00480c2b  40                     -inc eax
    (cpu.eax)++;
    // 00480c2c  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00480c2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480c2f  e84666ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00480c34  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480c36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c37  3bf3                   +cmp esi, ebx
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
    // 00480c39  7504                   -jne 0x480c3f
    if (!cpu.flags.zf)
    {
        goto L_0x00480c3f;
    }
    // 00480c3b  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00480c3d  eb0b                   -jmp 0x480c4a
    goto L_0x00480c4a;
L_0x00480c3f:
    // 00480c3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480c40  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480c41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480c42  e8e9c0ffff             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 00480c47  83c40c                 +add esp, 0xc
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
L_0x00480c4a:
    // 00480c4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480c4b  ff15dc704800           -call dword ptr [0x4870dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747484) /* 0x4870dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480c51  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480c53  eb02                   -jmp 0x480c57
    goto L_0x00480c57;
L_0x00480c55:
    // 00480c55  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00480c57:
    // 00480c57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480c5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c5e  a134eb5100             -mov eax, dword ptr [0x51eb34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368628) /* 0x51eb34 */);
    // 00480c63  83f801                 +cmp eax, 1
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
    // 00480c66  740d                   -je 0x480c75
    if (cpu.flags.zf)
    {
        goto L_0x00480c75;
    }
    // 00480c68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c6a  752a                   -jne 0x480c96
    if (!cpu.flags.zf)
    {
        goto L_0x00480c96;
    }
    // 00480c6c  833db43f4a0001         +cmp dword ptr [0x4a3fb4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4865972) /* 0x4a3fb4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480c73  7521                   -jne 0x480c96
    if (!cpu.flags.zf)
    {
        goto L_0x00480c96;
    }
L_0x00480c75:
    // 00480c75  68fc000000             -push 0xfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 252 /*0xfc*/;
    cpu.esp -= 4;
    // 00480c7a  e818000000             -call 0x480c97
    cpu.esp -= 4;
    sub_480c97(app, cpu);
    // 00480c7f  a1f0ec5100             -mov eax, dword ptr [0x51ecf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369072) /* 0x51ecf0 */);
    // 00480c84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c87  7402                   -je 0x480c8b
    if (cpu.flags.zf)
    {
        goto L_0x00480c8b;
    }
    // 00480c89  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00480c8b:
    // 00480c8b  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00480c90  e802000000             -call 0x480c97
    cpu.esp -= 4;
    sub_480c97(app, cpu);
    // 00480c95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480c96:
    // 00480c96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480c97(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c97  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480c98  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480c9a  81eca4010000           -sub esp, 0x1a4
    (cpu.esp) -= x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 00480ca0  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00480ca3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480ca5  b830684a00             -mov eax, 0x4a6830
    cpu.eax = 4876336 /*0x4a6830*/;
L_0x00480caa:
    // 00480caa  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480cac  740b                   -je 0x480cb9
    if (cpu.flags.zf)
    {
        goto L_0x00480cb9;
    }
    // 00480cae  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00480cb1  41                     -inc ecx
    (cpu.ecx)++;
    // 00480cb2  3dc0684a00             +cmp eax, 0x4a68c0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4876480 /*0x4a68c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480cb7  7cf1                   -jl 0x480caa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480caa;
    }
L_0x00480cb9:
    // 00480cb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480cba  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00480cbc  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00480cbf  3b9630684a00           +cmp edx, dword ptr [esi + 0x4a6830]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4876336) /* 0x4a6830 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480cc5  0f851c010000           -jne 0x480de7
    if (!cpu.flags.zf)
    {
        goto L_0x00480de7;
    }
    // 00480ccb  a134eb5100             -mov eax, dword ptr [0x51eb34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368628) /* 0x51eb34 */);
    // 00480cd0  83f801                 +cmp eax, 1
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
    // 00480cd3  0f84e8000000           -je 0x480dc1
    if (cpu.flags.zf)
    {
        goto L_0x00480dc1;
    }
    // 00480cd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480cdb  750d                   -jne 0x480cea
    if (!cpu.flags.zf)
    {
        goto L_0x00480cea;
    }
    // 00480cdd  833db43f4a0001         +cmp dword ptr [0x4a3fb4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4865972) /* 0x4a3fb4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ce4  0f84d7000000           -je 0x480dc1
    if (cpu.flags.zf)
    {
        goto L_0x00480dc1;
    }
L_0x00480cea:
    // 00480cea  81fafc000000           +cmp edx, 0xfc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480cf0  0f84f1000000           -je 0x480de7
    if (cpu.flags.zf)
    {
        goto L_0x00480de7;
    }
    // 00480cf6  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00480cfc  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00480d01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480d02  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480d04  ff1568714800           -call dword ptr [0x487168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747624) /* 0x487168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480d0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480d0c  7513                   -jne 0x480d21
    if (!cpu.flags.zf)
    {
        goto L_0x00480d21;
    }
    // 00480d0e  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00480d14  6868854800             -push 0x488568
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752744 /*0x488568*/;
    cpu.esp -= 4;
    // 00480d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480d1a  e811e5ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00480d1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480d21:
    // 00480d21  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00480d27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480d28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480d29  8dbd5cfeffff           -lea edi, [ebp - 0x1a4]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00480d2f  e8acd0ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00480d34  40                     -inc eax
    (cpu.eax)++;
    // 00480d35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d36  83f83c                 +cmp eax, 0x3c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480d39  7629                   -jbe 0x480d64
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480d64;
    }
    // 00480d3b  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00480d41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480d42  e899d0ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00480d47  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00480d49  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00480d4f  83e83b                 -sub eax, 0x3b
    (cpu.eax) -= x86::reg32(x86::sreg32(59 /*0x3b*/));
    // 00480d52  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00480d54  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480d56  6864854800             -push 0x488564
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752740 /*0x488564*/;
    cpu.esp -= 4;
    // 00480d5b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480d5c  e85f70ffff             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 00480d61  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00480d64:
    // 00480d64  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00480d6a  6848854800             -push 0x488548
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752712 /*0x488548*/;
    cpu.esp -= 4;
    // 00480d6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480d70  e8bbe4ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00480d75  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00480d7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480d7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480d7d  e8bee4ffff             -call 0x47f240
    cpu.esp -= 4;
    sub_47f240(app, cpu);
    // 00480d82  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00480d88  680cba4900             -push 0x49ba0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4831756 /*0x49ba0c*/;
    cpu.esp -= 4;
    // 00480d8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480d8e  e8ade4ffff             -call 0x47f240
    cpu.esp -= 4;
    sub_47f240(app, cpu);
    // 00480d93  ffb634684a00           -push dword ptr [esi + 0x4a6834]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4876340) /* 0x4a6834 */);
    cpu.esp -= 4;
    // 00480d99  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00480d9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480da0  e89be4ffff             -call 0x47f240
    cpu.esp -= 4;
    sub_47f240(app, cpu);
    // 00480da5  6810200100             -push 0x12010
    app->getMemory<x86::reg32>(cpu.esp-4) = 73744 /*0x12010*/;
    cpu.esp -= 4;
    // 00480daa  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00480db0  6820854800             -push 0x488520
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752672 /*0x488520*/;
    cpu.esp -= 4;
    // 00480db5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480db6  e8ae330000             -call 0x484169
    cpu.esp -= 4;
    sub_484169(app, cpu);
    // 00480dbb  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480dbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480dbf  eb26                   -jmp 0x480de7
    goto L_0x00480de7;
L_0x00480dc1:
    // 00480dc1  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00480dc4  8db634684a00           -lea esi, [esi + 0x4a6834]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4876340) /* 0x4a6834 */);
    // 00480dca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480dcc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480dcd  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00480dcf  e80cd0ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00480dd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480dd5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480dd6  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00480dd8  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 00480dda  ff1540714800           -call dword ptr [0x487140]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747584) /* 0x487140 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480de0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480de1  ff156c714800           -call dword ptr [0x48716c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747628) /* 0x48716c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00480de7:
    // 00480de7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480de8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480de9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480dea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480dea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480deb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480ded  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480dee  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00480df1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480df2  bf20059319             -mov edi, 0x19930520
    cpu.edi = 429065504 /*0x19930520*/;
    // 00480df7  393e                   +cmp dword ptr [esi], edi
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
    // 00480df9  7405                   -je 0x480e00
    if (cpu.flags.zf)
    {
        goto L_0x00480e00;
    }
    // 00480dfb  e8bd080000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x00480e00:
    // 00480e00  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00480e03  f6400466               +test byte ptr [eax + 4], 0x66
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 102 /*0x66*/));
    // 00480e07  741f                   -je 0x480e28
    if (cpu.flags.zf)
    {
        goto L_0x00480e28;
    }
    // 00480e09  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e0d  746f                   -je 0x480e7e
    if (cpu.flags.zf)
    {
        goto L_0x00480e7e;
    }
    // 00480e0f  837d1c00               +cmp dword ptr [ebp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e13  7569                   -jne 0x480e7e
    if (!cpu.flags.zf)
    {
        goto L_0x00480e7e;
    }
    // 00480e15  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00480e17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480e18  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00480e1b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00480e1e  e81c030000             -call 0x48113f
    cpu.esp -= 4;
    sub_48113f(app, cpu);
    // 00480e23  83c410                 +add esp, 0x10
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
    // 00480e26  eb56                   -jmp 0x480e7e
    goto L_0x00480e7e;
L_0x00480e28:
    // 00480e28  837e0c00               +cmp dword ptr [esi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e2c  7450                   -je 0x480e7e
    if (cpu.flags.zf)
    {
        goto L_0x00480e7e;
    }
    // 00480e2e  813863736de0           +cmp dword ptr [eax], 0xe06d7363
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3765269347 /*0xe06d7363*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e34  752c                   -jne 0x480e62
    if (!cpu.flags.zf)
    {
        goto L_0x00480e62;
    }
    // 00480e36  397814                 +cmp dword ptr [eax + 0x14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e39  7627                   -jbe 0x480e62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480e62;
    }
    // 00480e3b  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00480e3e  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00480e41  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480e43  741d                   -je 0x480e62
    if (cpu.flags.zf)
    {
        goto L_0x00480e62;
    }
    // 00480e45  0fb65524               -movzx edx, byte ptr [ebp + 0x24]
    cpu.edx = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(36) /* 0x24 */));
    // 00480e49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480e4a  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00480e4d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00480e50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480e51  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00480e54  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00480e57  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00480e5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480e5b  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00480e5d  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480e60  eb1f                   -jmp 0x480e81
    goto L_0x00480e81;
L_0x00480e62:
    // 00480e62  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00480e65  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00480e68  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00480e6b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480e6c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00480e6f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00480e72  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00480e75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480e76  e80a000000             -call 0x480e85
    cpu.esp -= 4;
    sub_480e85(app, cpu);
    // 00480e7b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00480e7e:
    // 00480e7e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00480e80  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480e81:
    // 00480e81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480e85(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480e85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480e86  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480e88  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00480e8b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00480e8e  8065ec00               -and byte ptr [ebp - 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00480e92  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480e95  83f8ff                 +cmp eax, -1
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
    // 00480e98  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00480e9b  7c08                   -jl 0x480ea5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480ea5;
    }
    // 00480e9d  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00480ea0  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ea3  7c05                   -jl 0x480eaa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480eaa;
    }
L_0x00480ea5:
    // 00480ea5  e813080000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x00480eaa:
    // 00480eaa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480eab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480eac  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00480eaf  bb63736de0             -mov ebx, 0xe06d7363
    cpu.ebx = 3765269347 /*0xe06d7363*/;
    // 00480eb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480eb5  bf20059319             -mov edi, 0x19930520
    cpu.edi = 429065504 /*0x19930520*/;
    // 00480eba  391e                   +cmp dword ptr [esi], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ebc  0f854b010000           -jne 0x48100d
    if (!cpu.flags.zf)
    {
        goto L_0x0048100d;
    }
    // 00480ec2  837e1003               +cmp dword ptr [esi + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ec6  7562                   -jne 0x480f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00480f2a;
    }
    // 00480ec8  397e14                 +cmp dword ptr [esi + 0x14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ecb  755d                   -jne 0x480f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00480f2a;
    }
    // 00480ecd  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ed1  7557                   -jne 0x480f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00480f2a;
    }
    // 00480ed3  e88fa5ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00480ed8  83786c00               +cmp dword ptr [eax + 0x6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480edc  0f8426010000           -je 0x481008
    if (cpu.flags.zf)
    {
        goto L_0x00481008;
    }
    // 00480ee2  e880a5ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00480ee7  8b706c                 -mov esi, dword ptr [eax + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 00480eea  e878a5ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00480eef  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00480ef2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00480ef4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480ef5  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00480ef8  c645ec01               -mov byte ptr [ebp - 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 1 /*0x1*/;
    // 00480efc  e855330000             -call 0x484256
    cpu.esp -= 4;
    sub_484256(app, cpu);
    // 00480f01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f05  7505                   -jne 0x480f0c
    if (!cpu.flags.zf)
    {
        goto L_0x00480f0c;
    }
    // 00480f07  e8b1070000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x00480f0c:
    // 00480f0c  391e                   +cmp dword ptr [esi], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f0e  0f85f9000000           -jne 0x48100d
    if (!cpu.flags.zf)
    {
        goto L_0x0048100d;
    }
    // 00480f14  837e1003               +cmp dword ptr [esi + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f18  7510                   -jne 0x480f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00480f2a;
    }
    // 00480f1a  397e14                 +cmp dword ptr [esi + 0x14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f1d  750b                   -jne 0x480f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00480f2a;
    }
    // 00480f1f  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f23  7505                   -jne 0x480f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00480f2a;
    }
    // 00480f25  e893070000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x00480f2a:
    // 00480f2a  391e                   +cmp dword ptr [esi], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f2c  0f85db000000           -jne 0x48100d
    if (!cpu.flags.zf)
    {
        goto L_0x0048100d;
    }
    // 00480f32  837e1003               +cmp dword ptr [esi + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f36  0f85d1000000           -jne 0x48100d
    if (!cpu.flags.zf)
    {
        goto L_0x0048100d;
    }
    // 00480f3c  397e14                 +cmp dword ptr [esi + 0x14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f3f  0f85c8000000           -jne 0x48100d
    if (!cpu.flags.zf)
    {
        goto L_0x0048100d;
    }
    // 00480f45  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00480f48  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00480f4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480f4c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480f4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480f50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480f51  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00480f54  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00480f57  e89194ffff             -call 0x47a3ed
    cpu.esp -= 4;
    sub_47a3ed(app, cpu);
    // 00480f5c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00480f5f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00480f61:
    // 00480f61  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480f64  3b45e8                 +cmp eax, dword ptr [ebp - 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f67  0f838b000000           -jae 0x480ff8
    if (!cpu.flags.cf)
    {
        goto L_0x00480ff8;
    }
    // 00480f6d  393b                   +cmp dword ptr [ebx], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f6f  7f7c                   -jg 0x480fed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00480fed;
    }
    // 00480f71  3b7b04                 +cmp edi, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f74  7f77                   -jg 0x480fed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00480fed;
    }
    // 00480f76  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00480f79  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00480f7c  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00480f7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f81  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00480f84  7e64                   -jle 0x480fea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00480fea;
    }
L_0x00480f86:
    // 00480f86  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00480f89  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00480f8c  8d7804                 -lea edi, [eax + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00480f8f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00480f91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f93  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00480f96  7e1f                   -jle 0x480fb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00480fb7;
    }
L_0x00480f98:
    // 00480f98  ff761c                 -push dword ptr [esi + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00480f9b  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 00480f9d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00480fa0  e83d010000             -call 0x4810e2
    cpu.esp -= 4;
    sub_4810e2(app, cpu);
    // 00480fa5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480fa8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480faa  751a                   -jne 0x480fc6
    if (!cpu.flags.zf)
    {
        goto L_0x00480fc6;
    }
    // 00480fac  ff4df8                 -dec dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))--;
    // 00480faf  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480fb2  3945f8                 +cmp dword ptr [ebp - 8], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480fb5  7fe1                   -jg 0x480f98
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00480f98;
    }
L_0x00480fb7:
    // 00480fb7  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00480fba  83450810               -add dword ptr [ebp + 8], 0x10
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00480fbe  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480fc2  7fc2                   -jg 0x480f86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00480f86;
    }
    // 00480fc4  eb24                   -jmp 0x480fea
    goto L_0x00480fea;
L_0x00480fc6:
    // 00480fc6  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00480fc9  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00480fcc  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00480fcf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480fd0  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 00480fd2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00480fd5  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00480fd8  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00480fdb  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00480fde  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00480fe1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480fe2  e80c020000             -call 0x4811f3
    cpu.esp -= 4;
    sub_4811f3(app, cpu);
    // 00480fe7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
L_0x00480fea:
    // 00480fea  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
L_0x00480fed:
    // 00480fed  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00480ff0  83c314                 +add ebx, 0x14
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480ff3  e969ffffff             -jmp 0x480f61
    goto L_0x00480f61;
L_0x00480ff8:
    // 00480ff8  807d1c00               +cmp byte ptr [ebp + 0x1c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480ffc  740a                   -je 0x481008
    if (cpu.flags.zf)
    {
        goto L_0x00481008;
    }
    // 00480ffe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481000  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481001  e871050000             -call 0x481577
    cpu.esp -= 4;
    sub_481577(app, cpu);
    // 00481006  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481007  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00481008:
    // 00481008  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481009  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048100a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048100b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048100c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048100d:
    // 0048100d  807d1c00               +cmp byte ptr [ebp + 0x1c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00481011  7520                   -jne 0x481033
    if (!cpu.flags.zf)
    {
        goto L_0x00481033;
    }
    // 00481013  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00481016  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00481019  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0048101c  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0048101f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00481022  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00481025  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00481028  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481029  e80a000000             -call 0x481038
    cpu.esp -= 4;
    sub_481038(app, cpu);
    // 0048102e  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00481031  ebd5                   -jmp 0x481008
    goto L_0x00481008;
L_0x00481033:
    // 00481033  e924060000             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::sub_481038(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481038  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481039  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048103b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048103c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048103d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048103e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048103f  e823a4ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00481044  83786800               +cmp dword ptr [eax + 0x68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481048  7421                   -je 0x48106b
    if (cpu.flags.zf)
    {
        goto L_0x0048106b;
    }
    // 0048104a  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 0048104d  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00481050  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481053  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00481056  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00481059  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048105c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048105f  e85e92ffff             -call 0x47a2c2
    cpu.esp -= 4;
    sub_47a2c2(app, cpu);
    // 00481064  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00481067  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481069  7573                   -jne 0x4810de
    if (!cpu.flags.zf)
    {
        goto L_0x004810de;
    }
L_0x0048106b:
    // 0048106b  8b7d1c                 -mov edi, dword ptr [ebp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048106e  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00481071  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481072  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00481075  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481076  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481077  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0048107a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0048107d  e86b93ffff             -call 0x47a3ed
    cpu.esp -= 4;
    sub_47a3ed(app, cpu);
    // 00481082  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481085  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00481087:
    // 00481087  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048108a  3b45f8                 +cmp eax, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048108d  734f                   -jae 0x4810de
    if (!cpu.flags.cf)
    {
        goto L_0x004810de;
    }
    // 0048108f  3b3e                   +cmp edi, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481091  7c43                   -jl 0x4810d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004810d6;
    }
    // 00481093  3b7e04                 +cmp edi, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481096  7f3e                   -jg 0x4810d6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004810d6;
    }
    // 00481098  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048109b  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048109e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004810a1  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004810a3  8b48f4                 -mov ecx, dword ptr [eax - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-12) /* -0xc */);
    // 004810a6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004810a8  7406                   -je 0x4810b0
    if (cpu.flags.zf)
    {
        goto L_0x004810b0;
    }
    // 004810aa  80790800               +cmp byte ptr [ecx + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004810ae  7526                   -jne 0x4810d6
    if (!cpu.flags.zf)
    {
        goto L_0x004810d6;
    }
L_0x004810b0:
    // 004810b0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004810b2  83c0f0                 -add eax, -0x10
    (cpu.eax) += x86::reg32(x86::sreg32(-16 /*-0x10*/));
    // 004810b5  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 004810b8  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004810bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004810bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004810be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004810bf  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004810c2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004810c5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004810c8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004810cb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004810ce  e820010000             -call 0x4811f3
    cpu.esp -= 4;
    sub_4811f3(app, cpu);
    // 004810d3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
L_0x004810d6:
    // 004810d6  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 004810d9  83c614                 +add esi, 0x14
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004810dc  eba9                   -jmp 0x481087
    goto L_0x00481087;
L_0x004810de:
    // 004810de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810e0  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4810e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004810e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004810e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004810e4  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004810e8  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004810eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004810ed  744a                   -je 0x481139
    if (cpu.flags.zf)
    {
        goto L_0x00481139;
    }
    // 004810ef  80780800               +cmp byte ptr [eax + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004810f3  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004810f6  7441                   -je 0x481139
    if (cpu.flags.zf)
    {
        goto L_0x00481139;
    }
    // 004810f8  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004810fc  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004810ff  3bc1                   +cmp eax, ecx
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
    // 00481101  7410                   -je 0x481113
    if (cpu.flags.zf)
    {
        goto L_0x00481113;
    }
    // 00481103  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00481106  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481107  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481108  e823160000             -call 0x482730
    cpu.esp -= 4;
    _strcmp(app, cpu);
    // 0048110d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048110e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481110  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481111  7522                   -jne 0x481135
    if (!cpu.flags.zf)
    {
        goto L_0x00481135;
    }
L_0x00481113:
    // 00481113  f60602                 +test byte ptr [esi], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi) & 2 /*0x2*/));
    // 00481116  7405                   -je 0x48111d
    if (cpu.flags.zf)
    {
        goto L_0x0048111d;
    }
    // 00481118  f60708                 +test byte ptr [edi], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi) & 8 /*0x8*/));
    // 0048111b  7418                   -je 0x481135
    if (cpu.flags.zf)
    {
        goto L_0x00481135;
    }
L_0x0048111d:
    // 0048111d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481121  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00481123  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00481125  7405                   -je 0x48112c
    if (cpu.flags.zf)
    {
        goto L_0x0048112c;
    }
    // 00481127  f60701                 +test byte ptr [edi], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi) & 1 /*0x1*/));
    // 0048112a  7409                   -je 0x481135
    if (cpu.flags.zf)
    {
        goto L_0x00481135;
    }
L_0x0048112c:
    // 0048112c  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0048112e  7409                   -je 0x481139
    if (cpu.flags.zf)
    {
        goto L_0x00481139;
    }
    // 00481130  f60702                 +test byte ptr [edi], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi) & 2 /*0x2*/));
    // 00481133  7504                   -jne 0x481139
    if (!cpu.flags.zf)
    {
        goto L_0x00481139;
    }
L_0x00481135:
    // 00481135  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481137  eb03                   -jmp 0x48113c
    goto L_0x0048113c;
L_0x00481139:
    // 00481139  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048113b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048113c:
    // 0048113c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048113d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048113e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48113f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048113f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481140  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481142  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00481144  6880854800             -push 0x488580
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752768 /*0x488580*/;
    cpu.esp -= 4;
    // 00481149  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0048114e  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00481154  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481155  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0048115c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048115f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481160  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481161  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481162  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00481165  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481168  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048116b  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 0048116e  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00481171  3b7514                 +cmp esi, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481174  7455                   -je 0x4811cb
    if (cpu.flags.zf)
    {
        return sub_4811cb(app, cpu);
    }
    // 00481176  83feff                 +cmp esi, -1
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
    // 00481179  7e05                   -jle 0x481180
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481180;
    }
    // 0048117b  3b7704                 +cmp esi, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048117e  7c05                   -jl 0x481185
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481185;
    }
L_0x00481180:
    // 00481180  e838050000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x00481185:
    // 00481185  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481189  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048118c  8b44f004               -mov eax, dword ptr [eax + esi*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 00481190  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481192  740c                   -je 0x4811a0
    if (cpu.flags.zf)
    {
        goto L_0x004811a0;
    }
    // 00481194  6803010000             -push 0x103
    app->getMemory<x86::reg32>(cpu.esp-4) = 259 /*0x103*/;
    cpu.esp -= 4;
    // 00481199  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048119a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048119b  e870040000             -call 0x481610
    cpu.esp -= 4;
    __CallSettingFrame_12(app, cpu);
L_0x004811a0:
    // 004811a0  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004811a4  eb1a                   -jmp 0x4811c0
    return sub_4811c0(app, cpu);
}

/* align: skip  */
void Application::sub_481171(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00481171;
    // 0048113f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481140  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481142  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00481144  6880854800             -push 0x488580
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752768 /*0x488580*/;
    cpu.esp -= 4;
    // 00481149  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0048114e  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00481154  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481155  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0048115c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048115f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481160  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481161  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481162  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00481165  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00481168  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048116b  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 0048116e  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_entry_0x00481171:
    // 00481171  3b7514                 +cmp esi, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481174  7455                   -je 0x4811cb
    if (cpu.flags.zf)
    {
        return sub_4811cb(app, cpu);
    }
    // 00481176  83feff                 +cmp esi, -1
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
    // 00481179  7e05                   -jle 0x481180
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481180;
    }
    // 0048117b  3b7704                 +cmp esi, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048117e  7c05                   -jl 0x481185
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481185;
    }
L_0x00481180:
    // 00481180  e838050000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x00481185:
    // 00481185  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481189  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048118c  8b44f004               -mov eax, dword ptr [eax + esi*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 00481190  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481192  740c                   -je 0x4811a0
    if (cpu.flags.zf)
    {
        goto L_0x004811a0;
    }
    // 00481194  6803010000             -push 0x103
    app->getMemory<x86::reg32>(cpu.esp-4) = 259 /*0x103*/;
    cpu.esp -= 4;
    // 00481199  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048119a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048119b  e870040000             -call 0x481610
    cpu.esp -= 4;
    __CallSettingFrame_12(app, cpu);
L_0x004811a0:
    // 004811a0  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004811a4  eb1a                   -jmp 0x4811c0
    return sub_4811c0(app, cpu);
}

/* align: skip  */
void Application::sub_4811a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004811a6  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 004811a9  e82f000000             -call 0x4811dd
    cpu.esp -= 4;
    sub_4811dd(app, cpu);
    // 004811ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4811b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004811b0  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004811b3  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004811b7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004811ba  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004811bd  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004811c0  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004811c3  8b34f0                 -mov esi, dword ptr [eax + esi*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 8);
    // 004811c6  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 004811c9  eba6                   -jmp 0x481171
    return sub_481171(app, cpu);
    // 004811cb  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004811ce  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004811d1  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004811d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811db  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4811cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004811cb;
    // 004811b0  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004811b3  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004811b7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004811ba  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004811bd  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004811c0  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004811c3  8b34f0                 -mov esi, dword ptr [eax + esi*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 8);
    // 004811c6  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 004811c9  eba6                   -jmp 0x481171
    return sub_481171(app, cpu);
L_entry_0x004811cb:
    // 004811cb  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004811ce  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004811d1  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004811d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811db  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4811c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004811c0;
    // 004811b0  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004811b3  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004811b7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004811ba  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004811bd  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
L_entry_0x004811c0:
    // 004811c0  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004811c3  8b34f0                 -mov esi, dword ptr [eax + esi*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 8);
    // 004811c6  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 004811c9  eba6                   -jmp 0x481171
    return sub_481171(app, cpu);
    // 004811cb  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004811ce  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004811d1  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004811d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811db  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4811dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004811dd  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004811e1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004811e3  813863736de0           +cmp dword ptr [eax], 0xe06d7363
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3765269347 /*0xe06d7363*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004811e9  7403                   -je 0x4811ee
    if (cpu.flags.zf)
    {
        goto L_0x004811ee;
    }
    // 004811eb  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004811ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004811ee:
    // 004811ee  e969040000             -jmp 0x48165c
    return sub_48165c(app, cpu);
}

/* align: skip  */
void Application::sub_4811f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004811f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004811f4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004811f6  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004811fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004811fb  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004811fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004811ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481200  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00481203  7410                   -je 0x481215
    if (cpu.flags.zf)
    {
        goto L_0x00481215;
    }
    // 00481205  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00481208  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481209  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048120a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048120d  e8a1010000             -call 0x4813b3
    cpu.esp -= 4;
    sub_4813b3(app, cpu);
    // 00481212  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00481215:
    // 00481215  837d2c00               +cmp dword ptr [ebp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481219  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048121c  7503                   -jne 0x481221
    if (!cpu.flags.zf)
    {
        goto L_0x00481221;
    }
    // 0048121e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048121f  eb03                   -jmp 0x481224
    goto L_0x00481224;
L_0x00481221:
    // 00481221  ff752c                 -push dword ptr [ebp + 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
L_0x00481224:
    // 00481224  e89b8fffff             -call 0x47a1c4
    cpu.esp -= 4;
    sub_47a1c4(app, cpu);
    // 00481229  8b7524                 -mov esi, dword ptr [ebp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0048122c  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0048122e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00481231  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00481234  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481235  e805ffffff             -call 0x48113f
    cpu.esp -= 4;
    sub_48113f(app, cpu);
    // 0048123a  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048123d  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00481242  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00481245  40                     -inc eax
    (cpu.eax)++;
    // 00481246  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00481249  ff730c                 -push dword ptr [ebx + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048124c  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0048124f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00481252  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481253  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00481256  e813000000             -call 0x48126e
    cpu.esp -= 4;
    sub_48126e(app, cpu);
    // 0048125b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048125e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481260  7407                   -je 0x481269
    if (cpu.flags.zf)
    {
        goto L_0x00481269;
    }
    // 00481262  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481263  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481264  e8198fffff             -call 0x47a182
    cpu.esp -= 4;
    sub_47a182(app, cpu);
L_0x00481269:
    // 00481269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048126a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048126b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048126c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048126d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48126e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048126e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048126f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481271  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00481273  6890854800             -push 0x488590
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752784 /*0x488590*/;
    cpu.esp -= 4;
    // 00481278  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0048127d  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00481283  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481284  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0048128b  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048128e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048128f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481290  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481291  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00481294  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00481297  895dd4                 -mov dword ptr [ebp - 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ebx;
    // 0048129a  8365dc00               -and dword ptr [ebp - 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0048129e  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004812a1  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004812a4  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004812a7  e8bba1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812ac  8b406c                 -mov eax, dword ptr [eax + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 004812af  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004812b2  e8b0a1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812b7  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004812ba  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004812bd  e8a5a1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812c2  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004812c5  89786c                 -mov dword ptr [eax + 0x6c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.edi;
    // 004812c8  e89aa1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812cd  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004812d0  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 004812d3  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004812d7  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 004812de  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004812e1  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004812e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004812e5  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004812e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004812e9  e85b8fffff             -call 0x47a249
    cpu.esp -= 4;
    sub_47a249(app, cpu);
    // 004812ee  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004812f1  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 004812f4  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004812f8  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004812fc  e83a000000             -call 0x48133b
    cpu.esp -= 4;
    sub_48133b(app, cpu);
    // 00481301  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00481304  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00481307  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0048130e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048130f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481310  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481311  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481312  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481304(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00481304;
    // 0048126e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048126f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00481271  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00481273  6890854800             -push 0x488590
    app->getMemory<x86::reg32>(cpu.esp-4) = 4752784 /*0x488590*/;
    cpu.esp -= 4;
    // 00481278  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0048127d  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00481283  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481284  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0048128b  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048128e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048128f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481290  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481291  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00481294  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00481297  895dd4                 -mov dword ptr [ebp - 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ebx;
    // 0048129a  8365dc00               -and dword ptr [ebp - 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0048129e  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004812a1  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004812a4  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004812a7  e8bba1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812ac  8b406c                 -mov eax, dword ptr [eax + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 004812af  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004812b2  e8b0a1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812b7  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004812ba  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004812bd  e8a5a1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812c2  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004812c5  89786c                 -mov dword ptr [eax + 0x6c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.edi;
    // 004812c8  e89aa1ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 004812cd  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004812d0  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 004812d3  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004812d7  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 004812de  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004812e1  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004812e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004812e5  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004812e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004812e9  e85b8fffff             -call 0x47a249
    cpu.esp -= 4;
    sub_47a249(app, cpu);
    // 004812ee  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004812f1  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 004812f4  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004812f8  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004812fc  e83a000000             -call 0x48133b
    cpu.esp -= 4;
    sub_48133b(app, cpu);
    // 00481301  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
L_entry_0x00481304:
    // 00481304  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00481307  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0048130e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048130f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481310  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481311  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481312  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481313(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481313  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00481316  e86e000000             -call 0x481389
    cpu.esp -= 4;
    sub_481389(app, cpu);
    // 0048131b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048131c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48131d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048131d  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00481320  8365d400               -and dword ptr [ebp - 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00481324  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00481326  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00481329  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048132a  e86b88ffff             -call 0x479b9a
    cpu.esp -= 4;
    __local_unwind2(app, cpu);
    // 0048132f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481330  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481331  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481333  ebcf                   -jmp 0x481304
    return sub_481304(app, cpu);
}

}
