#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_462e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462e60  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 00462e65  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00462e67  743b                   -je 0x462ea4
    if (cpu.flags.zf)
    {
        goto L_0x00462ea4;
    }
    // 00462e69  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00462e6e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462e6f  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00462e71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462e73  7e24                   -jle 0x462e99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462e99;
    }
    // 00462e75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00462e76:
    // 00462e76  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00462e7b  8b3cb0                 -mov edi, dword ptr [eax + esi*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00462e7e  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00462e80  e8abffffff             -call 0x462e30
    cpu.esp -= 4;
    sub_462e30(app, cpu);
    // 00462e85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462e86  e829450100             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00462e8b  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00462e90  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00462e93  46                     -inc esi
    (cpu.esi)++;
    // 00462e94  3bf0                   +cmp esi, eax
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
    // 00462e96  7cde                   -jl 0x462e76
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462e76;
    }
    // 00462e98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00462e99:
    // 00462e99  c705ccb6510000000000   -mov dword ptr [0x51b6cc], 0
    app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */) = 0 /*0x0*/;
    // 00462ea3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00462ea4:
    // 00462ea4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_462eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462eb0  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 00462eb5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00462eb7  746b                   -je 0x462f24
    if (cpu.flags.zf)
    {
        goto L_0x00462f24;
    }
    // 00462eb9  a1c8b65100             -mov eax, dword ptr [0x51b6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355208) /* 0x51b6c8 */);
    // 00462ebe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462ec0  7462                   -je 0x462f24
    if (cpu.flags.zf)
    {
        goto L_0x00462f24;
    }
    // 00462ec2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462ec3  e868170000             -call 0x464630
    cpu.esp -= 4;
    sub_464630(app, cpu);
    // 00462ec8  8b3580704800           -mov esi, dword ptr [0x487080]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747392) /* 0x487080 */);
    // 00462ece  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 00462ed0  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00462ed2  e889ffffff             -call 0x462e60
    cpu.esp -= 4;
    sub_462e60(app, cpu);
L_0x00462ed7:
    // 00462ed7  a1c8b65100             -mov eax, dword ptr [0x51b6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355208) /* 0x51b6c8 */);
    // 00462edc  8b1504ef5100           -mov edx, dword ptr [0x51ef04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00462ee2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00462ee4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462ee5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00462ee7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462ee8  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00462eeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462eed  75e8                   -jne 0x462ed7
    if (!cpu.flags.zf)
    {
        goto L_0x00462ed7;
    }
    // 00462eef  e83cfdffff             -call 0x462c30
    cpu.esp -= 4;
    sub_462c30(app, cpu);
    // 00462ef4  8b0dc0b65100           -mov ecx, dword ptr [0x51b6c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355200) /* 0x51b6c0 */);
    // 00462efa  e811fdffff             -call 0x462c10
    cpu.esp -= 4;
    sub_462c10(app, cpu);
    // 00462eff  a1c8b65100             -mov eax, dword ptr [0x51b6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355208) /* 0x51b6c8 */);
    // 00462f04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462f06  7410                   -je 0x462f18
    if (cpu.flags.zf)
    {
        goto L_0x00462f18;
    }
    // 00462f08  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00462f0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462f0b  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00462f0e  c705c8b6510000000000   -mov dword ptr [0x51b6c8], 0
    app->getMemory<x86::reg32>(x86::reg32(5355208) /* 0x51b6c8 */) = 0 /*0x0*/;
L_0x00462f18:
    // 00462f18  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 00462f1a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00462f1c  c605e0b6510000         -mov byte ptr [0x51b6e0], 0
    app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */) = 0 /*0x0*/;
    // 00462f23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00462f24:
    // 00462f24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_462f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462f30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462f31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462f32  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 00462f37  e8049bfeff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00462f3c  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00462f3e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00462f40  746e                   -je 0x462fb0
    if (cpu.flags.zf)
    {
        goto L_0x00462fb0;
    }
    // 00462f42  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00462f47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462f48  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00462f4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462f4c  7e58                   -jle 0x462fa6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462fa6;
    }
    // 00462f4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00462f4f:
    // 00462f4f  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00462f54  8b14b0                 -mov edx, dword ptr [eax + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00462f57  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00462f59  7440                   -je 0x462f9b
    if (cpu.flags.zf)
    {
        goto L_0x00462f9b;
    }
    // 00462f5b  8b4248                 -mov eax, dword ptr [edx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00462f5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462f60  7439                   -je 0x462f9b
    if (cpu.flags.zf)
    {
        goto L_0x00462f9b;
    }
    // 00462f62  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00462f64  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00462f67  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00462f69  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462f6a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00462f6c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00462f6e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462f6f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00462f71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462f72  e828480100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00462f77  8b0dd0b65100           -mov ecx, dword ptr [0x51b6d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00462f7d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00462f7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462f80  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00462f82  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 00462f85  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00462f89  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00462f8b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462f8c  8a4241                 -mov al, byte ptr [edx + 0x41]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(65) /* 0x41 */);
    // 00462f8f  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00462f93  e807480100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00462f98  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00462f9b:
    // 00462f9b  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00462fa0  46                     -inc esi
    (cpu.esi)++;
    // 00462fa1  3bf0                   +cmp esi, eax
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
    // 00462fa3  7caa                   -jl 0x462f4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462f4f;
    }
    // 00462fa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00462fa6:
    // 00462fa6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462fa7  e82b460100             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00462fac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00462faf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00462fb0:
    // 00462fb0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462fb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462fb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_462fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462fc0  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00462fc6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462fc7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462fc8  6848fd4900             -push 0x49fd48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4848968 /*0x49fd48*/;
    cpu.esp -= 4;
    // 00462fcd  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00462fcf  e8e33d0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00462fd4  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00462fd9  e889490100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00462fde  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00462fe1  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 00462fe6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00462fe8  e8539afeff             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00462fed  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00462fef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00462ff1  0f849e000000           -je 0x463095
    if (cpu.flags.zf)
    {
        goto L_0x00463095;
    }
L_0x00462ff7:
    // 00462ff7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462ff8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00462ffa  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462ffe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00463000  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463001  e882460100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00463006  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463009  83f801                 +cmp eax, 1
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
    // 0046300c  721d                   -jb 0x46302b
    if (cpu.flags.cf)
    {
        goto L_0x0046302b;
    }
    // 0046300e  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00463012:
    // 00463012  803e00                 +cmp byte ptr [esi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463015  7414                   -je 0x46302b
    if (cpu.flags.zf)
    {
        goto L_0x0046302b;
    }
    // 00463017  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463018  46                     -inc esi
    (cpu.esi)++;
    // 00463019  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046301b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046301d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046301e  e865460100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00463023  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463026  83f801                 +cmp eax, 1
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
    // 00463029  73e7                   -jae 0x463012
    if (!cpu.flags.cf)
    {
        goto L_0x00463012;
    }
L_0x0046302b:
    // 0046302b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046302c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046302e  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463032  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00463034  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463035  e84e460100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046303a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046303d  83f801                 +cmp eax, 1
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
    // 00463040  724a                   -jb 0x46308c
    if (cpu.flags.cf)
    {
        goto L_0x0046308c;
    }
    // 00463042  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463046  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046304a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046304b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046304c  682cfd4900             -push 0x49fd2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4848940 /*0x49fd2c*/;
    cpu.esp -= 4;
    // 00463051  e8613d0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00463056  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0046305b  e807490100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00463060  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463064  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463067  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046306b  e8c0000000             -call 0x463130
    cpu.esp -= 4;
    sub_463130(app, cpu);
    // 00463070  6828fd4900             -push 0x49fd28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4848936 /*0x49fd28*/;
    cpu.esp -= 4;
    // 00463075  e83d3d0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046307a  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0046307f  e8e3480100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00463084  83c408                 +add esp, 8
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
    // 00463087  e96bffffff             -jmp 0x462ff7
    goto L_0x00462ff7;
L_0x0046308c:
    // 0046308c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046308d  e845450100             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00463092  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463095:
    // 00463095  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463096  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463097  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0046309d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4630a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004630a0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004630a3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004630a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004630a6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004630a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004630a9  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004630ab  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004630ae  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004630b0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004630b2  49                     -dec ecx
    (cpu.ecx)--;
    // 004630b3  83f963                 +cmp ecx, 0x63
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004630b6  760d                   -jbe 0x4630c5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004630c5;
    }
    // 004630b8  6860fd4900             -push 0x49fd60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4848992 /*0x49fd60*/;
    cpu.esp -= 4;
    // 004630bd  e84e1bfcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004630c2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004630c5:
    // 004630c5  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004630c9  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004630cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004630ce  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004630d0  e8ab2c0000             -call 0x465d80
    cpu.esp -= 4;
    sub_465d80(app, cpu);
    // 004630d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004630d7  7408                   -je 0x4630e1
    if (cpu.flags.zf)
    {
        goto L_0x004630e1;
    }
    // 004630d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630da  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004630dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004630e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004630e1:
    // 004630e1  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004630e5  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004630e9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004630eb  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004630ef  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004630f2  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004630f6  df6c2410               -fild qword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004630fa  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004630fe  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00463102  dc0d58734800           -fmul qword ptr [0x487358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748120) /* 0x487358 */));
    // 00463108  df6c2410               -fild qword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0046310c  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046310e  e87d3c0100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463113  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463114  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00463116  ff157c704800           -call dword ptr [0x48707c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747388) /* 0x48707c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046311c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046311e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046311f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463120  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463123  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463130  81ecb0000000           -sub esp, 0xb0
    (cpu.esp) -= x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 00463136  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 0046313b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046313c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046313d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046313e  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00463140  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00463142  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00463144  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463145  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00463147  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0046314b  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0046314f  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00463153  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00463157  750e                   -jne 0x463167
    if (!cpu.flags.zf)
    {
        goto L_0x00463167;
    }
    // 00463159  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046315a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046315b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046315c  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046315f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463160  81c4b0000000           -add esp, 0xb0
    (cpu.esp) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 00463166  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463167:
    // 00463167  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 0046316c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046316e  3bc6                   +cmp eax, esi
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
    // 00463170  7e36                   -jle 0x4631a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004631a8;
    }
L_0x00463172:
    // 00463172  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00463177  8b04b8                 -mov eax, dword ptr [eax + edi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0046317a  3bc6                   +cmp eax, esi
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
    // 0046317c  7420                   -je 0x46319e
    if (cpu.flags.zf)
    {
        goto L_0x0046319e;
    }
    // 0046317e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463180  8a4841                 -mov cl, byte ptr [eax + 0x41]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(65) /* 0x41 */);
    // 00463183  3bcb                   +cmp ecx, ebx
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
    // 00463185  7517                   -jne 0x46319e
    if (!cpu.flags.zf)
    {
        goto L_0x0046319e;
    }
    // 00463187  397048                 +cmp dword ptr [eax + 0x48], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046318a  7412                   -je 0x46319e
    if (cpu.flags.zf)
    {
        goto L_0x0046319e;
    }
    // 0046318c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046318d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046318e  e81d1a0200             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00463193  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463196  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463198  0f84af000000           -je 0x46324d
    if (cpu.flags.zf)
    {
        goto L_0x0046324d;
    }
L_0x0046319e:
    // 0046319e  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 004631a3  47                     -inc edi
    (cpu.edi)++;
    // 004631a4  3bf8                   +cmp edi, eax
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
    // 004631a6  7cca                   -jl 0x463172
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463172;
    }
L_0x004631a8:
    // 004631a8  8b15c4b65100           -mov edx, dword ptr [0x51b6c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355204) /* 0x51b6c4 */);
    // 004631ae  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004631b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004631b1  ff15d0704800           -call dword ptr [0x4870d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747472) /* 0x4870d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004631b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004631b8  68ecfe4900             -push 0x49feec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849388 /*0x49feec*/;
    cpu.esp -= 4;
    // 004631bd  e8f53b0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004631c2  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 004631c7  e89b470100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 004631cc  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004631ce  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004631d1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004631d3  83c40c                 +add esp, 0xc
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
    // 004631d6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004631d8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004631da  49                     -dec ecx
    (cpu.ecx)--;
    // 004631db  83f963                 +cmp ecx, 0x63
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004631de  760d                   -jbe 0x4631ed
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004631ed;
    }
    // 004631e0  68d0fe4900             -push 0x49fed0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849360 /*0x49fed0*/;
    cpu.esp -= 4;
    // 004631e5  e8261afcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004631ea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004631ed:
    // 004631ed  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004631f1  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004631f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004631f6  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004631fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004631fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004631fc  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00463200  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00463202  e8992a0000             -call 0x465ca0
    cpu.esp -= 4;
    sub_465ca0(app, cpu);
    // 00463207  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463209  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046320a  744e                   -je 0x46325a
    if (cpu.flags.zf)
    {
        goto L_0x0046325a;
    }
    // 0046320c  68b4fe4900             -push 0x49feb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849332 /*0x49feb4*/;
    cpu.esp -= 4;
    // 00463211  e8a13b0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00463216  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463217  8d442468               -lea eax, [esp + 0x68]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0046321b  6898fe4900             -push 0x49fe98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849304 /*0x49fe98*/;
    cpu.esp -= 4;
    // 00463220  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463221  e8d23b0100             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00463226  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00463229  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0046322d  e88e48ffff             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00463232  8b0dc4b65100           -mov ecx, dword ptr [0x51b6c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355204) /* 0x51b6c4 */);
    // 00463238  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463239  ff15d8704800           -call dword ptr [0x4870d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747480) /* 0x4870d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046323f  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00463242  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463243  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463244  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463245  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463246  81c4b0000000           -add esp, 0xb0
    (cpu.esp) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 0046324c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046324d:
    // 0046324d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046324f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463250  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463251  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463252  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463253  81c4b0000000           -add esp, 0xb0
    (cpu.esp) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 00463259  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046325a:
    // 0046325a  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046325e  6888fe4900             -push 0x49fe88
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849288 /*0x49fe88*/;
    cpu.esp -= 4;
    // 00463263  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463264  e88f3b0100             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00463269  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046326c  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00463270  e84b48ffff             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00463275  8b0dccb65100           -mov ecx, dword ptr [0x51b6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 0046327b  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00463280  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463282  3bce                   +cmp ecx, esi
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
    // 00463284  7e0d                   -jle 0x463293
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00463293;
    }
L_0x00463286:
    // 00463286  8b1498                 -mov edx, dword ptr [eax + ebx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00463289  397248                 +cmp dword ptr [edx + 0x48], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046328c  7405                   -je 0x463293
    if (cpu.flags.zf)
    {
        goto L_0x00463293;
    }
    // 0046328e  43                     -inc ebx
    (cpu.ebx)++;
    // 0046328f  3bd9                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463291  7cf3                   -jl 0x463286
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463286;
    }
L_0x00463293:
    // 00463293  3bd9                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463295  755c                   -jne 0x4632f3
    if (!cpu.flags.zf)
    {
        goto L_0x004632f3;
    }
    // 00463297  8d0c8d04000000         -lea ecx, [ecx*4 + 4]
    cpu.ecx = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 0046329e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046329f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004632a0  e8a63c0100             -call 0x476f4b
    cpu.esp -= 4;
    sub_476f4b(app, cpu);
    // 004632a5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004632a8  3bc6                   +cmp eax, esi
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
    // 004632aa  a3d0b65100             -mov dword ptr [0x51b6d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */) = cpu.eax;
    // 004632af  750d                   -jne 0x4632be
    if (!cpu.flags.zf)
    {
        goto L_0x004632be;
    }
    // 004632b1  6868fe4900             -push 0x49fe68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849256 /*0x49fe68*/;
    cpu.esp -= 4;
    // 004632b6  e85519fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004632bb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004632be:
    // 004632be  6a4c                   -push 0x4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 76 /*0x4c*/;
    cpu.esp -= 4;
    // 004632c0  e8b53f0100             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 004632c5  8b15d0b65100           -mov edx, dword ptr [0x51b6d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 004632cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004632ce  89049a                 -mov dword ptr [edx + ebx*4], eax
    app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4) = cpu.eax;
    // 004632d1  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 004632d6  393498                 +cmp dword ptr [eax + ebx*4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004632d9  7512                   -jne 0x4632ed
    if (!cpu.flags.zf)
    {
        goto L_0x004632ed;
    }
    // 004632db  684cfe4900             -push 0x49fe4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849228 /*0x49fe4c*/;
    cpu.esp -= 4;
    // 004632e0  e82b19fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004632e5  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 004632ea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004632ed:
    // 004632ed  ff05ccb65100           -inc dword ptr [0x51b6cc]
    (app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */))++;
L_0x004632f3:
    // 004632f3  8b3498                 -mov esi, dword ptr [eax + ebx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 004632f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004632f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004632f8  6830fe4900             -push 0x49fe30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849200 /*0x49fe30*/;
    cpu.esp -= 4;
    // 004632fd  e8b53a0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00463302  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00463307  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463309  8d7c2444               -lea edi, [esp + 0x44]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0046330d  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046330f  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00463311  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00463315  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00463319  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046331c  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00463320  c744243824000000       -mov dword ptr [esp + 0x38], 0x24
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 36 /*0x24*/;
    // 00463328  c744243ce8000100       -mov dword ptr [esp + 0x3c], 0x100e8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 65768 /*0x100e8*/;
    // 00463330  894c2448               -mov dword ptr [esp + 0x48], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ecx;
    // 00463334  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00463336  2bd5                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00463338:
    // 00463338  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046333a  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0046333d  40                     -inc eax
    (cpu.eax)++;
    // 0046333e  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00463340  75f6                   -jne 0x463338
    if (!cpu.flags.zf)
    {
        goto L_0x00463338;
    }
    // 00463342  8a542424               -mov dl, byte ptr [esp + 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00463346  8d6e48                 -lea ebp, [esi + 0x48]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00463349  885641                 -mov byte ptr [esi + 0x41], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(65) /* 0x41 */) = cpu.dl;
    // 0046334c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463350  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00463353  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463357  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00463359  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046335a  668b510e               -mov dx, word ptr [ecx + 0xe]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0046335e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 00463361  885642                 -mov byte ptr [esi + 0x42], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(66) /* 0x42 */) = cpu.dl;
    // 00463364  a1c8b65100             -mov eax, dword ptr [0x51b6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355208) /* 0x51b6c8 */);
    // 00463369  8d542440               -lea edx, [esp + 0x40]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046336d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046336f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463370  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463371  ff510c                 -call dword ptr [ecx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463374  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463376  740a                   -je 0x463382
    if (cpu.flags.zf)
    {
        goto L_0x00463382;
    }
    // 00463378  6814fe4900             -push 0x49fe14
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849172 /*0x49fe14*/;
    cpu.esp -= 4;
    // 0046337d  e9a7000000             -jmp 0x463429
    goto L_0x00463429;
L_0x00463382:
    // 00463382  837d0000               +cmp dword ptr [ebp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463386  750d                   -jne 0x463395
    if (!cpu.flags.zf)
    {
        goto L_0x00463395;
    }
    // 00463388  680cfe4900             -push 0x49fe0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849164 /*0x49fe0c*/;
    cpu.esp -= 4;
    // 0046338d  e87e18fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463392  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463395:
    // 00463395  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00463399  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046339b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046339c  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004633a0  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004633a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004633a4  8d54243c               -lea edx, [esp + 0x3c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004633a8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004633aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004633ab  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004633af  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004633b0  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004633b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004633b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004633b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004633b8  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004633bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004633bd  7407                   -je 0x4633c6
    if (cpu.flags.zf)
    {
        goto L_0x004633c6;
    }
    // 004633bf  68f4fd4900             -push 0x49fdf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849140 /*0x49fdf4*/;
    cpu.esp -= 4;
    // 004633c4  eb63                   -jmp 0x463429
    goto L_0x00463429;
L_0x004633c6:
    // 004633c6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004633ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004633cc  750d                   -jne 0x4633db
    if (!cpu.flags.zf)
    {
        goto L_0x004633db;
    }
    // 004633ce  68dcfd4900             -push 0x49fddc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849116 /*0x49fddc*/;
    cpu.esp -= 4;
    // 004633d3  e83818fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004633d8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004633db:
    // 004633db  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004633df  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004633e3  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004633e7  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004633e9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004633ec  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004633ee  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004633f0  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004633f3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004633f5  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004633f9  8b357c704800           -mov esi, dword ptr [0x48707c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747388) /* 0x48707c */);
    // 004633ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463400  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463402  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00463406  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463407  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463409  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046340c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463410  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00463412  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00463414  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00463416  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463417  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046341b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046341c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046341d  ff514c                 -call dword ptr [ecx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463420  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463422  745f                   -je 0x463483
    if (cpu.flags.zf)
    {
        goto L_0x00463483;
    }
    // 00463424  68c0fd4900             -push 0x49fdc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849088 /*0x49fdc0*/;
    cpu.esp -= 4;
L_0x00463429:
    // 00463429  e889390100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046342e  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463432  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00463435  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00463437  741b                   -je 0x463454
    if (cpu.flags.zf)
    {
        goto L_0x00463454;
    }
    // 00463439  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046343c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463440  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00463442  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00463444  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00463446  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463447  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463448  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463449  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046344c  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x00463454:
    // 00463454  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00463457  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463459  740d                   -je 0x463468
    if (cpu.flags.zf)
    {
        goto L_0x00463468;
    }
    // 0046345b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046345d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046345e  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463461  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
L_0x00463468:
    // 00463468  6898fd4900             -push 0x49fd98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849048 /*0x49fd98*/;
    cpu.esp -= 4;
    // 0046346d  e89e17fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463472  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00463475  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00463478  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463479  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046347a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046347b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046347c  81c4b0000000           -add esp, 0xb0
    (cpu.esp) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 00463482  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463483:
    // 00463483  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00463487  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0046348f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463490  6884fd4900             -push 0x49fd84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849028 /*0x49fd84*/;
    cpu.esp -= 4;
    // 00463495  e81d390100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046349a  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0046349f  e8c3440100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 004634a4  a1c4b65100             -mov eax, dword ptr [0x51b6c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355204) /* 0x51b6c4 */);
    // 004634a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004634ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004634ad  ff15d8704800           -call dword ptr [0x4870d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747480) /* 0x4870d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004634b3  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004634b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634b9  81c4b0000000           -add esp, 0xb0
    (cpu.esp) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 004634bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4634c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004634c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004634c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004634c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004634c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004634c4  6a34                   -push 0x34
    app->getMemory<x86::reg32>(cpu.esp-4) = 52 /*0x34*/;
    cpu.esp -= 4;
    // 004634c6  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004634c8  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004634ca  e8ab3d0100             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 004634cf  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004634d1  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004634d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004634d6  3bf3                   +cmp esi, ebx
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
    // 004634d8  750d                   -jne 0x4634e7
    if (!cpu.flags.zf)
    {
        goto L_0x004634e7;
    }
    // 004634da  6880ff4900             -push 0x49ff80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849536 /*0x49ff80*/;
    cpu.esp -= 4;
    // 004634df  e82c17fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004634e4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004634e7:
    // 004634e7  a1d8b65100             -mov eax, dword ptr [0x51b6d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 004634ec  895e2c                 -mov dword ptr [esi + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 004634ef  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004634f2  a1d8b65100             -mov eax, dword ptr [0x51b6d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 004634f7  3bc3                   +cmp eax, ebx
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
    // 004634f9  7403                   -je 0x4634fe
    if (cpu.flags.zf)
    {
        goto L_0x004634fe;
    }
    // 004634fb  89702c                 -mov dword ptr [eax + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.esi;
L_0x004634fe:
    // 004634fe  8b0dd0b65100           -mov ecx, dword ptr [0x51b6d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00463504  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463508  8935d8b65100           -mov dword ptr [0x51b6d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */) = cpu.esi;
    // 0046350e  8b04a9                 -mov eax, dword ptr [ecx + ebp*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 00463511  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00463513  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00463516  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046351a  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0046351d  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00463520  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00463523  c746140000003f         -mov dword ptr [esi + 0x14], 0x3f000000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 1056964608 /*0x3f000000*/;
    // 0046352a  885e24                 -mov byte ptr [esi + 0x24], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bl;
    // 0046352d  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00463530  e8fb210000             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00463535  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00463538  d95e20                 -fstp dword ptr [esi + 0x20]
    app->getMemory<float>(cpu.esi + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046353b  395948                 +cmp dword ptr [ecx + 0x48], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046353e  750d                   -jne 0x46354d
    if (!cpu.flags.zf)
    {
        goto L_0x0046354d;
    }
    // 00463540  6860ff4900             -push 0x49ff60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849504 /*0x49ff60*/;
    cpu.esp -= 4;
    // 00463545  e8c616fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046354a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046354d:
    // 0046354d  a1c8b65100             -mov eax, dword ptr [0x51b6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355208) /* 0x51b6c8 */);
    // 00463552  8d4e28                 -lea ecx, [esi + 0x28]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00463555  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463556  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00463559  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046355b  8b4948                 -mov ecx, dword ptr [ecx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0046355e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046355f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463560  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463563  3bc3                   +cmp eax, ebx
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
    // 00463565  745b                   -je 0x4635c2
    if (cpu.flags.zf)
    {
        goto L_0x004635c2;
    }
    // 00463567  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046356c  7f25                   -jg 0x463593
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00463593;
    }
    // 0046356e  741c                   -je 0x46358c
    if (cpu.flags.zf)
    {
        goto L_0x0046358c;
    }
    // 00463570  3d0e000780             +cmp eax, 0x8007000e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942414 /*0x8007000e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463575  740e                   -je 0x463585
    if (cpu.flags.zf)
    {
        goto L_0x00463585;
    }
    // 00463577  3d57000780             +cmp eax, 0x80070057
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942487 /*0x80070057*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046357c  7537                   -jne 0x4635b5
    if (!cpu.flags.zf)
    {
        goto L_0x004635b5;
    }
    // 0046357e  6850ff4900             -push 0x49ff50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849488 /*0x49ff50*/;
    cpu.esp -= 4;
    // 00463583  eb28                   -jmp 0x4635ad
    goto L_0x004635ad;
L_0x00463585:
    // 00463585  6840ff4900             -push 0x49ff40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849472 /*0x49ff40*/;
    cpu.esp -= 4;
    // 0046358a  eb21                   -jmp 0x4635ad
    goto L_0x004635ad;
L_0x0046358c:
    // 0046358c  6830ff4900             -push 0x49ff30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849456 /*0x49ff30*/;
    cpu.esp -= 4;
    // 00463591  eb1a                   -jmp 0x4635ad
    goto L_0x004635ad;
L_0x00463593:
    // 00463593  3d32007888             +cmp eax, 0x88780032
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565746 /*0x88780032*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463598  740e                   -je 0x4635a8
    if (cpu.flags.zf)
    {
        goto L_0x004635a8;
    }
    // 0046359a  3daa007888             +cmp eax, 0x887800aa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565866 /*0x887800aa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046359f  7514                   -jne 0x4635b5
    if (!cpu.flags.zf)
    {
        goto L_0x004635b5;
    }
    // 004635a1  682cff4900             -push 0x49ff2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849452 /*0x49ff2c*/;
    cpu.esp -= 4;
    // 004635a6  eb05                   -jmp 0x4635ad
    goto L_0x004635ad;
L_0x004635a8:
    // 004635a8  681cff4900             -push 0x49ff1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849436 /*0x49ff1c*/;
    cpu.esp -= 4;
L_0x004635ad:
    // 004635ad  e805380100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004635b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004635b5:
    // 004635b5  68f8fe4900             -push 0x49fef8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849400 /*0x49fef8*/;
    cpu.esp -= 4;
    // 004635ba  e85116fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004635bf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004635c2:
    // 004635c2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004635c5  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004635c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004635c9  8b4248                 -mov eax, dword ptr [edx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004635cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004635cd  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004635cf  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004635d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4635e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004635e0  a1d8b65100             -mov eax, dword ptr [0x51b6d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 004635e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004635e6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004635e8  3bf0                   +cmp esi, eax
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
    // 004635ea  7515                   -jne 0x463601
    if (!cpu.flags.zf)
    {
        goto L_0x00463601;
    }
    // 004635ec  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004635ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004635f1  a3d8b65100             -mov dword ptr [0x51b6d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */) = cpu.eax;
    // 004635f6  741f                   -je 0x463617
    if (cpu.flags.zf)
    {
        goto L_0x00463617;
    }
    // 004635f8  c7402c00000000         -mov dword ptr [eax + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004635ff  eb16                   -jmp 0x463617
    goto L_0x00463617;
L_0x00463601:
    // 00463601  8b462c                 -mov eax, dword ptr [esi + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00463604  8b4e30                 -mov ecx, dword ptr [esi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00463607  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0046360a  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0046360d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046360f  7406                   -je 0x463617
    if (cpu.flags.zf)
    {
        goto L_0x00463617;
    }
    // 00463611  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00463614  89502c                 -mov dword ptr [eax + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.edx;
L_0x00463617:
    // 00463617  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0046361a  e8f1f5ffff             -call 0x462c10
    cpu.esp -= 4;
    sub_462c10(app, cpu);
    // 0046361f  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00463622  f6414102               +test byte ptr [ecx + 0x41], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(65) /* 0x41 */) & 2 /*0x2*/));
    // 00463626  7405                   -je 0x46362d
    if (cpu.flags.zf)
    {
        goto L_0x0046362d;
    }
    // 00463628  e803f8ffff             -call 0x462e30
    cpu.esp -= 4;
    sub_462e30(app, cpu);
L_0x0046362d:
    // 0046362d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046362e  e8813d0100             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00463633  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00463636  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463637  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463640  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00463645  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463646  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463647  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463648  8b3c88                 -mov edi, dword ptr [eax + ecx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0046364b  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046364d  f6474101               +test byte ptr [edi + 0x41], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(65) /* 0x41 */) & 1 /*0x1*/));
    // 00463651  7428                   -je 0x46367b
    if (cpu.flags.zf)
    {
        goto L_0x0046367b;
    }
    // 00463653  8b35d8b65100           -mov esi, dword ptr [0x51b6d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 00463659  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046365b  741e                   -je 0x46367b
    if (cpu.flags.zf)
    {
        goto L_0x0046367b;
    }
L_0x0046365d:
    // 0046365d  391e                   +cmp dword ptr [esi], ebx
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
    // 0046365f  7513                   -jne 0x463674
    if (!cpu.flags.zf)
    {
        goto L_0x00463674;
    }
    // 00463661  397e04                 +cmp dword ptr [esi + 4], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463664  750e                   -jne 0x463674
    if (!cpu.flags.zf)
    {
        goto L_0x00463674;
    }
    // 00463666  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00463669  d85c2410               -fcomp dword ptr [esp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0046366d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046366f  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00463672  7b0f                   -jnp 0x463683
    if (!cpu.flags.pf)
    {
        goto L_0x00463683;
    }
L_0x00463674:
    // 00463674  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00463677  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00463679  75e2                   -jne 0x46365d
    if (!cpu.flags.zf)
    {
        goto L_0x0046365d;
    }
L_0x0046367b:
    // 0046367b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046367c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046367d  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0046367f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463680  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00463683:
    // 00463683  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463684  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463685  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00463687  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463688  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_463690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463690  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 00463695  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463696  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046369a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046369c  7540                   -jne 0x4636de
    if (!cpu.flags.zf)
    {
        goto L_0x004636de;
    }
    // 0046369e  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004636a4  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004636aa  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004636ac  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004636af  e88cb9faff             -call 0x40f040
    cpu.esp -= 4;
    sub_40f040(app, cpu);
    // 004636b4  8b9684000000           -mov edx, dword ptr [esi + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004636ba  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004636bf  8b0c90                 -mov ecx, dword ptr [eax + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004636c2  8b8118030000           -mov eax, dword ptr [ecx + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 004636c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004636ca  7446                   -je 0x463712
    if (cpu.flags.zf)
    {
        goto L_0x00463712;
    }
    // 004636cc  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004636cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636d0  83ca01                 -or edx, 1
    cpu.edx |= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004636d3  885006                 -mov byte ptr [eax + 6], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004636d6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004636db  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004636de:
    // 004636de  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004636e0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004636e2  8a9680000000           -mov dl, byte ptr [esi + 0x80]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 004636e8  e843faffff             -call 0x463130
    cpu.esp -= 4;
    sub_463130(app, cpu);
    // 004636ed  83f8ff                 +cmp eax, -1
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
    // 004636f0  750f                   -jne 0x463701
    if (!cpu.flags.zf)
    {
        goto L_0x00463701;
    }
    // 004636f2  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004636f4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004636f6  e845b9faff             -call 0x40f040
    cpu.esp -= 4;
    sub_40f040(app, cpu);
    // 004636fb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004636fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636fe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00463701:
    // 00463701  a1e4b65100             -mov eax, dword ptr [0x51b6e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */);
    // 00463706  898694000000           -mov dword ptr [esi + 0x94], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */) = cpu.eax;
    // 0046370c  8935e4b65100           -mov dword ptr [0x51b6e4], esi
    app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */) = cpu.esi;
L_0x00463712:
    // 00463712  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00463717  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463718  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_463720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463720  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463721  8b35e4b65100           -mov esi, dword ptr [0x51b6e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */);
    // 00463727  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00463729  0f84d8000000           -je 0x463807
    if (cpu.flags.zf)
    {
        goto L_0x00463807;
    }
    // 0046372f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463731  8b2dd4704800           -mov ebp, dword ptr [0x4870d4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747476) /* 0x4870d4 */);
    // 00463737  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463738  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0046373d:
    // 0046373d  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00463743  8b0d2c845100           -mov ecx, dword ptr [0x51842c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 00463749  8bbe94000000           -mov edi, dword ptr [esi + 0x94]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 0046374f  3bc1                   +cmp eax, ecx
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
    // 00463751  0f8d82000000           -jge 0x4637d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004637d9;
    }
    // 00463757  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463759  7c7e                   -jl 0x4637d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004637d9;
    }
    // 0046375b  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00463761  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00463764  8498a8020000           -test byte ptr [eax + 0x2a8], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(680) /* 0x2a8 */) & cpu.bl));
    // 0046376a  746d                   -je 0x4637d9
    if (cpu.flags.zf)
    {
        goto L_0x004637d9;
    }
    // 0046376c  891de8b65100           -mov dword ptr [0x51b6e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355240) /* 0x51b6e8 */) = cpu.ebx;
    // 00463772  8a9680000000           -mov dl, byte ptr [esi + 0x80]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00463778  8b868c000000           -mov eax, dword ptr [esi + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0046377e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046377f  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00463785  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463786  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0046378c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046378d  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00463790  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00463792  e8f9000000             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 00463797  8b8e84000000           -mov ecx, dword ptr [esi + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0046379d  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004637a2  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004637a4  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004637a7  e894b8faff             -call 0x40f040
    cpu.esp -= 4;
    sub_40f040(app, cpu);
    // 004637ac  8b8e84000000           -mov ecx, dword ptr [esi + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004637b2  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004637b8  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 004637bb  8b8018030000           -mov eax, dword ptr [eax + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 004637c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004637c3  7408                   -je 0x4637cd
    if (cpu.flags.zf)
    {
        goto L_0x004637cd;
    }
    // 004637c5  8a4806                 -mov cl, byte ptr [eax + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004637c8  0bcb                   +or ecx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004637ca  884806                 -mov byte ptr [eax + 6], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = cpu.cl;
L_0x004637cd:
    // 004637cd  c705e8b6510000000000   -mov dword ptr [0x51b6e8], 0
    app->getMemory<x86::reg32>(x86::reg32(5355240) /* 0x51b6e8 */) = 0 /*0x0*/;
    // 004637d7  eb09                   -jmp 0x4637e2
    goto L_0x004637e2;
L_0x004637d9:
    // 004637d9  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004637db  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004637dd  e85eb8faff             -call 0x40f040
    cpu.esp -= 4;
    sub_40f040(app, cpu);
L_0x004637e2:
    // 004637e2  893de4b65100           -mov dword ptr [0x51b6e4], edi
    app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */) = cpu.edi;
    // 004637e8  8b9690000000           -mov edx, dword ptr [esi + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
    // 004637ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004637ef  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004637f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004637f2  e8bd3b0100             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 004637f7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004637fa  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004637fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004637fe  0f8539ffffff           -jne 0x46373d
    if (!cpu.flags.zf)
    {
        goto L_0x0046373d;
    }
    // 00463804  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463805  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463806  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00463807:
    // 00463807  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463808  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463810  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463811  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463812  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463813  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463814  6898000000             -push 0x98
    app->getMemory<x86::reg32>(cpu.esp-4) = 152 /*0x98*/;
    cpu.esp -= 4;
    // 00463819  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046381b  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046381d  e8583a0100             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00463822  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00463824  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00463827  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00463829  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046382b  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0046382d:
    // 0046382d  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046382f  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 00463832  40                     -inc eax
    (cpu.eax)++;
    // 00463833  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00463835  75f6                   -jne 0x46382d
    if (!cpu.flags.zf)
    {
        goto L_0x0046382d;
    }
    // 00463837  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046383b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046383f  888680000000           -mov byte ptr [esi + 0x80], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.al;
    // 00463845  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00463847  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046384b  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 00463851  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463855  899688000000           -mov dword ptr [esi + 0x88], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 0046385b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046385c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046385e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046385f  6890364600             -push 0x463690
    app->getMemory<x86::reg32>(cpu.esp-4) = 4601488 /*0x463690*/;
    cpu.esp -= 4;
    // 00463864  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00463866  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00463868  89868c000000           -mov dword ptr [esi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0046386e  ff1588704800           -call dword ptr [0x487088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747400) /* 0x487088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463874  898690000000           -mov dword ptr [esi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0046387a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046387b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046387c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046387d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046387e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_463890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463891  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463892  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463893  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00463895  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00463897  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463898  0f84a3000000           -je 0x463941
    if (cpu.flags.zf)
    {
        goto L_0x00463941;
    }
    // 0046389e  8b86a8020000           -mov eax, dword ptr [esi + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 004638a4  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004638a8  a900000040             +test eax, 0x40000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1073741824 /*0x40000000*/));
    // 004638ad  7409                   -je 0x4638b8
    if (cpu.flags.zf)
    {
        goto L_0x004638b8;
    }
    // 004638af  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004638b2  0f8489000000           -je 0x463941
    if (cpu.flags.zf)
    {
        goto L_0x00463941;
    }
L_0x004638b8:
    // 004638b8  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 004638bd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004638bf  a1e8b65100             -mov eax, dword ptr [0x51b6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355240) /* 0x51b6e8 */);
    // 004638c4  7522                   -jne 0x4638e8
    if (!cpu.flags.zf)
    {
        goto L_0x004638e8;
    }
    // 004638c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004638c8  7577                   -jne 0x463941
    if (!cpu.flags.zf)
    {
        goto L_0x00463941;
    }
    // 004638ca  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004638cd  7472                   -je 0x463941
    if (cpu.flags.zf)
    {
        goto L_0x00463941;
    }
L_0x004638cf:
    // 004638cf  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004638d3  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004638d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004638d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004638d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004638da  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004638dc  e82fffffff             -call 0x463810
    cpu.esp -= 4;
    sub_463810(app, cpu);
    // 004638e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638e5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004638e8:
    // 004638e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004638ea  7505                   -jne 0x4638f1
    if (!cpu.flags.zf)
    {
        goto L_0x004638f1;
    }
    // 004638ec  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004638ef  75de                   -jne 0x4638cf
    if (!cpu.flags.zf)
    {
        goto L_0x004638cf;
    }
L_0x004638f1:
    // 004638f1  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004638f3  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004638f9  e832f8ffff             -call 0x463130
    cpu.esp -= 4;
    sub_463130(app, cpu);
    // 004638fe  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00463900  83ffff                 +cmp edi, -1
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
    // 00463903  743c                   -je 0x463941
    if (cpu.flags.zf)
    {
        goto L_0x00463941;
    }
    // 00463905  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 0046390a  8b0cb8                 -mov ecx, dword ptr [eax + edi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 4);
    // 0046390d  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00463910  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463912  750d                   -jne 0x463921
    if (!cpu.flags.zf)
    {
        goto L_0x00463921;
    }
    // 00463914  68a8ff4900             -push 0x49ffa8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849576 /*0x49ffa8*/;
    cpu.esp -= 4;
    // 00463919  e8f212fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046391e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463921:
    // 00463921  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463925  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00463927  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463928  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046392a  e811fdffff             -call 0x463640
    cpu.esp -= 4;
    sub_463640(app, cpu);
    // 0046392f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00463931  750e                   -jne 0x463941
    if (!cpu.flags.zf)
    {
        goto L_0x00463941;
    }
    // 00463933  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463937  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463938  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463939  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046393a  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046393c  e87ffbffff             -call 0x4634c0
    cpu.esp -= 4;
    sub_4634c0(app, cpu);
L_0x00463941:
    // 00463941  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463942  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463943  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463944  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463945  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_463950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463950  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 00463955  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463956  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463957  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463958  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046395a  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046395c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046395e  746b                   -je 0x4639cb
    if (cpu.flags.zf)
    {
        goto L_0x004639cb;
    }
    // 00463960  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00463962  743e                   -je 0x4639a2
    if (cpu.flags.zf)
    {
        goto L_0x004639a2;
    }
    // 00463964  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00463969  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046396b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046396d  7e5c                   -jle 0x4639cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004639cb;
    }
L_0x0046396f:
    // 0046396f  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00463974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463975  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00463978  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463979  e832120200             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 0046397e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463981  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463983  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00463988  7409                   -je 0x463993
    if (cpu.flags.zf)
    {
        goto L_0x00463993;
    }
    // 0046398a  46                     -inc esi
    (cpu.esi)++;
    // 0046398b  3bf0                   +cmp esi, eax
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
    // 0046398d  7ce0                   -jl 0x46396f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046396f;
    }
    // 0046398f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463990  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463991  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463992  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463993:
    // 00463993  3bf0                   +cmp esi, eax
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
    // 00463995  7d34                   -jge 0x4639cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004639cb;
    }
    // 00463997  8b15d0b65100           -mov edx, dword ptr [0x51b6d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 0046399d  8b3cb2                 -mov edi, dword ptr [edx + esi*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 004639a0  eb02                   -jmp 0x4639a4
    goto L_0x004639a4;
L_0x004639a2:
    // 004639a2  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004639a4:
    // 004639a4  8b0dd8b65100           -mov ecx, dword ptr [0x51b6d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 004639aa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004639ac  741d                   -je 0x4639cb
    if (cpu.flags.zf)
    {
        goto L_0x004639cb;
    }
L_0x004639ae:
    // 004639ae  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004639b0  8b7130                 -mov esi, dword ptr [ecx + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004639b3  3bc3                   +cmp eax, ebx
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
    // 004639b5  750e                   -jne 0x4639c5
    if (!cpu.flags.zf)
    {
        goto L_0x004639c5;
    }
    // 004639b7  397904                 +cmp dword ptr [ecx + 4], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004639ba  7404                   -je 0x4639c0
    if (cpu.flags.zf)
    {
        goto L_0x004639c0;
    }
    // 004639bc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004639be  7505                   -jne 0x4639c5
    if (!cpu.flags.zf)
    {
        goto L_0x004639c5;
    }
L_0x004639c0:
    // 004639c0  e81bfcffff             -call 0x4635e0
    cpu.esp -= 4;
    sub_4635e0(app, cpu);
L_0x004639c5:
    // 004639c5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004639c7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004639c9  75e3                   -jne 0x4639ae
    if (!cpu.flags.zf)
    {
        goto L_0x004639ae;
    }
L_0x004639cb:
    // 004639cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4639d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004639d0  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 004639d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004639d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004639d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004639d8  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004639da  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004639dc  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004639de  7466                   -je 0x463a46
    if (cpu.flags.zf)
    {
        goto L_0x00463a46;
    }
    // 004639e0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004639e2  7462                   -je 0x463a46
    if (cpu.flags.zf)
    {
        goto L_0x00463a46;
    }
    // 004639e4  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 004639e9  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004639eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004639ed  7e57                   -jle 0x463a46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00463a46;
    }
L_0x004639ef:
    // 004639ef  a1d0b65100             -mov eax, dword ptr [0x51b6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 004639f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004639f5  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004639f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004639f9  e8b2110200             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 004639fe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463a01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463a03  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00463a08  740b                   -je 0x463a15
    if (cpu.flags.zf)
    {
        goto L_0x00463a15;
    }
    // 00463a0a  46                     -inc esi
    (cpu.esi)++;
    // 00463a0b  3bf0                   +cmp esi, eax
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
    // 00463a0d  7ce0                   -jl 0x4639ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004639ef;
    }
    // 00463a0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a12  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00463a15:
    // 00463a15  3bf0                   +cmp esi, eax
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
    // 00463a17  7d2d                   -jge 0x463a46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00463a46;
    }
    // 00463a19  8b15d0b65100           -mov edx, dword ptr [0x51b6d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 00463a1f  a1d8b65100             -mov eax, dword ptr [0x51b6d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 00463a24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463a26  8b34b2                 -mov esi, dword ptr [edx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00463a29  741b                   -je 0x463a46
    if (cpu.flags.zf)
    {
        goto L_0x00463a46;
    }
L_0x00463a2b:
    // 00463a2b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00463a2d  8b4830                 -mov ecx, dword ptr [eax + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00463a30  3bd3                   +cmp edx, ebx
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
    // 00463a32  750c                   -jne 0x463a40
    if (!cpu.flags.zf)
    {
        goto L_0x00463a40;
    }
    // 00463a34  397004                 +cmp dword ptr [eax + 4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463a37  7507                   -jne 0x463a40
    if (!cpu.flags.zf)
    {
        goto L_0x00463a40;
    }
    // 00463a39  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463a3d  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00463a40:
    // 00463a40  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00463a42  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00463a44  75e5                   -jne 0x463a2b
    if (!cpu.flags.zf)
    {
        goto L_0x00463a2b;
    }
L_0x00463a46:
    // 00463a46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a49  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_463a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463a50  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00463a55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463a56  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00463a58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463a59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463a5b  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00463a5d  7e13                   -jle 0x463a72
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00463a72;
    }
L_0x00463a5f:
    // 00463a5f  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00463a61  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463a63  e8e8feffff             -call 0x463950
    cpu.esp -= 4;
    sub_463950(app, cpu);
    // 00463a68  a1ccb65100             -mov eax, dword ptr [0x51b6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00463a6d  46                     -inc esi
    (cpu.esi)++;
    // 00463a6e  3bf0                   +cmp esi, eax
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
    // 00463a70  7ced                   -jl 0x463a5f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463a5f;
    }
L_0x00463a72:
    // 00463a72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463a80  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463a83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463a84  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00463a86  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00463a88  750d                   -jne 0x463a97
    if (!cpu.flags.zf)
    {
        goto L_0x00463a97;
    }
    // 00463a8a  68d0ff4900             -push 0x49ffd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849616 /*0x49ffd0*/;
    cpu.esp -= 4;
    // 00463a8f  e87c11fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463a94  83c404                 +add esp, 4
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
L_0x00463a97:
    // 00463a97  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00463a9a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00463a9f  844141                 -test byte ptr [ecx + 0x41], al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(65) /* 0x41 */) & cpu.al));
    // 00463aa2  7548                   -jne 0x463aec
    if (!cpu.flags.zf)
    {
        goto L_0x00463aec;
    }
    // 00463aa4  e8871c0000             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00463aa9  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00463aac  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463aae  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00463ab1  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00463ab9  8a4242                 -mov al, byte ptr [edx + 0x42]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(66) /* 0x42 */);
    // 00463abc  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00463abf  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00463ac1  d86620                 -fsub dword ptr [esi + 0x20]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(32) /* 0x20 */));
    // 00463ac4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00463ac8  da4c2404               -fimul dword ptr [esp + 4]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463acc  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00463ad0  da4c2404               -fimul dword ptr [esp + 4]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463ad4  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00463ad8  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00463ae0  da442404               -fiadd dword ptr [esp + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463ae4  e8a7320100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463ae9  d95e20                 -fstp dword ptr [esi + 0x20]
    app->getMemory<float>(cpu.esi + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00463aec:
    // 00463aec  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00463aef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463af0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463af3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463b00  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00463b05  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00463b08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463b09  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00463b0b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463b0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463b0d  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00463b0f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00463b11  750d                   -jne 0x463b20
    if (!cpu.flags.zf)
    {
        goto L_0x00463b20;
    }
    // 00463b13  683c004a00             -push 0x4a003c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849724 /*0x4a003c*/;
    cpu.esp -= 4;
    // 00463b18  e8f310fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463b1d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463b20:
    // 00463b20  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 00463b22  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00463b24  750d                   -jne 0x463b33
    if (!cpu.flags.zf)
    {
        goto L_0x00463b33;
    }
    // 00463b26  6818004a00             -push 0x4a0018
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849688 /*0x4a0018*/;
    cpu.esp -= 4;
    // 00463b2b  e8e010fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463b30  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463b33:
    // 00463b33  d986d0000000           -fld dword ptr [esi + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */)));
    // 00463b39  d8a3d0000000           -fsub dword ptr [ebx + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(208) /* 0xd0 */));
    // 00463b3f  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00463b43  d95c2420               -fstp dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463b47  d986d4000000           -fld dword ptr [esi + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */)));
    // 00463b4d  d8a3d4000000           -fsub dword ptr [ebx + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(212) /* 0xd4 */));
    // 00463b53  d95c2424               -fstp dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463b57  d986d8000000           -fld dword ptr [esi + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(216) /* 0xd8 */)));
    // 00463b5d  d8a3d8000000           -fsub dword ptr [ebx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(216) /* 0xd8 */));
    // 00463b63  d95c2428               -fstp dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463b67  e82491feff             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 00463b6c  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463b72  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463b74  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00463b77  7a0f                   -jp 0x463b88
    if (cpu.flags.pf)
    {
        goto L_0x00463b88;
    }
    // 00463b79  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463b7b  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00463b83  e996000000             -jmp 0x463c1e
    goto L_0x00463c1e;
L_0x00463b88:
    // 00463b88  d83d94744800           -fdivr dword ptr [0x487494]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)) / cpu.fpu.st(0);
    // 00463b8e  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00463b92  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00463b94  d95c2420               -fstp dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463b98  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 00463b9c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00463b9e  d95c2424               -fstp dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463ba2  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 00463ba6  d95c2428               -fstp dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463baa  d98320010000           -fld dword ptr [ebx + 0x120]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(288) /* 0x120 */)));
    // 00463bb0  d8a620010000           -fsub dword ptr [esi + 0x120]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(288) /* 0x120 */));
    // 00463bb6  d98324010000           -fld dword ptr [ebx + 0x124]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(292) /* 0x124 */)));
    // 00463bbc  d8a624010000           -fsub dword ptr [esi + 0x124]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(292) /* 0x124 */));
    // 00463bc2  d98328010000           -fld dword ptr [ebx + 0x128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(296) /* 0x128 */)));
    // 00463bc8  d8a628010000           -fsub dword ptr [esi + 0x128]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */));
    // 00463bce  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 00463bd2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00463bd4  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 00463bd8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00463bda  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00463bdc  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00463be0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00463be2  dc0d807a4800           -fmul qword ptr [0x487a80]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749952) /* 0x487a80 */));
    // 00463be8  d954240c               -fst dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    // 00463bec  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00463bf2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463bf4  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00463bf9  750a                   -jne 0x463c05
    if (!cpu.flags.zf)
    {
        goto L_0x00463c05;
    }
    // 00463bfb  c744240c0000803f       -mov dword ptr [esp + 0xc], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1065353216 /*0x3f800000*/;
    // 00463c03  eb19                   -jmp 0x463c1e
    goto L_0x00463c1e;
L_0x00463c05:
    // 00463c05  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00463c09  d81dec724800           -fcomp dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    cpu.fpu.pop();
    // 00463c0f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463c11  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463c14  7a08                   -jp 0x463c1e
    if (cpu.flags.pf)
    {
        goto L_0x00463c1e;
    }
    // 00463c16  c744240c000080bf       -mov dword ptr [esp + 0xc], 0xbf800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 3212836864 /*0xbf800000*/;
L_0x00463c1e:
    // 00463c1e  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00463c21  c74424100000803f       -mov dword ptr [esp + 0x10], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1065353216 /*0x3f800000*/;
    // 00463c29  f6414104               +test byte ptr [ecx + 0x41], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(65) /* 0x41 */) & 4 /*0x4*/));
    // 00463c2d  745d                   -je 0x463c8c
    if (cpu.flags.zf)
    {
        goto L_0x00463c8c;
    }
    // 00463c2f  8d8e1c010000           -lea ecx, [esi + 0x11c]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(284) /* 0x11c */);
    // 00463c35  e85690feff             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 00463c3a  d8b658020000           -fdiv dword ptr [esi + 0x258]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(600) /* 0x258 */));
    // 00463c40  d88e64020000           -fmul dword ptr [esi + 0x264]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(612) /* 0x264 */));
    // 00463c46  d81594744800           -fcom dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00463c4c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463c4e  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00463c53  750a                   -jne 0x463c5f
    if (!cpu.flags.zf)
    {
        goto L_0x00463c5f;
    }
    // 00463c55  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463c57  d90594744800           +fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00463c5d  eb15                   -jmp 0x463c74
    goto L_0x00463c74;
L_0x00463c5f:
    // 00463c5f  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463c65  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463c67  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463c6a  7a08                   -jp 0x463c74
    if (cpu.flags.pf)
    {
        goto L_0x00463c74;
    }
    // 00463c6c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463c6e  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
L_0x00463c74:
    // 00463c74  d88654020000           -fadd dword ptr [esi + 0x254]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(596) /* 0x254 */));
    // 00463c7a  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00463c7c  dc0dd8764800           -fmul qword ptr [0x4876d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749016) /* 0x4876d8 */));
    // 00463c82  dc0568734800           -fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 00463c88  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00463c8c:
    // 00463c8c  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00463c8f  8b4248                 -mov eax, dword ptr [edx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00463c92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463c94  750d                   -jne 0x463ca3
    if (!cpu.flags.zf)
    {
        goto L_0x00463ca3;
    }
    // 00463c96  68f8ff4900             -push 0x49fff8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849656 /*0x49fff8*/;
    cpu.esp -= 4;
    // 00463c9b  e8700ffcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463ca0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463ca3:
    // 00463ca3  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00463ca6  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463caa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463cab  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00463cae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463caf  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00463cb1  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00463cb4  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00463cbc  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00463cc0  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463cc4  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 00463cca  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00463cce  da4c2414               -fimul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00463cd2  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00463cd6  e8b5300100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463cdb  3da0860100             +cmp eax, 0x186a0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100000 /*0x186a0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463ce0  7607                   -jbe 0x463ce9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00463ce9;
    }
    // 00463ce2  b8a0860100             -mov eax, 0x186a0
    cpu.eax = 100000 /*0x186a0*/;
    // 00463ce7  eb0c                   -jmp 0x463cf5
    goto L_0x00463cf5;
L_0x00463ce9:
    // 00463ce9  3dd0070000             +cmp eax, 0x7d0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2000 /*0x7d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463cee  7305                   -jae 0x463cf5
    if (!cpu.flags.cf)
    {
        goto L_0x00463cf5;
    }
    // 00463cf0  b8d0070000             -mov eax, 0x7d0
    cpu.eax = 2000 /*0x7d0*/;
L_0x00463cf5:
    // 00463cf5  3b4718                 +cmp eax, dword ptr [edi + 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463cf8  740c                   -je 0x463d06
    if (cpu.flags.zf)
    {
        goto L_0x00463d06;
    }
    // 00463cfa  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00463cfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463cfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463cff  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00463d01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463d02  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00463d05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463d06:
    // 00463d06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463d07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463d08  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00463d0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463d0b  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00463d0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463d10  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463d14  dc25d8744800           -fsub qword ptr [0x4874d8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00463d1a  dc15a87a4800           -fcom qword ptr [0x487aa8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749992) /* 0x487aa8 */)));
    // 00463d20  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463d22  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463d25  7a08                   -jp 0x463d2f
    if (cpu.flags.pf)
    {
        goto L_0x00463d2f;
    }
    // 00463d27  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463d29  d905a07a4800           -fld dword ptr [0x487aa0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4749984) /* 0x487aa0 */)));
L_0x00463d2f:
    // 00463d2f  dc15987a4800           -fcom qword ptr [0x487a98]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749976) /* 0x487a98 */)));
    // 00463d35  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463d37  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00463d3c  7539                   -jne 0x463d77
    if (!cpu.flags.zf)
    {
        goto L_0x00463d77;
    }
    // 00463d3e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463d40  d905907a4800           -fld dword ptr [0x487a90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4749968) /* 0x487a90 */)));
L_0x00463d46:
    // 00463d46  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00463d4c  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 00463d4e  d9ec                   -fldlg2 
    cpu.fpu.push(0.30102999566398120);
    // 00463d50  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00463d52  d9f1                   -fyl2x 
    cpu.fpu.st(1) = cpu.fpu.log2(cpu.fpu.st(0)) * cpu.fpu.st(1);
    cpu.fpu.pop();
    // 00463d54  d80dbcb65100           -fmul dword ptr [0x51b6bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5355196) /* 0x51b6bc */));
    // 00463d5a  dc0d887a4800           -fmul qword ptr [0x487a88]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749960) /* 0x487a88 */));
    // 00463d60  e82b300100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463d65  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463d67  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00463d6b  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00463d6f  e81c300100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463d74  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00463d77:
    // 00463d77  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463d7d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463d7f  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463d82  7ac2                   -jp 0x463d46
    if (cpu.flags.pf)
    {
        goto L_0x00463d46;
    }
    // 00463d84  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 00463d8a  d9ec                   -fldlg2 
    cpu.fpu.push(0.30102999566398120);
    // 00463d8c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00463d8e  d9f1                   -fyl2x 
    cpu.fpu.st(1) = cpu.fpu.log2(cpu.fpu.st(0)) * cpu.fpu.st(1);
    cpu.fpu.pop();
    // 00463d90  d80dbcb65100           -fmul dword ptr [0x51b6bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5355196) /* 0x51b6bc */));
    // 00463d96  dc0d50754800           -fmul qword ptr [0x487550]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748624) /* 0x487550 */));
    // 00463d9c  e8ef2f0100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463da1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00463da5  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00463da9  e8e22f0100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463dae  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_463dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463dc0  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00463dc5  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00463dc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463dc9  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00463dcb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463dcc  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00463dce  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00463dd0  750d                   -jne 0x463ddf
    if (!cpu.flags.zf)
    {
        goto L_0x00463ddf;
    }
    // 00463dd2  6884004a00             -push 0x4a0084
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849796 /*0x4a0084*/;
    cpu.esp -= 4;
    // 00463dd7  e8340efcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463ddc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463ddf:
    // 00463ddf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463de0  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00463de2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00463de4  750d                   -jne 0x463df3
    if (!cpu.flags.zf)
    {
        goto L_0x00463df3;
    }
    // 00463de6  6860004a00             -push 0x4a0060
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849760 /*0x4a0060*/;
    cpu.esp -= 4;
    // 00463deb  e8200efcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463df0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463df3:
    // 00463df3  d986d0000000           -fld dword ptr [esi + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */)));
    // 00463df9  d8a7d0000000           -fsub dword ptr [edi + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(208) /* 0xd0 */));
    // 00463dff  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463e03  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463e07  d986d4000000           -fld dword ptr [esi + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */)));
    // 00463e0d  d8a7d4000000           -fsub dword ptr [edi + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(212) /* 0xd4 */));
    // 00463e13  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463e17  d986d8000000           -fld dword ptr [esi + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(216) /* 0xd8 */)));
    // 00463e1d  d8a7d8000000           -fsub dword ptr [edi + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(216) /* 0xd8 */));
    // 00463e23  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463e27  e8648efeff             -call 0x44cc90
    cpu.esp -= 4;
    sub_44cc90(app, cpu);
    // 00463e2c  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463e32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e33  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463e35  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00463e3a  7571                   -jne 0x463ead
    if (!cpu.flags.zf)
    {
        goto L_0x00463ead;
    }
    // 00463e3c  d83d94744800           -fdivr dword ptr [0x487494]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)) / cpu.fpu.st(0);
    // 00463e42  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00463e46  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00463e48  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463e4c  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00463e50  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00463e52  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463e56  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00463e5a  d9542414               -fst dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    // 00463e5e  d84f7c                 -fmul dword ptr [edi + 0x7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(124) /* 0x7c */));
    // 00463e61  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00463e65  d84f78                 -fmul dword ptr [edi + 0x78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(120) /* 0x78 */));
    // 00463e68  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00463e6a  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00463e6e  d84f74                 -fmul dword ptr [edi + 0x74]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(116) /* 0x74 */));
    // 00463e71  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00463e73  dc1568734800           -fcom qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    // 00463e79  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463e7b  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00463e80  7508                   -jne 0x463e8a
    if (!cpu.flags.zf)
    {
        goto L_0x00463e8a;
    }
    // 00463e82  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463e84  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
L_0x00463e8a:
    // 00463e8a  dc15f0794800           -fcom qword ptr [0x4879f0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749808) /* 0x4879f0 */)));
    // 00463e90  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463e92  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463e95  7a08                   -jp 0x463e9f
    if (cpu.flags.pf)
    {
        goto L_0x00463e9f;
    }
    // 00463e97  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463e99  d905ec724800           +fld dword ptr [0x4872ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
L_0x00463e9f:
    // 00463e9f  dc0568734800           +fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 00463ea5  dc0dd8744800           +fmul qword ptr [0x4874d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00463eab  eb08                   -jmp 0x463eb5
    goto L_0x00463eb5;
L_0x00463ead:
    // 00463ead  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463eaf  d905b4754800           -fld dword ptr [0x4875b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */)));
L_0x00463eb5:
    // 00463eb5  d85314                 -fcom dword ptr [ebx + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
    // 00463eb8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463eba  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00463ebd  7b0b                   -jnp 0x463eca
    if (!cpu.flags.pf)
    {
        goto L_0x00463eca;
    }
    // 00463ebf  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463ec2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463ec3  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00463ec5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463ec6  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00463ec9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463eca:
    // 00463eca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463ecb  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00463ecd  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463ecf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463ed0  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00463ed3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463ee0  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463ee4  dc1d60734800           -fcomp qword ptr [0x487360]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748128) /* 0x487360 */)));
    cpu.fpu.pop();
    // 00463eea  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463eec  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00463ef1  751c                   -jne 0x463f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00463f0f;
    }
    // 00463ef3  d9ec                   -fldlg2 
    cpu.fpu.push(0.30102999566398120);
    // 00463ef5  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463ef9  d9f1                   -fyl2x 
    cpu.fpu.st(1) = cpu.fpu.log2(cpu.fpu.st(0)) * cpu.fpu.st(1);
    cpu.fpu.pop();
    // 00463efb  d80dbcb65100           -fmul dword ptr [0x51b6bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5355196) /* 0x51b6bc */));
    // 00463f01  dc0d50754800           -fmul qword ptr [0x487550]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748624) /* 0x487550 */));
    // 00463f07  e8842e0100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00463f0c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00463f0f:
    // 00463f0f  b8f0d8ffff             -mov eax, 0xffffd8f0
    cpu.eax = 4294957296 /*0xffffd8f0*/;
    // 00463f14  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_463f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463f20  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463f23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463f24  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00463f26  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00463f28  750d                   -jne 0x463f37
    if (!cpu.flags.zf)
    {
        goto L_0x00463f37;
    }
    // 00463f2a  68c8004a00             -push 0x4a00c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849864 /*0x4a00c8*/;
    cpu.esp -= 4;
    // 00463f2f  e8dc0cfcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463f34  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463f37:
    // 00463f37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463f38  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 00463f3a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00463f3c  750d                   -jne 0x463f4b
    if (!cpu.flags.zf)
    {
        goto L_0x00463f4b;
    }
    // 00463f3e  68a8004a00             -push 0x4a00a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849832 /*0x4a00a8*/;
    cpu.esp -= 4;
    // 00463f43  e8c80cfcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00463f48  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00463f4b:
    // 00463f4b  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00463f4e  dc0db07a4800           -fmul qword ptr [0x487ab0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4750000) /* 0x487ab0 */));
    // 00463f54  8b86dc000000           -mov eax, dword ptr [esi + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(220) /* 0xdc */);
    // 00463f5a  8b8ee0000000           -mov ecx, dword ptr [esi + 0xe0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(224) /* 0xe0 */);
    // 00463f60  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00463f64  8b96e4000000           -mov edx, dword ptr [esi + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */);
    // 00463f6a  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00463f6e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00463f72  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00463f76  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00463f7a  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00463f7c  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00463f80  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00463f82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f83  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463f85  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463f88  7a0b                   -jp 0x463f95
    if (cpu.flags.pf)
    {
        goto L_0x00463f95;
    }
    // 00463f8a  d90534734800           +fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463f90  e991000000             -jmp 0x464026
    goto L_0x00464026;
L_0x00463f95:
    // 00463f95  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00463f99  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00463f9b  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463f9f  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00463fa1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463fa3  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463fa6  7a08                   -jp 0x463fb0
    if (cpu.flags.pf)
    {
        goto L_0x00463fb0;
    }
    // 00463fa8  d90534734800           +fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463fae  eb76                   -jmp 0x464026
    goto L_0x00464026;
L_0x00463fb0:
    // 00463fb0  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00463fb4  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00463fb6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00463fba  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00463fbc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463fbe  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463fc1  7a08                   -jp 0x463fcb
    if (cpu.flags.pf)
    {
        goto L_0x00463fcb;
    }
    // 00463fc3  d90534734800           +fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463fc9  eb5b                   -jmp 0x464026
    goto L_0x00464026;
L_0x00463fcb:
    // 00463fcb  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00463fcf  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00463fd3  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00463fd7  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00463fdb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00463fdd  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00463fe1  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00463fe5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00463fe7  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 00463fe9  d86c2404               -fsubr dword ptr [esp + 4]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)) - cpu.fpu.st(0);
    // 00463fed  d8742404               -fdiv dword ptr [esp + 4]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 00463ff1  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00463ff7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00463ff9  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00463ffc  7a0a                   -jp 0x464008
    if (cpu.flags.pf)
    {
        goto L_0x00464008;
    }
    // 00463ffe  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00464000  d90534734800           +fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00464006  eb1e                   -jmp 0x464026
    goto L_0x00464026;
L_0x00464008:
    // 00464008  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0046400a  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046400c  d84f10                 -fmul dword ptr [edi + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */));
    // 0046400f  d81594744800           -fcom dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00464015  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00464017  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0046401c  7508                   -jne 0x464026
    if (!cpu.flags.zf)
    {
        goto L_0x00464026;
    }
    // 0046401e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00464020  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
L_0x00464026:
    // 00464026  d8570c                 -fcom dword ptr [edi + 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 00464029  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046402b  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0046402e  7b0a                   -jnp 0x46403a
    if (!cpu.flags.pf)
    {
        goto L_0x0046403a;
    }
    // 00464030  d95f0c                 -fstp dword ptr [edi + 0xc]
    app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00464033  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00464035  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464036  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464039  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046403a:
    // 0046403a  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046403c  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0046403e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046403f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464042  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464050  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00464053  d85a0c                 -fcomp dword ptr [edx + 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    cpu.fpu.pop();
    // 00464056  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00464058  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0046405d  7506                   -jne 0x464065
    if (!cpu.flags.zf)
    {
        goto L_0x00464065;
    }
    // 0046405f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00464064  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464065:
    // 00464065  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00464068  d85a0c                 -fcomp dword ptr [edx + 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    cpu.fpu.pop();
    // 0046406b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046406d  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00464070  7a21                   -jp 0x464093
    if (cpu.flags.pf)
    {
        goto L_0x00464093;
    }
    // 00464072  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00464075  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464076  8b721c                 -mov esi, dword ptr [edx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00464079  3bc6                   +cmp eax, esi
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
    // 0046407b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046407c  7315                   -jae 0x464093
    if (!cpu.flags.cf)
    {
        goto L_0x00464093;
    }
    // 0046407e  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00464081  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00464086  844141                 -test byte ptr [ecx + 0x41], al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(65) /* 0x41 */) & cpu.al));
    // 00464089  7508                   -jne 0x464093
    if (!cpu.flags.zf)
    {
        goto L_0x00464093;
    }
    // 0046408b  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046408e  844241                 -test byte ptr [edx + 0x41], al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(65) /* 0x41 */) & cpu.al));
    // 00464091  7402                   -je 0x464095
    if (cpu.flags.zf)
    {
        goto L_0x00464095;
    }
L_0x00464093:
    // 00464093  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00464095:
    // 00464095  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4640a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004640a0  a1d8b65100             -mov eax, dword ptr [0x51b6d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 004640a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004640a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004640a8  0f8498000000           -je 0x464146
    if (cpu.flags.zf)
    {
        goto L_0x00464146;
    }
    // 004640ae  8b7830                 -mov edi, dword ptr [eax + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004640b1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004640b3  0f848d000000           -je 0x464146
    if (cpu.flags.zf)
    {
        goto L_0x00464146;
    }
    // 004640b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004640ba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004640bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x004640bc:
    // 004640bc  833f00                 +cmp dword ptr [edi], 0
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
    // 004640bf  750d                   -jne 0x4640ce
    if (!cpu.flags.zf)
    {
        goto L_0x004640ce;
    }
    // 004640c1  68e8004a00             -push 0x4a00e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849896 /*0x4a00e8*/;
    cpu.esp -= 4;
    // 004640c6  e8450bfcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004640cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004640ce:
    // 004640ce  8b5f2c                 -mov ebx, dword ptr [edi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 004640d1  8b6f30                 -mov ebp, dword ptr [edi + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 004640d4  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004640d6  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004640d8  e873ffffff             -call 0x464050
    cpu.esp -= 4;
    sub_464050(app, cpu);
    // 004640dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004640df  7458                   -je 0x464139
    if (cpu.flags.zf)
    {
        goto L_0x00464139;
    }
    // 004640e1  8b732c                 -mov esi, dword ptr [ebx + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    // 004640e4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004640e6  7414                   -je 0x4640fc
    if (cpu.flags.zf)
    {
        goto L_0x004640fc;
    }
L_0x004640e8:
    // 004640e8  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004640ea  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004640ec  e85fffffff             -call 0x464050
    cpu.esp -= 4;
    sub_464050(app, cpu);
    // 004640f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004640f3  7407                   -je 0x4640fc
    if (cpu.flags.zf)
    {
        goto L_0x004640fc;
    }
    // 004640f5  8b762c                 -mov esi, dword ptr [esi + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004640f8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004640fa  75ec                   -jne 0x4640e8
    if (!cpu.flags.zf)
    {
        goto L_0x004640e8;
    }
L_0x004640fc:
    // 004640fc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004640fe  896b30                 -mov dword ptr [ebx + 0x30], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = cpu.ebp;
    // 00464101  7406                   -je 0x464109
    if (cpu.flags.zf)
    {
        goto L_0x00464109;
    }
    // 00464103  8b472c                 -mov eax, dword ptr [edi + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 00464106  89452c                 -mov dword ptr [ebp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x00464109:
    // 00464109  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046410b  751a                   -jne 0x464127
    if (!cpu.flags.zf)
    {
        goto L_0x00464127;
    }
    // 0046410d  8b0dd8b65100           -mov ecx, dword ptr [0x51b6d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 00464113  89792c                 -mov dword ptr [ecx + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 00464116  8b15d8b65100           -mov edx, dword ptr [0x51b6d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 0046411c  895730                 -mov dword ptr [edi + 0x30], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0046411f  893dd8b65100           -mov dword ptr [0x51b6d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */) = cpu.edi;
    // 00464125  eb0f                   -jmp 0x464136
    goto L_0x00464136;
L_0x00464127:
    // 00464127  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0046412a  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0046412d  8b4e30                 -mov ecx, dword ptr [esi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00464130  89792c                 -mov dword ptr [ecx + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 00464133  897e30                 -mov dword ptr [esi + 0x30], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.edi;
L_0x00464136:
    // 00464136  89772c                 -mov dword ptr [edi + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.esi;
L_0x00464139:
    // 00464139  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046413b  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046413d  0f8579ffffff           -jne 0x4640bc
    if (!cpu.flags.zf)
    {
        goto L_0x004640bc;
    }
    // 00464143  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464144  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464145  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00464146:
    // 00464146  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464147  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464150  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464151  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 00464156  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464157  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464158  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464159  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046415b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046415c  0f84bf020000           -je 0x464421
    if (cpu.flags.zf)
    {
        goto L_0x00464421;
    }
    // 00464162  a1bcfc4900             -mov eax, dword ptr [0x49fcbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4848828) /* 0x49fcbc */);
    // 00464167  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00464169  3bc5                   +cmp eax, ebp
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
    // 0046416b  0f85b0020000           -jne 0x464421
    if (!cpu.flags.zf)
    {
        goto L_0x00464421;
    }
    // 00464171  e8aaf5ffff             -call 0x463720
    cpu.esp -= 4;
    sub_463720(app, cpu);
    // 00464176  8b35d8b65100           -mov esi, dword ptr [0x51b6d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 0046417c  3bf5                   +cmp esi, ebp
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
    // 0046417e  0f84b3000000           -je 0x464237
    if (cpu.flags.zf)
    {
        goto L_0x00464237;
    }
    // 00464184  bb00000040             -mov ebx, 0x40000000
    cpu.ebx = 1073741824 /*0x40000000*/;
L_0x00464189:
    // 00464189  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046418c  8b7e30                 -mov edi, dword ptr [esi + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0046418f  396848                 +cmp dword ptr [eax + 0x48], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464192  750d                   -jne 0x4641a1
    if (!cpu.flags.zf)
    {
        goto L_0x004641a1;
    }
    // 00464194  68c0014a00             -push 0x4a01c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850112 /*0x4a01c0*/;
    cpu.esp -= 4;
    // 00464199  e8720afcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046419e  83c404                 +add esp, 4
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
L_0x004641a1:
    // 004641a1  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004641a3  8599a8020000           -test dword ptr [ecx + 0x2a8], ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) & cpu.ebx));
    // 004641a9  7405                   -je 0x4641b0
    if (cpu.flags.zf)
    {
        goto L_0x004641b0;
    }
    // 004641ab  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004641ae  eb07                   -jmp 0x4641b7
    goto L_0x004641b7;
L_0x004641b0:
    // 004641b0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004641b2  e869fdffff             -call 0x463f20
    cpu.esp -= 4;
    sub_463f20(app, cpu);
L_0x004641b7:
    // 004641b7  833da8a4510001         +cmp dword ptr [0x51a4a8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5350568) /* 0x51a4a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004641be  7519                   -jne 0x4641d9
    if (!cpu.flags.zf)
    {
        goto L_0x004641d9;
    }
    // 004641c0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004641c2  3bc5                   +cmp eax, ebp
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
    // 004641c4  7413                   -je 0x4641d9
    if (cpu.flags.zf)
    {
        goto L_0x004641d9;
    }
    // 004641c6  3928                   +cmp dword ptr [eax], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004641c8  7403                   -je 0x4641cd
    if (cpu.flags.zf)
    {
        goto L_0x004641cd;
    }
    // 004641ca  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x004641cd:
    // 004641cd  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004641d0  f6424101               +test byte ptr [edx + 0x41], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(65) /* 0x41 */) & 1 /*0x1*/));
    // 004641d4  7403                   -je 0x4641d9
    if (cpu.flags.zf)
    {
        goto L_0x004641d9;
    }
    // 004641d6  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x004641d9:
    // 004641d9  d9460c                 -fld dword ptr [esi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004641dc  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004641e2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004641e4  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 004641e7  7a09                   -jp 0x4641f2
    if (cpu.flags.pf)
    {
        goto L_0x004641f2;
    }
    // 004641e9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004641ec  f6404101               +test byte ptr [eax + 0x41], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(65) /* 0x41 */) & 1 /*0x1*/));
    // 004641f0  7434                   -je 0x464226
    if (cpu.flags.zf)
    {
        goto L_0x00464226;
    }
L_0x004641f2:
    // 004641f2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004641f4  e887f8ffff             -call 0x463a80
    cpu.esp -= 4;
    sub_463a80(app, cpu);
    // 004641f9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004641fc  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004641ff  3b4844                 +cmp ecx, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464202  7206                   -jb 0x46420a
    if (cpu.flags.cf)
    {
        goto L_0x0046420a;
    }
    // 00464204  f6404101               +test byte ptr [eax + 0x41], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(65) /* 0x41 */) & 1 /*0x1*/));
    // 00464208  741c                   -je 0x464226
    if (cpu.flags.zf)
    {
        goto L_0x00464226;
    }
L_0x0046420a:
    // 0046420a  392e                   +cmp dword ptr [esi], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046420c  750d                   -jne 0x46421b
    if (!cpu.flags.zf)
    {
        goto L_0x0046421b;
    }
    // 0046420e  689c014a00             -push 0x4a019c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850076 /*0x4a019c*/;
    cpu.esp -= 4;
    // 00464213  e8f809fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00464218  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046421b:
    // 0046421b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046421d  f682a802000001         +test byte ptr [edx + 0x2a8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(680) /* 0x2a8 */) & 1 /*0x1*/));
    // 00464224  7507                   -jne 0x46422d
    if (!cpu.flags.zf)
    {
        goto L_0x0046422d;
    }
L_0x00464226:
    // 00464226  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464228  e8b3f3ffff             -call 0x4635e0
    cpu.esp -= 4;
    sub_4635e0(app, cpu);
L_0x0046422d:
    // 0046422d  3bfd                   +cmp edi, ebp
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
    // 0046422f  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00464231  0f8552ffffff           -jne 0x464189
    if (!cpu.flags.zf)
    {
        goto L_0x00464189;
    }
L_0x00464237:
    // 00464237  e864feffff             -call 0x4640a0
    cpu.esp -= 4;
    sub_4640a0(app, cpu);
    // 0046423c  8b0dccb65100           -mov ecx, dword ptr [0x51b6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 00464242  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00464244  3bcd                   +cmp ecx, ebp
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
    // 00464246  7e19                   -jle 0x464261
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464261;
    }
L_0x00464248:
    // 00464248  8b0dd0b65100           -mov ecx, dword ptr [0x51b6d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355216) /* 0x51b6d0 */);
    // 0046424e  40                     -inc eax
    (cpu.eax)++;
    // 0046424f  8b5481fc               -mov edx, dword ptr [ecx + eax*4 - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
    // 00464253  c6424000               -mov byte ptr [edx + 0x40], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00464257  8b0dccb65100           -mov ecx, dword ptr [0x51b6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355212) /* 0x51b6cc */);
    // 0046425d  3bc1                   +cmp eax, ecx
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
    // 0046425f  7ce7                   -jl 0x464248
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464248;
    }
L_0x00464261:
    // 00464261  8b1dd8b65100           -mov ebx, dword ptr [0x51b6d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 00464267  3bdd                   +cmp ebx, ebp
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
    // 00464269  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046426b  7417                   -je 0x464284
    if (cpu.flags.zf)
    {
        goto L_0x00464284;
    }
    // 0046426d  b1fd                   -mov cl, 0xfd
    cpu.cl = 253 /*0xfd*/;
L_0x0046426f:
    // 0046426f  8a5824                 -mov bl, byte ptr [eax + 0x24]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00464272  22d9                   -and bl, cl
    cpu.bl &= x86::reg8(x86::sreg8(cpu.cl));
    // 00464274  885824                 -mov byte ptr [eax + 0x24], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.bl;
    // 00464277  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 0046427a  3bc5                   +cmp eax, ebp
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
    // 0046427c  75f1                   -jne 0x46426f
    if (!cpu.flags.zf)
    {
        goto L_0x0046426f;
    }
    // 0046427e  8b1dd8b65100           -mov ebx, dword ptr [0x51b6d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
L_0x00464284:
    // 00464284  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0046428c:
    // 0046428c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046428e  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00464290  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00464292  7453                   -je 0x4642e7
    if (cpu.flags.zf)
    {
        goto L_0x004642e7;
    }
L_0x00464294:
    // 00464294  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00464297  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046429b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046429d  8a4740                 -mov al, byte ptr [edi + 0x40]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(64) /* 0x40 */);
    // 004642a0  3bc1                   +cmp eax, ecx
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
    // 004642a2  7534                   -jne 0x4642d8
    if (!cpu.flags.zf)
    {
        goto L_0x004642d8;
    }
    // 004642a4  8a4a24                 -mov cl, byte ptr [edx + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004642a7  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004642aa  752c                   -jne 0x4642d8
    if (!cpu.flags.zf)
    {
        goto L_0x004642d8;
    }
    // 004642ac  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004642af  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004642b5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004642b7  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004642bc  751a                   -jne 0x4642d8
    if (!cpu.flags.zf)
    {
        goto L_0x004642d8;
    }
    // 004642be  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004642c1  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004642c6  884a24                 -mov byte ptr [edx + 0x24], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.cl;
    // 004642c9  8a4f40                 -mov cl, byte ptr [edi + 0x40]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(64) /* 0x40 */);
    // 004642cc  fec1                   -inc cl
    (cpu.cl)++;
    // 004642ce  45                     -inc ebp
    (cpu.ebp)++;
    // 004642cf  884f40                 -mov byte ptr [edi + 0x40], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(64) /* 0x40 */) = cpu.cl;
    // 004642d2  8b1dd8b65100           -mov ebx, dword ptr [0x51b6d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
L_0x004642d8:
    // 004642d8  3b2dd4b65100           +cmp ebp, dword ptr [0x51b6d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5355220) /* 0x51b6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004642de  7419                   -je 0x4642f9
    if (cpu.flags.zf)
    {
        goto L_0x004642f9;
    }
    // 004642e0  8b5230                 -mov edx, dword ptr [edx + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004642e3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004642e5  75ad                   -jne 0x464294
    if (!cpu.flags.zf)
    {
        goto L_0x00464294;
    }
L_0x004642e7:
    // 004642e7  3b2dd4b65100           +cmp ebp, dword ptr [0x51b6d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5355220) /* 0x51b6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004642ed  740a                   -je 0x4642f9
    if (cpu.flags.zf)
    {
        goto L_0x004642f9;
    }
    // 004642ef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004642f1  7406                   -je 0x4642f9
    if (cpu.flags.zf)
    {
        goto L_0x004642f9;
    }
    // 004642f3  ff442410               +inc dword ptr [esp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004642f7  eb93                   -jmp 0x46428c
    goto L_0x0046428c;
L_0x004642f9:
    // 004642f9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004642fb  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004642fd  0f841e010000           -je 0x464421
    if (cpu.flags.zf)
    {
        goto L_0x00464421;
    }
    // 00464303  b3fe                   -mov bl, 0xfe
    cpu.bl = 254 /*0xfe*/;
L_0x00464305:
    // 00464305  8a4624                 -mov al, byte ptr [esi + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00464308  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0046430a  7521                   -jne 0x46432d
    if (!cpu.flags.zf)
    {
        goto L_0x0046432d;
    }
    // 0046430c  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0046430e  741d                   -je 0x46432d
    if (cpu.flags.zf)
    {
        goto L_0x0046432d;
    }
    // 00464310  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00464313  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464314  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00464316  ff5148                 -call dword ptr [ecx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464319  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046431b  740d                   -je 0x46432a
    if (cpu.flags.zf)
    {
        goto L_0x0046432a;
    }
    // 0046431d  6884014a00             -push 0x4a0184
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850052 /*0x4a0184*/;
    cpu.esp -= 4;
    // 00464322  e8e908fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00464327  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046432a:
    // 0046432a  205e24                 -and byte ptr [esi + 0x24], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) &= x86::reg8(x86::sreg8(cpu.bl));
L_0x0046432d:
    // 0046432d  8a4624                 -mov al, byte ptr [esi + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00464330  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00464332  7460                   -je 0x464394
    if (cpu.flags.zf)
    {
        goto L_0x00464394;
    }
    // 00464334  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00464336  755c                   -jne 0x464394
    if (!cpu.flags.zf)
    {
        goto L_0x00464394;
    }
    // 00464338  d9460c                 -fld dword ptr [esi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 0046433b  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00464341  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00464343  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00464348  754a                   -jne 0x464394
    if (!cpu.flags.zf)
    {
        goto L_0x00464394;
    }
    // 0046434a  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0046434d  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00464350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464351  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464352  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00464354  ff5234                 -call dword ptr [edx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464357  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464359  740d                   -je 0x464368
    if (cpu.flags.zf)
    {
        goto L_0x00464368;
    }
    // 0046435b  686c014a00             -push 0x4a016c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850028 /*0x4a016c*/;
    cpu.esp -= 4;
    // 00464360  e8ab08fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00464365  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464368:
    // 00464368  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046436b  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0046436e  8a4a41                 -mov cl, byte ptr [edx + 0x41]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(65) /* 0x41 */);
    // 00464371  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00464373  83e101                 -and ecx, 1
    cpu.ecx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00464376  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464377  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464379  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046437b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046437c  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046437f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464381  740d                   -je 0x464390
    if (cpu.flags.zf)
    {
        goto L_0x00464390;
    }
    // 00464383  686c014a00             -push 0x4a016c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850028 /*0x4a016c*/;
    cpu.esp -= 4;
    // 00464388  e88308fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046438d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464390:
    // 00464390  804e2401               -or byte ptr [esi + 0x24], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00464394:
    // 00464394  f6462401               +test byte ptr [esi + 0x24], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) & 1 /*0x1*/));
    // 00464398  747c                   -je 0x464416
    if (cpu.flags.zf)
    {
        goto L_0x00464416;
    }
    // 0046439a  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0046439d  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004643a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004643a1  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 004643a3  e838fbffff             -call 0x463ee0
    cpu.esp -= 4;
    sub_463ee0(app, cpu);
    // 004643a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004643a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004643aa  ff553c                 -call dword ptr [ebp + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004643ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004643af  740d                   -je 0x4643be
    if (cpu.flags.zf)
    {
        goto L_0x004643be;
    }
    // 004643b1  6848014a00             -push 0x4a0148
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849992 /*0x4a0148*/;
    cpu.esp -= 4;
    // 004643b6  e85508fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004643bb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004643be:
    // 004643be  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004643c0  e83bf7ffff             -call 0x463b00
    cpu.esp -= 4;
    sub_463b00(app, cpu);
    // 004643c5  3c01                   +cmp al, 1
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
    // 004643c7  751e                   -jne 0x4643e7
    if (!cpu.flags.zf)
    {
        goto L_0x004643e7;
    }
    // 004643c9  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004643cc  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004643cf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004643d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004643d1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004643d3  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004643d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004643d8  740d                   -je 0x4643e7
    if (cpu.flags.zf)
    {
        goto L_0x004643e7;
    }
    // 004643da  6824014a00             -push 0x4a0124
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849956 /*0x4a0124*/;
    cpu.esp -= 4;
    // 004643df  e82c08fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004643e4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004643e7:
    // 004643e7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004643e9  e8d2f9ffff             -call 0x463dc0
    cpu.esp -= 4;
    sub_463dc0(app, cpu);
    // 004643ee  3c01                   +cmp al, 1
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
    // 004643f0  7524                   -jne 0x464416
    if (!cpu.flags.zf)
    {
        goto L_0x00464416;
    }
    // 004643f2  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004643f5  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004643f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004643f9  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 004643fb  e810f9ffff             -call 0x463d10
    cpu.esp -= 4;
    sub_463d10(app, cpu);
    // 00464400  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464401  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464402  ff5540                 -call dword ptr [ebp + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464405  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464407  740d                   -je 0x464416
    if (cpu.flags.zf)
    {
        goto L_0x00464416;
    }
    // 00464409  6804014a00             -push 0x4a0104
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849924 /*0x4a0104*/;
    cpu.esp -= 4;
    // 0046440e  e8fd07fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00464413  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464416:
    // 00464416  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00464419  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046441b  0f85e4feffff           -jne 0x464305
    if (!cpu.flags.zf)
    {
        goto L_0x00464305;
    }
L_0x00464421:
    // 00464421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464423  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464424  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464425  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464426  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464430  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464431  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00464433  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00464436  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00464439  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046443a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046443b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046443c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046443e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046443f  e87a3f0100             -call 0x4783be
    cpu.esp -= 4;
    sub_4783be(app, cpu);
    // 00464444  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00464446  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464447  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00464449  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046444d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0046444f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464450  c744242400000000       -mov dword ptr [esp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00464458  e842330100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0046445d  8b35d8b65100           -mov esi, dword ptr [0x51b6d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 00464463  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00464466  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00464468  7479                   -je 0x4644e3
    if (cpu.flags.zf)
    {
        goto L_0x004644e3;
    }
L_0x0046446a:
    // 0046446a  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046446d  f6414101               +test byte ptr [ecx + 0x41], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(65) /* 0x41 */) & 1 /*0x1*/));
    // 00464471  7469                   -je 0x4644dc
    if (cpu.flags.zf)
    {
        goto L_0x004644dc;
    }
    // 00464473  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00464475  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464476  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00464478  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046447c  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 0046447f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00464481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464482  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00464486  e814330100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0046448b  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046448e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046448f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00464491  6a4c                   -push 0x4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 76 /*0x4c*/;
    cpu.esp -= 4;
    // 00464493  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464494  e806330100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00464499  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046449a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046449c  6a34                   -push 0x34
    app->getMemory<x86::reg32>(cpu.esp-4) = 52 /*0x34*/;
    cpu.esp -= 4;
    // 0046449e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046449f  e8fb320100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 004644a4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004644a7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004644a9  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 004644ac  8a4841                 -mov cl, byte ptr [eax + 0x41]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(65) /* 0x41 */);
    // 004644af  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004644b2  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004644b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004644b5  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004644b7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004644ba  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004644be  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004644c1  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004644c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004644c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004644c6  6810024a00             -push 0x4a0210
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850192 /*0x4a0210*/;
    cpu.esp -= 4;
    // 004644cb  e8e7280100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004644d0  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004644d4  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004644d7  40                     -inc eax
    (cpu.eax)++;
    // 004644d8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004644dc:
    // 004644dc  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004644df  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004644e1  7587                   -jne 0x46446a
    if (!cpu.flags.zf)
    {
        goto L_0x0046446a;
    }
L_0x004644e3:
    // 004644e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004644e4  e8d53e0100             -call 0x4783be
    cpu.esp -= 4;
    sub_4783be(app, cpu);
    // 004644e9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004644eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004644ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004644ed  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004644ef  e87d370100             -call 0x477c71
    cpu.esp -= 4;
    sub_477c71(app, cpu);
    // 004644f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004644f5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004644f7  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004644fb  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004644fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004644fe  e89c320100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00464503  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464505  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464506  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464507  e865370100             -call 0x477c71
    cpu.esp -= 4;
    sub_477c71(app, cpu);
    // 0046450c  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00464510  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464511  68ec014a00             -push 0x4a01ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850156 /*0x4a01ec*/;
    cpu.esp -= 4;
    // 00464516  e89c280100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046451b  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046451e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046451f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464520  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464521  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00464523  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464524  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464530  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464531  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00464533  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00464536  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0046453c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046453d  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046453f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464540  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00464542  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464546  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00464548  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464549  e83a310100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046454e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464552  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464555  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464557  0f84aa000000           -je 0x464607
    if (cpu.flags.zf)
    {
        goto L_0x00464607;
    }
L_0x0046455d:
    // 0046455d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046455e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00464560  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464564  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00464566  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464567  e81c310100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046456c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046456d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046456f  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00464573  6a4c                   -push 0x4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 76 /*0x4c*/;
    cpu.esp -= 4;
    // 00464575  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464576  e80d310100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046457b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046457c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046457e  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00464582  6a34                   -push 0x34
    app->getMemory<x86::reg32>(cpu.esp-4) = 52 /*0x34*/;
    cpu.esp -= 4;
    // 00464584  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464585  e8fe300100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0046458a  8b8c24b1000000         -mov ecx, dword ptr [esp + 0xb1]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(177) /* 0xb1 */);
    // 00464591  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00464594  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00464598  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046459e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004645a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004645a3  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004645a9  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004645ac  8d442454               -lea eax, [esp + 0x54]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004645b0  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004645b4  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004645b8  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004645bb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004645bd  6834024a00             -push 0x4a0234
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850228 /*0x4a0234*/;
    cpu.esp -= 4;
    // 004645c2  e8f0270100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004645c7  8b8c24a1000000         -mov ecx, dword ptr [esp + 0xa1]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(161) /* 0xa1 */);
    // 004645ce  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004645d2  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004645d5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004645d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004645da  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004645de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645df  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004645e5  81e1ffff0000           +and ecx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004645eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004645ec  8b148a                 -mov edx, dword ptr [edx + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 004645ef  8d4c244c               -lea ecx, [esp + 0x4c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004645f3  e898f2ffff             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    // 004645f8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004645fc  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004645fd  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00464601  0f8556ffffff           -jne 0x46455d
    if (!cpu.flags.zf)
    {
        goto L_0x0046455d;
    }
L_0x00464607:
    // 00464607  8b0dd8b65100           -mov ecx, dword ptr [0x51b6d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 0046460d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046460f  7417                   -je 0x464628
    if (cpu.flags.zf)
    {
        goto L_0x00464628;
    }
L_0x00464611:
    // 00464611  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00464614  8b7130                 -mov esi, dword ptr [ecx + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 00464617  f6404102               +test byte ptr [eax + 0x41], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(65) /* 0x41 */) & 2 /*0x2*/));
    // 0046461b  7405                   -je 0x464622
    if (cpu.flags.zf)
    {
        goto L_0x00464622;
    }
    // 0046461d  e8beefffff             -call 0x4635e0
    cpu.esp -= 4;
    sub_4635e0(app, cpu);
L_0x00464622:
    // 00464622  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00464624  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464626  75e9                   -jne 0x464611
    if (!cpu.flags.zf)
    {
        goto L_0x00464611;
    }
L_0x00464628:
    // 00464628  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464629  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046462b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046462c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464630  a0e0b65100             -mov al, byte ptr [0x51b6e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 00464635  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464636  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00464638  7459                   -je 0x464693
    if (cpu.flags.zf)
    {
        goto L_0x00464693;
    }
    // 0046463a  8b35d8b65100           -mov esi, dword ptr [0x51b6d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 00464640  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00464642  744f                   -je 0x464693
    if (cpu.flags.zf)
    {
        goto L_0x00464693;
    }
L_0x00464644:
    // 00464644  f6462401               +test byte ptr [esi + 0x24], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) & 1 /*0x1*/));
    // 00464648  7442                   -je 0x46468c
    if (cpu.flags.zf)
    {
        goto L_0x0046468c;
    }
    // 0046464a  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0046464d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046464e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00464650  ff5148                 -call dword ptr [ecx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464653  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464655  740d                   -je 0x464664
    if (cpu.flags.zf)
    {
        goto L_0x00464664;
    }
    // 00464657  6884014a00             -push 0x4a0184
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850052 /*0x4a0184*/;
    cpu.esp -= 4;
    // 0046465c  e8af05fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00464661  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464664:
    // 00464664  8a5624                 -mov dl, byte ptr [esi + 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00464667  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0046466a  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0046466d  68f0d8ffff             -push 0xffffd8f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4294957296 /*0xffffd8f0*/;
    cpu.esp -= 4;
    // 00464672  885624                 -mov byte ptr [esi + 0x24], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.dl;
    // 00464675  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00464677  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464678  ff523c                 -call dword ptr [edx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046467b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046467d  740d                   -je 0x46468c
    if (cpu.flags.zf)
    {
        goto L_0x0046468c;
    }
    // 0046467f  6848014a00             -push 0x4a0148
    app->getMemory<x86::reg32>(cpu.esp-4) = 4849992 /*0x4a0148*/;
    cpu.esp -= 4;
    // 00464684  e88705fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00464689  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046468c:
    // 0046468c  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0046468f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00464691  75b1                   -jne 0x464644
    if (!cpu.flags.zf)
    {
        goto L_0x00464644;
    }
L_0x00464693:
    // 00464693  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464694  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4646a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004646a0  a10cb85100             -mov eax, dword ptr [0x51b80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355532) /* 0x51b80c */);
    // 004646a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004646a7  7413                   -je 0x4646bc
    if (cpu.flags.zf)
    {
        goto L_0x004646bc;
    }
    // 004646a9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004646ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004646ac  ff158c704800           -call dword ptr [0x48708c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747404) /* 0x48708c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004646b2  c7050cb8510000000000   -mov dword ptr [0x51b80c], 0
    app->getMemory<x86::reg32>(x86::reg32(5355532) /* 0x51b80c */) = 0 /*0x0*/;
L_0x004646bc:
    // 004646bc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004646be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4646c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004646c0  a10cb85100             -mov eax, dword ptr [0x51b80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355532) /* 0x51b80c */);
    // 004646c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004646c7  7532                   -jne 0x4646fb
    if (!cpu.flags.zf)
    {
        goto L_0x004646fb;
    }
    // 004646c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004646ca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004646cc  6880024a00             -push 0x4a0280
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850304 /*0x4a0280*/;
    cpu.esp -= 4;
    // 004646d1  6880024a00             -push 0x4a0280
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850304 /*0x4a0280*/;
    cpu.esp -= 4;
    // 004646d6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004646d8  e834470100             -call 0x478e11
    cpu.esp -= 4;
    sub_478e11(app, cpu);
    // 004646dd  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004646df  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004646e2  83feff                 +cmp esi, -1
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
    // 004646e5  750d                   -jne 0x4646f4
    if (!cpu.flags.zf)
    {
        goto L_0x004646f4;
    }
    // 004646e7  686c024a00             -push 0x4a026c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850284 /*0x4a026c*/;
    cpu.esp -= 4;
    // 004646ec  e81f05fcff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004646f1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004646f4:
    // 004646f4  89350cb85100           -mov dword ptr [0x51b80c], esi
    app->getMemory<x86::reg32>(x86::reg32(5355532) /* 0x51b80c */) = cpu.esi;
    // 004646fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004646fb:
    // 004646fb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004646fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464700  a104ef5100             -mov eax, dword ptr [0x51ef04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00464705  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00464708  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464709  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046470a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046470b  ff150c724800           -call dword ptr [0x48720c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747788) /* 0x48720c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464711  8b2d08724800           -mov ebp, dword ptr [0x487208]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747784) /* 0x487208 */);
    // 00464717  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00464719  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046471a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046471b  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046471f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464721  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464723  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464725  7437                   -je 0x46475e
    if (cpu.flags.zf)
    {
        goto L_0x0046475e;
    }
    // 00464727  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464728  8b1ddc714800           -mov ebx, dword ptr [0x4871dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747740) /* 0x4871dc */);
    // 0046472e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046472f  8b3de0714800           -mov edi, dword ptr [0x4871e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747744) /* 0x4871e0 */);
L_0x00464735:
    // 00464735  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464739  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046473a  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046473c  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464740  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464741  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464743  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464745  46                     -inc esi
    (cpu.esi)++;
    // 00464746  83f932                 +cmp ecx, 0x32
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464749  7f11                   -jg 0x46475c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046475c;
    }
    // 0046474b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046474d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046474f  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00464753  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464755  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464756  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464758  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046475a  75d9                   -jne 0x464735
    if (!cpu.flags.zf)
    {
        goto L_0x00464735;
    }
L_0x0046475c:
    // 0046475c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046475d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046475e:
    // 0046475e  e85d33ffff             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00464763  e8e8e3ffff             -call 0x462b50
    cpu.esp -= 4;
    sub_462b50(app, cpu);
    // 00464768  a158024a00             -mov eax, dword ptr [0x4a0258]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4850264) /* 0x4a0258 */);
    // 0046476d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046476e  83f8ff                 +cmp eax, -1
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
    // 00464771  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464772  7409                   -je 0x46477d
    if (cpu.flags.zf)
    {
        goto L_0x0046477d;
    }
    // 00464774  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464775  e809400100             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 0046477a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046477d:
    // 0046477d  a15c024a00             -mov eax, dword ptr [0x4a025c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4850268) /* 0x4a025c */);
    // 00464782  83f8ff                 +cmp eax, -1
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
    // 00464785  7409                   -je 0x464790
    if (cpu.flags.zf)
    {
        goto L_0x00464790;
    }
    // 00464787  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464788  e8f63f0100             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 0046478d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464790:
    // 00464790  a160024a00             -mov eax, dword ptr [0x4a0260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4850272) /* 0x4a0260 */);
    // 00464795  83f8ff                 +cmp eax, -1
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
    // 00464798  7409                   -je 0x4647a3
    if (cpu.flags.zf)
    {
        goto L_0x004647a3;
    }
    // 0046479a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046479b  e8e33f0100             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 004647a0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004647a3:
    // 004647a3  a164024a00             -mov eax, dword ptr [0x4a0264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4850276) /* 0x4a0264 */);
    // 004647a8  83f8ff                 +cmp eax, -1
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
    // 004647ab  7409                   -je 0x4647b6
    if (cpu.flags.zf)
    {
        goto L_0x004647b6;
    }
    // 004647ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004647ae  e8d03f0100             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 004647b3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004647b6:
    // 004647b6  a100b85100             -mov eax, dword ptr [0x51b800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355520) /* 0x51b800 */);
    // 004647bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004647bd  7409                   -je 0x4647c8
    if (cpu.flags.zf)
    {
        goto L_0x004647c8;
    }
    // 004647bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004647c0  e8122e0100             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 004647c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004647c8:
    // 004647c8  a10cb85100             -mov eax, dword ptr [0x51b80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355532) /* 0x51b80c */);
    // 004647cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004647cf  7413                   -je 0x4647e4
    if (cpu.flags.zf)
    {
        goto L_0x004647e4;
    }
    // 004647d1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004647d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004647d4  ff158c704800           -call dword ptr [0x48708c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747404) /* 0x48708c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004647da  c7050cb8510000000000   -mov dword ptr [0x51b80c], 0
    app->getMemory<x86::reg32>(x86::reg32(5355532) /* 0x51b80c */) = 0 /*0x0*/;
L_0x004647e4:
    // 004647e4  a108b85100             -mov eax, dword ptr [0x51b808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355528) /* 0x51b808 */);
    // 004647e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004647eb  7418                   -je 0x464805
    if (cpu.flags.zf)
    {
        goto L_0x00464805;
    }
    // 004647ed  a104ef5100             -mov eax, dword ptr [0x51ef04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 004647f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004647f4  68a0024a00             -push 0x4a02a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850336 /*0x4a02a0*/;
    cpu.esp -= 4;
    // 004647f9  688c024a00             -push 0x4a028c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850316 /*0x4a028c*/;
    cpu.esp -= 4;
    // 004647fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004647ff  ff15ec714800           -call dword ptr [0x4871ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747756) /* 0x4871ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00464805:
    // 00464805  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464809  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046480c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464810  a110b85100             -mov eax, dword ptr [0x51b810]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355536) /* 0x51b810 */);
    // 00464815  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00464818  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046481a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046481b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046481c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046481d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046481e  7540                   -jne 0x464860
    if (!cpu.flags.zf)
    {
        goto L_0x00464860;
    }
    // 00464820  e8eb99fbff             -call 0x41e210
    cpu.esp -= 4;
    sub_41e210(app, cpu);
    // 00464825  8b35e4714800           -mov esi, dword ptr [0x4871e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747748) /* 0x4871e4 */);
    // 0046482b  8b3de0714800           -mov edi, dword ptr [0x4871e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747744) /* 0x4871e0 */);
    // 00464831  8b1ddc714800           -mov ebx, dword ptr [0x4871dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747740) /* 0x4871dc */);
    // 00464837  bd14000000             -mov ebp, 0x14
    cpu.ebp = 20 /*0x14*/;
L_0x0046483c:
    // 0046483c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046483e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464840  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464842  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00464846  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464848  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464849  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046484b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046484d  7411                   -je 0x464860
    if (cpu.flags.zf)
    {
        goto L_0x00464860;
    }
    // 0046484f  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464853  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464854  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464856  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046485a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046485b  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046485d  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046485e  75dc                   -jne 0x46483c
    if (!cpu.flags.zf)
    {
        goto L_0x0046483c;
    }
L_0x00464860:
    // 00464860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464862  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464863  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464864  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00464867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464870  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00464873  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 00464877  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464878  8b35e4714800           -mov esi, dword ptr [0x4871e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747748) /* 0x4871e4 */);
    // 0046487e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00464880  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464882  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464884  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464886  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464887  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464889  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046488b  7431                   -je 0x4648be
    if (cpu.flags.zf)
    {
        goto L_0x004648be;
    }
    // 0046488d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046488e  8b1ddc714800           -mov ebx, dword ptr [0x4871dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747740) /* 0x4871dc */);
    // 00464894  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464895  8b3de0714800           -mov edi, dword ptr [0x4871e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747744) /* 0x4871e0 */);
L_0x0046489b:
    // 0046489b  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046489f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004648a0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004648a2  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004648a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004648a7  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004648a9  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004648ad  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004648af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004648b1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004648b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004648b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004648b6  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004648b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004648ba  75df                   -jne 0x46489b
    if (!cpu.flags.zf)
    {
        goto L_0x0046489b;
    }
    // 004648bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004648bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004648be:
    // 004648be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004648bf  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004648c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4648d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004648d0  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 004648d6  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004648da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004648db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004648dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004648dd  8bb42494000000         -mov esi, dword ptr [esp + 0x94]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 004648e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004648e5  8bbc249c000000         -mov edi, dword ptr [esp + 0x9c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004648ec  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004648ee  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004648f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004648f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004648f3  68e80e4a00             -push 0x4a0ee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853480 /*0x4a0ee8*/;
    cpu.esp -= 4;
    // 004648f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004648f9  e8fa240100             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004648fe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464901  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464905  e8260d0000             -call 0x465630
    cpu.esp -= 4;
    sub_465630(app, cpu);
    // 0046490a  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0046490f  e853300100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00464914  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00464916  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464919  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046491a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046491b  68e80e4a00             -push 0x4a0ee8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853480 /*0x4a0ee8*/;
    cpu.esp -= 4;
    // 00464920  e892240100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464925  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0046492a  e838300100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0046492f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00464931  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00464934  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00464936  3d050000c0             +cmp eax, 0xc0000005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225477 /*0xc0000005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046493b  7510                   -jne 0x46494d
    if (!cpu.flags.zf)
    {
        goto L_0x0046494d;
    }
    // 0046493d  68780e4a00             -push 0x4a0e78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853368 /*0x4a0e78*/;
    cpu.esp -= 4;
    // 00464942  68580e4a00             -push 0x4a0e58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853336 /*0x4a0e58*/;
    cpu.esp -= 4;
    // 00464947  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464948  e99e010000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x0046494d:
    // 0046494d  3d8c0000c0             +cmp eax, 0xc000008c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225612 /*0xc000008c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464952  7510                   -jne 0x464964
    if (!cpu.flags.zf)
    {
        goto L_0x00464964;
    }
    // 00464954  68e00d4a00             -push 0x4a0de0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853216 /*0x4a0de0*/;
    cpu.esp -= 4;
    // 00464959  68bc0d4a00             -push 0x4a0dbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853180 /*0x4a0dbc*/;
    cpu.esp -= 4;
    // 0046495e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046495f  e987010000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464964:
    // 00464964  3d03000080             +cmp eax, 0x80000003
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483651 /*0x80000003*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464969  7510                   -jne 0x46497b
    if (!cpu.flags.zf)
    {
        goto L_0x0046497b;
    }
    // 0046496b  689c0d4a00             -push 0x4a0d9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853148 /*0x4a0d9c*/;
    cpu.esp -= 4;
    // 00464970  68840d4a00             -push 0x4a0d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853124 /*0x4a0d84*/;
    cpu.esp -= 4;
    // 00464975  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464976  e970010000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x0046497b:
    // 0046497b  3d02000080             +cmp eax, 0x80000002
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483650 /*0x80000002*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464980  7510                   -jne 0x464992
    if (!cpu.flags.zf)
    {
        goto L_0x00464992;
    }
    // 00464982  68b00c4a00             -push 0x4a0cb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852912 /*0x4a0cb0*/;
    cpu.esp -= 4;
    // 00464987  688c0c4a00             -push 0x4a0c8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852876 /*0x4a0c8c*/;
    cpu.esp -= 4;
    // 0046498c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046498d  e959010000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464992:
    // 00464992  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 00464997  7510                   -jne 0x4649a9
    if (!cpu.flags.zf)
    {
        goto L_0x004649a9;
    }
    // 00464999  68f00b4a00             -push 0x4a0bf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852720 /*0x4a0bf0*/;
    cpu.esp -= 4;
    // 0046499e  68d00b4a00             -push 0x4a0bd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852688 /*0x4a0bd0*/;
    cpu.esp -= 4;
    // 004649a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004649a4  e942010000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x004649a9:
    // 004649a9  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 004649ae  7510                   -jne 0x4649c0
    if (!cpu.flags.zf)
    {
        goto L_0x004649c0;
    }
    // 004649b0  68780b4a00             -push 0x4a0b78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852600 /*0x4a0b78*/;
    cpu.esp -= 4;
    // 004649b5  68580b4a00             -push 0x4a0b58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852568 /*0x4a0b58*/;
    cpu.esp -= 4;
    // 004649ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004649bb  e92b010000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x004649c0:
    // 004649c0  3d8f0000c0             +cmp eax, 0xc000008f
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
    // 004649c5  7510                   -jne 0x4649d7
    if (!cpu.flags.zf)
    {
        goto L_0x004649d7;
    }
    // 004649c7  68f80a4a00             -push 0x4a0af8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852472 /*0x4a0af8*/;
    cpu.esp -= 4;
    // 004649cc  68d40a4a00             -push 0x4a0ad4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852436 /*0x4a0ad4*/;
    cpu.esp -= 4;
    // 004649d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004649d2  e914010000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x004649d7:
    // 004649d7  3d900000c0             +cmp eax, 0xc0000090
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
    // 004649dc  7510                   -jne 0x4649ee
    if (!cpu.flags.zf)
    {
        goto L_0x004649ee;
    }
    // 004649de  68800a4a00             -push 0x4a0a80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852352 /*0x4a0a80*/;
    cpu.esp -= 4;
    // 004649e3  685c0a4a00             -push 0x4a0a5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852316 /*0x4a0a5c*/;
    cpu.esp -= 4;
    // 004649e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004649e9  e9fd000000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x004649ee:
    // 004649ee  3d910000c0             +cmp eax, 0xc0000091
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
    // 004649f3  7510                   -jne 0x464a05
    if (!cpu.flags.zf)
    {
        goto L_0x00464a05;
    }
    // 004649f5  68f0094a00             -push 0x4a09f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852208 /*0x4a09f0*/;
    cpu.esp -= 4;
    // 004649fa  68d4094a00             -push 0x4a09d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852180 /*0x4a09d4*/;
    cpu.esp -= 4;
    // 004649ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a00  e9e6000000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a05:
    // 00464a05  3d920000c0             +cmp eax, 0xc0000092
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
    // 00464a0a  7510                   -jne 0x464a1c
    if (!cpu.flags.zf)
    {
        goto L_0x00464a1c;
    }
    // 00464a0c  6880094a00             -push 0x4a0980
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852096 /*0x4a0980*/;
    cpu.esp -= 4;
    // 00464a11  6864094a00             -push 0x4a0964
    app->getMemory<x86::reg32>(cpu.esp-4) = 4852068 /*0x4a0964*/;
    cpu.esp -= 4;
    // 00464a16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a17  e9cf000000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a1c:
    // 00464a1c  3d930000c0             +cmp eax, 0xc0000093
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
    // 00464a21  7510                   -jne 0x464a33
    if (!cpu.flags.zf)
    {
        goto L_0x00464a33;
    }
    // 00464a23  68f8084a00             -push 0x4a08f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851960 /*0x4a08f8*/;
    cpu.esp -= 4;
    // 00464a28  68e0084a00             -push 0x4a08e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851936 /*0x4a08e0*/;
    cpu.esp -= 4;
    // 00464a2d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a2e  e9b8000000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a33:
    // 00464a33  3d1d0000c0             +cmp eax, 0xc000001d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225501 /*0xc000001d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464a38  7510                   -jne 0x464a4a
    if (!cpu.flags.zf)
    {
        goto L_0x00464a4a;
    }
    // 00464a3a  68ac084a00             -push 0x4a08ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851884 /*0x4a08ac*/;
    cpu.esp -= 4;
    // 00464a3f  688c084a00             -push 0x4a088c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851852 /*0x4a088c*/;
    cpu.esp -= 4;
    // 00464a44  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a45  e9a1000000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a4a:
    // 00464a4a  3d060000c0             +cmp eax, 0xc0000006
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225478 /*0xc0000006*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464a4f  7510                   -jne 0x464a61
    if (!cpu.flags.zf)
    {
        goto L_0x00464a61;
    }
    // 00464a51  68b8074a00             -push 0x4a07b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851640 /*0x4a07b8*/;
    cpu.esp -= 4;
    // 00464a56  689c074a00             -push 0x4a079c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851612 /*0x4a079c*/;
    cpu.esp -= 4;
    // 00464a5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a5c  e98a000000             -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a61:
    // 00464a61  3d940000c0             +cmp eax, 0xc0000094
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225620 /*0xc0000094*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464a66  750d                   -jne 0x464a75
    if (!cpu.flags.zf)
    {
        goto L_0x00464a75;
    }
    // 00464a68  6850074a00             -push 0x4a0750
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851536 /*0x4a0750*/;
    cpu.esp -= 4;
    // 00464a6d  682c074a00             -push 0x4a072c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851500 /*0x4a072c*/;
    cpu.esp -= 4;
    // 00464a72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a73  eb76                   -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a75:
    // 00464a75  3d950000c0             +cmp eax, 0xc0000095
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225621 /*0xc0000095*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464a7a  750d                   -jne 0x464a89
    if (!cpu.flags.zf)
    {
        goto L_0x00464a89;
    }
    // 00464a7c  68c8064a00             -push 0x4a06c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851400 /*0x4a06c8*/;
    cpu.esp -= 4;
    // 00464a81  68ac064a00             -push 0x4a06ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851372 /*0x4a06ac*/;
    cpu.esp -= 4;
    // 00464a86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a87  eb62                   -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a89:
    // 00464a89  3d260000c0             +cmp eax, 0xc0000026
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225510 /*0xc0000026*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464a8e  750d                   -jne 0x464a9d
    if (!cpu.flags.zf)
    {
        goto L_0x00464a9d;
    }
    // 00464a90  6800064a00             -push 0x4a0600
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851200 /*0x4a0600*/;
    cpu.esp -= 4;
    // 00464a95  68dc054a00             -push 0x4a05dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851164 /*0x4a05dc*/;
    cpu.esp -= 4;
    // 00464a9a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464a9b  eb4e                   -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464a9d:
    // 00464a9d  3d250000c0             +cmp eax, 0xc0000025
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225509 /*0xc0000025*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464aa2  750d                   -jne 0x464ab1
    if (!cpu.flags.zf)
    {
        goto L_0x00464ab1;
    }
    // 00464aa4  6888054a00             -push 0x4a0588
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851080 /*0x4a0588*/;
    cpu.esp -= 4;
    // 00464aa9  6860054a00             -push 0x4a0560
    app->getMemory<x86::reg32>(cpu.esp-4) = 4851040 /*0x4a0560*/;
    cpu.esp -= 4;
    // 00464aae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464aaf  eb3a                   -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464ab1:
    // 00464ab1  3d960000c0             +cmp eax, 0xc0000096
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225622 /*0xc0000096*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464ab6  750d                   -jne 0x464ac5
    if (!cpu.flags.zf)
    {
        goto L_0x00464ac5;
    }
    // 00464ab8  68f8044a00             -push 0x4a04f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850936 /*0x4a04f8*/;
    cpu.esp -= 4;
    // 00464abd  68dc044a00             -push 0x4a04dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850908 /*0x4a04dc*/;
    cpu.esp -= 4;
    // 00464ac2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464ac3  eb26                   -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464ac5:
    // 00464ac5  3d04000080             +cmp eax, 0x80000004
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483652 /*0x80000004*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464aca  750d                   -jne 0x464ad9
    if (!cpu.flags.zf)
    {
        goto L_0x00464ad9;
    }
    // 00464acc  6878044a00             -push 0x4a0478
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850808 /*0x4a0478*/;
    cpu.esp -= 4;
    // 00464ad1  6860044a00             -push 0x4a0460
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850784 /*0x4a0460*/;
    cpu.esp -= 4;
    // 00464ad6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464ad7  eb12                   -jmp 0x464aeb
    goto L_0x00464aeb;
L_0x00464ad9:
    // 00464ad9  3dfd0000c0             +cmp eax, 0xc00000fd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225725 /*0xc00000fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464ade  7518                   -jne 0x464af8
    if (!cpu.flags.zf)
    {
        goto L_0x00464af8;
    }
    // 00464ae0  6840044a00             -push 0x4a0440
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850752 /*0x4a0440*/;
    cpu.esp -= 4;
    // 00464ae5  6824044a00             -push 0x4a0424
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850724 /*0x4a0424*/;
    cpu.esp -= 4;
    // 00464aea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x00464aeb:
    // 00464aeb  6804044a00             -push 0x4a0404
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850692 /*0x4a0404*/;
    cpu.esp -= 4;
    // 00464af0  e8c2220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464af5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00464af8:
    // 00464af8  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00464afd  e8b5220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b02  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464b05  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00464b07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464b08  68f4034a00             -push 0x4a03f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850676 /*0x4a03f4*/;
    cpu.esp -= 4;
    // 00464b0d  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464b12  e8a0220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b17  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00464b1c  e896220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b21  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464b24  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00464b27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464b28  68e4034a00             -push 0x4a03e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850660 /*0x4a03e4*/;
    cpu.esp -= 4;
    // 00464b2d  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464b32  e880220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b37  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464b3a  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00464b3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464b3e  68e0034a00             -push 0x4a03e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850656 /*0x4a03e0*/;
    cpu.esp -= 4;
    // 00464b43  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464b48  e86a220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b4d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464b50  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464b53  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464b54  68dc034a00             -push 0x4a03dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850652 /*0x4a03dc*/;
    cpu.esp -= 4;
    // 00464b59  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464b5e  e854220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b63  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464b66  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00464b69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464b6a  68d8034a00             -push 0x4a03d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850648 /*0x4a03d8*/;
    cpu.esp -= 4;
    // 00464b6f  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464b74  e83e220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b79  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464b7c  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00464b7f  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00464b82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464b83  68d4034a00             -push 0x4a03d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850644 /*0x4a03d4*/;
    cpu.esp -= 4;
    // 00464b88  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464b8d  e825220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464b92  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464b95  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00464b98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464b99  68d0034a00             -push 0x4a03d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850640 /*0x4a03d0*/;
    cpu.esp -= 4;
    // 00464b9e  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464ba3  e80f220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464ba8  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00464bad  e805220100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464bb2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464bb5  8b82bc000000           -mov eax, dword ptr [edx + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(188) /* 0xbc */);
    // 00464bbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464bbc  68c8034a00             -push 0x4a03c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850632 /*0x4a03c8*/;
    cpu.esp -= 4;
    // 00464bc1  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464bc6  e8ec210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464bcb  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464bce  8b9198000000           -mov edx, dword ptr [ecx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00464bd4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464bd5  68b4034a00             -push 0x4a03b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850612 /*0x4a03b4*/;
    cpu.esp -= 4;
    // 00464bda  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464bdf  e8d3210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464be4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464be7  8b8894000000           -mov ecx, dword ptr [eax + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 00464bed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464bee  68ac034a00             -push 0x4a03ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850604 /*0x4a03ac*/;
    cpu.esp -= 4;
    // 00464bf3  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464bf8  e8ba210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464bfd  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464c00  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00464c03  8b8290000000           -mov eax, dword ptr [edx + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(144) /* 0x90 */);
    // 00464c09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464c0a  68a4034a00             -push 0x4a03a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850596 /*0x4a03a4*/;
    cpu.esp -= 4;
    // 00464c0f  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464c14  e89e210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464c19  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464c1c  8b918c000000           -mov edx, dword ptr [ecx + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 00464c22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464c23  689c034a00             -push 0x4a039c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850588 /*0x4a039c*/;
    cpu.esp -= 4;
    // 00464c28  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464c2d  e885210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464c32  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464c35  8b88c8000000           -mov ecx, dword ptr [eax + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(200) /* 0xc8 */);
    // 00464c3b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464c3c  6894034a00             -push 0x4a0394
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850580 /*0x4a0394*/;
    cpu.esp -= 4;
    // 00464c41  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464c46  e86c210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464c4b  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00464c50  e862210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464c55  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464c58  8b82b0000000           -mov eax, dword ptr [edx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(176) /* 0xb0 */);
    // 00464c5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464c5f  6890034a00             -push 0x4a0390
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850576 /*0x4a0390*/;
    cpu.esp -= 4;
    // 00464c64  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464c69  e849210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464c6e  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464c71  8b91a4000000           -mov edx, dword ptr [ecx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00464c77  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464c78  688c034a00             -push 0x4a038c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850572 /*0x4a038c*/;
    cpu.esp -= 4;
    // 00464c7d  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464c82  e830210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464c87  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464c8a  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00464c8d  8b88ac000000           -mov ecx, dword ptr [eax + 0xac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00464c93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464c94  6888034a00             -push 0x4a0388
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850568 /*0x4a0388*/;
    cpu.esp -= 4;
    // 00464c99  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464c9e  e814210100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464ca3  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464ca6  8b82a8000000           -mov eax, dword ptr [edx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 00464cac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464cad  6884034a00             -push 0x4a0384
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850564 /*0x4a0384*/;
    cpu.esp -= 4;
    // 00464cb2  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464cb7  e8fb200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464cbc  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464cbf  8b91a0000000           -mov edx, dword ptr [ecx + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 00464cc5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464cc6  6880034a00             -push 0x4a0380
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850560 /*0x4a0380*/;
    cpu.esp -= 4;
    // 00464ccb  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464cd0  e8e2200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464cd5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464cd8  8b889c000000           -mov ecx, dword ptr [eax + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 00464cde  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464cdf  687c034a00             -push 0x4a037c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850556 /*0x4a037c*/;
    cpu.esp -= 4;
    // 00464ce4  68e8034a00             -push 0x4a03e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850664 /*0x4a03e8*/;
    cpu.esp -= 4;
    // 00464ce9  e8c9200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464cee  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00464cf3  e8bf200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464cf8  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464cfb  8b82c4000000           -mov eax, dword ptr [edx + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(196) /* 0xc4 */);
    // 00464d01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464d02  6878034a00             -push 0x4a0378
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850552 /*0x4a0378*/;
    cpu.esp -= 4;
    // 00464d07  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464d0c  e8a6200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464d11  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464d14  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00464d17  8b91b4000000           -mov edx, dword ptr [ecx + 0xb4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00464d1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464d1e  6874034a00             -push 0x4a0374
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850548 /*0x4a0374*/;
    cpu.esp -= 4;
    // 00464d23  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464d28  e88a200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464d2d  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00464d32  e880200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464d37  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464d3a  8b88b8000000           -mov ecx, dword ptr [eax + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 00464d40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464d41  6870034a00             -push 0x4a0370
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850544 /*0x4a0370*/;
    cpu.esp -= 4;
    // 00464d46  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464d4b  e867200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464d50  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464d53  8b82c0000000           -mov eax, dword ptr [edx + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(192) /* 0xc0 */);
    // 00464d59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464d5a  6868034a00             -push 0x4a0368
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850536 /*0x4a0368*/;
    cpu.esp -= 4;
    // 00464d5f  68bc034a00             -push 0x4a03bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850620 /*0x4a03bc*/;
    cpu.esp -= 4;
    // 00464d64  e84e200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464d69  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00464d6e  e844200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464d73  6860034a00             -push 0x4a0360
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850528 /*0x4a0360*/;
    cpu.esp -= 4;
    // 00464d78  e83a200100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464d7d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464d80  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00464d83  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00464d8b  8bb8c4000000           -mov edi, dword ptr [eax + 0xc4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00464d91  8b88b4000000           -mov ecx, dword ptr [eax + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 00464d97  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464d9a  3bf9                   +cmp edi, ecx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464d9c  0f83fe000000           -jae 0x464ea0
    if (!cpu.flags.cf)
    {
        goto L_0x00464ea0;
    }
    // 00464da2  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00464da6:
    // 00464da6  8b1dbc704800           -mov ebx, dword ptr [0x4870bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747452) /* 0x4870bc */);
    // 00464dac  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00464dae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464daf  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464db1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464db3  0f8561010000           -jne 0x464f1a
    if (!cpu.flags.zf)
    {
        goto L_0x00464f1a;
    }
    // 00464db9  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464dbc  3bbab4000000           +cmp edi, dword ptr [edx + 0xb4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(180) /* 0xb4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464dc2  750d                   -jne 0x464dd1
    if (!cpu.flags.zf)
    {
        goto L_0x00464dd1;
    }
    // 00464dc4  6858034a00             -push 0x4a0358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850520 /*0x4a0358*/;
    cpu.esp -= 4;
    // 00464dc9  e8e91f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464dce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464dd1:
    // 00464dd1  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464dd5  81e303000080           +and ebx, 0x80000003
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(2147483651 /*0x80000003*/))));
    // 00464ddb  7905                   -jns 0x464de2
    if (!cpu.flags.sf)
    {
        goto L_0x00464de2;
    }
    // 00464ddd  4b                     -dec ebx
    (cpu.ebx)--;
    // 00464dde  83cbfc                 +or ebx, 0xfffffffc
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/))));
    // 00464de1  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00464de2:
    // 00464de2  7510                   -jne 0x464df4
    if (!cpu.flags.zf)
    {
        goto L_0x00464df4;
    }
    // 00464de4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464de5  6850034a00             -push 0x4a0350
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850512 /*0x4a0350*/;
    cpu.esp -= 4;
    // 00464dea  e8c81f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464def  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464df2  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00464df4:
    // 00464df4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00464df6  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00464df8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464df9  684c034a00             -push 0x4a034c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850508 /*0x4a034c*/;
    cpu.esp -= 4;
    // 00464dfe  e8b41f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464e03  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464e06  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00464e08  7506                   -jne 0x464e10
    if (!cpu.flags.zf)
    {
        goto L_0x00464e10;
    }
    // 00464e0a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00464e0c  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
    // 00464e0e  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x00464e10:
    // 00464e10  83fb01                 +cmp ebx, 1
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
    // 00464e13  7509                   -jne 0x464e1e
    if (!cpu.flags.zf)
    {
        goto L_0x00464e1e;
    }
    // 00464e15  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00464e17  8a17                   -mov dl, byte ptr [edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi);
    // 00464e19  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00464e1c  03ea                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00464e1e:
    // 00464e1e  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464e21  7509                   -jne 0x464e2c
    if (!cpu.flags.zf)
    {
        goto L_0x00464e2c;
    }
    // 00464e23  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00464e25  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00464e27  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00464e2a  03e8                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00464e2c:
    // 00464e2c  83fb03                 +cmp ebx, 3
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
    // 00464e2f  7517                   -jne 0x464e48
    if (!cpu.flags.zf)
    {
        goto L_0x00464e48;
    }
    // 00464e31  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00464e33  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
    // 00464e35  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00464e38  03e9                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00464e3a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464e3b  6844034a00             -push 0x4a0344
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850500 /*0x4a0344*/;
    cpu.esp -= 4;
    // 00464e40  e8721f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464e45  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00464e48:
    // 00464e48  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464e4b  8b82b4000000           -mov eax, dword ptr [edx + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(180) /* 0xb4 */);
    // 00464e51  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00464e54  3bf8                   +cmp edi, eax
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
    // 00464e56  750d                   -jne 0x464e65
    if (!cpu.flags.zf)
    {
        goto L_0x00464e65;
    }
    // 00464e58  6838034a00             -push 0x4a0338
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850488 /*0x4a0338*/;
    cpu.esp -= 4;
    // 00464e5d  e8551f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464e62  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464e65:
    // 00464e65  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464e68  8b91b4000000           -mov edx, dword ptr [ecx + 0xb4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00464e6e  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00464e71  3bfa                   +cmp edi, edx
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
    // 00464e73  750d                   -jne 0x464e82
    if (!cpu.flags.zf)
    {
        goto L_0x00464e82;
    }
    // 00464e75  6824034a00             -push 0x4a0324
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850468 /*0x4a0324*/;
    cpu.esp -= 4;
    // 00464e7a  e8381f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464e7f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464e82:
    // 00464e82  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464e85  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464e89  47                     -inc edi
    (cpu.edi)++;
    // 00464e8a  43                     -inc ebx
    (cpu.ebx)++;
    // 00464e8b  8b88b4000000           -mov ecx, dword ptr [eax + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 00464e91  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00464e95  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464e98  3bf9                   +cmp edi, ecx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464e9a  0f8206ffffff           -jb 0x464da6
    if (cpu.flags.cf)
    {
        goto L_0x00464da6;
    }
L_0x00464ea0:
    // 00464ea0  8b1dbc704800           -mov ebx, dword ptr [0x4870bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747452) /* 0x4870bc */);
L_0x00464ea6:
    // 00464ea6  6814034a00             -push 0x4a0314
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850452 /*0x4a0314*/;
    cpu.esp -= 4;
    // 00464eab  e8071f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464eb0  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464eb3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464eb6  8bb2b4000000           -mov esi, dword ptr [edx + 0xb4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(180) /* 0xb4 */);
    // 00464ebc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00464ebe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464ebf  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464ec1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464ec3  751f                   -jne 0x464ee4
    if (!cpu.flags.zf)
    {
        goto L_0x00464ee4;
    }
L_0x00464ec5:
    // 00464ec5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464ec8  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00464eca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464ecb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464ecc  68f0024a00             -push 0x4a02f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850416 /*0x4a02f0*/;
    cpu.esp -= 4;
    // 00464ed1  e8e11e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464ed6  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00464ed8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00464edb  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00464edd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464ede  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00464ee0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464ee2  74e1                   -je 0x464ec5
    if (cpu.flags.zf)
    {
        goto L_0x00464ec5;
    }
L_0x00464ee4:
    // 00464ee4  68d4024a00             -push 0x4a02d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850388 /*0x4a02d4*/;
    cpu.esp -= 4;
    // 00464ee9  e8c91e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464eee  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00464ef3  e86f2a0100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00464ef8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464efb  e8c0fbfbff             -call 0x424ac0
    cpu.esp -= 4;
    sub_424ac0(app, cpu);
    // 00464f00  e8bb2bffff             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 00464f05  e846dcffff             -call 0x462b50
    cpu.esp -= 4;
    sub_462b50(app, cpu);
    // 00464f0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00464f12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f13  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00464f19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464f1a:
    // 00464f1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464f1b  68ac024a00             -push 0x4a02ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4850348 /*0x4a02ac*/;
    cpu.esp -= 4;
    // 00464f20  e8921e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464f25  83c408                 +add esp, 8
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
    // 00464f28  e979ffffff             -jmp 0x464ea6
    goto L_0x00464ea6;
}

/* align: skip  */
void Application::sub_464f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00464f30  a108b85100             -mov eax, dword ptr [0x51b808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355528) /* 0x51b808 */);
    // 00464f35  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464f36  40                     -inc eax
    (cpu.eax)++;
    // 00464f37  6894104a00             -push 0x4a1094
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853908 /*0x4a1094*/;
    cpu.esp -= 4;
    // 00464f3c  a308b85100             -mov dword ptr [0x51b808], eax
    app->getMemory<x86::reg32>(x86::reg32(5355528) /* 0x51b808 */) = cpu.eax;
    // 00464f41  e8711e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464f46  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464f4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464f4d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00464f4f  48                     -dec eax
    (cpu.eax)--;
    // 00464f50  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464f53  7737                   -ja 0x464f8c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00464f8c;
    }
    // 00464f55  ff248528504600         -jmp dword ptr [eax*4 + 0x465028]
    cpu.ip = app->getMemory<x86::reg32>(4608040 + cpu.eax * 4); goto dynamic_jump;
  case 0x00464f5c:
    // 00464f5c  687c104a00             -push 0x4a107c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853884 /*0x4a107c*/;
    cpu.esp -= 4;
    // 00464f61  eb21                   -jmp 0x464f84
    goto L_0x00464f84;
  case 0x00464f63:
    // 00464f63  6864104a00             -push 0x4a1064
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853860 /*0x4a1064*/;
    cpu.esp -= 4;
    // 00464f68  eb1a                   -jmp 0x464f84
    goto L_0x00464f84;
  case 0x00464f6a:
    // 00464f6a  684c104a00             -push 0x4a104c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853836 /*0x4a104c*/;
    cpu.esp -= 4;
    // 00464f6f  eb13                   -jmp 0x464f84
    goto L_0x00464f84;
  case 0x00464f71:
    // 00464f71  682c104a00             -push 0x4a102c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853804 /*0x4a102c*/;
    cpu.esp -= 4;
    // 00464f76  eb0c                   -jmp 0x464f84
    goto L_0x00464f84;
  case 0x00464f78:
    // 00464f78  680c104a00             -push 0x4a100c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853772 /*0x4a100c*/;
    cpu.esp -= 4;
    // 00464f7d  eb05                   -jmp 0x464f84
    goto L_0x00464f84;
  case 0x00464f7f:
    // 00464f7f  68b00f4a00             -push 0x4a0fb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853680 /*0x4a0fb0*/;
    cpu.esp -= 4;
L_0x00464f84:
    // 00464f84  e82e1e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464f89  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464f8c:
    // 00464f8c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00464f8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464f90  68940f4a00             -push 0x4a0f94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853652 /*0x4a0f94*/;
    cpu.esp -= 4;
    // 00464f95  e81d1e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464f9a  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00464f9d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00464fa0  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00464fa3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464fa4  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00464fa7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464fa8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464fa9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464faa  68800f4a00             -push 0x4a0f80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853632 /*0x4a0f80*/;
    cpu.esp -= 4;
    // 00464faf  e8031e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464fb4  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00464fb7  dc1d68734800           -fcomp qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    cpu.fpu.pop();
    // 00464fbd  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00464fc0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00464fc2  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00464fc7  7410                   -je 0x464fd9
    if (cpu.flags.zf)
    {
        goto L_0x00464fd9;
    }
    // 00464fc9  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00464fcc  dc1df0794800           -fcomp qword ptr [0x4879f0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749808) /* 0x4879f0 */)));
    cpu.fpu.pop();
    // 00464fd2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00464fd4  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00464fd7  7a0d                   -jp 0x464fe6
    if (cpu.flags.pf)
    {
        goto L_0x00464fe6;
    }
L_0x00464fd9:
    // 00464fd9  68680f4a00             -push 0x4a0f68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853608 /*0x4a0f68*/;
    cpu.esp -= 4;
    // 00464fde  e8d41d0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00464fe3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00464fe6:
    // 00464fe6  dd4610                 -fld qword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00464fe9  dc1d68734800           -fcomp qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    cpu.fpu.pop();
    // 00464fef  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00464ff1  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00464ff6  7410                   -je 0x465008
    if (cpu.flags.zf)
    {
        goto L_0x00465008;
    }
    // 00464ff8  dd4610                 -fld qword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00464ffb  dc1df0794800           -fcomp qword ptr [0x4879f0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749808) /* 0x4879f0 */)));
    cpu.fpu.pop();
    // 00465001  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00465003  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00465006  7a0d                   -jp 0x465015
    if (cpu.flags.pf)
    {
        goto L_0x00465015;
    }
L_0x00465008:
    // 00465008  68500f4a00             -push 0x4a0f50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853584 /*0x4a0f50*/;
    cpu.esp -= 4;
    // 0046500d  e8a51d0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465012  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00465015:
    // 00465015  68380f4a00             -push 0x4a0f38
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853560 /*0x4a0f38*/;
    cpu.esp -= 4;
    // 0046501a  e8f1fbfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046501f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465022  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465024  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465025  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_465040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465040  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465041  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00465043  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00465045  68b87a4800             -push 0x487ab8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750008 /*0x487ab8*/;
    cpu.esp -= 4;
    // 0046504a  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0046504f  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00465055  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465056  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0046505d  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465061  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465062  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465063  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00465066  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00465069  893500ef5100           -mov dword ptr [0x51ef00], esi
    app->getMemory<x86::reg32>(x86::reg32(5369600) /* 0x51ef00 */) = cpu.esi;
    // 0046506f  e83c060000             -call 0x4656b0
    cpu.esp -= 4;
    sub_4656b0(app, cpu);
    // 00465074  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00465079  68e8104a00             -push 0x4a10e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853992 /*0x4a10e8*/;
    cpu.esp -= 4;
    // 0046507e  68dc104a00             -push 0x4a10dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853980 /*0x4a10dc*/;
    cpu.esp -= 4;
    // 00465083  e8874a0100             -call 0x479b0f
    cpu.esp -= 4;
    sub_479b0f(app, cpu);
    // 00465088  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046508b  a300b85100             -mov dword ptr [0x51b800], eax
    app->getMemory<x86::reg32>(x86::reg32(5355520) /* 0x51b800 */) = cpu.eax;
    // 00465090  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465092  750d                   -jne 0x4650a1
    if (!cpu.flags.zf)
    {
        goto L_0x004650a1;
    }
    // 00465094  68c0104a00             -push 0x4a10c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853952 /*0x4a10c0*/;
    cpu.esp -= 4;
    // 00465099  e8191d0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046509e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004650a1:
    // 004650a1  e81af6ffff             -call 0x4646c0
    cpu.esp -= 4;
    sub_4646c0(app, cpu);
    // 004650a6  e8152affff             -call 0x457ac0
    cpu.esp -= 4;
    sub_457ac0(app, cpu);
    // 004650ab  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004650ad  e8be040000             -call 0x465570
    cpu.esp -= 4;
    sub_465570(app, cpu);
    // 004650b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004650b4  7518                   -jne 0x4650ce
    if (!cpu.flags.zf)
    {
        goto L_0x004650ce;
    }
    // 004650b6  e845f6ffff             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 004650bb  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004650be  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004650c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650c8  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004650ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650cb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004650ce:
    // 004650ce  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004650d1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004650d3  e8f8040000             -call 0x4655d0
    cpu.esp -= 4;
    sub_4655d0(app, cpu);
    // 004650d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004650da  7518                   -jne 0x4650f4
    if (!cpu.flags.zf)
    {
        goto L_0x004650f4;
    }
    // 004650dc  e81ff6ffff             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 004650e1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004650e4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004650eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650ee  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004650f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004650f1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004650f4:
    // 004650f4  e897000000             -call 0x465190
    cpu.esp -= 4;
    sub_465190(app, cpu);
    // 004650f9  e8e2050000             -call 0x4656e0
    cpu.esp -= 4;
    sub_4656e0(app, cpu);
    // 004650fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465100  7518                   -jne 0x46511a
    if (!cpu.flags.zf)
    {
        goto L_0x0046511a;
    }
    // 00465102  e8f9f5ffff             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 00465107  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0046510a  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00465111  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465112  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465113  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465114  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00465116  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465117  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0046511a:
    // 0046511a  e8b1d8ffff             -call 0x4629d0
    cpu.esp -= 4;
    sub_4629d0(app, cpu);
    // 0046511f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465121  750d                   -jne 0x465130
    if (!cpu.flags.zf)
    {
        goto L_0x00465130;
    }
    // 00465123  68ac104a00             -push 0x4a10ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853932 /*0x4a10ac*/;
    cpu.esp -= 4;
    // 00465128  e8e3fafbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046512d  83c404                 +add esp, 4
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
L_0x00465130:
    // 00465130  c745fc00000000         -mov dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 0 /*0x0*/;
    // 00465137  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046513a  e891e2fbff             -call 0x4233d0
    cpu.esp -= 4;
    sub_4233d0(app, cpu);
    // 0046513f  eb15                   -jmp 0x465156
    return sub_465156(app, cpu);
}

/* align: skip  */
void Application::sub_465141(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465141  68a0104a00             -push 0x4a10a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853920 /*0x4a10a0*/;
    cpu.esp -= 4;
    // 00465146  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00465149  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046514a  e881f7ffff             -call 0x4648d0
    cpu.esp -= 4;
    sub_4648d0(app, cpu);
    // 0046514f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465152  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465153(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465153  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00465156  c745fcffffffff         -mov dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 4294967295 /*0xffffffff*/;
    // 0046515d  e89ef5ffff             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 00465162  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465164  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00465169  e8f9270100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0046516e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465171  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465173  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00465176  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0046517d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046517e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046517f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465180  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00465182  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465183  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_465156(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00465156;
    // 00465153  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
L_entry_0x00465156:
    // 00465156  c745fcffffffff         -mov dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 4294967295 /*0xffffffff*/;
    // 0046515d  e89ef5ffff             -call 0x464700
    cpu.esp -= 4;
    sub_464700(app, cpu);
    // 00465162  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465164  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00465169  e8f9270100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0046516e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465171  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465173  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00465176  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0046517d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046517e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046517f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465180  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00465182  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465183  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_465190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465190  6824c74800             -push 0x48c724
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769572 /*0x48c724*/;
    cpu.esp -= 4;
    // 00465195  6848384900             -push 0x493848
    app->getMemory<x86::reg32>(cpu.esp-4) = 4798536 /*0x493848*/;
    cpu.esp -= 4;
    // 0046519a  e8bf2a0100             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 0046519f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004651a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004651a4  7501                   -jne 0x4651a7
    if (!cpu.flags.zf)
    {
        goto L_0x004651a7;
    }
    // 004651a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004651a7:
    // 004651a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004651a8  e82a240100             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 004651ad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004651b0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004651b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4651c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004651c0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004651c2  a31cb85100             -mov dword ptr [0x51b81c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355548) /* 0x51b81c */) = cpu.eax;
    // 004651c7  a318b85100             -mov dword ptr [0x51b818], eax
    app->getMemory<x86::reg32>(x86::reg32(5355544) /* 0x51b818 */) = cpu.eax;
    // 004651cc  a1f8b65100             -mov eax, dword ptr [0x51b6f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355256) /* 0x51b6f8 */);
    // 004651d1  83f80a                 +cmp eax, 0xa
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
    // 004651d4  7c1a                   -jl 0x4651f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004651f0;
    }
    // 004651d6  8b0dfcb65100           -mov ecx, dword ptr [0x51b6fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355260) /* 0x51b6fc */);
    // 004651dc  83f90a                 +cmp ecx, 0xa
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004651df  7c0f                   -jl 0x4651f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004651f0;
    }
    // 004651e1  3dc8000000             +cmp eax, 0xc8
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
    // 004651e6  7f08                   -jg 0x4651f0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004651f0;
    }
    // 004651e8  81f9b4000000           +cmp ecx, 0xb4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(180 /*0xb4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004651ee  7e17                   -jle 0x465207
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465207;
    }
L_0x004651f0:
    // 004651f0  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004651f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004651f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004651f7  a3f8b65100             -mov dword ptr [0x51b6f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5355256) /* 0x51b6f8 */) = cpu.eax;
    // 004651fc  a3fcb65100             -mov dword ptr [0x51b6fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5355260) /* 0x51b6fc */) = cpu.eax;
    // 00465201  ff1510724800           -call dword ptr [0x487210]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747792) /* 0x487210 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00465207:
    // 00465207  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465210  32c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
L_0x00465212:
    // 00465212  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00465215  7508                   -jne 0x46521f
    if (!cpu.flags.zf)
    {
        goto L_0x0046521f;
    }
    // 00465217  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00465219  fec0                   -inc al
    (cpu.al)++;
    // 0046521b  3c1a                   +cmp al, 0x1a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(26 /*0x1a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046521d  7cf3                   -jl 0x465212
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465212;
    }
L_0x0046521f:
    // 0046521f  83c041                 -add eax, 0x41
    (cpu.eax) += x86::reg32(x86::sreg32(65 /*0x41*/));
    // 00465222  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00465230  a114d44a00             -mov eax, dword ptr [0x4ad414]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903956) /* 0x4ad414 */);
    // 00465235  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465238  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046523a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046523b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046523c  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00465240  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465241  742b                   -je 0x46526e
    if (cpu.flags.zf)
    {
        goto L_0x0046526e;
    }
    // 00465243  83fe02                 +cmp esi, 2
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
    // 00465246  7426                   -je 0x46526e
    if (cpu.flags.zf)
    {
        goto L_0x0046526e;
    }
    // 00465248  81feb9030000           +cmp esi, 0x3b9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(953 /*0x3b9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046524e  741e                   -je 0x46526e
    if (cpu.flags.zf)
    {
        goto L_0x0046526e;
    }
    // 00465250  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00465254  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00465258  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465259  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046525a  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046525e  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00465260  e8bb0cfcff             -call 0x425f20
    cpu.esp -= 4;
    sub_425f20(app, cpu);
    // 00465265  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465266  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465267  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465268  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046526b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0046526e:
    // 0046526e  833d68024a0001         +cmp dword ptr [0x4a0268], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4850280) /* 0x4a0268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465275  7508                   -jne 0x46527f
    if (!cpu.flags.zf)
    {
        goto L_0x0046527f;
    }
    // 00465277  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465279  ff1520724800           -call dword ptr [0x487220]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747808) /* 0x487220 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0046527f:
    // 0046527f  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00465283  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00465287  81fe00020000           +cmp esi, 0x200
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046528d  0f8749010000           -ja 0x4653dc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004653dc;
    }
    // 00465293  0f8407010000           -je 0x4653a0
    if (cpu.flags.zf)
    {
        goto L_0x004653a0;
    }
    // 00465299  8d46fe                 -lea eax, [esi - 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0046529c  3dfe000000             +cmp eax, 0xfe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004652a1  0f8794010000           -ja 0x46543b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 004652a7  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004652a9  8a9068544600           -mov dl, byte ptr [eax + 0x465468]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4609128) /* 0x465468 */);
    // 004652af  ff249554544600         -jmp dword ptr [edx*4 + 0x465454]
    cpu.ip = app->getMemory<x86::reg32>(4609108 + cpu.edx * 4); goto dynamic_jump;
  case 0x004652b6:
    // 004652b6  6800b75100             -push 0x51b700
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355264 /*0x51b700*/;
    cpu.esp -= 4;
    // 004652bb  ff151c724800           -call dword ptr [0x48721c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747804) /* 0x48721c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004652c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004652c3  0f8472010000           -je 0x46543b
    if (cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 004652c9  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004652cd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004652cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004652d0  6800b75100             -push 0x51b700
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355264 /*0x51b700*/;
    cpu.esp -= 4;
    // 004652d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004652d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004652d8  ff1518724800           -call dword ptr [0x487218]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747800) /* 0x487218 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004652de  83f801                 +cmp eax, 1
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
    // 004652e1  0f8554010000           -jne 0x46543b
    if (!cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 004652e7  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004652eb  81e1ffff0000           +and ecx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004652f1  e8aa6ffbff             -call 0x41c2a0
    cpu.esp -= 4;
    sub_41c2a0(app, cpu);
    // 004652f6  e940010000             -jmp 0x46543b
    goto L_0x0046543b;
  case 0x004652fb:
    // 004652fb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004652fd  ff1514724800           -call dword ptr [0x487214]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747796) /* 0x487214 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465303  e933010000             -jmp 0x46543b
    goto L_0x0046543b;
  case 0x00465308:
    // 00465308  833d68024a0001         +cmp dword ptr [0x4a0268], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4850280) /* 0x4a0268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046530f  0f8526010000           -jne 0x46543b
    if (!cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 00465315  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465316  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465317  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465319  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046531a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046531d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
  case 0x00465320:
    // 00465320  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00465324  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465326  753d                   -jne 0x465365
    if (!cpu.flags.zf)
    {
        goto L_0x00465365;
    }
    // 00465328  e81354ffff             -call 0x45a740
    cpu.esp -= 4;
    sub_45a740(app, cpu);
    // 0046532d  a16c845100             -mov eax, dword ptr [0x51846c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342316) /* 0x51846c */);
    // 00465332  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465334  7402                   -je 0x465338
    if (cpu.flags.zf)
    {
        goto L_0x00465338;
    }
    // 00465336  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00465338:
    // 00465338  a158845100             -mov eax, dword ptr [0x518458]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342296) /* 0x518458 */);
    // 0046533d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046533f  740f                   -je 0x465350
    if (cpu.flags.zf)
    {
        goto L_0x00465350;
    }
    // 00465341  a324b85100             -mov dword ptr [0x51b824], eax
    app->getMemory<x86::reg32>(x86::reg32(5355556) /* 0x51b824 */) = cpu.eax;
    // 00465346  c7055884510000000000   -mov dword ptr [0x518458], 0
    app->getMemory<x86::reg32>(x86::reg32(5342296) /* 0x518458 */) = 0 /*0x0*/;
L_0x00465350:
    // 00465350  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465351  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465352  c70568024a0000000000   -mov dword ptr [0x4a0268], 0
    app->getMemory<x86::reg32>(x86::reg32(4850280) /* 0x4a0268 */) = 0 /*0x0*/;
    // 0046535c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046535e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046535f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465362  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00465365:
    // 00465365  e89653ffff             -call 0x45a700
    cpu.esp -= 4;
    sub_45a700(app, cpu);
    // 0046536a  a170845100             -mov eax, dword ptr [0x518470]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342320) /* 0x518470 */);
    // 0046536f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465371  7402                   -je 0x465375
    if (cpu.flags.zf)
    {
        goto L_0x00465375;
    }
    // 00465373  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00465375:
    // 00465375  8b0d24b85100           -mov ecx, dword ptr [0x51b824]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355556) /* 0x51b824 */);
    // 0046537b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046537c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046537d  890d58845100           -mov dword ptr [0x518458], ecx
    app->getMemory<x86::reg32>(x86::reg32(5342296) /* 0x518458 */) = cpu.ecx;
    // 00465383  c70524b8510000000000   -mov dword ptr [0x51b824], 0
    app->getMemory<x86::reg32>(x86::reg32(5355556) /* 0x51b824 */) = 0 /*0x0*/;
    // 0046538d  c70568024a0001000000   -mov dword ptr [0x4a0268], 1
    app->getMemory<x86::reg32>(x86::reg32(4850280) /* 0x4a0268 */) = 1 /*0x1*/;
    // 00465397  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465399  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046539a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046539d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004653a0:
    // 004653a0  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004653a2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004653a3  8b1df8b65100           -mov ebx, dword ptr [0x51b6f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355256) /* 0x51b6f8 */);
    // 004653a9  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004653af  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004653b1  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004653b3  2bd3                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004653b5  8b1dfcb65100           -mov ebx, dword ptr [0x51b6fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355260) /* 0x51b6fc */);
    // 004653bb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004653be  891518b85100           -mov dword ptr [0x51b818], edx
    app->getMemory<x86::reg32>(x86::reg32(5355544) /* 0x51b818 */) = cpu.edx;
    // 004653c4  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004653c6  2bd3                   +sub edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004653c8  890df8b65100           -mov dword ptr [0x51b6f8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355256) /* 0x51b6f8 */) = cpu.ecx;
    // 004653ce  89151cb85100           -mov dword ptr [0x51b81c], edx
    app->getMemory<x86::reg32>(x86::reg32(5355548) /* 0x51b81c */) = cpu.edx;
    // 004653d4  a3fcb65100             -mov dword ptr [0x51b6fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5355260) /* 0x51b6fc */) = cpu.eax;
    // 004653d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004653da  eb5f                   -jmp 0x46543b
    goto L_0x0046543b;
L_0x004653dc:
    // 004653dc  81fe11030000           +cmp esi, 0x311
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(785 /*0x311*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004653e2  7743                   -ja 0x465427
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00465427;
    }
    // 004653e4  7410                   -je 0x4653f6
    if (cpu.flags.zf)
    {
        goto L_0x004653f6;
    }
    // 004653e6  81fe19020000           +cmp esi, 0x219
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(537 /*0x219*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004653ec  7414                   -je 0x465402
    if (cpu.flags.zf)
    {
        goto L_0x00465402;
    }
    // 004653ee  81fe10030000           +cmp esi, 0x310
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(784 /*0x310*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004653f4  7545                   -jne 0x46543b
    if (!cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
L_0x004653f6:
    // 004653f6  c70514b8510001000000   -mov dword ptr [0x51b814], 1
    app->getMemory<x86::reg32>(x86::reg32(5355540) /* 0x51b814 */) = 1 /*0x1*/;
    // 00465400  eb39                   -jmp 0x46543b
    goto L_0x0046543b;
L_0x00465402:
    // 00465402  81fd04800000           +cmp ebp, 0x8004
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32772 /*0x8004*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465408  7531                   -jne 0x46543b
    if (!cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 0046540a  837f0402               +cmp dword ptr [edi + 4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046540e  752b                   -jne 0x46543b
    if (!cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 00465410  f6471001               +test byte ptr [edi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00465414  7425                   -je 0x46543b
    if (cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 00465416  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00465419  e8f2fdffff             -call 0x465210
    cpu.esp -= 4;
    sub_465210(app, cpu);
    // 0046541e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00465420  e87bbffcff             -call 0x4313a0
    cpu.esp -= 4;
    sub_4313a0(app, cpu);
    // 00465425  eb14                   -jmp 0x46543b
    goto L_0x0046543b;
L_0x00465427:
    // 00465427  81feb9030000           +cmp esi, 0x3b9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(953 /*0x3b9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046542d  750c                   -jne 0x46543b
    if (!cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 0046542f  83fd01                 +cmp ebp, 1
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
    // 00465432  7507                   -jne 0x46543b
    if (!cpu.flags.zf)
    {
        goto L_0x0046543b;
    }
    // 00465434  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00465436  e845d0ffff             -call 0x462480
    cpu.esp -= 4;
    sub_462480(app, cpu);
  [[fallthrough]];
  case 0x0046543b:
L_0x0046543b:
    // 0046543b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046543f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465440  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465441  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465442  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    return sub_465443(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_465443(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465443  ff15f8714800           -call dword ptr [0x4871f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747768) /* 0x4871f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465449  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046544a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046544b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046544c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046544f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_465570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465570  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465573  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465574  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00465576  68007f0000             -push 0x7f00
    app->getMemory<x86::reg32>(cpu.esp-4) = 32512 /*0x7f00*/;
    cpu.esp -= 4;
    // 0046557b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046557c  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00465580  c744241030524600       -mov dword ptr [esp + 0x10], 0x465230
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 4608560 /*0x465230*/;
    // 00465588  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0046558c  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00465590  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00465594  ff15f4714800           -call dword ptr [0x4871f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747764) /* 0x4871f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046559a  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0046559e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004655a0  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004655a4  ff153c704800           -call dword ptr [0x48703c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747324) /* 0x48703c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004655aa  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004655ae  c7442428ec104a00       -mov dword ptr [esp + 0x28], 0x4a10ec
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 4853996 /*0x4a10ec*/;
    // 004655b6  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004655ba  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004655be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004655bf  ff152c724800           -call dword ptr [0x48722c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747820) /* 0x48722c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004655c5  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004655ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004655cb  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004655ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4655d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004655d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004655d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004655d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004655d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004655d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004655d7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004655d9  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004655db  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004655dd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004655df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004655e1  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 004655e6  68fc104a00             -push 0x4a10fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854012 /*0x4a10fc*/;
    cpu.esp -= 4;
    // 004655eb  68ec104a00             -push 0x4a10ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4853996 /*0x4a10ec*/;
    cpu.esp -= 4;
    // 004655f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004655f2  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004655f4  890d00ef5100           -mov dword ptr [0x51ef00], ecx
    app->getMemory<x86::reg32>(x86::reg32(5369600) /* 0x51ef00 */) = cpu.ecx;
    // 004655fa  ff1524724800           -call dword ptr [0x487224]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747812) /* 0x487224 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465600  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465602  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00465604  7503                   -jne 0x465609
    if (!cpu.flags.zf)
    {
        goto L_0x00465609;
    }
    // 00465606  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465607  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465608  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465609:
    // 00465609  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046560a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046560b  893504ef5100           -mov dword ptr [0x51ef04], esi
    app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */) = cpu.esi;
    // 00465611  ff15f0714800           -call dword ptr [0x4871f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747760) /* 0x4871f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465617  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465618  ff1528724800           -call dword ptr [0x487228]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747816) /* 0x487228 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046561e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00465623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465630  a104ef5100             -mov eax, dword ptr [0x51ef04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00465635  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465636  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465638  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465639  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046563b  ff15f0714800           -call dword ptr [0x4871f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747760) /* 0x4871f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465641  8b0d04ef5100           -mov ecx, dword ptr [0x51ef04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5369604) /* 0x51ef04 */);
    // 00465647  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 0046564c  68007a4900             -push 0x497a00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4815360 /*0x497a00*/;
    cpu.esp -= 4;
    // 00465651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465652  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465653  ff15ec714800           -call dword ptr [0x4871ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747756) /* 0x4871ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046565a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465660  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00465663  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 00465667  c744240020000000       -mov dword ptr [esp], 0x20
    app->getMemory<x86::reg32>(cpu.esp) = 32 /*0x20*/;
    // 0046566f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465670  ff1594704800           -call dword ptr [0x487094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747412) /* 0x487094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465676  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046567a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046567e  c1e90a                 -shr ecx, 0xa
    cpu.ecx >>= 10 /*0xa*/ % 32;
    // 00465681  c1ea0a                 -shr edx, 0xa
    cpu.edx >>= 10 /*0xa*/ % 32;
    // 00465684  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465685  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465686  682c114a00             -push 0x4a112c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854060 /*0x4a112c*/;
    cpu.esp -= 4;
    // 0046568b  e827170100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465690  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00465694  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00465698  c1e80a                 -shr eax, 0xa
    cpu.eax >>= 10 /*0xa*/ % 32;
    // 0046569b  c1e90a                 -shr ecx, 0xa
    cpu.ecx >>= 10 /*0xa*/ % 32;
    // 0046569e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046569f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004656a0  6808114a00             -push 0x4a1108
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854024 /*0x4a1108*/;
    cpu.esp -= 4;
    // 004656a5  e80d170100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004656aa  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004656ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4656b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004656b0  a12cb85100             -mov eax, dword ptr [0x51b82c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355564) /* 0x51b82c */);
    // 004656b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004656b7  7513                   -jne 0x4656cc
    if (!cpu.flags.zf)
    {
        goto L_0x004656cc;
    }
    // 004656b9  9b                     -wait 
    /*nothing*/;
    // 004656ba  d93df0b65100           -fnstcw word ptr [0x51b6f0]
    app->getMemory<x86::reg16>(x86::reg32(5355248) /* 0x51b6f0 */) = cpu.fpu.control.word;
    // 004656c0  9b                     -wait 
    /*nothing*/;
    // 004656c1  c7052cb8510001000000   -mov dword ptr [0x51b82c], 1
    app->getMemory<x86::reg32>(x86::reg32(5355564) /* 0x51b82c */) = 1 /*0x1*/;
    // 004656cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004656cc:
    // 004656cc  d92df0b65100           -fldcw word ptr [0x51b6f0]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(x86::reg32(5355248) /* 0x51b6f0 */);
    // 004656d2  9b                     -wait 
    /*nothing*/;
    // 004656d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4656e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004656e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004656e1  6840b85100             -push 0x51b840
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355584 /*0x51b840*/;
    cpu.esp -= 4;
    // 004656e6  ff1550704800           -call dword ptr [0x487050]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747344) /* 0x487050 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004656ec  8b355c704800           -mov esi, dword ptr [0x48705c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747356) /* 0x48705c */);
    // 004656f2  6838b85100             -push 0x51b838
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355576 /*0x51b838*/;
    cpu.esp -= 4;
    // 004656f7  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004656f9  a13cb85100             -mov eax, dword ptr [0x51b83c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355580) /* 0x51b83c */);
    // 004656fe  8b0d38b85100           -mov ecx, dword ptr [0x51b838]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355576) /* 0x51b838 */);
    // 00465704  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465706  6a24                   -push 0x24
    app->getMemory<x86::reg32>(cpu.esp-4) = 36 /*0x24*/;
    cpu.esp -= 4;
    // 00465708  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465709  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046570a  e821460100             -call 0x479d30
    cpu.esp -= 4;
    __alldiv(app, cpu);
    // 0046570f  a338b85100             -mov dword ptr [0x51b838], eax
    app->getMemory<x86::reg32>(x86::reg32(5355576) /* 0x51b838 */) = cpu.eax;
    // 00465714  89153cb85100           -mov dword ptr [0x51b83c], edx
    app->getMemory<x86::reg32>(x86::reg32(5355580) /* 0x51b83c */) = cpu.edx;
    // 0046571a  6830b85100             -push 0x51b830
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355568 /*0x51b830*/;
    cpu.esp -= 4;
    // 0046571f  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465721  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00465726  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465727  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465730  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465733  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 00465737  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465738  ff1550704800           -call dword ptr [0x487050]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747344) /* 0x487050 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046573e  8b1540b85100           -mov edx, dword ptr [0x51b840]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355584) /* 0x51b840 */);
    // 00465744  a144b85100             -mov eax, dword ptr [0x51b844]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355588) /* 0x51b844 */);
    // 00465749  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046574d  2bca                   +sub ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046574f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00465753  1bd0                   -sbb edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00465755  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00465759  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046575d  df6c2400               -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00465761  df2d30b85100           -fild qword ptr [0x51b830]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(x86::reg32(5355568) /* 0x51b830 */))));
    // 00465767  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00465769  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046576c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465770  dd0558114a00           -fld qword ptr [0x4a1158]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4854104) /* 0x4a1158 */)));
    // 00465776  dc1df0794800           -fcomp qword ptr [0x4879f0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749808) /* 0x4879f0 */)));
    cpu.fpu.pop();
    // 0046577c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046577e  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00465781  7a0b                   -jp 0x46578e
    if (cpu.flags.pf)
    {
        goto L_0x0046578e;
    }
    // 00465783  e8a8ffffff             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00465788  dd1d58114a00           -fstp qword ptr [0x4a1158]
    app->getMemory<double>(x86::reg32(4854104) /* 0x4a1158 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046578e:
    // 0046578e  e89dffffff             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00465793  dd0558114a00           -fld qword ptr [0x4a1158]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4854104) /* 0x4a1158 */)));
    // 00465799  d8e9                   -fsubr st(1)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(1)) - cpu.fpu.st(0);
    // 0046579b  d91504b85100           -fst dword ptr [0x51b804]
    app->getMemory<float>(x86::reg32(5355524) /* 0x51b804 */) = float(cpu.fpu.st(0));
    // 004657a1  d81d50764800           -fcomp dword ptr [0x487650]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748880) /* 0x487650 */)));
    cpu.fpu.pop();
    // 004657a7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004657a9  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004657ac  7b15                   -jnp 0x4657c3
    if (!cpu.flags.pf)
    {
        goto L_0x004657c3;
    }
    // 004657ae  d90504b85100           -fld dword ptr [0x51b804]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5355524) /* 0x51b804 */)));
    // 004657b4  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 004657ba  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004657bc  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004657c1  750a                   -jne 0x4657cd
    if (!cpu.flags.zf)
    {
        goto L_0x004657cd;
    }
L_0x004657c3:
    // 004657c3  c70504b851000ad7233c   -mov dword ptr [0x51b804], 0x3c23d70a
    app->getMemory<x86::reg32>(x86::reg32(5355524) /* 0x51b804 */) = 1008981770 /*0x3c23d70a*/;
L_0x004657cd:
    // 004657cd  dd1d58114a00           -fstp qword ptr [0x4a1158]
    app->getMemory<double>(x86::reg32(4854104) /* 0x4a1158 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004657d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4657e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004657e0  81ec24010000           -sub esp, 0x124
    (cpu.esp) -= x86::reg32(x86::sreg32(292 /*0x124*/));
    // 004657e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004657e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004657e8  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004657ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004657eb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004657ed  750d                   -jne 0x4657fc
    if (!cpu.flags.zf)
    {
        goto L_0x004657fc;
    }
    // 004657ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004657f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004657f1  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004657f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004657f5  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 004657fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004657fc:
    // 004657fc  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004657fe  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00465801  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00465803  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00465805  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00465807  49                     -dec ecx
    (cpu.ecx)--;
    // 00465808  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046580c  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046580e  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00465810  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00465813  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465815  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00465817  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046581a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046581c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046581e  7e0d                   -jle 0x46582d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046582d;
    }
    // 00465820  807c042f2f             +cmp byte ptr [esp + eax + 0x2f], 0x2f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(47) /* 0x2f */ + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00465825  7406                   -je 0x46582d
    if (cpu.flags.zf)
    {
        goto L_0x0046582d;
    }
    // 00465827  c64404302f             -mov byte ptr [esp + eax + 0x30], 0x2f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 1) = 47 /*0x2f*/;
    // 0046582c  40                     -inc eax
    (cpu.eax)++;
L_0x0046582d:
    // 0046582d  83f801                 +cmp eax, 1
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
    // 00465830  7f0d                   -jg 0x46583f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046583f;
    }
    // 00465832  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465833  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465834  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00465837  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465838  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 0046583e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046583f:
    // 0046583f  8d6c0430               -lea ebp, [esp + eax + 0x30]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 1);
    // 00465843  a158b95100             -mov eax, dword ptr [0x51b958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355864) /* 0x51b958 */);
    // 00465848  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046584a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046584c  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 00465850  7441                   -je 0x465893
    if (cpu.flags.zf)
    {
        goto L_0x00465893;
    }
L_0x00465852:
    // 00465852  8d742430               -lea esi, [esp + 0x30]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
L_0x00465856:
    // 00465856  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00465858  8aca                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046585a  3a16                   +cmp dl, byte ptr [esi]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046585c  751c                   -jne 0x46587a
    if (!cpu.flags.zf)
    {
        goto L_0x0046587a;
    }
    // 0046585e  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00465860  7414                   -je 0x465876
    if (cpu.flags.zf)
    {
        goto L_0x00465876;
    }
    // 00465862  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00465865  8aca                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00465867  3a5601                 +cmp dl, byte ptr [esi + 1]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046586a  750e                   -jne 0x46587a
    if (!cpu.flags.zf)
    {
        goto L_0x0046587a;
    }
    // 0046586c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046586f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00465872  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00465874  75e0                   -jne 0x465856
    if (!cpu.flags.zf)
    {
        goto L_0x00465856;
    }
L_0x00465876:
    // 00465876  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00465878  eb05                   -jmp 0x46587f
    goto L_0x0046587f;
L_0x0046587a:
    // 0046587a  1bc0                   +sbb eax, eax
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
    // 0046587c  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0046587f:
    // 0046587f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465881  0f8486000000           -je 0x46590d
    if (cpu.flags.zf)
    {
        goto L_0x0046590d;
    }
    // 00465887  8b04bd5cb95100         -mov eax, dword ptr [edi*4 + 0x51b95c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355868) /* 0x51b95c */ + cpu.edi * 4);
    // 0046588e  47                     -inc edi
    (cpu.edi)++;
    // 0046588f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465891  75bf                   -jne 0x465852
    if (!cpu.flags.zf)
    {
        goto L_0x00465852;
    }
L_0x00465893:
    // 00465893  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00465897  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046589b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046589c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046589d  c645ff00               -mov byte ptr [ebp - 1], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = 0 /*0x0*/;
    // 004658a1  e887ff0100             -call 0x48582d
    cpu.esp -= 4;
    sub_48582d(app, cpu);
    // 004658a6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004658a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004658ab  741a                   -je 0x4658c7
    if (cpu.flags.zf)
    {
        goto L_0x004658c7;
    }
    // 004658ad  8d542430               -lea edx, [esp + 0x30]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004658b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004658b2  e8443b0100             -call 0x4793fb
    cpu.esp -= 4;
    sub_4793fb(app, cpu);
    // 004658b7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004658ba  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004658bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004658be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004658bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004658c0  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 004658c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004658c7:
    // 004658c7  8b442412               -mov eax, dword ptr [esp + 0x12]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(18) /* 0x12 */);
    // 004658cb  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004658ce  750d                   -jne 0x4658dd
    if (!cpu.flags.zf)
    {
        goto L_0x004658dd;
    }
    // 004658d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004658d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004658d2  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004658d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004658d6  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 004658dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004658dd:
    // 004658dd  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004658e1  c645ff2f               -mov byte ptr [ebp - 1], 0x2f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = 47 /*0x2f*/;
    // 004658e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004658e6  e882d40100             -call 0x482d6d
    cpu.esp -= 4;
    sub_482d6d(app, cpu);
    // 004658eb  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004658ef  8904bd58b95100         -mov dword ptr [edi*4 + 0x51b958], eax
    app->getMemory<x86::reg32>(x86::reg32(5355864) /* 0x51b958 */ + cpu.edi * 4) = cpu.eax;
    // 004658f6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004658f7  6874114a00             -push 0x4a1174
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854132 /*0x4a1174*/;
    cpu.esp -= 4;
    // 004658fc  68483d4a00             -push 0x4a3d48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865352 /*0x4a3d48*/;
    cpu.esp -= 4;
    // 00465901  c645ff00               -mov byte ptr [ebp - 1], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = 0 /*0x0*/;
    // 00465905  e8372c0100             -call 0x478541
    cpu.esp -= 4;
    sub_478541(app, cpu);
    // 0046590a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0046590d:
    // 0046590d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046590e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046590f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465911  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465912  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 00465918  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465920  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00465926  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465927  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465928  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465929  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046592a  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046592c  6a2f                   -push 0x2f
    app->getMemory<x86::reg32>(cpu.esp-4) = 47 /*0x2f*/;
    cpu.esp -= 4;
    // 0046592e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046592f  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00465931  e83a450100             -call 0x479e70
    cpu.esp -= 4;
    _strchr(app, cpu);
    // 00465936  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465939  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046593b  7419                   -je 0x465956
    if (cpu.flags.zf)
    {
        goto L_0x00465956;
    }
    // 0046593d  6808c74800             -push 0x48c708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769544 /*0x48c708*/;
    cpu.esp -= 4;
    // 00465942  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465943  e816230100             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 00465948  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046594b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046594c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046594d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046594e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046594f  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00465955  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465956:
    // 00465956  bb58b95100             -mov ebx, 0x51b958
    cpu.ebx = 5355864 /*0x51b958*/;
L_0x0046595b:
    // 0046595b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046595d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046595f  745a                   -je 0x4659bb
    if (cpu.flags.zf)
    {
        goto L_0x004659bb;
    }
    // 00465961  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00465965  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00465967:
    // 00465967  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00465969  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0046596c  40                     -inc eax
    (cpu.eax)++;
    // 0046596d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0046596f  75f6                   -jne 0x465967
    if (!cpu.flags.zf)
    {
        goto L_0x00465967;
    }
    // 00465971  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00465973  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00465976  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00465978  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046597c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0046597e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00465980  2bf9                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465982  6808c74800             -push 0x48c708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769544 /*0x48c708*/;
    cpu.esp -= 4;
    // 00465987  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00465989  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0046598b  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046598d  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046598f  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00465992  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00465994  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00465996  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00465998  4f                     -dec edi
    (cpu.edi)--;
    // 00465999  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046599c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046599e  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004659a0  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004659a4  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004659a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004659a8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004659aa  e8af220100             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 004659af  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004659b1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004659b4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004659b7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004659b9  74a0                   -je 0x46595b
    if (cpu.flags.zf)
    {
        goto L_0x0046595b;
    }
L_0x004659bb:
    // 004659bb  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004659bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659c1  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004659c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4659d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004659d0  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004659d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004659d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004659d5  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004659d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004659da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004659db  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 004659e0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004659e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004659e3  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004659e7  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 004659ee  ff155c724800           -call dword ptr [0x48725c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747868) /* 0x48725c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004659f4  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004659f6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004659f8  750a                   -jne 0x465a04
    if (!cpu.flags.zf)
    {
        goto L_0x00465a04;
    }
    // 004659fa  be00e10000             -mov esi, 0xe100
    cpu.esi = 57600 /*0xe100*/;
    // 004659ff  e943010000             -jmp 0x465b47
    goto L_0x00465b47;
L_0x00465a04:
    // 00465a04  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00465a08  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465a0a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465a0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465a0d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465a0e  ff1574724800           -call dword ptr [0x487274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747892) /* 0x487274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465a14  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465a16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00465a18  0f8529010000           -jne 0x465b47
    if (!cpu.flags.zf)
    {
        goto L_0x00465b47;
    }
    // 00465a1e  813b52494646           +cmp dword ptr [ebx], 0x46464952
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1179011410 /*0x46464952*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465a24  0f8518010000           -jne 0x465b42
    if (!cpu.flags.zf)
    {
        goto L_0x00465b42;
    }
    // 00465a2a  817b0857415645         +cmp dword ptr [ebx + 8], 0x45564157
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1163280727 /*0x45564157*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465a31  0f850b010000           -jne 0x465b42
    if (!cpu.flags.zf)
    {
        goto L_0x00465b42;
    }
    // 00465a37  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00465a39  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00465a3d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465a3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465a3f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465a40  c7442434666d7420       -mov dword ptr [esp + 0x34], 0x20746d66
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = 544501094 /*0x20746d66*/;
    // 00465a48  ff1574724800           -call dword ptr [0x487274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747892) /* 0x487274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465a4e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465a50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00465a52  0f85ef000000           -jne 0x465b47
    if (!cpu.flags.zf)
    {
        goto L_0x00465b47;
    }
    // 00465a58  837c242810             +cmp dword ptr [esp + 0x28], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465a5d  0f82df000000           -jb 0x465b42
    if (cpu.flags.cf)
    {
        goto L_0x00465b42;
    }
    // 00465a63  8b3560724800           -mov esi, dword ptr [0x487260]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747872) /* 0x487260 */);
    // 00465a69  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00465a6d  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00465a6f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465a70  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465a71  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465a73  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465a76  740a                   -je 0x465a82
    if (cpu.flags.zf)
    {
        goto L_0x00465a82;
    }
    // 00465a78  be02e10000             -mov esi, 0xe102
    cpu.esi = 57602 /*0xe102*/;
    // 00465a7d  e9c5000000             -jmp 0x465b47
    goto L_0x00465b47;
L_0x00465a82:
    // 00465a82  66837c241401           +cmp word ptr [esp + 0x14], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00465a88  7508                   -jne 0x465a92
    if (!cpu.flags.zf)
    {
        goto L_0x00465a92;
    }
    // 00465a8a  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00465a8c  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00465a90  eb1d                   -jmp 0x465aaf
    goto L_0x00465aaf;
L_0x00465a92:
    // 00465a92  8d54243c               -lea edx, [esp + 0x3c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00465a96  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00465a98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465a99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465a9a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465a9c  83f802                 +cmp eax, 2
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
    // 00465a9f  740a                   -je 0x465aab
    if (cpu.flags.zf)
    {
        goto L_0x00465aab;
    }
    // 00465aa1  be02e10000             -mov esi, 0xe102
    cpu.esi = 57602 /*0xe102*/;
    // 00465aa6  e99c000000             -jmp 0x465b47
    goto L_0x00465b47;
L_0x00465aab:
    // 00465aab  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
L_0x00465aaf:
    // 00465aaf  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00465ab4  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00465ab7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465ab8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465aba  ff1598704800           -call dword ptr [0x487098]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747416) /* 0x487098 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465ac0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465ac2  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00465ac5  7507                   -jne 0x465ace
    if (!cpu.flags.zf)
    {
        goto L_0x00465ace;
    }
    // 00465ac7  be00e00000             -mov esi, 0xe000
    cpu.esi = 57344 /*0xe000*/;
    // 00465acc  eb79                   -jmp 0x465b47
    goto L_0x00465b47;
L_0x00465ace:
    // 00465ace  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00465ad2  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00465ad4  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00465ad8  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00465adb  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00465adf  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00465ae2  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00465ae6  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00465ae9  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00465aec  668b4c243c             -mov cx, word ptr [esp + 0x3c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00465af1  66894810               -mov word ptr [eax + 0x10], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.cx;
    // 00465af5  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00465af9  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00465afc  741e                   -je 0x465b1c
    if (cpu.flags.zf)
    {
        goto L_0x00465b1c;
    }
    // 00465afe  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00465b01  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00465b06  83c212                 -add edx, 0x12
    (cpu.edx) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00465b09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465b0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465b0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465b0c  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465b0e  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00465b12  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00465b18  3bc1                   +cmp eax, ecx
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
    // 00465b1a  7526                   -jne 0x465b42
    if (!cpu.flags.zf)
    {
        goto L_0x00465b42;
    }
L_0x00465b1c:
    // 00465b1c  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00465b20  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465b22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465b23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465b24  ff1564724800           -call dword ptr [0x487264]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747876) /* 0x487264 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465b2a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465b2c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00465b2e  7517                   -jne 0x465b47
    if (!cpu.flags.zf)
    {
        goto L_0x00465b47;
    }
    // 00465b30  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465b34  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00465b36  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465b38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b3a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b3c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465b3f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00465b42:
    // 00465b42  be01e10000             -mov esi, 0xe101
    cpu.esi = 57601 /*0xe101*/;
L_0x00465b47:
    // 00465b47  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00465b4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465b4c  740e                   -je 0x465b5c
    if (cpu.flags.zf)
    {
        goto L_0x00465b5c;
    }
    // 00465b4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465b4f  ff157c704800           -call dword ptr [0x48707c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747388) /* 0x48707c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465b55  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
L_0x00465b5c:
    // 00465b5c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00465b5e  741d                   -je 0x465b7d
    if (cpu.flags.zf)
    {
        goto L_0x00465b7d;
    }
    // 00465b60  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465b62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465b63  ff1568724800           -call dword ptr [0x487268]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747880) /* 0x487268 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465b69  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465b6b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465b6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b70  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00465b72  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465b74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b76  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b77  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465b7a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00465b7d:
    // 00465b7d  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465b81  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465b83  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00465b85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b89  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465b8c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_465b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465b91  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00465b95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465b96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465b97  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00465b9a  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00465b9c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465b9f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465ba1  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00465ba3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465ba4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465ba5  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00465ba7  ff1558724800           -call dword ptr [0x487258]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747864) /* 0x487258 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465bad  83f8ff                 +cmp eax, -1
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
    // 00465bb0  7413                   -je 0x465bc5
    if (cpu.flags.zf)
    {
        goto L_0x00465bc5;
    }
    // 00465bb2  c70664617461           -mov dword ptr [esi], 0x61746164
    app->getMemory<x86::reg32>(cpu.esi) = 1635017060 /*0x61746164*/;
    // 00465bb8  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00465bba  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00465bbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465bbd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465bbe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465bbf  ff1574724800           -call dword ptr [0x487274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747892) /* 0x487274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00465bc5:
    // 00465bc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_465bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465bd0  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00465bd3  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 00465bd7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465bd8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465bd9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465bda  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465bdb  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00465bdd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465bdf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465be0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465be1  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00465be3  ff1534724800           -call dword ptr [0x487234]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747828) /* 0x487234 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465be9  f7d8                   +neg eax
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
    // 00465beb  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00465bed  f7d8                   +neg eax
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
    // 00465bef  7567                   -jne 0x465c58
    if (!cpu.flags.zf)
    {
        goto L_0x00465c58;
    }
    // 00465bf1  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00465bf5  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00465bf8  3bf8                   +cmp edi, eax
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
    // 00465bfa  7602                   -jbe 0x465bfe
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00465bfe;
    }
    // 00465bfc  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00465bfe:
    // 00465bfe  2bc7                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00465c00  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00465c02  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00465c04  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00465c07  763d                   -jbe 0x465c46
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00465c46;
    }
    // 00465c09  8b5c245c               -mov ebx, dword ptr [esp + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00465c0d  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00465c11  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
L_0x00465c15:
    // 00465c15  3bc1                   +cmp eax, ecx
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
    // 00465c17  751e                   -jne 0x465c37
    if (!cpu.flags.zf)
    {
        goto L_0x00465c37;
    }
    // 00465c19  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465c1d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465c1f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465c20  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465c21  ff1550724800           -call dword ptr [0x487250]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747856) /* 0x487250 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465c27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465c29  752d                   -jne 0x465c58
    if (!cpu.flags.zf)
    {
        goto L_0x00465c58;
    }
    // 00465c2b  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00465c2f  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00465c33  3bc1                   +cmp eax, ecx
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
    // 00465c35  7435                   -je 0x465c6c
    if (cpu.flags.zf)
    {
        goto L_0x00465c6c;
    }
L_0x00465c37:
    // 00465c37  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00465c39  40                     -inc eax
    (cpu.eax)++;
    // 00465c3a  88141e                 -mov byte ptr [esi + ebx], dl
    app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1) = cpu.dl;
    // 00465c3d  46                     -inc esi
    (cpu.esi)++;
    // 00465c3e  3bf7                   +cmp esi, edi
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
    // 00465c40  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00465c44  72cf                   -jb 0x465c15
    if (cpu.flags.cf)
    {
        goto L_0x00465c15;
    }
L_0x00465c46:
    // 00465c46  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465c4a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465c4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465c4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465c4e  ff1554724800           -call dword ptr [0x487254]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747860) /* 0x487254 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465c54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465c56  742d                   -je 0x465c85
    if (cpu.flags.zf)
    {
        goto L_0x00465c85;
    }
L_0x00465c58:
    // 00465c58  8b4c2464               -mov ecx, dword ptr [esp + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00465c5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c5f  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00465c65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c66  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00465c69  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00465c6c:
    // 00465c6c  8b4c2464               -mov ecx, dword ptr [esp + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00465c70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c73  b803e10000             -mov eax, 0xe103
    cpu.eax = 57603 /*0xe103*/;
    // 00465c78  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00465c7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c7f  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00465c82  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00465c85:
    // 00465c85  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00465c89  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00465c8b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c8f  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00465c92  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_465ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465ca0  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465ca3  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00465ca7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465ca8  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00465cac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465cad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465cae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465caf  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00465cb3  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00465cb5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465cb6  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00465cbc  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00465cc2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465cc3  8d54244c               -lea edx, [esp + 0x4c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00465cc7  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00465cce  e8fdfcffff             -call 0x4659d0
    cpu.esp -= 4;
    sub_4659d0(app, cpu);
    // 00465cd3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465cd5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00465cd7  754f                   -jne 0x465d28
    if (!cpu.flags.zf)
    {
        goto L_0x00465d28;
    }
    // 00465cd9  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00465cdd  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465ce2  8d4c2448               -lea ecx, [esp + 0x48]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00465ce6  e8a5feffff             -call 0x465b90
    cpu.esp -= 4;
    sub_465b90(app, cpu);
    // 00465ceb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465ced  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00465cef  7537                   -jne 0x465d28
    if (!cpu.flags.zf)
    {
        goto L_0x00465d28;
    }
    // 00465cf1  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00465cf5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465cf6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465cf7  ff1598704800           -call dword ptr [0x487098]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747416) /* 0x487098 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465cfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465cff  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00465d01  7507                   -jne 0x465d0a
    if (!cpu.flags.zf)
    {
        goto L_0x00465d0a;
    }
    // 00465d03  be00e00000             -mov esi, 0xe000
    cpu.esi = 57344 /*0xe000*/;
    // 00465d08  eb1e                   -jmp 0x465d28
    goto L_0x00465d28;
L_0x00465d0a:
    // 00465d0a  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00465d0e  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465d12  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465d13  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00465d17  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465d18  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00465d1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465d1d  e8aefeffff             -call 0x465bd0
    cpu.esp -= 4;
    sub_465bd0(app, cpu);
    // 00465d22  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465d24  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00465d26  7426                   -je 0x465d4e
    if (cpu.flags.zf)
    {
        goto L_0x00465d4e;
    }
L_0x00465d28:
    // 00465d28  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00465d2a  8b2d7c704800           -mov ebp, dword ptr [0x48707c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747388) /* 0x48707c */);
    // 00465d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465d32  7409                   -je 0x465d3d
    if (cpu.flags.zf)
    {
        goto L_0x00465d3d;
    }
    // 00465d34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465d35  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465d37  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x00465d3d:
    // 00465d3d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00465d3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465d41  7412                   -je 0x465d55
    if (cpu.flags.zf)
    {
        goto L_0x00465d55;
    }
    // 00465d43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465d44  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465d46  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00465d4c  eb07                   -jmp 0x465d55
    goto L_0x00465d55;
L_0x00465d4e:
    // 00465d4e  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00465d52  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00465d55:
    // 00465d55  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00465d59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465d5b  7409                   -je 0x465d66
    if (cpu.flags.zf)
    {
        goto L_0x00465d66;
    }
    // 00465d5d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465d5f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465d60  ff1568724800           -call dword ptr [0x487268]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747880) /* 0x487268 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00465d66:
    // 00465d66  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465d68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465d69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465d6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465d6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465d6c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465d6f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_465d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465d80  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465d83  8d442400               -lea eax, [esp]
    cpu.eax = x86::reg32(cpu.esp);
    // 00465d87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465d88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465d89  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00465d8d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465d8e  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00465d90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465d91  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00465d97  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465d98  8d542440               -lea edx, [esp + 0x40]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00465d9c  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00465da2  e829fcffff             -call 0x4659d0
    cpu.esp -= 4;
    sub_4659d0(app, cpu);
    // 00465da7  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00465da9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00465dab  7518                   -jne 0x465dc5
    if (!cpu.flags.zf)
    {
        goto L_0x00465dc5;
    }
    // 00465dad  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00465db1  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00465db5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465db6  8d4c243c               -lea ecx, [esp + 0x3c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00465dba  e8d1fdffff             -call 0x465b90
    cpu.esp -= 4;
    sub_465b90(app, cpu);
    // 00465dbf  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00465dc1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00465dc3  7415                   -je 0x465dda
    if (cpu.flags.zf)
    {
        goto L_0x00465dda;
    }
L_0x00465dc5:
    // 00465dc5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00465dc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465dc9  7415                   -je 0x465de0
    if (cpu.flags.zf)
    {
        goto L_0x00465de0;
    }
    // 00465dcb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465dcc  ff157c704800           -call dword ptr [0x48707c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747388) /* 0x48707c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465dd2  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00465dd8  eb06                   -jmp 0x465de0
    goto L_0x00465de0;
L_0x00465dda:
    // 00465dda  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00465dde  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00465de0:
    // 00465de0  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00465de4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465de6  7409                   -je 0x465df1
    if (cpu.flags.zf)
    {
        goto L_0x00465df1;
    }
    // 00465de8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465dea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465deb  ff1568724800           -call dword ptr [0x487268]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747880) /* 0x487268 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00465df1:
    // 00465df1  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00465df3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465df4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465df5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465df6  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00465df9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_465e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00465e00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465e01  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00465e03  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00465e06  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465e07  685c124a00             -push 0x4a125c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854364 /*0x4a125c*/;
    cpu.esp -= 4;
    // 00465e0c  e8a60f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465e11  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00465e14  8b7618                 -mov esi, dword ptr [esi + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00465e17  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465e1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465e1c  785b                   -js 0x465e79
    if (cpu.flags.sf)
    {
        goto L_0x00465e79;
    }
    // 00465e1e  83fe08                 +cmp esi, 8
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
    // 00465e21  0f870d010000           -ja 0x465f34
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00465f34;
    }
    // 00465e27  ff24b5445f4600         -jmp dword ptr [esi*4 + 0x465f44]
    cpu.ip = app->getMemory<x86::reg32>(4611908 + cpu.esi * 4); goto dynamic_jump;
  case 0x00465e2e:
    // 00465e2e  6850124a00             -push 0x4a1250
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854352 /*0x4a1250*/;
    cpu.esp -= 4;
    // 00465e33  e87f0f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465e38  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465e3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e3c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465e3d:
    // 00465e3d  6844124a00             -push 0x4a1244
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854340 /*0x4a1244*/;
    cpu.esp -= 4;
    // 00465e42  e8700f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465e47  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465e4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e4b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465e4c:
    // 00465e4c  6838124a00             -push 0x4a1238
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854328 /*0x4a1238*/;
    cpu.esp -= 4;
    // 00465e51  e8610f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465e56  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465e59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e5a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465e5b:
    // 00465e5b  682c124a00             -push 0x4a122c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854316 /*0x4a122c*/;
    cpu.esp -= 4;
    // 00465e60  e8520f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465e65  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465e68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e69  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465e6a:
    // 00465e6a  6818124a00             -push 0x4a1218
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854296 /*0x4a1218*/;
    cpu.esp -= 4;
    // 00465e6f  e8430f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465e74  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465e77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465e79:
    // 00465e79  8d8600f0ffff           -lea eax, [esi - 0x1000]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-4096) /* -0x1000 */);
    // 00465e7f  83f80a                 +cmp eax, 0xa
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
    // 00465e82  0f87ac000000           -ja 0x465f34
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00465f34;
    }
    // 00465e88  ff2485685f4600         -jmp dword ptr [eax*4 + 0x465f68]
    cpu.ip = app->getMemory<x86::reg32>(4611944 + cpu.eax * 4); goto dynamic_jump;
  case 0x00465e8f:
    // 00465e8f  680c124a00             -push 0x4a120c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854284 /*0x4a120c*/;
    cpu.esp -= 4;
    // 00465e94  e81e0f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465e99  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465e9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e9d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465e9e:
    // 00465e9e  6800124a00             -push 0x4a1200
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854272 /*0x4a1200*/;
    cpu.esp -= 4;
    // 00465ea3  e80f0f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465ea8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465eab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465eac  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465ead:
    // 00465ead  68f4114a00             -push 0x4a11f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854260 /*0x4a11f4*/;
    cpu.esp -= 4;
    // 00465eb2  e8000f0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465eb7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465eba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ebb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465ebc:
    // 00465ebc  68e8114a00             -push 0x4a11e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854248 /*0x4a11e8*/;
    cpu.esp -= 4;
    // 00465ec1  e8f10e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465ec6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465ec9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465eca  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465ecb:
    // 00465ecb  68d8114a00             -push 0x4a11d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854232 /*0x4a11d8*/;
    cpu.esp -= 4;
    // 00465ed0  e8e20e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465ed5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465ed8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ed9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465eda:
    // 00465eda  68c8114a00             -push 0x4a11c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854216 /*0x4a11c8*/;
    cpu.esp -= 4;
    // 00465edf  e8d30e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465ee4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465ee7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ee8  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465ee9:
    // 00465ee9  68bc114a00             -push 0x4a11bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854204 /*0x4a11bc*/;
    cpu.esp -= 4;
    // 00465eee  e8c40e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465ef3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465ef6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ef7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465ef8:
    // 00465ef8  68b0114a00             -push 0x4a11b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854192 /*0x4a11b0*/;
    cpu.esp -= 4;
    // 00465efd  e8b50e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465f02  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465f05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f06  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465f07:
    // 00465f07  68a4114a00             -push 0x4a11a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854180 /*0x4a11a4*/;
    cpu.esp -= 4;
    // 00465f0c  e8a60e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465f11  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465f14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f15  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465f16:
    // 00465f16  6898114a00             -push 0x4a1198
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854168 /*0x4a1198*/;
    cpu.esp -= 4;
    // 00465f1b  e8970e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465f20  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465f23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f24  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00465f25:
    // 00465f25  6890114a00             -push 0x4a1190
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854160 /*0x4a1190*/;
    cpu.esp -= 4;
    // 00465f2a  e8880e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465f2f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465f32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465f34:
    // 00465f34  6884114a00             -push 0x4a1184
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854148 /*0x4a1184*/;
    cpu.esp -= 4;
    // 00465f39  e8790e0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00465f3e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465f41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f42  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_465fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465fa0  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00465fa3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465fa4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465fa5  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00465fa9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465faa  83feff                 +cmp esi, -1
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
    // 00465fad  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00465faf  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00465fb1  7440                   -je 0x465ff3
    if (cpu.flags.zf)
    {
        goto L_0x00465ff3;
    }
    // 00465fb3  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00465fb7  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00465fb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465fba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465fbb  ff1544724800           -call dword ptr [0x487244]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747844) /* 0x487244 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465fc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465fc3  740b                   -je 0x465fd0
    if (cpu.flags.zf)
    {
        goto L_0x00465fd0;
    }
    // 00465fc5  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00465fc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fca  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00465fcd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00465fd0:
    // 00465fd0  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00465fd5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00465fd7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465fd8  8d4c244c               -lea ecx, [esp + 0x4c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00465fdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465fdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465fde  ff1548724800           -call dword ptr [0x487248]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747848) /* 0x487248 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00465fe4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465fe6  7413                   -je 0x465ffb
    if (cpu.flags.zf)
    {
        goto L_0x00465ffb;
    }
    // 00465fe8  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00465fea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465feb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fed  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00465ff0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00465ff3:
    // 00465ff3  c744244000000000       -mov dword ptr [esp + 0x40], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x00465ffb:
    // 00465ffb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00465ffd  7407                   -je 0x466006
    if (cpu.flags.zf)
    {
        goto L_0x00466006;
    }
    // 00465fff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466000  ff154c724800           -call dword ptr [0x48724c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747852) /* 0x48724c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00466006:
    // 00466006  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046600a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046600b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046600c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046600d  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00466010  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_466020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466020  81ecdc000000           -sub esp, 0xdc
    (cpu.esp) -= x86::reg32(x86::sreg32(220 /*0xdc*/));
    // 00466026  a158ba5100             -mov eax, dword ptr [0x51ba58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 0046602b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046602c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046602d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046602e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046602f  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00466031  3bc7                   +cmp eax, edi
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
    // 00466033  c7442410ffffffff       -mov dword ptr [esp + 0x10], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 4294967295 /*0xffffffff*/;
    // 0046603b  7510                   -jne 0x46604d
    if (!cpu.flags.zf)
    {
        goto L_0x0046604d;
    }
    // 0046603d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046603e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046603f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466040  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00466043  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466044  81c4dc000000           -add esp, 0xdc
    (cpu.esp) += x86::reg32(x86::sreg32(220 /*0xdc*/));
    // 0046604a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0046604d:
    // 0046604d  8d8c24bc000000         -lea ecx, [esp + 0xbc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00466054  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00466056  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466057  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466058  ff1544724800           -call dword ptr [0x487244]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747844) /* 0x487244 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046605e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466060  7407                   -je 0x466069
    if (cpu.flags.zf)
    {
        goto L_0x00466069;
    }
    // 00466062  89bc24e8000000         -mov dword ptr [esp + 0xe8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */) = cpu.edi;
L_0x00466069:
    // 00466069  39bc24e8000000         +cmp dword ptr [esp + 0xe8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466070  0f86bd000000           -jbe 0x466133
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466133;
    }
    // 00466076  8b2d40724800           -mov ebp, dword ptr [0x487240]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747840) /* 0x487240 */);
L_0x0046607c:
    // 0046607c  a158ba5100             -mov eax, dword ptr [0x51ba58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 00466081  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00466085  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00466087  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466088  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466089  c7442420a8000000       -mov dword ptr [esp + 0x20], 0xa8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 168 /*0xa8*/;
    // 00466091  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00466095  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00466097  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466099  0f8584000000           -jne 0x466123
    if (!cpu.flags.zf)
    {
        goto L_0x00466123;
    }
    // 0046609f  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004660a3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004660a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004660a7  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004660a9  7678                   -jbe 0x466123
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466123;
    }
L_0x004660ab:
    // 004660ab  8b1558ba5100           -mov edx, dword ptr [0x51ba58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 004660b1  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004660b5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004660b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004660b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004660b9  c7442420a8000000       -mov dword ptr [esp + 0x20], 0xa8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 168 /*0xa8*/;
    // 004660c1  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004660c5  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004660c9  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004660cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004660cd  754f                   -jne 0x46611e
    if (!cpu.flags.zf)
    {
        goto L_0x0046611e;
    }
    // 004660cf  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004660d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004660d4  6878124a00             -push 0x4a1278
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854392 /*0x4a1278*/;
    cpu.esp -= 4;
    // 004660d9  e8d90c0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004660de  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004660e1  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004660e5  e816fdffff             -call 0x465e00
    cpu.esp -= 4;
    sub_465e00(app, cpu);
    // 004660ea  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004660ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004660f0  792c                   -jns 0x46611e
    if (!cpu.flags.sf)
    {
        goto L_0x0046611e;
    }
    // 004660f2  817c242c05100000       +cmp dword ptr [esp + 0x2c], 0x1005
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4101 /*0x1005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004660fa  7522                   -jne 0x46611e
    if (!cpu.flags.zf)
    {
        goto L_0x0046611e;
    }
    // 004660fc  8b8c24f0000000         -mov ecx, dword ptr [esp + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 00466103  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466104  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00466108  e873010000             -call 0x466280
    cpu.esp -= 4;
    sub_466280(app, cpu);
    // 0046610d  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00466111  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00466115  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00466118  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046611c  7519                   -jne 0x466137
    if (!cpu.flags.zf)
    {
        goto L_0x00466137;
    }
L_0x0046611e:
    // 0046611e  46                     -inc esi
    (cpu.esi)++;
    // 0046611f  3bf3                   +cmp esi, ebx
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
    // 00466121  7288                   -jb 0x4660ab
    if (cpu.flags.cf)
    {
        goto L_0x004660ab;
    }
L_0x00466123:
    // 00466123  8b8424e8000000         -mov eax, dword ptr [esp + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 0046612a  47                     -inc edi
    (cpu.edi)++;
    // 0046612b  3bf8                   +cmp edi, eax
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
    // 0046612d  0f8249ffffff           -jb 0x46607c
    if (cpu.flags.cf)
    {
        goto L_0x0046607c;
    }
L_0x00466133:
    // 00466133  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00466137:
    // 00466137  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466138  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466139  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046613a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046613b  81c4dc000000           -add esp, 0xdc
    (cpu.esp) += x86::reg32(x86::sreg32(220 /*0xdc*/));
    // 00466141  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_466150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466150  81ecdc000000           -sub esp, 0xdc
    (cpu.esp) -= x86::reg32(x86::sreg32(220 /*0xdc*/));
    // 00466156  a158ba5100             -mov eax, dword ptr [0x51ba58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 0046615b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046615c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046615d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046615e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046615f  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00466161  3bc7                   +cmp eax, edi
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
    // 00466163  c7442410ffffffff       -mov dword ptr [esp + 0x10], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 4294967295 /*0xffffffff*/;
    // 0046616b  7510                   -jne 0x46617d
    if (!cpu.flags.zf)
    {
        goto L_0x0046617d;
    }
    // 0046616d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046616e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046616f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466170  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00466173  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466174  81c4dc000000           -add esp, 0xdc
    (cpu.esp) += x86::reg32(x86::sreg32(220 /*0xdc*/));
    // 0046617a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0046617d:
    // 0046617d  8d8c24bc000000         -lea ecx, [esp + 0xbc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00466184  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00466186  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466187  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466188  ff1544724800           -call dword ptr [0x487244]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747844) /* 0x487244 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046618e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466190  7407                   -je 0x466199
    if (cpu.flags.zf)
    {
        goto L_0x00466199;
    }
    // 00466192  89bc24e8000000         -mov dword ptr [esp + 0xe8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */) = cpu.edi;
L_0x00466199:
    // 00466199  39bc24e8000000         +cmp dword ptr [esp + 0xe8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004661a0  0f86bd000000           -jbe 0x466263
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466263;
    }
    // 004661a6  8b2d40724800           -mov ebp, dword ptr [0x487240]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747840) /* 0x487240 */);
L_0x004661ac:
    // 004661ac  a158ba5100             -mov eax, dword ptr [0x51ba58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 004661b1  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004661b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004661b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004661b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004661b9  c7442420a8000000       -mov dword ptr [esp + 0x20], 0xa8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 168 /*0xa8*/;
    // 004661c1  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004661c5  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004661c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004661c9  0f8584000000           -jne 0x466253
    if (!cpu.flags.zf)
    {
        goto L_0x00466253;
    }
    // 004661cf  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004661d3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004661d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004661d7  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004661d9  7678                   -jbe 0x466253
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466253;
    }
L_0x004661db:
    // 004661db  8b1558ba5100           -mov edx, dword ptr [0x51ba58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 004661e1  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004661e5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004661e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004661e8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004661e9  c7442420a8000000       -mov dword ptr [esp + 0x20], 0xa8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 168 /*0xa8*/;
    // 004661f1  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004661f5  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004661f9  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004661fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004661fd  754f                   -jne 0x46624e
    if (!cpu.flags.zf)
    {
        goto L_0x0046624e;
    }
    // 004661ff  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00466203  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466204  6878124a00             -push 0x4a1278
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854392 /*0x4a1278*/;
    cpu.esp -= 4;
    // 00466209  e8a90b0100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046620e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466211  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00466215  e8e6fbffff             -call 0x465e00
    cpu.esp -= 4;
    sub_465e00(app, cpu);
    // 0046621a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046621e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466220  792c                   -jns 0x46624e
    if (!cpu.flags.sf)
    {
        goto L_0x0046624e;
    }
    // 00466222  817c242c08100000       +cmp dword ptr [esp + 0x2c], 0x1008
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4104 /*0x1008*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046622a  7522                   -jne 0x46624e
    if (!cpu.flags.zf)
    {
        goto L_0x0046624e;
    }
    // 0046622c  8b8c24f0000000         -mov ecx, dword ptr [esp + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 00466233  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466234  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00466238  e843000000             -call 0x466280
    cpu.esp -= 4;
    sub_466280(app, cpu);
    // 0046623d  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00466241  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00466245  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00466248  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046624c  7519                   -jne 0x466267
    if (!cpu.flags.zf)
    {
        goto L_0x00466267;
    }
L_0x0046624e:
    // 0046624e  46                     -inc esi
    (cpu.esi)++;
    // 0046624f  3bf3                   +cmp esi, ebx
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
    // 00466251  7288                   -jb 0x4661db
    if (cpu.flags.cf)
    {
        goto L_0x004661db;
    }
L_0x00466253:
    // 00466253  8b8424e8000000         -mov eax, dword ptr [esp + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 0046625a  47                     -inc edi
    (cpu.edi)++;
    // 0046625b  3bf8                   +cmp edi, eax
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
    // 0046625d  0f8249ffffff           -jb 0x4661ac
    if (cpu.flags.cf)
    {
        goto L_0x004661ac;
    }
L_0x00466263:
    // 00466263  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00466267:
    // 00466267  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466268  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466269  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046626a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046626b  81c4dc000000           -add esp, 0xdc
    (cpu.esp) += x86::reg32(x86::sreg32(220 /*0xdc*/));
    // 00466271  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_466280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466280  81ece8000000           -sub esp, 0xe8
    (cpu.esp) -= x86::reg32(x86::sreg32(232 /*0xe8*/));
    // 00466286  d98424ec000000         -fld dword ptr [esp + 0xec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(236) /* 0xec */)));
    // 0046628d  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00466293  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466294  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466295  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00466297  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466298  c744244ca8000000       -mov dword ptr [esp + 0x4c], 0xa8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = 168 /*0xa8*/;
    // 004662a0  89742458               -mov dword ptr [esp + 0x58], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.esi;
    // 004662a4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004662a6  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004662a9  7a0d                   -jp 0x4662b8
    if (cpu.flags.pf)
    {
        goto L_0x004662b8;
    }
    // 004662ab  c78424f800000000000000 -mov dword ptr [esp + 0xf8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */) = 0 /*0x0*/;
    // 004662b6  eb21                   -jmp 0x4662d9
    goto L_0x004662d9;
L_0x004662b8:
    // 004662b8  d98424f8000000         -fld dword ptr [esp + 0xf8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(248) /* 0xf8 */)));
    // 004662bf  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 004662c5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004662c7  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004662cc  750b                   -jne 0x4662d9
    if (!cpu.flags.zf)
    {
        goto L_0x004662d9;
    }
    // 004662ce  c78424f80000000000803f -mov dword ptr [esp + 0xf8], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */) = 1065353216 /*0x3f800000*/;
L_0x004662d9:
    // 004662d9  8b0d58ba5100           -mov ecx, dword ptr [0x51ba58]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 004662df  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004662e3  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004662e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004662e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004662e7  ff1540724800           -call dword ptr [0x487240]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747840) /* 0x487240 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004662ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004662ef  0f8552010000           -jne 0x466447
    if (!cpu.flags.zf)
    {
        goto L_0x00466447;
    }
    // 004662f5  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004662f9  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004662fb  3bc5                   +cmp eax, ebp
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
    // 004662fd  0f8444010000           -je 0x466447
    if (cpu.flags.zf)
    {
        goto L_0x00466447;
    }
    // 00466303  8d14c0                 -lea edx, [eax + eax*8]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00466306  8d0490                 -lea eax, [eax + edx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 4);
    // 00466309  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046630c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046630d  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0046630f  ff15a0704800           -call dword ptr [0x4870a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747424) /* 0x4870a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00466315  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00466317  3bfd                   +cmp edi, ebp
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
    // 00466319  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0046631d  0f8424010000           -je 0x466447
    if (cpu.flags.zf)
    {
        goto L_0x00466447;
    }
    // 00466323  8b1558ba5100           -mov edx, dword ptr [0x51ba58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 00466329  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0046632d  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00466331  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466332  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466333  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466334  c744242818000000       -mov dword ptr [esp + 0x28], 0x18
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 24 /*0x18*/;
    // 0046633c  8974242c               -mov dword ptr [esp + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 00466340  896c2430               -mov dword ptr [esp + 0x30], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebp;
    // 00466344  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00466348  c744243894000000       -mov dword ptr [esp + 0x38], 0x94
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 148 /*0x94*/;
    // 00466350  897c243c               -mov dword ptr [esp + 0x3c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edi;
    // 00466354  ff1538724800           -call dword ptr [0x487238]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747832) /* 0x487238 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0046635a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046635c  0f85de000000           -jne 0x466440
    if (!cpu.flags.zf)
    {
        goto L_0x00466440;
    }
    // 00466362  396c2428               +cmp dword ptr [esp + 0x28], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466366  0f86d4000000           -jbe 0x466440
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466440;
    }
    // 0046636c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046636d  8b1d3c724800           -mov ebx, dword ptr [0x48723c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747836) /* 0x48723c */);
    // 00466373  8d770c                 -lea esi, [edi + 0xc]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
L_0x00466376:
    // 00466376  817efc01000350         +cmp dword ptr [esi - 4], 0x50030001
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1342373889 /*0x50030001*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046637d  0f85a9000000           -jne 0x46642c
    if (!cpu.flags.zf)
    {
        goto L_0x0046642c;
    }
    // 00466383  833e00                 +cmp dword ptr [esi], 0
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
    // 00466386  0f88a0000000           -js 0x46642c
    if (cpu.flags.sf)
    {
        goto L_0x0046642c;
    }
    // 0046638c  c744243818000000       -mov dword ptr [esp + 0x38], 0x18
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 24 /*0x18*/;
    // 00466394  8b46f8                 -mov eax, dword ptr [esi - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */);
    // 00466397  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0046639b  c744244001000000       -mov dword ptr [esp + 0x40], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
    // 004663a3  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004663a6  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004663aa  894c2444               -mov dword ptr [esp + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ecx;
    // 004663ae  8b0d58ba5100           -mov ecx, dword ptr [0x51ba58]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 004663b4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004663b6  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004663ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004663bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004663bc  c744245404000000       -mov dword ptr [esp + 0x54], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 4 /*0x4*/;
    // 004663c4  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 004663c8  ff1578724800           -call dword ptr [0x487278]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747896) /* 0x487278 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004663ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004663d0  755a                   -jne 0x46642c
    if (!cpu.flags.zf)
    {
        goto L_0x0046642c;
    }
    // 004663d2  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004663d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004663d7  6890124a00             -push 0x4a1290
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854416 /*0x4a1290*/;
    cpu.esp -= 4;
    // 004663dc  e8d6090100             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004663e1  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 004663e6  e87c150100             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 004663eb  8b7e58                 -mov edi, dword ptr [esi + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004663ee  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004663f1  2bc7                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004663f3  c744242800000000       -mov dword ptr [esp + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004663fb  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004663ff  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00466402  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00466406  d88c24fc000000         -fmul dword ptr [esp + 0xfc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(252) /* 0xfc */));
    // 0046640d  e87e090100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00466412  8b1558ba5100           -mov edx, dword ptr [0x51ba58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 00466418  8d4c2438               -lea ecx, [esp + 0x38]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046641c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046641e  03c7                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00466420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466421  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466422  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00466426  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00466428  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x0046642c:
    // 0046642c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00466430  45                     -inc ebp
    (cpu.ebp)++;
    // 00466431  81c694000000           -add esi, 0x94
    (cpu.esi) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 00466437  3be8                   +cmp ebp, eax
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
    // 00466439  0f8237ffffff           -jb 0x466376
    if (cpu.flags.cf)
    {
        goto L_0x00466376;
    }
    // 0046643f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00466440:
    // 00466440  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466441  ff159c704800           -call dword ptr [0x48709c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747420) /* 0x48709c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00466447:
    // 00466447  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466448  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466449  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046644a  81c4e8000000           -add esp, 0xe8
    (cpu.esp) += x86::reg32(x86::sreg32(232 /*0xe8*/));
    // 00466450  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_466460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466460  8b1558ba5100           -mov edx, dword ptr [0x51ba58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 00466466  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00466468  e833fbffff             -call 0x465fa0
    cpu.esp -= 4;
    sub_465fa0(app, cpu);
    // 0046646d  a358ba5100             -mov dword ptr [0x51ba58], eax
    app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */) = cpu.eax;
    // 00466472  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466480  8b1558ba5100           -mov edx, dword ptr [0x51ba58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 00466486  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00466488  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046648a  e811fbffff             -call 0x465fa0
    cpu.esp -= 4;
    sub_465fa0(app, cpu);
    // 0046648f  a358ba5100             -mov dword ptr [0x51ba58], eax
    app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */) = cpu.eax;
    // 00466494  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4664a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004664a0  e8bbffffff             -call 0x466460
    cpu.esp -= 4;
    sub_466460(app, cpu);
    // 004664a5  a158ba5100             -mov eax, dword ptr [0x51ba58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 004664aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004664ac  740a                   -je 0x4664b8
    if (cpu.flags.zf)
    {
        goto L_0x004664b8;
    }
    // 004664ae  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004664b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004664b3  e868fbffff             -call 0x466020
    cpu.esp -= 4;
    sub_466020(app, cpu);
L_0x004664b8:
    // 004664b8  e8c3ffffff             -call 0x466480
    cpu.esp -= 4;
    sub_466480(app, cpu);
    // 004664bd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4664c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004664c0  e89bffffff             -call 0x466460
    cpu.esp -= 4;
    sub_466460(app, cpu);
    // 004664c5  a158ba5100             -mov eax, dword ptr [0x51ba58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356120) /* 0x51ba58 */);
    // 004664ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004664cc  740a                   -je 0x4664d8
    if (cpu.flags.zf)
    {
        goto L_0x004664d8;
    }
    // 004664ce  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004664d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004664d3  e878fcffff             -call 0x466150
    cpu.esp -= 4;
    sub_466150(app, cpu);
L_0x004664d8:
    // 004664d8  e8a3ffffff             -call 0x466480
    cpu.esp -= 4;
    sub_466480(app, cpu);
    // 004664dd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4664e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004664e0  a164ba5100             -mov eax, dword ptr [0x51ba64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 004664e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004664e7  751d                   -jne 0x466506
    if (!cpu.flags.zf)
    {
        goto L_0x00466506;
    }
    // 004664e9  a174ba5100             -mov eax, dword ptr [0x51ba74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */);
    // 004664ee  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004664f0  a1a8124a00             -mov eax, dword ptr [0x4a12a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4854440) /* 0x4a12a8 */);
    // 004664f5  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004664f7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004664f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004664f9  68c4124a00             -push 0x4a12c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854468 /*0x4a12c4*/;
    cpu.esp -= 4;
    // 004664fe  e82d6cfbff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 00466503  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00466506:
    // 00466506  8b0d64ba5100           -mov ecx, dword ptr [0x51ba64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 0046650c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046650e  803901                 +cmp byte ptr [ecx], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00466511  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00466514  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466520  a164ba5100             -mov eax, dword ptr [0x51ba64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 00466525  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466527  751d                   -jne 0x466546
    if (!cpu.flags.zf)
    {
        goto L_0x00466546;
    }
    // 00466529  a174ba5100             -mov eax, dword ptr [0x51ba74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */);
    // 0046652e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00466530  a1a8124a00             -mov eax, dword ptr [0x4a12a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4854440) /* 0x4a12a8 */);
    // 00466535  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00466537  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466538  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466539  68d0124a00             -push 0x4a12d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854480 /*0x4a12d0*/;
    cpu.esp -= 4;
    // 0046653e  e8ed6bfbff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 00466543  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00466546:
    // 00466546  8b0d64ba5100           -mov ecx, dword ptr [0x51ba64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 0046654c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046654e  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00466550  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466560  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466563  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466564  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00466566  e8b5ffffff             -call 0x466520
    cpu.esp -= 4;
    sub_466520(app, cpu);
    // 0046656b  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046656f  7529                   -jne 0x46659a
    if (!cpu.flags.zf)
    {
        goto L_0x0046659a;
    }
    // 00466571  68dc124a00             -push 0x4a12dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854492 /*0x4a12dc*/;
    cpu.esp -= 4;
    // 00466576  e895e6fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046657b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046657e:
    // 0046657e  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00466582  e849000000             -call 0x4665d0
    cpu.esp -= 4;
    sub_4665d0(app, cpu);
    // 00466587  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0046658b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046658d  7406                   -je 0x466595
    if (cpu.flags.zf)
    {
        goto L_0x00466595;
    }
    // 0046658f  c706ffffffff           -mov dword ptr [esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi) = 4294967295 /*0xffffffff*/;
L_0x00466595:
    // 00466595  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466596  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466599  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046659a:
    // 0046659a  663d0200               +cmp ax, 2
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046659e  75de                   -jne 0x46657e
    if (!cpu.flags.zf)
    {
        goto L_0x0046657e;
    }
    // 004665a0  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004665a4  e827000000             -call 0x4665d0
    cpu.esp -= 4;
    sub_4665d0(app, cpu);
    // 004665a9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004665ad  8b0d68ba5100           -mov ecx, dword ptr [0x51ba68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356136) /* 0x51ba68 */);
    // 004665b3  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004665b9  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004665bb  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004665c0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004665c2  d90482                 +fld dword ptr [edx + eax*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + cpu.eax * 4)));
    // 004665c5  74ce                   -je 0x466595
    if (cpu.flags.zf)
    {
        goto L_0x00466595;
    }
    // 004665c7  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004665c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004665ca  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004665cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4665d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004665d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004665d1  a170ba5100             -mov eax, dword ptr [0x51ba70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356144) /* 0x51ba70 */);
    // 004665d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004665d7  48                     -dec eax
    (cpu.eax)--;
    // 004665d8  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004665da  a370ba5100             -mov dword ptr [0x51ba70], eax
    app->getMemory<x86::reg32>(x86::reg32(5356144) /* 0x51ba70 */) = cpu.eax;
    // 004665df  a174ba5100             -mov eax, dword ptr [0x51ba74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */);
    // 004665e4  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004665e7  4a                     -dec edx
    (cpu.edx)--;
    // 004665e8  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004665eb  a164ba5100             -mov eax, dword ptr [0x51ba64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 004665f0  8b0d74ba5100           -mov ecx, dword ptr [0x51ba74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */);
    // 004665f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004665f8  7411                   -je 0x46660b
    if (cpu.flags.zf)
    {
        goto L_0x0046660b;
    }
    // 004665fa  8b1570ba5100           -mov edx, dword ptr [0x51ba70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356144) /* 0x51ba70 */);
    // 00466600  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00466602  7c07                   -jl 0x46660b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046660b;
    }
    // 00466604  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00466607  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00466609  7d1e                   -jge 0x466629
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466629;
    }
L_0x0046660b:
    // 0046660b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046660d  8b15a8124a00           -mov edx, dword ptr [0x4a12a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4854440) /* 0x4a12a8 */);
    // 00466613  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00466615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466616  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466617  6804134a00             -push 0x4a1304
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854532 /*0x4a1304*/;
    cpu.esp -= 4;
    // 0046661c  e80f6bfbff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 00466621  a164ba5100             -mov eax, dword ptr [0x51ba64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 00466626  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00466629:
    // 00466629  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046662b  80f901                 +cmp cl, 1
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046662e  7509                   -jne 0x466639
    if (!cpu.flags.zf)
    {
        goto L_0x00466639;
    }
    // 00466630  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00466633  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00466637  eb18                   -jmp 0x466651
    goto L_0x00466651;
L_0x00466639:
    // 00466639  80f902                 +cmp cl, 2
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046663c  7509                   -jne 0x466647
    if (!cpu.flags.zf)
    {
        goto L_0x00466647;
    }
    // 0046663e  668b5004               -mov dx, word ptr [eax + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00466642  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 00466645  eb05                   -jmp 0x46664c
    goto L_0x0046664c;
L_0x00466647:
    // 00466647  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046664a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0046664c:
    // 0046664c  a164ba5100             -mov eax, dword ptr [0x51ba64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
L_0x00466651:
    // 00466651  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00466654  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00466656  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466659  891564ba5100           -mov dword ptr [0x51ba64], edx
    app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */) = cpu.edx;
    // 0046665f  8b156cba5100           -mov edx, dword ptr [0x51ba6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */);
    // 00466665  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466666  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00466668  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046666c  890d6cba5100           -mov dword ptr [0x51ba6c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */) = cpu.ecx;
    // 00466672  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466673  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466680  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466681  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466682  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00466684  e897feffff             -call 0x466520
    cpu.esp -= 4;
    sub_466520(app, cpu);
    // 00466689  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046668d  7538                   -jne 0x4666c7
    if (!cpu.flags.zf)
    {
        goto L_0x004666c7;
    }
    // 0046668f  68dc124a00             -push 0x4a12dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854492 /*0x4a12dc*/;
    cpu.esp -= 4;
    // 00466694  e877e5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466699  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046669c:
    // 0046669c  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004666a0  e82bffffff             -call 0x4665d0
    cpu.esp -= 4;
    sub_4665d0(app, cpu);
    // 004666a5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004666a7  7417                   -je 0x4666c0
    if (cpu.flags.zf)
    {
        goto L_0x004666c0;
    }
    // 004666a9  a174ba5100             -mov eax, dword ptr [0x51ba74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */);
    // 004666ae  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004666b0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004666b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004666b3  6810134a00             -push 0x4a1310
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854544 /*0x4a1310*/;
    cpu.esp -= 4;
    // 004666b8  e853e5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004666bd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004666c0:
    // 004666c0  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
L_0x004666c4:
    // 004666c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004666c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004666c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004666c7:
    // 004666c7  663d0200               +cmp ax, 2
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004666cb  75cf                   -jne 0x46669c
    if (!cpu.flags.zf)
    {
        goto L_0x0046669c;
    }
    // 004666cd  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004666d1  e8fafeffff             -call 0x4665d0
    cpu.esp -= 4;
    sub_4665d0(app, cpu);
    // 004666d6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004666da  8b0d68ba5100           -mov ecx, dword ptr [0x51ba68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356136) /* 0x51ba68 */);
    // 004666e0  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004666e6  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004666e8  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004666ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004666ef  d90482                 +fld dword ptr [edx + eax*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + cpu.eax * 4)));
    // 004666f2  74d0                   -je 0x4666c4
    if (cpu.flags.zf)
    {
        goto L_0x004666c4;
    }
    // 004666f4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004666f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004666f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004666f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466700  e81bfeffff             -call 0x466520
    cpu.esp -= 4;
    sub_466520(app, cpu);
    // 00466705  83f801                 +cmp eax, 1
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
    // 00466708  740d                   -je 0x466717
    if (cpu.flags.zf)
    {
        goto L_0x00466717;
    }
    // 0046670a  6850134a00             -push 0x4a1350
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854608 /*0x4a1350*/;
    cpu.esp -= 4;
    // 0046670f  e8fce4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466714  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00466717:
    // 00466717  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00466719  e9b2feffff             -jmp 0x4665d0
    return sub_4665d0(app, cpu);
}

/* align: skip  */
void Application::sub_466720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00466720  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466723  a17cba5100             -mov eax, dword ptr [0x51ba7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356156) /* 0x51ba7c */);
    // 00466728  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466729  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046672a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046672b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046672c  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046672e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466730  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00466734  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00466736  750f                   -jne 0x466747
    if (!cpu.flags.zf)
    {
        goto L_0x00466747;
    }
    // 00466738  b9fc134a00             -mov ecx, 0x4a13fc
    cpu.ecx = 4854780 /*0x4a13fc*/;
    // 0046673d  e87e040000             -call 0x466bc0
    cpu.esp -= 4;
    sub_466bc0(app, cpu);
    // 00466742  a37cba5100             -mov dword ptr [0x51ba7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5356156) /* 0x51ba7c */) = cpu.eax;
L_0x00466747:
    // 00466747  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046674b  0f8456030000           -je 0x466aa7
    if (cpu.flags.zf)
    {
        goto L_0x00466aa7;
    }
    // 00466751  833d60ba510001         +cmp dword ptr [0x51ba60], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5356128) /* 0x51ba60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466758  0f8449030000           -je 0x466aa7
    if (cpu.flags.zf)
    {
        goto L_0x00466aa7;
    }
    // 0046675e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00466760  750d                   -jne 0x46676f
    if (!cpu.flags.zf)
    {
        goto L_0x0046676f;
    }
    // 00466762  68e0134a00             -push 0x4a13e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854752 /*0x4a13e0*/;
    cpu.esp -= 4;
    // 00466767  e8a4e4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046676c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046676f:
    // 0046676f  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00466771  893574ba5100           -mov dword ptr [0x51ba74], esi
    app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */) = cpu.esi;
    // 00466777  807e0603               +cmp byte ptr [esi + 6], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046677b  7506                   -jne 0x466783
    if (!cpu.flags.zf)
    {
        goto L_0x00466783;
    }
    // 0046677d  c6460600               -mov byte ptr [esi + 6], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00466781  eb0b                   -jmp 0x46678e
    goto L_0x0046678e;
L_0x00466783:
    // 00466783  668b4720               -mov ax, word ptr [edi + 0x20]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00466787  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0046678a  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
L_0x0046678e:
    // 0046678e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466790  668b4e04               -mov cx, word ptr [esi + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00466794  890d68ba5100           -mov dword ptr [0x51ba68], ecx
    app->getMemory<x86::reg32>(x86::reg32(5356136) /* 0x51ba68 */) = cpu.ecx;
    // 0046679a  8a4606                 -mov al, byte ptr [esi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0046679d  3c01                   +cmp al, 1
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
    // 0046679f  0f8f02030000           -jg 0x466aa7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00466aa7;
    }
L_0x004667a5:
    // 004667a5  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004667a9  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004667ab  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004667b1  40                     -inc eax
    (cpu.eax)++;
    // 004667b2  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004667b6  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004667b9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004667bb  8a04ea                 -mov al, byte ptr [edx + ebp*8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.ebp * 8);
    // 004667be  8d3cea                 -lea edi, [edx + ebp*8]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebp * 8);
    // 004667c1  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004667c4  0f8778020000           -ja 0x466a42
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00466a42;
    }
    // 004667ca  ff2485b06a4600         -jmp dword ptr [eax*4 + 0x466ab0]
    cpu.ip = app->getMemory<x86::reg32>(4614832 + cpu.eax * 4); goto dynamic_jump;
  case 0x004667d1:
    // 004667d1  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004667d4  a17cba5100             -mov eax, dword ptr [0x51ba7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356156) /* 0x51ba7c */);
    // 004667d9  3bf8                   +cmp edi, eax
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
    // 004667db  0f8473020000           -je 0x466a54
    if (cpu.flags.zf)
    {
        goto L_0x00466a54;
    }
    // 004667e1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004667e3  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004667e5  807e0601               +cmp byte ptr [esi + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004667e9  0f8fb8020000           -jg 0x466aa7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00466aa7;
    }
    // 004667ef  45                     -inc ebp
    (cpu.ebp)++;
    // 004667f0  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004667f2  66896e08               -mov word ptr [esi + 8], bp
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.bp;
    // 004667f6  893574ba5100           -mov dword ptr [0x51ba74], esi
    app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */) = cpu.esi;
    // 004667fc  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00466800  a368ba5100             -mov dword ptr [0x51ba68], eax
    app->getMemory<x86::reg32>(x86::reg32(5356136) /* 0x51ba68 */) = cpu.eax;
    // 00466805  e938020000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x0046680a:
    // 0046680a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046680c  e84ffdffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00466811  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00466815  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466817  e844fdffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046681c  d9542414               -fst dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    // 00466820  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00466824  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00466828  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0046682d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046682e  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00466830  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00466834  e8c7020000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 00466839  e904020000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x0046683e:
    // 0046683e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466840  e81bfdffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00466845  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00466849  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046684b  e810fdffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00466850  d8742410               +fdiv dword ptr [esp + 0x10]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00466854  e994000000             -jmp 0x4668ed
    goto L_0x004668ed;
  case 0x00466859:
    // 00466859  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046685b  e800fdffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00466860  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00466864  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466866  e8f5fcffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046686b  d9542414               -fst dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    // 0046686f  e81c050100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00466874  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00466878  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046687a  e811050100             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0046687f  33f8                   -xor edi, eax
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466881  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00466885  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00466889  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046688a  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0046688e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00466893  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00466895  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00466899  e862020000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 0046689e  e99f010000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x004668a3:
    // 004668a3  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004668a5  e8b6fcffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004668aa  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004668ae  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004668b0  e8abfcffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004668b5  d9542414               -fst dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    // 004668b9  d8442410               -fadd dword ptr [esp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004668bd  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004668c1  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004668c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004668c7  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004668c9  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004668cd  e82e020000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 004668d2  e96b010000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x004668d7:
    // 004668d7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004668d9  e882fcffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004668de  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004668e2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004668e4  e877fcffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004668e9  d8642410               -fsub dword ptr [esp + 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
L_0x004668ed:
    // 004668ed  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004668f1  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004668f5  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004668f7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004668f8  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004668fd  e8fe010000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 00466902  e93b010000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x00466907:
    // 00466907  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00466909  e852fcffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046690e  d95c2410               +fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00466912  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00466916  e845fcffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046691b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046691f  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00466925  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00466927  d9442410               +fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0046692b  d91c81                 +fstp dword ptr [ecx + eax*4]
    app->getMemory<float>(cpu.ecx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046692e  e90f010000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x00466933:
    // 00466933  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00466936  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466937  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0046693c  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046693e  e8bd010000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 00466943  e9fa000000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x00466948:
    // 00466948  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0046694b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046694d  668b5702               -mov dx, word ptr [edi + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00466951  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466952  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00466954  e8a7010000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 00466959  e9e4000000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x0046695e:
    // 0046695e  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00466961  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00466963  668b5702               -mov dx, word ptr [edi + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00466967  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466968  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046696d  e88e010000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 00466972  e9cb000000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x00466977:
    // 00466977  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466979  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00466981  e8dafbffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00466986  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0046698c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046698e  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00466991  7a08                   -jp 0x46699b
    if (cpu.flags.pf)
    {
        goto L_0x0046699b;
    }
    // 00466993  c74424100000803f       -mov dword ptr [esp + 0x10], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1065353216 /*0x3f800000*/;
L_0x0046699b:
    // 0046699b  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046699f  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004669a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004669a2  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004669a7  e854010000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 004669ac  e991000000             -jmp 0x466a42
    goto L_0x00466a42;
  case 0x004669b1:
    // 004669b1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004669b3  e8a8fbffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004669b8  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004669be  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004669c3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004669c5  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004669c8  7a16                   -jp 0x4669e0
    if (cpu.flags.pf)
    {
        goto L_0x004669e0;
    }
    // 004669ca  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004669ce  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004669d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004669d1  c74424140000803f       -mov dword ptr [esp + 0x14], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1065353216 /*0x3f800000*/;
    // 004669d9  e822010000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 004669de  eb62                   -jmp 0x466a42
    goto L_0x00466a42;
L_0x004669e0:
    // 004669e0  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004669e4  c744241000000000       -mov dword ptr [esp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004669ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004669ed  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004669ef  e80c010000             -call 0x466b00
    cpu.esp -= 4;
    sub_466b00(app, cpu);
    // 004669f4  eb4c                   -jmp 0x466a42
    goto L_0x00466a42;
  case 0x004669f6:
    // 004669f6  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004669f9  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004669fc  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00466a00  eb40                   -jmp 0x466a42
    goto L_0x00466a42;
  case 0x00466a02:
    // 00466a02  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466a04  e857fbffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00466a09  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00466a0f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00466a11  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00466a14  7a2c                   -jp 0x466a42
    if (cpu.flags.pf)
    {
        goto L_0x00466a42;
    }
    // 00466a16  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00466a19  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 00466a1c  66895608               -mov word ptr [esi + 8], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.dx;
    // 00466a20  eb20                   -jmp 0x466a42
    goto L_0x00466a42;
  case 0x00466a22:
    // 00466a22  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466a24  e837fbffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00466a29  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00466a2f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00466a31  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00466a36  750a                   -jne 0x466a42
    if (!cpu.flags.zf)
    {
        goto L_0x00466a42;
    }
    // 00466a38  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00466a3b  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00466a3e  66894e08               -mov word ptr [esi + 8], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.cx;
  [[fallthrough]];
  case 0x00466a42:
L_0x00466a42:
    // 00466a42  807e0601               +cmp byte ptr [esi + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00466a46  0f8e59fdffff           -jle 0x4667a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004667a5;
    }
    // 00466a4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a50  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466a53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466a54:
    // 00466a54  8a5606                 -mov dl, byte ptr [esi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00466a57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a58  83ca02                 -or edx, 2
    cpu.edx |= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00466a5b  885606                 -mov byte ptr [esi + 6], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00466a5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a61  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466a64  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00466a65:
    // 00466a65  8b0d74ba5100           -mov ecx, dword ptr [0x51ba74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */);
    // 00466a6b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00466a6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466a70  7435                   -je 0x466aa7
    if (cpu.flags.zf)
    {
        goto L_0x00466aa7;
    }
    // 00466a72  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00466a76  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00466a78  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00466a7a  741a                   -je 0x466a96
    if (cpu.flags.zf)
    {
        goto L_0x00466a96;
    }
    // 00466a7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466a7d  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00466a7f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466a80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466a81  68a8134a00             -push 0x4a13a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854696 /*0x4a13a8*/;
    cpu.esp -= 4;
    // 00466a86  e8a566fbff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 00466a8b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466a8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a92  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466a95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466a96:
    // 00466a96  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00466a98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466a99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466a9a  687c134a00             -push 0x4a137c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4854652 /*0x4a137c*/;
    cpu.esp -= 4;
    // 00466a9f  e88c66fbff             -call 0x41d130
    cpu.esp -= 4;
    sub_41d130(app, cpu);
    // 00466aa4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00466aa7:
    // 00466aa7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466aa8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466aa9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466aaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466aab  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466aae  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_466b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466b00  8b1570ba5100           -mov edx, dword ptr [0x51ba70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356144) /* 0x51ba70 */);
    // 00466b06  a174ba5100             -mov eax, dword ptr [0x51ba74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356148) /* 0x51ba74 */);
    // 00466b0b  42                     -inc edx
    (cpu.edx)++;
    // 00466b0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466b0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466b0f  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00466b11  891570ba5100           -mov dword ptr [0x51ba70], edx
    app->getMemory<x86::reg32>(x86::reg32(5356144) /* 0x51ba70 */) = cpu.edx;
    // 00466b17  7403                   -je 0x466b1c
    if (cpu.flags.zf)
    {
        goto L_0x00466b1c;
    }
    // 00466b19  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
L_0x00466b1c:
    // 00466b1c  a16cba5100             -mov eax, dword ptr [0x51ba6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */);
    // 00466b21  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466b23  7551                   -jne 0x466b76
    if (!cpu.flags.zf)
    {
        goto L_0x00466b76;
    }
    // 00466b25  6800030000             -push 0x300
    app->getMemory<x86::reg32>(cpu.esp-4) = 768 /*0x300*/;
    cpu.esp -= 4;
    // 00466b2a  e84b070100             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00466b2f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466b32  a36cba5100             -mov dword ptr [0x51ba6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */) = cpu.eax;
    // 00466b37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466b39  7512                   -jne 0x466b4d
    if (!cpu.flags.zf)
    {
        goto L_0x00466b4d;
    }
    // 00466b3b  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00466b40  e8cbe0fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466b45  a16cba5100             -mov eax, dword ptr [0x51ba6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */);
    // 00466b4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00466b4d:
    // 00466b4d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00466b4f:
    // 00466b4f  8d54010c               -lea edx, [ecx + eax + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1);
    // 00466b53  89540108               -mov dword ptr [ecx + eax + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.edx;
    // 00466b57  a16cba5100             -mov eax, dword ptr [0x51ba6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */);
    // 00466b5c  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00466b5f  81f9f4020000           +cmp ecx, 0x2f4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(756 /*0x2f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466b65  7ce8                   -jl 0x466b4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466b4f;
    }
    // 00466b67  c780fc02000000000000   -mov dword ptr [eax + 0x2fc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(764) /* 0x2fc */) = 0 /*0x0*/;
    // 00466b71  a16cba5100             -mov eax, dword ptr [0x51ba6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */);
L_0x00466b76:
    // 00466b76  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00466b79  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00466b7c  89156cba5100           -mov dword ptr [0x51ba6c], edx
    app->getMemory<x86::reg32>(x86::reg32(5356140) /* 0x51ba6c */) = cpu.edx;
    // 00466b82  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00466b86  83fb01                 +cmp ebx, 1
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
    // 00466b89  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00466b8b  741f                   -je 0x466bac
    if (cpu.flags.zf)
    {
        goto L_0x00466bac;
    }
    // 00466b8d  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466b90  7518                   -jne 0x466baa
    if (!cpu.flags.zf)
    {
        goto L_0x00466baa;
    }
    // 00466b92  668b12                 -mov dx, word ptr [edx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx);
    // 00466b95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466b96  66895004               -mov word ptr [eax + 4], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 00466b9a  8b1564ba5100           -mov edx, dword ptr [0x51ba64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 00466ba0  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00466ba2  a364ba5100             -mov dword ptr [0x51ba64], eax
    app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */) = cpu.eax;
    // 00466ba7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00466baa:
    // 00466baa  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x00466bac:
    // 00466bac  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00466baf  8b1564ba5100           -mov edx, dword ptr [0x51ba64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */);
    // 00466bb5  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00466bb7  a364ba5100             -mov dword ptr [0x51ba64], eax
    app->getMemory<x86::reg32>(x86::reg32(5356132) /* 0x51ba64 */) = cpu.eax;
    // 00466bbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bbd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_466bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466bc0  a114144a00             -mov eax, dword ptr [0x4a1414]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4854804) /* 0x4a1414 */);
    // 00466bc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466bc6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466bc7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466bc8  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00466bca  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00466bcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466bce  7424                   -je 0x466bf4
    if (cpu.flags.zf)
    {
        goto L_0x00466bf4;
    }
    // 00466bd0  b814144a00             -mov eax, 0x4a1414
    cpu.eax = 4854804 /*0x4a1414*/;
    // 00466bd5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00466bd7:
    // 00466bd7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00466bd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466bda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466bdb  e8d0df0100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00466be0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466be3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466be5  7413                   -je 0x466bfa
    if (cpu.flags.zf)
    {
        goto L_0x00466bfa;
    }
    // 00466be7  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00466bea  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466bed  47                     -inc edi
    (cpu.edi)++;
    // 00466bee  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00466bf0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00466bf2  75e3                   -jne 0x466bd7
    if (!cpu.flags.zf)
    {
        goto L_0x00466bd7;
    }
L_0x00466bf4:
    // 00466bf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bf5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bf6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466bf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bf9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466bfa:
    // 00466bfa  8b04fd10144a00         -mov eax, dword ptr [edi*8 + 0x4a1410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4854800) /* 0x4a1410 */ + cpu.edi * 8);
    // 00466c01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466c10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466c11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466c12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466c13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466c14  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00466c16  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00466c18  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00466c1a  66397e06               +cmp word ptr [esi + 6], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00466c1e  7623                   -jbe 0x466c43
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466c43;
    }
    // 00466c20  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00466c22:
    // 00466c22  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00466c25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466c26  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00466c28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466c29  e882df0100             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00466c2e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466c31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466c33  7415                   -je 0x466c4a
    if (cpu.flags.zf)
    {
        goto L_0x00466c4a;
    }
    // 00466c35  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466c37  47                     -inc edi
    (cpu.edi)++;
    // 00466c38  668b4e06               -mov cx, word ptr [esi + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00466c3c  83c328                 -add ebx, 0x28
    (cpu.ebx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00466c3f  3bf9                   +cmp edi, ecx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466c41  7cdf                   -jl 0x466c22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466c22;
    }
L_0x00466c43:
    // 00466c43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c46  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466c48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466c4a:
    // 00466c4a  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00466c4d  8d14bf                 -lea edx, [edi + edi*4]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 4);
    // 00466c50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c51  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c53  8d04d0                 -lea eax, [eax + edx*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.edx * 8);
    // 00466c56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466c57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466c60  66813d80be51000001     +cmp word ptr [0x51be80], 0x100
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5357184) /* 0x51be80 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(256 /*0x100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00466c69  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466c6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466c6b  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00466c6d  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00466c6f  720d                   -jb 0x466c7e
    if (cpu.flags.cf)
    {
        goto L_0x00466c7e;
    }
    // 00466c71  68d8274a00             -push 0x4a27d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4859864 /*0x4a27d8*/;
    cpu.esp -= 4;
    // 00466c76  e895dffbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466c7b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00466c7e:
    // 00466c7e  a180be5100             -mov eax, dword ptr [0x51be80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357184) /* 0x51be80 */);
    // 00466c83  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00466c88  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00466c8a  66ff0580be5100         -inc word ptr [0x51be80]
    (app->getMemory<x86::reg16>(x86::reg32(5357184) /* 0x51be80 */))++;
    // 00466c91  6689b880ba5100         -mov word ptr [eax + 0x51ba80], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5356160) /* 0x51ba80 */) = cpu.di;
    // 00466c98  6689b080bc5100         -mov word ptr [eax + 0x51bc80], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5356672) /* 0x51bc80 */) = cpu.si;
    // 00466c9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ca0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ca1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466cb0  66ff0d80be5100         -dec word ptr [0x51be80]
    (app->getMemory<x86::reg16>(x86::reg32(5357184) /* 0x51be80 */))--;
    // 00466cb7  a180be5100             -mov eax, dword ptr [0x51be80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357184) /* 0x51be80 */);
    // 00466cbc  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00466cc1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466cc3  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00466cc5  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00466cc7  668b8880bc5100         -mov cx, word ptr [eax + 0x51bc80]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5356672) /* 0x51bc80 */);
    // 00466cce  668b9080ba5100         -mov dx, word ptr [eax + 0x51ba80]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5356160) /* 0x51ba80 */);
    // 00466cd5  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00466cda  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00466cdd  890c90                 -mov dword ptr [eax + edx*4], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.ecx;
    // 00466ce0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466cf0  a188be5100             -mov eax, dword ptr [0x51be88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */);
    // 00466cf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466cf7  754a                   -jne 0x466d43
    if (!cpu.flags.zf)
    {
        goto L_0x00466d43;
    }
    // 00466cf9  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00466cfe  e877050100             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00466d03  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466d06  a388be5100             -mov dword ptr [0x51be88], eax
    app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */) = cpu.eax;
    // 00466d0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466d0d  7512                   -jne 0x466d21
    if (!cpu.flags.zf)
    {
        goto L_0x00466d21;
    }
    // 00466d0f  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00466d14  e8f7defbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466d19  a188be5100             -mov eax, dword ptr [0x51be88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */);
    // 00466d1e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00466d21:
    // 00466d21  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00466d23:
    // 00466d23  8d54c808               -lea edx, [eax + ecx*8 + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ecx * 8);
    // 00466d27  8954c804               -mov dword ptr [eax + ecx*8 + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8) = cpu.edx;
    // 00466d2b  a188be5100             -mov eax, dword ptr [0x51be88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */);
    // 00466d30  41                     -inc ecx
    (cpu.ecx)++;
    // 00466d31  83f93f                 +cmp ecx, 0x3f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466d34  7ced                   -jl 0x466d23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466d23;
    }
    // 00466d36  c744c80400000000       -mov dword ptr [eax + ecx*8 + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8) = 0 /*0x0*/;
    // 00466d3e  a188be5100             -mov eax, dword ptr [0x51be88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */);
L_0x00466d43:
    // 00466d43  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00466d46  890d88be5100           -mov dword ptr [0x51be88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */) = cpu.ecx;
    // 00466d4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466d50  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00466d52  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00466d55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466d60  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466d63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466d64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466d65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466d66  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00466d68  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00466d6c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466d6d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00466d6f  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00466d72  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00466d74  0f848a000000           -je 0x466e04
    if (cpu.flags.zf)
    {
        goto L_0x00466e04;
    }
    // 00466d7a  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00466d7d  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00466d80  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00466d82  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00466d84  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00466d86  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00466d8a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00466d8c  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00466d90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466d91  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466d93  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00466d97  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466d99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466d9a  e8000a0100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00466d9f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00466da1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466da2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466da4  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466da6  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00466da9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466daa  e8f0090100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00466daf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466db0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466db2  8d4c2438               -lea ecx, [esp + 0x38]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00466db6  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466db8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466db9  e8e1090100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00466dbe  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00466dc2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466dc3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466dc5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466dc6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466dc7  e8d3090100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00466dcc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00466dcf  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00466dd2  668b4022               -mov ax, word ptr [eax + 0x22]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(34) /* 0x22 */);
    // 00466dd6  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00466dd9  7629                   -jbe 0x466e04
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466e04;
    }
    // 00466ddb  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00466dde  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00466de0  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00466de3  761f                   -jbe 0x466e04
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466e04;
    }
L_0x00466de5:
    // 00466de5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466de6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466de8  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466dea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466deb  e8af090100             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00466df0  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00466df3  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00466df6  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00466df8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466dfb  668b5122               -mov dx, word ptr [ecx + 0x22]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(34) /* 0x22 */);
    // 00466dff  45                     -inc ebp
    (cpu.ebp)++;
    // 00466e00  3bea                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466e02  7ce1                   -jl 0x466de5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466de5;
    }
L_0x00466e04:
    // 00466e04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466e05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466e06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466e07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466e08  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00466e0b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_466e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466e10  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00466e13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466e14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466e15  8b2d84be5100           -mov ebp, dword ptr [0x51be84]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 00466e1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466e1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466e1d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00466e1f  3bef                   +cmp ebp, edi
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
    // 00466e21  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00466e23  754e                   -jne 0x466e73
    if (!cpu.flags.zf)
    {
        goto L_0x00466e73;
    }
    // 00466e25  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 00466e2a  e84b040100             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00466e2f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466e32  3bc7                   +cmp eax, edi
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
    // 00466e34  a384be5100             -mov dword ptr [0x51be84], eax
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.eax;
    // 00466e39  7512                   -jne 0x466e4d
    if (!cpu.flags.zf)
    {
        goto L_0x00466e4d;
    }
    // 00466e3b  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00466e40  e8cbddfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466e45  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 00466e4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00466e4d:
    // 00466e4d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00466e4f:
    // 00466e4f  8d540110               -lea edx, [ecx + eax + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 00466e53  8954010c               -mov dword ptr [ecx + eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.edx;
    // 00466e57  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 00466e5c  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466e5f  81f9f0030000           +cmp ecx, 0x3f0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1008 /*0x3f0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466e65  7ce8                   -jl 0x466e4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466e4f;
    }
    // 00466e67  89b8fc030000           -mov dword ptr [eax + 0x3fc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1020) /* 0x3fc */) = cpu.edi;
    // 00466e6d  8b2d84be5100           -mov ebp, dword ptr [0x51be84]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
L_0x00466e73:
    // 00466e73  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00466e76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466e77  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466e79  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00466e7d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466e7f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466e80  890d84be5100           -mov dword ptr [0x51be84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.ecx;
    // 00466e86  e8fd070100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00466e8b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466e8c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466e8e  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00466e92  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466e94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466e95  e8ee070100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00466e9a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466e9b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466e9d  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00466ea1  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466ea3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466ea4  e8df070100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00466ea9  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00466ead  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466eae  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466eb0  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00466eb4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466eb5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466eb6  e8cd070100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00466ebb  8b4c2450               -mov ecx, dword ptr [esp + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00466ebf  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00466ec5  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00466ec8  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00466ecb  8b8018030000           -mov eax, dword ptr [eax + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 00466ed1  3bc7                   +cmp eax, edi
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
    // 00466ed3  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00466ed6  752c                   -jne 0x466f04
    if (!cpu.flags.zf)
    {
        goto L_0x00466f04;
    }
    // 00466ed8  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00466edc  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00466ee2  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00466ee5  8b8ab4020000           -mov ecx, dword ptr [edx + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(692) /* 0x2b4 */);
    // 00466eeb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466eec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466eed  6880284a00             -push 0x4a2880
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860032 /*0x4a2880*/;
    cpu.esp -= 4;
    // 00466ef2  e8c0fe0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00466ef7  6848284a00             -push 0x4a2848
    app->getMemory<x86::reg32>(cpu.esp-4) = 4859976 /*0x4a2848*/;
    cpu.esp -= 4;
    // 00466efc  e80fddfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466f01  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00466f04:
    // 00466f04  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00466f07  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00466f0b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00466f0d  e8fefcffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00466f12  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00466f14  3bf7                   +cmp esi, edi
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
    // 00466f16  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00466f1a  751c                   -jne 0x466f38
    if (!cpu.flags.zf)
    {
        goto L_0x00466f38;
    }
    // 00466f1c  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00466f20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466f21  6818284a00             -push 0x4a2818
    app->getMemory<x86::reg32>(cpu.esp-4) = 4859928 /*0x4a2818*/;
    cpu.esp -= 4;
    // 00466f26  e88cfe0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00466f2b  68f0274a00             -push 0x4a27f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4859888 /*0x4a27f0*/;
    cpu.esp -= 4;
    // 00466f30  e8dbdcfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00466f35  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00466f38:
    // 00466f38  897504                 -mov dword ptr [ebp + 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00466f3b  66397e22               +cmp word ptr [esi + 0x22], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00466f3f  764e                   -jbe 0x466f8f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466f8f;
    }
    // 00466f41  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00466f44  66397e22               +cmp word ptr [esi + 0x22], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00466f48  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 00466f4c  7641                   -jbe 0x466f8f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466f8f;
    }
L_0x00466f4e:
    // 00466f4e  e89dfdffff             -call 0x466cf0
    cpu.esp -= 4;
    sub_466cf0(app, cpu);
    // 00466f53  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00466f55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466f56  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00466f58  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00466f5a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466f5b  e828070100             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00466f60  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466f63  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00466f6a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00466f6c  7505                   -jne 0x466f73
    if (!cpu.flags.zf)
    {
        goto L_0x00466f73;
    }
    // 00466f6e  897508                 -mov dword ptr [ebp + 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00466f71  eb03                   -jmp 0x466f76
    goto L_0x00466f76;
L_0x00466f73:
    // 00466f73  897704                 -mov dword ptr [edi + 4], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00466f76:
    // 00466f76  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00466f7a  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00466f7e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466f80  40                     -inc eax
    (cpu.eax)++;
    // 00466f81  668b4a22               -mov cx, word ptr [edx + 0x22]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(34) /* 0x22 */);
    // 00466f85  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00466f87  3bc1                   +cmp eax, ecx
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
    // 00466f89  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00466f8d  7cbf                   -jl 0x466f4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466f4e;
    }
L_0x00466f8f:
    // 00466f8f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00466f93  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00466f99  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00466f9b  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00466f9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466f9e  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00466fa0  e8bb9bfeff             -call 0x450b60
    cpu.esp -= 4;
    sub_450b60(app, cpu);
    // 00466fa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466fa6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466fa7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466fa8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466fa9  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00466fac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_466fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466fb0  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00466fb3  6683782200             +cmp word ptr [eax + 0x22], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00466fb8  7623                   -jbe 0x466fdd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00466fdd;
    }
    // 00466fba  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00466fbd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466fbf  742c                   -je 0x466fed
    if (cpu.flags.zf)
    {
        goto L_0x00466fed;
    }
    // 00466fc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466fc2  8b3588be5100           -mov esi, dword ptr [0x51be88]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */);
L_0x00466fc8:
    // 00466fc8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00466fcb  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00466fce  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00466fd0  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00466fd2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00466fd4  893588be5100           -mov dword ptr [0x51be88], esi
    app->getMemory<x86::reg32>(x86::reg32(5357192) /* 0x51be88 */) = cpu.esi;
    // 00466fda  75ec                   -jne 0x466fc8
    if (!cpu.flags.zf)
    {
        goto L_0x00466fc8;
    }
    // 00466fdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00466fdd:
    // 00466fdd  8b1584be5100           -mov edx, dword ptr [0x51be84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 00466fe3  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00466fe6  890d84be5100           -mov dword ptr [0x51be84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.ecx;
    // 00466fec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466fed:
    // 00466fed  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 00466ff2  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00466ff5  890d84be5100           -mov dword ptr [0x51be84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.ecx;
    // 00466ffb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_467000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467000  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467001  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00467003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467004  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00467006  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467008  7404                   -je 0x46700e
    if (cpu.flags.zf)
    {
        goto L_0x0046700e;
    }
    // 0046700a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046700c  750d                   -jne 0x46701b
    if (!cpu.flags.zf)
    {
        goto L_0x0046701b;
    }
L_0x0046700e:
    // 0046700e  68c8284a00             -push 0x4a28c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860104 /*0x4a28c8*/;
    cpu.esp -= 4;
    // 00467013  e8f8dbfbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467018  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046701b:
    // 0046701b  8b8618030000           -mov eax, dword ptr [esi + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(792) /* 0x318 */);
    // 00467021  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467023  7413                   -je 0x467038
    if (cpu.flags.zf)
    {
        goto L_0x00467038;
    }
    // 00467025  3907                   +cmp dword ptr [edi], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467027  750f                   -jne 0x467038
    if (!cpu.flags.zf)
    {
        goto L_0x00467038;
    }
    // 00467029  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046702b  e880ffffff             -call 0x466fb0
    cpu.esp -= 4;
    sub_466fb0(app, cpu);
    // 00467030  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00467035  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467036  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467037  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467038:
    // 00467038  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467039  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046703b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046703c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_467040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467041  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467042  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00467045  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467046  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00467048  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046704c  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046704f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467051  750a                   -jne 0x46705d
    if (!cpu.flags.zf)
    {
        goto L_0x0046705d;
    }
    // 00467053  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467054  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467055  83c404                 +add esp, 4
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
    // 00467058  e953ffffff             -jmp 0x466fb0
    return sub_466fb0(app, cpu);
L_0x0046705d:
    // 0046705d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046705e  668b5e22               -mov bx, word ptr [esi + 0x22]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00467062  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00467065  763a                   -jbe 0x4670a1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004670a1;
    }
    // 00467067  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046706a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046706c  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 0046706f  7630                   -jbe 0x4670a1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004670a1;
    }
    // 00467071  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00467072:
    // 00467072  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00467075  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00467077  668b2c43               -mov bp, word ptr [ebx + eax*2]
    cpu.bp = app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2);
    // 0046707b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046707d  668b5f04               -mov bx, word ptr [edi + 4]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467081  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00467083  03eb                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00467085  8b1dacc05100           -mov ebx, dword ptr [0x51c0ac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046708b  40                     -inc eax
    (cpu.eax)++;
    // 0046708c  893cab                 -mov dword ptr [ebx + ebp*4], edi
    app->getMemory<x86::reg32>(cpu.ebx + cpu.ebp * 4) = cpu.edi;
    // 0046708f  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00467092  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00467094  668b7e22               -mov di, word ptr [esi + 0x22]
    cpu.di = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00467098  3bc7                   +cmp eax, edi
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
    // 0046709a  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046709e  7cd2                   -jl 0x467072
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00467072;
    }
    // 004670a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004670a1:
    // 004670a1  e80affffff             -call 0x466fb0
    cpu.esp -= 4;
    sub_466fb0(app, cpu);
    // 004670a6  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004670a8  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004670aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670ad  83c404                 +add esp, 4
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
    // 004670b0  e96bf6ffff             -jmp 0x466720
    return sub_466720(app, cpu);
}

/* align: skip  */
void Application::sub_4670c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004670c0  81ec90000000           -sub esp, 0x90
    (cpu.esp) -= x86::reg32(x86::sreg32(144 /*0x90*/));
    // 004670c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004670c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004670c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004670c9  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004670cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004670cc  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004670d0  c7442410000080bf       -mov dword ptr [esp + 0x10], 0xbf800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 3212836864 /*0xbf800000*/;
    // 004670d8  e803f4ffff             -call 0x4664e0
    cpu.esp -= 4;
    sub_4664e0(app, cpu);
    // 004670dd  83f801                 +cmp eax, 1
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
    // 004670e0  750b                   -jne 0x4670ed
    if (!cpu.flags.zf)
    {
        goto L_0x004670ed;
    }
    // 004670e2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004670e4  e877f4ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004670e9  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004670ed:
    // 004670ed  e80ef6ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 004670f2  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004670f4  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004670f6  e865f4ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004670fb  e890fc0000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00467100  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00467102  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00467106  e8f5f5ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046710b  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x0046710f:
    // 0046710f  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00467111  40                     -inc eax
    (cpu.eax)++;
    // 00467112  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00467114  42                     -inc edx
    (cpu.edx)++;
    // 00467115  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00467117  75f6                   -jne 0x46710f
    if (!cpu.flags.zf)
    {
        goto L_0x0046710f;
    }
    // 00467119  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046711d  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00467120  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00467122  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00467124  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00467126  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467127  7453                   -je 0x46717c
    if (cpu.flags.zf)
    {
        goto L_0x0046717c;
    }
    // 00467129  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046712d  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00467131  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00467133  7413                   -je 0x467148
    if (cpu.flags.zf)
    {
        goto L_0x00467148;
    }
L_0x00467135:
    // 00467135  3c2e                   +cmp al, 0x2e
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
    // 00467137  740a                   -je 0x467143
    if (cpu.flags.zf)
    {
        goto L_0x00467143;
    }
    // 00467139  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046713c  41                     -inc ecx
    (cpu.ecx)++;
    // 0046713d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046713f  75f4                   -jne 0x467135
    if (!cpu.flags.zf)
    {
        goto L_0x00467135;
    }
    // 00467141  eb05                   -jmp 0x467148
    goto L_0x00467148;
L_0x00467143:
    // 00467143  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467146  751c                   -jne 0x467164
    if (!cpu.flags.zf)
    {
        goto L_0x00467164;
    }
L_0x00467148:
    // 00467148  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046714c  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046714f  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00467151  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00467153  a12c2a4a00             -mov eax, dword ptr [0x4a2a2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4860460) /* 0x4a2a2c */);
    // 00467158  8a0d302a4a00           -mov cl, byte ptr [0x4a2a30]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4860464) /* 0x4a2a30 */);
    // 0046715e  4f                     -dec edi
    (cpu.edi)--;
    // 0046715f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00467161  884f04                 -mov byte ptr [edi + 4], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.cl;
L_0x00467164:
    // 00467164  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00467168  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046716a  e8e10d0000             -call 0x467f50
    cpu.esp -= 4;
    sub_467f50(app, cpu);
    // 0046716f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00467171  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00467173  7453                   -je 0x4671c8
    if (cpu.flags.zf)
    {
        goto L_0x004671c8;
    }
    // 00467175  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00467178  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046717a  744c                   -je 0x4671c8
    if (cpu.flags.zf)
    {
        goto L_0x004671c8;
    }
L_0x0046717c:
    // 0046717c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046717e  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00467180  e88bfaffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00467185  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467187  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00467189  751e                   -jne 0x4671a9
    if (!cpu.flags.zf)
    {
        goto L_0x004671a9;
    }
    // 0046718b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046718f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467190  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00467194  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467195  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00467197  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467198  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467199  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046719b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046719c  68d0294a00             -push 0x4a29d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860368 /*0x4a29d0*/;
    cpu.esp -= 4;
    // 004671a1  e86adafbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004671a6  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x004671a9:
    // 004671a9  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004671ad  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004671b3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004671b5  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004671b8  0f8a09010000           -jp 0x4672c7
    if (cpu.flags.pf)
    {
        goto L_0x004672c7;
    }
    // 004671be  807b0602               +cmp byte ptr [ebx + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004671c2  0f8585000000           -jne 0x46724d
    if (!cpu.flags.zf)
    {
        goto L_0x0046724d;
    }
L_0x004671c8:
    // 004671c8  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004671cc  e8cf0d0000             -call 0x467fa0
    cpu.esp -= 4;
    sub_467fa0(app, cpu);
    // 004671d1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004671d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004671d5  7513                   -jne 0x4671ea
    if (!cpu.flags.zf)
    {
        goto L_0x004671ea;
    }
    // 004671d7  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004671db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004671dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004671dd  6888294a00             -push 0x4a2988
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860296 /*0x4a2988*/;
    cpu.esp -= 4;
    // 004671e2  e829dafbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004671e7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004671ea:
    // 004671ea  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004671ec  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004671ee  e81dfaffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 004671f3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004671f5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004671f7  7522                   -jne 0x46721b
    if (!cpu.flags.zf)
    {
        goto L_0x0046721b;
    }
    // 004671f9  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004671fd  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00467201  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467202  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00467206  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467207  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467208  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046720a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046720b  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046720d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046720e  6820294a00             -push 0x4a2920
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860192 /*0x4a2920*/;
    cpu.esp -= 4;
    // 00467213  e8f8d9fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467218  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x0046721b:
    // 0046721b  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046721d  668b4622               -mov ax, word ptr [esi + 0x22]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00467221  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467222  7811                   -js 0x467235
    if (cpu.flags.sf)
    {
        goto L_0x00467235;
    }
    // 00467224  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00467227:
    // 00467227  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046722b  e830f3ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467230  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467231  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467233  75f2                   -jne 0x467227
    if (!cpu.flags.zf)
    {
        goto L_0x00467227;
    }
L_0x00467235:
    // 00467235  68f4284a00             -push 0x4a28f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860148 /*0x4a28f4*/;
    cpu.esp -= 4;
    // 0046723a  e878fb0000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046723f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467242  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467243  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467244  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467245  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467246  81c490000000           -add esp, 0x90
    (cpu.esp) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 0046724c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046724d:
    // 0046724d  33ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0046724f  c644241000             -mov byte ptr [esp + 0x10], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00467254  668b6f22               -mov bp, word ptr [edi + 0x22]
    cpu.bp = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
    // 00467258  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467259  783a                   -js 0x467295
    if (cpu.flags.sf)
    {
        goto L_0x00467295;
    }
L_0x0046725b:
    // 0046725b  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0046725e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00467260  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467262  668b3468               -mov si, word ptr [eax + ebp*2]
    cpu.si = app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 2);
    // 00467266  668b4b04               -mov cx, word ptr [ebx + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046726a  03f1                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046726c  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00467270  e8ebf2ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467275  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046727b  d91cb2                 -fstp dword ptr [edx + esi*4]
    app->getMemory<float>(cpu.edx + cpu.esi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046727e  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00467282  83f9ff                 +cmp ecx, -1
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
    // 00467285  740b                   -je 0x467292
    if (cpu.flags.zf)
    {
        goto L_0x00467292;
    }
    // 00467287  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00467289  e8d2f9ffff             -call 0x466c60
    cpu.esp -= 4;
    sub_466c60(app, cpu);
    // 0046728e  fe442410               +inc byte ptr [esp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
L_0x00467292:
    // 00467292  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467293  79c6                   -jns 0x46725b
    if (!cpu.flags.sf)
    {
        goto L_0x0046725b;
    }
L_0x00467295:
    // 00467295  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00467297  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00467299  e882f4ffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 0046729e  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004672a2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004672a4  0f86de000000           -jbe 0x467388
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00467388;
    }
    // 004672aa  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004672ae  81e6ff000000           +and esi, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/))));
L_0x004672b4:
    // 004672b4  e8f7f9ffff             -call 0x466cb0
    cpu.esp -= 4;
    sub_466cb0(app, cpu);
    // 004672b9  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004672ba  75f8                   -jne 0x4672b4
    if (!cpu.flags.zf)
    {
        goto L_0x004672b4;
    }
    // 004672bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672c0  81c490000000           -add esp, 0x90
    (cpu.esp) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 004672c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004672c7:
    // 004672c7  8b3584be5100           -mov esi, dword ptr [0x51be84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 004672cd  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004672cf  3bf5                   +cmp esi, ebp
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
    // 004672d1  754e                   -jne 0x467321
    if (!cpu.flags.zf)
    {
        goto L_0x00467321;
    }
    // 004672d3  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 004672d8  e89dff0000             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 004672dd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004672e0  3bc5                   +cmp eax, ebp
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
    // 004672e2  a384be5100             -mov dword ptr [0x51be84], eax
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.eax;
    // 004672e7  7512                   -jne 0x4672fb
    if (!cpu.flags.zf)
    {
        goto L_0x004672fb;
    }
    // 004672e9  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 004672ee  e81dd9fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004672f3  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 004672f8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004672fb:
    // 004672fb  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004672fd:
    // 004672fd  8d540110               -lea edx, [ecx + eax + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 00467301  8954010c               -mov dword ptr [ecx + eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.edx;
    // 00467305  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 0046730a  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046730d  81f9f0030000           +cmp ecx, 0x3f0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1008 /*0x3f0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467313  7ce8                   -jl 0x4672fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004672fd;
    }
    // 00467315  89a8fc030000           -mov dword ptr [eax + 0x3fc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1020) /* 0x3fc */) = cpu.ebp;
    // 0046731b  8b3584be5100           -mov esi, dword ptr [0x51be84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
L_0x00467321:
    // 00467321  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00467324  890d84be5100           -mov dword ptr [0x51be84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.ecx;
    // 0046732a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0046732c  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0046732f  66396f22               +cmp word ptr [edi + 0x22], bp
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bp));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00467333  762b                   -jbe 0x467360
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00467360;
    }
    // 00467335  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00467337  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0046733a  668b4722               -mov ax, word ptr [edi + 0x22]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
    // 0046733e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046733f  781f                   -js 0x467360
    if (cpu.flags.sf)
    {
        goto L_0x00467360;
    }
    // 00467341  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00467344:
    // 00467344  e8a7f9ffff             -call 0x466cf0
    cpu.esp -= 4;
    sub_466cf0(app, cpu);
    // 00467349  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046734b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046734d  e80ef2ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467352  d91f                   +fstp dword ptr [edi]
    app->getMemory<float>(cpu.edi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467354  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00467357  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467358  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046735b  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046735e  75e4                   -jne 0x467344
    if (!cpu.flags.zf)
    {
        goto L_0x00467344;
    }
L_0x00467360:
    // 00467360  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00467364  dc0dc87a4800           -fmul qword ptr [0x487ac8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4750024) /* 0x487ac8 */));
    // 0046736a  e821fa0000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0046736f  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00467375  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00467377  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00467379  3bca                   +cmp ecx, edx
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
    // 0046737b  7501                   -jne 0x46737e
    if (!cpu.flags.zf)
    {
        goto L_0x0046737e;
    }
    // 0046737d  41                     -inc ecx
    (cpu.ecx)++;
L_0x0046737e:
    // 0046737e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046737f  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00467381  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467383  e8d897feff             -call 0x450b60
    cpu.esp -= 4;
    sub_450b60(app, cpu);
L_0x00467388:
    // 00467388  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467389  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046738a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046738b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046738c  81c490000000           -add esp, 0x90
    (cpu.esp) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 00467392  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4673a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004673a0  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004673a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004673a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004673a5  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004673a7  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004673a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004673aa  83fe0a                 +cmp esi, 0xa
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
    // 004673ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004673ae  7d2e                   -jge 0x4673de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004673de;
    }
    // 004673b0  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004673b4  683c2a4a00             -push 0x4a2a3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860476 /*0x4a2a3c*/;
    cpu.esp -= 4;
    // 004673b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004673ba  e839fa0000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004673bf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004673c2  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004673c6  e8c5b5fcff             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 004673cb  83f8ff                 +cmp eax, -1
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
    // 004673ce  7536                   -jne 0x467406
    if (!cpu.flags.zf)
    {
        goto L_0x00467406;
    }
    // 004673d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004673d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004673d2  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004673d6  68342a4a00             -push 0x4a2a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860468 /*0x4a2a34*/;
    cpu.esp -= 4;
    // 004673db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004673dc  eb0a                   -jmp 0x4673e8
    goto L_0x004673e8;
L_0x004673de:
    // 004673de  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004673e2  68342a4a00             -push 0x4a2a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860468 /*0x4a2a34*/;
    cpu.esp -= 4;
    // 004673e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004673e8:
    // 004673e8  e80bfa0000             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004673ed  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004673f1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004673f4  e897b5fcff             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 004673f9  83f8ff                 +cmp eax, -1
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
    // 004673fc  7508                   -jne 0x467406
    if (!cpu.flags.zf)
    {
        goto L_0x00467406;
    }
    // 004673fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004673ff  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467401  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467402  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00467405  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467406:
    // 00467406  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0046740c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046740d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046740e  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00467411  8b8218030000           -mov eax, dword ptr [edx + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(792) /* 0x318 */);
    // 00467417  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046741a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_467420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467420  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00467423  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00467427  c7442400000080bf       -mov dword ptr [esp], 0xbf800000
    app->getMemory<x86::reg32>(cpu.esp) = 3212836864 /*0xbf800000*/;
    // 0046742f  e8acf0ffff             -call 0x4664e0
    cpu.esp -= 4;
    sub_4664e0(app, cpu);
    // 00467434  83f801                 +cmp eax, 1
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
    // 00467437  750b                   -jne 0x467444
    if (!cpu.flags.zf)
    {
        goto L_0x00467444;
    }
    // 00467439  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046743b  e820f1ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467440  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00467444:
    // 00467444  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467445  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467446  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467447  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467448  e8b3f2ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 0046744d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046744f  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00467451  e80af1ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467456  e835f90000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0046745b  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046745d  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00467461  e89af2ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 00467466  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00467468  83c9ff                 -or ecx, 0xffffffff
    cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0046746b  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046746d  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046746f  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00467471  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00467473  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467474  7411                   -je 0x467487
    if (cpu.flags.zf)
    {
        goto L_0x00467487;
    }
    // 00467476  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00467478  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046747a  e821ffffff             -call 0x4673a0
    cpu.esp -= 4;
    sub_4673a0(app, cpu);
    // 0046747f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00467481  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00467483  744d                   -je 0x4674d2
    if (cpu.flags.zf)
    {
        goto L_0x004674d2;
    }
    // 00467485  eb04                   -jmp 0x46748b
    goto L_0x0046748b;
L_0x00467487:
    // 00467487  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x0046748b:
    // 0046748b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046748d  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046748f  e87cf7ffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00467494  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467496  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00467498  751d                   -jne 0x4674b7
    if (!cpu.flags.zf)
    {
        goto L_0x004674b7;
    }
    // 0046749a  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046749e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004674a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004674a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004674a4  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004674a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004674a7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004674a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004674aa  68902a4a00             -push 0x4a2a90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860560 /*0x4a2a90*/;
    cpu.esp -= 4;
    // 004674af  e85cd7fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004674b4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x004674b7:
    // 004674b7  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004674bb  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004674c1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004674c3  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004674c6  0f8ae2000000           -jp 0x4675ae
    if (cpu.flags.pf)
    {
        goto L_0x004675ae;
    }
    // 004674cc  807b0602               +cmp byte ptr [ebx + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004674d0  7566                   -jne 0x467538
    if (!cpu.flags.zf)
    {
        goto L_0x00467538;
    }
L_0x004674d2:
    // 004674d2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004674d4  e8c70a0000             -call 0x467fa0
    cpu.esp -= 4;
    sub_467fa0(app, cpu);
    // 004674d9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004674db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004674dd  750e                   -jne 0x4674ed
    if (!cpu.flags.zf)
    {
        goto L_0x004674ed;
    }
    // 004674df  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004674e0  68582a4a00             -push 0x4a2a58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860504 /*0x4a2a58*/;
    cpu.esp -= 4;
    // 004674e5  e826d7fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004674ea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004674ed:
    // 004674ed  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004674ef  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004674f1  e81af7ffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 004674f6  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004674f8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004674fa  750d                   -jne 0x467509
    if (!cpu.flags.zf)
    {
        goto L_0x00467509;
    }
    // 004674fc  68442a4a00             -push 0x4a2a44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860484 /*0x4a2a44*/;
    cpu.esp -= 4;
    // 00467501  e80ad7fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467506  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00467509:
    // 00467509  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046750b  668b4622               -mov ax, word ptr [esi + 0x22]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 0046750f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467510  7811                   -js 0x467523
    if (cpu.flags.sf)
    {
        goto L_0x00467523;
    }
    // 00467512  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00467515:
    // 00467515  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467519  e842f0ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 0046751e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046751f  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467521  75f2                   -jne 0x467515
    if (!cpu.flags.zf)
    {
        goto L_0x00467515;
    }
L_0x00467523:
    // 00467523  68f4284a00             -push 0x4a28f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860148 /*0x4a28f4*/;
    cpu.esp -= 4;
    // 00467528  e88af80000             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0046752d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467530  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467531  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467532  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467533  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467534  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00467537  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467538:
    // 00467538  33ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0046753a  c644241000             -mov byte ptr [esp + 0x10], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0046753f  668b6f22               -mov bp, word ptr [edi + 0x22]
    cpu.bp = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
    // 00467543  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467544  7839                   -js 0x46757f
    if (cpu.flags.sf)
    {
        goto L_0x0046757f;
    }
L_0x00467546:
    // 00467546  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00467549  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046754b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046754d  668b3469               -mov si, word ptr [ecx + ebp*2]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + cpu.ebp * 2);
    // 00467551  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00467555  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467559  03f2                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046755b  e800f0ffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467560  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467565  d91cb0                 -fstp dword ptr [eax + esi*4]
    app->getMemory<float>(cpu.eax + cpu.esi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467568  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046756c  83f9ff                 +cmp ecx, -1
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
    // 0046756f  740b                   -je 0x46757c
    if (cpu.flags.zf)
    {
        goto L_0x0046757c;
    }
    // 00467571  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00467573  e8e8f6ffff             -call 0x466c60
    cpu.esp -= 4;
    sub_466c60(app, cpu);
    // 00467578  fe442410               +inc byte ptr [esp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
L_0x0046757c:
    // 0046757c  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046757d  79c7                   -jns 0x467546
    if (!cpu.flags.sf)
    {
        goto L_0x00467546;
    }
L_0x0046757f:
    // 0046757f  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00467581  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00467583  e898f1ffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 00467588  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046758c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046758e  0f86e2000000           -jbe 0x467676
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00467676;
    }
    // 00467594  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00467598  81e6ff000000           +and esi, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/))));
L_0x0046759e:
    // 0046759e  e80df7ffff             -call 0x466cb0
    cpu.esp -= 4;
    sub_466cb0(app, cpu);
    // 004675a3  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004675a4  75f8                   -jne 0x46759e
    if (!cpu.flags.zf)
    {
        goto L_0x0046759e;
    }
    // 004675a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004675a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004675a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004675a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004675aa  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004675ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004675ae:
    // 004675ae  8b3584be5100           -mov esi, dword ptr [0x51be84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 004675b4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004675b6  7552                   -jne 0x46760a
    if (!cpu.flags.zf)
    {
        goto L_0x0046760a;
    }
    // 004675b8  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 004675bd  e8b8fc0000             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 004675c2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004675c5  a384be5100             -mov dword ptr [0x51be84], eax
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.eax;
    // 004675ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004675cc  7512                   -jne 0x4675e0
    if (!cpu.flags.zf)
    {
        goto L_0x004675e0;
    }
    // 004675ce  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 004675d3  e838d6fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004675d8  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 004675dd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004675e0:
    // 004675e0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004675e2:
    // 004675e2  8d540110               -lea edx, [ecx + eax + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 004675e6  8954010c               -mov dword ptr [ecx + eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.edx;
    // 004675ea  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 004675ef  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004675f2  81f9f0030000           +cmp ecx, 0x3f0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1008 /*0x3f0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004675f8  7ce8                   -jl 0x4675e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004675e2;
    }
    // 004675fa  c780fc03000000000000   -mov dword ptr [eax + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00467604  8b3584be5100           -mov esi, dword ptr [0x51be84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
L_0x0046760a:
    // 0046760a  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046760d  890d84be5100           -mov dword ptr [0x51be84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.ecx;
    // 00467613  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00467615  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00467618  66837f2200             +cmp word ptr [edi + 0x22], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046761d  762f                   -jbe 0x46764e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046764e;
    }
    // 0046761f  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00467621  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00467628  668b4722               -mov ax, word ptr [edi + 0x22]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
    // 0046762c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046762d  781f                   -js 0x46764e
    if (cpu.flags.sf)
    {
        goto L_0x0046764e;
    }
    // 0046762f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00467632:
    // 00467632  e8b9f6ffff             -call 0x466cf0
    cpu.esp -= 4;
    sub_466cf0(app, cpu);
    // 00467637  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00467639  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046763b  e820efffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467640  d91f                   +fstp dword ptr [edi]
    app->getMemory<float>(cpu.edi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467642  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00467645  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467646  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00467649  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046764c  75e4                   -jne 0x467632
    if (!cpu.flags.zf)
    {
        goto L_0x00467632;
    }
L_0x0046764e:
    // 0046764e  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00467652  dc0dc87a4800           -fmul qword ptr [0x487ac8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4750024) /* 0x487ac8 */));
    // 00467658  e833f70000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0046765d  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00467663  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00467665  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00467667  3bca                   +cmp ecx, edx
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
    // 00467669  7501                   -jne 0x46766c
    if (!cpu.flags.zf)
    {
        goto L_0x0046766c;
    }
    // 0046766b  41                     -inc ecx
    (cpu.ecx)++;
L_0x0046766c:
    // 0046766c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046766d  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0046766f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467671  e8ea94feff             -call 0x450b60
    cpu.esp -= 4;
    sub_450b60(app, cpu);
L_0x00467676:
    // 00467676  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467677  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467678  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467679  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046767a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046767d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_467680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467680  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00467683  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467684  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467685  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467686  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467687  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00467689  c7442410000080bf       -mov dword ptr [esp + 0x10], 0xbf800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 3212836864 /*0xbf800000*/;
    // 00467691  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00467695  e846eeffff             -call 0x4664e0
    cpu.esp -= 4;
    sub_4664e0(app, cpu);
    // 0046769a  83f801                 +cmp eax, 1
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
    // 0046769d  750b                   -jne 0x4676aa
    if (!cpu.flags.zf)
    {
        goto L_0x004676aa;
    }
    // 0046769f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004676a1  e8baeeffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004676a6  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004676aa:
    // 004676aa  e851f0ffff             -call 0x466700
    cpu.esp -= 4;
    sub_466700(app, cpu);
    // 004676af  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004676b1  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004676b3  e8a8eeffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004676b8  e8d3f60000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004676bd  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004676bf  83feff                 +cmp esi, -1
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
    // 004676c2  7505                   -jne 0x4676c9
    if (!cpu.flags.zf)
    {
        goto L_0x004676c9;
    }
    // 004676c4  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004676c7  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
L_0x004676c9:
    // 004676c9  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004676cf  8b04b1                 -mov eax, dword ptr [ecx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 004676d2  8b8818030000           -mov ecx, dword ptr [eax + 0x318]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 004676d8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004676da  751a                   -jne 0x4676f6
    if (!cpu.flags.zf)
    {
        goto L_0x004676f6;
    }
    // 004676dc  8b88b4020000           -mov ecx, dword ptr [eax + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(692) /* 0x2b4 */);
    // 004676e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004676e3  e82881ffff             -call 0x45f810
    cpu.esp -= 4;
    sub_45f810(app, cpu);
    // 004676e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004676e9  682c2b4a00             -push 0x4a2b2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860716 /*0x4a2b2c*/;
    cpu.esp -= 4;
    // 004676ee  e81dd5fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004676f3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004676f6:
    // 004676f6  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004676fc  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004676fe  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00467701  8b9818030000           -mov ebx, dword ptr [eax + 0x318]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 00467707  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00467709  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0046770b  e800f5ffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00467710  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467712  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00467714  7518                   -jne 0x46772e
    if (!cpu.flags.zf)
    {
        goto L_0x0046772e;
    }
    // 00467716  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046771a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046771b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046771c  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046771e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00467720  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467721  68e02a4a00             -push 0x4a2ae0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860640 /*0x4a2ae0*/;
    cpu.esp -= 4;
    // 00467726  e8e5d4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046772b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0046772e:
    // 0046772e  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00467732  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00467738  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046773a  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0046773d  0f8ad9000000           -jp 0x46781c
    if (cpu.flags.pf)
    {
        goto L_0x0046781c;
    }
    // 00467743  807b0602               +cmp byte ptr [ebx + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467747  755d                   -jne 0x4677a6
    if (!cpu.flags.zf)
    {
        goto L_0x004677a6;
    }
    // 00467749  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046774b  e850080000             -call 0x467fa0
    cpu.esp -= 4;
    sub_467fa0(app, cpu);
    // 00467750  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467752  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00467754  750e                   -jne 0x467764
    if (!cpu.flags.zf)
    {
        goto L_0x00467764;
    }
    // 00467756  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467757  68582a4a00             -push 0x4a2a58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860504 /*0x4a2a58*/;
    cpu.esp -= 4;
    // 0046775c  e8afd4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467761  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00467764:
    // 00467764  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00467766  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00467768  e8a3f4ffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 0046776d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046776f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467771  750d                   -jne 0x467780
    if (!cpu.flags.zf)
    {
        goto L_0x00467780;
    }
    // 00467773  68442a4a00             -push 0x4a2a44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860484 /*0x4a2a44*/;
    cpu.esp -= 4;
    // 00467778  e893d4fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0046777d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00467780:
    // 00467780  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00467782  668b4622               -mov ax, word ptr [esi + 0x22]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00467786  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467787  0f8857010000           -js 0x4678e4
    if (cpu.flags.sf)
    {
        goto L_0x004678e4;
    }
    // 0046778d  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00467790:
    // 00467790  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00467794  e8c7edffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 00467799  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046779a  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046779c  75f2                   -jne 0x467790
    if (!cpu.flags.zf)
    {
        goto L_0x00467790;
    }
    // 0046779e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046779f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004677a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004677a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004677a2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004677a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004677a6:
    // 004677a6  33ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004677a8  c644241000             -mov byte ptr [esp + 0x10], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004677ad  668b6f22               -mov bp, word ptr [edi + 0x22]
    cpu.bp = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
    // 004677b1  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004677b2  7839                   -js 0x4677ed
    if (cpu.flags.sf)
    {
        goto L_0x004677ed;
    }
L_0x004677b4:
    // 004677b4  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004677b7  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004677b9  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004677bb  668b3469               -mov si, word ptr [ecx + ebp*2]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + cpu.ebp * 2);
    // 004677bf  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004677c3  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004677c7  03f2                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004677c9  e892edffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004677ce  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004677d3  d91cb0                 -fstp dword ptr [eax + esi*4]
    app->getMemory<float>(cpu.eax + cpu.esi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004677d6  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004677da  83f9ff                 +cmp ecx, -1
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
    // 004677dd  740b                   -je 0x4677ea
    if (cpu.flags.zf)
    {
        goto L_0x004677ea;
    }
    // 004677df  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004677e1  e87af4ffff             -call 0x466c60
    cpu.esp -= 4;
    sub_466c60(app, cpu);
    // 004677e6  fe442410               +inc byte ptr [esp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
L_0x004677ea:
    // 004677ea  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004677eb  79c7                   -jns 0x4677b4
    if (!cpu.flags.sf)
    {
        goto L_0x004677b4;
    }
L_0x004677ed:
    // 004677ed  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004677ef  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004677f1  e82aefffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 004677f6  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004677fa  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004677fc  0f86e2000000           -jbe 0x4678e4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004678e4;
    }
    // 00467802  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00467806  81e6ff000000           +and esi, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/))));
L_0x0046780c:
    // 0046780c  e89ff4ffff             -call 0x466cb0
    cpu.esp -= 4;
    sub_466cb0(app, cpu);
    // 00467811  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00467812  75f8                   -jne 0x46780c
    if (!cpu.flags.zf)
    {
        goto L_0x0046780c;
    }
    // 00467814  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467815  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467816  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467817  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467818  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046781b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046781c:
    // 0046781c  8b3584be5100           -mov esi, dword ptr [0x51be84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 00467822  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467824  7552                   -jne 0x467878
    if (!cpu.flags.zf)
    {
        goto L_0x00467878;
    }
    // 00467826  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 0046782b  e84afa0000             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00467830  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467833  a384be5100             -mov dword ptr [0x51be84], eax
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.eax;
    // 00467838  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046783a  7512                   -jne 0x46784e
    if (!cpu.flags.zf)
    {
        goto L_0x0046784e;
    }
    // 0046783c  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 00467841  e8cad3fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467846  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 0046784b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046784e:
    // 0046784e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00467850:
    // 00467850  8d540110               -lea edx, [ecx + eax + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 00467854  8954010c               -mov dword ptr [ecx + eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.edx;
    // 00467858  a184be5100             -mov eax, dword ptr [0x51be84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
    // 0046785d  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00467860  81f9f0030000           +cmp ecx, 0x3f0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1008 /*0x3f0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467866  7ce8                   -jl 0x467850
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00467850;
    }
    // 00467868  c780fc03000000000000   -mov dword ptr [eax + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00467872  8b3584be5100           -mov esi, dword ptr [0x51be84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */);
L_0x00467878:
    // 00467878  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046787b  890d84be5100           -mov dword ptr [0x51be84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5357188) /* 0x51be84 */) = cpu.ecx;
    // 00467881  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00467883  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00467886  66837f2200             +cmp word ptr [edi + 0x22], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046788b  762f                   -jbe 0x4678bc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004678bc;
    }
    // 0046788d  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046788f  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00467896  668b4722               -mov ax, word ptr [edi + 0x22]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(34) /* 0x22 */);
    // 0046789a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046789b  781f                   -js 0x4678bc
    if (cpu.flags.sf)
    {
        goto L_0x004678bc;
    }
    // 0046789d  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x004678a0:
    // 004678a0  e84bf4ffff             -call 0x466cf0
    cpu.esp -= 4;
    sub_466cf0(app, cpu);
    // 004678a5  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004678a7  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004678a9  e8b2ecffff             -call 0x466560
    cpu.esp -= 4;
    sub_466560(app, cpu);
    // 004678ae  d91f                   +fstp dword ptr [edi]
    app->getMemory<float>(cpu.edi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004678b0  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004678b3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004678b4  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004678b7  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004678ba  75e4                   -jne 0x4678a0
    if (!cpu.flags.zf)
    {
        goto L_0x004678a0;
    }
L_0x004678bc:
    // 004678bc  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004678c0  dc0dc87a4800           -fmul qword ptr [0x487ac8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4750024) /* 0x487ac8 */));
    // 004678c6  e8c5f40000             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 004678cb  8b1548845100           -mov edx, dword ptr [0x518448]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 004678d1  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004678d3  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004678d5  3bca                   +cmp ecx, edx
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
    // 004678d7  7501                   -jne 0x4678da
    if (!cpu.flags.zf)
    {
        goto L_0x004678da;
    }
    // 004678d9  41                     -inc ecx
    (cpu.ecx)++;
L_0x004678da:
    // 004678da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004678db  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004678dd  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004678df  e87c92feff             -call 0x450b60
    cpu.esp -= 4;
    sub_450b60(app, cpu);
L_0x004678e4:
    // 004678e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004678e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004678e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004678e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004678e8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004678eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4678f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004678f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004678f1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004678f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004678f4  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004678f6  66837e2201             +cmp word ptr [esi + 0x22], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004678fb  740d                   -je 0x46790a
    if (cpu.flags.zf)
    {
        goto L_0x0046790a;
    }
    // 004678fd  68542b4a00             -push 0x4a2b54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860756 /*0x4a2b54*/;
    cpu.esp -= 4;
    // 00467902  e809d3fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467907  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046790a:
    // 0046790a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0046790d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046790f  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00467913  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00467916  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046791b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046791d  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467921  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00467923  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00467925  d91c88                 -fstp dword ptr [eax + ecx*4]
    app->getMemory<float>(cpu.eax + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467928  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046792a  e8f1edffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 0046792f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467930  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467931  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_467940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467940  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467941  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00467943  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467944  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00467946  66837e2202             +cmp word ptr [esi + 0x22], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046794b  740d                   -je 0x46795a
    if (cpu.flags.zf)
    {
        goto L_0x0046795a;
    }
    // 0046794d  68702b4a00             -push 0x4a2b70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860784 /*0x4a2b70*/;
    cpu.esp -= 4;
    // 00467952  e8b9d2fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467957  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046795a:
    // 0046795a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0046795d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046795f  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00467963  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00467966  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046796b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046796d  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467971  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00467973  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467975  d91c88                 -fstp dword ptr [eax + ecx*4]
    app->getMemory<float>(cpu.eax + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467978  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0046797b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046797d  668b4704               -mov ax, word ptr [edi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467981  668b5102               -mov dx, word ptr [ecx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00467985  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 0046798b  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0046798f  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00467991  d91c91                 -fstp dword ptr [ecx + edx*4]
    app->getMemory<float>(cpu.ecx + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467994  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00467996  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00467998  e883edffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 0046799d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046799e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046799f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4679b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004679b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004679b1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004679b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004679b4  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004679b6  66837e2203             +cmp word ptr [esi + 0x22], 3
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(3 /*0x3*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004679bb  740d                   -je 0x4679ca
    if (cpu.flags.zf)
    {
        goto L_0x004679ca;
    }
    // 004679bd  688c2b4a00             -push 0x4a2b8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860812 /*0x4a2b8c*/;
    cpu.esp -= 4;
    // 004679c2  e849d2fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004679c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004679ca:
    // 004679ca  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004679cd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004679cf  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004679d3  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004679d6  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004679db  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004679dd  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004679e1  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004679e3  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004679e5  d91c88                 -fstp dword ptr [eax + ecx*4]
    app->getMemory<float>(cpu.eax + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004679e8  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004679eb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004679ed  668b4704               -mov ax, word ptr [edi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004679f1  668b5102               -mov dx, word ptr [ecx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004679f5  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 004679fb  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004679ff  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00467a01  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467a03  d91c91                 -fstp dword ptr [ecx + edx*4]
    app->getMemory<float>(cpu.ecx + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467a06  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00467a09  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467a0b  668b4f04               -mov cx, word ptr [edi + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467a0f  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00467a13  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467a19  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00467a1d  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00467a1f  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00467a21  d91c82                 -fstp dword ptr [edx + eax*4]
    app->getMemory<float>(cpu.edx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467a24  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00467a26  e8f5ecffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 00467a2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467a2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467a2d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_467a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467a30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467a31  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00467a33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467a34  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00467a36  66837e2204             +cmp word ptr [esi + 0x22], 4
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(34) /* 0x22 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(4 /*0x4*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00467a3b  740d                   -je 0x467a4a
    if (cpu.flags.zf)
    {
        goto L_0x00467a4a;
    }
    // 00467a3d  68702b4a00             -push 0x4a2b70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860784 /*0x4a2b70*/;
    cpu.esp -= 4;
    // 00467a42  e8c9d1fbff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00467a47  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00467a4a:
    // 00467a4a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00467a4d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467a4f  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00467a53  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00467a56  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467a5b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467a5d  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467a61  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00467a63  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467a65  d91c88                 -fstp dword ptr [eax + ecx*4]
    app->getMemory<float>(cpu.eax + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467a68  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00467a6b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467a6d  668b4704               -mov ax, word ptr [edi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467a71  668b5102               -mov dx, word ptr [ecx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00467a75  8b0dacc05100           -mov ecx, dword ptr [0x51c0ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467a7b  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00467a7f  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00467a81  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467a83  d91c91                 -fstp dword ptr [ecx + edx*4]
    app->getMemory<float>(cpu.ecx + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467a86  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00467a89  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467a8b  668b4f04               -mov cx, word ptr [edi + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467a8f  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00467a93  8b15acc05100           -mov edx, dword ptr [0x51c0ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467a99  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00467a9d  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00467a9f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467aa1  d91c82                 -fstp dword ptr [edx + eax*4]
    app->getMemory<float>(cpu.edx + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467aa4  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00467aa7  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467aa9  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00467aad  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00467ab1  a1acc05100             -mov eax, dword ptr [0x51c0ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5357740) /* 0x51c0ac */);
    // 00467ab6  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00467aba  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00467abc  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00467abe  d91c88                 -fstp dword ptr [eax + ecx*4]
    app->getMemory<float>(cpu.eax + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00467ac1  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00467ac3  e858ecffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 00467ac8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467ac9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467aca  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_467ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467ad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467ad1  e8da6cfbff             -call 0x41e7b0
    cpu.esp -= 4;
    sub_41e7b0(app, cpu);
    // 00467ad6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467ad8  7426                   -je 0x467b00
    if (cpu.flags.zf)
    {
        goto L_0x00467b00;
    }
    // 00467ada  8bb018030000           -mov esi, dword ptr [eax + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 00467ae0  b918ae4800             -mov ecx, 0x48ae18
    cpu.ecx = 4763160 /*0x48ae18*/;
    // 00467ae5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00467ae7  e824f1ffff             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 00467aec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467aee  7410                   -je 0x467b00
    if (cpu.flags.zf)
    {
        goto L_0x00467b00;
    }
    // 00467af0  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00467af2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467af4  e827ecffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
    // 00467af9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00467afe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467aff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467b00:
    // 00467b00  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467b02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467b03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_467b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467b10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467b11  8b358cbe5100           -mov esi, dword ptr [0x51be8c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5357196) /* 0x51be8c */);
    // 00467b17  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467b19  741e                   -je 0x467b39
    if (cpu.flags.zf)
    {
        goto L_0x00467b39;
    }
L_0x00467b1b:
    // 00467b1b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00467b1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467b20  7410                   -je 0x467b32
    if (cpu.flags.zf)
    {
        goto L_0x00467b32;
    }
    // 00467b22  807e0603               +cmp byte ptr [esi + 6], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467b26  750a                   -jne 0x467b32
    if (!cpu.flags.zf)
    {
        goto L_0x00467b32;
    }
    // 00467b28  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00467b2b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00467b2d  e8eeebffff             -call 0x466720
    cpu.esp -= 4;
    sub_466720(app, cpu);
L_0x00467b32:
    // 00467b32  8b7618                 -mov esi, dword ptr [esi + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00467b35  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467b37  75e2                   -jne 0x467b1b
    if (!cpu.flags.zf)
    {
        goto L_0x00467b1b;
    }
L_0x00467b39:
    // 00467b39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467b3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_467b40(WinApplication* app, x86::CPU& cpu)
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
void Application::sub_467bc0(WinApplication* app, x86::CPU& cpu)
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
void Application::sub_467ca0(WinApplication* app, x86::CPU& cpu)
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
    _malloc(app, cpu);
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

}
