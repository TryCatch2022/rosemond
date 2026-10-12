#include "menu.h"
namespace menu
{

/* align: skip  */
void Application::asm_sub_401000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401000  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 00401006  8b8424ac000000         -mov eax, dword ptr [esp + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0040100d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040100e  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00401015  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401016  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401017  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401018  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040101c  6824214300             -push 0x432124
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399396 /*0x432124*/;
    cpu.esp -= 4;
    // 00401021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401022  e89e410200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00401027  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401028  6818214300             -push 0x432118
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399384 /*0x432118*/;
    cpu.esp -= 4;
    // 0040102d  e862410200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401032  8d542444               -lea edx, [esp + 0x44]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00401036  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401037  6804214300             -push 0x432104
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399364 /*0x432104*/;
    cpu.esp -= 4;
    // 0040103c  e853410200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401041  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00401045  6800214300             -push 0x432100
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399360 /*0x432100*/;
    cpu.esp -= 4;
    // 0040104a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040104b  e831410200             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 00401050  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00401052  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00401055  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00401057  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0040105b  7514                   -jne 0x401071
    if (!cpu.flags.zf)
    {
        goto L_0x00401071;
    }
    // 0040105d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040105e  e892400200             -call 0x4250f5
    cpu.esp -= 4;
    sub_4250f5(app, cpu);
    // 00401063  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401066  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401068  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401069  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040106a  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 00401070  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401071:
    // 00401071  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401072  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401074  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00401078  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 0040107a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040107b  e88d3f0200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 00401080  8a44242a               -mov al, byte ptr [esp + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(42) /* 0x2a */);
    // 00401084  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401087  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401089  741c                   -je 0x4010a7
    if (cpu.flags.zf)
    {
        goto L_0x004010a7;
    }
    // 0040108b  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040108d  7418                   -je 0x4010a7
    if (cpu.flags.zf)
    {
        goto L_0x004010a7;
    }
    // 0040108f  68c8204300             -push 0x4320c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399304 /*0x4320c8*/;
    cpu.esp -= 4;
    // 00401094  e8fb400200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401099  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040109c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040109e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040109f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004010a0  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 004010a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004010a7:
    // 004010a7  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004010ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004010ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004010ad  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004010af  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004010b1  7618                   -jbe 0x4010cb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004010cb;
    }
L_0x004010b3:
    // 004010b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004010b4  e83a3f0200             -call 0x424ff3
    cpu.esp -= 4;
    sub_424ff3(app, cpu);
    // 004010b9  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004010bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004010c0  46                     -inc esi
    (cpu.esi)++;
    // 004010c1  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004010c7  3bf2                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004010c9  7ce8                   -jl 0x4010b3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004010b3;
    }
L_0x004010cb:
    // 004010cb  8bb424b8000000         -mov esi, dword ptr [esp + 0xb8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 004010d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004010d3  e828020000             -call 0x401300
    cpu.esp -= 4;
    sub_401300(app, cpu);
    // 004010d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004010d9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004010da  e811030000             -call 0x4013f0
    cpu.esp -= 4;
    sub_4013f0(app, cpu);
    // 004010df  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004010e4  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004010e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004010e9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004010eb  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004010ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004010ee  e8f63d0200             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 004010f3  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004010f7  8b44244a               -mov eax, dword ptr [esp + 0x4a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(74) /* 0x4a */);
    // 004010fb  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004010ff  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401105  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040110a  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00401110  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00401113  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 00401116  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00401119  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040111a  e8563d0200             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0040111f  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00401122  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00401126  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401128  750d                   -jne 0x401137
    if (!cpu.flags.zf)
    {
        goto L_0x00401137;
    }
    // 0040112a  68bc204300             -push 0x4320bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399292 /*0x4320bc*/;
    cpu.esp -= 4;
    // 0040112f  e85cce0100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 00401134  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00401137:
    // 00401137  8b44242e               -mov eax, dword ptr [esp + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(46) /* 0x2e */);
    // 0040113b  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0040113f  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00401141  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00401143  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401149  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040114f  4d                     -dec ebp
    (cpu.ebp)--;
    // 00401150  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401154  0faffd                 -imul edi, ebp
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00401157  0faffe                 -imul edi, esi
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040115a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040115c  03fa                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040115e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00401160  0f8c3f010000           -jl 0x4012a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004012a5;
    }
L_0x00401166:
    // 00401166  807c24220a             +cmp byte ptr [esp + 0x22], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(34) /* 0x22 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040116b  0f85dc000000           -jne 0x40124d
    if (!cpu.flags.zf)
    {
        goto L_0x0040124d;
    }
    // 00401171  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401175  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401176  e8783e0200             -call 0x424ff3
    cpu.esp -= 4;
    sub_424ff3(app, cpu);
    // 0040117b  8ad0                   -mov dl, al
    cpu.dl = cpu.al;
    // 0040117d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401180  83e27f                 -and edx, 0x7f
    cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00401183  42                     -inc edx
    (cpu.edx)++;
    // 00401184  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00401186  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00401188  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0040118c  7460                   -je 0x4011ee
    if (cpu.flags.zf)
    {
        goto L_0x004011ee;
    }
    // 0040118e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401192  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00401196  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401197  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401198  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040119a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040119b  e86d3e0200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 004011a0  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004011a4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004011a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004011a9  0f8ee6000000           -jle 0x401295
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401295;
    }
    // 004011af  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004011b3  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004011b5:
    // 004011b5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004011b7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004011b9  7e10                   -jle 0x4011cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004011cb;
    }
L_0x004011bb:
    // 004011bb  8a4c0418               -mov cl, byte ptr [esp + eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */ + cpu.eax * 1);
    // 004011bf  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004011c1  47                     -inc edi
    (cpu.edi)++;
    // 004011c2  40                     -inc eax
    (cpu.eax)++;
    // 004011c3  3bc6                   +cmp eax, esi
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
    // 004011c5  7cf4                   -jl 0x4011bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004011bb;
    }
    // 004011c7  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
L_0x004011cb:
    // 004011cb  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004011cd  43                     -inc ebx
    (cpu.ebx)++;
    // 004011ce  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004011d3  3bd8                   +cmp ebx, eax
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
    // 004011d5  750f                   -jne 0x4011e6
    if (!cpu.flags.zf)
    {
        goto L_0x004011e6;
    }
    // 004011d7  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004011d9  4d                     -dec ebp
    (cpu.ebp)--;
    // 004011da  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004011dd  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004011e0  03442410               +add eax, dword ptr [esp + 0x10]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004011e4  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004011e6:
    // 004011e6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004011e7  75cc                   -jne 0x4011b5
    if (!cpu.flags.zf)
    {
        goto L_0x004011b5;
    }
    // 004011e9  e9ab000000             -jmp 0x401299
    goto L_0x00401299;
L_0x004011ee:
    // 004011ee  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004011f0  0f8e9f000000           -jle 0x401295
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401295;
    }
    // 004011f6  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x004011fa:
    // 004011fa  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004011fe  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00401202  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401203  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401204  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401206  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401207  e8013e0200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 0040120c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040120f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401211  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401213  7e0c                   -jle 0x401221
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401221;
    }
L_0x00401215:
    // 00401215  8a4c0418               -mov cl, byte ptr [esp + eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */ + cpu.eax * 1);
    // 00401219  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 0040121b  47                     -inc edi
    (cpu.edi)++;
    // 0040121c  40                     -inc eax
    (cpu.eax)++;
    // 0040121d  3bc6                   +cmp eax, esi
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
    // 0040121f  7cf4                   -jl 0x401215
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401215;
    }
L_0x00401221:
    // 00401221  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401225  43                     -inc ebx
    (cpu.ebx)++;
    // 00401226  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00401228  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040122d  3bd8                   +cmp ebx, eax
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
    // 0040122f  750f                   -jne 0x401240
    if (!cpu.flags.zf)
    {
        goto L_0x00401240;
    }
    // 00401231  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00401233  4d                     -dec ebp
    (cpu.ebp)--;
    // 00401234  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00401237  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040123a  03442410               +add eax, dword ptr [esp + 0x10]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040123e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00401240:
    // 00401240  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00401244  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00401245  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00401249  75af                   -jne 0x4011fa
    if (!cpu.flags.zf)
    {
        goto L_0x004011fa;
    }
    // 0040124b  eb4c                   -jmp 0x401299
    goto L_0x00401299;
L_0x0040124d:
    // 0040124d  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401251  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00401255  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401256  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401257  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401259  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040125a  e8ae3d0200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 0040125f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401262  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401264  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401266  7e0c                   -jle 0x401274
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401274;
    }
L_0x00401268:
    // 00401268  8a4c0418               -mov cl, byte ptr [esp + eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */ + cpu.eax * 1);
    // 0040126c  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 0040126e  47                     -inc edi
    (cpu.edi)++;
    // 0040126f  40                     -inc eax
    (cpu.eax)++;
    // 00401270  3bc6                   +cmp eax, esi
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
    // 00401272  7cf4                   -jl 0x401268
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401268;
    }
L_0x00401274:
    // 00401274  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401278  43                     -inc ebx
    (cpu.ebx)++;
    // 00401279  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040127b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401280  3bd8                   +cmp ebx, eax
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
    // 00401282  7515                   -jne 0x401299
    if (!cpu.flags.zf)
    {
        goto L_0x00401299;
    }
    // 00401284  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00401286  4d                     -dec ebp
    (cpu.ebp)--;
    // 00401287  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0040128a  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040128d  03442410               +add eax, dword ptr [esp + 0x10]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401291  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00401293  eb04                   -jmp 0x401299
    goto L_0x00401299;
L_0x00401295:
    // 00401295  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
L_0x00401299:
    // 00401299  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0040129b  0f8dc5feffff           -jge 0x401166
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401166;
    }
    // 004012a1  8b44242e               -mov eax, dword ptr [esp + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(46) /* 0x2e */);
L_0x004012a5:
    // 004012a5  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004012ab  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004012b0  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004012b3  8b1564dd4300           -mov edx, dword ptr [0x43dd64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004012b9  0fafce                 -imul ecx, esi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004012bc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004012c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004012c1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004012c3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004012c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004012c5  e81f3c0200             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 004012ca  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004012ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004012cf  e8723b0200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 004012d4  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004012d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004012d9  e8123b0200             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 004012de  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004012e1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004012e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004012e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004012e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004012e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004012ea  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 004012f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401300  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 00401305  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00401308  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040130a  0f85cd000000           -jne 0x4013dd
    if (!cpu.flags.zf)
    {
        goto L_0x004013dd;
    }
    // 00401310  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401311  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00401315  6800214300             -push 0x432100
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399360 /*0x432100*/;
    cpu.esp -= 4;
    // 0040131a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040131b  e8613e0200             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 00401320  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401323  a364dd4300             -mov dword ptr [0x43dd64], eax
    app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */) = cpu.eax;
    // 00401328  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040132a  7575                   -jne 0x4013a1
    if (!cpu.flags.zf)
    {
        goto L_0x004013a1;
    }
    // 0040132c  6848214300             -push 0x432148
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399432 /*0x432148*/;
    cpu.esp -= 4;
    // 00401331  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401332  e84a3e0200             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 00401337  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040133a  a364dd4300             -mov dword ptr [0x43dd64], eax
    app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */) = cpu.eax;
    // 0040133f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401341  7512                   -jne 0x401355
    if (!cpu.flags.zf)
    {
        goto L_0x00401355;
    }
    // 00401343  6830214300             -push 0x432130
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399408 /*0x432130*/;
    cpu.esp -= 4;
    // 00401348  e843cc0100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 0040134d  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 00401352  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00401355:
    // 00401355  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401356  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401357  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401359  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0040135b  6860dd4300             -push 0x43dd60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4447584 /*0x43dd60*/;
    cpu.esp -= 4;
    // 00401360  c70560dd430000000000   -mov dword ptr [0x43dd60], 0
    app->getMemory<x86::reg32>(x86::reg32(4447584) /* 0x43dd60 */) = 0 /*0x0*/;
    // 0040136a  e87a3b0200             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 0040136f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401372  be00080000             -mov esi, 0x800
    cpu.esi = 2048 /*0x800*/;
L_0x00401377:
    // 00401377  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 0040137c  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00401380  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401381  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401383  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00401385  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401386  e85e3b0200             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 0040138b  83c410                 +add esp, 0x10
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
    // 0040138e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040138f  75e6                   -jne 0x401377
    if (!cpu.flags.zf)
    {
        goto L_0x00401377;
    }
    // 00401391  8b1564dd4300           -mov edx, dword ptr [0x43dd64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 00401397  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401398  e8533a0200             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 0040139d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004013a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004013a1:
    // 004013a1  682c214300             -push 0x43212c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399404 /*0x43212c*/;
    cpu.esp -= 4;
    // 004013a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004013a7  e8d53d0200             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 004013ac  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004013af  a364dd4300             -mov dword ptr [0x43dd64], eax
    app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */) = cpu.eax;
    // 004013b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004013b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013b7  7512                   -jne 0x4013cb
    if (!cpu.flags.zf)
    {
        goto L_0x004013cb;
    }
    // 004013b9  6830214300             -push 0x432130
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399408 /*0x432130*/;
    cpu.esp -= 4;
    // 004013be  e8cdcb0100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 004013c3  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004013c8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004013cb:
    // 004013cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004013cc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004013ce  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004013d0  6860dd4300             -push 0x43dd60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4447584 /*0x43dd60*/;
    cpu.esp -= 4;
    // 004013d5  e8333c0200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 004013da  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004013dd:
    // 004013dd  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004013e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4013f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004013f0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004013f4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004013f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004013f8  e803ffffff             -call 0x401300
    cpu.esp -= 4;
    sub_401300(app, cpu);
    // 004013fd  a160dd4300             -mov eax, dword ptr [0x43dd60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447584) /* 0x43dd60 */);
    // 00401402  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401405  3d00080000             +cmp eax, 0x800
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
    // 0040140a  750d                   -jne 0x401419
    if (!cpu.flags.zf)
    {
        goto L_0x00401419;
    }
    // 0040140c  684c214300             -push 0x43214c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399436 /*0x43214c*/;
    cpu.esp -= 4;
    // 00401411  e87acb0100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 00401416  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00401419:
    // 00401419  8b0d60dd4300           -mov ecx, dword ptr [0x43dd60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4447584) /* 0x43dd60 */);
    // 0040141f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401420  41                     -inc ecx
    (cpu.ecx)++;
    // 00401421  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401422  890d60dd4300           -mov dword ptr [0x43dd60], ecx
    app->getMemory<x86::reg32>(x86::reg32(4447584) /* 0x43dd60 */) = cpu.ecx;
    // 00401428  8b0d64dd4300           -mov ecx, dword ptr [0x43dd64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 0040142e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401430  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401432  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401433  e8373f0200             -call 0x42536f
    cpu.esp -= 4;
    sub_42536f(app, cpu);
    // 00401438  8b1564dd4300           -mov edx, dword ptr [0x43dd64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 0040143e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040143f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401441  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00401443  6860dd4300             -push 0x43dd60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4447584 /*0x43dd60*/;
    cpu.esp -= 4;
    // 00401448  e89c3a0200             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 0040144d  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 00401452  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00401454  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401456  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401457  e8133f0200             -call 0x42536f
    cpu.esp -= 4;
    sub_42536f(app, cpu);
    // 0040145c  8b0d64dd4300           -mov ecx, dword ptr [0x43dd64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 00401462  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401463  e8af3d0200             -call 0x425217
    cpu.esp -= 4;
    sub_425217(app, cpu);
    // 00401468  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0040146c  89442441               -mov dword ptr [esp + 0x41], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(65) /* 0x41 */) = cpu.eax;
    // 00401470  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00401473  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00401475  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00401477  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00401479  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040147b  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040147f  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00401481  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00401483  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00401485  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401487  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040148a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040148c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040148e  a160dd4300             -mov eax, dword ptr [0x43dd60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447584) /* 0x43dd60 */);
    // 00401493  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00401496  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00401498  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040149a  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0040149d  8d5401f3               -lea edx, [ecx + eax - 0xd]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-13) /* -0xd */ + cpu.eax * 1);
    // 004014a1  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004014a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004014a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004014a8  e8c23e0200             -call 0x42536f
    cpu.esp -= 4;
    sub_42536f(app, cpu);
    // 004014ad  8b0d64dd4300           -mov ecx, dword ptr [0x43dd64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004014b3  8d542440               -lea edx, [esp + 0x40]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004014b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004014b8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004014ba  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004014bc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004014bd  e8273a0200             -call 0x424ee9
    cpu.esp -= 4;
    sub_424ee9(app, cpu);
    // 004014c2  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004014c7  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004014ca  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004014cc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004014ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004014cf  e89b3e0200             -call 0x42536f
    cpu.esp -= 4;
    sub_42536f(app, cpu);
    // 004014d4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004014d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014d9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004014dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4014e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004014e0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004014e4  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004014e8  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004014ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004014ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004014f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004014f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004014f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004014f3  e8b8030000             -call 0x4018b0
    cpu.esp -= 4;
    sub_4018b0(app, cpu);
    // 004014f8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004014fb  83f8ff                 +cmp eax, -1
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
    // 004014fe  750c                   -jne 0x40150c
    if (!cpu.flags.zf)
    {
        goto L_0x0040150c;
    }
    // 00401500  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401501  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401502  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401504  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401505  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0040150b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040150c:
    // 0040150c  8b1564dd4300           -mov edx, dword ptr [0x43dd64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 00401512  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401514  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401515  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401516  e8543e0200             -call 0x42536f
    cpu.esp -= 4;
    sub_42536f(app, cpu);
    // 0040151b  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 00401520  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00401524  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401525  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401527  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00401529  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040152a  e8de3a0200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 0040152f  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00401533  8b54243e               -mov edx, dword ptr [esp + 0x3e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(62) /* 0x3e */);
    // 00401537  8b742440               -mov esi, dword ptr [esp + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0040153b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401540  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401546  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040154c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0040154f  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 00401552  89742450               -mov dword ptr [esp + 0x50], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.esi;
    // 00401556  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00401559  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040155a  e816390200             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0040155f  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00401561  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00401564  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00401566  896c243c               -mov dword ptr [esp + 0x3c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebp;
    // 0040156a  750d                   -jne 0x401579
    if (!cpu.flags.zf)
    {
        goto L_0x00401579;
    }
    // 0040156c  68bc204300             -push 0x4320bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399292 /*0x4320bc*/;
    cpu.esp -= 4;
    // 00401571  e81aca0100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 00401576  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00401579:
    // 00401579  a164dd4300             -mov eax, dword ptr [0x43dd64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 0040157e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040157f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401581  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401582  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401583  e8853a0200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 00401588  8b542432               -mov edx, dword ptr [esp + 0x32]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(50) /* 0x32 */);
    // 0040158c  b91b000000             -mov ecx, 0x1b
    cpu.ecx = 27 /*0x1b*/;
    // 00401591  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401593  8d7c2464               -lea edi, [esp + 0x64]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00401597  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00401599  a17c5a4900             -mov eax, dword ptr [0x495a7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807292) /* 0x495a7c */);
    // 0040159e  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004015a2  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 004015a9  8a442434               -mov al, byte ptr [esp + 0x34]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004015ad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004015b0  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004015b6  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004015bc  3c20                   +cmp al, 0x20
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
    // 004015be  c74424546c000000       -mov dword ptr [esp + 0x54], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 108 /*0x6c*/;
    // 004015c6  c744245807100000       -mov dword ptr [esp + 0x58], 0x1007
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = 4103 /*0x1007*/;
    // 004015ce  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 004015d2  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 004015d6  c78424bc00000040080000 -mov dword ptr [esp + 0xbc], 0x840
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = 2112 /*0x840*/;
    // 004015e1  750c                   -jne 0x4015ef
    if (!cpu.flags.zf)
    {
        goto L_0x004015ef;
    }
    // 004015e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015e5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004015e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015e8  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004015ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004015ef:
    // 004015ef  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004015f4  bea85a4900             -mov esi, 0x495aa8
    cpu.esi = 4807336 /*0x495aa8*/;
    // 004015f9  8dbc249c000000         -lea edi, [esp + 0x9c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00401600  8d54244c               -lea edx, [esp + 0x4c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00401604  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00401606  8b8c24ac000000         -mov ecx, dword ptr [esp + 0xac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0040160d  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00401611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401612  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401613  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401614  e857030000             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 00401619  8b8c24bc000000         -mov ecx, dword ptr [esp + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00401620  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00401624  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401625  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00401629  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040162a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040162b  e840030000             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 00401630  8b8c24cc000000         -mov ecx, dword ptr [esp + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00401637  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040163b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040163c  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00401640  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401641  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401642  e829030000             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 00401647  8b8c24dc000000         -mov ecx, dword ptr [esp + 0xdc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 0040164e  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00401652  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401653  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00401657  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401658  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401659  e812030000             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 0040165e  8b8424f4000000         -mov eax, dword ptr [esp + 0xf4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(244) /* 0xf4 */);
    // 00401665  8bb424d8000000         -mov esi, dword ptr [esp + 0xd8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 0040166c  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0040166f  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401673  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00401675  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401677  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401678  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0040167c  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 0040167f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401680  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401681  8974243c               -mov dword ptr [esp + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 00401685  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040168a  7419                   -je 0x4016a5
    if (cpu.flags.zf)
    {
        goto L_0x004016a5;
    }
    // 0040168c  6880214300             -push 0x432180
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399488 /*0x432180*/;
    cpu.esp -= 4;
    // 00401691  e8fe3a0200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401696  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401699  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040169b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040169c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040169d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040169e  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004016a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004016a5:
    // 004016a5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004016a9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004016ab  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004016af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004016b1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004016b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004016b4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004016b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016b7  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004016ba  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004016bf  751c                   -jne 0x4016dd
    if (!cpu.flags.zf)
    {
        goto L_0x004016dd;
    }
L_0x004016c1:
    // 004016c1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004016c5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004016c7  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004016cb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004016cd  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004016cf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004016d0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004016d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016d3  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004016d6  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004016db  74e4                   -je 0x4016c1
    if (cpu.flags.zf)
    {
        goto L_0x004016c1;
    }
L_0x004016dd:
    // 004016dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004016df  7419                   -je 0x4016fa
    if (cpu.flags.zf)
    {
        goto L_0x004016fa;
    }
    // 004016e1  686c214300             -push 0x43216c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399468 /*0x43216c*/;
    cpu.esp -= 4;
    // 004016e6  e8a93a0200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 004016eb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004016ee  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004016f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004016f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004016f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004016f3  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004016f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004016fa:
    // 004016fa  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004016fe  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00401702  0faff1                 -imul esi, ecx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401705  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00401709  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0040170d  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00401711  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401712  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00401714  8bdd                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00401716  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401718  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0040171c  0f865a010000           -jbe 0x40187c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040187c;
    }
L_0x00401722:
    // 00401722  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00401724  0f8e39010000           -jle 0x401863
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401863;
    }
    // 0040172a  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0040172e:
    // 0040172e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401730  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 00401735  8a4b02                 -mov cl, byte ptr [ebx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00401738  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0040173f  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00401742  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401744  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401746  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0040174a  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 0040174d  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040174f  8b6c2454               -mov ebp, dword ptr [esp + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00401753  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 00401756  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401758  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0040175d  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040175f  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00401761  0faf74243c             -imul esi, dword ptr [esp + 0x3c]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */))));
    // 00401766  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 00401768  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040176a  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 0040176f  8a4b01                 -mov cl, byte ptr [ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00401772  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00401775  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401777  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401779  23f7                   -and esi, edi
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edi));
    // 0040177b  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 0040177e  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00401780  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 00401785  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 00401788  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040178a  2bcd                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040178c  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0040178e  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 00401793  0faf7c2434             -imul edi, dword ptr [esp + 0x34]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 00401798  d3ff                   -sar edi, cl
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (cpu.cl % 32));
    // 0040179a  8b8c24b4000000         -mov ecx, dword ptr [esp + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004017a1  23f9                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004017a3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004017a5  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004017a7  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 004017aa  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004017ac  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004017ae  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004017b2  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 004017b5  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004017b7  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 004017ba  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004017bc  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 004017c1  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004017c3  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004017c5  0faf6c242c             -imul ebp, dword ptr [esp + 0x2c]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 004017ca  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004017ce  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 004017d0  8b8c24b8000000         -mov ecx, dword ptr [esp + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 004017d7  23e9                   -and ebp, ecx
    cpu.ebp &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004017d9  3c20                   +cmp al, 0x20
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
    // 004017db  7549                   -jne 0x401826
    if (!cpu.flags.zf)
    {
        goto L_0x00401826;
    }
    // 004017dd  837c241801             +cmp dword ptr [esp + 0x18], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004017e2  750a                   -jne 0x4017ee
    if (!cpu.flags.zf)
    {
        goto L_0x004017ee;
    }
    // 004017e4  807b0340               +cmp byte ptr [ebx + 3], 0x40
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004017e8  7604                   -jbe 0x4017ee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004017ee;
    }
    // 004017ea  c64303ff               -mov byte ptr [ebx + 3], 0xff
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 255 /*0xff*/;
L_0x004017ee:
    // 004017ee  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004017f0  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 004017f5  8a4b03                 -mov cl, byte ptr [ebx + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004017f8  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 004017fb  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004017fd  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004017ff  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401801  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 00401806  c1f807                 -sar eax, 7
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (7 /*0x7*/ % 32));
    // 00401809  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040180b  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 0040180e  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00401810  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00401814  0faf442418             -imul eax, dword ptr [esp + 0x18]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00401819  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040181b  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0040181d  238424bc000000         +and eax, dword ptr [esp + 0xbc]
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */)))));
    // 00401824  eb02                   -jmp 0x401828
    goto L_0x00401828;
L_0x00401826:
    // 00401826  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00401828:
    // 00401828  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040182c  0bc5                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040182e  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00401832  0bc7                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00401834  0bc6                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00401836  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00401838  0bf0                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0040183a  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040183e  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00401840  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00401842  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00401846  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0040184a  03d9                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040184c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040184d  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00401851  0f85d7feffff           -jne 0x40172e
    if (!cpu.flags.zf)
    {
        goto L_0x0040172e;
    }
    // 00401857  8b4c2464               -mov ecx, dword ptr [esp + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0040185b  8b6c2440               -mov ebp, dword ptr [esp + 0x40]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0040185f  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
L_0x00401863:
    // 00401863  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401867  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0040186b  03f0                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040186d  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040186e  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00401872  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 00401876  0f85a6feffff           -jne 0x401722
    if (!cpu.flags.zf)
    {
        goto L_0x00401722;
    }
L_0x0040187c:
    // 0040187c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401880  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401882  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401883  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00401885  ff9180000000           -call dword ptr [ecx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040188b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040188c  e8b5350200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00401891  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00401895  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401898  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401899  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189c  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004018a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4018b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004018b0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004018b4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004018b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004018b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004018b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004018ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004018bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004018bc  e83ffaffff             -call 0x401300
    cpu.esp -= 4;
    sub_401300(app, cpu);
    // 004018c1  8b0d64dd4300           -mov ecx, dword ptr [0x43dd64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004018c7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004018c9  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004018cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004018cc  e89e3a0200             -call 0x42536f
    cpu.esp -= 4;
    sub_42536f(app, cpu);
    // 004018d1  a160dd4300             -mov eax, dword ptr [0x43dd60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447584) /* 0x43dd60 */);
    // 004018d6  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004018da  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004018dd  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004018df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004018e1  7e59                   -jle 0x40193c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040193c;
    }
L_0x004018e3:
    // 004018e3  8b1564dd4300           -mov edx, dword ptr [0x43dd64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4447588) /* 0x43dd64 */);
    // 004018e9  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004018ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004018ee  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004018f0  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004018f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004018f3  e815370200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 004018f8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004018fb  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004018fd  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00401901:
    // 00401901  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00401903  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 00401905  8aca                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00401907  3ad3                   +cmp dl, bl
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
    // 00401909  751e                   -jne 0x401929
    if (!cpu.flags.zf)
    {
        goto L_0x00401929;
    }
    // 0040190b  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0040190d  7416                   -je 0x401925
    if (cpu.flags.zf)
    {
        goto L_0x00401925;
    }
    // 0040190f  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00401912  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00401915  8aca                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00401917  3ad3                   +cmp dl, bl
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
    // 00401919  750e                   -jne 0x401929
    if (!cpu.flags.zf)
    {
        goto L_0x00401929;
    }
    // 0040191b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040191e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00401921  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00401923  75dc                   -jne 0x401901
    if (!cpu.flags.zf)
    {
        goto L_0x00401901;
    }
L_0x00401925:
    // 00401925  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00401927  eb05                   -jmp 0x40192e
    goto L_0x0040192e;
L_0x00401929:
    // 00401929  1bc0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040192b  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0040192e:
    // 0040192e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401930  7424                   -je 0x401956
    if (cpu.flags.zf)
    {
        goto L_0x00401956;
    }
    // 00401932  a160dd4300             -mov eax, dword ptr [0x43dd60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447584) /* 0x43dd60 */);
    // 00401937  45                     -inc ebp
    (cpu.ebp)++;
    // 00401938  3be8                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040193a  7ca7                   -jl 0x4018e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004018e3;
    }
L_0x0040193c:
    // 0040193c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040193d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040193e  6898214300             -push 0x432198
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399512 /*0x432198*/;
    cpu.esp -= 4;
    // 00401943  e84c380200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401948  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040194b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040194e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040194f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401950  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401951  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401952  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00401955  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401956:
    // 00401956  8b44241d               -mov eax, dword ptr [esp + 0x1d]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 0040195a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040195b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040195c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040195d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040195e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00401961  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401970  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00401974  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00401978  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0040197b  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00401981  7511                   -jne 0x401994
    if (!cpu.flags.zf)
    {
        goto L_0x00401994;
    }
L_0x00401983:
    // 00401983  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00401985  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00401987  42                     -inc edx
    (cpu.edx)++;
    // 00401988  83fa1f                 +cmp edx, 0x1f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040198b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0040198d  740c                   -je 0x40199b
    if (cpu.flags.zf)
    {
        goto L_0x0040199b;
    }
    // 0040198f  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00401992  74ef                   -je 0x401983
    if (cpu.flags.zf)
    {
        goto L_0x00401983;
    }
L_0x00401994:
    // 00401994  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00401998  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0040199a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040199b:
    // 0040199b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040199f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004019a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4019b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004019b0  81eccc000000           -sub esp, 0xcc
    (cpu.esp) -= x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004019b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004019b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004019b8  8bac24dc000000         -mov ebp, dword ptr [esp + 0xdc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 004019bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004019c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004019c1  6800214300             -push 0x432100
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399360 /*0x432100*/;
    cpu.esp -= 4;
    // 004019c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004019c7  e8b5370200             -call 0x425181
    cpu.esp -= 4;
    sub_425181(app, cpu);
    // 004019cc  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004019ce  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004019d1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004019d3  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004019d7  7516                   -jne 0x4019ef
    if (!cpu.flags.zf)
    {
        goto L_0x004019ef;
    }
    // 004019d9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004019da  e816370200             -call 0x4250f5
    cpu.esp -= 4;
    sub_4250f5(app, cpu);
    // 004019df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004019e2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004019e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019e8  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004019ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004019ef:
    // 004019ef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004019f0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004019f2  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004019f6  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 004019f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004019f9  e80f360200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 004019fe  8a442432               -mov al, byte ptr [esp + 0x32]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(50) /* 0x32 */);
    // 00401a02  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401a05  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401a07  741e                   -je 0x401a27
    if (cpu.flags.zf)
    {
        goto L_0x00401a27;
    }
    // 00401a09  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401a0b  741a                   -je 0x401a27
    if (cpu.flags.zf)
    {
        goto L_0x00401a27;
    }
    // 00401a0d  68c8204300             -push 0x4320c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399304 /*0x4320c8*/;
    cpu.esp -= 4;
    // 00401a12  e87d370200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401a17  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401a1a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401a1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a20  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00401a26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401a27:
    // 00401a27  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00401a2b  8b54242e               -mov edx, dword ptr [esp + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(46) /* 0x2e */);
    // 00401a2f  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401a33  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00401a39  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401a3f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401a40  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401a45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401a46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401a47  688c224300             -push 0x43228c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399756 /*0x43228c*/;
    cpu.esp -= 4;
    // 00401a4c  e843370200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401a51  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00401a55  8b9424f8000000         -mov edx, dword ptr [esp + 0xf8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 00401a5c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00401a5e  8bb424fc000000         -mov esi, dword ptr [esp + 0xfc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00401a65  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401a6b  8b7c2440               -mov edi, dword ptr [esp + 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00401a6f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00401a71  8b4c243e               -mov ecx, dword ptr [esp + 0x3e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(62) /* 0x3e */);
    // 00401a75  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00401a77  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401a7a  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401a80  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00401a84  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00401a86  8bb424f0000000         -mov esi, dword ptr [esp + 0xf0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 00401a8d  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00401a8f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00401a95  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00401a97  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00401a9b  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 00401a9f  668bd7                 -mov dx, di
    cpu.dx = cpu.di;
    // 00401aa2  668954246c             -mov word ptr [esp + 0x6c], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.dx;
    // 00401aa7  8a542420               -mov dl, byte ptr [esp + 0x20]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00401aab  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00401aad  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00401aaf  7623                   -jbe 0x401ad4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00401ad4;
    }
L_0x00401ab1:
    // 00401ab1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401ab2  e83c350200             -call 0x424ff3
    cpu.esp -= 4;
    sub_424ff3(app, cpu);
    // 00401ab7  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00401abb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401abe  46                     -inc esi
    (cpu.esi)++;
    // 00401abf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00401ac4  3bf0                   +cmp esi, eax
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
    // 00401ac6  7ce9                   -jl 0x401ab1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401ab1;
    }
    // 00401ac8  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401acc  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00401ad0  8b4c242e               -mov ecx, dword ptr [esp + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(46) /* 0x2e */);
L_0x00401ad4:
    // 00401ad4  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00401ada  be80204300             -mov esi, 0x432080
    cpu.esi = 4399232 /*0x432080*/;
    // 00401adf  c1ef03                 -shr edi, 3
    cpu.edi >>= 3 /*0x3*/ % 32;
    // 00401ae2  897c2448               -mov dword ptr [esp + 0x48], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edi;
L_0x00401ae6:
    // 00401ae6  813effff0000           +cmp dword ptr [esi], 0xffff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401aec  7527                   -jne 0x401b15
    if (!cpu.flags.zf)
    {
        goto L_0x00401b15;
    }
    // 00401aee  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401af4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401af5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401af6  6874224300             -push 0x432274
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399732 /*0x432274*/;
    cpu.esp -= 4;
    // 00401afb  e894360200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401b00  6848224300             -push 0x432248
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399688 /*0x432248*/;
    cpu.esp -= 4;
    // 00401b05  e886c40100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 00401b0a  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00401b0e  8b4c243e               -mov ecx, dword ptr [esp + 0x3e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(62) /* 0x3e */);
    // 00401b12  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00401b15:
    // 00401b15  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00401b17  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00401b19  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401b1f  3bd3                   +cmp edx, ebx
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
    // 00401b21  7405                   -je 0x401b28
    if (cpu.flags.zf)
    {
        goto L_0x00401b28;
    }
    // 00401b23  83c604                 +add esi, 4
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
    // 00401b26  ebbe                   -jmp 0x401ae6
    goto L_0x00401ae6;
L_0x00401b28:
    // 00401b28  be80204300             -mov esi, 0x432080
    cpu.esi = 4399232 /*0x432080*/;
L_0x00401b2d:
    // 00401b2d  813effff0000           +cmp dword ptr [esi], 0xffff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401b33  752d                   -jne 0x401b62
    if (!cpu.flags.zf)
    {
        goto L_0x00401b62;
    }
    // 00401b35  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401b3a  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401b40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401b41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401b42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401b43  6830224300             -push 0x432230
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399664 /*0x432230*/;
    cpu.esp -= 4;
    // 00401b48  e847360200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401b4d  6848224300             -push 0x432248
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399688 /*0x432248*/;
    cpu.esp -= 4;
    // 00401b52  e839c40100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 00401b57  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00401b5b  8b4c2442               -mov ecx, dword ptr [esp + 0x42]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(66) /* 0x42 */);
    // 00401b5f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00401b62:
    // 00401b62  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00401b64  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00401b66  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401b6c  3bd3                   +cmp edx, ebx
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
    // 00401b6e  7405                   -je 0x401b75
    if (cpu.flags.zf)
    {
        goto L_0x00401b75;
    }
    // 00401b70  83c604                 +add esi, 4
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
    // 00401b73  ebb8                   -jmp 0x401b2d
    goto L_0x00401b2d;
L_0x00401b75:
    // 00401b75  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401b7a  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401b80  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401b83  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00401b86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401b87  e8e9320200             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 00401b8c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401b8f  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00401b93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401b95  750d                   -jne 0x401ba4
    if (!cpu.flags.zf)
    {
        goto L_0x00401ba4;
    }
    // 00401b97  68bc204300             -push 0x4320bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399292 /*0x4320bc*/;
    cpu.esp -= 4;
    // 00401b9c  e8efc30100             -call 0x41df90
    cpu.esp -= 4;
    sub_41df90(app, cpu);
    // 00401ba1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00401ba4:
    // 00401ba4  8b5c242e               -mov ebx, dword ptr [esp + 0x2e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(46) /* 0x2e */);
    // 00401ba8  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401bac  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401bb2  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401bb8  4b                     -dec ebx
    (cpu.ebx)--;
    // 00401bb9  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401bbd  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00401bc0  0faff7                 -imul esi, edi
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00401bc3  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00401bc5  03f1                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401bc7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00401bc9  0f8c25010000           -jl 0x401cf4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401cf4;
    }
L_0x00401bcf:
    // 00401bcf  8a442422               -mov al, byte ptr [esp + 0x22]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(34) /* 0x22 */);
    // 00401bd3  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401bd5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401bd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401bda  0f85cd000000           -jne 0x401cad
    if (!cpu.flags.zf)
    {
        goto L_0x00401cad;
    }
    // 00401be0  e80e340200             -call 0x424ff3
    cpu.esp -= 4;
    sub_424ff3(app, cpu);
    // 00401be5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00401be7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401bea  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00401bed  41                     -inc ecx
    (cpu.ecx)++;
    // 00401bee  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00401bf0  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00401bf4  745a                   -je 0x401c50
    if (cpu.flags.zf)
    {
        goto L_0x00401c50;
    }
    // 00401bf6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401bfa  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00401bfe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401bff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401c00  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401c02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401c03  e805340200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 00401c08  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00401c0c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401c0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401c11  0f8ed5000000           -jle 0x401cec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401cec;
    }
    // 00401c17  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00401c19:
    // 00401c19  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401c1b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00401c1d  7e0c                   -jle 0x401c2b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401c2b;
    }
L_0x00401c1f:
    // 00401c1f  8a54041c               -mov dl, byte ptr [esp + eax + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.eax * 1);
    // 00401c23  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00401c25  46                     -inc esi
    (cpu.esi)++;
    // 00401c26  40                     -inc eax
    (cpu.eax)++;
    // 00401c27  3bc7                   +cmp eax, edi
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
    // 00401c29  7cf4                   -jl 0x401c1f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401c1f;
    }
L_0x00401c2b:
    // 00401c2b  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401c2f  45                     -inc ebp
    (cpu.ebp)++;
    // 00401c30  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401c35  3be8                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401c37  750f                   -jne 0x401c48
    if (!cpu.flags.zf)
    {
        goto L_0x00401c48;
    }
    // 00401c39  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00401c3b  4b                     -dec ebx
    (cpu.ebx)--;
    // 00401c3c  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00401c3f  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00401c42  03442414               +add eax, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401c46  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00401c48:
    // 00401c48  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00401c49  75ce                   -jne 0x401c19
    if (!cpu.flags.zf)
    {
        goto L_0x00401c19;
    }
    // 00401c4b  e99c000000             -jmp 0x401cec
    goto L_0x00401cec;
L_0x00401c50:
    // 00401c50  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00401c52  0f8e94000000           -jle 0x401cec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401cec;
    }
    // 00401c58  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00401c5c:
    // 00401c5c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401c60  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00401c64  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401c65  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401c66  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401c68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401c69  e89f330200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 00401c6e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401c71  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401c73  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00401c75  7e0c                   -jle 0x401c83
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401c83;
    }
L_0x00401c77:
    // 00401c77  8a54041c               -mov dl, byte ptr [esp + eax + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.eax * 1);
    // 00401c7b  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00401c7d  46                     -inc esi
    (cpu.esi)++;
    // 00401c7e  40                     -inc eax
    (cpu.eax)++;
    // 00401c7f  3bc7                   +cmp eax, edi
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
    // 00401c81  7cf4                   -jl 0x401c77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401c77;
    }
L_0x00401c83:
    // 00401c83  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401c87  45                     -inc ebp
    (cpu.ebp)++;
    // 00401c88  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401c8d  3be8                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401c8f  750f                   -jne 0x401ca0
    if (!cpu.flags.zf)
    {
        goto L_0x00401ca0;
    }
    // 00401c91  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00401c93  4b                     -dec ebx
    (cpu.ebx)--;
    // 00401c94  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00401c97  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00401c9a  03442414               +add eax, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401c9e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00401ca0:
    // 00401ca0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00401ca4  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00401ca5  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00401ca9  75b1                   -jne 0x401c5c
    if (!cpu.flags.zf)
    {
        goto L_0x00401c5c;
    }
    // 00401cab  eb3f                   -jmp 0x401cec
    goto L_0x00401cec;
L_0x00401cad:
    // 00401cad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401cae  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00401cb2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401cb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401cb5  e853330200             -call 0x42500d
    cpu.esp -= 4;
    sub_42500d(app, cpu);
    // 00401cba  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00401cbd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401cbf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00401cc1  7e0c                   -jle 0x401ccf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401ccf;
    }
L_0x00401cc3:
    // 00401cc3  8a54041c               -mov dl, byte ptr [esp + eax + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.eax * 1);
    // 00401cc7  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00401cc9  46                     -inc esi
    (cpu.esi)++;
    // 00401cca  40                     -inc eax
    (cpu.eax)++;
    // 00401ccb  3bc7                   +cmp eax, edi
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
    // 00401ccd  7cf4                   -jl 0x401cc3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401cc3;
    }
L_0x00401ccf:
    // 00401ccf  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00401cd3  45                     -inc ebp
    (cpu.ebp)++;
    // 00401cd4  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401cd9  3be8                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401cdb  750f                   -jne 0x401cec
    if (!cpu.flags.zf)
    {
        goto L_0x00401cec;
    }
    // 00401cdd  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00401cdf  4b                     -dec ebx
    (cpu.ebx)--;
    // 00401ce0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00401ce3  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00401ce6  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00401cea  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00401cec:
    // 00401cec  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00401cee  0f8ddbfeffff           -jge 0x401bcf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401bcf;
    }
L_0x00401cf4:
    // 00401cf4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401cf8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401cf9  e8f2300200             -call 0x424df0
    cpu.esp -= 4;
    sub_424df0(app, cpu);
    // 00401cfe  6804224300             -push 0x432204
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399620 /*0x432204*/;
    cpu.esp -= 4;
    // 00401d03  e88c340200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401d08  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 00401d0d  e8e9360200             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 00401d12  b91b000000             -mov ecx, 0x1b
    cpu.ecx = 27 /*0x1b*/;
    // 00401d17  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401d19  8d7c247c               -lea edi, [esp + 0x7c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00401d1d  8b157c5a4900           -mov edx, dword ptr [0x495a7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4807292) /* 0x495a7c */);
    // 00401d23  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00401d25  8b4c243a               -mov ecx, dword ptr [esp + 0x3a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(58) /* 0x3a */);
    // 00401d29  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00401d2d  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401d33  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00401d38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401d39  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 00401d3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401d3f  68ec214300             -push 0x4321ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399596 /*0x4321ec*/;
    cpu.esp -= 4;
    // 00401d44  899c2488000000         -mov dword ptr [esp + 0x88], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ebx;
    // 00401d4b  c784248c00000007100000 -mov dword ptr [esp + 0x8c], 0x1007
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = 4103 /*0x1007*/;
    // 00401d56  89842494000000         -mov dword ptr [esp + 0x94], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.eax;
    // 00401d5d  898c2490000000         -mov dword ptr [esp + 0x90], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.ecx;
    // 00401d64  c78424f000000040080000 -mov dword ptr [esp + 0xf0], 0x840
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */) = 2112 /*0x840*/;
    // 00401d6f  899424a4000000         -mov dword ptr [esp + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.edx;
    // 00401d76  e819340200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401d7b  8a442448               -mov al, byte ptr [esp + 0x48]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00401d7f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00401d82  3c20                   +cmp al, 0x20
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
    // 00401d84  751a                   -jne 0x401da0
    if (!cpu.flags.zf)
    {
        goto L_0x00401da0;
    }
    // 00401d86  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401d8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401d8b  e8b6300200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00401d90  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401d93  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401d95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d99  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00401d9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401da0:
    // 00401da0  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00401da5  bea85a4900             -mov esi, 0x495aa8
    cpu.esi = 4807336 /*0x495aa8*/;
    // 00401daa  8dbc24b8000000         -lea edi, [esp + 0xb8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00401db1  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00401db5  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00401db7  8b8c24c8000000         -mov ecx, dword ptr [esp + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00401dbe  8d442458               -lea eax, [esp + 0x58]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00401dc2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401dc3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401dc4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401dc5  e8a6fbffff             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 00401dca  8b8c24d8000000         -mov ecx, dword ptr [esp + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 00401dd1  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00401dd5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401dd6  8d442454               -lea eax, [esp + 0x54]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00401dda  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401ddb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401ddc  e88ffbffff             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 00401de1  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 00401de8  8d542478               -lea edx, [esp + 0x78]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00401dec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401ded  8d442468               -lea eax, [esp + 0x68]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00401df1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401df2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401df3  e878fbffff             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 00401df8  8b8c24f8000000         -mov ecx, dword ptr [esp + 0xf8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 00401dff  8d542478               -lea edx, [esp + 0x78]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00401e03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401e04  8d442460               -lea eax, [esp + 0x60]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00401e08  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401e09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401e0a  e861fbffff             -call 0x401970
    cpu.esp -= 4;
    sub_401970(app, cpu);
    // 00401e0f  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00401e16  8bb424f4000000         -mov esi, dword ptr [esp + 0xf4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(244) /* 0xf4 */);
    // 00401e1d  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00401e20  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00401e22  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00401e24  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00401e28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401e29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401e2a  8d542478               -lea edx, [esp + 0x78]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00401e2e  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 00401e31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401e32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401e33  89742450               -mov dword ptr [esp + 0x50], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.esi;
    // 00401e37  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401e3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401e3c  741a                   -je 0x401e58
    if (cpu.flags.zf)
    {
        goto L_0x00401e58;
    }
    // 00401e3e  6880214300             -push 0x432180
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399488 /*0x432180*/;
    cpu.esp -= 4;
    // 00401e43  e84c330200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401e48  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401e4b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401e4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e51  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00401e57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401e58:
    // 00401e58  68dc214300             -push 0x4321dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399580 /*0x4321dc*/;
    cpu.esp -= 4;
    // 00401e5d  e832330200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401e62  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 00401e67  e88f350200             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 00401e6c  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00401e70  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401e73  8d542470               -lea edx, [esp + 0x70]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00401e77  895c2470               -mov dword ptr [esp + 0x70], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebx;
    // 00401e7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401e7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401e7d  c744247c06080000       -mov dword ptr [esp + 0x7c], 0x806
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = 2054 /*0x806*/;
    // 00401e85  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 00401e8c  89bc2480000000         -mov dword ptr [esp + 0x80], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edi;
    // 00401e93  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00401e95  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401e96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401e97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401e98  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401e9b  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401ea0  7519                   -jne 0x401ebb
    if (!cpu.flags.zf)
    {
        goto L_0x00401ebb;
    }
L_0x00401ea2:
    // 00401ea2  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00401ea6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401ea7  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00401eab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401eac  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00401eae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401eaf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401eb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401eb1  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401eb4  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401eb9  74e7                   -je 0x401ea2
    if (cpu.flags.zf)
    {
        goto L_0x00401ea2;
    }
L_0x00401ebb:
    // 00401ebb  3bc7                   +cmp eax, edi
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
    // 00401ebd  741a                   -je 0x401ed9
    if (cpu.flags.zf)
    {
        goto L_0x00401ed9;
    }
    // 00401ebf  686c214300             -push 0x43216c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399468 /*0x43216c*/;
    cpu.esp -= 4;
    // 00401ec4  e8cb320200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401ec9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401ecc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401ece  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401ecf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401ed0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401ed1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401ed2  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 00401ed8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401ed9:
    // 00401ed9  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00401edd  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00401ee4  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00401ee6  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401eea  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401eed  8bb42480000000         -mov esi, dword ptr [esp + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00401ef4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00401ef8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401ef9  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00401efd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401efe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401eff  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00401f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401f02  68bc214300             -push 0x4321bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4399548 /*0x4321bc*/;
    cpu.esp -= 4;
    // 00401f07  89742464               -mov dword ptr [esp + 0x64], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.esi;
    // 00401f0b  e884320200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00401f10  68e0cf4300             -push 0x43cfe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4444128 /*0x43cfe0*/;
    cpu.esp -= 4;
    // 00401f15  e8e1340200             -call 0x4253fb
    cpu.esp -= 4;
    sub_4253fb(app, cpu);
    // 00401f1a  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00401f21  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00401f24  3bc7                   +cmp eax, edi
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
    // 00401f26  0f865e010000           -jbe 0x40208a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040208a;
    }
    // 00401f2c  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
L_0x00401f30:
    // 00401f30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401f32  0f8e35010000           -jle 0x40206d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040206d;
    }
    // 00401f38  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00401f3c:
    // 00401f3c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401f3e  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 00401f43  8a4b02                 -mov cl, byte ptr [ebx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00401f46  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00401f4d  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00401f50  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401f52  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401f54  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00401f58  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 00401f5b  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00401f5d  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00401f61  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 00401f64  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401f66  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 00401f6b  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00401f6d  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00401f6f  0faf742458             -imul esi, dword ptr [esp + 0x58]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */))));
    // 00401f74  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 00401f76  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401f78  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 00401f7d  8a4b01                 -mov cl, byte ptr [ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00401f80  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00401f83  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401f85  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401f87  23f7                   -and esi, edi
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edi));
    // 00401f89  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 00401f8c  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00401f8e  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 00401f93  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 00401f96  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00401f98  2bcd                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00401f9a  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00401f9c  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 00401fa1  0faf7c2444             -imul edi, dword ptr [esp + 0x44]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */))));
    // 00401fa6  d3ff                   -sar edi, cl
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (cpu.cl % 32));
    // 00401fa8  8b8c24cc000000         -mov ecx, dword ptr [esp + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00401faf  23f9                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401fb1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401fb3  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00401fb5  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00401fb8  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00401fba  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401fbc  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00401fc0  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 00401fc3  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00401fc5  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 00401fc8  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401fca  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 00401fcf  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00401fd1  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00401fd3  0faf6c244c             -imul ebp, dword ptr [esp + 0x4c]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */))));
    // 00401fd8  8a44246c               -mov al, byte ptr [esp + 0x6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00401fdc  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 00401fde  8b8c24d0000000         -mov ecx, dword ptr [esp + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00401fe5  23e9                   -and ebp, ecx
    cpu.ebp &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401fe7  3c20                   +cmp al, 0x20
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
    // 00401fe9  7549                   -jne 0x402034
    if (!cpu.flags.zf)
    {
        goto L_0x00402034;
    }
    // 00401feb  837c243801             +cmp dword ptr [esp + 0x38], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401ff0  750a                   -jne 0x401ffc
    if (!cpu.flags.zf)
    {
        goto L_0x00401ffc;
    }
    // 00401ff2  807b0340               +cmp byte ptr [ebx + 3], 0x40
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401ff6  7604                   -jbe 0x401ffc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00401ffc;
    }
    // 00401ff8  c64303ff               -mov byte ptr [ebx + 3], 0xff
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 255 /*0xff*/;
L_0x00401ffc:
    // 00401ffc  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401ffe  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 00402003  8a4b03                 -mov cl, byte ptr [ebx + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00402006  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00402009  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0040200b  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040200d  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040200f  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 00402014  c1f807                 -sar eax, 7
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (7 /*0x7*/ % 32));
    // 00402017  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00402019  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 0040201c  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040201e  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00402022  0faf442438             -imul eax, dword ptr [esp + 0x38]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */))));
    // 00402027  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00402029  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0040202b  238424d4000000         +and eax, dword ptr [esp + 0xd4]
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(212) /* 0xd4 */)))));
    // 00402032  eb02                   -jmp 0x402036
    goto L_0x00402036;
L_0x00402034:
    // 00402034  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00402036:
    // 00402036  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040203a  0bc5                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0040203c  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00402040  0bc7                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00402042  0bc6                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00402044  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402046  0bf0                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00402048  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040204c  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 0040204e  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00402050  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00402054  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00402058  03d9                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040205a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040205b  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0040205f  0f85d7feffff           -jne 0x401f3c
    if (!cpu.flags.zf)
    {
        goto L_0x00401f3c;
    }
    // 00402065  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00402069  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
L_0x0040206d:
    // 0040206d  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402071  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00402075  03d6                   +add edx, esi
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
    // 00402077  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00402078  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0040207c  894c2478               -mov dword ptr [esp + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 00402080  0f85aafeffff           -jne 0x401f30
    if (!cpu.flags.zf)
    {
        goto L_0x00401f30;
    }
    // 00402086  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x0040208a:
    // 0040208a  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0040208e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402090  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402091  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00402093  ff9180000000           -call dword ptr [ecx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402099  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040209a  e8a72d0200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0040209f  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004020a3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004020a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020aa  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004020b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4020c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004020c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004020c1  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004020c5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004020c7  741f                   -je 0x4020e8
    if (cpu.flags.zf)
    {
        goto L_0x004020e8;
    }
    // 004020c9  a1b0224300             -mov eax, dword ptr [0x4322b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4399792) /* 0x4322b0 */);
    // 004020ce  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004020d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004020d2  7414                   -je 0x4020e8
    if (cpu.flags.zf)
    {
        goto L_0x004020e8;
    }
    // 004020d4  b9b0224300             -mov ecx, 0x4322b0
    cpu.ecx = 4399792 /*0x4322b0*/;
L_0x004020d9:
    // 004020d9  3bc6                   +cmp eax, esi
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
    // 004020db  740f                   -je 0x4020ec
    if (cpu.flags.zf)
    {
        goto L_0x004020ec;
    }
    // 004020dd  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004020e0  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004020e3  42                     -inc edx
    (cpu.edx)++;
    // 004020e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004020e6  75f1                   -jne 0x4020d9
    if (!cpu.flags.zf)
    {
        goto L_0x004020d9;
    }
L_0x004020e8:
    // 004020e8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004020ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004020ec:
    // 004020ec  8b04d5b4224300         -mov eax, dword ptr [edx*8 + 0x4322b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4399796) /* 0x4322b4 */ + cpu.edx * 8);
    // 004020f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402100  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00402104  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402105  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00402107  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040210a  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040210c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040210e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402112  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402113  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402115  49                     -dec ecx
    (cpu.ecx)--;
    // 00402116  3bc8                   +cmp ecx, eax
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
    // 00402118  7d0d                   -jge 0x402127
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402127;
    }
L_0x0040211a:
    // 0040211a  c6041120               -mov byte ptr [ecx + edx], 0x20
    app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1) = 32 /*0x20*/;
    // 0040211e  41                     -inc ecx
    (cpu.ecx)++;
    // 0040211f  3bc8                   +cmp ecx, eax
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
    // 00402121  c6041100               -mov byte ptr [ecx + edx], 0
    app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 00402125  7cf3                   -jl 0x40211a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040211a;
    }
L_0x00402127:
    // 00402127  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402130  b8cc4e0000             -mov eax, 0x4ecc
    cpu.eax = 20172 /*0x4ecc*/;
    // 00402135  e896350200             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 0040213a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040213b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040213c  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0040213e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040213f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402140  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00402147  8bb5fc000000           -mov esi, dword ptr [ebp + 0xfc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(252) /* 0xfc */);
    // 0040214d  6868dd4300             -push 0x43dd68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4447592 /*0x43dd68*/;
    cpu.esp -= 4;
    // 00402152  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402153  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00402157  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00402159  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0040215d  e863300200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00402162  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402165  3bde                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402167  0f84b0010000           -je 0x40231d
    if (cpu.flags.zf)
    {
        goto L_0x0040231d;
    }
L_0x0040216d:
    // 0040216d  8b8508010000           -mov eax, dword ptr [ebp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(264) /* 0x108 */);
    // 00402173  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00402176  3bf0                   +cmp esi, eax
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
    // 00402178  752b                   -jne 0x4021a5
    if (!cpu.flags.zf)
    {
        goto L_0x004021a5;
    }
    // 0040217a  8dbc24bc000000         -lea edi, [esp + 0xbc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00402181  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402184  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402186  68b4284300             -push 0x4328b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401332 /*0x4328b4*/;
    cpu.esp -= 4;
    // 0040218b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040218d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0040218f  49                     -dec ecx
    (cpu.ecx)--;
    // 00402190  8d8c0cc0000000         -lea ecx, [esp + ecx + 0xc0]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(192) /* 0xc0 */ + cpu.ecx * 1);
    // 00402197  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402198  e828300200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 0040219d  83c408                 +add esp, 8
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
    // 004021a0  e96a010000             -jmp 0x40230f
    goto L_0x0040230f;
L_0x004021a5:
    // 004021a5  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004021a8  0f8429010000           -je 0x4022d7
    if (cpu.flags.zf)
    {
        goto L_0x004022d7;
    }
    // 004021ae  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004021b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004021b2  e809ffffff             -call 0x4020c0
    cpu.esp -= 4;
    sub_4020c0(app, cpu);
    // 004021b7  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004021b9  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004021bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004021bd  e8fefeffff             -call 0x4020c0
    cpu.esp -= 4;
    sub_4020c0(app, cpu);
    // 004021c2  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004021c4  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 004021c6  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004021ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004021cb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004021cc  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004021d0  e8fb330200             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 004021d5  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004021d9  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 004021db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004021dc  e81fffffff             -call 0x402100
    cpu.esp -= 4;
    sub_402100(app, cpu);
    // 004021e1  8dbc24d8000000         -lea edi, [esp + 0xd8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 004021e8  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004021eb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004021ed  83c41c                 +add esp, 0x1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004021f0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004021f2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004021f4  49                     -dec ecx
    (cpu.ecx)--;
    // 004021f5  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004021f9  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004021fb  8d940cbc000000         -lea edx, [esp + ecx + 0xbc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */ + cpu.ecx * 1);
    // 00402202  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00402205  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00402207  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402209  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040220b  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040220d  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0040220f  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00402211  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00402214  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00402216  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00402218  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040221b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0040221d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0040221f  7455                   -je 0x402276
    if (cpu.flags.zf)
    {
        goto L_0x00402276;
    }
    // 00402221  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00402223  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00402227  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402228  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402229  e8a2330200             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0040222e  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00402232  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00402234  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402235  e8c6feffff             -call 0x402100
    cpu.esp -= 4;
    sub_402100(app, cpu);
    // 0040223a  8dbc24d0000000         -lea edi, [esp + 0xd0]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00402241  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402244  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402246  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402249  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040224b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0040224d  49                     -dec ecx
    (cpu.ecx)--;
    // 0040224e  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00402252  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00402254  8dac0cbc000000         -lea ebp, [esp + ecx + 0xbc]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */ + cpu.ecx * 1);
    // 0040225b  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0040225e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00402260  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402262  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402264  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402266  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00402268  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0040226a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040226d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040226f  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00402271  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00402274  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
L_0x00402276:
    // 00402276  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0040227a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040227c  7455                   -je 0x4022d3
    if (cpu.flags.zf)
    {
        goto L_0x004022d3;
    }
    // 0040227e  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00402280  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00402284  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402285  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402286  e845330200             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0040228b  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0040228f  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00402291  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402292  e869feffff             -call 0x402100
    cpu.esp -= 4;
    sub_402100(app, cpu);
    // 00402297  8dbc24d0000000         -lea edi, [esp + 0xd0]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 0040229e  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004022a1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004022a3  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004022a6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004022a8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004022aa  49                     -dec ecx
    (cpu.ecx)--;
    // 004022ab  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004022af  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004022b1  8dac0cbc000000         -lea ebp, [esp + ecx + 0xbc]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */ + cpu.ecx * 1);
    // 004022b8  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004022bb  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004022bd  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004022bf  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004022c1  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004022c3  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004022c5  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004022c7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004022ca  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004022cc  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004022ce  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004022d1  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
L_0x004022d3:
    // 004022d3  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x004022d7:
    // 004022d7  8dbc24bc000000         -lea edi, [esp + 0xbc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 004022de  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004022e1  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004022e3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004022e5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004022e7  49                     -dec ecx
    (cpu.ecx)--;
    // 004022e8  bfb0284300             -mov edi, 0x4328b0
    cpu.edi = 4401328 /*0x4328b0*/;
    // 004022ed  8d940cbc000000         -lea edx, [esp + ecx + 0xbc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */ + cpu.ecx * 1);
    // 004022f4  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004022f7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004022f9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004022fb  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004022fd  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004022ff  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00402301  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00402303  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00402306  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00402308  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040230a  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040230d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
L_0x0040230f:
    // 0040230f  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00402311  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402315  3bd8                   +cmp ebx, eax
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
    // 00402317  0f8550feffff           -jne 0x40216d
    if (!cpu.flags.zf)
    {
        goto L_0x0040216d;
    }
L_0x0040231d:
    // 0040231d  8b85d4000000           -mov eax, dword ptr [ebp + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(212) /* 0xd4 */);
    // 00402323  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402325  7439                   -je 0x402360
    if (cpu.flags.zf)
    {
        goto L_0x00402360;
    }
    // 00402327  8b8dc8000000           -mov ecx, dword ptr [ebp + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(200) /* 0xc8 */);
    // 0040232d  8d9424bc000000         -lea edx, [esp + 0xbc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00402334  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402335  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402336  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402337  e894320200             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0040233c  8bbdd4000000           -mov edi, dword ptr [ebp + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(212) /* 0xd4 */);
    // 00402342  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402345  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402347  83c40c                 +add esp, 0xc
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
    // 0040234a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040234c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0040234e  49                     -dec ecx
    (cpu.ecx)--;
    // 0040234f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402350  898dc4000000           -mov dword ptr [ebp + 0xc4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(196) /* 0xc4 */) = cpu.ecx;
    // 00402356  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402357  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402358  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402359  81c4cc4e0000           -add esp, 0x4ecc
    (cpu.esp) += x86::reg32(x86::sreg32(20172 /*0x4ecc*/));
    // 0040235f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402360:
    // 00402360  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402361  c785c400000000000000   -mov dword ptr [ebp + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
    // 0040236b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040236c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040236d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040236e  81c4cc4e0000           -add esp, 0x4ecc
    (cpu.esp) += x86::reg32(x86::sreg32(20172 /*0x4ecc*/));
    // 00402374  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402380  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00402382  6838ef4200             -push 0x42ef38
    app->getMemory<x86::reg32>(cpu.esp-4) = 4386616 /*0x42ef38*/;
    cpu.esp -= 4;
    // 00402387  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0040238d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040238e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00402395  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00402398  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402399  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040239b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040239c  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040239e  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004023a2  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004023a6  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004023aa  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004023ae  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004023b2  8b8600010000           -mov eax, dword ptr [esi + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(256) /* 0x100 */);
    // 004023b8  8b8e04010000           -mov ecx, dword ptr [esi + 0x104]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(260) /* 0x104 */);
    // 004023be  3bc1                   +cmp eax, ecx
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
    // 004023c0  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004023c4  0f838c000000           -jae 0x402456
    if (!cpu.flags.cf)
    {
        goto L_0x00402456;
    }
    // 004023ca  8b86fc000000           -mov eax, dword ptr [esi + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 004023d0  8d8ef8000000           -lea ecx, [esi + 0xf8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(248) /* 0xf8 */);
    // 004023d6  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004023da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004023db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004023dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004023dd  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004023e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004023e2  e889120000             -call 0x403670
    cpu.esp -= 4;
    sub_403670(app, cpu);
    // 004023e7  8b8efc000000           -mov ecx, dword ptr [esi + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 004023ed  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004023f1  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004023f4  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004023f7  8b8efc000000           -mov ecx, dword ptr [esi + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 004023fd  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00402401  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402404  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00402407  8b8efc000000           -mov ecx, dword ptr [esi + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 0040240d  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402410  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402413  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00402415  3bc3                   +cmp eax, ebx
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
    // 00402417  740b                   -je 0x402424
    if (cpu.flags.zf)
    {
        goto L_0x00402424;
    }
    // 00402419  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040241a  e8272a0200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0040241f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402422  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
L_0x00402424:
    // 00402424  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00402428  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402429  e883c90200             -call 0x42edb1
    cpu.esp -= 4;
    sub_42edb1(app, cpu);
    // 0040242e  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00402432  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00402434  8b86fc000000           -mov eax, dword ptr [esi + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 0040243a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040243d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00402440  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00402443  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402446  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402447  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0040244a  8b9600010000           -mov edx, dword ptr [esi + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(256) /* 0x100 */);
    // 00402450  8996dc000000           -mov dword ptr [esi + 0xdc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */) = cpu.edx;
L_0x00402456:
    // 00402456  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 0040245c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040245e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040245f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402461  ff5040                 -call dword ptr [eax + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402464  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402466  e8c5fcffff             -call 0x402130
    cpu.esp -= 4;
    sub_402130(app, cpu);
    // 0040246b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040246f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402470  3bc3                   +cmp eax, ebx
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
    // 00402472  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402473  7409                   -je 0x40247e
    if (cpu.flags.zf)
    {
        goto L_0x0040247e;
    }
    // 00402475  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402476  e8cb290200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0040247b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040247e:
    // 0040247e  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00402482  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00402489  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0040248c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402490  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402491  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402495  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402496  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00402498  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402499  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040249a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040249b  8babfc000000           -mov ebp, dword ptr [ebx + 0xfc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(252) /* 0xfc */);
    // 004024a1  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004024a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004024ab  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004024ae  7426                   -je 0x4024d6
    if (cpu.flags.zf)
    {
        goto L_0x004024d6;
    }
    // 004024b0  3bf5                   +cmp esi, ebp
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
    // 004024b2  7422                   -je 0x4024d6
    if (cpu.flags.zf)
    {
        goto L_0x004024d6;
    }
L_0x004024b4:
    // 004024b4  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004024b8  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004024bb  8d7e08                 -lea edi, [esi + 8]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004024be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004024bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004024c0  e82bc90200             -call 0x42edf0
    cpu.esp -= 4;
    sub_42edf0(app, cpu);
    // 004024c5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004024c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004024ca  7504                   -jne 0x4024d0
    if (!cpu.flags.zf)
    {
        goto L_0x004024d0;
    }
    // 004024cc  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x004024d0:
    // 004024d0  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004024d2  3bf5                   +cmp esi, ebp
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
    // 004024d4  75de                   -jne 0x4024b4
    if (!cpu.flags.zf)
    {
        goto L_0x004024b4;
    }
L_0x004024d6:
    // 004024d6  8bbbfc000000           -mov edi, dword ptr [ebx + 0xfc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(252) /* 0xfc */);
    // 004024dc  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 004024de  3bf7                   +cmp esi, edi
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
    // 004024e0  7454                   -je 0x402536
    if (cpu.flags.zf)
    {
        goto L_0x00402536;
    }
    // 004024e2  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x004024e6:
    // 004024e6  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004024e9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004024ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004024eb  e800c90200             -call 0x42edf0
    cpu.esp -= 4;
    sub_42edf0(app, cpu);
    // 004024f0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004024f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004024f5  740e                   -je 0x402505
    if (cpu.flags.zf)
    {
        goto L_0x00402505;
    }
    // 004024f7  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004024f9  3bf7                   +cmp esi, edi
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
    // 004024fb  75e9                   -jne 0x4024e6
    if (!cpu.flags.zf)
    {
        goto L_0x004024e6;
    }
    // 004024fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004024fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004024ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402500  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402501  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402502  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00402505:
    // 00402505  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00402509  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0040250d  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402511  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00402514  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00402517  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0040251a  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00402521  8b83f0000000           -mov eax, dword ptr [ebx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(240) /* 0xf0 */);
    // 00402527  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00402529  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040252a  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040252c  ff5240                 -call dword ptr [edx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040252f  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00402531  e8fafbffff             -call 0x402130
    cpu.esp -= 4;
    sub_402130(app, cpu);
L_0x00402536:
    // 00402536  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402537  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402538  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402539  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040253a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040253b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402541  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402542  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402543  8bb9fc000000           -mov edi, dword ptr [ecx + 0xfc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(252) /* 0xfc */);
    // 00402549  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0040254b  3bf7                   +cmp esi, edi
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
    // 0040254d  741b                   -je 0x40256a
    if (cpu.flags.zf)
    {
        goto L_0x0040256a;
    }
    // 0040254f  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00402553:
    // 00402553  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00402556  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402557  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402558  e893c80200             -call 0x42edf0
    cpu.esp -= 4;
    sub_42edf0(app, cpu);
    // 0040255d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402560  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402562  740e                   -je 0x402572
    if (cpu.flags.zf)
    {
        goto L_0x00402572;
    }
    // 00402564  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00402566  3bf7                   +cmp esi, edi
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
    // 00402568  75e9                   -jne 0x402553
    if (!cpu.flags.zf)
    {
        goto L_0x00402553;
    }
L_0x0040256a:
    // 0040256a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040256b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040256c  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0040256e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040256f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00402572:
    // 00402572  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402576  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00402579  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040257a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0040257c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402580  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00402583  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402584  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00402586  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00402588  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402589  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402590  8b89fc000000           -mov ecx, dword ptr [ecx + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(252) /* 0xfc */);
    // 00402596  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402598  3bc1                   +cmp eax, ecx
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
    // 0040259a  7414                   -je 0x4025b0
    if (cpu.flags.zf)
    {
        goto L_0x004025b0;
    }
    // 0040259c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004025a0:
    // 004025a0  395014                 +cmp dword ptr [eax + 0x14], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004025a3  7410                   -je 0x4025b5
    if (cpu.flags.zf)
    {
        goto L_0x004025b5;
    }
    // 004025a5  395018                 +cmp dword ptr [eax + 0x18], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004025a8  740b                   -je 0x4025b5
    if (cpu.flags.zf)
    {
        goto L_0x004025b5;
    }
    // 004025aa  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004025ac  3bc1                   +cmp eax, ecx
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
    // 004025ae  75f0                   -jne 0x4025a0
    if (!cpu.flags.zf)
    {
        goto L_0x004025a0;
    }
L_0x004025b0:
    // 004025b0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004025b2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004025b5:
    // 004025b5  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004025b8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4025c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004025c0  a1b0224300             -mov eax, dword ptr [0x4322b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4399792) /* 0x4322b0 */);
    // 004025c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004025c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004025c7  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004025c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004025ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004025cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004025cd  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004025cf  7436                   -je 0x402607
    if (cpu.flags.zf)
    {
        goto L_0x00402607;
    }
    // 004025d1  bfb0224300             -mov edi, 0x4322b0
    cpu.edi = 4399792 /*0x4322b0*/;
    // 004025d6  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004025d8:
    // 004025d8  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004025da  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004025dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004025de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004025df  68f4284300             -push 0x4328f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401396 /*0x4328f4*/;
    cpu.esp -= 4;
    // 004025e4  e8ab2b0200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 004025e9  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004025eb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004025ee  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004025f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004025f1  e89affffff             -call 0x402590
    cpu.esp -= 4;
    sub_402590(app, cpu);
    // 004025f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004025f8  7414                   -je 0x40260e
    if (cpu.flags.zf)
    {
        goto L_0x0040260e;
    }
    // 004025fa  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004025fd  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402600  43                     -inc ebx
    (cpu.ebx)++;
    // 00402601  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00402603  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402605  75d1                   -jne 0x4025d8
    if (!cpu.flags.zf)
    {
        goto L_0x004025d8;
    }
L_0x00402607:
    // 00402607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402608  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402609  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040260a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040260c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040260d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040260e:
    // 0040260e  8b04ddb0224300         -mov eax, dword ptr [ebx*8 + 0x4322b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4399792) /* 0x4322b0 */ + cpu.ebx * 8);
    // 00402615  8b0cddb4224300         -mov ecx, dword ptr [ebx*8 + 0x4322b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4399796) /* 0x4322b4 */ + cpu.ebx * 8);
    // 0040261c  8d34ddb0224300         -lea esi, [ebx*8 + 0x4322b0]
    cpu.esi = x86::reg32(x86::reg32(4399792) /* 0x4322b0 */ + cpu.ebx * 8);
    // 00402623  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402624  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402625  68dc284300             -push 0x4328dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401372 /*0x4328dc*/;
    cpu.esp -= 4;
    // 0040262a  e8652b0200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0040262f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00402631  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00402634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402636  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402637  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402638  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402640  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402641  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402643  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00402645  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 0040264b  3bca                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040264d  7c3c                   -jl 0x40268b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040268b;
    }
    // 0040264f  398e00010000           +cmp dword ptr [esi + 0x100], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(256) /* 0x100 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402655  7e34                   -jle 0x40268b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040268b;
    }
    // 00402657  8b86fc000000           -mov eax, dword ptr [esi + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 0040265d  3bca                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040265f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00402661  7e05                   -jle 0x402668
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402668;
    }
L_0x00402663:
    // 00402663  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00402665  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00402666  75fb                   -jne 0x402663
    if (!cpu.flags.zf)
    {
        goto L_0x00402663;
    }
L_0x00402668:
    // 00402668  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040266b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040266c  6840284000             -push 0x402840
    app->getMemory<x86::reg32>(cpu.esp-4) = 4204608 /*0x402840*/;
    cpu.esp -= 4;
    // 00402671  898608010000           -mov dword ptr [esi + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 00402677  899610010000           -mov dword ptr [esi + 0x110], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 0040267d  89960c010000           -mov dword ptr [esi + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 00402683  e8581f0000             -call 0x4045e0
    cpu.esp -= 4;
    sub_4045e0(app, cpu);
    // 00402688  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0040268b:
    // 0040268b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040268d  e89efaffff             -call 0x402130
    cpu.esp -= 4;
    sub_402130(app, cpu);
    // 00402692  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00402694  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402695  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4026a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004026a0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004026a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004026a5  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004026a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004026a8  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004026ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004026ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004026ae  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004026b0  e87bae0100             -call 0x41d530
    cpu.esp -= 4;
    sub_41d530(app, cpu);
    // 004026b5  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004026b7  8b86f0000000           -mov eax, dword ptr [esi + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 004026bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004026bf  7d11                   -jge 0x4026d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004026d2;
    }
    // 004026c1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004026c3  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004026c5  c786f0000000ffffffff   -mov dword ptr [esi + 0xf0], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */) = 4294967295 /*0xffffffff*/;
    // 004026cf  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004026d2:
    // 004026d2  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004026d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026d6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4026e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004026e0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004026e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004026e5  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004026e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004026e8  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004026ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004026ed  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004026ef  e8dcad0100             -call 0x41d4d0
    cpu.esp -= 4;
    sub_41d4d0(app, cpu);
    // 004026f4  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004026f6  3bc2                   +cmp eax, edx
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
    // 004026f8  7c3c                   -jl 0x402736
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00402736;
    }
    // 004026fa  398600010000           +cmp dword ptr [esi + 0x100], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(256) /* 0x100 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402700  7e34                   -jle 0x402736
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402736;
    }
    // 00402702  8b8efc000000           -mov ecx, dword ptr [esi + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 00402708  3bc2                   +cmp eax, edx
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
    // 0040270a  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040270c  7e05                   -jle 0x402713
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402713;
    }
L_0x0040270e:
    // 0040270e  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402710  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00402711  75fb                   -jne 0x40270e
    if (!cpu.flags.zf)
    {
        goto L_0x0040270e;
    }
L_0x00402713:
    // 00402713  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402716  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402717  6840284000             -push 0x402840
    app->getMemory<x86::reg32>(cpu.esp-4) = 4204608 /*0x402840*/;
    cpu.esp -= 4;
    // 0040271c  898e08010000           -mov dword ptr [esi + 0x108], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.ecx;
    // 00402722  899610010000           -mov dword ptr [esi + 0x110], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 00402728  89960c010000           -mov dword ptr [esi + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 0040272e  e8ad1e0000             -call 0x4045e0
    cpu.esp -= 4;
    sub_4045e0(app, cpu);
    // 00402733  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00402736:
    // 00402736  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402738  e8f3f9ffff             -call 0x402130
    cpu.esp -= 4;
    sub_402130(app, cpu);
    // 0040273d  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040273f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402740  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402750  8b91fc000000           -mov edx, dword ptr [ecx + 0xfc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(252) /* 0xfc */);
    // 00402756  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00402758  3bc2                   +cmp eax, edx
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
    // 0040275a  7428                   -je 0x402784
    if (cpu.flags.zf)
    {
        goto L_0x00402784;
    }
    // 0040275c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040275d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040275e  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402763  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00402765:
    // 00402765  397018                 +cmp dword ptr [eax + 0x18], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402768  7503                   -jne 0x40276d
    if (!cpu.flags.zf)
    {
        goto L_0x0040276d;
    }
    // 0040276a  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
L_0x0040276d:
    // 0040276d  397014                 +cmp dword ptr [eax + 0x14], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402770  7509                   -jne 0x40277b
    if (!cpu.flags.zf)
    {
        goto L_0x0040277b;
    }
    // 00402772  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00402775  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00402778  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
L_0x0040277b:
    // 0040277b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0040277d  3bc2                   +cmp eax, edx
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
    // 0040277f  75e4                   -jne 0x402765
    if (!cpu.flags.zf)
    {
        goto L_0x00402765;
    }
    // 00402781  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402782  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402783  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00402784:
    // 00402784  e8a7f9ffff             -call 0x402130
    cpu.esp -= 4;
    sub_402130(app, cpu);
    // 00402789  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402791  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402795  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402796  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00402798  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402799  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040279a  8bb5fc000000           -mov esi, dword ptr [ebp + 0xfc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(252) /* 0xfc */);
    // 004027a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004027a1  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004027a3  e8a8ffffff             -call 0x402750
    cpu.esp -= 4;
    sub_402750(app, cpu);
    // 004027a8  3bfe                   +cmp edi, esi
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
    // 004027aa  7476                   -je 0x402822
    if (cpu.flags.zf)
    {
        goto L_0x00402822;
    }
    // 004027ac  8b8508010000           -mov eax, dword ptr [ebp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(264) /* 0x108 */);
L_0x004027b2:
    // 004027b2  8d4f08                 -lea ecx, [edi + 8]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004027b5  3bc8                   +cmp ecx, eax
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
    // 004027b7  7408                   -je 0x4027c1
    if (cpu.flags.zf)
    {
        goto L_0x004027c1;
    }
    // 004027b9  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004027bb  3bfe                   +cmp edi, esi
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
    // 004027bd  75f3                   -jne 0x4027b2
    if (!cpu.flags.zf)
    {
        goto L_0x004027b2;
    }
    // 004027bf  eb61                   -jmp 0x402822
    goto L_0x00402822;
L_0x004027c1:
    // 004027c1  81fb010f0000           +cmp ebx, 0xf01
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3841 /*0xf01*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004027c7  7408                   -je 0x4027d1
    if (cpu.flags.zf)
    {
        goto L_0x004027d1;
    }
    // 004027c9  81fb020f0000           +cmp ebx, 0xf02
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3842 /*0xf02*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004027cf  7544                   -jne 0x402815
    if (!cpu.flags.zf)
    {
        goto L_0x00402815;
    }
L_0x004027d1:
    // 004027d1  8d770c                 -lea esi, [edi + 0xc]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004027d4  c744241402000000       -mov dword ptr [esp + 0x14], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
L_0x004027dc:
    // 004027dc  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004027df  7426                   -je 0x402807
    if (cpu.flags.zf)
    {
        goto L_0x00402807;
    }
    // 004027e1  8b95fc000000           -mov edx, dword ptr [ebp + 0xfc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(252) /* 0xfc */);
    // 004027e7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004027e9  3bc2                   +cmp eax, edx
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
    // 004027eb  741a                   -je 0x402807
    if (cpu.flags.zf)
    {
        goto L_0x00402807;
    }
L_0x004027ed:
    // 004027ed  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004027f0  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004027f2  750d                   -jne 0x402801
    if (!cpu.flags.zf)
    {
        goto L_0x00402801;
    }
    // 004027f4  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004027f7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004027f9  7403                   -je 0x4027fe
    if (cpu.flags.zf)
    {
        goto L_0x004027fe;
    }
    // 004027fb  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004027fe:
    // 004027fe  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
L_0x00402801:
    // 00402801  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00402803  3bc2                   +cmp eax, edx
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
    // 00402805  75e6                   -jne 0x4027ed
    if (!cpu.flags.zf)
    {
        goto L_0x004027ed;
    }
L_0x00402807:
    // 00402807  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040280b  83c604                 +add esi, 4
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
    // 0040280e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040280f  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00402813  75c7                   -jne 0x4027dc
    if (!cpu.flags.zf)
    {
        goto L_0x004027dc;
    }
L_0x00402815:
    // 00402815  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00402818  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040281a  7403                   -je 0x40281f
    if (cpu.flags.zf)
    {
        goto L_0x0040281f;
    }
    // 0040281c  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0040281f:
    // 0040281f  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
L_0x00402822:
    // 00402822  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00402824  c7850801000000000000   -mov dword ptr [ebp + 0x108], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(264) /* 0x108 */) = 0 /*0x0*/;
    // 0040282e  e8fdf8ffff             -call 0x402130
    cpu.esp -= 4;
    sub_402130(app, cpu);
    // 00402833  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402834  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402835  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402836  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402837  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402840  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402844  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402848  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040284c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040284d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040284e  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402853  e808000000             -call 0x402860
    cpu.esp -= 4;
    sub_402860(app, cpu);
    // 00402858  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402860  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402861  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402864  8b8608010000           -mov eax, dword ptr [esi + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 0040286a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040286c  7429                   -je 0x402897
    if (cpu.flags.zf)
    {
        goto L_0x00402897;
    }
    // 0040286e  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402872  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402873  e848f8ffff             -call 0x4020c0
    cpu.esp -= 4;
    sub_4020c0(app, cpu);
    // 00402878  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040287b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040287d  747b                   -je 0x4028fa
    if (cpu.flags.zf)
    {
        goto L_0x004028fa;
    }
    // 0040287f  81ff020f0000           +cmp edi, 0xf02
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3842 /*0xf02*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402885  7417                   -je 0x40289e
    if (cpu.flags.zf)
    {
        goto L_0x0040289e;
    }
    // 00402887  81ff010f0000           +cmp edi, 0xf01
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3841 /*0xf01*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040288d  740f                   -je 0x40289e
    if (cpu.flags.zf)
    {
        goto L_0x0040289e;
    }
    // 0040288f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402890  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402892  e8f9feffff             -call 0x402790
    cpu.esp -= 4;
    sub_402790(app, cpu);
L_0x00402897:
    // 00402897  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402898  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0040289a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040289b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0040289e:
    // 0040289e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004028a2  8bbe0c010000           -mov edi, dword ptr [esi + 0x10c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004028a8  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004028ac  8b9610010000           -mov edx, dword ptr [esi + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004028b2  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004028b4  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004028b6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004028b8  899610010000           -mov dword ptr [esi + 0x110], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004028be  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004028bf  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004028c1  89be0c010000           -mov dword ptr [esi + 0x10c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edi;
    // 004028c7  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004028c9  3d96000000             +cmp eax, 0x96
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(150 /*0x96*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004028ce  7e0c                   -jle 0x4028dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004028dc;
    }
    // 004028d0  68020f0000             -push 0xf02
    app->getMemory<x86::reg32>(cpu.esp-4) = 3842 /*0xf02*/;
    cpu.esp -= 4;
    // 004028d5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004028d7  e8b4feffff             -call 0x402790
    cpu.esp -= 4;
    sub_402790(app, cpu);
L_0x004028dc:
    // 004028dc  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004028e2  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004028e3  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004028e5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004028e7  3d96000000             +cmp eax, 0x96
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(150 /*0x96*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004028ec  7e0c                   -jle 0x4028fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004028fa;
    }
    // 004028ee  68010f0000             -push 0xf01
    app->getMemory<x86::reg32>(cpu.esp-4) = 3841 /*0xf01*/;
    cpu.esp -= 4;
    // 004028f3  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004028f5  e896feffff             -call 0x402790
    cpu.esp -= 4;
    sub_402790(app, cpu);
L_0x004028fa:
    // 004028fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028fb  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004028fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028fe  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402910  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402912  8b88f0000000           -mov ecx, dword ptr [eax + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */);
    // 00402918  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040291a  7c2c                   -jl 0x402948
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00402948;
    }
    // 0040291c  39880c010000           +cmp dword ptr [eax + 0x10c], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(268) /* 0x10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402922  7e24                   -jle 0x402948
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402948;
    }
    // 00402924  8b9008010000           -mov edx, dword ptr [eax + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(264) /* 0x108 */);
    // 0040292a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040292c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0040292e  7e05                   -jle 0x402935
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402935;
    }
L_0x00402930:
    // 00402930  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00402932  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00402933  75fb                   -jne 0x402930
    if (!cpu.flags.zf)
    {
        goto L_0x00402930;
    }
L_0x00402935:
    // 00402935  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00402938  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040293a  740c                   -je 0x402948
    if (cpu.flags.zf)
    {
        goto L_0x00402948;
    }
    // 0040293c  8b88f4000000           -mov ecx, dword ptr [eax + 0xf4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(244) /* 0xf4 */);
    // 00402942  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402944  7402                   -je 0x402948
    if (cpu.flags.zf)
    {
        goto L_0x00402948;
    }
    // 00402946  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00402948:
    // 00402948  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402951  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402952  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402954  8b86fc000000           -mov eax, dword ptr [esi + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 0040295a  8b8e0c010000           -mov ecx, dword ptr [esi + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00402960  3bc1                   +cmp eax, ecx
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
    // 00402962  7d3f                   -jge 0x4029a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004029a3;
    }
    // 00402964  8b8e10010000           -mov ecx, dword ptr [esi + 0x110]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 0040296a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040296c  740b                   -je 0x402979
    if (cpu.flags.zf)
    {
        goto L_0x00402979;
    }
    // 0040296e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402970  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402973  d95c2404               +fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402977  eb08                   -jmp 0x402981
    goto L_0x00402981;
L_0x00402979:
    // 00402979  c744240400000000       -mov dword ptr [esp + 4], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x00402981:
    // 00402981  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00402985  d89e14010000           -fcomp dword ptr [esi + 0x114]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */)));
    cpu.fpu.pop();
    // 0040298b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040298d  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00402990  7507                   -jne 0x402999
    if (!cpu.flags.zf)
    {
        goto L_0x00402999;
    }
    // 00402992  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402994  e887010000             -call 0x402b20
    cpu.esp -= 4;
    sub_402b20(app, cpu);
L_0x00402999:
    // 00402999  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040299d  898614010000           -mov dword ptr [esi + 0x114], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */) = cpu.eax;
L_0x004029a3:
    // 004029a3  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004029a5  e8a6a90100             -call 0x41d350
    cpu.esp -= 4;
    sub_41d350(app, cpu);
    // 004029aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4029b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004029b0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004029b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004029b4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004029b6  8b86fc000000           -mov eax, dword ptr [esi + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 004029bc  8b8e0c010000           -mov ecx, dword ptr [esi + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004029c2  3bc1                   +cmp eax, ecx
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
    // 004029c4  7d49                   -jge 0x402a0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402a0f;
    }
    // 004029c6  8b8e10010000           -mov ecx, dword ptr [esi + 0x110]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004029cc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004029ce  7407                   -je 0x4029d7
    if (cpu.flags.zf)
    {
        goto L_0x004029d7;
    }
    // 004029d0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004029d2  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004029d5  eb06                   -jmp 0x4029dd
    goto L_0x004029dd;
L_0x004029d7:
    // 004029d7  d90580014300           -fld dword ptr [0x430180]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4391296) /* 0x430180 */)));
L_0x004029dd:
    // 004029dd  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004029e3  8b8efc000000           -mov ecx, dword ptr [esi + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 004029e9  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004029eb  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004029f3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004029f7  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004029fb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004029fd  e822310200             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 00402a02  898600010000           -mov dword ptr [esi + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 00402a08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402a09  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402a0b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402a0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402a0f:
    // 00402a0f  c7860001000000000000   -mov dword ptr [esi + 0x100], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(256) /* 0x100 */) = 0 /*0x0*/;
    // 00402a19  8b8600010000           -mov eax, dword ptr [esi + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(256) /* 0x100 */);
    // 00402a1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402a20  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402a23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402a30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402a31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402a32  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00402a34  8b870c010000           -mov eax, dword ptr [edi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(268) /* 0x10c */);
    // 00402a3a  8b97fc000000           -mov edx, dword ptr [edi + 0xfc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */);
    // 00402a40  3bd0                   +cmp edx, eax
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
    // 00402a42  0f8d9b000000           -jge 0x402ae3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402ae3;
    }
    // 00402a48  8b8f10010000           -mov ecx, dword ptr [edi + 0x110]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(272) /* 0x110 */);
    // 00402a4e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402a50  7468                   -je 0x402aba
    if (cpu.flags.zf)
    {
        goto L_0x00402aba;
    }
    // 00402a52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402a53  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402a57  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00402a59  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00402a5b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00402a5f  7d06                   -jge 0x402a67
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402a67;
    }
    // 00402a61  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00402a63  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
L_0x00402a67:
    // 00402a67  3bf0                   +cmp esi, eax
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
    // 00402a69  7e06                   -jle 0x402a71
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402a71;
    }
    // 00402a6b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00402a6d  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
L_0x00402a71:
    // 00402a71  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 00402a75  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 00402a79  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402a7b  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00402a7d  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402a81  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402a85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402a86  ff503c                 -call dword ptr [eax + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402a89  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00402a8d  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402a90  89b700010000           -mov dword ptr [edi + 0x100], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(256) /* 0x100 */) = cpu.esi;
    // 00402a96  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402a99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402a9a  6844294300             -push 0x432944
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401476 /*0x432944*/;
    cpu.esp -= 4;
    // 00402a9f  e8f0260200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00402aa4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00402aa7  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00402aa9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402aaa  e871000000             -call 0x402b20
    cpu.esp -= 4;
    sub_402b20(app, cpu);
    // 00402aaf  8b8700010000           -mov eax, dword ptr [edi + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(256) /* 0x100 */);
    // 00402ab5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ab6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ab7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00402aba:
    // 00402aba  6830294300             -push 0x432930
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401456 /*0x432930*/;
    cpu.esp -= 4;
    // 00402abf  c7870001000000000000   -mov dword ptr [edi + 0x100], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(256) /* 0x100 */) = 0 /*0x0*/;
    // 00402ac9  e8c6260200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00402ace  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402ad1  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00402ad3  e848000000             -call 0x402b20
    cpu.esp -= 4;
    sub_402b20(app, cpu);
    // 00402ad8  8b8700010000           -mov eax, dword ptr [edi + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(256) /* 0x100 */);
    // 00402ade  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402adf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ae0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00402ae3:
    // 00402ae3  c7870001000000000000   -mov dword ptr [edi + 0x100], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(256) /* 0x100 */) = 0 /*0x0*/;
    // 00402aed  8b870c010000           -mov eax, dword ptr [edi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(268) /* 0x10c */);
    // 00402af3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402af4  6810294300             -push 0x432910
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401424 /*0x432910*/;
    cpu.esp -= 4;
    // 00402af9  e896260200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00402afe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402b01  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00402b03  e818000000             -call 0x402b20
    cpu.esp -= 4;
    sub_402b20(app, cpu);
    // 00402b08  8b8700010000           -mov eax, dword ptr [edi + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(256) /* 0x100 */);
    // 00402b0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402b0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402b10  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402b20  b8284e0000             -mov eax, 0x4e28
    cpu.eax = 20008 /*0x4e28*/;
    // 00402b25  e8a62b0200             -call 0x4256d0
    cpu.esp -= 4;
    sub_4256d0(app, cpu);
    // 00402b2a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402b2b  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00402b2d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402b2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402b2f  8bb308010000           -mov esi, dword ptr [ebx + 0x108]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(264) /* 0x108 */);
    // 00402b35  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402b36  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00402b3a  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 00402b3c  c644241800             -mov byte ptr [esp + 0x18], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00402b41  e86afeffff             -call 0x4029b0
    cpu.esp -= 4;
    sub_4029b0(app, cpu);
    // 00402b46  8b8300010000           -mov eax, dword ptr [ebx + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(256) /* 0x100 */);
    // 00402b4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402b4e  7e06                   -jle 0x402b56
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402b56;
    }
L_0x00402b50:
    // 00402b50  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00402b53  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00402b54  75fa                   -jne 0x402b50
    if (!cpu.flags.zf)
    {
        goto L_0x00402b50;
    }
L_0x00402b56:
    // 00402b56  3bee                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402b58  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00402b60  0f84bd000000           -je 0x402c23
    if (cpu.flags.zf)
    {
        goto L_0x00402c23;
    }
L_0x00402b66:
    // 00402b66  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402b6a  8b8bfc000000           -mov ecx, dword ptr [ebx + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(252) /* 0xfc */);
    // 00402b70  3bc1                   +cmp eax, ecx
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
    // 00402b72  0f8dab000000           -jge 0x402c23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402c23;
    }
    // 00402b78  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402b7b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00402b7d  746c                   -je 0x402beb
    if (cpu.flags.zf)
    {
        goto L_0x00402beb;
    }
    // 00402b7f  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00402b82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402b84  7423                   -je 0x402ba9
    if (cpu.flags.zf)
    {
        goto L_0x00402ba9;
    }
    // 00402b86  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00402b8a  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402b8d  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402b8f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402b90  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00402b92  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402b94  49                     -dec ecx
    (cpu.ecx)--;
    // 00402b95  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 00402b9a  8d4c0c20               -lea ecx, [esp + ecx + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */ + cpu.ecx * 1);
    // 00402b9e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402b9f  e821260200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00402ba4  83c40c                 +add esp, 0xc
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
    // 00402ba7  eb62                   -jmp 0x402c0b
    goto L_0x00402c0b;
L_0x00402ba9:
    // 00402ba9  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00402bad  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402bb0  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402bb3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00402bb5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402bb7  49                     -dec ecx
    (cpu.ecx)--;
    // 00402bb8  6868294300             -push 0x432968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401512 /*0x432968*/;
    cpu.esp -= 4;
    // 00402bbd  8d740c20               -lea esi, [esp + ecx + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */ + cpu.ecx * 1);
    // 00402bc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402bc2  e8fe250200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00402bc7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402bca  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402bcd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402bcf  83c40c                 +add esp, 0xc
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
    // 00402bd2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00402bd4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402bd6  49                     -dec ecx
    (cpu.ecx)--;
    // 00402bd7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402bd9  7e30                   -jle 0x402c0b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402c0b;
    }
L_0x00402bdb:
    // 00402bdb  8a1406                 -mov dl, byte ptr [esi + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 00402bde  80c280                 -add dl, 0x80
    (cpu.dl) += x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00402be1  881406                 -mov byte ptr [esi + eax], dl
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dl;
    // 00402be4  40                     -inc eax
    (cpu.eax)++;
    // 00402be5  3bc1                   +cmp eax, ecx
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
    // 00402be7  7cf2                   -jl 0x402bdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00402bdb;
    }
    // 00402be9  eb20                   -jmp 0x402c0b
    goto L_0x00402c0b;
L_0x00402beb:
    // 00402beb  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00402bef  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402bf2  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402bf4  68b0284300             -push 0x4328b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401328 /*0x4328b0*/;
    cpu.esp -= 4;
    // 00402bf9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00402bfb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402bfd  49                     -dec ecx
    (cpu.ecx)--;
    // 00402bfe  8d540c1c               -lea edx, [esp + ecx + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.ecx * 1);
    // 00402c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402c03  e8bd250200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00402c08  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00402c0b:
    // 00402c0b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00402c0f  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00402c12  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402c16  41                     -inc ecx
    (cpu.ecx)++;
    // 00402c17  3be8                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402c19  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00402c1d  0f8543ffffff           -jne 0x402b66
    if (!cpu.flags.zf)
    {
        goto L_0x00402b66;
    }
L_0x00402c23:
    // 00402c23  8b83d4000000           -mov eax, dword ptr [ebx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(212) /* 0xd4 */);
    // 00402c29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402c2b  7436                   -je 0x402c63
    if (cpu.flags.zf)
    {
        goto L_0x00402c63;
    }
    // 00402c2d  8b8bc8000000           -mov ecx, dword ptr [ebx + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(200) /* 0xc8 */);
    // 00402c33  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00402c37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402c38  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402c39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402c3a  e891290200             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 00402c3f  8bbbd4000000           -mov edi, dword ptr [ebx + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(212) /* 0xd4 */);
    // 00402c45  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402c48  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402c4a  83c40c                 +add esp, 0xc
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
    // 00402c4d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00402c4f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00402c51  49                     -dec ecx
    (cpu.ecx)--;
    // 00402c52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c54  898bc4000000           -mov dword ptr [ebx + 0xc4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(196) /* 0xc4 */) = cpu.ecx;
    // 00402c5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c5c  81c4284e0000           -add esp, 0x4e28
    (cpu.esp) += x86::reg32(x86::sreg32(20008 /*0x4e28*/));
    // 00402c62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402c63:
    // 00402c63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c65  c783c400000000000000   -mov dword ptr [ebx + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
    // 00402c6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c71  81c4284e0000           -add esp, 0x4e28
    (cpu.esp) += x86::reg32(x86::sreg32(20008 /*0x4e28*/));
    // 00402c77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402c80  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00402c82  6858ef4200             -push 0x42ef58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4386648 /*0x42ef58*/;
    cpu.esp -= 4;
    // 00402c87  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00402c8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402c8e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00402c95  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00402c98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402c99  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00402c9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402c9c  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402c9e  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00402ca2  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00402ca6  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00402caa  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00402cae  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00402cb2  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00402cb8  8b8ef8000000           -mov ecx, dword ptr [esi + 0xf8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(248) /* 0xf8 */);
    // 00402cbe  3bc1                   +cmp eax, ecx
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
    // 00402cc0  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00402cc4  0f8d8f000000           -jge 0x402d59
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402d59;
    }
    // 00402cca  8b8608010000           -mov eax, dword ptr [esi + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 00402cd0  8d8e04010000           -lea ecx, [esi + 0x104]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(260) /* 0x104 */);
    // 00402cd6  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402cda  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402cdb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402cdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402cdd  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402ce1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402ce2  e889090000             -call 0x403670
    cpu.esp -= 4;
    sub_403670(app, cpu);
    // 00402ce7  8b8e08010000           -mov ecx, dword ptr [esi + 0x108]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 00402ced  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402cf0  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402cf3  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00402cf5  3bc3                   +cmp eax, ebx
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
    // 00402cf7  740b                   -je 0x402d04
    if (cpu.flags.zf)
    {
        goto L_0x00402d04;
    }
    // 00402cf9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402cfa  e847210200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00402cff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402d02  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
L_0x00402d04:
    // 00402d04  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00402d08  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402d09  e8a3c00200             -call 0x42edb1
    cpu.esp -= 4;
    sub_42edb1(app, cpu);
    // 00402d0e  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00402d12  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00402d14  8b8608010000           -mov eax, dword ptr [esi + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 00402d1a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402d1d  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00402d20  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402d22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d23  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00402d26  8a4c2434               -mov cl, byte ptr [esp + 0x34]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00402d2a  3acb                   +cmp cl, bl
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
    // 00402d2c  8b8e08010000           -mov ecx, dword ptr [esi + 0x108]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 00402d32  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00402d35  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402d38  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00402d3b  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00402d41  8b8efc000000           -mov ecx, dword ptr [esi + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(252) /* 0xfc */);
    // 00402d47  8986dc000000           -mov dword ptr [esi + 0xdc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */) = cpu.eax;
    // 00402d4d  3bc1                   +cmp eax, ecx
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
    // 00402d4f  7e15                   -jle 0x402d66
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402d66;
    }
    // 00402d51  898edc000000           -mov dword ptr [esi + 0xdc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */) = cpu.ecx;
    // 00402d57  eb0d                   -jmp 0x402d66
    goto L_0x00402d66;
L_0x00402d59:
    // 00402d59  686c294300             -push 0x43296c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401516 /*0x43296c*/;
    cpu.esp -= 4;
    // 00402d5e  e831240200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00402d63  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00402d66:
    // 00402d66  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00402d6c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00402d6e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402d6f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402d71  ff5040                 -call dword ptr [eax + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402d74  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402d76  e8a5fdffff             -call 0x402b20
    cpu.esp -= 4;
    sub_402b20(app, cpu);
    // 00402d7b  8bb6dc000000           -mov esi, dword ptr [esi + 0xdc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */);
    // 00402d81  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402d85  4e                     -dec esi
    (cpu.esi)--;
    // 00402d86  3bc3                   +cmp eax, ebx
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
    // 00402d88  7409                   -je 0x402d93
    if (cpu.flags.zf)
    {
        goto L_0x00402d93;
    }
    // 00402d8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402d8b  e8b6200200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00402d90  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00402d93:
    // 00402d93  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00402d97  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00402d99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d9b  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00402da2  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00402da5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402db0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402db4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402db5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402db6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402db7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402db8  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00402dba  83f801                 +cmp eax, 1
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
    // 00402dbd  8b9f08010000           -mov ebx, dword ptr [edi + 0x108]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(264) /* 0x108 */);
    // 00402dc3  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00402dc5  7c42                   -jl 0x402e09
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00402e09;
    }
    // 00402dc7  e8e4fbffff             -call 0x4029b0
    cpu.esp -= 4;
    sub_4029b0(app, cpu);
    // 00402dcc  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402dce  3bf3                   +cmp esi, ebx
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
    // 00402dd0  741f                   -je 0x402df1
    if (cpu.flags.zf)
    {
        goto L_0x00402df1;
    }
    // 00402dd2  8b97dc000000           -mov edx, dword ptr [edi + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(220) /* 0xdc */);
    // 00402dd8  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00402dda:
    // 00402dda  3bca                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402ddc  7d13                   -jge 0x402df1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402df1;
    }
    // 00402dde  8baf18010000           -mov ebp, dword ptr [edi + 0x118]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(280) /* 0x118 */);
    // 00402de4  03e8                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00402de6  3bcd                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402de8  7426                   -je 0x402e10
    if (cpu.flags.zf)
    {
        goto L_0x00402e10;
    }
    // 00402dea  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00402dec  41                     -inc ecx
    (cpu.ecx)++;
    // 00402ded  3bf3                   +cmp esi, ebx
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
    // 00402def  75e9                   -jne 0x402dda
    if (!cpu.flags.zf)
    {
        goto L_0x00402dda;
    }
L_0x00402df1:
    // 00402df1  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402df5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00402df9  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00402dfd  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00402e00  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00402e03  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x00402e09:
    // 00402e09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e0d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00402e10:
    // 00402e10  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00402e14  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00402e17  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00402e1b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402e1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402e1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402e1e  e8ad270200             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 00402e23  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00402e27  c6441fff00             -mov byte ptr [edi + ebx - 1], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1) = 0 /*0x0*/;
    // 00402e2c  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00402e2f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00402e32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402e34  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 00402e37  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00402e39  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00402e3c  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00402e40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e43  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00402e45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e46  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402e50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402e51  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00402e53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402e54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402e55  8bab08010000           -mov ebp, dword ptr [ebx + 0x108]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(264) /* 0x108 */);
    // 00402e5b  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 00402e5e  3bfd                   +cmp edi, ebp
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
    // 00402e60  744e                   -je 0x402eb0
    if (cpu.flags.zf)
    {
        goto L_0x00402eb0;
    }
    // 00402e62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00402e63:
    // 00402e63  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00402e65  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00402e67  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00402e6a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00402e6c  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00402e6e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00402e70  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00402e73  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00402e76  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00402e79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402e7b  7410                   -je 0x402e8d
    if (cpu.flags.zf)
    {
        goto L_0x00402e8d;
    }
    // 00402e7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402e7e  e8c31f0200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00402e83  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402e86  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00402e8d:
    // 00402e8d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402e8f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402e90  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00402e93  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00402e96  e8b02c0200             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 00402e9b  8b8b0c010000           -mov ecx, dword ptr [ebx + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(268) /* 0x10c */);
    // 00402ea1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402ea4  49                     -dec ecx
    (cpu.ecx)--;
    // 00402ea5  3bfd                   +cmp edi, ebp
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
    // 00402ea7  898b0c010000           -mov dword ptr [ebx + 0x10c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(268) /* 0x10c */) = cpu.ecx;
    // 00402ead  75b4                   -jne 0x402e63
    if (!cpu.flags.zf)
    {
        goto L_0x00402e63;
    }
    // 00402eaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00402eb0:
    // 00402eb0  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00402eb2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402eb4  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00402eb6  c783dc00000000000000   -mov dword ptr [ebx + 0xdc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(220) /* 0xdc */) = 0 /*0x0*/;
    // 00402ec0  ff5240                 -call dword ptr [edx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402ec3  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00402ec5  e856fcffff             -call 0x402b20
    cpu.esp -= 4;
    sub_402b20(app, cpu);
    // 00402eca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ecb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ecc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ecd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402ed0  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00402ed3  8a442440               -mov al, byte ptr [esp + 0x40]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00402ed7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402ed8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402ed9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402eda  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00402edc  8a819c000000           -mov al, byte ptr [ecx + 0x9c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 00402ee2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402ee3  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00402ee7  7411                   -je 0x402efa
    if (cpu.flags.zf)
    {
        goto L_0x00402efa;
    }
    // 00402ee9  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00402eeb  7408                   -je 0x402ef5
    if (cpu.flags.zf)
    {
        goto L_0x00402ef5;
    }
    // 00402eed  81c18c000000           +add ecx, 0x8c
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402ef3  eb11                   -jmp 0x402f06
    goto L_0x00402f06;
L_0x00402ef5:
    // 00402ef5  83c16c                 +add ecx, 0x6c
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402ef8  eb0c                   -jmp 0x402f06
    goto L_0x00402f06;
L_0x00402efa:
    // 00402efa  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00402efc  7405                   -je 0x402f03
    if (cpu.flags.zf)
    {
        goto L_0x00402f03;
    }
    // 00402efe  83c17c                 +add ecx, 0x7c
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(124 /*0x7c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402f01  eb03                   -jmp 0x402f06
    goto L_0x00402f06;
L_0x00402f03:
    // 00402f03  83c15c                 -add ecx, 0x5c
    (cpu.ecx) += x86::reg32(x86::sreg32(92 /*0x5c*/));
L_0x00402f06:
    // 00402f06  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402f08  8b742438               -mov esi, dword ptr [esp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00402f0c  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00402f10  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402f13  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00402f16  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00402f1a  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00402f1c  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00402f1f  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00402f23  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00402f25  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00402f29  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00402f2b  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00402f2d  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402f2f  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00402f33  3bf1                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402f35  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00402f39  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00402f3d  7d0c                   -jge 0x402f4b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402f4b;
    }
    // 00402f3f  2bce                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00402f41  03d9                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402f43  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00402f47  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00402f4b:
    // 00402f4b  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00402f4f  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00402f53  3bf1                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402f55  7d0c                   -jge 0x402f63
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402f63;
    }
    // 00402f57  2bce                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00402f59  03f9                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402f5b  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00402f5f  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00402f63:
    // 00402f63  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00402f67  3bc1                   +cmp eax, ecx
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
    // 00402f69  7e14                   -jle 0x402f7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402f7f;
    }
    // 00402f6b  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402f6d  2bf0                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00402f6f  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00402f73  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00402f75  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00402f79  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402f7b  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00402f7f:
    // 00402f7f  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00402f83  3bd1                   +cmp edx, ecx
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
    // 00402f85  7e0c                   -jle 0x402f93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402f93;
    }
    // 00402f87  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402f89  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00402f8b  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00402f8d  03ee                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 00402f8f  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x00402f93:
    // 00402f93  2b442414               -sub eax, dword ptr [esp + 0x14]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00402f97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402f99  7e49                   -jle 0x402fe4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402fe4;
    }
    // 00402f9b  2b542418               -sub edx, dword ptr [esp + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00402f9f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00402fa1  7e41                   -jle 0x402fe4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402fe4;
    }
    // 00402fa3  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00402fa7  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00402fa9  2bd3                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00402fab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00402fad  7e35                   -jle 0x402fe4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402fe4;
    }
    // 00402faf  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00402fb1  2bcf                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00402fb3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402fb5  7e2d                   -jle 0x402fe4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402fe4;
    }
    // 00402fb7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402fb9  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 00402fbe  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00402fc1  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00402fc5  8bd4                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00402fc7  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00402fc9  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00402fcc  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00402fcf  8b414c                 -mov eax, dword ptr [ecx + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 00402fd2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402fd3  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00402fd7  896a0c                 -mov dword ptr [edx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00402fda  8d5158                 -lea edx, [ecx + 0x58]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 00402fdd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402fde  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402fdf  e8bc910100             -call 0x41c1a0
    cpu.esp -= 4;
    sub_41c1a0(app, cpu);
L_0x00402fe4:
    // 00402fe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fe5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fe6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fe7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fe8  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00402feb  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::asm_sub_402ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402ff0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00402ff3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402ff4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402ff5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402ff6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402ff8  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00402ffa  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00402ffc  8b96ac000000           -mov edx, dword ptr [esi + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00403002  8b8eb4000000           -mov ecx, dword ptr [esi + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 00403008  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403009  3bcd                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040300b  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0040300d  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00403011  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00403015  744c                   -je 0x403063
    if (cpu.flags.zf)
    {
        goto L_0x00403063;
    }
    // 00403017  8b86b0000000           -mov eax, dword ptr [esi + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0040301d  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040301f  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00403023  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403026  db86cc000000           -fild dword ptr [esi + 0xcc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */))));
    // 0040302c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00403030  8b8ec4000000           -mov ecx, dword ptr [esi + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 00403036  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0040303a  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00403040  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00403044  2bc8                   +sub ecx, eax
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
    // 00403046  da4c2414               +fimul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0040304a  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0040304e  da642414               +fisub dword ptr [esp + 0x14]
    cpu.fpu.st(0) -= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00403052  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00403054  e8cb2a0200             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
    // 00403059  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040305d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00403061  eb04                   -jmp 0x403067
    goto L_0x00403067;
L_0x00403063:
    // 00403063  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x00403067:
    // 00403067  3bfa                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403069  0f8492000000           -je 0x403101
    if (cpu.flags.zf)
    {
        goto L_0x00403101;
    }
    // 0040306f  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
L_0x00403075:
    // 00403075  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00403078  3b4c2414               +cmp ecx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040307c  7f15                   -jg 0x403093
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403093;
    }
    // 0040307e  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00403080  45                     -inc ebp
    (cpu.ebp)++;
    // 00403081  3bfa                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403083  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00403085  75ee                   -jne 0x403075
    if (!cpu.flags.zf)
    {
        goto L_0x00403075;
    }
    // 00403087  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0040308b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040308c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040308d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040308e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040308f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403092  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403093:
    // 00403093  3bfa                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403095  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00403099  7466                   -je 0x403101
    if (cpu.flags.zf)
    {
        goto L_0x00403101;
    }
    // 0040309b  2b5c2414               -sub ebx, dword ptr [esp + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
L_0x0040309f:
    // 0040309f  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 004030a5  8b8ed8000000           -mov ecx, dword ptr [esi + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */);
    // 004030ab  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004030ad  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004030af  3be9                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004030b1  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 004030b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004030b5  8d8eb8000000           -lea ecx, [esi + 0xb8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 004030bb  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004030be  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 004030c0  8bd4                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004030c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004030c3  8b86d0000000           -mov eax, dword ptr [esi + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 004030c9  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004030cb  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004030ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004030cf  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004030d2  8b6908                 -mov ebp, dword ptr [ecx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004030d5  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004030d8  896a08                 -mov dword ptr [edx + 8], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004030db  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004030de  8d4f08                 -lea ecx, [edi + 8]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004030e1  e8eafdffff             -call 0x402ed0
    cpu.esp -= 4;
    sub_402ed0(app, cpu);
    // 004030e6  8b96cc000000           -mov edx, dword ptr [esi + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 004030ec  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004030f0  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004030f2  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004030f6  03da                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004030f8  45                     -inc ebp
    (cpu.ebp)++;
    // 004030f9  3bf8                   +cmp edi, eax
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
    // 004030fb  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004030ff  759e                   -jne 0x40309f
    if (!cpu.flags.zf)
    {
        goto L_0x0040309f;
    }
L_0x00403101:
    // 00403101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403102  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403103  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403104  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403105  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403108  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403110  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00403112  687bef4200             -push 0x42ef7b
    app->getMemory<x86::reg32>(cpu.esp-4) = 4386683 /*0x42ef7b*/;
    cpu.esp -= 4;
    // 00403117  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0040311d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040311e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00403125  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0040312b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040312c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040312d  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040312f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403131  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403132  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00403136  8b8ec8000000           -mov ecx, dword ptr [esi + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */);
    // 0040313c  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00403140  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00403142  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00403146  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040314a  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 00403150  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00403152  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00403156  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 0040315a  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0040315e  8d3c00                 -lea edi, [eax + eax]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00403161  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00403165  894c2454               -mov dword ptr [esp + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 00403169  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0040316d  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 00403171  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00403175  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00403179  897c2430               -mov dword ptr [esp + 0x30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edi;
    // 0040317d  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00403181  8bbc2428010000         -mov edi, dword ptr [esp + 0x128]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00403188  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0040318c  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00403190  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00403194  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00403196  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 0040319a  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040319e  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 004031a1  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004031a5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004031a7  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004031ab  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004031af  896c243c               -mov dword ptr [esp + 0x3c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebp;
    // 004031b3  89542444               -mov dword ptr [esp + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 004031b7  894c2448               -mov dword ptr [esp + 0x48], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ecx;
    // 004031bb  7502                   -jne 0x4031bf
    if (!cpu.flags.zf)
    {
        goto L_0x004031bf;
    }
    // 004031bd  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004031bf:
    // 004031bf  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004031c3  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004031c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004031c7  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004031cb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004031cc  8d542444               -lea edx, [esp + 0x44]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004031d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004031d1  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004031d4  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004031d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004031d9  8b94242c010000         -mov edx, dword ptr [esp + 0x12c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004031e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004031e1  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004031e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004031e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004031e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004031e8  8d4c247c               -lea ecx, [esp + 0x7c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004031ec  e89f920100             -call 0x41c490
    cpu.esp -= 4;
    sub_41c490(app, cpu);
    // 004031f1  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 004031f8  c744245ce4014300       -mov dword ptr [esp + 0x5c], 0x4301e4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 4391396 /*0x4301e4*/;
    // 00403200  8baeac000000           -mov ebp, dword ptr [esi + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00403206  8dbea8000000           -lea edi, [esi + 0xa8]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0040320c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0040320e  c784241401000000000000 -mov dword ptr [esp + 0x114], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = 0 /*0x0*/;
    // 00403219  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0040321c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040321d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040321e  e8fd040000             -call 0x403720
    cpu.esp -= 4;
    sub_403720(app, cpu);
    // 00403223  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00403226  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00403229  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0040322b  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0040322f  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403232  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403233  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403234  e887050000             -call 0x4037c0
    cpu.esp -= 4;
    sub_4037c0(app, cpu);
    // 00403239  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0040323c  8b842408010000         -mov eax, dword ptr [esp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00403243  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403246  42                     -inc edx
    (cpu.edx)++;
    // 00403247  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403249  895708                 -mov dword ptr [edi + 8], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0040324c  c7842414010000ffffffff -mov dword ptr [esp + 0x114], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = 4294967295 /*0xffffffff*/;
    // 00403257  c744245cb4014300       -mov dword ptr [esp + 0x5c], 0x4301b4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 4391348 /*0x4301b4*/;
    // 0040325f  c78424fc00000000000000 -mov dword ptr [esp + 0xfc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = 0 /*0x0*/;
    // 0040326a  7409                   -je 0x403275
    if (cpu.flags.zf)
    {
        goto L_0x00403275;
    }
    // 0040326c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040326d  e8d41b0200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00403272  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00403275:
    // 00403275  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00403279  c744245c84014300       -mov dword ptr [esp + 0x5c], 0x430184
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 4391300 /*0x430184*/;
    // 00403281  e8ca030000             -call 0x403650
    cpu.esp -= 4;
    sub_403650(app, cpu);
    // 00403286  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0040328a  e8a1030000             -call 0x403630
    cpu.esp -= 4;
    sub_403630(app, cpu);
    // 0040328f  8b96ac000000           -mov edx, dword ptr [esi + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00403295  8a842424010000         -mov al, byte ptr [esp + 0x124]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0040329c  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040329f  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004032a2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004032a4  742b                   -je 0x4032d1
    if (cpu.flags.zf)
    {
        goto L_0x004032d1;
    }
    // 004032a6  8b87a0000000           -mov eax, dword ptr [edi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(160) /* 0xa0 */);
    // 004032ac  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004032ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004032b0  7e1f                   -jle 0x4032d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004032d1;
    }
L_0x004032b2:
    // 004032b2  8b87a4000000           -mov eax, dword ptr [edi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(164) /* 0xa4 */);
    // 004032b8  8b0ca8                 -mov ecx, dword ptr [eax + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 4);
    // 004032bb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004032bd  7407                   -je 0x4032c6
    if (cpu.flags.zf)
    {
        goto L_0x004032c6;
    }
    // 004032bf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004032c1  e88a040000             -call 0x403750
    cpu.esp -= 4;
    sub_403750(app, cpu);
L_0x004032c6:
    // 004032c6  8b87a0000000           -mov eax, dword ptr [edi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(160) /* 0xa0 */);
    // 004032cc  45                     -inc ebp
    (cpu.ebp)++;
    // 004032cd  3be8                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004032cf  7ce1                   -jl 0x4032b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004032b2;
    }
L_0x004032d1:
    // 004032d1  8a8c2424010000         -mov cl, byte ptr [esp + 0x124]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004032d8  888f9c000000           -mov byte ptr [edi + 0x9c], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(156) /* 0x9c */) = cpu.cl;
    // 004032de  8b96ac000000           -mov edx, dword ptr [esi + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 004032e4  8b8c2420010000         -mov ecx, dword ptr [esp + 0x120]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004032eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004032ec  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004032ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004032f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004032f1  8988b4000000           -mov dword ptr [eax + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 004032f7  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004032fe  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00403305  81c40c010000           -add esp, 0x10c
    (cpu.esp) += x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 0040330b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_403310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403310  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403311  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00403313  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 00403319  c706b4014300           -mov dword ptr [esi], 0x4301b4
    app->getMemory<x86::reg32>(cpu.esi) = 4391348 /*0x4301b4*/;
    // 0040331f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403321  c786a000000000000000   -mov dword ptr [esi + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0040332b  7409                   -je 0x403336
    if (cpu.flags.zf)
    {
        goto L_0x00403336;
    }
    // 0040332d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040332e  e8131b0200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00403333  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00403336:
    // 00403336  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00403339  c70684014300           -mov dword ptr [esi], 0x430184
    app->getMemory<x86::reg32>(cpu.esi) = 4391300 /*0x430184*/;
    // 0040333f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403341  740d                   -je 0x403350
    if (cpu.flags.zf)
    {
        goto L_0x00403350;
    }
    // 00403343  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403345  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403346  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403349  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
L_0x00403350:
    // 00403350  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00403353  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403355  740d                   -je 0x403364
    if (cpu.flags.zf)
    {
        goto L_0x00403364;
    }
    // 00403357  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403359  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040335a  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040335d  c7464400000000         -mov dword ptr [esi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
L_0x00403364:
    // 00403364  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403365  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403370  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00403373  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403374  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403375  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403376  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00403378  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403379  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040337b  8baeac000000           -mov ebp, dword ptr [esi + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00403381  8b8eb4000000           -mov ecx, dword ptr [esi + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 00403387  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00403389  3bc8                   +cmp ecx, eax
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
    // 0040338b  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0040338e  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00403392  7442                   -je 0x4033d6
    if (cpu.flags.zf)
    {
        goto L_0x004033d6;
    }
    // 00403394  8b86b0000000           -mov eax, dword ptr [esi + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0040339a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040339c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004033a0  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033a3  db86cc000000           -fild dword ptr [esi + 0xcc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */))));
    // 004033a9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004033ad  8b8ec4000000           -mov ecx, dword ptr [esi + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 004033b3  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004033b7  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 004033bd  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004033c1  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004033c3  da4c2414               -fimul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004033c7  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004033cb  da642414               -fisub dword ptr [esp + 0x14]
    cpu.fpu.st(0) -= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004033cf  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004033d1  e84e270200             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
L_0x004033d6:
    // 004033d6  3bdd                   +cmp ebx, ebp
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
    // 004033d8  746d                   -je 0x403447
    if (cpu.flags.zf)
    {
        goto L_0x00403447;
    }
    // 004033da  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 004033e0  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004033e4  2bc8                   +sub ecx, eax
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
    // 004033e6  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004033ea  eb04                   -jmp 0x4033f0
    goto L_0x004033f0;
L_0x004033ec:
    // 004033ec  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x004033f0:
    // 004033f0  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004033f2  3bca                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004033f4  7f1a                   -jg 0x403410
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403410;
    }
    // 004033f6  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 004033fc  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 00403402  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00403404  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00403406  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0040340a  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0040340c  3bca                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040340e  7f23                   -jg 0x403433
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403433;
    }
L_0x00403410:
    // 00403410  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403414  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00403416  41                     -inc ecx
    (cpu.ecx)++;
    // 00403417  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0040341b  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 00403421  03f9                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00403423  3bdd                   +cmp ebx, ebp
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
    // 00403425  75c5                   -jne 0x4033ec
    if (!cpu.flags.zf)
    {
        goto L_0x004033ec;
    }
    // 00403427  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403429  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00403430  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403433:
    // 00403433  8a83a4000000           -mov al, byte ptr [ebx + 0xa4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(164) /* 0xa4 */);
    // 00403439  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040343b  740a                   -je 0x403447
    if (cpu.flags.zf)
    {
        goto L_0x00403447;
    }
    // 0040343d  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403441  8996d8000000           -mov dword ptr [esi + 0xd8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */) = cpu.edx;
L_0x00403447:
    // 00403447  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403449  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040344a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040344b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040344c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040344d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00403450  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_403460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403460  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00403463  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403464  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403465  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403466  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00403468  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403469  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040346b  8baeac000000           -mov ebp, dword ptr [esi + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00403471  8b8eb4000000           -mov ecx, dword ptr [esi + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */);
    // 00403477  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00403479  3bc8                   +cmp ecx, eax
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
    // 0040347b  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0040347e  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00403482  7442                   -je 0x4034c6
    if (cpu.flags.zf)
    {
        goto L_0x004034c6;
    }
    // 00403484  8b86b0000000           -mov eax, dword ptr [esi + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0040348a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040348c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00403490  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403493  db86cc000000           -fild dword ptr [esi + 0xcc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */))));
    // 00403499  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040349d  8b8ec4000000           -mov ecx, dword ptr [esi + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 004034a3  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004034a7  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 004034ad  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004034b1  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004034b3  da4c2414               -fimul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004034b7  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004034bb  da642414               -fisub dword ptr [esp + 0x14]
    cpu.fpu.st(0) -= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004034bf  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004034c1  e85e260200             -call 0x425b24
    cpu.esp -= 4;
    sub_425b24(app, cpu);
L_0x004034c6:
    // 004034c6  3bdd                   +cmp ebx, ebp
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
    // 004034c8  744d                   -je 0x403517
    if (cpu.flags.zf)
    {
        goto L_0x00403517;
    }
    // 004034ca  8b8ed4000000           -mov ecx, dword ptr [esi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 004034d0  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004034d4  2bc8                   +sub ecx, eax
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
    // 004034d6  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004034da  eb04                   -jmp 0x4034e0
    goto L_0x004034e0;
L_0x004034dc:
    // 004034dc  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x004034e0:
    // 004034e0  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004034e2  3bca                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004034e4  7f1a                   -jg 0x403500
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403500;
    }
    // 004034e6  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 004034ec  8b96d4000000           -mov edx, dword ptr [esi + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 004034f2  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004034f4  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004034f6  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004034fa  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004034fc  3bca                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004034fe  7f23                   -jg 0x403523
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403523;
    }
L_0x00403500:
    // 00403500  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403504  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00403506  41                     -inc ecx
    (cpu.ecx)++;
    // 00403507  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0040350b  8b8ecc000000           -mov ecx, dword ptr [esi + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 00403511  03f9                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00403513  3bdd                   +cmp ebx, ebp
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
    // 00403515  75c5                   -jne 0x4034dc
    if (!cpu.flags.zf)
    {
        goto L_0x004034dc;
    }
L_0x00403517:
    // 00403517  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403519  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040351a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040351b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040351c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040351d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00403520  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403523:
    // 00403523  8a83a4000000           -mov al, byte ptr [ebx + 0xa4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(164) /* 0xa4 */);
    // 00403529  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040352b  74ea                   -je 0x403517
    if (cpu.flags.zf)
    {
        goto L_0x00403517;
    }
    // 0040352d  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403531  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00403533  8996d8000000           -mov dword ptr [esi + 0xd8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */) = cpu.edx;
    // 00403539  e862000000             -call 0x4035a0
    cpu.esp -= 4;
    sub_4035a0(app, cpu);
    // 0040353e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040353f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403540  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403541  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403542  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00403545  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_403550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403550  8b91ac000000           -mov edx, dword ptr [ecx + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00403556  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403557  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403558  8bb9d8000000           -mov edi, dword ptr [ecx + 0xd8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0040355e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00403560  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00403562  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00403564  7c25                   -jl 0x40358b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040358b;
    }
    // 00403566  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403567  8b99b0000000           -mov ebx, dword ptr [ecx + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0040356d  3bfb                   +cmp edi, ebx
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
    // 0040356f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403570  7319                   -jae 0x40358b
    if (!cpu.flags.cf)
    {
        goto L_0x0040358b;
    }
    // 00403572  3bc2                   +cmp eax, edx
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
    // 00403574  7415                   -je 0x40358b
    if (cpu.flags.zf)
    {
        goto L_0x0040358b;
    }
L_0x00403576:
    // 00403576  3bf7                   +cmp esi, edi
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
    // 00403578  750a                   -jne 0x403584
    if (!cpu.flags.zf)
    {
        goto L_0x00403584;
    }
    // 0040357a  8a88a4000000           -mov cl, byte ptr [eax + 0xa4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 00403580  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00403582  750c                   -jne 0x403590
    if (!cpu.flags.zf)
    {
        goto L_0x00403590;
    }
L_0x00403584:
    // 00403584  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00403586  46                     -inc esi
    (cpu.esi)++;
    // 00403587  3bc2                   +cmp eax, edx
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
    // 00403589  75eb                   -jne 0x403576
    if (!cpu.flags.zf)
    {
        goto L_0x00403576;
    }
L_0x0040358b:
    // 0040358b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040358c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040358e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040358f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403590:
    // 00403590  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403591  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403594  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403595  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4035a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004035a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004035a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004035a3  e8a8ffffff             -call 0x403550
    cpu.esp -= 4;
    sub_403550(app, cpu);
    // 004035a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004035aa  7407                   -je 0x4035b3
    if (cpu.flags.zf)
    {
        goto L_0x004035b3;
    }
    // 004035ac  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004035ae  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004035b0  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004035b3:
    // 004035b3  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004035b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4035c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004035c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4035d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004035d0  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004035d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004035d5  7502                   -jne 0x4035d9
    if (!cpu.flags.zf)
    {
        goto L_0x004035d9;
    }
    // 004035d7  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004035d9:
    // 004035d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4035e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004035e0  8b4138                 -mov eax, dword ptr [ecx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004035e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004035e5  7502                   -jne 0x4035e9
    if (!cpu.flags.zf)
    {
        goto L_0x004035e9;
    }
    // 004035e7  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004035e9:
    // 004035e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4035f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004035f0  8b413c                 -mov eax, dword ptr [ecx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004035f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004035f5  7502                   -jne 0x4035f9
    if (!cpu.flags.zf)
    {
        goto L_0x004035f9;
    }
    // 004035f7  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004035f9:
    // 004035f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403600  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00403603  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403605  7502                   -jne 0x403609
    if (!cpu.flags.zf)
    {
        goto L_0x00403609;
    }
    // 00403607  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00403609:
    // 00403609  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403610  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403612  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_403620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403620  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00403622  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403625  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_403630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403630  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403631  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00403633  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00403636  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403638  740d                   -je 0x403647
    if (cpu.flags.zf)
    {
        goto L_0x00403647;
    }
    // 0040363a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040363c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040363d  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403640  c7464400000000         -mov dword ptr [esi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
L_0x00403647:
    // 00403647  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403648  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403651  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00403653  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00403656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403658  740d                   -je 0x403667
    if (cpu.flags.zf)
    {
        goto L_0x00403667;
    }
    // 0040365a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040365c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040365d  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403660  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
L_0x00403667:
    // 00403667  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403668  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403671  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403672  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403676  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403677  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00403679  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0040367b  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0040367e  e8d3240200             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 00403683  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403686  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00403688  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040368a  7502                   -jne 0x40368e
    if (!cpu.flags.zf)
    {
        goto L_0x0040368e;
    }
    // 0040368c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0040368e:
    // 0040368e  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00403690  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00403692  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00403694  7502                   -jne 0x403698
    if (!cpu.flags.zf)
    {
        goto L_0x00403698;
    }
    // 00403696  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00403698:
    // 00403698  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0040369b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0040369e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004036a1  8d7808                 -lea edi, [eax + 8]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004036a4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004036a6  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004036a8  740b                   -je 0x4036b5
    if (cpu.flags.zf)
    {
        goto L_0x004036b5;
    }
    // 004036aa  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004036ae  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 004036b3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004036b5:
    // 004036b5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004036b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036b9  41                     -inc ecx
    (cpu.ecx)++;
    // 004036ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036bb  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004036be  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004036c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036c3  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004036c5  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004036c7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4036d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004036d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004036d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004036d2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004036d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004036d5  8a8e9c000000           -mov cl, byte ptr [esi + 0x9c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */);
    // 004036db  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004036dd  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 004036e0  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004036e2  742b                   -je 0x40370f
    if (cpu.flags.zf)
    {
        goto L_0x0040370f;
    }
    // 004036e4  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 004036ea  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004036ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004036ee  7e1f                   -jle 0x40370f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040370f;
    }
L_0x004036f0:
    // 004036f0  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 004036f6  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 004036f9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004036fb  7407                   -je 0x403704
    if (cpu.flags.zf)
    {
        goto L_0x00403704;
    }
    // 004036fd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004036ff  e84c000000             -call 0x403750
    cpu.esp -= 4;
    sub_403750(app, cpu);
L_0x00403704:
    // 00403704  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 0040370a  47                     -inc edi
    (cpu.edi)++;
    // 0040370b  3bf8                   +cmp edi, eax
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
    // 0040370d  7ce1                   -jl 0x4036f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004036f0;
    }
L_0x0040370f:
    // 0040370f  889e9c000000           -mov byte ptr [esi + 0x9c], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.bl;
    // 00403715  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403717  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403718  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403719  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040371a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403720  68b8000000             -push 0xb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 184 /*0xb8*/;
    cpu.esp -= 4;
    // 00403725  e82c240200             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 0040372a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040372e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403731  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403733  7502                   -jne 0x403737
    if (!cpu.flags.zf)
    {
        goto L_0x00403737;
    }
    // 00403735  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00403737:
    // 00403737  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00403739  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040373d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040373f  7406                   -je 0x403747
    if (cpu.flags.zf)
    {
        goto L_0x00403747;
    }
    // 00403741  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00403744  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403747:
    // 00403747  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0040374a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_403750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403751  8a5c2408               -mov bl, byte ptr [esp + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00403755  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403756  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403757  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00403759  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040375b  742b                   -je 0x403788
    if (cpu.flags.zf)
    {
        goto L_0x00403788;
    }
    // 0040375d  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 00403763  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00403765  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403767  7e1f                   -jle 0x403788
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00403788;
    }
L_0x00403769:
    // 00403769  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0040376f  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 00403772  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403774  7407                   -je 0x40377d
    if (cpu.flags.zf)
    {
        goto L_0x0040377d;
    }
    // 00403776  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403778  e8d3ffffff             -call 0x403750
    cpu.esp -= 4;
    sub_403750(app, cpu);
L_0x0040377d:
    // 0040377d  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 00403783  47                     -inc edi
    (cpu.edi)++;
    // 00403784  3bf8                   +cmp edi, eax
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
    // 00403786  7ce1                   -jl 0x403769
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403769;
    }
L_0x00403788:
    // 00403788  889e9c000000           -mov byte ptr [esi + 0x9c], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(156) /* 0x9c */) = cpu.bl;
    // 0040378e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040378f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403790  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403791  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4037a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004037a0  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 004037a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004037a8  740a                   -je 0x4037b4
    if (cpu.flags.zf)
    {
        goto L_0x004037b4;
    }
    // 004037aa  8a919c000000           -mov dl, byte ptr [ecx + 0x9c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 004037b0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004037b2  7502                   -jne 0x4037b6
    if (!cpu.flags.zf)
    {
        goto L_0x004037b6;
    }
L_0x004037b4:
    // 004037b4  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004037b6:
    // 004037b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4037c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004037c0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004037c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004037c6  0f8472010000           -je 0x40393e
    if (cpu.flags.zf)
    {
        goto L_0x0040393e;
    }
    // 004037cc  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004037d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004037d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004037d2  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004037d5  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004037d8  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004037db  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004037de  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004037e1  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004037e4  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004037e7  8d5110                 -lea edx, [ecx + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004037ea  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004037ed  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004037ef  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004037f2  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004037f5  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004037f8  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004037fb  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004037fe  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00403801  8d5120                 -lea edx, [ecx + 0x20]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00403804  8d7020                 -lea esi, [eax + 0x20]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00403807  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00403809  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0040380b  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040380e  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00403811  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00403814  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00403817  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0040381a  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0040381d  8a5130                 -mov dl, byte ptr [ecx + 0x30]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 00403820  885030                 -mov byte ptr [eax + 0x30], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.dl;
    // 00403823  c700a4024300           -mov dword ptr [eax], 0x4302a4
    app->getMemory<x86::reg32>(cpu.eax) = 4391588 /*0x4302a4*/;
    // 00403829  8b5134                 -mov edx, dword ptr [ecx + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0040382c  8d705c                 -lea esi, [eax + 0x5c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0040382f  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00403832  8b5138                 -mov edx, dword ptr [ecx + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 00403835  895038                 -mov dword ptr [eax + 0x38], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 00403838  8b513c                 -mov edx, dword ptr [ecx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 0040383b  89503c                 -mov dword ptr [eax + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0040383e  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00403841  895040                 -mov dword ptr [eax + 0x40], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00403844  c70074024300           -mov dword ptr [eax], 0x430274
    app->getMemory<x86::reg32>(cpu.eax) = 4391540 /*0x430274*/;
    // 0040384a  8b5144                 -mov edx, dword ptr [ecx + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0040384d  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 00403850  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00403853  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00403856  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 00403859  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0040385c  8b5150                 -mov edx, dword ptr [ecx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0040385f  895050                 -mov dword ptr [eax + 0x50], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 00403862  8b5154                 -mov edx, dword ptr [ecx + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 00403865  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00403868  c70084014300           -mov dword ptr [eax], 0x430184
    app->getMemory<x86::reg32>(cpu.eax) = 4391300 /*0x430184*/;
    // 0040386e  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 00403871  895058                 -mov dword ptr [eax + 0x58], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 00403874  8d515c                 -lea edx, [ecx + 0x5c]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 00403877  8b795c                 -mov edi, dword ptr [ecx + 0x5c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 0040387a  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0040387c  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040387f  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00403882  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00403885  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00403888  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0040388b  c70044024300           -mov dword ptr [eax], 0x430244
    app->getMemory<x86::reg32>(cpu.eax) = 4391492 /*0x430244*/;
    // 00403891  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00403894  8d516c                 -lea edx, [ecx + 0x6c]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(108) /* 0x6c */);
    // 00403897  8d706c                 -lea esi, [eax + 0x6c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 0040389a  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0040389c  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0040389e  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004038a1  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004038a4  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004038a7  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004038aa  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004038ad  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004038b0  8d517c                 -lea edx, [ecx + 0x7c]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 004038b3  8d707c                 -lea esi, [eax + 0x7c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(124) /* 0x7c */);
    // 004038b6  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004038b8  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004038ba  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004038bd  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004038c0  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004038c3  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004038c6  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004038c9  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004038cc  8d918c000000           -lea edx, [ecx + 0x8c]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 004038d2  8db08c000000           -lea esi, [eax + 0x8c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 004038d8  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004038da  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004038dc  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004038df  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004038e2  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004038e5  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004038e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004038e9  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004038ec  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004038ef  8a919c000000           -mov dl, byte ptr [ecx + 0x9c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 004038f5  88909c000000           -mov byte ptr [eax + 0x9c], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(156) /* 0x9c */) = cpu.dl;
    // 004038fb  8b91a0000000           -mov edx, dword ptr [ecx + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 00403901  8990a0000000           -mov dword ptr [eax + 0xa0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 00403907  8b91a4000000           -mov edx, dword ptr [ecx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0040390d  8990a4000000           -mov dword ptr [eax + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.edx;
    // 00403913  c700b4014300           -mov dword ptr [eax], 0x4301b4
    app->getMemory<x86::reg32>(cpu.eax) = 4391348 /*0x4301b4*/;
    // 00403919  8b91a8000000           -mov edx, dword ptr [ecx + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0040391f  c70014024300           -mov dword ptr [eax], 0x430214
    app->getMemory<x86::reg32>(cpu.eax) = 4391444 /*0x430214*/;
    // 00403925  8990a8000000           -mov dword ptr [eax + 0xa8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.edx;
    // 0040392b  8b89ac000000           -mov ecx, dword ptr [ecx + 0xac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00403931  8988ac000000           -mov dword ptr [eax + 0xac], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = cpu.ecx;
    // 00403937  c700e4014300           -mov dword ptr [eax], 0x4301e4
    app->getMemory<x86::reg32>(cpu.eax) = 4391396 /*0x4301e4*/;
    // 0040393d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040393e:
    // 0040393e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403940  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00403942  ff20                   -jmp dword ptr [eax]
    return app->dynamic_call(app->getMemory<x86::reg32>(cpu.eax), cpu);
}

/* align: skip  */
void Application::asm_sub_403950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403950  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403951  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00403953  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403954  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00403956  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00403958  3bc7                   +cmp eax, edi
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
    // 0040395a  740b                   -je 0x403967
    if (cpu.flags.zf)
    {
        goto L_0x00403967;
    }
    // 0040395c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040395d  e8e4140200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00403962  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403965  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
L_0x00403967:
    // 00403967  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0040396a  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0040396d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040396e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040396f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403970  81ece0000000           -sub esp, 0xe0
    (cpu.esp) -= x86::reg32(x86::sreg32(224 /*0xe0*/));
    // 00403976  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403977  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403978  8bac24ec000000         -mov ebp, dword ptr [esp + 0xec]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */);
    // 0040397f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00403981  0f84d4000000           -je 0x403a5b
    if (cpu.flags.zf)
    {
        goto L_0x00403a5b;
    }
    // 00403987  8b9c24f0000000         -mov ebx, dword ptr [esp + 0xf0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 0040398e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00403990  0f84c5000000           -je 0x403a5b
    if (cpu.flags.zf)
    {
        goto L_0x00403a5b;
    }
    // 00403996  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00403999  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040399a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040399b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040399c  ff506c                 -call dword ptr [eax + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040399f  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004039a1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004039a2  ff516c                 -call dword ptr [ecx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004039a5  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004039a8  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004039ac  b91b000000             -mov ecx, 0x1b
    cpu.ecx = 27 /*0x1b*/;
    // 004039b1  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004039b5  8dbc2484000000         -lea edi, [esp + 0x84]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004039bc  c74424186c000000       -mov dword ptr [esp + 0x18], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 108 /*0x6c*/;
    // 004039c4  c744241c06000000       -mov dword ptr [esp + 0x1c], 6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 6 /*0x6*/;
    // 004039cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004039cd  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004039cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004039d0  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004039d3  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004039d5  8d942484000000         -lea edx, [esp + 0x84]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004039dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004039dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004039de  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004039e1  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004039e4  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004039e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004039e9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004039ea  ff5044                 -call dword ptr [eax + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004039ed  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004039ef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004039f1  755b                   -jne 0x403a4e
    if (!cpu.flags.zf)
    {
        goto L_0x00403a4e;
    }
    // 004039f3  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004039f5  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004039f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004039fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004039fb  ff5244                 -call dword ptr [edx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004039fe  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403a00  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00403a02  753e                   -jne 0x403a42
    if (!cpu.flags.zf)
    {
        goto L_0x00403a42;
    }
    // 00403a04  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00403a0b  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00403a12  682000cc00             -push 0xcc0020
    app->getMemory<x86::reg32>(cpu.esp-4) = 13369376 /*0xcc0020*/;
    cpu.esp -= 4;
    // 00403a17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403a18  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00403a1c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403a1d  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00403a21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403a22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403a23  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00403a27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403a28  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00403a2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403a2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403a2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403a2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403a30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403a31  ff1514004300           -call dword ptr [0x430014]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390932) /* 0x430014 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403a37  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00403a3b  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00403a3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403a3e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403a3f  ff5168                 -call dword ptr [ecx + 0x68]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00403a42:
    // 00403a42  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403a46  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00403a49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403a4a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403a4b  ff5068                 -call dword ptr [eax + 0x68]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00403a4e:
    // 00403a4e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403a50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403a51  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403a52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403a53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403a54  81c4e0000000           -add esp, 0xe0
    (cpu.esp) += x86::reg32(x86::sreg32(224 /*0xe0*/));
    // 00403a5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403a5b:
    // 00403a5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403a5c  b805400080             -mov eax, 0x80004005
    cpu.eax = 2147500037 /*0x80004005*/;
    // 00403a61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403a62  81c4e0000000           -add esp, 0xe0
    (cpu.esp) += x86::reg32(x86::sreg32(224 /*0xe0*/));
    // 00403a68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403a70  81ec64020000           -sub esp, 0x264
    (cpu.esp) -= x86::reg32(x86::sreg32(612 /*0x264*/));
    // 00403a76  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00403a79  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00403a7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403a7c  8bb42470020000         -mov esi, dword ptr [esp + 0x270]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(624) /* 0x270 */);
    // 00403a83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403a84  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00403a86  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00403a88  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00403a8a  49                     -dec ecx
    (cpu.ecx)--;
    // 00403a8b  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403a8e  7619                   -jbe 0x403aa9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00403aa9;
    }
    // 00403a90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403a91  68a82a4300             -push 0x432aa8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401832 /*0x432aa8*/;
    cpu.esp -= 4;
    // 00403a96  e8f9160200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00403a9b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403a9e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403aa0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403aa1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403aa2  81c464020000           -add esp, 0x264
    (cpu.esp) += x86::reg32(x86::sreg32(612 /*0x264*/));
    // 00403aa8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403aa9:
    // 00403aa9  68a02a4300             -push 0x432aa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401824 /*0x432aa0*/;
    cpu.esp -= 4;
    // 00403aae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403aaf  e8bc200200             -call 0x425b70
    cpu.esp -= 4;
    sub_425b70(app, cpu);
    // 00403ab4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403ab7  3bc6                   +cmp eax, esi
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
    // 00403ab9  753d                   -jne 0x403af8
    if (!cpu.flags.zf)
    {
        goto L_0x00403af8;
    }
    // 00403abb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403abc  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00403ac0  68982a4300             -push 0x432a98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401816 /*0x432a98*/;
    cpu.esp -= 4;
    // 00403ac5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403ac6  e8fa160200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00403acb  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00403acf  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00403ad3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403ad4  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00403ad8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403ad9  8b942484020000         -mov edx, dword ptr [esp + 0x284]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */);
    // 00403ae0  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00403ae4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403ae5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403ae6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403ae7  e8c4deffff             -call 0x4019b0
    cpu.esp -= 4;
    sub_4019b0(app, cpu);
    // 00403aec  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00403aef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403af0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403af1  81c464020000           -add esp, 0x264
    (cpu.esp) += x86::reg32(x86::sreg32(612 /*0x264*/));
    // 00403af7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403af8:
    // 00403af8  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00403afc  68842a4300             -push 0x432a84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401796 /*0x432a84*/;
    cpu.esp -= 4;
    // 00403b01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403b02  e8be160200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00403b07  8bbc2478020000         -mov edi, dword ptr [esp + 0x278]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */);
    // 00403b0e  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00403b12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403b13  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403b15  e8c6d9ffff             -call 0x4014e0
    cpu.esp -= 4;
    sub_4014e0(app, cpu);
    // 00403b1a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00403b1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403b1f  757b                   -jne 0x403b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00403b9c;
    }
    // 00403b21  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00403b25  68842a4300             -push 0x432a84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401796 /*0x432a84*/;
    cpu.esp -= 4;
    // 00403b2a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403b2b  e895160200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00403b30  6894294300             -push 0x432994
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401556 /*0x432994*/;
    cpu.esp -= 4;
    // 00403b35  8d84244c010000         -lea eax, [esp + 0x14c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 00403b3c  687c2a4300             -push 0x432a7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401788 /*0x432a7c*/;
    cpu.esp -= 4;
    // 00403b41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403b42  e87e160200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00403b47  8d8c2454010000         -lea ecx, [esp + 0x154]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 00403b4e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403b4f  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00403b53  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403b54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403b55  e8a6d4ffff             -call 0x401000
    cpu.esp -= 4;
    sub_401000(app, cpu);
    // 00403b5a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00403b5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403b5f  7519                   -jne 0x403b7a
    if (!cpu.flags.zf)
    {
        goto L_0x00403b7a;
    }
    // 00403b61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403b62  685c2a4300             -push 0x432a5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401756 /*0x432a5c*/;
    cpu.esp -= 4;
    // 00403b67  e828160200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00403b6c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403b6f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403b71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b73  81c464020000           -add esp, 0x264
    (cpu.esp) += x86::reg32(x86::sreg32(612 /*0x264*/));
    // 00403b79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403b7a:
    // 00403b7a  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00403b7e  68842a4300             -push 0x432a84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401796 /*0x432a84*/;
    cpu.esp -= 4;
    // 00403b83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403b84  e83c160200             -call 0x4251c5
    cpu.esp -= 4;
    sub_4251c5(app, cpu);
    // 00403b89  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00403b8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403b8e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403b8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403b90  e84bd9ffff             -call 0x4014e0
    cpu.esp -= 4;
    sub_4014e0(app, cpu);
    // 00403b95  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00403b98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403b9a  7500                   -jne 0x403b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00403b9c;
    }
L_0x00403b9c:
    // 00403b9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b9e  81c464020000           -add esp, 0x264
    (cpu.esp) += x86::reg32(x86::sreg32(612 /*0x264*/));
    // 00403ba4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403bb0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00403bb4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00403bb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403bb9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403bbb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403bbd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403bbe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403bbf  e8acfeffff             -call 0x403a70
    cpu.esp -= 4;
    sub_403a70(app, cpu);
    // 00403bc4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403bc6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403bc9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00403bcb  7418                   -je 0x403be5
    if (cpu.flags.zf)
    {
        goto L_0x00403be5;
    }
    // 00403bcd  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00403bd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403bd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403bd3  e898fdffff             -call 0x403970
    cpu.esp -= 4;
    sub_403970(app, cpu);
    // 00403bd8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00403bda  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403bdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403bde  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403be1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403be3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403be4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403be5:
    // 00403be5  b805400080             -mov eax, 0x80004005
    cpu.eax = 2147500037 /*0x80004005*/;
    // 00403bea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403beb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403bf0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00403bf4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403bf7  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403bfb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403bfd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403bff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403c00  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00403c04  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403c07  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403c08  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403c09  ff510c                 -call dword ptr [ecx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403c0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403c0e  740b                   -je 0x403c1b
    if (cpu.flags.zf)
    {
        goto L_0x00403c1b;
    }
    // 00403c10  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403c15  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403c18  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403c1b:
    // 00403c1b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403c1f  6878054300             -push 0x430578
    app->getMemory<x86::reg32>(cpu.esp-4) = 4392312 /*0x430578*/;
    cpu.esp -= 4;
    // 00403c24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403c25  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403c27  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403c2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403c2c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403c30  7411                   -je 0x403c43
    if (cpu.flags.zf)
    {
        goto L_0x00403c43;
    }
    // 00403c32  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403c34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403c35  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403c38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403c3d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403c40  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403c43:
    // 00403c43  8b150c3a4900           -mov edx, dword ptr [0x493a0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 00403c49  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403c4b  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00403c4d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403c4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403c4f  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403c52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403c54  7415                   -je 0x403c6b
    if (cpu.flags.zf)
    {
        goto L_0x00403c6b;
    }
    // 00403c56  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403c5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403c5b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403c5d  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403c60  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403c65  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403c68  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403c6b:
    // 00403c6b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403c6f  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00403c73  c744240018000000       -mov dword ptr [esp], 0x18
    app->getMemory<x86::reg32>(cpu.esp) = 24 /*0x18*/;
    // 00403c7b  c744240410000000       -mov dword ptr [esp + 4], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 16 /*0x10*/;
    // 00403c83  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00403c8b  c744240c01000000       -mov dword ptr [esp + 0xc], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00403c93  c744241018fcffff       -mov dword ptr [esp + 0x10], 0xfffffc18
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 4294966296 /*0xfffffc18*/;
    // 00403c9b  c7442414e8030000       -mov dword ptr [esp + 0x14], 0x3e8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1000 /*0x3e8*/;
    // 00403ca3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403ca5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403ca6  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00403ca8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403ca9  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403cac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403cae  7415                   -je 0x403cc5
    if (cpu.flags.zf)
    {
        goto L_0x00403cc5;
    }
    // 00403cb0  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403cb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403cb5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403cb7  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403cba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403cbf  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403cc2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403cc5:
    // 00403cc5  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403cc9  8d542400               -lea edx, [esp]
    cpu.edx = x86::reg32(cpu.esp);
    // 00403ccd  c744240804000000       -mov dword ptr [esp + 8], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
    // 00403cd5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403cd6  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403cd8  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00403cda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403cdb  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403cde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403ce0  7415                   -je 0x403cf7
    if (cpu.flags.zf)
    {
        goto L_0x00403cf7;
    }
    // 00403ce2  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403ce6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403ce7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403ce9  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403cec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403cf1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403cf4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403cf7:
    // 00403cf7  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403cfb  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00403cff  c744240808000000       -mov dword ptr [esp + 8], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 00403d07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403d08  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403d0a  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00403d0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403d0d  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403d10  8d4c2400               -lea ecx, [esp]
    cpu.ecx = x86::reg32(cpu.esp);
    // 00403d14  c744240814000000       -mov dword ptr [esp + 8], 0x14
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 20 /*0x14*/;
    // 00403d1c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403d21  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00403d23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403d24  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403d26  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403d29  687ce04300             -push 0x43e07c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4448380 /*0x43e07c*/;
    cpu.esp -= 4;
    // 00403d2e  6848064300             -push 0x430648
    app->getMemory<x86::reg32>(cpu.esp-4) = 4392520 /*0x430648*/;
    cpu.esp -= 4;
    // 00403d33  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00403d37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403d38  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403d3a  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403d3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403d3e  740b                   -je 0x403d4b
    if (cpu.flags.zf)
    {
        goto L_0x00403d4b;
    }
    // 00403d40  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403d45  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403d48  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00403d4b:
    // 00403d4b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00403d4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403d50  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403d52  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403d55  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403d57  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00403d5a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_403d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403d60  a17ce04300             -mov eax, dword ptr [0x43e07c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448380) /* 0x43e07c */);
    // 00403d65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403d67  7501                   -jne 0x403d6a
    if (!cpu.flags.zf)
    {
        goto L_0x00403d6a;
    }
    // 00403d69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403d6a:
    // 00403d6a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403d6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403d6d  ff511c                 -call dword ptr [ecx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403d70  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00403d72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403d74  0f9dc2                 -setge dl
    cpu.dl = (cpu.flags.sf == cpu.flags.of);
    // 00403d77  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403d79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403d80  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00403d83  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00403d87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403d88  8b5c2460               -mov ebx, dword ptr [esp + 0x60]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00403d8c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403d8d  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00403d91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403d92  8b742460               -mov esi, dword ptr [esp + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00403d96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403d97  8b7c2468               -mov edi, dword ptr [esp + 0x68]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00403d9b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00403da1  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00403da7  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00403dad  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00403db4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00403dba  a17ce04300             -mov eax, dword ptr [0x43e07c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448380) /* 0x43e07c */);
    // 00403dbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403dc1  7508                   -jne 0x403dcb
    if (!cpu.flags.zf)
    {
        goto L_0x00403dcb;
    }
    // 00403dc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403dc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403dc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403dc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403dc7  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00403dca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403dcb:
    // 00403dcb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403dcd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403dce  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403dd1  a17ce04300             -mov eax, dword ptr [0x43e07c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448380) /* 0x43e07c */);
    // 00403dd6  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403dda  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403ddb  6a50                   -push 0x50
    app->getMemory<x86::reg32>(cpu.esp-4) = 80 /*0x50*/;
    cpu.esp -= 4;
    // 00403ddd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403ddf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403de0  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403de3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403de5  7416                   -je 0x403dfd
    if (cpu.flags.zf)
    {
        goto L_0x00403dfd;
    }
    // 00403de7  3d1e000780             +cmp eax, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403dec  7505                   -jne 0x403df3
    if (!cpu.flags.zf)
    {
        goto L_0x00403df3;
    }
    // 00403dee  e86dffffff             -call 0x403d60
    cpu.esp -= 4;
    sub_403d60(app, cpu);
L_0x00403df3:
    // 00403df3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403df4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403df5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403df6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403df8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403df9  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00403dfc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403dfd:
    // 00403dfd  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00403e01  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00403e05  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00403e09  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00403e0b  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00403e0f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00403e11  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00403e15  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00403e17  8acc                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 00403e19  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00403e1e  81e180000000           -and ecx, 0x80
    cpu.ecx &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00403e24  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 00403e27  8a542442               -mov dl, byte ptr [esp + 0x42]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(66) /* 0x42 */);
    // 00403e2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403e2c  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 00403e2e  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00403e30  8a44243f               -mov al, byte ptr [esp + 0x3f]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(63) /* 0x3f */);
    // 00403e34  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00403e36  81e280000000           -and edx, 0x80
    cpu.edx &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00403e3c  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00403e41  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00403e43  8a542440               -mov dl, byte ptr [esp + 0x40]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00403e47  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00403e49  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00403e4b  8a442441               -mov al, byte ptr [esp + 0x41]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(65) /* 0x41 */);
    // 00403e4f  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00403e51  81e280000000           -and edx, 0x80
    cpu.edx &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00403e57  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00403e5c  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00403e5e  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00403e62  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00403e64  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00403e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403e67  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00403e6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403e6b  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00403e6d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403e72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403e73  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00403e76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403e80  a16cde4300             -mov eax, dword ptr [0x43de6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447852) /* 0x43de6c */);
    // 00403e85  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00403e87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403e88  68f03b4000             -push 0x403bf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4209648 /*0x403bf0*/;
    cpu.esp -= 4;
    // 00403e8d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403e8f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00403e91  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403e92  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403e95  e8c6feffff             -call 0x403d60
    cpu.esp -= 4;
    sub_403d60(app, cpu);
    // 00403e9a  8b0d7ce04300           -mov ecx, dword ptr [0x43e07c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4448380) /* 0x43e07c */);
    // 00403ea0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403ea2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403ea4  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00403ea7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403eb0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403eb3  8b0dac054300           -mov ecx, dword ptr [0x4305ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4392364) /* 0x4305ac */);
    // 00403eb9  a1a8054300             -mov eax, dword ptr [0x4305a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4392360) /* 0x4305a8 */);
    // 00403ebe  8b15b0054300           -mov edx, dword ptr [0x4305b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4392368) /* 0x4305b0 */);
    // 00403ec4  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00403ec8  8b0d083a4900           -mov ecx, dword ptr [0x493a08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798984) /* 0x493a08 */);
    // 00403ece  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403ed0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00403ed4  a1b4054300             -mov eax, dword ptr [0x4305b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4392372) /* 0x4305b4 */);
    // 00403ed9  686cde4300             -push 0x43de6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4447852 /*0x43de6c*/;
    cpu.esp -= 4;
    // 00403ede  6800070000             -push 0x700
    app->getMemory<x86::reg32>(cpu.esp-4) = 1792 /*0x700*/;
    cpu.esp -= 4;
    // 00403ee3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403ee4  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00403ee8  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00403eec  e8efb30100             -call 0x41f2e0
    cpu.esp -= 4;
    sub_41f2e0(app, cpu);
    // 00403ef1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403ef3  7406                   -je 0x403efb
    if (cpu.flags.zf)
    {
        goto L_0x00403efb;
    }
    // 00403ef5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403ef7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403efa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403efb:
    // 00403efb  a16cde4300             -mov eax, dword ptr [0x43de6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447852) /* 0x43de6c */);
    // 00403f00  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403f02  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00403f06  6870df4300             -push 0x43df70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4448112 /*0x43df70*/;
    cpu.esp -= 4;
    // 00403f0b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403f0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403f0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403f0f  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403f12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403f14  7413                   -je 0x403f29
    if (cpu.flags.zf)
    {
        goto L_0x00403f29;
    }
    // 00403f16  682c2b4300             -push 0x432b2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401964 /*0x432b2c*/;
    cpu.esp -= 4;
    // 00403f1b  e874120200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00403f20  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403f23  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403f25  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403f28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403f29:
    // 00403f29  a170df4300             -mov eax, dword ptr [0x43df70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */);
    // 00403f2e  6890054300             -push 0x430590
    app->getMemory<x86::reg32>(cpu.esp-4) = 4392336 /*0x430590*/;
    cpu.esp -= 4;
    // 00403f33  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403f34  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403f36  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403f39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403f3b  7413                   -je 0x403f50
    if (cpu.flags.zf)
    {
        goto L_0x00403f50;
    }
    // 00403f3d  68fc2a4300             -push 0x432afc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401916 /*0x432afc*/;
    cpu.esp -= 4;
    // 00403f42  e84d120200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00403f47  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403f4a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403f4c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403f4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403f50:
    // 00403f50  a170df4300             -mov eax, dword ptr [0x43df70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */);
    // 00403f55  8b150c3a4900           -mov edx, dword ptr [0x493a0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798988) /* 0x493a0c */);
    // 00403f5b  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00403f5d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403f5e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403f60  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403f61  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403f64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403f66  7413                   -je 0x403f7b
    if (cpu.flags.zf)
    {
        goto L_0x00403f7b;
    }
    // 00403f68  68c82a4300             -push 0x432ac8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4401864 /*0x432ac8*/;
    cpu.esp -= 4;
    // 00403f6d  e822120200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00403f72  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403f75  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403f77  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403f7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403f7b:
    // 00403f7b  a170df4300             -mov eax, dword ptr [0x43df70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */);
    // 00403f80  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403f81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403f82  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403f84  ff511c                 -call dword ptr [ecx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403f87  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00403f89  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403f8b  0f9dc2                 -setge dl
    cpu.dl = (cpu.flags.sf == cpu.flags.of);
    // 00403f8e  891574df4300           -mov dword ptr [0x43df74], edx
    app->getMemory<x86::reg32>(x86::reg32(4448116) /* 0x43df74 */) = cpu.edx;
    // 00403f94  e8e7feffff             -call 0x403e80
    cpu.esp -= 4;
    sub_403e80(app, cpu);
    // 00403f99  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00403f9e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403fa0  bf78df4300             -mov edi, 0x43df78
    cpu.edi = 4448120 /*0x43df78*/;
    // 00403fa5  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00403fa7  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00403fac  bf70de4300             -mov edi, 0x43de70
    cpu.edi = 4447856 /*0x43de70*/;
    // 00403fb1  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00403fb3  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00403fb8  bf6cdd4300             -mov edi, 0x43dd6c
    cpu.edi = 4447596 /*0x43dd6c*/;
    // 00403fbd  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00403fbf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403fc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403fc5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403fc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403fd0  a118bd4300             -mov eax, dword ptr [0x43bd18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4439320) /* 0x43bd18 */);
    // 00403fd5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403fd7  747d                   -je 0x404056
    if (cpu.flags.zf)
    {
        goto L_0x00404056;
    }
    // 00403fd9  a170df4300             -mov eax, dword ptr [0x43df70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */);
    // 00403fde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403fdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403fe0  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00403fe5  be78df4300             -mov esi, 0x43df78
    cpu.esi = 4448120 /*0x43df78*/;
    // 00403fea  bf70de4300             -mov edi, 0x43de70
    cpu.edi = 4447856 /*0x43de70*/;
    // 00403fef  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00403ff1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00403ff3  6878df4300             -push 0x43df78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4448120 /*0x43df78*/;
    cpu.esp -= 4;
    // 00403ff8  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00403ffd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403ffe  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404001  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404002  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404005  742b                   -je 0x404032
    if (cpu.flags.zf)
    {
        goto L_0x00404032;
    }
    // 00404007  3d1e000780             +cmp eax, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040400c  7548                   -jne 0x404056
    if (!cpu.flags.zf)
    {
        goto L_0x00404056;
    }
    // 0040400e  a170df4300             -mov eax, dword ptr [0x43df70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */);
    // 00404013  c70574df430000000000   -mov dword ptr [0x43df74], 0
    app->getMemory<x86::reg32>(x86::reg32(4448116) /* 0x43df74 */) = 0 /*0x0*/;
    // 0040401d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040401e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00404020  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404023  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404025  7c2f                   -jl 0x404056
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00404056;
    }
    // 00404027  c70574df430001000000   -mov dword ptr [0x43df74], 1
    app->getMemory<x86::reg32>(x86::reg32(4448116) /* 0x43df74 */) = 1 /*0x1*/;
    // 00404031  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404032:
    // 00404032  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404034  b280                   -mov dl, 0x80
    cpu.dl = 128 /*0x80*/;
L_0x00404036:
    // 00404036  8a8878df4300           -mov cl, byte ptr [eax + 0x43df78]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4448120) /* 0x43df78 */);
    // 0040403c  84ca                   +test dl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.cl));
    // 0040403e  740e                   -je 0x40404e
    if (cpu.flags.zf)
    {
        goto L_0x0040404e;
    }
    // 00404040  849070de4300           -test byte ptr [eax + 0x43de70], dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4447856) /* 0x43de70 */) & cpu.dl));
    // 00404046  7506                   -jne 0x40404e
    if (!cpu.flags.zf)
    {
        goto L_0x0040404e;
    }
    // 00404048  88886cdd4300           -mov byte ptr [eax + 0x43dd6c], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4447596) /* 0x43dd6c */) = cpu.cl;
L_0x0040404e:
    // 0040404e  40                     -inc eax
    (cpu.eax)++;
    // 0040404f  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404054  7ce0                   -jl 0x404036
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00404036;
    }
L_0x00404056:
    // 00404056  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404060  a178e04300             -mov eax, dword ptr [0x43e078]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448376) /* 0x43e078 */);
    // 00404065  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404066  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00404068  3bc6                   +cmp eax, esi
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
    // 0040406a  7417                   -je 0x404083
    if (cpu.flags.zf)
    {
        goto L_0x00404083;
    }
    // 0040406c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040406e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040406f  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404072  a178e04300             -mov eax, dword ptr [0x43e078]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448376) /* 0x43e078 */);
    // 00404077  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404078  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040407a  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040407d  893578e04300           -mov dword ptr [0x43e078], esi
    app->getMemory<x86::reg32>(x86::reg32(4448376) /* 0x43e078 */) = cpu.esi;
L_0x00404083:
    // 00404083  a17ce04300             -mov eax, dword ptr [0x43e07c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448380) /* 0x43e07c */);
    // 00404088  3bc6                   +cmp eax, esi
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
    // 0040408a  7417                   -je 0x4040a3
    if (cpu.flags.zf)
    {
        goto L_0x004040a3;
    }
    // 0040408c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040408e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040408f  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404092  a17ce04300             -mov eax, dword ptr [0x43e07c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448380) /* 0x43e07c */);
    // 00404097  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404098  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040409a  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040409d  89357ce04300           -mov dword ptr [0x43e07c], esi
    app->getMemory<x86::reg32>(x86::reg32(4448380) /* 0x43e07c */) = cpu.esi;
L_0x004040a3:
    // 004040a3  393574df4300           +cmp dword ptr [0x43df74], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4448116) /* 0x43df74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004040a9  7411                   -je 0x4040bc
    if (cpu.flags.zf)
    {
        goto L_0x004040bc;
    }
    // 004040ab  a170df4300             -mov eax, dword ptr [0x43df70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */);
    // 004040b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004040b1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004040b3  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004040b6  893574df4300           -mov dword ptr [0x43df74], esi
    app->getMemory<x86::reg32>(x86::reg32(4448116) /* 0x43df74 */) = cpu.esi;
L_0x004040bc:
    // 004040bc  a170df4300             -mov eax, dword ptr [0x43df70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */);
    // 004040c1  3bc6                   +cmp eax, esi
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
    // 004040c3  740c                   -je 0x4040d1
    if (cpu.flags.zf)
    {
        goto L_0x004040d1;
    }
    // 004040c5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004040c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004040c8  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004040cb  893570df4300           -mov dword ptr [0x43df70], esi
    app->getMemory<x86::reg32>(x86::reg32(4448112) /* 0x43df70 */) = cpu.esi;
L_0x004040d1:
    // 004040d1  a16cde4300             -mov eax, dword ptr [0x43de6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4447852) /* 0x43de6c */);
    // 004040d6  3bc6                   +cmp eax, esi
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
    // 004040d8  740c                   -je 0x4040e6
    if (cpu.flags.zf)
    {
        goto L_0x004040e6;
    }
    // 004040da  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004040dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004040dd  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004040e0  89356cde4300           -mov dword ptr [0x43de6c], esi
    app->getMemory<x86::reg32>(x86::reg32(4447852) /* 0x43de6c */) = cpu.esi;
L_0x004040e6:
    // 004040e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4040f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004040f0  a118bd4300             -mov eax, dword ptr [0x43bd18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4439320) /* 0x43bd18 */);
    // 004040f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004040f7  7503                   -jne 0x4040fc
    if (!cpu.flags.zf)
    {
        goto L_0x004040fc;
    }
    // 004040f9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004040fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004040fc:
    // 004040fc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00404100  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00404105  8d886cdd4300           -lea ecx, [eax + 0x43dd6c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4447596) /* 0x43dd6c */);
    // 0040410b  8a806cdd4300           -mov al, byte ptr [eax + 0x43dd6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4447596) /* 0x43dd6c */);
    // 00404111  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00404114  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00404119  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404120  e80b000000             -call 0x404130
    cpu.esp -= 4;
    sub_404130(app, cpu);
    // 00404125  e936000000             -jmp 0x404160
    return sub_404160(app, cpu);
}

/* align: skip  */
void Application::asm_sub_404130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404131  8a442403               -mov al, byte ptr [esp + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 00404135  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0040413a  a248ca4700             -mov byte ptr [0x47ca48], al
    app->getMemory<x86::reg8>(x86::reg32(4704840) /* 0x47ca48 */) = cpu.al;
    // 0040413f  e8121a0200             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 00404144  8900                   -mov dword ptr [eax], eax
    app->getMemory<x86::reg32>(cpu.eax) = cpu.eax;
    // 00404146  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00404149  a34cca4700             -mov dword ptr [0x47ca4c], eax
    app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */) = cpu.eax;
    // 0040414e  c70550ca470000000000   -mov dword ptr [0x47ca50], 0
    app->getMemory<x86::reg32>(x86::reg32(4704848) /* 0x47ca50 */) = 0 /*0x0*/;
    // 00404158  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040415b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404160  6870414000             -push 0x404170
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211056 /*0x404170*/;
    cpu.esp -= 4;
    // 00404165  e8f31a0200             -call 0x425c5d
    cpu.esp -= 4;
    sub_425c5d(app, cpu);
    // 0040416a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040416b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404171  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404172  8b3d4cca4700           -mov edi, dword ptr [0x47ca4c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */);
    // 00404178  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0040417a  3bf7                   +cmp esi, edi
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
    // 0040417c  742d                   -je 0x4041ab
    if (cpu.flags.zf)
    {
        goto L_0x004041ab;
    }
L_0x0040417e:
    // 0040417e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00404180  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00404182  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404183  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00404186  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00404188  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0040418a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040418c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040418f  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00404192  e8b4190200             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 00404197  8b0d50ca4700           -mov ecx, dword ptr [0x47ca50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4704848) /* 0x47ca50 */);
    // 0040419d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004041a0  49                     -dec ecx
    (cpu.ecx)--;
    // 004041a1  3bf7                   +cmp esi, edi
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
    // 004041a3  890d50ca4700           -mov dword ptr [0x47ca50], ecx
    app->getMemory<x86::reg32>(x86::reg32(4704848) /* 0x47ca50 */) = cpu.ecx;
    // 004041a9  75d3                   -jne 0x40417e
    if (!cpu.flags.zf)
    {
        goto L_0x0040417e;
    }
L_0x004041ab:
    // 004041ab  a14cca4700             -mov eax, dword ptr [0x47ca4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */);
    // 004041b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004041b1  e895190200             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 004041b6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004041b9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004041bb  a34cca4700             -mov dword ptr [0x47ca4c], eax
    app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */) = cpu.eax;
    // 004041c0  a350ca4700             -mov dword ptr [0x47ca50], eax
    app->getMemory<x86::reg32>(x86::reg32(4704848) /* 0x47ca50 */) = cpu.eax;
    // 004041c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004041c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004041c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4041d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004041d0  a14cca4700             -mov eax, dword ptr [0x47ca4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */);
    // 004041d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004041d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004041d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004041d8  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004041da  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004041dc  3bf7                   +cmp esi, edi
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
    // 004041de  741b                   -je 0x4041fb
    if (cpu.flags.zf)
    {
        goto L_0x004041fb;
    }
    // 004041e0  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x004041e4:
    // 004041e4  8d4e12                 -lea ecx, [esi + 0x12]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004041e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004041e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004041e9  e802ac0200             -call 0x42edf0
    cpu.esp -= 4;
    sub_42edf0(app, cpu);
    // 004041ee  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004041f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004041f3  740c                   -je 0x404201
    if (cpu.flags.zf)
    {
        goto L_0x00404201;
    }
    // 004041f5  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004041f7  3bf7                   +cmp esi, edi
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
    // 004041f9  75e9                   -jne 0x4041e4
    if (!cpu.flags.zf)
    {
        goto L_0x004041e4;
    }
L_0x004041fb:
    // 004041fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004041fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004041fd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004041ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404200  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404201:
    // 00404201  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00404204  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404205  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404206  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404207  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404210  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00404213  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404214  8b9c2480000000         -mov ebx, dword ptr [esp + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0040421b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040421c  e8afffffff             -call 0x4041d0
    cpu.esp -= 4;
    sub_4041d0(app, cpu);
    // 00404221  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00404224  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404226  740f                   -je 0x404237
    if (cpu.flags.zf)
    {
        goto L_0x00404237;
    }
    // 00404228  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0040422f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404230  894874                 -mov dword ptr [eax + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 00404233  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00404236  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404237:
    // 00404237  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404238  8b354cca4700           -mov esi, dword ptr [0x47ca4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */);
    // 0040423e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040423f  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00404244  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00404247  e80a190200             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 0040424c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040424f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00404251  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00404253  7502                   -jne 0x404257
    if (!cpu.flags.zf)
    {
        goto L_0x00404257;
    }
    // 00404255  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00404257:
    // 00404257  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00404259  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0040425b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040425d  7502                   -jne 0x404261
    if (!cpu.flags.zf)
    {
        goto L_0x00404261;
    }
    // 0040425f  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00404261:
    // 00404261  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00404264  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00404267  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040426a  8d7808                 -lea edi, [eax + 8]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040426d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040426f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00404271  740b                   -je 0x40427e
    if (cpu.flags.zf)
    {
        goto L_0x0040427e;
    }
    // 00404273  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 00404278  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040427c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0040427e:
    // 0040427e  8b1550ca4700           -mov edx, dword ptr [0x47ca50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4704848) /* 0x47ca50 */);
    // 00404284  a14cca4700             -mov eax, dword ptr [0x47ca4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */);
    // 00404289  42                     -inc edx
    (cpu.edx)++;
    // 0040428a  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0040428c  891550ca4700           -mov dword ptr [0x47ca50], edx
    app->getMemory<x86::reg32>(x86::reg32(4704848) /* 0x47ca50 */) = cpu.edx;
    // 00404292  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00404295  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00404298  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040429a  83c212                 +add edx, 0x12
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040429d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0040429f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004042a1  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004042a3  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004042a5  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004042a7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004042a9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004042ac  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004042ae  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004042b0  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004042b7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004042ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004042bb  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004042bd  8b0d4cca4700           -mov ecx, dword ptr [0x47ca4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4704844) /* 0x47ca4c */);
    // 004042c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004042c4  68a4a84300             -push 0x43a8a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434084 /*0x43a8a4*/;
    cpu.esp -= 4;
    // 004042c9  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004042cc  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 004042cf  e8c00e0200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 004042d4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004042d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004042d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004042d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004042da  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 004042dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4042e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004042e0  e90b000000             -jmp 0x4042f0
    return sub_4042f0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4042f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004042f0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004042f2  c70588e0430074024300   -mov dword ptr [0x43e088], 0x430274
    app->getMemory<x86::reg32>(x86::reg32(4448392) /* 0x43e088 */) = 4391540 /*0x430274*/;
    // 004042fc  a38ce04300             -mov dword ptr [0x43e08c], eax
    app->getMemory<x86::reg32>(x86::reg32(4448396) /* 0x43e08c */) = cpu.eax;
    // 00404301  a390e04300             -mov dword ptr [0x43e090], eax
    app->getMemory<x86::reg32>(x86::reg32(4448400) /* 0x43e090 */) = cpu.eax;
    // 00404306  a394e04300             -mov dword ptr [0x43e094], eax
    app->getMemory<x86::reg32>(x86::reg32(4448404) /* 0x43e094 */) = cpu.eax;
    // 0040430b  a398e04300             -mov dword ptr [0x43e098], eax
    app->getMemory<x86::reg32>(x86::reg32(4448408) /* 0x43e098 */) = cpu.eax;
    // 00404310  a3a0e04300             -mov dword ptr [0x43e0a0], eax
    app->getMemory<x86::reg32>(x86::reg32(4448416) /* 0x43e0a0 */) = cpu.eax;
    // 00404315  a39ce04300             -mov dword ptr [0x43e09c], eax
    app->getMemory<x86::reg32>(x86::reg32(4448412) /* 0x43e09c */) = cpu.eax;
    // 0040431a  a3a4e04300             -mov dword ptr [0x43e0a4], eax
    app->getMemory<x86::reg32>(x86::reg32(4448420) /* 0x43e0a4 */) = cpu.eax;
    // 0040431f  a3bce04300             -mov dword ptr [0x43e0bc], eax
    app->getMemory<x86::reg32>(x86::reg32(4448444) /* 0x43e0bc */) = cpu.eax;
    // 00404324  a3c0e04300             -mov dword ptr [0x43e0c0], eax
    app->getMemory<x86::reg32>(x86::reg32(4448448) /* 0x43e0c0 */) = cpu.eax;
    // 00404329  a3c4e04300             -mov dword ptr [0x43e0c4], eax
    app->getMemory<x86::reg32>(x86::reg32(4448452) /* 0x43e0c4 */) = cpu.eax;
    // 0040432e  a3c8e04300             -mov dword ptr [0x43e0c8], eax
    app->getMemory<x86::reg32>(x86::reg32(4448456) /* 0x43e0c8 */) = cpu.eax;
    // 00404333  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404340  e90b000000             -jmp 0x404350
    return sub_404350(app, cpu);
}

/* align: skip  */
void Application::asm_sub_404350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404350  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404352  c7051039490074024300   -mov dword ptr [0x493910], 0x430274
    app->getMemory<x86::reg32>(x86::reg32(4798736) /* 0x493910 */) = 4391540 /*0x430274*/;
    // 0040435c  a314394900             -mov dword ptr [0x493914], eax
    app->getMemory<x86::reg32>(x86::reg32(4798740) /* 0x493914 */) = cpu.eax;
    // 00404361  a318394900             -mov dword ptr [0x493918], eax
    app->getMemory<x86::reg32>(x86::reg32(4798744) /* 0x493918 */) = cpu.eax;
    // 00404366  a31c394900             -mov dword ptr [0x49391c], eax
    app->getMemory<x86::reg32>(x86::reg32(4798748) /* 0x49391c */) = cpu.eax;
    // 0040436b  a320394900             -mov dword ptr [0x493920], eax
    app->getMemory<x86::reg32>(x86::reg32(4798752) /* 0x493920 */) = cpu.eax;
    // 00404370  a328394900             -mov dword ptr [0x493928], eax
    app->getMemory<x86::reg32>(x86::reg32(4798760) /* 0x493928 */) = cpu.eax;
    // 00404375  a324394900             -mov dword ptr [0x493924], eax
    app->getMemory<x86::reg32>(x86::reg32(4798756) /* 0x493924 */) = cpu.eax;
    // 0040437a  a32c394900             -mov dword ptr [0x49392c], eax
    app->getMemory<x86::reg32>(x86::reg32(4798764) /* 0x49392c */) = cpu.eax;
    // 0040437f  a344394900             -mov dword ptr [0x493944], eax
    app->getMemory<x86::reg32>(x86::reg32(4798788) /* 0x493944 */) = cpu.eax;
    // 00404384  a348394900             -mov dword ptr [0x493948], eax
    app->getMemory<x86::reg32>(x86::reg32(4798792) /* 0x493948 */) = cpu.eax;
    // 00404389  a34c394900             -mov dword ptr [0x49394c], eax
    app->getMemory<x86::reg32>(x86::reg32(4798796) /* 0x49394c */) = cpu.eax;
    // 0040438e  a350394900             -mov dword ptr [0x493950], eax
    app->getMemory<x86::reg32>(x86::reg32(4798800) /* 0x493950 */) = cpu.eax;
    // 00404393  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4043a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004043a0  e90b000000             -jmp 0x4043b0
    return sub_4043b0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4043b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004043b0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004043b2  c705b0e4430074024300   -mov dword ptr [0x43e4b0], 0x430274
    app->getMemory<x86::reg32>(x86::reg32(4449456) /* 0x43e4b0 */) = 4391540 /*0x430274*/;
    // 004043bc  a3b4e44300             -mov dword ptr [0x43e4b4], eax
    app->getMemory<x86::reg32>(x86::reg32(4449460) /* 0x43e4b4 */) = cpu.eax;
    // 004043c1  a3b8e44300             -mov dword ptr [0x43e4b8], eax
    app->getMemory<x86::reg32>(x86::reg32(4449464) /* 0x43e4b8 */) = cpu.eax;
    // 004043c6  a3bce44300             -mov dword ptr [0x43e4bc], eax
    app->getMemory<x86::reg32>(x86::reg32(4449468) /* 0x43e4bc */) = cpu.eax;
    // 004043cb  a3c0e44300             -mov dword ptr [0x43e4c0], eax
    app->getMemory<x86::reg32>(x86::reg32(4449472) /* 0x43e4c0 */) = cpu.eax;
    // 004043d0  a3c8e44300             -mov dword ptr [0x43e4c8], eax
    app->getMemory<x86::reg32>(x86::reg32(4449480) /* 0x43e4c8 */) = cpu.eax;
    // 004043d5  a3c4e44300             -mov dword ptr [0x43e4c4], eax
    app->getMemory<x86::reg32>(x86::reg32(4449476) /* 0x43e4c4 */) = cpu.eax;
    // 004043da  a3cce44300             -mov dword ptr [0x43e4cc], eax
    app->getMemory<x86::reg32>(x86::reg32(4449484) /* 0x43e4cc */) = cpu.eax;
    // 004043df  a3e4e44300             -mov dword ptr [0x43e4e4], eax
    app->getMemory<x86::reg32>(x86::reg32(4449508) /* 0x43e4e4 */) = cpu.eax;
    // 004043e4  a3e8e44300             -mov dword ptr [0x43e4e8], eax
    app->getMemory<x86::reg32>(x86::reg32(4449512) /* 0x43e4e8 */) = cpu.eax;
    // 004043e9  a3ece44300             -mov dword ptr [0x43e4ec], eax
    app->getMemory<x86::reg32>(x86::reg32(4449516) /* 0x43e4ec */) = cpu.eax;
    // 004043ee  a3f0e44300             -mov dword ptr [0x43e4f0], eax
    app->getMemory<x86::reg32>(x86::reg32(4449520) /* 0x43e4f0 */) = cpu.eax;
    // 004043f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404400  e90b000000             -jmp 0x404410
    return sub_404410(app, cpu);
}

/* align: skip  */
void Application::asm_sub_404410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404410  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404412  c7055839490074024300   -mov dword ptr [0x493958], 0x430274
    app->getMemory<x86::reg32>(x86::reg32(4798808) /* 0x493958 */) = 4391540 /*0x430274*/;
    // 0040441c  a35c394900             -mov dword ptr [0x49395c], eax
    app->getMemory<x86::reg32>(x86::reg32(4798812) /* 0x49395c */) = cpu.eax;
    // 00404421  a360394900             -mov dword ptr [0x493960], eax
    app->getMemory<x86::reg32>(x86::reg32(4798816) /* 0x493960 */) = cpu.eax;
    // 00404426  a364394900             -mov dword ptr [0x493964], eax
    app->getMemory<x86::reg32>(x86::reg32(4798820) /* 0x493964 */) = cpu.eax;
    // 0040442b  a368394900             -mov dword ptr [0x493968], eax
    app->getMemory<x86::reg32>(x86::reg32(4798824) /* 0x493968 */) = cpu.eax;
    // 00404430  a370394900             -mov dword ptr [0x493970], eax
    app->getMemory<x86::reg32>(x86::reg32(4798832) /* 0x493970 */) = cpu.eax;
    // 00404435  a36c394900             -mov dword ptr [0x49396c], eax
    app->getMemory<x86::reg32>(x86::reg32(4798828) /* 0x49396c */) = cpu.eax;
    // 0040443a  a374394900             -mov dword ptr [0x493974], eax
    app->getMemory<x86::reg32>(x86::reg32(4798836) /* 0x493974 */) = cpu.eax;
    // 0040443f  a38c394900             -mov dword ptr [0x49398c], eax
    app->getMemory<x86::reg32>(x86::reg32(4798860) /* 0x49398c */) = cpu.eax;
    // 00404444  a390394900             -mov dword ptr [0x493990], eax
    app->getMemory<x86::reg32>(x86::reg32(4798864) /* 0x493990 */) = cpu.eax;
    // 00404449  a394394900             -mov dword ptr [0x493994], eax
    app->getMemory<x86::reg32>(x86::reg32(4798868) /* 0x493994 */) = cpu.eax;
    // 0040444e  a398394900             -mov dword ptr [0x493998], eax
    app->getMemory<x86::reg32>(x86::reg32(4798872) /* 0x493998 */) = cpu.eax;
    // 00404453  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404460  e90b000000             -jmp 0x404470
    return sub_404470(app, cpu);
}

/* align: skip  */
void Application::asm_sub_404470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404470  b820ec4700             -mov eax, 0x47ec20
    cpu.eax = 4713504 /*0x47ec20*/;
    // 00404475  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 0040447a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0040447c:
    // 0040447c  c740f8a4024300         -mov dword ptr [eax - 8], 0x4302a4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = 4391588 /*0x4302a4*/;
    // 00404483  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00404486  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00404488  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0040448b  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0040448e  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00404491  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00404494  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00404497  c740f874024300         -mov dword ptr [eax - 8], 0x430274
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = 4391540 /*0x430274*/;
    // 0040449e  89482c                 -mov dword ptr [eax + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 004044a1  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004044a4  894834                 -mov dword ptr [eax + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 004044a7  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 004044aa  83c044                 +add eax, 0x44
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004044ad  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004044ae  75cc                   -jne 0x40447c
    if (!cpu.flags.zf)
    {
        goto L_0x0040447c;
    }
    // 004044b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4044c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004044c0  e90b000000             -jmp 0x4044d0
    return sub_4044d0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4044d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004044d0  b8b0e14300             -mov eax, 0x43e1b0
    cpu.eax = 4448688 /*0x43e1b0*/;
    // 004044d5  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 004044da  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004044dc:
    // 004044dc  c740f8a4024300         -mov dword ptr [eax - 8], 0x4302a4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = 4391588 /*0x4302a4*/;
    // 004044e3  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004044e6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004044e8  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004044eb  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004044ee  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004044f1  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004044f4  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004044f7  c740f874024300         -mov dword ptr [eax - 8], 0x430274
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = 4391540 /*0x430274*/;
    // 004044fe  89482c                 -mov dword ptr [eax + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00404501  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 00404504  894834                 -mov dword ptr [eax + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 00404507  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0040450a  83c044                 +add eax, 0x44
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040450d  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040450e  75cc                   -jne 0x4044dc
    if (!cpu.flags.zf)
    {
        goto L_0x004044dc;
    }
    // 00404510  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404520  e90b000000             -jmp 0x404530
    return sub_404530(app, cpu);
}

/* align: skip  */
void Application::asm_sub_404530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404530  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404532  c70568e4430074024300   -mov dword ptr [0x43e468], 0x430274
    app->getMemory<x86::reg32>(x86::reg32(4449384) /* 0x43e468 */) = 4391540 /*0x430274*/;
    // 0040453c  a36ce44300             -mov dword ptr [0x43e46c], eax
    app->getMemory<x86::reg32>(x86::reg32(4449388) /* 0x43e46c */) = cpu.eax;
    // 00404541  a370e44300             -mov dword ptr [0x43e470], eax
    app->getMemory<x86::reg32>(x86::reg32(4449392) /* 0x43e470 */) = cpu.eax;
    // 00404546  a374e44300             -mov dword ptr [0x43e474], eax
    app->getMemory<x86::reg32>(x86::reg32(4449396) /* 0x43e474 */) = cpu.eax;
    // 0040454b  a378e44300             -mov dword ptr [0x43e478], eax
    app->getMemory<x86::reg32>(x86::reg32(4449400) /* 0x43e478 */) = cpu.eax;
    // 00404550  a380e44300             -mov dword ptr [0x43e480], eax
    app->getMemory<x86::reg32>(x86::reg32(4449408) /* 0x43e480 */) = cpu.eax;
    // 00404555  a37ce44300             -mov dword ptr [0x43e47c], eax
    app->getMemory<x86::reg32>(x86::reg32(4449404) /* 0x43e47c */) = cpu.eax;
    // 0040455a  a384e44300             -mov dword ptr [0x43e484], eax
    app->getMemory<x86::reg32>(x86::reg32(4449412) /* 0x43e484 */) = cpu.eax;
    // 0040455f  a39ce44300             -mov dword ptr [0x43e49c], eax
    app->getMemory<x86::reg32>(x86::reg32(4449436) /* 0x43e49c */) = cpu.eax;
    // 00404564  a3a0e44300             -mov dword ptr [0x43e4a0], eax
    app->getMemory<x86::reg32>(x86::reg32(4449440) /* 0x43e4a0 */) = cpu.eax;
    // 00404569  a3a4e44300             -mov dword ptr [0x43e4a4], eax
    app->getMemory<x86::reg32>(x86::reg32(4449444) /* 0x43e4a4 */) = cpu.eax;
    // 0040456e  a3a8e44300             -mov dword ptr [0x43e4a8], eax
    app->getMemory<x86::reg32>(x86::reg32(4449448) /* 0x43e4a8 */) = cpu.eax;
    // 00404573  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404580  e90b000000             -jmp 0x404590
    return sub_404590(app, cpu);
}

/* align: skip  */
void Application::asm_sub_404590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404590  b8d8e04300             -mov eax, 0x43e0d8
    cpu.eax = 4448472 /*0x43e0d8*/;
    // 00404595  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0040459a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0040459c:
    // 0040459c  c740f8a4024300         -mov dword ptr [eax - 8], 0x4302a4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = 4391588 /*0x4302a4*/;
    // 004045a3  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004045a6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004045a8  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004045ab  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004045ae  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004045b1  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004045b4  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004045b7  c740f874024300         -mov dword ptr [eax - 8], 0x430274
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = 4391540 /*0x430274*/;
    // 004045be  89482c                 -mov dword ptr [eax + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 004045c1  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004045c4  894834                 -mov dword ptr [eax + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 004045c7  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 004045ca  83c044                 +add eax, 0x44
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004045cd  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004045ce  75cc                   -jne 0x40459c
    if (!cpu.flags.zf)
    {
        goto L_0x0040459c;
    }
    // 004045d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4045e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004045e0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004045e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004045e6  741b                   -je 0x404603
    if (cpu.flags.zf)
    {
        goto L_0x00404603;
    }
    // 004045e8  a3c4394900             -mov dword ptr [0x4939c4], eax
    app->getMemory<x86::reg32>(x86::reg32(4798916) /* 0x4939c4 */) = cpu.eax;
    // 004045ed  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004045f1  a3c8394900             -mov dword ptr [0x4939c8], eax
    app->getMemory<x86::reg32>(x86::reg32(4798920) /* 0x4939c8 */) = cpu.eax;
    // 004045f6  e8d5f9ffff             -call 0x403fd0
    cpu.esp -= 4;
    sub_403fd0(app, cpu);
    // 004045fb  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004045fd  e8eefaffff             -call 0x4040f0
    cpu.esp -= 4;
    sub_4040f0(app, cpu);
    // 00404602  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00404603:
    // 00404603  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404610  8b0dc4394900           -mov ecx, dword ptr [0x4939c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4798916) /* 0x4939c4 */);
    // 00404616  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404618  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040461a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0040461d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404620  e80b000000             -call 0x404630
    cpu.esp -= 4;
    sub_404630(app, cpu);
    // 00404625  e936000000             -jmp 0x404660
    return sub_404660(app, cpu);
}

/* align: skip  */
void Application::asm_sub_404630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404630  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404631  8a442403               -mov al, byte ptr [esp + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 00404635  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00404637  a258e44300             -mov byte ptr [0x43e458], al
    app->getMemory<x86::reg8>(x86::reg32(4449368) /* 0x43e458 */) = cpu.al;
    // 0040463c  e815150200             -call 0x425b56
    cpu.esp -= 4;
    sub_425b56(app, cpu);
    // 00404641  8900                   -mov dword ptr [eax], eax
    app->getMemory<x86::reg32>(cpu.eax) = cpu.eax;
    // 00404643  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00404646  a35ce44300             -mov dword ptr [0x43e45c], eax
    app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */) = cpu.eax;
    // 0040464b  c70560e4430000000000   -mov dword ptr [0x43e460], 0
    app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */) = 0 /*0x0*/;
    // 00404655  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00404658  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404660  6870464000             -push 0x404670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4212336 /*0x404670*/;
    cpu.esp -= 4;
    // 00404665  e8f3150200             -call 0x425c5d
    cpu.esp -= 4;
    sub_425c5d(app, cpu);
    // 0040466a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040466b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404671  8b1d5ce44300           -mov ebx, dword ptr [0x43e45c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */);
    // 00404677  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404678  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0040467a  3bfb                   +cmp edi, ebx
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
    // 0040467c  7437                   -je 0x4046b5
    if (cpu.flags.zf)
    {
        goto L_0x004046b5;
    }
    // 0040467e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0040467f:
    // 0040467f  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00404681  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00404683  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00404686  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00404688  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0040468a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040468c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0040468f  8d4e08                 -lea ecx, [esi + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00404692  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00404695  e846000000             -call 0x4046e0
    cpu.esp -= 4;
    sub_4046e0(app, cpu);
    // 0040469a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040469b  e8ab140200             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 004046a0  8b0d60e44300           -mov ecx, dword ptr [0x43e460]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */);
    // 004046a6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004046a9  49                     -dec ecx
    (cpu.ecx)--;
    // 004046aa  3bfb                   +cmp edi, ebx
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
    // 004046ac  890d60e44300           -mov dword ptr [0x43e460], ecx
    app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */) = cpu.ecx;
    // 004046b2  75cb                   -jne 0x40467f
    if (!cpu.flags.zf)
    {
        goto L_0x0040467f;
    }
    // 004046b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004046b5:
    // 004046b5  8b0d5ce44300           -mov ecx, dword ptr [0x43e45c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */);
    // 004046bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004046bc  e88a140200             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 004046c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004046c4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004046c6  a35ce44300             -mov dword ptr [0x43e45c], eax
    app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */) = cpu.eax;
    // 004046cb  a360e44300             -mov dword ptr [0x43e460], eax
    app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */) = cpu.eax;
    // 004046d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004046d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004046d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4046e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004046e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004046e1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004046e3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004046e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004046e7  740f                   -je 0x4046f8
    if (cpu.flags.zf)
    {
        goto L_0x004046f8;
    }
    // 004046e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004046ea  e857070200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 004046ef  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004046f2  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x004046f8:
    // 004046f8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004046fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004046fd  740d                   -je 0x40470c
    if (cpu.flags.zf)
    {
        goto L_0x0040470c;
    }
    // 004046ff  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00404701  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404702  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404705  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x0040470c:
    // 0040470c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040470d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404710  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00404712  6898ef4200             -push 0x42ef98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4386712 /*0x42ef98*/;
    cpu.esp -= 4;
    // 00404717  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0040471d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040471e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00404725  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00404728  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404729  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040472d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040472e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040472f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404730  68c0a84300             -push 0x43a8c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434112 /*0x43a8c0*/;
    cpu.esp -= 4;
    // 00404735  e85a0a0200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0040473a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040473c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040473f  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00404743  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00404747  8b355ce44300           -mov esi, dword ptr [0x43e45c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */);
    // 0040474d  b958e44300             -mov ecx, 0x43e458
    cpu.ecx = 4449368 /*0x43e458*/;
    // 00404752  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00404756  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00404759  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040475a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040475b  e8406e0100             -call 0x41b5a0
    cpu.esp -= 4;
    sub_41b5a0(app, cpu);
    // 00404760  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00404763  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00404766  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00404768  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0040476c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040476f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404770  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404771  e8fa6e0100             -call 0x41b670
    cpu.esp -= 4;
    sub_41b670(app, cpu);
    // 00404776  8b1560e44300           -mov edx, dword ptr [0x43e460]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */);
    // 0040477c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00404780  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00404783  42                     -inc edx
    (cpu.edx)++;
    // 00404784  3bc7                   +cmp eax, edi
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
    // 00404786  891560e44300           -mov dword ptr [0x43e460], edx
    app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */) = cpu.edx;
    // 0040478c  c744241cffffffff       -mov dword ptr [esp + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 00404794  740d                   -je 0x4047a3
    if (cpu.flags.zf)
    {
        goto L_0x004047a3;
    }
    // 00404796  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404797  e8aa060200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0040479c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040479f  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x004047a3:
    // 004047a3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004047a7  3bc7                   +cmp eax, edi
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
    // 004047a9  7406                   -je 0x4047b1
    if (cpu.flags.zf)
    {
        goto L_0x004047b1;
    }
    // 004047ab  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004047ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004047ae  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004047b1:
    // 004047b1  a15ce44300             -mov eax, dword ptr [0x43e45c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */);
    // 004047b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004047b7  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004047ba  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004047bd  e8efa50200             -call 0x42edb1
    cpu.esp -= 4;
    sub_42edb1(app, cpu);
    // 004047c2  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004047c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004047c9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004047cb  a160e44300             -mov eax, dword ptr [0x43e460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */);
    // 004047d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047d3  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004047da  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004047dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4047e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004047e0  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004047e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004047e4  8b1d5ce44300           -mov ebx, dword ptr [0x43e45c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */);
    // 004047ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004047eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004047ec  8b7c247c               -mov edi, dword ptr [esp + 0x7c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004047f0  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004047f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004047f3  6824a94300             -push 0x43a924
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434212 /*0x43a924*/;
    cpu.esp -= 4;
    // 004047f8  e897090200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 004047fd  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004047ff  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00404802  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404803  ff506c                 -call dword ptr [eax + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404806  3bf3                   +cmp esi, ebx
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
    // 00404808  740b                   -je 0x404815
    if (cpu.flags.zf)
    {
        goto L_0x00404815;
    }
L_0x0040480a:
    // 0040480a  397e0c                 +cmp dword ptr [esi + 0xc], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040480d  741a                   -je 0x404829
    if (cpu.flags.zf)
    {
        goto L_0x00404829;
    }
    // 0040480f  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00404811  3bf3                   +cmp esi, ebx
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
    // 00404813  75f5                   -jne 0x40480a
    if (!cpu.flags.zf)
    {
        goto L_0x0040480a;
    }
L_0x00404815:
    // 00404815  6810a94300             -push 0x43a910
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434192 /*0x43a910*/;
    cpu.esp -= 4;
    // 0040481a  e875090200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0040481f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00404822  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404823  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404824  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404825  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00404828  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404829:
    // 00404829  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0040482c  8b15bc394900           -mov edx, dword ptr [0x4939bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4798908) /* 0x4939bc */);
    // 00404832  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404833  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404834  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404835  e876f3ffff             -call 0x403bb0
    cpu.esp -= 4;
    sub_403bb0(app, cpu);
    // 0040483a  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0040483c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040483f  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00404843  c744240c6c000000       -mov dword ptr [esp + 0xc], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 108 /*0x6c*/;
    // 0040484b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040484c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040484d  c744241806000000       -mov dword ptr [esp + 0x18], 6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 6 /*0x6*/;
    // 00404855  ff5058                 -call dword ptr [eax + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404858  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0040485c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00404860  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00404863  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404864  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404865  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404866  68dca84300             -push 0x43a8dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434140 /*0x43a8dc*/;
    cpu.esp -= 4;
    // 0040486b  e824090200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00404870  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00404873  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404874  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404875  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404876  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00404879  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404880  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00404883  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404884  8b1d5ce44300           -mov ebx, dword ptr [0x43e45c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */);
    // 0040488a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040488b  8bb42480000000         -mov esi, dword ptr [esp + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00404892  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404893  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00404895  83fe01                 +cmp esi, 1
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
    // 00404898  0f82f2000000           -jb 0x404990
    if (cpu.flags.cf)
    {
        goto L_0x00404990;
    }
    // 0040489e  68f0a94300             -push 0x43a9f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434416 /*0x43a9f0*/;
    cpu.esp -= 4;
    // 004048a3  e8ec080200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 004048a8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004048ad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004048b0  3bf0                   +cmp esi, eax
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
    // 004048b2  760f                   -jbe 0x4048c3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004048c3;
    }
L_0x004048b4:
    // 004048b4  3bfb                   +cmp edi, ebx
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
    // 004048b6  0f84c7000000           -je 0x404983
    if (cpu.flags.zf)
    {
        goto L_0x00404983;
    }
    // 004048bc  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004048be  40                     -inc eax
    (cpu.eax)++;
    // 004048bf  3bc6                   +cmp eax, esi
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
    // 004048c1  72f1                   -jb 0x4048b4
    if (cpu.flags.cf)
    {
        goto L_0x004048b4;
    }
L_0x004048c3:
    // 004048c3  3bfb                   +cmp edi, ebx
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
    // 004048c5  0f84b8000000           -je 0x404983
    if (cpu.flags.zf)
    {
        goto L_0x00404983;
    }
    // 004048cb  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004048ce  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004048d0  3bc3                   +cmp eax, ebx
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
    // 004048d2  7545                   -jne 0x404919
    if (!cpu.flags.zf)
    {
        goto L_0x00404919;
    }
    // 004048d4  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004048d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004048d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004048d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004048da  a1bc394900             -mov eax, dword ptr [0x4939bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4798908) /* 0x4939bc */);
    // 004048df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004048e0  e88bf1ffff             -call 0x403a70
    cpu.esp -= 4;
    sub_403a70(app, cpu);
    // 004048e5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004048e7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004048ea  3bf3                   +cmp esi, ebx
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
    // 004048ec  751a                   -jne 0x404908
    if (!cpu.flags.zf)
    {
        goto L_0x00404908;
    }
    // 004048ee  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004048f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004048f2  68c0a94300             -push 0x43a9c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434368 /*0x43a9c0*/;
    cpu.esp -= 4;
    // 004048f7  e898080200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 004048fc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004048ff  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404901  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404902  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404903  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404904  83c474                 +add esp, 0x74
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(116 /*0x74*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00404907  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404908:
    // 00404908  89770c                 -mov dword ptr [edi + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0040490b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040490d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040490e  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404911  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00404913  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404914  ff5004                 -call dword ptr [eax + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00404917  eb16                   -jmp 0x40492f
    goto L_0x0040492f;
L_0x00404919:
    // 00404919  6898a94300             -push 0x43a998
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434328 /*0x43a998*/;
    cpu.esp -= 4;
    // 0040491e  e871080200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00404923  8b770c                 -mov esi, dword ptr [edi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00404926  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00404929  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0040492b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040492c  ff5104                 -call dword ptr [ecx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0040492f:
    // 0040492f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00404933  c74424146c000000       -mov dword ptr [esp + 0x14], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 108 /*0x6c*/;
    // 0040493b  c744241806000000       -mov dword ptr [esp + 0x18], 6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 6 /*0x6*/;
    // 00404943  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00404945  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404946  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404947  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040494a  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0040494e  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00404952  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00404955  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404956  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404957  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00404958  6868a94300             -push 0x43a968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434280 /*0x43a968*/;
    cpu.esp -= 4;
    // 0040495d  e832080200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 00404962  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00404965  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00404969  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0040496d  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00404971  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00404973  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404974  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00404976  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404977  ff5174                 -call dword ptr [ecx + 0x74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040497a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040497c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040497d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040497e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040497f  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00404982  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404983:
    // 00404983  6848a94300             -push 0x43a948
    app->getMemory<x86::reg32>(cpu.esp-4) = 4434248 /*0x43a948*/;
    cpu.esp -= 4;
    // 00404988  e807080200             -call 0x425194
    cpu.esp -= 4;
    sub_425194(app, cpu);
    // 0040498d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00404990:
    // 00404990  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404991  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404992  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404994  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404995  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00404998  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4049a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004049a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004049a1  8b2d5ce44300           -mov ebp, dword ptr [0x43e45c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4449372) /* 0x43e45c */);
    // 004049a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004049a8  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004049ab  3bfd                   +cmp edi, ebp
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
    // 004049ad  7456                   -je 0x404a05
    if (cpu.flags.zf)
    {
        goto L_0x00404a05;
    }
    // 004049af  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004049b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004049b1  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004049b3:
    // 004049b3  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004049b5  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004049b7  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004049ba  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004049bc  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004049be  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004049c0  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004049c3  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004049c6  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004049c9  3bc3                   +cmp eax, ebx
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
    // 004049cb  740c                   -je 0x4049d9
    if (cpu.flags.zf)
    {
        goto L_0x004049d9;
    }
    // 004049cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004049ce  e873040200             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 004049d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004049d6  895e08                 -mov dword ptr [esi + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
L_0x004049d9:
    // 004049d9  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004049dc  3bc3                   +cmp eax, ebx
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
    // 004049de  7409                   -je 0x4049e9
    if (cpu.flags.zf)
    {
        goto L_0x004049e9;
    }
    // 004049e0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004049e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004049e3  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004049e6  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004049e9:
    // 004049e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004049ea  e85c110200             -call 0x425b4b
    cpu.esp -= 4;
    sub_425b4b(app, cpu);
    // 004049ef  8b0d60e44300           -mov ecx, dword ptr [0x43e460]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */);
    // 004049f5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004049f8  49                     -dec ecx
    (cpu.ecx)--;
    // 004049f9  3bfd                   +cmp edi, ebp
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
    // 004049fb  890d60e44300           -mov dword ptr [0x43e460], ecx
    app->getMemory<x86::reg32>(x86::reg32(4449376) /* 0x43e460 */) = cpu.ecx;
    // 00404a01  75b0                   -jne 0x4049b3
    if (!cpu.flags.zf)
    {
        goto L_0x004049b3;
    }
    // 00404a03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404a04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00404a05:
    // 00404a05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404a06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404a07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_404a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404a10  e80b000000             -call 0x404a20
    cpu.esp -= 4;
    sub_404a20(app, cpu);
    // 00404a15  e926000000             -jmp 0x404a40
    return sub_404a40(app, cpu);
}

}
