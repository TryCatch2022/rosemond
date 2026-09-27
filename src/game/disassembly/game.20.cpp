#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_47991f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047991f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479920  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479924  3b35e01f5200           +cmp esi, dword ptr [0x521fe0]
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
    // 0047992a  7340                   -jae 0x47996c
    if (!cpu.flags.cf)
    {
        goto L_0x0047996c;
    }
    // 0047992c  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047992e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00479930  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00479933  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00479936  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047993d  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00479940  f644810401             +test byte ptr [ecx + eax*4 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) & 1 /*0x1*/));
    // 00479945  7425                   -je 0x47996c
    if (cpu.flags.zf)
    {
        goto L_0x0047996c;
    }
    // 00479947  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479948  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479949  e8325c0000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 0047994e  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00479952  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00479956  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479957  e828000000             -call 0x479984
    cpu.esp -= 4;
    sub_479984(app, cpu);
    // 0047995c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047995d  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047995f  e87b5c0000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 00479964  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00479967  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00479969  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047996a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047996b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047996c:
    // 0047996c  e8414b0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479971  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 00479977  e83f4b0000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0047997c  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047997f  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00479982  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479983  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479984(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479984  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479985  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00479987  81ec14040000           -sub esp, 0x414
    (cpu.esp) -= x86::reg32(x86::sreg32(1044 /*0x414*/));
    // 0047998d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047998e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047998f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479990  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00479992  397d10                 +cmp dword ptr [ebp + 0x10], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479995  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 00479998  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 0047999b  7507                   -jne 0x4799a4
    if (!cpu.flags.zf)
    {
        goto L_0x004799a4;
    }
L_0x0047999d:
    // 0047999d  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047999f  e966010000             -jmp 0x479b0a
    goto L_0x00479b0a;
L_0x004799a4:
    // 004799a4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004799a7  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 004799aa  8d1c85e01e5200         -lea ebx, [eax*4 + 0x521ee0]
    cpu.ebx = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 004799b1  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004799b4  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004799b7  8d34c0                 -lea esi, [eax + eax*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004799ba  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004799bc  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004799bf  f644300420             +test byte ptr [eax + esi + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 32 /*0x20*/));
    // 004799c4  740e                   -je 0x4799d4
    if (cpu.flags.zf)
    {
        goto L_0x004799d4;
    }
    // 004799c6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004799c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004799c9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004799cc  e8584b0000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 004799d1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004799d4:
    // 004799d4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004799d6  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004799d8  f6400480               +test byte ptr [eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 004799dc  0f84c1000000           -je 0x479aa3
    if (cpu.flags.zf)
    {
        goto L_0x00479aa3;
    }
    // 004799e2  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004799e5  397d10                 +cmp dword ptr [ebp + 0x10], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004799e8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004799eb  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004799ee  0f86ea000000           -jbe 0x479ade
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00479ade;
    }
L_0x004799f4:
    // 004799f4  8d85ecfbffff           -lea eax, [ebp - 0x414]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
L_0x004799fa:
    // 004799fa  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004799fd  2b4d0c                 -sub ecx, dword ptr [ebp + 0xc]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00479a00  3b4d10                 +cmp ecx, dword ptr [ebp + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479a03  7329                   -jae 0x479a2e
    if (!cpu.flags.cf)
    {
        goto L_0x00479a2e;
    }
    // 00479a05  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00479a08  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00479a0b  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00479a0d  80f90a                 +cmp cl, 0xa
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479a10  7507                   -jne 0x479a19
    if (!cpu.flags.zf)
    {
        goto L_0x00479a19;
    }
    // 00479a12  ff45f0                 -inc dword ptr [ebp - 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))++;
    // 00479a15  c6000d                 -mov byte ptr [eax], 0xd
    app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 00479a18  40                     -inc eax
    (cpu.eax)++;
L_0x00479a19:
    // 00479a19  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00479a1b  40                     -inc eax
    (cpu.eax)++;
    // 00479a1c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479a1e  8d95ecfbffff           -lea edx, [ebp - 0x414]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 00479a24  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00479a26  81f900040000           +cmp ecx, 0x400
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
    // 00479a2c  7ccc                   -jl 0x4799fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004799fa;
    }
L_0x00479a2e:
    // 00479a2e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00479a30  8d85ecfbffff           -lea eax, [ebp - 0x414]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 00479a36  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00479a38  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00479a3b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479a3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479a3e  8d85ecfbffff           -lea eax, [ebp - 0x414]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 00479a44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479a45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479a46  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00479a48  ff3430                 -push dword ptr [eax + esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
    cpu.esp -= 4;
    // 00479a4b  ff156c714800           -call dword ptr [0x48716c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747628) /* 0x48716c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479a51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479a53  7443                   -je 0x479a98
    if (cpu.flags.zf)
    {
        goto L_0x00479a98;
    }
    // 00479a55  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00479a58  0145f8                 -add dword ptr [ebp - 8], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479a5b  3bc7                   +cmp eax, edi
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
    // 00479a5d  7c0b                   -jl 0x479a6a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479a6a;
    }
    // 00479a5f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00479a62  2b450c                 -sub eax, dword ptr [ebp + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00479a65  3b4510                 +cmp eax, dword ptr [ebp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479a68  728a                   -jb 0x4799f4
    if (cpu.flags.cf)
    {
        goto L_0x004799f4;
    }
L_0x00479a6a:
    // 00479a6a  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00479a6c:
    // 00479a6c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00479a6f  3bc7                   +cmp eax, edi
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
    // 00479a71  0f8590000000           -jne 0x479b07
    if (!cpu.flags.zf)
    {
        goto L_0x00479b07;
    }
    // 00479a77  397d08                 +cmp dword ptr [ebp + 8], edi
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
    // 00479a7a  7462                   -je 0x479ade
    if (cpu.flags.zf)
    {
        goto L_0x00479ade;
    }
    // 00479a7c  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00479a7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a7f  397508                 +cmp dword ptr [ebp + 8], esi
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
    // 00479a82  754c                   -jne 0x479ad0
    if (!cpu.flags.zf)
    {
        goto L_0x00479ad0;
    }
    // 00479a84  e8294a0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479a89  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 00479a8f  e8274a0000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00479a94  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00479a96  eb41                   -jmp 0x479ad9
    goto L_0x00479ad9;
L_0x00479a98:
    // 00479a98  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479a9e  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479aa1  ebc7                   -jmp 0x479a6a
    goto L_0x00479a6a;
L_0x00479aa3:
    // 00479aa3  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00479aa6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479aa7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479aa8  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00479aab  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00479aae  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 00479ab0  ff156c714800           -call dword ptr [0x48716c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747628) /* 0x48716c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479ab6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479ab8  740b                   -je 0x479ac5
    if (cpu.flags.zf)
    {
        goto L_0x00479ac5;
    }
    // 00479aba  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00479abd  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00479ac0  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00479ac3  eba7                   -jmp 0x479a6c
    goto L_0x00479a6c;
L_0x00479ac5:
    // 00479ac5  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479acb  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479ace  eb9c                   -jmp 0x479a6c
    goto L_0x00479a6c;
L_0x00479ad0:
    // 00479ad0  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00479ad3  e867490000             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00479ad8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479ad9:
    // 00479ad9  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00479adc  eb2c                   -jmp 0x479b0a
    goto L_0x00479b0a;
L_0x00479ade:
    // 00479ade  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00479ae0  f644300440             +test byte ptr [eax + esi + 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 64 /*0x40*/));
    // 00479ae5  740c                   -je 0x479af3
    if (cpu.flags.zf)
    {
        goto L_0x00479af3;
    }
    // 00479ae7  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00479aea  80381a                 +cmp byte ptr [eax], 0x1a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(26 /*0x1a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479aed  0f84aafeffff           -je 0x47999d
    if (cpu.flags.zf)
    {
        goto L_0x0047999d;
    }
L_0x00479af3:
    // 00479af3  e8ba490000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479af8  c7001c000000           -mov dword ptr [eax], 0x1c
    app->getMemory<x86::reg32>(cpu.eax) = 28 /*0x1c*/;
    // 00479afe  e8b8490000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00479b03  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00479b05  ebd2                   -jmp 0x479ad9
    goto L_0x00479ad9;
L_0x00479b07:
    // 00479b07  2b45f0                 -sub eax, dword ptr [ebp - 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
L_0x00479b0a:
    // 00479b0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b0d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479b0f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479b0f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b10  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479b15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b16  e86ee0ffff             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 00479b1b  f6460c83               +test byte ptr [esi + 0xc], 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 131 /*0x83*/));
    // 00479b1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b20  7407                   -je 0x479b29
    if (cpu.flags.zf)
    {
        goto L_0x00479b29;
    }
    // 00479b22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b23  e8e0daffff             -call 0x477608
    cpu.esp -= 4;
    __fclose_lk(app, cpu);
    // 00479b28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479b29:
    // 00479b29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b2a  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00479b2c  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00479b30  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479b32  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479b35  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00479b37  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00479b3b  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00479b3e  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00479b41  e8c1460000             -call 0x47e207
    cpu.esp -= 4;
    sub_47e207(app, cpu);
    // 00479b46  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b47  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00479b49  e88de0ffff             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 00479b4e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00479b51  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00479b53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__global_unwind2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479b58  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479b59  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00479b5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b5c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b5d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479b5e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479b5f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479b61  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479b63  68709b4700             -push 0x479b70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4692848 /*0x479b70*/;
    cpu.esp -= 4;
    // 00479b68  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00479b6b  e820bb0000             -call 0x485690
    cpu.esp -= 4;
    sub_485690(app, cpu);
    // 00479b70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b73  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b74  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00479b76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479b78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479b78  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00479b7c  f7410406000000         +test dword ptr [ecx + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00479b83  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479b88  740f                   -je 0x479b99
    if (cpu.flags.zf)
    {
        goto L_0x00479b99;
    }
    // 00479b8a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479b8e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479b92  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00479b94  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x00479b99:
    // 00479b99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__local_unwind2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479b9a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479b9d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479ba1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479ba2  6afe                   -push -2
    app->getMemory<x86::reg32>(cpu.esp-4) = -2 /*-0x2*/;
    cpu.esp -= 4;
    // 00479ba4  68789b4700             -push 0x479b78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4692856 /*0x479b78*/;
    cpu.esp -= 4;
    // 00479ba9  64ff3500000000         -push dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.efs);
    cpu.esp -= 4;
    // 00479bb0  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
L_0x00479bb7:
    // 00479bb7  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479bbb  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479bbe  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00479bc1  83feff                 +cmp esi, -1
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
    // 00479bc4  742e                   -je 0x479bf4
    if (cpu.flags.zf)
    {
        goto L_0x00479bf4;
    }
    // 00479bc6  3b742424               +cmp esi, dword ptr [esp + 0x24]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479bca  7428                   -je 0x479bf4
    if (cpu.flags.zf)
    {
        goto L_0x00479bf4;
    }
    // 00479bcc  8d3476                 -lea esi, [esi + esi*2]
    cpu.esi = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00479bcf  8b0cb3                 -mov ecx, dword ptr [ebx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.esi * 4);
    // 00479bd2  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00479bd6  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00479bd9  837cb30400             +cmp dword ptr [ebx + esi*4 + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479bde  7512                   -jne 0x479bf2
    if (!cpu.flags.zf)
    {
        goto L_0x00479bf2;
    }
    // 00479be0  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 00479be5  8b44b308               -mov eax, dword ptr [ebx + esi*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    // 00479be9  e840000000             -call 0x479c2e
    cpu.esp -= 4;
    sub_479c2e(app, cpu);
    // 00479bee  ff54b308               -call dword ptr [ebx + esi*4 + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00479bf2:
    // 00479bf2  ebc3                   -jmp 0x479bb7
    goto L_0x00479bb7;
L_0x00479bf4:
    // 00479bf4  648f0500000000         -pop dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.efs) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bfb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00479bfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__abnormal_termination(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479c02  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479c04  648b0d00000000         -mov ecx, dword ptr fs:[0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.efs);
    // 00479c0b  817904789b4700         +cmp dword ptr [ecx + 4], 0x479b78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4692856 /*0x479b78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479c12  7510                   -jne 0x479c24
    if (!cpu.flags.zf)
    {
        goto L_0x00479c24;
    }
    // 00479c14  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00479c17  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00479c1a  395108                 +cmp dword ptr [ecx + 8], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479c1d  7505                   -jne 0x479c24
    if (!cpu.flags.zf)
    {
        goto L_0x00479c24;
    }
    // 00479c1f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00479c24:
    // 00479c24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__NLG_Notify1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479c25  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479c26  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479c27  bb943f4a00             -mov ebx, 0x4a3f94
    cpu.ebx = 4865940 /*0x4a3f94*/;
    // 00479c2c  eb0a                   -jmp 0x479c38
    return sub_479c38(app, cpu);
}

/* align: skip  */
void Application::sub_479c2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479c2e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479c2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479c30  bb943f4a00             -mov ebx, 0x4a3f94
    cpu.ebx = 4865940 /*0x4a3f94*/;
    // 00479c35  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00479c38  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00479c3b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00479c3e  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00479c41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c43  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_479c38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00479c38;
    // 00479c2e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479c2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479c30  bb943f4a00             -mov ebx, 0x4a3f94
    cpu.ebx = 4865940 /*0x4a3f94*/;
    // 00479c35  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_entry_0x00479c38:
    // 00479c38  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00479c3b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00479c3e  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00479c41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c43  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_479c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479c50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479c51  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00479c53  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479c56  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479c57  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479c58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479c59  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479c5a  fc                     -cld 
    cpu.flags.df = 0;
    // 00479c5b  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00479c5e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00479c61  f7400406000000         +test dword ptr [eax + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00479c68  0f8582000000           -jne 0x479cf0
    if (!cpu.flags.zf)
    {
        goto L_0x00479cf0;
    }
    // 00479c6e  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00479c71  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479c74  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00479c77  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00479c7a  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00479c7d  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00479c80  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
L_0x00479c83:
    // 00479c83  83feff                 +cmp esi, -1
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
    // 00479c86  7461                   -je 0x479ce9
    if (cpu.flags.zf)
    {
        goto L_0x00479ce9;
    }
    // 00479c88  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00479c8b  837c8f0400             +cmp dword ptr [edi + ecx*4 + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479c90  7445                   -je 0x479cd7
    if (cpu.flags.zf)
    {
        goto L_0x00479cd7;
    }
    // 00479c92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479c93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479c94  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00479c97  ff548f04               -call dword ptr [edi + ecx*4 + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479c9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c9d  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00479ca0  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479ca2  7433                   -je 0x479cd7
    if (cpu.flags.zf)
    {
        goto L_0x00479cd7;
    }
    // 00479ca4  783c                   -js 0x479ce2
    if (cpu.flags.sf)
    {
        goto L_0x00479ce2;
    }
    // 00479ca6  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00479ca9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479caa  e8a9feffff             -call 0x479b58
    cpu.esp -= 4;
    __global_unwind2(app, cpu);
    // 00479caf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479cb2  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00479cb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479cb6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479cb7  e8defeffff             -call 0x479b9a
    cpu.esp -= 4;
    __local_unwind2(app, cpu);
    // 00479cbc  83c408                 +add esp, 8
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
    // 00479cbf  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00479cc2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00479cc4  8b448f08               -mov eax, dword ptr [edi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00479cc8  e861ffffff             -call 0x479c2e
    cpu.esp -= 4;
    sub_479c2e(app, cpu);
    // 00479ccd  8b048f                 -mov eax, dword ptr [edi + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00479cd0  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00479cd3  ff548f08               -call dword ptr [edi + ecx*4 + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00479cd7:
    // 00479cd7  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00479cda  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00479cdd  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00479ce0  eba1                   -jmp 0x479c83
    goto L_0x00479c83;
L_0x00479ce2:
    // 00479ce2  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 00479ce7  eb1c                   -jmp 0x479d05
    goto L_0x00479d05;
L_0x00479ce9:
    // 00479ce9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479cee  eb15                   -jmp 0x479d05
    goto L_0x00479d05;
L_0x00479cf0:
    // 00479cf0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479cf1  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00479cf4  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00479cf6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479cf7  e89efeffff             -call 0x479b9a
    cpu.esp -= 4;
    __local_unwind2(app, cpu);
    // 00479cfc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479cff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d00  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00479d05:
    // 00479d05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d09  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00479d0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479d0d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d0d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479d0e  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479d12  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00479d14  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00479d17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479d18  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00479d1b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479d1c  e879feffff             -call 0x479b9a
    cpu.esp -= 4;
    __local_unwind2(app, cpu);
    // 00479d21  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479d24  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d25  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::__alldiv(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479d31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479d32  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479d33  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00479d35  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00479d39  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479d3b  7d14                   -jge 0x479d51
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479d51;
    }
    // 00479d3d  47                     -inc edi
    (cpu.edi)++;
    // 00479d3e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479d42  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00479d44  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00479d46  83d800                 -sbb eax, 0
    (cpu.eax) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00479d49  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00479d4d  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00479d51:
    // 00479d51  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479d55  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479d57  7d14                   -jge 0x479d6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479d6d;
    }
    // 00479d59  47                     -inc edi
    (cpu.edi)++;
    // 00479d5a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479d5e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00479d60  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00479d62  83d800                 -sbb eax, 0
    (cpu.eax) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00479d65  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00479d69  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x00479d6d:
    // 00479d6d  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479d6f  7518                   -jne 0x479d89
    if (!cpu.flags.zf)
    {
        goto L_0x00479d89;
    }
    // 00479d71  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479d75  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00479d79  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479d7b  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00479d7d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479d7f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479d83  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00479d85  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00479d87  eb41                   -jmp 0x479dca
    goto L_0x00479dca;
L_0x00479d89:
    // 00479d89  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479d8b  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479d8f  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00479d93  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00479d97:
    // 00479d97  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ebx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00479d99  d1d9                   -rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 00479d9b  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00479d9d  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 00479d9f  0bdb                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00479da1  75f4                   -jne 0x479d97
    if (!cpu.flags.zf)
    {
        goto L_0x00479d97;
    }
    // 00479da3  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00479da5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479da7  f764241c               -mul dword ptr [esp + 0x1c]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */));
    // 00479dab  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479dad  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479db1  f7e6                   -mul esi
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.esi);
    // 00479db3  03d1                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00479db5  720e                   -jb 0x479dc5
    if (cpu.flags.cf)
    {
        goto L_0x00479dc5;
    }
    // 00479db7  3b542414               +cmp edx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479dbb  7708                   -ja 0x479dc5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00479dc5;
    }
    // 00479dbd  7207                   -jb 0x479dc6
    if (cpu.flags.cf)
    {
        goto L_0x00479dc6;
    }
    // 00479dbf  3b442410               +cmp eax, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479dc3  7601                   -jbe 0x479dc6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00479dc6;
    }
L_0x00479dc5:
    // 00479dc5  4e                     -dec esi
    (cpu.esi)--;
L_0x00479dc6:
    // 00479dc6  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479dc8  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00479dca:
    // 00479dca  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479dcb  7507                   -jne 0x479dd4
    if (!cpu.flags.zf)
    {
        goto L_0x00479dd4;
    }
    // 00479dcd  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00479dcf  f7d8                   +neg eax
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
    // 00479dd1  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00479dd4:
    // 00479dd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479dd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479dd6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479dd7  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_479dda(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479dda  833d1420520000         +cmp dword ptr [0x522014], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382164) /* 0x522014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479de1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479de2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479de3  8b3508eb5100           -mov esi, dword ptr [0x51eb08]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */);
    // 00479de9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479dea  7465                   -je 0x479e51
    if (cpu.flags.zf)
    {
        goto L_0x00479e51;
    }
    // 00479dec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479dee  751b                   -jne 0x479e0b
    if (!cpu.flags.zf)
    {
        goto L_0x00479e0b;
    }
    // 00479df0  393510eb5100           +cmp dword ptr [0x51eb10], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479df6  7459                   -je 0x479e51
    if (cpu.flags.zf)
    {
        goto L_0x00479e51;
    }
    // 00479df8  e8eb670000             -call 0x4805e8
    cpu.esp -= 4;
    sub_4805e8(app, cpu);
    // 00479dfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479dff  7550                   -jne 0x479e51
    if (!cpu.flags.zf)
    {
        goto L_0x00479e51;
    }
    // 00479e01  8b3508eb5100           -mov esi, dword ptr [0x51eb08]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5368584) /* 0x51eb08 */);
    // 00479e07  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479e09  7446                   -je 0x479e51
    if (cpu.flags.zf)
    {
        goto L_0x00479e51;
    }
L_0x00479e0b:
    // 00479e0b  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479e0f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479e11  743e                   -je 0x479e51
    if (cpu.flags.zf)
    {
        goto L_0x00479e51;
    }
    // 00479e13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479e14  e8c73f0000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00479e19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e1a  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00479e1c:
    // 00479e1c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00479e1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479e20  742f                   -je 0x479e51
    if (cpu.flags.zf)
    {
        goto L_0x00479e51;
    }
    // 00479e22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479e23  e8b83f0000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00479e28  3bc7                   +cmp eax, edi
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
    // 00479e2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e2b  7617                   -jbe 0x479e44
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00479e44;
    }
    // 00479e2d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00479e2f  803c383d               +cmp byte ptr [eax + edi], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479e33  750f                   -jne 0x479e44
    if (!cpu.flags.zf)
    {
        goto L_0x00479e44;
    }
    // 00479e35  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479e36  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479e37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479e38  e86c670000             -call 0x4805a9
    cpu.esp -= 4;
    __mbsnbicoll(app, cpu);
    // 00479e3d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00479e40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479e42  7405                   -je 0x479e49
    if (cpu.flags.zf)
    {
        goto L_0x00479e49;
    }
L_0x00479e44:
    // 00479e44  83c604                 +add esi, 4
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
    // 00479e47  ebd3                   -jmp 0x479e1c
    goto L_0x00479e1c;
L_0x00479e49:
    // 00479e49  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00479e4b  8d443801               -lea eax, [eax + edi + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */ + cpu.edi * 1);
    // 00479e4f  eb02                   -jmp 0x479e53
    goto L_0x00479e53;
L_0x00479e51:
    // 00479e51  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479e53:
    // 00479e53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_strchr(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00479e70;
L_0x00479e60:
    // 00479e60  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00479e63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e64  c3                     -ret 
    cpu.esp += 4;
    return;
L_entry_0x00479e70:
    // 00479e70  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479e72  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479e76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479e77  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479e79  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00479e7c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479e80  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 00479e86  7413                   -je 0x479e9b
    if (cpu.flags.zf)
    {
        goto L_0x00479e9b;
    }
L_0x00479e88:
    // 00479e88  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00479e8a  42                     -inc edx
    (cpu.edx)++;
    // 00479e8b  38d9                   +cmp cl, bl
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
    // 00479e8d  74d1                   -je 0x479e60
    if (cpu.flags.zf)
    {
        goto L_0x00479e60;
    }
    // 00479e8f  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00479e91  7451                   -je 0x479ee4
    if (cpu.flags.zf)
    {
        goto L_0x00479ee4;
    }
    // 00479e93  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 00479e99  75ed                   -jne 0x479e88
    if (!cpu.flags.zf)
    {
        goto L_0x00479e88;
    }
L_0x00479e9b:
    // 00479e9b  0bd8                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00479e9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479e9e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00479ea0  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00479ea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479ea4  0bd8                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479ea6:
    // 00479ea6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479ea8  bffffefe7e             -mov edi, 0x7efefeff
    cpu.edi = 2130640639 /*0x7efefeff*/;
    // 00479ead  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479eaf  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00479eb1  33cb                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479eb3  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479eb5  03f9                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00479eb7  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00479eba  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00479ebd  33cf                   -xor ecx, edi
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00479ebf  33c6                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00479ec1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479ec4  81e100010181           +and ecx, 0x81010100
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(2164326656 /*0x81010100*/))));
    // 00479eca  751c                   -jne 0x479ee8
    if (!cpu.flags.zf)
    {
        goto L_0x00479ee8;
    }
    // 00479ecc  2500010181             +and eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2164326656 /*0x81010100*/))));
    // 00479ed1  74d3                   -je 0x479ea6
    if (cpu.flags.zf)
    {
        goto L_0x00479ea6;
    }
    // 00479ed3  2500010101             +and eax, 0x1010100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16843008 /*0x1010100*/))));
    // 00479ed8  7508                   -jne 0x479ee2
    if (!cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479eda  81e600000080           +and esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 00479ee0  75c4                   -jne 0x479ea6
    if (!cpu.flags.zf)
    {
        goto L_0x00479ea6;
    }
L_0x00479ee2:
    // 00479ee2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ee3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479ee4:
    // 00479ee4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ee5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479ee7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479ee8:
    // 00479ee8  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00479eeb  38d8                   +cmp al, bl
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
    // 00479eed  7436                   -je 0x479f25
    if (cpu.flags.zf)
    {
        goto L_0x00479f25;
    }
    // 00479eef  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00479ef1  74ef                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479ef3  38dc                   +cmp ah, bl
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479ef5  7427                   -je 0x479f1e
    if (cpu.flags.zf)
    {
        goto L_0x00479f1e;
    }
    // 00479ef7  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00479ef9  74e7                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479efb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00479efe  38d8                   +cmp al, bl
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
    // 00479f00  7415                   -je 0x479f17
    if (cpu.flags.zf)
    {
        goto L_0x00479f17;
    }
    // 00479f02  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00479f04  74dc                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479f06  38dc                   +cmp ah, bl
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f08  7406                   -je 0x479f10
    if (cpu.flags.zf)
    {
        goto L_0x00479f10;
    }
    // 00479f0a  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00479f0c  74d4                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479f0e  eb96                   -jmp 0x479ea6
    goto L_0x00479ea6;
L_0x00479f10:
    // 00479f10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f12  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00479f15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f17:
    // 00479f17  8d42fe                 -lea eax, [edx - 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00479f1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f1e:
    // 00479f1e  8d42fd                 -lea eax, [edx - 3]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-3) /* -0x3 */);
    // 00479f21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f25:
    // 00479f25  8d42fc                 -lea eax, [edx - 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00479f28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479e76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00479e76;
L_0x00479e60:
    // 00479e60  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00479e63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e64  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00479e70  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479e72  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_entry_0x00479e76:
    // 00479e76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479e77  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479e79  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00479e7c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479e80  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 00479e86  7413                   -je 0x479e9b
    if (cpu.flags.zf)
    {
        goto L_0x00479e9b;
    }
L_0x00479e88:
    // 00479e88  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00479e8a  42                     -inc edx
    (cpu.edx)++;
    // 00479e8b  38d9                   +cmp cl, bl
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
    // 00479e8d  74d1                   -je 0x479e60
    if (cpu.flags.zf)
    {
        goto L_0x00479e60;
    }
    // 00479e8f  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00479e91  7451                   -je 0x479ee4
    if (cpu.flags.zf)
    {
        goto L_0x00479ee4;
    }
    // 00479e93  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 00479e99  75ed                   -jne 0x479e88
    if (!cpu.flags.zf)
    {
        goto L_0x00479e88;
    }
L_0x00479e9b:
    // 00479e9b  0bd8                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00479e9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479e9e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00479ea0  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00479ea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479ea4  0bd8                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479ea6:
    // 00479ea6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479ea8  bffffefe7e             -mov edi, 0x7efefeff
    cpu.edi = 2130640639 /*0x7efefeff*/;
    // 00479ead  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479eaf  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00479eb1  33cb                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479eb3  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479eb5  03f9                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00479eb7  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00479eba  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00479ebd  33cf                   -xor ecx, edi
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00479ebf  33c6                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00479ec1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479ec4  81e100010181           +and ecx, 0x81010100
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(2164326656 /*0x81010100*/))));
    // 00479eca  751c                   -jne 0x479ee8
    if (!cpu.flags.zf)
    {
        goto L_0x00479ee8;
    }
    // 00479ecc  2500010181             +and eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2164326656 /*0x81010100*/))));
    // 00479ed1  74d3                   -je 0x479ea6
    if (cpu.flags.zf)
    {
        goto L_0x00479ea6;
    }
    // 00479ed3  2500010101             +and eax, 0x1010100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16843008 /*0x1010100*/))));
    // 00479ed8  7508                   -jne 0x479ee2
    if (!cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479eda  81e600000080           +and esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 00479ee0  75c4                   -jne 0x479ea6
    if (!cpu.flags.zf)
    {
        goto L_0x00479ea6;
    }
L_0x00479ee2:
    // 00479ee2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ee3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479ee4:
    // 00479ee4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ee5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479ee7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479ee8:
    // 00479ee8  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00479eeb  38d8                   +cmp al, bl
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
    // 00479eed  7436                   -je 0x479f25
    if (cpu.flags.zf)
    {
        goto L_0x00479f25;
    }
    // 00479eef  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00479ef1  74ef                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479ef3  38dc                   +cmp ah, bl
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479ef5  7427                   -je 0x479f1e
    if (cpu.flags.zf)
    {
        goto L_0x00479f1e;
    }
    // 00479ef7  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00479ef9  74e7                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479efb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00479efe  38d8                   +cmp al, bl
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
    // 00479f00  7415                   -je 0x479f17
    if (cpu.flags.zf)
    {
        goto L_0x00479f17;
    }
    // 00479f02  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00479f04  74dc                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479f06  38dc                   +cmp ah, bl
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f08  7406                   -je 0x479f10
    if (cpu.flags.zf)
    {
        goto L_0x00479f10;
    }
    // 00479f0a  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00479f0c  74d4                   -je 0x479ee2
    if (cpu.flags.zf)
    {
        goto L_0x00479ee2;
    }
    // 00479f0e  eb96                   -jmp 0x479ea6
    goto L_0x00479ea6;
L_0x00479f10:
    // 00479f10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f12  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00479f15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f17:
    // 00479f17  8d42fe                 -lea eax, [edx - 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00479f1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f1e:
    // 00479f1e  8d42fd                 -lea eax, [edx - 3]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-3) /* -0x3 */);
    // 00479f21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f25:
    // 00479f25  8d42fc                 -lea eax, [edx - 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00479f28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479f30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479f31  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00479f33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479f34  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479f35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479f36  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479f39  0bc9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00479f3b  0f84e9000000           -je 0x47a02a
    if (cpu.flags.zf)
    {
        goto L_0x0047a02a;
    }
    // 00479f41  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00479f44  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00479f47  8d05bceb5100           -lea eax, [0x51ebbc]
    cpu.eax = x86::reg32(x86::reg32(5368764) /* 0x51ebbc */);
    // 00479f4d  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479f51  754e                   -jne 0x479fa1
    if (!cpu.flags.zf)
    {
        goto L_0x00479fa1;
    }
    // 00479f53  b741                   -mov bh, 0x41
    cpu.bh = 65 /*0x41*/;
    // 00479f55  b35a                   -mov bl, 0x5a
    cpu.bl = 90 /*0x5a*/;
    // 00479f57  b620                   -mov dh, 0x20
    cpu.dh = 32 /*0x20*/;
    // 00479f59  8d4900                 -lea ecx, [ecx]
    cpu.ecx = x86::reg32(cpu.ecx);
L_0x00479f5c:
    // 00479f5c  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00479f5e  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 00479f60  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00479f62  7421                   -je 0x479f85
    if (cpu.flags.zf)
    {
        goto L_0x00479f85;
    }
    // 00479f64  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 00479f66  741d                   -je 0x479f85
    if (cpu.flags.zf)
    {
        goto L_0x00479f85;
    }
    // 00479f68  46                     -inc esi
    (cpu.esi)++;
    // 00479f69  47                     -inc edi
    (cpu.edi)++;
    // 00479f6a  38fc                   +cmp ah, bh
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f6c  7206                   -jb 0x479f74
    if (cpu.flags.cf)
    {
        goto L_0x00479f74;
    }
    // 00479f6e  38dc                   +cmp ah, bl
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f70  7702                   -ja 0x479f74
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00479f74;
    }
    // 00479f72  02e6                   -add ah, dh
    (cpu.ah) += x86::reg8(x86::sreg8(cpu.dh));
L_0x00479f74:
    // 00479f74  38f8                   +cmp al, bh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f76  7206                   -jb 0x479f7e
    if (cpu.flags.cf)
    {
        goto L_0x00479f7e;
    }
    // 00479f78  38d8                   +cmp al, bl
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
    // 00479f7a  7702                   -ja 0x479f7e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00479f7e;
    }
    // 00479f7c  02c6                   -add al, dh
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dh));
L_0x00479f7e:
    // 00479f7e  38c4                   +cmp ah, al
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f80  750d                   -jne 0x479f8f
    if (!cpu.flags.zf)
    {
        goto L_0x00479f8f;
    }
    // 00479f82  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479f83  75d7                   -jne 0x479f5c
    if (!cpu.flags.zf)
    {
        goto L_0x00479f5c;
    }
L_0x00479f85:
    // 00479f85  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479f87  38c4                   +cmp ah, al
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f89  0f849b000000           -je 0x47a02a
    if (cpu.flags.zf)
    {
        goto L_0x0047a02a;
    }
L_0x00479f8f:
    // 00479f8f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00479f94  0f8290000000           -jb 0x47a02a
    if (cpu.flags.cf)
    {
        goto L_0x0047a02a;
    }
    // 00479f9a  f7d9                   +neg ecx
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
    // 00479f9c  e989000000             -jmp 0x47a02a
    goto L_0x0047a02a;
L_0x00479fa1:
    // 00479fa1  f0ff05e81f5200         -lock inc dword ptr [0x521fe8]
    x86::atomic_increment(reinterpret_cast<x86::reg32 *>(x86::reg32(5382120) /* 0x521fe8 */));
    // 00479fa8  833de41f520000         +cmp dword ptr [0x521fe4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479faf  7f04                   -jg 0x479fb5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00479fb5;
    }
    // 00479fb1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479fb3  eb19                   -jmp 0x479fce
    goto L_0x00479fce;
L_0x00479fb5:
    // 00479fb5  f0ff0de81f5200         -lock dec dword ptr [0x521fe8]
    x86::atomic_decrement(reinterpret_cast<x86::reg32 *>(x86::reg32(5382120) /* 0x521fe8 */));
    // 00479fbc  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00479fbe  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00479fc0  e8042b0000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00479fc5  c7042401000000         -mov dword ptr [esp], 1
    app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
    // 00479fcc  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x00479fce:
    // 00479fce  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479fd0  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479fd2  8bff                   -mov edi, edi
    cpu.edi = cpu.edi;
L_0x00479fd4:
    // 00479fd4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00479fd6  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479fd8  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00479fda  7423                   -je 0x479fff
    if (cpu.flags.zf)
    {
        goto L_0x00479fff;
    }
    // 00479fdc  0bdb                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00479fde  741f                   -je 0x479fff
    if (cpu.flags.zf)
    {
        goto L_0x00479fff;
    }
    // 00479fe0  46                     -inc esi
    (cpu.esi)++;
    // 00479fe1  47                     -inc edi
    (cpu.edi)++;
    // 00479fe2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479fe3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479fe4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479fe5  e822d5ffff             -call 0x47750c
    cpu.esp -= 4;
    sub_47750c(app, cpu);
    // 00479fea  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479fec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479fef  e818d5ffff             -call 0x47750c
    cpu.esp -= 4;
    sub_47750c(app, cpu);
    // 00479ff4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479ff7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ff8  3bc3                   +cmp eax, ebx
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
    // 00479ffa  7509                   -jne 0x47a005
    if (!cpu.flags.zf)
    {
        goto L_0x0047a005;
    }
    // 00479ffc  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479ffd  75d5                   -jne 0x479fd4
    if (!cpu.flags.zf)
    {
        goto L_0x00479fd4;
    }
L_0x00479fff:
    // 00479fff  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a001  3bc3                   +cmp eax, ebx
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
    // 0047a003  7409                   -je 0x47a00e
    if (cpu.flags.zf)
    {
        goto L_0x0047a00e;
    }
L_0x0047a005:
    // 0047a005  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0047a00a  7202                   -jb 0x47a00e
    if (cpu.flags.cf)
    {
        goto L_0x0047a00e;
    }
    // 0047a00c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x0047a00e:
    // 0047a00e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a00f  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a011  7509                   -jne 0x47a01c
    if (!cpu.flags.zf)
    {
        goto L_0x0047a01c;
    }
    // 0047a013  f0ff0de81f5200         +lock dec dword ptr [0x521fe8]
    {
        x86::reg32 tmp = x86::atomic_decrement(reinterpret_cast<x86::reg32 *>(x86::reg32(5382120) /* 0x521fe8 */));
        cpu.flags.of = (tmp == 0x7fffffff);
        cpu.set_szp(tmp);
    }
    // 0047a01a  eb0e                   -jmp 0x47a02a
    goto L_0x0047a02a;
L_0x0047a01c:
    // 0047a01c  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047a01e  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0047a020  e8052b0000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047a025  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a028  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x0047a02a:
    // 0047a02a  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a02c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a02d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a02e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a02f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a030  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::entry(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a031  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a032  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a034  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0047a036  68e87c4800             -push 0x487ce8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750568 /*0x487ce8*/;
    cpu.esp -= 4;
    // 0047a03b  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0047a040  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a046  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a047  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0047a04e  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0047a051  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a052  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a053  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a054  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047a057  ff1574704800           -call dword ptr [0x487074]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747380) /* 0x487074 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a05d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a05f  8ad4                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0047a061  8915f8ea5100           -mov dword ptr [0x51eaf8], edx
    app->getMemory<x86::reg32>(x86::reg32(5368568) /* 0x51eaf8 */) = cpu.edx;
    // 0047a067  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a069  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047a06f  890df4ea5100           -mov dword ptr [0x51eaf4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5368564) /* 0x51eaf4 */) = cpu.ecx;
    // 0047a075  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0047a078  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a07a  890df0ea5100           -mov dword ptr [0x51eaf0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5368560) /* 0x51eaf0 */) = cpu.ecx;
    // 0047a080  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047a083  a3ecea5100             -mov dword ptr [0x51eaec], eax
    app->getMemory<x86::reg32>(x86::reg32(5368556) /* 0x51eaec */) = cpu.eax;
    // 0047a088  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a08a  e8402c0000             -call 0x47cccf
    cpu.esp -= 4;
    sub_47cccf(app, cpu);
    // 0047a08f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a090  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a092  7508                   -jne 0x47a09c
    if (!cpu.flags.zf)
    {
        goto L_0x0047a09c;
    }
    // 0047a094  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0047a096  e8c3000000             -call 0x47a15e
    cpu.esp -= 4;
    sub_47a15e(app, cpu);
    // 0047a09b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a09c:
    // 0047a09c  e85f130000             -call 0x47b400
    cpu.esp -= 4;
    sub_47b400(app, cpu);
    // 0047a0a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a0a3  7508                   -jne 0x47a0ad
    if (!cpu.flags.zf)
    {
        goto L_0x0047a0ad;
    }
    // 0047a0a5  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0047a0a7  e8b2000000             -call 0x47a15e
    cpu.esp -= 4;
    sub_47a15e(app, cpu);
    // 0047a0ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a0ad:
    // 0047a0ad  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047a0af  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0047a0b2  e8133f0000             -call 0x47dfca
    cpu.esp -= 4;
    sub_47dfca(app, cpu);
    // 0047a0b7  ff150c714800           -call dword ptr [0x48710c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747532) /* 0x48710c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a0bd  a310205200             -mov dword ptr [0x522010], eax
    app->getMemory<x86::reg32>(x86::reg32(5382160) /* 0x522010 */) = cpu.eax;
    // 0047a0c2  e8656a0000             -call 0x480b2c
    cpu.esp -= 4;
    sub_480b2c(app, cpu);
    // 0047a0c7  a32ceb5100             -mov dword ptr [0x51eb2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5368620) /* 0x51eb2c */) = cpu.eax;
    // 0047a0cc  e80e680000             -call 0x4808df
    cpu.esp -= 4;
    sub_4808df(app, cpu);
    // 0047a0d1  e850670000             -call 0x480826
    cpu.esp -= 4;
    sub_480826(app, cpu);
    // 0047a0d6  e857e5ffff             -call 0x478632
    cpu.esp -= 4;
    sub_478632(app, cpu);
    // 0047a0db  8975d0                 -mov dword ptr [ebp - 0x30], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.esi;
    // 0047a0de  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 0047a0e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a0e2  ff1510714800           -call dword ptr [0x487110]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747536) /* 0x487110 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a0e8  e8e1660000             -call 0x4807ce
    cpu.esp -= 4;
    sub_4807ce(app, cpu);
    // 0047a0ed  89459c                 -mov dword ptr [ebp - 0x64], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-100) /* -0x64 */) = cpu.eax;
    // 0047a0f0  f645d001               +test byte ptr [ebp - 0x30], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-48) /* -0x30 */) & 1 /*0x1*/));
    // 0047a0f4  7406                   -je 0x47a0fc
    if (cpu.flags.zf)
    {
        goto L_0x0047a0fc;
    }
    // 0047a0f6  0fb745d4               -movzx eax, word ptr [ebp - 0x2c]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 0047a0fa  eb03                   -jmp 0x47a0ff
    goto L_0x0047a0ff;
L_0x0047a0fc:
    // 0047a0fc  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0047a0fe  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a0ff:
    // 0047a0ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a100  ff759c                 -push dword ptr [ebp - 0x64]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    cpu.esp -= 4;
    // 0047a103  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a104  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a105  ff1568704800           -call dword ptr [0x487068]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747368) /* 0x487068 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a10b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a10c  e82faffeff             -call 0x465040
    cpu.esp -= 4;
    sub_465040(app, cpu);
    // 0047a111  8945a0                 -mov dword ptr [ebp - 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.eax;
    // 0047a114  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a115  e845e5ffff             -call 0x47865f
    cpu.esp -= 4;
    sub_47865f(app, cpu);
    // 0047a11a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047a11d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a11f  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047a121  894d98                 -mov dword ptr [ebp - 0x68], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-104) /* -0x68 */) = cpu.ecx;
    // 0047a124  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a125  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a126  e82b650000             -call 0x480656
    cpu.esp -= 4;
    sub_480656(app, cpu);
    // 0047a12b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a12c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a12d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a12e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a12e  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047a131  ff7598                 -push dword ptr [ebp - 0x68]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-104) /* -0x68 */);
    cpu.esp -= 4;
    // 0047a134  e837e5ffff             -call 0x478670
    cpu.esp -= 4;
    __exit(app, cpu);
    return __amsg_exit(app, cpu);
}

/* align: skip  */
void Application::__amsg_exit(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a139  833d34eb510001         +cmp dword ptr [0x51eb34], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368628) /* 0x51eb34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a140  7505                   -jne 0x47a147
    if (!cpu.flags.zf)
    {
        goto L_0x0047a147;
    }
    // 0047a142  e8176b0000             -call 0x480c5e
    cpu.esp -= 4;
    sub_480c5e(app, cpu);
L_0x0047a147:
    // 0047a147  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0047a14b  e8476b0000             -call 0x480c97
    cpu.esp -= 4;
    sub_480c97(app, cpu);
    // 0047a150  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 0047a155  ff15b03f4a00           -call dword ptr [0x4a3fb0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865968) /* 0x4a3fb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    NFS2_ASSERT(false);  // falls off the end of the routine
}

/* align: skip  */
void Application::sub_47a15e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a15e  833d34eb510001         +cmp dword ptr [0x51eb34], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368628) /* 0x51eb34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a165  7505                   -jne 0x47a16c
    if (!cpu.flags.zf)
    {
        goto L_0x0047a16c;
    }
    // 0047a167  e8f26a0000             -call 0x480c5e
    cpu.esp -= 4;
    sub_480c5e(app, cpu);
L_0x0047a16c:
    // 0047a16c  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0047a170  e8226b0000             -call 0x480c97
    cpu.esp -= 4;
    sub_480c97(app, cpu);
    // 0047a175  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a176  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 0047a17b  ff15c0714800           -call dword ptr [0x4871c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747712) /* 0x4871c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    NFS2_ASSERT(false);  // falls off the end of the routine
}

/* align: skip  */
void Application::sub_47a182(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a182  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a183  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a185  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a186  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a187  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a188  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a189  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a18c  83c00c                 +add eax, 0xc
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a18f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047a192  648b1d00000000         -mov ebx, dword ptr fs:[0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a199  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047a19b  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 0047a1a1  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a1a4  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a1a7  8b63fc                 -mov esp, dword ptr [ebx - 4]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0047a1aa  8b6dfc                 -mov ebp, dword ptr [ebp - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047a1ad  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip  */
void Application::sub_47a1b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a1b6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1b8  870424                 -xchg dword ptr [esp], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esp);
        app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
        cpu.eax = tmp;
    }
    // 0047a1bb  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip  */
void Application::sub_47a1bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a1bd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1bf  870424                 -xchg dword ptr [esp], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esp);
        app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
        cpu.eax = tmp;
    }
    // 0047a1c2  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip  */
void Application::sub_47a1c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a1c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a1c5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a1c7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a1c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a1c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a1ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a1cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a1cc  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a1d2  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047a1d5  c745fceca14700         -mov dword ptr [ebp - 4], 0x47a1ec
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 4694508 /*0x47a1ec*/;
    // 0047a1dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a1de  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a1e1  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047a1e4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a1e7  e8a4b40000             -call 0x485690
    cpu.esp -= 4;
    sub_485690(app, cpu);
    // 0047a1ec  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a1ef  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047a1f2  24fd                   -and al, 0xfd
    cpu.al &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047a1f4  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a1f7  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047a1fa  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a200  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047a203  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0047a205  64891d00000000         -mov dword ptr fs:[0], ebx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ebx;
    // 0047a20c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a20d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a20e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a20f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a210  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_47a213(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a213  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a214  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a216  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a219  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a21a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a21b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a21c  fc                     -cld 
    cpu.flags.df = 0;
    // 0047a21d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047a220  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a222  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a223  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a224  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a225  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047a228  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047a22b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047a22e  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a231  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a234  e8b16b0000             -call 0x480dea
    cpu.esp -= 4;
    sub_480dea(app, cpu);
    // 0047a239  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047a23c  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047a23f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a240  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a241  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a242  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047a245  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0047a247  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a248  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a249(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a249  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a24a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a24c  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047a24f  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a252  8365ec00               -and dword ptr [ebp - 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047a256  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a259  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047a25c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047a25f  c745f09da24700         -mov dword ptr [ebp - 0x10], 0x47a29d
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 4694685 /*0x47a29d*/;
    // 0047a266  40                     -inc eax
    (cpu.eax)++;
    // 0047a267  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0047a26a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047a26d  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a273  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0047a276  8d85ecffffff           -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047a27c  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 0047a282  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047a285  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a286  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047a289  e882730000             -call 0x481610
    cpu.esp -= 4;
    __CallSettingFrame_12(app, cpu);
    // 0047a28e  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a290  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047a293  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 0047a299  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a29b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a29c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a29d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a29d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a29e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a2a0  fc                     -cld 
    cpu.flags.df = 0;
    // 0047a2a1  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a2a4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a2a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a2a7  ff7010                 -push dword ptr [eax + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047a2aa  ff7008                 -push dword ptr [eax + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a2ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a2af  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047a2b2  ff700c                 -push dword ptr [eax + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a2b5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a2b8  e82d6b0000             -call 0x480dea
    cpu.esp -= 4;
    sub_480dea(app, cpu);
    // 0047a2bd  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047a2c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a2c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a2c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a2c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a2c3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a2c5  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047a2c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a2c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a2ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a2cb  8365d800               -and dword ptr [ebp - 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047a2cf  c745dc78a34700         -mov dword ptr [ebp - 0x24], 0x47a378
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = 4694904 /*0x47a378*/;
    // 0047a2d6  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047a2d9  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047a2dc  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a2df  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0047a2e2  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047a2e5  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0047a2e8  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047a2eb  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0047a2ee  8365f000               -and dword ptr [ebp - 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047a2f2  8365f400               -and dword ptr [ebp - 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047a2f6  8365f800               -and dword ptr [ebp - 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047a2fa  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047a2fe  c745f04aa34700         -mov dword ptr [ebp - 0x10], 0x47a34a
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 4694858 /*0x47a34a*/;
    // 0047a305  8965f4                 -mov dword ptr [ebp - 0xc], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esp;
    // 0047a308  896df8                 -mov dword ptr [ebp - 8], ebp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebp;
    // 0047a30b  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a311  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0047a314  8d85d8ffffff           -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047a31a  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 0047a320  c745cc01000000         -mov dword ptr [ebp - 0x34], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = 1 /*0x1*/;
    // 0047a327  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a32a  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 0047a32d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a330  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0047a333  8d45d0                 -lea eax, [ebp - 0x30]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0047a336  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a337  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a33a  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 0047a33c  e826110000             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 0047a341  ff5068                 -call dword ptr [eax + 0x68]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a344  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a345  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a346  8365cc00               -and dword ptr [ebp - 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047a34a  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a34e  7417                   -je 0x47a367
    if (cpu.flags.zf)
    {
        goto L_0x0047a367;
    }
    // 0047a350  648b1d00000000         -mov ebx, dword ptr fs:[0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a357  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047a359  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047a35c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0047a35e  64891d00000000         -mov dword ptr fs:[0], ebx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ebx;
    // 0047a365  eb09                   -jmp 0x47a370
    goto L_0x0047a370;
L_0x0047a367:
    // 0047a367  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047a36a  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
L_0x0047a370:
    // 0047a370  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0047a373  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a374  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a375  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a376  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a377  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a378(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a378  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a379  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a37b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a37c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a37d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a37e  fc                     -cld 
    cpu.flags.df = 0;
    // 0047a37f  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a382  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047a385  83e066                 -and eax, 0x66
    cpu.eax &= x86::reg32(x86::sreg32(102 /*0x66*/));
    // 0047a388  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a38a  740f                   -je 0x47a39b
    if (cpu.flags.zf)
    {
        goto L_0x0047a39b;
    }
    // 0047a38c  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a38f  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 0047a396  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a398  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a399  eb4d                   -jmp 0x47a3e8
    goto L_0x0047a3e8;
L_0x0047a39b:
    // 0047a39b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a39d  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a3a0  ff7014                 -push dword ptr [eax + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047a3a3  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a3a6  ff7010                 -push dword ptr [eax + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047a3a9  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a3ac  ff7008                 -push dword ptr [eax + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a3af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a3b1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047a3b4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a3b7  ff700c                 -push dword ptr [eax + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a3ba  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a3bd  e8286a0000             -call 0x480dea
    cpu.esp -= 4;
    sub_480dea(app, cpu);
    // 0047a3c2  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047a3c5  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a3c8  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a3cc  750b                   -jne 0x47a3d9
    if (!cpu.flags.zf)
    {
        goto L_0x0047a3d9;
    }
    // 0047a3ce  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a3d1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a3d4  e8ebfdffff             -call 0x47a1c4
    cpu.esp -= 4;
    sub_47a1c4(app, cpu);
L_0x0047a3d9:
    // 0047a3d9  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a3dc  8b631c                 -mov esp, dword ptr [ebx + 0x1c]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0047a3df  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0047a3e2  ff6318                 -jmp dword ptr [ebx + 0x18]
    return app->dynamic_call(app->getMemory<x86::reg32>(cpu.ebx + 24), cpu);
L_0x0047a3e8:
    // 0047a3e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a3ed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a3ed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a3ee  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a3f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a3f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a3f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a3f3  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 0047a3f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a3f8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a3fb  8b770c                 -mov esi, dword ptr [edi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0047a3fe  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047a401  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a403  897508                 -mov dword ptr [ebp + 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0047a406  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047a409  7c39                   -jl 0x47a444
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a444;
    }
L_0x0047a40b:
    // 0047a40b  83feff                 +cmp esi, -1
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
    // 0047a40e  7505                   -jne 0x47a415
    if (!cpu.flags.zf)
    {
        goto L_0x0047a415;
    }
    // 0047a410  e8a8720000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x0047a415:
    // 0047a415  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a418  4e                     -dec esi
    (cpu.esi)--;
    // 0047a419  8d04b6                 -lea eax, [esi + esi*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 4);
    // 0047a41c  394c8304               +cmp dword ptr [ebx + eax*4 + 4], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a420  8d0483                 -lea eax, [ebx + eax*4]
    cpu.eax = x86::reg32(cpu.ebx + cpu.eax * 4);
    // 0047a423  7d05                   -jge 0x47a42a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a42a;
    }
    // 0047a425  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a428  7e05                   -jle 0x47a42f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a42f;
    }
L_0x0047a42a:
    // 0047a42a  83feff                 +cmp esi, -1
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
    // 0047a42d  750c                   -jne 0x47a43b
    if (!cpu.flags.zf)
    {
        goto L_0x0047a43b;
    }
L_0x0047a42f:
    // 0047a42f  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a432  ff4d0c                 -dec dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))--;
    // 0047a435  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047a438  897508                 -mov dword ptr [ebp + 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x0047a43b:
    // 0047a43b  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 0047a43f  7dca                   -jge 0x47a40b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a40b;
    }
    // 0047a441  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0047a444:
    // 0047a444  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047a447  46                     -inc esi
    (cpu.esi)++;
    // 0047a448  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 0047a44a  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047a44d  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0047a44f  3b470c                 +cmp eax, dword ptr [edi + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a452  7704                   -ja 0x47a458
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047a458;
    }
    // 0047a454  3bf0                   +cmp esi, eax
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
    // 0047a456  7605                   -jbe 0x47a45d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047a45d;
    }
L_0x0047a458:
    // 0047a458  e860720000             -call 0x4816bd
    cpu.esp -= 4;
    sub_4816bd(app, cpu);
L_0x0047a45d:
    // 0047a45d  8d04b6                 -lea eax, [esi + esi*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 4);
    // 0047a460  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a461  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a462  8d0483                 -lea eax, [ebx + eax*4]
    cpu.eax = x86::reg32(cpu.ebx + cpu.eax * 4);
    // 0047a465  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a466  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a467  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a468(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a468  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a469  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a46b  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0047a46d  68f87c4800             -push 0x487cf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750584 /*0x487cf8*/;
    cpu.esp -= 4;
    // 0047a472  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0047a477  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047a47d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a47e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0047a485  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a489  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a48a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a48b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a48e  0faf750c               -imul esi, dword ptr [ebp + 0xc]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 0047a492  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047a495  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 0047a498  83fee0                 +cmp esi, -0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-32 /*-0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a49b  7714                   -ja 0x47a4b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047a4b1;
    }
    // 0047a49d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a49f  3bf3                   +cmp esi, ebx
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
    // 0047a4a1  7503                   -jne 0x47a4a6
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4a6;
    }
    // 0047a4a3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a4a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a4a6:
    // 0047a4a6  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047a4a9  83e6f0                 +and esi, 0xfffffff0
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/))));
    // 0047a4ac  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047a4af  eb02                   -jmp 0x47a4b3
    goto L_0x0047a4b3;
L_0x0047a4b1:
    // 0047a4b1  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047a4b3:
    // 0047a4b3  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0047a4b6  83fee0                 +cmp esi, -0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-32 /*-0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a4b9  0f87a8000000           -ja 0x47a567
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047a567;
    }
    // 0047a4bf  a1f01f5200             -mov eax, dword ptr [0x521ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382128) /* 0x521ff0 */);
    // 0047a4c4  83f803                 +cmp eax, 3
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
    // 0047a4c7  7541                   -jne 0x47a50a
    if (!cpu.flags.zf)
    {
        goto L_0x0047a50a;
    }
    // 0047a4c9  8b7de4                 -mov edi, dword ptr [ebp - 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0047a4cc  3b3d0c205200           +cmp edi, dword ptr [0x52200c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382156) /* 0x52200c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a4d2  777c                   -ja 0x47a550
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047a550;
    }
    // 0047a4d4  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047a4d6  e8ee250000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047a4db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a4dc  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0047a4df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a4e0  e843170000             -call 0x47bc28
    cpu.esp -= 4;
    sub_47bc28(app, cpu);
    // 0047a4e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a4e6  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047a4e9  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047a4ed  e80f000000             -call 0x47a501
    cpu.esp -= 4;
    sub_47a501(app, cpu);
    // 0047a4f2  395de0                 +cmp dword ptr [ebp - 0x20], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a4f5  745e                   -je 0x47a555
    if (cpu.flags.zf)
    {
        goto L_0x0047a555;
    }
    // 0047a4f7  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047a4fa  eb48                   -jmp 0x47a544
    goto L_0x0047a544;
L_0x0047a50a:
    // 0047a50a  83f802                 +cmp eax, 2
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
    // 0047a50d  7541                   -jne 0x47a550
    if (!cpu.flags.zf)
    {
        goto L_0x0047a550;
    }
    // 0047a50f  3b3534604a00           +cmp esi, dword ptr [0x4a6034]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4874292) /* 0x4a6034 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a515  7739                   -ja 0x47a550
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047a550;
    }
    // 0047a517  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047a519  e8ab250000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047a51e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a51f  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047a526  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a528  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047a52b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a52c  e89a210000             -call 0x47c6cb
    cpu.esp -= 4;
    sub_47c6cb(app, cpu);
    // 0047a531  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a532  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047a535  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047a539  e84c000000             -call 0x47a58a
    cpu.esp -= 4;
    sub_47a58a(app, cpu);
    // 0047a53e  395de0                 +cmp dword ptr [ebp - 0x20], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a541  7412                   -je 0x47a555
    if (cpu.flags.zf)
    {
        goto L_0x0047a555;
    }
    // 0047a543  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0047a544:
    // 0047a544  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a545  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0047a548  e8d3710000             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 0047a54d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0047a550:
    // 0047a550  395de0                 +cmp dword ptr [ebp - 0x20], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a553  753e                   -jne 0x47a593
    if (!cpu.flags.zf)
    {
        goto L_0x0047a593;
    }
L_0x0047a555:
    // 0047a555  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a556  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0047a558  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047a55e  ff15e0704800           -call dword ptr [0x4870e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747488) /* 0x4870e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a564  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x0047a567:
    // 0047a567  395de0                 +cmp dword ptr [ebp - 0x20], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a56a  7527                   -jne 0x47a593
    if (!cpu.flags.zf)
    {
        goto L_0x0047a593;
    }
    // 0047a56c  391daceb5100           +cmp dword ptr [0x51ebac], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368748) /* 0x51ebac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a572  741f                   -je 0x47a593
    if (cpu.flags.zf)
    {
        goto L_0x0047a593;
    }
    // 0047a574  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a575  e8c5250000             -call 0x47cb3f
    cpu.esp -= 4;
    sub_47cb3f(app, cpu);
    // 0047a57a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a57b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a57d  0f8530ffffff           -jne 0x47a4b3
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4b3;
    }
    // 0047a583  eb11                   -jmp 0x47a596
    goto L_0x0047a596;
L_0x0047a593:
    // 0047a593  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
L_0x0047a596:
    // 0047a596  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a599  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047a5a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5a3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a4fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a4fc  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a4fe  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    return sub_47a501(app, cpu);
}

/* align: skip  */
void Application::sub_47a501(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a501  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047a503  e822260000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047a508  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a509  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a585(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a585  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a587  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    return sub_47a58a(app, cpu);
}

/* align: skip  */
void Application::sub_47a58a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a58a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047a58c  e899250000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047a591  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a592  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a5a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a5a5  6800000300             -push 0x30000
    app->getMemory<x86::reg32>(cpu.esp-4) = 196608 /*0x30000*/;
    cpu.esp -= 4;
    // 0047a5aa  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 0047a5af  e8f9710000             -call 0x4817ad
    cpu.esp -= 4;
    sub_4817ad(app, cpu);
    // 0047a5b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a5b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a5b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a5b8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a5ba  83ec18                 +sub esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a5bd  dd05187d4800           +fld qword ptr [0x487d18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4750616) /* 0x487d18 */)));
    // 0047a5c3  dd5df8                 +fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047a5c6  dd05107d4800           +fld qword ptr [0x487d10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4750608) /* 0x487d10 */)));
    // 0047a5cc  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047a5cf  dd45f0                 +fld qword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0047a5d2  dc75f8                 +fdiv qword ptr [ebp - 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 0047a5d5  dc4df8                 +fmul qword ptr [ebp - 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 0047a5d8  dc6df0                 +fsubr qword ptr [ebp - 0x10]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) - cpu.fpu.st(0);
    // 0047a5db  dd5de8                 +fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047a5de  dd45e8                 +fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0047a5e1  dc1de07c4800           +fcomp qword ptr [0x487ce0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750560) /* 0x487ce0 */)));
    cpu.fpu.pop();
    // 0047a5e7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047a5e9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047a5ea  7605                   -jbe 0x47a5f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047a5f1;
    }
    // 0047a5ec  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a5ee  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5ef  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a5f1:
    // 0047a5f1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a5f3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a5f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a5f5  683c7d4800             -push 0x487d3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750652 /*0x487d3c*/;
    cpu.esp -= 4;
    // 0047a5fa  ff1568704800           -call dword ptr [0x487068]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747368) /* 0x487068 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a600  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a602  7415                   -je 0x47a619
    if (cpu.flags.zf)
    {
        goto L_0x0047a619;
    }
    // 0047a604  68207d4800             -push 0x487d20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750624 /*0x487d20*/;
    cpu.esp -= 4;
    // 0047a609  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a60a  ff1584704800           -call dword ptr [0x487084]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747396) /* 0x487084 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a610  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a612  7405                   -je 0x47a619
    if (cpu.flags.zf)
    {
        goto L_0x0047a619;
    }
    // 0047a614  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a616  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047a618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a619:
    // 0047a619  e999ffffff             -jmp 0x47a5b7
    return sub_47a5b7(app, cpu);
}

/* align: skip  */
void Application::sub_47a61e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a61e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a61f  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047a623  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0047a626  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a627  e871ceffff             -call 0x47749d
    cpu.esp -= 4;
    sub_47749d(app, cpu);
    // 0047a62c  83f865                 +cmp eax, 0x65
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
    // 0047a62f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a630  742c                   -je 0x47a65e
    if (cpu.flags.zf)
    {
        goto L_0x0047a65e;
    }
L_0x0047a632:
    // 0047a632  46                     -inc esi
    (cpu.esi)++;
    // 0047a633  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 0047a63a  7e0f                   -jle 0x47a64b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a64b;
    }
    // 0047a63c  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0047a63f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047a641  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a642  e8422c0000             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 0047a647  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a648  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a649  eb0f                   -jmp 0x47a65a
    goto L_0x0047a65a;
L_0x0047a64b:
    // 0047a64b  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0047a64e  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047a654  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0047a657  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047a65a:
    // 0047a65a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a65c  75d4                   -jne 0x47a632
    if (!cpu.flags.zf)
    {
        goto L_0x0047a632;
    }
L_0x0047a65e:
    // 0047a65e  8a0d1c644a00           -mov cl, byte ptr [0x4a641c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */);
    // 0047a664  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047a666  880e                   -mov byte ptr [esi], cl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.cl;
    // 0047a668  46                     -inc esi
    (cpu.esi)++;
L_0x0047a669:
    // 0047a669  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0047a66b  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0047a66d  8ac1                   -mov al, cl
    cpu.al = cpu.cl;
    // 0047a66f  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0047a671  46                     -inc esi
    (cpu.esi)++;
    // 0047a672  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047a674  75f3                   -jne 0x47a669
    if (!cpu.flags.zf)
    {
        goto L_0x0047a669;
    }
    // 0047a676  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a677  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a678  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047a67c  8a151c644a00           -mov dl, byte ptr [0x4a641c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */);
    // 0047a682  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047a684  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047a686  740c                   -je 0x47a694
    if (cpu.flags.zf)
    {
        goto L_0x0047a694;
    }
L_0x0047a688:
    // 0047a688  3aca                   +cmp cl, dl
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
    // 0047a68a  7408                   -je 0x47a694
    if (cpu.flags.zf)
    {
        goto L_0x0047a694;
    }
    // 0047a68c  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047a68f  40                     -inc eax
    (cpu.eax)++;
    // 0047a690  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047a692  75f4                   -jne 0x47a688
    if (!cpu.flags.zf)
    {
        goto L_0x0047a688;
    }
L_0x0047a694:
    // 0047a694  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047a696  40                     -inc eax
    (cpu.eax)++;
    // 0047a697  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047a699  742a                   -je 0x47a6c5
    if (cpu.flags.zf)
    {
        goto L_0x0047a6c5;
    }
L_0x0047a69b:
    // 0047a69b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047a69d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047a69f  740d                   -je 0x47a6ae
    if (cpu.flags.zf)
    {
        goto L_0x0047a6ae;
    }
    // 0047a6a1  80f965                 +cmp cl, 0x65
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(101 /*0x65*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a6a4  7408                   -je 0x47a6ae
    if (cpu.flags.zf)
    {
        goto L_0x0047a6ae;
    }
    // 0047a6a6  80f945                 +cmp cl, 0x45
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a6a9  7403                   -je 0x47a6ae
    if (cpu.flags.zf)
    {
        goto L_0x0047a6ae;
    }
    // 0047a6ab  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047a6ac  ebed                   -jmp 0x47a69b
    goto L_0x0047a69b;
L_0x0047a6ae:
    // 0047a6ae  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0047a6b0:
    // 0047a6b0  48                     -dec eax
    (cpu.eax)--;
    // 0047a6b1  803830                 +cmp byte ptr [eax], 0x30
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
    // 0047a6b4  74fa                   -je 0x47a6b0
    if (cpu.flags.zf)
    {
        goto L_0x0047a6b0;
    }
    // 0047a6b6  3810                   +cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a6b8  7501                   -jne 0x47a6bb
    if (!cpu.flags.zf)
    {
        goto L_0x0047a6bb;
    }
    // 0047a6ba  48                     -dec eax
    (cpu.eax)--;
L_0x0047a6bb:
    // 0047a6bb  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047a6bd  40                     -inc eax
    (cpu.eax)++;
    // 0047a6be  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a6bf  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047a6c1  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0047a6c3  75f6                   -jne 0x47a6bb
    if (!cpu.flags.zf)
    {
        goto L_0x0047a6bb;
    }
L_0x0047a6c5:
    // 0047a6c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a6c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a6c6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047a6ca  dd00                   +fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 0047a6cc  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 0047a6d2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047a6d4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047a6d5  7204                   -jb 0x47a6db
    if (cpu.flags.cf)
    {
        goto L_0x0047a6db;
    }
    // 0047a6d7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a6d9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a6db:
    // 0047a6db  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a6dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__fassign(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a6de  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a6df  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a6e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a6e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a6e3  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0047a6e7  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047a6ea  741b                   -je 0x47a707
    if (cpu.flags.zf)
    {
        goto L_0x0047a707;
    }
    // 0047a6ec  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047a6ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a6f0  e87b750000             -call 0x481c70
    cpu.esp -= 4;
    sub_481c70(app, cpu);
    // 0047a6f5  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a6f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6fa  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047a6fd  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047a6ff  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047a702  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047a705  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a706  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a707:
    // 0047a707  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a70a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a70b  e88d750000             -call 0x481c9d
    cpu.esp -= 4;
    sub_481c9d(app, cpu);
    // 0047a710  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a713  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a714  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a715  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a718  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047a71a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a71b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a71c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a71c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a71d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a71f  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047a722  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047a725  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a726  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a727  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a72a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a72b  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a72e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a72f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a730  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 0047a732  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047a735  e807760000             -call 0x481d41
    cpu.esp -= 4;
    sub_481d41(app, cpu);
    // 0047a73a  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a73d  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a740  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a741  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a744  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047a747  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a748  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a74a  837df02d               +cmp dword ptr [ebp - 0x10], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a74e  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0047a751  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a753  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047a755  0f9fc1                 -setg cl
    cpu.cl = (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of));
    // 0047a758  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a75a  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a75c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a75d  e868750000             -call 0x481cca
    cpu.esp -= 4;
    sub_481cca(app, cpu);
    // 0047a762  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a765  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a767  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a768  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047a76b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a76c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a76f  e809000000             -call 0x47a77d
    cpu.esp -= 4;
    sub_47a77d(app, cpu);
    // 0047a774  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a777  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047a77a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a77b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a77c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a77d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a77d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a77e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a781  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a783  385d18                 +cmp byte ptr [ebp + 0x18], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a786  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a787  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047a78a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a78b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a78e  741b                   -je 0x47a7ab
    if (cpu.flags.zf)
    {
        goto L_0x0047a7ab;
    }
    // 0047a790  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a792  395d0c                 +cmp dword ptr [ebp + 0xc], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a795  0f9fc0                 -setg al
    cpu.al = (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of));
    // 0047a798  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a799  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a79b  833e2d                 +cmp dword ptr [esi], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a79e  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0047a7a1  03c7                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047a7a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a7a4  e876020000             -call 0x47aa1f
    cpu.esp -= 4;
    sub_47aa1f(app, cpu);
    // 0047a7a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a7aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a7ab:
    // 0047a7ab  833e2d                 +cmp dword ptr [esi], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a7ae  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047a7b0  7506                   -jne 0x47a7b8
    if (!cpu.flags.zf)
    {
        goto L_0x0047a7b8;
    }
    // 0047a7b2  c6072d                 -mov byte ptr [edi], 0x2d
    app->getMemory<x86::reg8>(cpu.edi) = 45 /*0x2d*/;
    // 0047a7b5  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
L_0x0047a7b8:
    // 0047a7b8  395d0c                 +cmp dword ptr [ebp + 0xc], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a7bb  7e12                   -jle 0x47a7cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a7cf;
    }
    // 0047a7bd  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047a7c0  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047a7c3  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0047a7c5  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a7c7  8a0d1c644a00           -mov cl, byte ptr [0x4a641c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */);
    // 0047a7cd  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
L_0x0047a7cf:
    // 0047a7cf  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a7d1  385d18                 +cmp byte ptr [ebp + 0x18], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a7d4  68487d4800             -push 0x487d48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750664 /*0x487d48*/;
    cpu.esp -= 4;
    // 0047a7d9  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 0047a7dc  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a7de  034d0c                 -add ecx, dword ptr [ebp + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047a7e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a7e2  e8494a0000             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 0047a7e7  395d10                 +cmp dword ptr [ebp + 0x10], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a7ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a7eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a7ec  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a7ee  7403                   -je 0x47a7f3
    if (cpu.flags.zf)
    {
        goto L_0x0047a7f3;
    }
    // 0047a7f0  c60145                 -mov byte ptr [ecx], 0x45
    app->getMemory<x86::reg8>(cpu.ecx) = 69 /*0x45*/;
L_0x0047a7f3:
    // 0047a7f3  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047a7f6  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a7f7  803830                 +cmp byte ptr [eax], 0x30
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
    // 0047a7fa  743c                   -je 0x47a838
    if (cpu.flags.zf)
    {
        goto L_0x0047a838;
    }
    // 0047a7fc  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047a7ff  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047a800  7905                   -jns 0x47a807
    if (!cpu.flags.sf)
    {
        goto L_0x0047a807;
    }
    // 0047a802  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0047a804  c6012d                 -mov byte ptr [ecx], 0x2d
    app->getMemory<x86::reg8>(cpu.ecx) = 45 /*0x2d*/;
L_0x0047a807:
    // 0047a807  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a808  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a80b  7c11                   -jl 0x47a81e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a81e;
    }
    // 0047a80d  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a80f  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 0047a811  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047a812  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a813  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047a815  0001                   -add byte ptr [ecx], al
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047a817  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a819  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047a81a  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047a81c  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0047a81e:
    // 0047a81e  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a81f  83fb0a                 +cmp ebx, 0xa
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
    // 0047a822  7c11                   -jl 0x47a835
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a835;
    }
    // 0047a824  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a826  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0047a828  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047a829  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a82a  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047a82c  0001                   -add byte ptr [ecx], al
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047a82e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a830  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047a831  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047a833  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0047a835:
    // 0047a835  005901                 -add byte ptr [ecx + 1], bl
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */)) += x86::reg8(x86::sreg8(cpu.bl));
L_0x0047a838:
    // 0047a838  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047a83a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a83b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a83c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a83d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a83e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a83f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a83f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a840  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a842  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047a845  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047a848  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a849  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a84a  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a84d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a84e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a852  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a853  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 0047a855  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047a858  e8e4740000             -call 0x481d41
    cpu.esp -= 4;
    sub_481d41(app, cpu);
    // 0047a85d  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a860  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a863  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a864  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047a867  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047a869  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a86a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a86c  837df02d               +cmp dword ptr [ebp - 0x10], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a870  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0047a873  03450c                 -add eax, dword ptr [ebp + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047a876  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a877  e84e740000             -call 0x481cca
    cpu.esp -= 4;
    sub_481cca(app, cpu);
    // 0047a87c  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a87f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a881  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a882  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a883  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a886  e809000000             -call 0x47a894
    cpu.esp -= 4;
    sub_47a894(app, cpu);
    // 0047a88b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a88e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0047a891  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a892  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a893  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a894(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a894  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a895  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a897  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a898  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a899  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a89c  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a89f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a8a0  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047a8a3  48                     -dec eax
    (cpu.eax)--;
    // 0047a8a4  807d1400               +cmp byte ptr [ebp + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a8a8  741a                   -je 0x47a8c4
    if (cpu.flags.zf)
    {
        goto L_0x0047a8c4;
    }
    // 0047a8aa  3b450c                 +cmp eax, dword ptr [ebp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a8ad  7515                   -jne 0x47a8c4
    if (!cpu.flags.zf)
    {
        goto L_0x0047a8c4;
    }
    // 0047a8af  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a8b1  833e2d                 +cmp dword ptr [esi], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a8b4  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 0047a8b7  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a8b9  03cb                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a8bb  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a8bd  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 0047a8c0  80600100               -and byte ptr [eax + 1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0047a8c4:
    // 0047a8c4  833e2d                 +cmp dword ptr [esi], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a8c7  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047a8c9  7506                   -jne 0x47a8d1
    if (!cpu.flags.zf)
    {
        goto L_0x0047a8d1;
    }
    // 0047a8cb  c6032d                 -mov byte ptr [ebx], 0x2d
    app->getMemory<x86::reg8>(cpu.ebx) = 45 /*0x2d*/;
    // 0047a8ce  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x0047a8d1:
    // 0047a8d1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047a8d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a8d6  7f10                   -jg 0x47a8e8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047a8e8;
    }
    // 0047a8d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a8da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a8db  e83f010000             -call 0x47aa1f
    cpu.esp -= 4;
    sub_47aa1f(app, cpu);
    // 0047a8e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8e1  c60730                 -mov byte ptr [edi], 0x30
    app->getMemory<x86::reg8>(cpu.edi) = 48 /*0x30*/;
    // 0047a8e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8e5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047a8e6  eb02                   -jmp 0x47a8ea
    goto L_0x0047a8ea;
L_0x0047a8e8:
    // 0047a8e8  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0047a8ea:
    // 0047a8ea  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 0047a8ee  7e44                   -jle 0x47a934
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a934;
    }
    // 0047a8f0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a8f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a8f3  e827010000             -call 0x47aa1f
    cpu.esp -= 4;
    sub_47aa1f(app, cpu);
    // 0047a8f8  a01c644a00             -mov al, byte ptr [0x4a641c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4875292) /* 0x4a641c */);
    // 0047a8fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8fe  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047a900  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047a903  47                     -inc edi
    (cpu.edi)++;
    // 0047a904  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a905  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047a907  7d2b                   -jge 0x47a934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a934;
    }
    // 0047a909  807d1400               +cmp byte ptr [ebp + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a90d  7404                   -je 0x47a913
    if (cpu.flags.zf)
    {
        goto L_0x0047a913;
    }
    // 0047a90f  f7de                   +neg esi
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
    // 0047a911  eb07                   -jmp 0x47a91a
    goto L_0x0047a91a;
L_0x0047a913:
    // 0047a913  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0047a915  39750c                 +cmp dword ptr [ebp + 0xc], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a918  7c03                   -jl 0x47a91d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a91d;
    }
L_0x0047a91a:
    // 0047a91a  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x0047a91d:
    // 0047a91d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a920  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a921  e8f9000000             -call 0x47aa1f
    cpu.esp -= 4;
    sub_47aa1f(app, cpu);
    // 0047a926  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a929  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0047a92b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a92c  e8ef6d0000             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 0047a931  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0047a934:
    // 0047a934  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a935  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a937  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a938  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a939  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a93a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a93b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a93b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a93c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a93e  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047a941  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a942  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a943  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0047a946  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a947  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a948  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a94b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a94c  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047a94f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a951  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 0047a953  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047a956  e8e6730000             -call 0x481d41
    cpu.esp -= 4;
    sub_481d41(app, cpu);
    // 0047a95b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047a95e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047a961  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0047a964  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a966  837df02d               +cmp dword ptr [ebp - 0x10], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a96a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0047a96d  03450c                 -add eax, dword ptr [ebp + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0047a970  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047a972  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a975  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a976  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a977  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a978  e84d730000             -call 0x481cca
    cpu.esp -= 4;
    sub_481cca(app, cpu);
    // 0047a97d  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047a980  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047a983  48                     -dec eax
    (cpu.eax)--;
    // 0047a984  3bf0                   +cmp esi, eax
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
    // 0047a986  0f9cc1                 -setl cl
    cpu.cl = (cpu.flags.sf != cpu.flags.of);
    // 0047a989  83f8fc                 +cmp eax, -4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a98c  7c26                   -jl 0x47a9b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a9b4;
    }
    // 0047a98e  3bc3                   +cmp eax, ebx
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
    // 0047a990  7d22                   -jge 0x47a9b4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a9b4;
    }
    // 0047a992  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047a994  740a                   -je 0x47a9a0
    if (cpu.flags.zf)
    {
        goto L_0x0047a9a0;
    }
L_0x0047a996:
    // 0047a996  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0047a998  47                     -inc edi
    (cpu.edi)++;
    // 0047a999  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047a99b  75f9                   -jne 0x47a996
    if (!cpu.flags.zf)
    {
        goto L_0x0047a996;
    }
    // 0047a99d  2047fe                 -and byte ptr [edi - 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */) &= x86::reg8(x86::sreg8(cpu.al));
L_0x0047a9a0:
    // 0047a9a0  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a9a3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a9a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a9a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a9a7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a9aa  e8e5feffff             -call 0x47a894
    cpu.esp -= 4;
    sub_47a894(app, cpu);
    // 0047a9af  83c410                 +add esp, 0x10
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
    // 0047a9b2  eb15                   -jmp 0x47a9c9
    goto L_0x0047a9c9;
L_0x0047a9b4:
    // 0047a9b4  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047a9b7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047a9b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a9ba  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047a9bd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a9be  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a9c1  e8b7fdffff             -call 0x47a77d
    cpu.esp -= 4;
    sub_47a77d(app, cpu);
    // 0047a9c6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0047a9c9:
    // 0047a9c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9cc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__cfltcvt(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a9ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a9cf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047a9d1  837d1065               +cmp dword ptr [ebp + 0x10], 0x65
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a9d5  7432                   -je 0x47aa09
    if (cpu.flags.zf)
    {
        goto L_0x0047aa09;
    }
    // 0047a9d7  837d1045               +cmp dword ptr [ebp + 0x10], 0x45
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a9db  742c                   -je 0x47aa09
    if (cpu.flags.zf)
    {
        goto L_0x0047aa09;
    }
    // 0047a9dd  837d1066               +cmp dword ptr [ebp + 0x10], 0x66
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a9e1  7513                   -jne 0x47a9f6
    if (!cpu.flags.zf)
    {
        goto L_0x0047a9f6;
    }
    // 0047a9e3  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047a9e6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a9e9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047a9ec  e84efeffff             -call 0x47a83f
    cpu.esp -= 4;
    sub_47a83f(app, cpu);
    // 0047a9f1  83c40c                 +add esp, 0xc
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
    // 0047a9f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a9f6:
    // 0047a9f6  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047a9f9  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047a9fc  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047a9ff  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047aa02  e834ffffff             -call 0x47a93b
    cpu.esp -= 4;
    sub_47a93b(app, cpu);
    // 0047aa07  eb11                   -jmp 0x47aa1a
    goto L_0x0047aa1a;
L_0x0047aa09:
    // 0047aa09  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047aa0c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047aa0f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047aa12  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047aa15  e802fdffff             -call 0x47a71c
    cpu.esp -= 4;
    sub_47a71c(app, cpu);
L_0x0047aa1a:
    // 0047aa1a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047aa1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47aa1f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aa1f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047aa20  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047aa24  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047aa26  741a                   -je 0x47aa42
    if (cpu.flags.zf)
    {
        goto L_0x0047aa42;
    }
    // 0047aa28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa29  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047aa2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa2e  e8ad330000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047aa33  40                     -inc eax
    (cpu.eax)++;
    // 0047aa34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047aa35  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa36  03f7                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047aa38  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa39  e822740000             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 0047aa3e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047aa41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047aa42:
    // 0047aa42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47aa44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aa44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa45  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047aa49  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047aa4c  e84d770000             -call 0x48219e
    cpu.esp -= 4;
    sub_48219e(app, cpu);
    // 0047aa51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047aa53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa54  7477                   -je 0x47aacd
    if (cpu.flags.zf)
    {
        goto L_0x0047aacd;
    }
    // 0047aa56  81fe283d4a00           +cmp esi, 0x4a3d28
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865320 /*0x4a3d28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aa5c  7504                   -jne 0x47aa62
    if (!cpu.flags.zf)
    {
        goto L_0x0047aa62;
    }
    // 0047aa5e  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047aa60  eb0b                   -jmp 0x47aa6d
    goto L_0x0047aa6d;
L_0x0047aa62:
    // 0047aa62  81fe483d4a00           +cmp esi, 0x4a3d48
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865352 /*0x4a3d48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aa68  7563                   -jne 0x47aacd
    if (!cpu.flags.zf)
    {
        goto L_0x0047aacd;
    }
    // 0047aa6a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047aa6c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047aa6d:
    // 0047aa6d  ff05e4ea5100           -inc dword ptr [0x51eae4]
    (app->getMemory<x86::reg32>(x86::reg32(5368548) /* 0x51eae4 */))++;
    // 0047aa73  66f7460c0c01           +test word ptr [esi + 0xc], 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 268 /*0x10c*/));
    // 0047aa79  7552                   -jne 0x47aacd
    if (!cpu.flags.zf)
    {
        goto L_0x0047aacd;
    }
    // 0047aa7b  833c8538eb510000       +cmp dword ptr [eax*4 + 0x51eb38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368632) /* 0x51eb38 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aa83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047aa84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047aa85  8d3c8538eb5100         -lea edi, [eax*4 + 0x51eb38]
    cpu.edi = x86::reg32(x86::reg32(5368632) /* 0x51eb38 */ + cpu.eax * 4);
    // 0047aa8c  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0047aa91  7520                   -jne 0x47aab3
    if (!cpu.flags.zf)
    {
        goto L_0x0047aab3;
    }
    // 0047aa93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047aa94  e8e1c7ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047aa99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047aa9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa9c  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047aa9e  7513                   -jne 0x47aab3
    if (!cpu.flags.zf)
    {
        goto L_0x0047aab3;
    }
    // 0047aaa0  8d4614                 -lea eax, [esi + 0x14]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047aaa3  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047aaa5  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047aaa8  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047aaaa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aaab  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047aaae  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047aab1  eb0d                   -jmp 0x47aac0
    goto L_0x0047aac0;
L_0x0047aab3:
    // 0047aab3  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0047aab5  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047aab8  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0047aabb  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0047aabd  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0047aac0:
    // 0047aac0  66814e0c0211           -or word ptr [esi + 0xc], 0x1102
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg16(x86::sreg16(4354 /*0x1102*/));
    // 0047aac6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047aac8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aac9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aaca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aacb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aacc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aacd:
    // 0047aacd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047aacf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aad0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47aad1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aad1  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aad6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aad7  7420                   -je 0x47aaf9
    if (cpu.flags.zf)
    {
        goto L_0x0047aaf9;
    }
    // 0047aad9  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047aadd  f6460d10               +test byte ptr [esi + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0047aae1  7416                   -je 0x47aaf9
    if (cpu.flags.zf)
    {
        goto L_0x0047aaf9;
    }
    // 0047aae3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aae4  e8dbceffff             -call 0x4779c4
    cpu.esp -= 4;
    sub_4779c4(app, cpu);
    // 0047aae9  80660dee               -and byte ptr [esi + 0xd], 0xee
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) &= x86::reg8(x86::sreg8(238 /*0xee*/));
    // 0047aaed  83661800               -and dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047aaf1  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047aaf4  83660800               -and dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047aaf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047aaf9:
    // 0047aaf9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aafa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47aafb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047aafb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047aafc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047aafe  81ec48020000           -sub esp, 0x248
    (cpu.esp) -= x86::reg32(x86::sreg32(584 /*0x248*/));
    // 0047ab04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ab05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ab06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ab07  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ab0a  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047ab0c  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0047ab0e  47                     -inc edi
    (cpu.edi)++;
    // 0047ab0f  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047ab11  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 0047ab14  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 0047ab17  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0047ab1a  0f84f4060000           -je 0x47b214
    if (cpu.flags.zf)
    {
        goto L_0x0047b214;
    }
    // 0047ab20  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047ab23  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047ab25  eb08                   -jmp 0x47ab2f
    goto L_0x0047ab2f;
L_0x0047ab27:
    // 0047ab27  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047ab2a  8b75d0                 -mov esi, dword ptr [ebp - 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0047ab2d  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047ab2f:
    // 0047ab2f  3955ec                 +cmp dword ptr [ebp - 0x14], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ab32  0f8cdc060000           -jl 0x47b214
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047b214;
    }
    // 0047ab38  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ab3b  7c13                   -jl 0x47ab50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ab50;
    }
    // 0047ab3d  80fb78                 +cmp bl, 0x78
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
    // 0047ab40  7f0e                   -jg 0x47ab50
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ab50;
    }
    // 0047ab42  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047ab45  8a80307d4800           -mov al, byte ptr [eax + 0x487d30]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4750640) /* 0x487d30 */);
    // 0047ab4b  83e00f                 +and eax, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/))));
    // 0047ab4e  eb02                   -jmp 0x47ab52
    goto L_0x0047ab52;
L_0x0047ab50:
    // 0047ab50  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047ab52:
    // 0047ab52  0fbe84c6507d4800       -movsx eax, byte ptr [esi + eax*8 + 0x487d50]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4750672) /* 0x487d50 */ + cpu.eax * 8)));
    // 0047ab5a  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047ab5d  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ab60  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 0047ab63  0f879a060000           -ja 0x47b203
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047b203;
    }
    // 0047ab69  ff24851cb24700         -jmp dword ptr [eax*4 + 0x47b21c]
    cpu.ip = app->getMemory<x86::reg32>(4698652 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047ab70:
    // 0047ab70  834df0ff               +or dword ptr [ebp - 0x10], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047ab74  8955cc                 -mov dword ptr [ebp - 0x34], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.edx;
    // 0047ab77  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
    // 0047ab7a  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 0047ab7d  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 0047ab80  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0047ab83  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0047ab86  e978060000             -jmp 0x47b203
    goto L_0x0047b203;
  case 0x0047ab8b:
    // 0047ab8b  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047ab8e  83e820                 +sub eax, 0x20
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ab91  743b                   -je 0x47abce
    if (cpu.flags.zf)
    {
        goto L_0x0047abce;
    }
    // 0047ab93  83e803                 +sub eax, 3
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
    // 0047ab96  742d                   -je 0x47abc5
    if (cpu.flags.zf)
    {
        goto L_0x0047abc5;
    }
    // 0047ab98  83e808                 +sub eax, 8
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
    // 0047ab9b  741f                   -je 0x47abbc
    if (cpu.flags.zf)
    {
        goto L_0x0047abbc;
    }
    // 0047ab9d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ab9e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ab9f  7412                   -je 0x47abb3
    if (cpu.flags.zf)
    {
        goto L_0x0047abb3;
    }
    // 0047aba1  83e803                 +sub eax, 3
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
    // 0047aba4  0f8559060000           -jne 0x47b203
    if (!cpu.flags.zf)
    {
        goto L_0x0047b203;
    }
    // 0047abaa  834dfc08               +or dword ptr [ebp - 4], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(8 /*0x8*/))));
    // 0047abae  e950060000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047abb3:
    // 0047abb3  834dfc04               +or dword ptr [ebp - 4], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0047abb7  e947060000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047abbc:
    // 0047abbc  834dfc01               +or dword ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0047abc0  e93e060000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047abc5:
    // 0047abc5  804dfc80               +or byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 0047abc9  e935060000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047abce:
    // 0047abce  834dfc02               +or dword ptr [ebp - 4], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0047abd2  e92c060000             -jmp 0x47b203
    goto L_0x0047b203;
  case 0x0047abd7:
    // 0047abd7  80fb2a                 +cmp bl, 0x2a
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047abda  7523                   -jne 0x47abff
    if (!cpu.flags.zf)
    {
        goto L_0x0047abff;
    }
    // 0047abdc  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047abdf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047abe0  e88e410000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047abe5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047abe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047abe8  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047abeb  0f8d12060000           -jge 0x47b203
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047b203;
    }
    // 0047abf1  834dfc04               -or dword ptr [ebp - 4], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047abf5  f7d8                   +neg eax
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
L_0x0047abf7:
    // 0047abf7  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047abfa  e904060000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047abff:
    // 0047abff  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047ac02  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047ac05  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047ac08  8d4441d0               -lea eax, [ecx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0047ac0c  ebe9                   -jmp 0x47abf7
    goto L_0x0047abf7;
  case 0x0047ac0e:
    // 0047ac0e  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0047ac11  e9ed050000             -jmp 0x47b203
    goto L_0x0047b203;
  case 0x0047ac16:
    // 0047ac16  80fb2a                 +cmp bl, 0x2a
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac19  751e                   -jne 0x47ac39
    if (!cpu.flags.zf)
    {
        goto L_0x0047ac39;
    }
    // 0047ac1b  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ac1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ac1f  e84f410000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047ac24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ac26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac27  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0047ac2a  0f8dd3050000           -jge 0x47b203
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047b203;
    }
    // 0047ac30  834df0ff               +or dword ptr [ebp - 0x10], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047ac34  e9ca050000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047ac39:
    // 0047ac39  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0047ac3c  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047ac3f  8d4441d0               -lea eax, [ecx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 0047ac43  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0047ac46  e9b8050000             -jmp 0x47b203
    goto L_0x0047b203;
  case 0x0047ac4b:
    // 0047ac4b  80fb49                 +cmp bl, 0x49
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac4e  742e                   -je 0x47ac7e
    if (cpu.flags.zf)
    {
        goto L_0x0047ac7e;
    }
    // 0047ac50  80fb68                 +cmp bl, 0x68
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac53  7420                   -je 0x47ac75
    if (cpu.flags.zf)
    {
        goto L_0x0047ac75;
    }
    // 0047ac55  80fb6c                 +cmp bl, 0x6c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac58  7412                   -je 0x47ac6c
    if (cpu.flags.zf)
    {
        goto L_0x0047ac6c;
    }
    // 0047ac5a  80fb77                 +cmp bl, 0x77
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac5d  0f85a0050000           -jne 0x47b203
    if (!cpu.flags.zf)
    {
        goto L_0x0047b203;
    }
    // 0047ac63  804dfd08               +or byte ptr [ebp - 3], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0047ac67  e997050000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047ac6c:
    // 0047ac6c  834dfc10               +or dword ptr [ebp - 4], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(16 /*0x10*/))));
    // 0047ac70  e98e050000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047ac75:
    // 0047ac75  834dfc20               +or dword ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 0047ac79  e985050000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047ac7e:
    // 0047ac7e  803f36                 +cmp byte ptr [edi], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac81  7514                   -jne 0x47ac97
    if (!cpu.flags.zf)
    {
        goto L_0x0047ac97;
    }
    // 0047ac83  807f0134               +cmp byte ptr [edi + 1], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac87  750e                   -jne 0x47ac97
    if (!cpu.flags.zf)
    {
        goto L_0x0047ac97;
    }
    // 0047ac89  47                     -inc edi
    (cpu.edi)++;
    // 0047ac8a  47                     -inc edi
    (cpu.edi)++;
    // 0047ac8b  804dfd80               +or byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 0047ac8f  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0047ac92  e96c050000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047ac97:
    // 0047ac97  8955d0                 -mov dword ptr [ebp - 0x30], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.edx;
  [[fallthrough]];
  case 0x0047ac9a:
    // 0047ac9a  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047aca0  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0047aca3  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0047aca6  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0047acab  7419                   -je 0x47acc6
    if (cpu.flags.zf)
    {
        goto L_0x0047acc6;
    }
    // 0047acad  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047acb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047acb1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047acb4  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047acb7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047acb8  e87f050000             -call 0x47b23c
    cpu.esp -= 4;
    sub_47b23c(app, cpu);
    // 0047acbd  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0047acbf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047acc2  47                     -inc edi
    (cpu.edi)++;
    // 0047acc3  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0047acc6:
    // 0047acc6  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047acc9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047acca  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047accd  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047acd0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047acd1  e866050000             -call 0x47b23c
    cpu.esp -= 4;
    sub_47b23c(app, cpu);
    // 0047acd6  83c40c                 +add esp, 0xc
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
    // 0047acd9  e925050000             -jmp 0x47b203
    goto L_0x0047b203;
  case 0x0047acde:
    // 0047acde  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047ace1  83f867                 +cmp eax, 0x67
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
    // 0047ace4  0f8f1c020000           -jg 0x47af06
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047af06;
    }
    // 0047acea  83f865                 +cmp eax, 0x65
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
    // 0047aced  0f8d96000000           -jge 0x47ad89
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ad89;
    }
    // 0047acf3  83f858                 +cmp eax, 0x58
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
    // 0047acf6  0f8feb000000           -jg 0x47ade7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ade7;
    }
    // 0047acfc  0f8478020000           -je 0x47af7a
    if (cpu.flags.zf)
    {
        goto L_0x0047af7a;
    }
    // 0047ad02  83e843                 +sub eax, 0x43
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
    // 0047ad05  0f849f000000           -je 0x47adaa
    if (cpu.flags.zf)
    {
        goto L_0x0047adaa;
    }
    // 0047ad0b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ad0c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ad0d  7470                   -je 0x47ad7f
    if (cpu.flags.zf)
    {
        goto L_0x0047ad7f;
    }
    // 0047ad0f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ad10  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ad11  746c                   -je 0x47ad7f
    if (cpu.flags.zf)
    {
        goto L_0x0047ad7f;
    }
    // 0047ad13  83e80c                 +sub eax, 0xc
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
    // 0047ad16  0f85e9030000           -jne 0x47b105
    if (!cpu.flags.zf)
    {
        goto L_0x0047b105;
    }
    // 0047ad1c  66f745fc3008           +test word ptr [ebp - 4], 0x830
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2096 /*0x830*/));
    // 0047ad22  7504                   -jne 0x47ad28
    if (!cpu.flags.zf)
    {
        goto L_0x0047ad28;
    }
    // 0047ad24  804dfd08               -or byte ptr [ebp - 3], 8
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0047ad28:
    // 0047ad28  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047ad2b  83feff                 +cmp esi, -1
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
    // 0047ad2e  7505                   -jne 0x47ad35
    if (!cpu.flags.zf)
    {
        goto L_0x0047ad35;
    }
    // 0047ad30  beffffff7f             -mov esi, 0x7fffffff
    cpu.esi = 2147483647 /*0x7fffffff*/;
L_0x0047ad35:
    // 0047ad35  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ad38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ad39  e835400000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047ad3e  66f745fc1008           +test word ptr [ebp - 4], 0x810
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2064 /*0x810*/));
    // 0047ad44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ad45  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ad47  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0047ad4a  0f84fe010000           -je 0x47af4e
    if (cpu.flags.zf)
    {
        goto L_0x0047af4e;
    }
    // 0047ad50  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ad52  7509                   -jne 0x47ad5d
    if (!cpu.flags.zf)
    {
        goto L_0x0047ad5d;
    }
    // 0047ad54  8b0dd43f4a00           -mov ecx, dword ptr [0x4a3fd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4866004) /* 0x4a3fd4 */);
    // 0047ad5a  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
L_0x0047ad5d:
    // 0047ad5d  c745dc01000000         -mov dword ptr [ebp - 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = 1 /*0x1*/;
    // 0047ad64  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0047ad66:
    // 0047ad66  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ad68  4e                     -dec esi
    (cpu.esi)--;
    // 0047ad69  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ad6b  0f84d4010000           -je 0x47af45
    if (cpu.flags.zf)
    {
        goto L_0x0047af45;
    }
    // 0047ad71  66833800               +cmp word ptr [eax], 0
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
    // 0047ad75  0f84ca010000           -je 0x47af45
    if (cpu.flags.zf)
    {
        goto L_0x0047af45;
    }
    // 0047ad7b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ad7c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ad7d  ebe7                   -jmp 0x47ad66
    goto L_0x0047ad66;
L_0x0047ad7f:
    // 0047ad7f  c745cc01000000         -mov dword ptr [ebp - 0x34], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = 1 /*0x1*/;
    // 0047ad86  80c320                 -add bl, 0x20
    (cpu.bl) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0047ad89:
    // 0047ad89  834dfc40               -or dword ptr [ebp - 4], 0x40
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047ad8d  8dbdb8fdffff           -lea edi, [ebp - 0x248]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 0047ad93  3bca                   +cmp ecx, edx
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
    // 0047ad95  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 0047ad98  0f8dcf000000           -jge 0x47ae6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ae6d;
    }
    // 0047ad9e  c745f006000000         -mov dword ptr [ebp - 0x10], 6
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 6 /*0x6*/;
    // 0047ada5  e9d1000000             -jmp 0x47ae7b
    goto L_0x0047ae7b;
L_0x0047adaa:
    // 0047adaa  66f745fc3008           +test word ptr [ebp - 4], 0x830
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2096 /*0x830*/));
    // 0047adb0  7504                   -jne 0x47adb6
    if (!cpu.flags.zf)
    {
        goto L_0x0047adb6;
    }
    // 0047adb2  804dfd08               -or byte ptr [ebp - 3], 8
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0047adb6:
    // 0047adb6  66f745fc1008           +test word ptr [ebp - 4], 0x810
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 2064 /*0x810*/));
    // 0047adbc  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047adbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047adc0  743b                   -je 0x47adfd
    if (cpu.flags.zf)
    {
        goto L_0x0047adfd;
    }
    // 0047adc2  e813050000             -call 0x47b2da
    cpu.esp -= 4;
    sub_47b2da(app, cpu);
    // 0047adc7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047adc8  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 0047adce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047adcf  e8f3730000             -call 0x4821c7
    cpu.esp -= 4;
    sub_4821c7(app, cpu);
    // 0047add4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047add7  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047adda  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047addc  7d32                   -jge 0x47ae10
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ae10;
    }
    // 0047adde  c745d801000000         -mov dword ptr [ebp - 0x28], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = 1 /*0x1*/;
    // 0047ade5  eb29                   -jmp 0x47ae10
    goto L_0x0047ae10;
L_0x0047ade7:
    // 0047ade7  83e85a                 +sub eax, 0x5a
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
    // 0047adea  7432                   -je 0x47ae1e
    if (cpu.flags.zf)
    {
        goto L_0x0047ae1e;
    }
    // 0047adec  83e809                 +sub eax, 9
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
    // 0047adef  74c5                   -je 0x47adb6
    if (cpu.flags.zf)
    {
        goto L_0x0047adb6;
    }
    // 0047adf1  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047adf2  0f84e8010000           -je 0x47afe0
    if (cpu.flags.zf)
    {
        goto L_0x0047afe0;
    }
    // 0047adf8  e908030000             -jmp 0x47b105
    goto L_0x0047b105;
L_0x0047adfd:
    // 0047adfd  e8713f0000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047ae02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae03  8885b8fdffff           -mov byte ptr [ebp - 0x248], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-584) /* -0x248 */) = cpu.al;
    // 0047ae09  c745f401000000         -mov dword ptr [ebp - 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 1 /*0x1*/;
L_0x0047ae10:
    // 0047ae10  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 0047ae16  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047ae19  e9e7020000             -jmp 0x47b105
    goto L_0x0047b105;
L_0x0047ae1e:
    // 0047ae1e  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ae21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ae22  e84c3f0000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047ae27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ae29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae2a  7433                   -je 0x47ae5f
    if (cpu.flags.zf)
    {
        goto L_0x0047ae5f;
    }
    // 0047ae2c  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047ae2f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ae31  742c                   -je 0x47ae5f
    if (cpu.flags.zf)
    {
        goto L_0x0047ae5f;
    }
    // 0047ae33  f645fd08               +test byte ptr [ebp - 3], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 8 /*0x8*/));
    // 0047ae37  7417                   -je 0x47ae50
    if (cpu.flags.zf)
    {
        goto L_0x0047ae50;
    }
    // 0047ae39  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0047ae3c  d1e8                   +shr eax, 1
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
    // 0047ae3e  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0047ae41  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047ae44  c745dc01000000         -mov dword ptr [ebp - 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = 1 /*0x1*/;
    // 0047ae4b  e9b5020000             -jmp 0x47b105
    goto L_0x0047b105;
L_0x0047ae50:
    // 0047ae50  8365dc00               +and dword ptr [ebp - 0x24], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0047ae54  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0047ae57  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0047ae5a  e9a3020000             -jmp 0x47b102
    goto L_0x0047b102;
L_0x0047ae5f:
    // 0047ae5f  a1d03f4a00             -mov eax, dword ptr [0x4a3fd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4866000) /* 0x4a3fd0 */);
    // 0047ae64  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047ae67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ae68  e98e000000             -jmp 0x47aefb
    goto L_0x0047aefb;
L_0x0047ae6d:
    // 0047ae6d  750c                   -jne 0x47ae7b
    if (!cpu.flags.zf)
    {
        goto L_0x0047ae7b;
    }
    // 0047ae6f  80fb67                 +cmp bl, 0x67
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ae72  7507                   -jne 0x47ae7b
    if (!cpu.flags.zf)
    {
        goto L_0x0047ae7b;
    }
    // 0047ae74  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
L_0x0047ae7b:
    // 0047ae7b  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ae7e  ff75cc                 -push dword ptr [ebp - 0x34]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    cpu.esp -= 4;
    // 0047ae81  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047ae84  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047ae87  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0047ae8a  8b48f8                 -mov ecx, dword ptr [eax - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0047ae8d  894db8                 -mov dword ptr [ebp - 0x48], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ecx;
    // 0047ae90  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0047ae93  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
    // 0047ae96  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 0047ae99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ae9a  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 0047aea0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047aea1  8d45b8                 -lea eax, [ebp - 0x48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 0047aea4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047aea5  ff15b83f4a00           -call dword ptr [0x4a3fb8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865976) /* 0x4a3fb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047aeab  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047aeae  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047aeb1  81e680000000           +and esi, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 0047aeb7  7414                   -je 0x47aecd
    if (cpu.flags.zf)
    {
        goto L_0x0047aecd;
    }
    // 0047aeb9  837df000               +cmp dword ptr [ebp - 0x10], 0
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
    // 0047aebd  750e                   -jne 0x47aecd
    if (!cpu.flags.zf)
    {
        goto L_0x0047aecd;
    }
    // 0047aebf  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 0047aec5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047aec6  ff15c43f4a00           -call dword ptr [0x4a3fc4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865988) /* 0x4a3fc4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047aecc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047aecd:
    // 0047aecd  80fb67                 +cmp bl, 0x67
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047aed0  7512                   -jne 0x47aee4
    if (!cpu.flags.zf)
    {
        goto L_0x0047aee4;
    }
    // 0047aed2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047aed4  750e                   -jne 0x47aee4
    if (!cpu.flags.zf)
    {
        goto L_0x0047aee4;
    }
    // 0047aed6  8d85b8fdffff           -lea eax, [ebp - 0x248]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-584) /* -0x248 */);
    // 0047aedc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047aedd  ff15bc3f4a00           -call dword ptr [0x4a3fbc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4865980) /* 0x4a3fbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047aee3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047aee4:
    // 0047aee4  80bdb8fdffff2d         +cmp byte ptr [ebp - 0x248], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-584) /* -0x248 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047aeeb  750d                   -jne 0x47aefa
    if (!cpu.flags.zf)
    {
        goto L_0x0047aefa;
    }
    // 0047aeed  804dfd01               +or byte ptr [ebp - 3], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047aef1  8dbdb9fdffff           -lea edi, [ebp - 0x247]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-583) /* -0x247 */);
    // 0047aef7  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
L_0x0047aefa:
    // 0047aefa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047aefb:
    // 0047aefb  e8e02e0000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047af00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af01  e9fc010000             -jmp 0x47b102
    goto L_0x0047b102;
L_0x0047af06:
    // 0047af06  83e869                 +sub eax, 0x69
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
    // 0047af09  0f84d1000000           -je 0x47afe0
    if (cpu.flags.zf)
    {
        goto L_0x0047afe0;
    }
    // 0047af0f  83e805                 +sub eax, 5
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
    // 0047af12  0f849e000000           -je 0x47afb6
    if (cpu.flags.zf)
    {
        goto L_0x0047afb6;
    }
    // 0047af18  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047af19  0f8484000000           -je 0x47afa3
    if (cpu.flags.zf)
    {
        goto L_0x0047afa3;
    }
    // 0047af1f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047af20  7451                   -je 0x47af73
    if (cpu.flags.zf)
    {
        goto L_0x0047af73;
    }
    // 0047af22  83e803                 +sub eax, 3
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
    // 0047af25  0f84fdfdffff           -je 0x47ad28
    if (cpu.flags.zf)
    {
        goto L_0x0047ad28;
    }
    // 0047af2b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047af2c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047af2d  0f84b1000000           -je 0x47afe4
    if (cpu.flags.zf)
    {
        goto L_0x0047afe4;
    }
    // 0047af33  83e803                 +sub eax, 3
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
    // 0047af36  0f85c9010000           -jne 0x47b105
    if (!cpu.flags.zf)
    {
        goto L_0x0047b105;
    }
    // 0047af3c  c745d427000000         -mov dword ptr [ebp - 0x2c], 0x27
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = 39 /*0x27*/;
    // 0047af43  eb3c                   -jmp 0x47af81
    goto L_0x0047af81;
L_0x0047af45:
    // 0047af45  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047af47  d1f8                   +sar eax, 1
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
    // 0047af49  e9b4010000             -jmp 0x47b102
    goto L_0x0047b102;
L_0x0047af4e:
    // 0047af4e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047af50  7509                   -jne 0x47af5b
    if (!cpu.flags.zf)
    {
        goto L_0x0047af5b;
    }
    // 0047af52  8b0dd03f4a00           -mov ecx, dword ptr [0x4a3fd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4866000) /* 0x4a3fd0 */);
    // 0047af58  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
L_0x0047af5b:
    // 0047af5b  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0047af5d:
    // 0047af5d  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047af5f  4e                     -dec esi
    (cpu.esi)--;
    // 0047af60  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047af62  7408                   -je 0x47af6c
    if (cpu.flags.zf)
    {
        goto L_0x0047af6c;
    }
    // 0047af64  803800                 +cmp byte ptr [eax], 0
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
    // 0047af67  7403                   -je 0x47af6c
    if (cpu.flags.zf)
    {
        goto L_0x0047af6c;
    }
    // 0047af69  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047af6a  ebf1                   -jmp 0x47af5d
    goto L_0x0047af5d;
L_0x0047af6c:
    // 0047af6c  2bc1                   +sub eax, ecx
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
    // 0047af6e  e98f010000             -jmp 0x47b102
    goto L_0x0047b102;
L_0x0047af73:
    // 0047af73  c745f008000000         -mov dword ptr [ebp - 0x10], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 8 /*0x8*/;
L_0x0047af7a:
    // 0047af7a  c745d407000000         -mov dword ptr [ebp - 0x2c], 7
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = 7 /*0x7*/;
L_0x0047af81:
    // 0047af81  f645fc80               +test byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 128 /*0x80*/));
    // 0047af85  c745f410000000         -mov dword ptr [ebp - 0xc], 0x10
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 16 /*0x10*/;
    // 0047af8c  745d                   -je 0x47afeb
    if (cpu.flags.zf)
    {
        goto L_0x0047afeb;
    }
    // 0047af8e  8a45d4                 -mov al, byte ptr [ebp - 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0047af91  c645ea30               -mov byte ptr [ebp - 0x16], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 48 /*0x30*/;
    // 0047af95  0451                   +add al, 0x51
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(81 /*0x51*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047af97  c745e402000000         -mov dword ptr [ebp - 0x1c], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 2 /*0x2*/;
    // 0047af9e  8845eb                 -mov byte ptr [ebp - 0x15], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */) = cpu.al;
    // 0047afa1  eb48                   -jmp 0x47afeb
    goto L_0x0047afeb;
L_0x0047afa3:
    // 0047afa3  f645fc80               +test byte ptr [ebp - 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 128 /*0x80*/));
    // 0047afa7  c745f408000000         -mov dword ptr [ebp - 0xc], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 8 /*0x8*/;
    // 0047afae  743b                   -je 0x47afeb
    if (cpu.flags.zf)
    {
        goto L_0x0047afeb;
    }
    // 0047afb0  804dfd02               +or byte ptr [ebp - 3], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0047afb4  eb35                   -jmp 0x47afeb
    goto L_0x0047afeb;
L_0x0047afb6:
    // 0047afb6  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047afb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047afba  e8b43d0000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047afbf  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 0047afc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047afc4  7409                   -je 0x47afcf
    if (cpu.flags.zf)
    {
        goto L_0x0047afcf;
    }
    // 0047afc6  668b4dec               -mov cx, word ptr [ebp - 0x14]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047afca  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0047afcd  eb05                   -jmp 0x47afd4
    goto L_0x0047afd4;
L_0x0047afcf:
    // 0047afcf  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047afd2  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
L_0x0047afd4:
    // 0047afd4  c745d801000000         -mov dword ptr [ebp - 0x28], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = 1 /*0x1*/;
    // 0047afdb  e923020000             -jmp 0x47b203
    goto L_0x0047b203;
L_0x0047afe0:
    // 0047afe0  834dfc40               -or dword ptr [ebp - 4], 0x40
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x0047afe4:
    // 0047afe4  c745f40a000000         -mov dword ptr [ebp - 0xc], 0xa
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 10 /*0xa*/;
L_0x0047afeb:
    // 0047afeb  f645fd80               +test byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 128 /*0x80*/));
    // 0047afef  740c                   -je 0x47affd
    if (cpu.flags.zf)
    {
        goto L_0x0047affd;
    }
    // 0047aff1  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047aff4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047aff5  e8863d0000             -call 0x47ed80
    cpu.esp -= 4;
    sub_47ed80(app, cpu);
    // 0047affa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047affb  eb41                   -jmp 0x47b03e
    goto L_0x0047b03e;
L_0x0047affd:
    // 0047affd  f645fc20               +test byte ptr [ebp - 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 32 /*0x20*/));
    // 0047b001  7421                   -je 0x47b024
    if (cpu.flags.zf)
    {
        goto L_0x0047b024;
    }
    // 0047b003  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 0047b007  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b00a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b00b  740c                   -je 0x47b019
    if (cpu.flags.zf)
    {
        goto L_0x0047b019;
    }
    // 0047b00d  e8613d0000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047b012  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b013  0fbfc0                 -movsx eax, ax
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
L_0x0047b016:
    // 0047b016  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047b017  eb25                   -jmp 0x47b03e
    goto L_0x0047b03e;
L_0x0047b019:
    // 0047b019  e8553d0000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047b01e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b01f  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 0047b022  ebf2                   -jmp 0x47b016
    goto L_0x0047b016;
L_0x0047b024:
    // 0047b024  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 0047b028  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b02b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b02c  7408                   -je 0x47b036
    if (cpu.flags.zf)
    {
        goto L_0x0047b036;
    }
    // 0047b02e  e8403d0000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047b033  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b034  ebe0                   -jmp 0x47b016
    goto L_0x0047b016;
L_0x0047b036:
    // 0047b036  e8383d0000             -call 0x47ed73
    cpu.esp -= 4;
    sub_47ed73(app, cpu);
    // 0047b03b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b03c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047b03e:
    // 0047b03e  f645fc40               +test byte ptr [ebp - 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 64 /*0x40*/));
    // 0047b042  741b                   -je 0x47b05f
    if (cpu.flags.zf)
    {
        goto L_0x0047b05f;
    }
    // 0047b044  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047b046  7f17                   -jg 0x47b05f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047b05f;
    }
    // 0047b048  7c04                   -jl 0x47b04e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047b04e;
    }
    // 0047b04a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b04c  7311                   -jae 0x47b05f
    if (!cpu.flags.cf)
    {
        goto L_0x0047b05f;
    }
L_0x0047b04e:
    // 0047b04e  f7d8                   +neg eax
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
    // 0047b050  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 0047b053  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b055  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0047b057  804dfd01               +or byte ptr [ebp - 3], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047b05b  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047b05d  eb04                   -jmp 0x47b063
    goto L_0x0047b063;
L_0x0047b05f:
    // 0047b05f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b061  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x0047b063:
    // 0047b063  f645fd80               +test byte ptr [ebp - 3], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 128 /*0x80*/));
    // 0047b067  7503                   -jne 0x47b06c
    if (!cpu.flags.zf)
    {
        goto L_0x0047b06c;
    }
    // 0047b069  83e700                 -and edi, 0
    cpu.edi &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047b06c:
    // 0047b06c  837df000               +cmp dword ptr [ebp - 0x10], 0
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
    // 0047b070  7d09                   -jge 0x47b07b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047b07b;
    }
    // 0047b072  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 0047b079  eb04                   -jmp 0x47b07f
    goto L_0x0047b07f;
L_0x0047b07b:
    // 0047b07b  8365fcf7               -and dword ptr [ebp - 4], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
L_0x0047b07f:
    // 0047b07f  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b081  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047b083  7504                   -jne 0x47b089
    if (!cpu.flags.zf)
    {
        goto L_0x0047b089;
    }
    // 0047b085  8365e400               -and dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047b089:
    // 0047b089  8d45b7                 -lea eax, [ebp - 0x49]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-73) /* -0x49 */);
    // 0047b08c  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x0047b08f:
    // 0047b08f  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047b092  ff4df0                 -dec dword ptr [ebp - 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))--;
    // 0047b095  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b097  7f06                   -jg 0x47b09f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047b09f;
    }
    // 0047b099  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b09b  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047b09d  743b                   -je 0x47b0da
    if (cpu.flags.zf)
    {
        goto L_0x0047b0da;
    }
L_0x0047b09f:
    // 0047b09f  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047b0a2  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047b0a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b0a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b0a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b0a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b0a7  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 0047b0aa  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 0047b0ad  e84e720000             -call 0x482300
    cpu.esp -= 4;
    __aullrem(app, cpu);
    // 0047b0b2  ff75c4                 -push dword ptr [ebp - 0x3c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    cpu.esp -= 4;
    // 0047b0b5  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047b0b7  83c330                 -add ebx, 0x30
    (cpu.ebx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047b0ba  ff75c0                 -push dword ptr [ebp - 0x40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    cpu.esp -= 4;
    // 0047b0bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b0be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b0bf  e8cc710000             -call 0x482290
    cpu.esp -= 4;
    __aulldiv(app, cpu);
    // 0047b0c4  83fb39                 +cmp ebx, 0x39
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
    // 0047b0c7  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b0c9  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047b0cb  7e03                   -jle 0x47b0d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047b0d0;
    }
    // 0047b0cd  035dd4                 +add ebx, dword ptr [ebp - 0x2c]
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
L_0x0047b0d0:
    // 0047b0d0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047b0d3  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047b0d6  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0047b0d8  ebb5                   -jmp 0x47b08f
    goto L_0x0047b08f;
L_0x0047b0da:
    // 0047b0da  8d45b7                 -lea eax, [ebp - 0x49]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-73) /* -0x49 */);
    // 0047b0dd  2b45f8                 -sub eax, dword ptr [ebp - 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047b0e0  ff45f8                 -inc dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))++;
    // 0047b0e3  f645fd02               +test byte ptr [ebp - 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) & 2 /*0x2*/));
    // 0047b0e7  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047b0ea  7419                   -je 0x47b105
    if (cpu.flags.zf)
    {
        goto L_0x0047b105;
    }
    // 0047b0ec  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047b0ef  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047b0f2  7504                   -jne 0x47b0f8
    if (!cpu.flags.zf)
    {
        goto L_0x0047b0f8;
    }
    // 0047b0f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b0f6  750d                   -jne 0x47b105
    if (!cpu.flags.zf)
    {
        goto L_0x0047b105;
    }
L_0x0047b0f8:
    // 0047b0f8  ff4df8                 -dec dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))--;
    // 0047b0fb  40                     -inc eax
    (cpu.eax)++;
    // 0047b0fc  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047b0ff  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
L_0x0047b102:
    // 0047b102  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0047b105:
    // 0047b105  837dd800               +cmp dword ptr [ebp - 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b109  0f85f4000000           -jne 0x47b203
    if (!cpu.flags.zf)
    {
        goto L_0x0047b203;
    }
    // 0047b10f  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047b112  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047b115  7426                   -je 0x47b13d
    if (cpu.flags.zf)
    {
        goto L_0x0047b13d;
    }
    // 0047b117  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0047b11a  7406                   -je 0x47b122
    if (cpu.flags.zf)
    {
        goto L_0x0047b122;
    }
    // 0047b11c  c645ea2d               -mov byte ptr [ebp - 0x16], 0x2d
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 45 /*0x2d*/;
    // 0047b120  eb14                   -jmp 0x47b136
    goto L_0x0047b136;
L_0x0047b122:
    // 0047b122  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0047b125  7406                   -je 0x47b12d
    if (cpu.flags.zf)
    {
        goto L_0x0047b12d;
    }
    // 0047b127  c645ea2b               -mov byte ptr [ebp - 0x16], 0x2b
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 43 /*0x2b*/;
    // 0047b12b  eb09                   -jmp 0x47b136
    goto L_0x0047b136;
L_0x0047b12d:
    // 0047b12d  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0047b130  740b                   -je 0x47b13d
    if (cpu.flags.zf)
    {
        goto L_0x0047b13d;
    }
    // 0047b132  c645ea20               -mov byte ptr [ebp - 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 32 /*0x20*/;
L_0x0047b136:
    // 0047b136  c745e401000000         -mov dword ptr [ebp - 0x1c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 1 /*0x1*/;
L_0x0047b13d:
    // 0047b13d  8b75e0                 -mov esi, dword ptr [ebp - 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047b140  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 0047b143  2b75f4                 -sub esi, dword ptr [ebp - 0xc]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0047b146  f6c30c                 +test bl, 0xc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 12 /*0xc*/));
    // 0047b149  7512                   -jne 0x47b15d
    if (!cpu.flags.zf)
    {
        goto L_0x0047b15d;
    }
    // 0047b14b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047b14e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b14f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047b152  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b153  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047b155  e817010000             -call 0x47b271
    cpu.esp -= 4;
    sub_47b271(app, cpu);
    // 0047b15a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047b15d:
    // 0047b15d  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047b160  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b161  8d45ea                 -lea eax, [ebp - 0x16]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-22) /* -0x16 */);
    // 0047b164  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047b167  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0047b16a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b16b  e832010000             -call 0x47b2a2
    cpu.esp -= 4;
    sub_47b2a2(app, cpu);
    // 0047b170  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047b173  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0047b176  7417                   -je 0x47b18f
    if (cpu.flags.zf)
    {
        goto L_0x0047b18f;
    }
    // 0047b178  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0047b17b  7512                   -jne 0x47b18f
    if (!cpu.flags.zf)
    {
        goto L_0x0047b18f;
    }
    // 0047b17d  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047b180  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b181  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047b184  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b185  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0047b187  e8e5000000             -call 0x47b271
    cpu.esp -= 4;
    sub_47b271(app, cpu);
    // 0047b18c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047b18f:
    // 0047b18f  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b193  7441                   -je 0x47b1d6
    if (cpu.flags.zf)
    {
        goto L_0x0047b1d6;
    }
    // 0047b195  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 0047b199  7e3b                   -jle 0x47b1d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047b1d6;
    }
    // 0047b19b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047b19e  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047b1a1  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0047b1a4:
    // 0047b1a4  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0047b1a7  43                     -inc ebx
    (cpu.ebx)++;
    // 0047b1a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b1a9  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0047b1ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b1ad  43                     -inc ebx
    (cpu.ebx)++;
    // 0047b1ae  e814700000             -call 0x4821c7
    cpu.esp -= 4;
    sub_4821c7(app, cpu);
    // 0047b1b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b1b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b1b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b1b7  7e32                   -jle 0x47b1eb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047b1eb;
    }
    // 0047b1b9  8d4dec                 -lea ecx, [ebp - 0x14]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047b1bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b1bd  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047b1c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b1c1  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0047b1c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b1c5  e8d8000000             -call 0x47b2a2
    cpu.esp -= 4;
    sub_47b2a2(app, cpu);
    // 0047b1ca  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047b1cd  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047b1cf  4f                     -dec edi
    (cpu.edi)--;
    // 0047b1d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b1d2  75d0                   -jne 0x47b1a4
    if (!cpu.flags.zf)
    {
        goto L_0x0047b1a4;
    }
    // 0047b1d4  eb15                   -jmp 0x47b1eb
    goto L_0x0047b1eb;
L_0x0047b1d6:
    // 0047b1d6  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047b1d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b1da  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047b1dd  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0047b1e0  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0047b1e3  e8ba000000             -call 0x47b2a2
    cpu.esp -= 4;
    sub_47b2a2(app, cpu);
    // 0047b1e8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047b1eb:
    // 0047b1eb  f645fc04               +test byte ptr [ebp - 4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4 /*0x4*/));
    // 0047b1ef  7412                   -je 0x47b203
    if (cpu.flags.zf)
    {
        goto L_0x0047b203;
    }
    // 0047b1f1  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047b1f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b1f5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047b1f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b1f9  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047b1fb  e871000000             -call 0x47b271
    cpu.esp -= 4;
    sub_47b271(app, cpu);
    // 0047b200  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047b203:
    // 0047b203  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047b206  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0047b208  47                     -inc edi
    (cpu.edi)++;
    // 0047b209  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047b20b  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0047b20e  0f8513f9ffff           -jne 0x47ab27
    if (!cpu.flags.zf)
    {
        goto L_0x0047ab27;
    }
L_0x0047b214:
    // 0047b214  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047b217  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b218  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b219  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b21a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b21b  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_47b23c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b23c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b23d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047b23f  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047b242  ff4904                 +dec dword ptr [ecx + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047b245  780e                   -js 0x47b255
    if (cpu.flags.sf)
    {
        goto L_0x0047b255;
    }
    // 0047b247  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047b249  8a4508                 -mov al, byte ptr [ebp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b24c  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047b24e  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047b250  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0047b253  eb0b                   -jmp 0x47b260
    goto L_0x0047b260;
L_0x0047b255:
    // 0047b255  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b256  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047b259  e88a000000             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 0047b25e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b25f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047b260:
    // 0047b260  83f8ff                 +cmp eax, -1
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
    // 0047b263  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b266  7505                   -jne 0x47b26d
    if (!cpu.flags.zf)
    {
        goto L_0x0047b26d;
    }
    // 0047b268  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047b26b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b26c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b26d:
    // 0047b26d  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 0047b26f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b270  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b271(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b271  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b272  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b273  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b277  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047b279  4f                     -dec edi
    (cpu.edi)--;
    // 0047b27a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b27c  7e21                   -jle 0x47b29f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047b29f;
    }
    // 0047b27e  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0047b282:
    // 0047b282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b283  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047b287  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047b28b  e8acffffff             -call 0x47b23c
    cpu.esp -= 4;
    sub_47b23c(app, cpu);
    // 0047b290  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b293  833eff                 +cmp dword ptr [esi], -1
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
    // 0047b296  7407                   -je 0x47b29f
    if (cpu.flags.zf)
    {
        goto L_0x0047b29f;
    }
    // 0047b298  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047b29a  4f                     -dec edi
    (cpu.edi)--;
    // 0047b29b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b29d  7fe3                   -jg 0x47b282
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047b282;
    }
L_0x0047b29f:
    // 0047b29f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b2a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b2a2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b2a3  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047b2a7  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047b2a9  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047b2aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b2ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b2ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b2ae  7e26                   -jle 0x47b2d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047b2d6;
    }
    // 0047b2b0  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047b2b4  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047b2b8:
    // 0047b2b8  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0047b2bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b2bc  46                     -inc esi
    (cpu.esi)++;
    // 0047b2bd  ff74241c               -push dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047b2c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b2c2  e875ffffff             -call 0x47b23c
    cpu.esp -= 4;
    sub_47b23c(app, cpu);
    // 0047b2c7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b2ca  833fff                 +cmp dword ptr [edi], -1
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
    // 0047b2cd  7407                   -je 0x47b2d6
    if (cpu.flags.zf)
    {
        goto L_0x0047b2d6;
    }
    // 0047b2cf  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047b2d1  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047b2d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b2d4  7fe2                   -jg 0x47b2b8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047b2b8;
    }
L_0x0047b2d6:
    // 0047b2d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b2da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b2da  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b2de  830004                 -add dword ptr [eax], 4
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047b2e1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047b2e3  668b40fc               -mov ax, word ptr [eax - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0047b2e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b2e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b2e8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b2e9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047b2eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b2ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b2ed  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047b2f0  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047b2f3  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047b2f6  a882                   +test al, 0x82
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 130 /*0x82*/));
    // 0047b2f8  0f84f6000000           -je 0x47b3f4
    if (cpu.flags.zf)
    {
        goto L_0x0047b3f4;
    }
    // 0047b2fe  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0047b300  0f85ee000000           -jne 0x47b3f4
    if (!cpu.flags.zf)
    {
        goto L_0x0047b3f4;
    }
    // 0047b306  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0047b308  7416                   -je 0x47b320
    if (cpu.flags.zf)
    {
        goto L_0x0047b320;
    }
    // 0047b30a  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047b30e  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0047b310  0f84de000000           -je 0x47b3f4
    if (cpu.flags.zf)
    {
        goto L_0x0047b3f4;
    }
    // 0047b316  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047b319  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0047b31b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047b31d  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0047b320:
    // 0047b320  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047b323  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047b327  83650c00               -and dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047b32b  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0047b32d  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0047b32f  66a90c01               +test ax, 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 268 /*0x10c*/));
    // 0047b333  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047b336  7522                   -jne 0x47b35a
    if (!cpu.flags.zf)
    {
        goto L_0x0047b35a;
    }
    // 0047b338  81fe283d4a00           +cmp esi, 0x4a3d28
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865320 /*0x4a3d28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b33e  7408                   -je 0x47b348
    if (cpu.flags.zf)
    {
        goto L_0x0047b348;
    }
    // 0047b340  81fe483d4a00           +cmp esi, 0x4a3d48
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865352 /*0x4a3d48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b346  750b                   -jne 0x47b353
    if (!cpu.flags.zf)
    {
        goto L_0x0047b353;
    }
L_0x0047b348:
    // 0047b348  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b349  e8506e0000             -call 0x48219e
    cpu.esp -= 4;
    sub_48219e(app, cpu);
    // 0047b34e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b350  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b351  7507                   -jne 0x47b35a
    if (!cpu.flags.zf)
    {
        goto L_0x0047b35a;
    }
L_0x0047b353:
    // 0047b353  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b354  e81c700000             -call 0x482375
    cpu.esp -= 4;
    sub_482375(app, cpu);
    // 0047b359  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047b35a:
    // 0047b35a  66f7460c0801           +test word ptr [esi + 0xc], 0x108
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 264 /*0x108*/));
    // 0047b360  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b361  7467                   -je 0x47b3ca
    if (cpu.flags.zf)
    {
        goto L_0x0047b3ca;
    }
    // 0047b363  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047b366  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b368  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b36a  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047b36d  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047b36f  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0047b372  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b373  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047b375  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047b378  7e10                   -jle 0x47b38a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047b38a;
    }
    // 0047b37a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b37b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b37c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b37d  e89de5ffff             -call 0x47991f
    cpu.esp -= 4;
    sub_47991f(app, cpu);
    // 0047b382  83c40c                 +add esp, 0xc
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
    // 0047b385  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047b388  eb36                   -jmp 0x47b3c0
    goto L_0x0047b3c0;
L_0x0047b38a:
    // 0047b38a  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b38d  7419                   -je 0x47b3a8
    if (cpu.flags.zf)
    {
        goto L_0x0047b3a8;
    }
    // 0047b38f  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047b391  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047b393  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047b396  83e01f                 +and eax, 0x1f
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/))));
    // 0047b399  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047b3a0  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047b3a3  8d0481                 -lea eax, [ecx + eax*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 0047b3a6  eb05                   -jmp 0x47b3ad
    goto L_0x0047b3ad;
L_0x0047b3a8:
    // 0047b3a8  b830644a00             -mov eax, 0x4a6430
    cpu.eax = 4875312 /*0x4a6430*/;
L_0x0047b3ad:
    // 0047b3ad  f6400420               +test byte ptr [eax + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 0047b3b1  740d                   -je 0x47b3c0
    if (cpu.flags.zf)
    {
        goto L_0x0047b3c0;
    }
    // 0047b3b3  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047b3b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047b3b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b3b8  e807310000             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    // 0047b3bd  83c40c                 +add esp, 0xc
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
L_0x0047b3c0:
    // 0047b3c0  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047b3c3  8a4d08                 -mov cl, byte ptr [ebp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b3c6  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0047b3c8  eb14                   -jmp 0x47b3de
    goto L_0x0047b3de;
L_0x0047b3ca:
    // 0047b3ca  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047b3cc  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b3cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b3d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b3d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b3d3  e847e5ffff             -call 0x47991f
    cpu.esp -= 4;
    sub_47991f(app, cpu);
    // 0047b3d8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b3db  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0047b3de:
    // 0047b3de  397d0c                 +cmp dword ptr [ebp + 0xc], edi
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
    // 0047b3e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3e2  7406                   -je 0x47b3ea
    if (cpu.flags.zf)
    {
        goto L_0x0047b3ea;
    }
    // 0047b3e4  834e0c20               +or dword ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 0047b3e8  eb0f                   -jmp 0x47b3f9
    goto L_0x0047b3f9;
L_0x0047b3ea:
    // 0047b3ea  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b3ed  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0047b3f2  eb08                   -jmp 0x47b3fc
    goto L_0x0047b3fc;
L_0x0047b3f4:
    // 0047b3f4  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0047b3f6  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0047b3f9:
    // 0047b3f9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0047b3fc:
    // 0047b3fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b400  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b401  e89a160000             -call 0x47caa0
    cpu.esp -= 4;
    sub_47caa0(app, cpu);
    // 0047b406  ff1500714800           -call dword ptr [0x487100]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747520) /* 0x487100 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b40c  83f8ff                 +cmp eax, -1
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
    // 0047b40f  a3d83f4a00             -mov dword ptr [0x4a3fd8], eax
    app->getMemory<x86::reg32>(x86::reg32(4866008) /* 0x4a3fd8 */) = cpu.eax;
    // 0047b414  743a                   -je 0x47b450
    if (cpu.flags.zf)
    {
        goto L_0x0047b450;
    }
    // 0047b416  6a74                   -push 0x74
    app->getMemory<x86::reg32>(cpu.esp-4) = 116 /*0x74*/;
    cpu.esp -= 4;
    // 0047b418  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047b41a  e849f0ffff             -call 0x47a468
    cpu.esp -= 4;
    sub_47a468(app, cpu);
    // 0047b41f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b421  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b422  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047b424  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b425  7429                   -je 0x47b450
    if (cpu.flags.zf)
    {
        goto L_0x0047b450;
    }
    // 0047b427  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b428  ff35d83f4a00           -push dword ptr [0x4a3fd8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4866008) /* 0x4a3fd8 */);
    cpu.esp -= 4;
    // 0047b42e  ff1504714800           -call dword ptr [0x487104]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747524) /* 0x487104 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b434  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b436  7418                   -je 0x47b450
    if (cpu.flags.zf)
    {
        goto L_0x0047b450;
    }
    // 0047b438  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b439  e816000000             -call 0x47b454
    cpu.esp -= 4;
    sub_47b454(app, cpu);
    // 0047b43e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b43f  ff1508714800           -call dword ptr [0x487108]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747528) /* 0x487108 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b445  834e04ff               -or dword ptr [esi + 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047b449  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047b44b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047b44d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b44e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b44f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b450:
    // 0047b450  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b452  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b453  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b454(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b454  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b458  c74050a8674a00         -mov dword ptr [eax + 0x50], 0x4a67a8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = 4876200 /*0x4a67a8*/;
    // 0047b45f  c7401401000000         -mov dword ptr [eax + 0x14], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0047b466  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b467(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b467  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b468  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b469  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b46f  ff35d83f4a00           -push dword ptr [0x4a3fd8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4866008) /* 0x4a3fd8 */);
    cpu.esp -= 4;
    // 0047b475  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047b477  ff15f8704800           -call dword ptr [0x4870f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747512) /* 0x4870f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b47d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b47f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047b481  753f                   -jne 0x47b4c2
    if (!cpu.flags.zf)
    {
        goto L_0x0047b4c2;
    }
    // 0047b483  6a74                   -push 0x74
    app->getMemory<x86::reg32>(cpu.esp-4) = 116 /*0x74*/;
    cpu.esp -= 4;
    // 0047b485  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047b487  e8dcefffff             -call 0x47a468
    cpu.esp -= 4;
    sub_47a468(app, cpu);
    // 0047b48c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b48e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b48f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047b491  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b492  7426                   -je 0x47b4ba
    if (cpu.flags.zf)
    {
        goto L_0x0047b4ba;
    }
    // 0047b494  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b495  ff35d83f4a00           -push dword ptr [0x4a3fd8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4866008) /* 0x4a3fd8 */);
    cpu.esp -= 4;
    // 0047b49b  ff1504714800           -call dword ptr [0x487104]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747524) /* 0x487104 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b4a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b4a3  7415                   -je 0x47b4ba
    if (cpu.flags.zf)
    {
        goto L_0x0047b4ba;
    }
    // 0047b4a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b4a6  e8a9ffffff             -call 0x47b454
    cpu.esp -= 4;
    sub_47b454(app, cpu);
    // 0047b4ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4ac  ff1508714800           -call dword ptr [0x487108]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747528) /* 0x487108 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b4b2  834e04ff               +or dword ptr [esi + 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047b4b6  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047b4b8  eb08                   -jmp 0x47b4c2
    goto L_0x0047b4c2;
L_0x0047b4ba:
    // 0047b4ba  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0047b4bc  e878ecffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 0047b4c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047b4c2:
    // 0047b4c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b4c3  ff15fc704800           -call dword ptr [0x4870fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747516) /* 0x4870fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b4c9  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b4cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b6a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047b6a3  83c4e0                 +add esp, -0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-32 /*-0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047b6a6  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047b6a9  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047b6ac  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0047b6af  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047b6b2  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0047b6b5  eb09                   -jmp 0x47b6c0
    return sub_47b6c0(app, cpu);
}

/* align: skip  */
void Application::__startOneArgErrorHandling(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b6b8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047b6ba  83c4e0                 -add esp, -0x20
    (cpu.esp) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 0047b6bd  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047b6c0  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047b6c3  894de4                 -mov dword ptr [ebp - 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ecx;
    // 0047b6c6  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b6c9  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047b6cc  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0047b6cf  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 0047b6d2  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b6d5  8d4de0                 -lea ecx, [ebp - 0x20]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047b6d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b6d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b6da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b6db  e8d96c0000             -call 0x4823b9
    cpu.esp -= 4;
    sub_4823b9(app, cpu);
    // 0047b6e0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b6e3  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047b6e6  66817d087f02           +cmp word ptr [ebp + 8], 0x27f
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(639 /*0x27f*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047b6ec  7403                   -je 0x47b6f1
    if (cpu.flags.zf)
    {
        goto L_0x0047b6f1;
    }
    // 0047b6ee  d96d08                 -fldcw word ptr [ebp + 8]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047b6f1:
    // 0047b6f1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047b6c0;
    // 0047b6b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b6b8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047b6ba  83c4e0                 -add esp, -0x20
    (cpu.esp) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 0047b6bd  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_entry_0x0047b6c0:
    // 0047b6c0  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047b6c3  894de4                 -mov dword ptr [ebp - 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ecx;
    // 0047b6c6  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b6c9  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047b6cc  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0047b6cf  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 0047b6d2  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b6d5  8d4de0                 -lea ecx, [ebp - 0x20]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047b6d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b6d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b6da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b6db  e8d96c0000             -call 0x4823b9
    cpu.esp -= 4;
    sub_4823b9(app, cpu);
    // 0047b6e0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b6e3  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047b6e6  66817d087f02           +cmp word ptr [ebp + 8], 0x27f
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(639 /*0x27f*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047b6ec  7403                   -je 0x47b6f1
    if (cpu.flags.zf)
    {
        goto L_0x0047b6f1;
    }
    // 0047b6ee  d96d08                 -fldcw word ptr [ebp + 8]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047b6f1:
    // 0047b6f1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b715(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b715  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b719  81e200030000           -and edx, 0x300
    cpu.edx &= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0047b71f  83ca7f                 -or edx, 0x7f
    cpu.edx |= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047b722  6689542406             -mov word ptr [esp + 6], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 0047b727  d96c2406               -fldcw word ptr [esp + 6]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0047b72b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b72c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b72c  a900000800             +test eax, 0x80000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 524288 /*0x80000*/));
    // 0047b731  7406                   -je 0x47b739
    if (cpu.flags.zf)
    {
        goto L_0x0047b739;
    }
    // 0047b733  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0047b738  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b739:
    // 0047b739  dc05d07d4800           -fadd qword ptr [0x487dd0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4750800) /* 0x487dd0 */));
    // 0047b73f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047b744  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b788(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b788  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b78c  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0047b791  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b796  7401                   -je 0x47b799
    if (cpu.flags.zf)
    {
        goto L_0x0047b799;
    }
    // 0047b798  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b799:
    // 0047b799  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b79d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__math_exit(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b7ab  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 0047b7af  663d7f02               +cmp ax, 0x27f
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(639 /*0x27f*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047b7b3  741e                   -je 0x47b7d3
    if (cpu.flags.zf)
    {
        goto L_0x0047b7d3;
    }
    // 0047b7b5  6683e020               +and ax, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ax &= x86::reg16(x86::sreg16(32 /*0x20*/))));
    // 0047b7b9  7415                   -je 0x47b7d0
    if (cpu.flags.zf)
    {
        goto L_0x0047b7d0;
    }
    // 0047b7bb  9b                     -wait 
    /*nothing*/;
    // 0047b7bc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047b7be  6683e020               +and ax, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ax &= x86::reg16(x86::sreg16(32 /*0x20*/))));
    // 0047b7c2  740c                   -je 0x47b7d0
    if (cpu.flags.zf)
    {
        goto L_0x0047b7d0;
    }
    // 0047b7c4  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0047b7c9  e8e9feffff             -call 0x47b6b7
    cpu.esp -= 4;
    __startOneArgErrorHandling(app, cpu);
    // 0047b7ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b7d0:
    // 0047b7d0  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
L_0x0047b7d3:
    // 0047b7d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b88c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b88c  6840010000             -push 0x140
    app->getMemory<x86::reg32>(cpu.esp-4) = 320 /*0x140*/;
    cpu.esp -= 4;
    // 0047b891  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047b893  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047b899  ff15e0704800           -call dword ptr [0x4870e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747488) /* 0x4870e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047b89f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b8a1  a308205200             -mov dword ptr [0x522008], eax
    app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */) = cpu.eax;
    // 0047b8a6  7501                   -jne 0x47b8a9
    if (!cpu.flags.zf)
    {
        goto L_0x0047b8a9;
    }
    // 0047b8a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b8a9:
    // 0047b8a9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b8ad  83250020520000         -and dword ptr [0x522000], 0
    app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047b8b4  83250420520000         -and dword ptr [0x522004], 0
    app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047b8bb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047b8bd  a3fc1f5200             -mov dword ptr [0x521ffc], eax
    app->getMemory<x86::reg32>(x86::reg32(5382140) /* 0x521ffc */) = cpu.eax;
    // 0047b8c2  890d0c205200           -mov dword ptr [0x52200c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5382156) /* 0x52200c */) = cpu.ecx;
    // 0047b8c8  c705f41f520010000000   -mov dword ptr [0x521ff4], 0x10
    app->getMemory<x86::reg32>(x86::reg32(5382132) /* 0x521ff4 */) = 16 /*0x10*/;
    // 0047b8d2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b8d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b8d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b8d4  a104205200             -mov eax, dword ptr [0x522004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */);
    // 0047b8d9  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047b8dc  a108205200             -mov eax, dword ptr [0x522008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */);
    // 0047b8e1  8d0c88                 -lea ecx, [eax + ecx*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ecx * 4);
L_0x0047b8e4:
    // 0047b8e4  3bc1                   +cmp eax, ecx
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
    // 0047b8e6  7314                   -jae 0x47b8fc
    if (!cpu.flags.cf)
    {
        goto L_0x0047b8fc;
    }
    // 0047b8e8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b8ec  2b500c                 -sub edx, dword ptr [eax + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 0047b8ef  81fa00001000           +cmp edx, 0x100000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048576 /*0x100000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b8f5  7207                   -jb 0x47b8fe
    if (cpu.flags.cf)
    {
        goto L_0x0047b8fe;
    }
    // 0047b8f7  83c014                 +add eax, 0x14
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047b8fa  ebe8                   -jmp 0x47b8e4
    goto L_0x0047b8e4;
L_0x0047b8fc:
    // 0047b8fc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047b8fe:
    // 0047b8fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b8ff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b8ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b900  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047b902  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047b905  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b908  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b909  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b90a  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047b90d  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047b910  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b911  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0047b913  83c6fc                 -add esi, -4
    (cpu.esi) += x86::reg32(x86::sreg32(-4 /*-0x4*/));
    // 0047b916  2b790c                 -sub edi, dword ptr [ecx + 0xc]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 0047b919  c1ef0f                 -shr edi, 0xf
    cpu.edi >>= 15 /*0xf*/ % 32;
    // 0047b91c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047b91e  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 0047b924  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 0047b92b  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 0047b92e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b930  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b931  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0047b934  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047b937  0f85e6020000           -jne 0x47bc23
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc23;
    }
    // 0047b93d  8b1431                 -mov edx, dword ptr [ecx + esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 1);
    // 0047b940  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0047b943  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0047b946  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0047b949  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0047b94c  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047b94f  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0047b952  895d0c                 -mov dword ptr [ebp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047b955  757e                   -jne 0x47b9d5
    if (!cpu.flags.zf)
    {
        goto L_0x0047b9d5;
    }
    // 0047b957  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0047b95a  4a                     -dec edx
    (cpu.edx)--;
    // 0047b95b  83fa3f                 +cmp edx, 0x3f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b95e  7603                   -jbe 0x47b963
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047b963;
    }
    // 0047b960  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047b962  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047b963:
    // 0047b963  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047b966  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b969  754c                   -jne 0x47b9b7
    if (!cpu.flags.zf)
    {
        goto L_0x0047b9b7;
    }
    // 0047b96b  83fa20                 +cmp edx, 0x20
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b96e  731e                   -jae 0x47b98e
    if (!cpu.flags.cf)
    {
        goto L_0x0047b98e;
    }
    // 0047b970  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047b975  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047b977  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047b979  8d4c0204               -lea ecx, [edx + eax + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047b97d  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047b97f  215cb844               +and dword ptr [eax + edi*4 + 0x44], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edi * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047b983  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047b985  7528                   -jne 0x47b9af
    if (!cpu.flags.zf)
    {
        goto L_0x0047b9af;
    }
    // 0047b987  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b98a  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047b98c  eb21                   -jmp 0x47b9af
    goto L_0x0047b9af;
L_0x0047b98e:
    // 0047b98e  8d4ae0                 -lea ecx, [edx - 0x20]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-32) /* -0x20 */);
    // 0047b991  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047b996  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047b998  8d4c0204               -lea ecx, [edx + eax + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047b99c  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047b99e  219cb8c4000000         +and dword ptr [eax + edi*4 + 0xc4], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edi * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047b9a5  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047b9a7  7506                   -jne 0x47b9af
    if (!cpu.flags.zf)
    {
        goto L_0x0047b9af;
    }
    // 0047b9a9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b9ac  215904                 +and dword ptr [ecx + 4], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0047b9af:
    // 0047b9af  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047b9b2  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047b9b5  eb03                   -jmp 0x47b9ba
    goto L_0x0047b9ba;
L_0x0047b9b7:
    // 0047b9b7  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0047b9ba:
    // 0047b9ba  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047b9bd  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047b9c0  034df4                 -add ecx, dword ptr [ebp - 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0047b9c3  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047b9c6  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047b9c9  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047b9cc  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047b9cf  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047b9d2  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x0047b9d5:
    // 0047b9d5  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b9d7  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0047b9da  4a                     -dec edx
    (cpu.edx)--;
    // 0047b9db  83fa3f                 +cmp edx, 0x3f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b9de  7603                   -jbe 0x47b9e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047b9e3;
    }
    // 0047b9e0  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047b9e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047b9e3:
    // 0047b9e3  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047b9e6  83e301                 +and ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0047b9e9  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0047b9ec  0f8594000000           -jne 0x47ba86
    if (!cpu.flags.zf)
    {
        goto L_0x0047ba86;
    }
    // 0047b9f2  2b75f8                 -sub esi, dword ptr [ebp - 8]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047b9f5  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047b9f8  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0047b9fb  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047b9fd  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047ba00  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047ba01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ba02  3bde                   +cmp ebx, esi
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
    // 0047ba04  7602                   -jbe 0x47ba08
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047ba08;
    }
    // 0047ba06  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0047ba08:
    // 0047ba08  034df8                 -add ecx, dword ptr [ebp - 8]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047ba0b  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ba0d  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047ba10  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0047ba13  4a                     -dec edx
    (cpu.edx)--;
    // 0047ba14  3bd6                   +cmp edx, esi
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
    // 0047ba16  7602                   -jbe 0x47ba1a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047ba1a;
    }
    // 0047ba18  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0047ba1a:
    // 0047ba1a  3bda                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ba1c  7463                   -je 0x47ba81
    if (cpu.flags.zf)
    {
        goto L_0x0047ba81;
    }
    // 0047ba1e  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ba21  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047ba24  3b7108                 +cmp esi, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ba27  7540                   -jne 0x47ba69
    if (!cpu.flags.zf)
    {
        goto L_0x0047ba69;
    }
    // 0047ba29  83fb20                 +cmp ebx, 0x20
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ba2c  731c                   -jae 0x47ba4a
    if (!cpu.flags.cf)
    {
        goto L_0x0047ba4a;
    }
    // 0047ba2e  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 0047ba33  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047ba35  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0047ba37  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 0047ba39  2174b844               +and dword ptr [eax + edi*4 + 0x44], esi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edi * 4) &= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047ba3d  fe4c0304               +dec byte ptr [ebx + eax + 4]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047ba41  7526                   -jne 0x47ba69
    if (!cpu.flags.zf)
    {
        goto L_0x0047ba69;
    }
    // 0047ba43  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ba46  2131                   +and dword ptr [ecx], esi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047ba48  eb1f                   -jmp 0x47ba69
    goto L_0x0047ba69;
L_0x0047ba4a:
    // 0047ba4a  8d4be0                 -lea ecx, [ebx - 0x20]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(-32) /* -0x20 */);
    // 0047ba4d  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 0047ba52  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0047ba54  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 0047ba56  21b4b8c4000000         +and dword ptr [eax + edi*4 + 0xc4], esi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edi * 4) &= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047ba5d  fe4c0304               +dec byte ptr [ebx + eax + 4]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047ba61  7506                   -jne 0x47ba69
    if (!cpu.flags.zf)
    {
        goto L_0x0047ba69;
    }
    // 0047ba63  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ba66  217104                 +and dword ptr [ecx + 4], esi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.esi))));
L_0x0047ba69:
    // 0047ba69  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ba6c  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047ba6f  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047ba72  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047ba75  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ba78  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047ba7b  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047ba7e  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x0047ba81:
    // 0047ba81  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ba84  eb03                   -jmp 0x47ba89
    goto L_0x0047ba89;
L_0x0047ba86:
    // 0047ba86  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047ba89:
    // 0047ba89  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 0047ba8d  7508                   -jne 0x47ba97
    if (!cpu.flags.zf)
    {
        goto L_0x0047ba97;
    }
    // 0047ba8f  3bda                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ba91  0f8481000000           -je 0x47bb18
    if (cpu.flags.zf)
    {
        goto L_0x0047bb18;
    }
L_0x0047ba97:
    // 0047ba97  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047ba9a  8b5cd104               -mov ebx, dword ptr [ecx + edx*8 + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edx * 8);
    // 0047ba9e  8d0cd1                 -lea ecx, [ecx + edx*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.edx * 8);
    // 0047baa1  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047baa4  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047baa7  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047baaa  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047baad  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0047bab0  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047bab3  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bab6  7560                   -jne 0x47bb18
    if (!cpu.flags.zf)
    {
        goto L_0x0047bb18;
    }
    // 0047bab8  8a4c0204               -mov cl, byte ptr [edx + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047babc  83fa20                 +cmp edx, 0x20
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047babf  884d0f                 -mov byte ptr [ebp + 0xf], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */) = cpu.cl;
    // 0047bac2  fec1                   +inc cl
    {
        x86::reg8& tmp = cpu.cl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047bac4  884c0204               -mov byte ptr [edx + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 0047bac8  7325                   -jae 0x47baef
    if (!cpu.flags.cf)
    {
        goto L_0x0047baef;
    }
    // 0047baca  807d0f00               +cmp byte ptr [ebp + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bace  750e                   -jne 0x47bade
    if (!cpu.flags.zf)
    {
        goto L_0x0047bade;
    }
    // 0047bad0  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047bad5  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047bad7  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047bad9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047badc  0919                   -or dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047bade:
    // 0047bade  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047bae3  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047bae5  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047bae7  8d44b844               -lea eax, [eax + edi*4 + 0x44]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edi * 4);
    // 0047baeb  0918                   +or dword ptr [eax], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047baed  eb29                   -jmp 0x47bb18
    goto L_0x0047bb18;
L_0x0047baef:
    // 0047baef  807d0f00               +cmp byte ptr [ebp + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047baf3  7510                   -jne 0x47bb05
    if (!cpu.flags.zf)
    {
        goto L_0x0047bb05;
    }
    // 0047baf5  8d4ae0                 -lea ecx, [edx - 0x20]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-32) /* -0x20 */);
    // 0047baf8  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047bafd  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047baff  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047bb02  095904                 -or dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047bb05:
    // 0047bb05  8d4ae0                 -lea ecx, [edx - 0x20]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-32) /* -0x20 */);
    // 0047bb08  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 0047bb0d  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0047bb0f  8d84b8c4000000         -lea eax, [eax + edi*4 + 0xc4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edi * 4);
    // 0047bb16  0910                   +or dword ptr [eax], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx))));
L_0x0047bb18:
    // 0047bb18  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047bb1b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047bb1d  894430fc               -mov dword ptr [eax + esi - 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1) = cpu.eax;
    // 0047bb21  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047bb24  ff08                   +dec dword ptr [eax]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.eax);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047bb26  0f85f7000000           -jne 0x47bc23
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc23;
    }
    // 0047bb2c  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
    // 0047bb31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bb33  0f84dc000000           -je 0x47bc15
    if (cpu.flags.zf)
    {
        goto L_0x0047bc15;
    }
    // 0047bb39  8b0df81f5200           -mov ecx, dword ptr [0x521ff8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382136) /* 0x521ff8 */);
    // 0047bb3f  8b35f4704800           -mov esi, dword ptr [0x4870f4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747508) /* 0x4870f4 */);
    // 0047bb45  c1e10f                 -shl ecx, 0xf
    cpu.ecx <<= 15 /*0xf*/ % 32;
    // 0047bb48  03480c                 -add ecx, dword ptr [eax + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 0047bb4b  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0047bb50  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 0047bb55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bb56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bb57  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047bb59  8b0df81f5200           -mov ecx, dword ptr [0x521ff8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382136) /* 0x521ff8 */);
    // 0047bb5f  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
    // 0047bb64  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 0047bb69  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0047bb6b  095008                 -or dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bb6e  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
    // 0047bb73  8b0df81f5200           -mov ecx, dword ptr [0x521ff8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382136) /* 0x521ff8 */);
    // 0047bb79  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047bb7c  83a488c400000000       -and dword ptr [eax + ecx*4 + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047bb84  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
    // 0047bb89  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047bb8c  fe4843                 -dec byte ptr [eax + 0x43]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(67) /* 0x43 */))--;
    // 0047bb8f  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
    // 0047bb94  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047bb97  80794300               +cmp byte ptr [ecx + 0x43], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(67) /* 0x43 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bb9b  7509                   -jne 0x47bba6
    if (!cpu.flags.zf)
    {
        goto L_0x0047bba6;
    }
    // 0047bb9d  836004fe               -and dword ptr [eax + 4], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 0047bba1  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
L_0x0047bba6:
    // 0047bba6  837808ff               +cmp dword ptr [eax + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bbaa  7569                   -jne 0x47bc15
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc15;
    }
    // 0047bbac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bbad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047bbaf  ff700c                 -push dword ptr [eax + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047bbb2  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047bbb4  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
    // 0047bbb9  ff7010                 -push dword ptr [eax + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047bbbc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047bbbe  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047bbc4  ff15a4714800           -call dword ptr [0x4871a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747684) /* 0x4871a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047bbca  a104205200             -mov eax, dword ptr [0x522004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */);
    // 0047bbcf  8b1508205200           -mov edx, dword ptr [0x522008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */);
    // 0047bbd5  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047bbd8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047bbdb  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047bbdd  a100205200             -mov eax, dword ptr [0x522000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */);
    // 0047bbe2  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bbe4  8d4c11ec               -lea ecx, [ecx + edx - 0x14]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-20) /* -0x14 */ + cpu.edx * 1);
    // 0047bbe8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bbe9  8d4814                 -lea ecx, [eax + 0x14]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047bbec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bbed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047bbee  e86d620000             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 0047bbf3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047bbf6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047bbf9  ff0d04205200           -dec dword ptr [0x522004]
    (app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */))--;
    // 0047bbff  3b0500205200           +cmp eax, dword ptr [0x522000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bc05  7604                   -jbe 0x47bc0b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047bc0b;
    }
    // 0047bc07  836d0814               -sub dword ptr [ebp + 8], 0x14
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) -= x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0047bc0b:
    // 0047bc0b  a108205200             -mov eax, dword ptr [0x522008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */);
    // 0047bc10  a3fc1f5200             -mov dword ptr [0x521ffc], eax
    app->getMemory<x86::reg32>(x86::reg32(5382140) /* 0x521ffc */) = cpu.eax;
L_0x0047bc15:
    // 0047bc15  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047bc18  893df81f5200           -mov dword ptr [0x521ff8], edi
    app->getMemory<x86::reg32>(x86::reg32(5382136) /* 0x521ff8 */) = cpu.edi;
    // 0047bc1e  a300205200             -mov dword ptr [0x522000], eax
    app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */) = cpu.eax;
L_0x0047bc23:
    // 0047bc23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc26  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47bc28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bc28  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047bc29  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047bc2b  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047bc2e  a104205200             -mov eax, dword ptr [0x522004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */);
    // 0047bc33  8b1508205200           -mov edx, dword ptr [0x522008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */);
    // 0047bc39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bc3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bc3b  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047bc3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bc3f  8d3c82                 -lea edi, [edx + eax*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.eax * 4);
    // 0047bc42  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047bc45  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0047bc48  8d4817                 -lea ecx, [eax + 0x17]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 0047bc4b  83e1f0                 -and ecx, 0xfffffff0
    cpu.ecx &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0047bc4e  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 0047bc51  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0047bc54  49                     -dec ecx
    (cpu.ecx)--;
    // 0047bc55  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bc58  7d0e                   -jge 0x47bc68
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bc68;
    }
    // 0047bc5a  83ceff                 -or esi, 0xffffffff
    cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047bc5d  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0047bc5f  834df8ff               +or dword ptr [ebp - 8], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047bc63  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 0047bc66  eb10                   -jmp 0x47bc78
    goto L_0x0047bc78;
L_0x0047bc68:
    // 0047bc68  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 0047bc6b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047bc6e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047bc70  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047bc72  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 0047bc75  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x0047bc78:
    // 0047bc78  a1fc1f5200             -mov eax, dword ptr [0x521ffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382140) /* 0x521ffc */);
    // 0047bc7d  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047bc7f  3bdf                   +cmp ebx, edi
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
    // 0047bc81  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047bc84  7319                   -jae 0x47bc9f
    if (!cpu.flags.cf)
    {
        goto L_0x0047bc9f;
    }
L_0x0047bc86:
    // 0047bc86  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047bc89  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047bc8b  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047bc8e  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 0047bc90  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047bc92  750b                   -jne 0x47bc9f
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc9f;
    }
    // 0047bc94  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047bc97  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bc9a  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047bc9d  72e7                   -jb 0x47bc86
    if (cpu.flags.cf)
    {
        goto L_0x0047bc86;
    }
L_0x0047bc9f:
    // 0047bc9f  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bca2  7579                   -jne 0x47bd1d
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd1d;
    }
    // 0047bca4  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0047bca6:
    // 0047bca6  3bd8                   +cmp ebx, eax
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
    // 0047bca8  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047bcab  7315                   -jae 0x47bcc2
    if (!cpu.flags.cf)
    {
        goto L_0x0047bcc2;
    }
    // 0047bcad  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047bcb0  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047bcb2  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047bcb5  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 0047bcb7  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047bcb9  7505                   -jne 0x47bcc0
    if (!cpu.flags.zf)
    {
        goto L_0x0047bcc0;
    }
    // 0047bcbb  83c314                 +add ebx, 0x14
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
    // 0047bcbe  ebe6                   -jmp 0x47bca6
    goto L_0x0047bca6;
L_0x0047bcc0:
    // 0047bcc0  3bd8                   +cmp ebx, eax
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
L_0x0047bcc2:
    // 0047bcc2  7559                   -jne 0x47bd1d
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd1d;
    }
L_0x0047bcc4:
    // 0047bcc4  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bcc7  7311                   -jae 0x47bcda
    if (!cpu.flags.cf)
    {
        goto L_0x0047bcda;
    }
    // 0047bcc9  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bccd  7508                   -jne 0x47bcd7
    if (!cpu.flags.zf)
    {
        goto L_0x0047bcd7;
    }
    // 0047bccf  83c314                 +add ebx, 0x14
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
    // 0047bcd2  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047bcd5  ebed                   -jmp 0x47bcc4
    goto L_0x0047bcc4;
L_0x0047bcd7:
    // 0047bcd7  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x0047bcda:
    // 0047bcda  7526                   -jne 0x47bd02
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd02;
    }
    // 0047bcdc  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0047bcde:
    // 0047bcde  3bd8                   +cmp ebx, eax
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
    // 0047bce0  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047bce3  730d                   -jae 0x47bcf2
    if (!cpu.flags.cf)
    {
        goto L_0x0047bcf2;
    }
    // 0047bce5  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bce9  7505                   -jne 0x47bcf0
    if (!cpu.flags.zf)
    {
        goto L_0x0047bcf0;
    }
    // 0047bceb  83c314                 +add ebx, 0x14
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
    // 0047bcee  ebee                   -jmp 0x47bcde
    goto L_0x0047bcde;
L_0x0047bcf0:
    // 0047bcf0  3bd8                   +cmp ebx, eax
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
L_0x0047bcf2:
    // 0047bcf2  750e                   -jne 0x47bd02
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd02;
    }
    // 0047bcf4  e838020000             -call 0x47bf31
    cpu.esp -= 4;
    sub_47bf31(app, cpu);
    // 0047bcf9  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047bcfb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bcfd  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047bd00  7414                   -je 0x47bd16
    if (cpu.flags.zf)
    {
        goto L_0x0047bd16;
    }
L_0x0047bd02:
    // 0047bd02  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bd03  e8da020000             -call 0x47bfe2
    cpu.esp -= 4;
    sub_47bfe2(app, cpu);
    // 0047bd08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd09  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047bd0c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0047bd0e  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047bd11  8338ff                 +cmp dword ptr [eax], -1
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
    // 0047bd14  7507                   -jne 0x47bd1d
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd1d;
    }
L_0x0047bd16:
    // 0047bd16  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047bd18  e90f020000             -jmp 0x47bf2c
    goto L_0x0047bf2c;
L_0x0047bd1d:
    // 0047bd1d  891dfc1f5200           -mov dword ptr [0x521ffc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5382140) /* 0x521ffc */) = cpu.ebx;
    // 0047bd23  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047bd26  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047bd28  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bd2b  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0047bd2e  7414                   -je 0x47bd44
    if (cpu.flags.zf)
    {
        goto L_0x0047bd44;
    }
    // 0047bd30  8b8c90c4000000         -mov ecx, dword ptr [eax + edx*4 + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 0047bd37  8b7c9044               -mov edi, dword ptr [eax + edx*4 + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 0047bd3b  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047bd3e  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 0047bd40  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047bd42  7537                   -jne 0x47bd7b
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd7b;
    }
L_0x0047bd44:
    // 0047bd44  8b90c4000000           -mov edx, dword ptr [eax + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 0047bd4a  8b7044                 -mov esi, dword ptr [eax + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0047bd4d  2355f8                 -and edx, dword ptr [ebp - 8]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047bd50  2375f4                 -and esi, dword ptr [ebp - 0xc]
    cpu.esi &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0047bd53  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047bd57  8d4844                 -lea ecx, [eax + 0x44]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0047bd5a  0bd6                   +or edx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047bd5c  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047bd5f  7517                   -jne 0x47bd78
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd78;
    }
L_0x0047bd61:
    // 0047bd61  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0047bd67  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047bd6a  2355f8                 -and edx, dword ptr [ebp - 8]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047bd6d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047bd70  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0047bd72  2339                   -and edi, dword ptr [ecx]
    cpu.edi &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0047bd74  0bd7                   +or edx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047bd76  74e9                   -je 0x47bd61
    if (cpu.flags.zf)
    {
        goto L_0x0047bd61;
    }
L_0x0047bd78:
    // 0047bd78  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0047bd7b:
    // 0047bd7b  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047bd7d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047bd7f  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 0047bd85  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 0047bd8c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0047bd8f  8b4c9044               -mov ecx, dword ptr [eax + edx*4 + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 0047bd93  23ce                   +and ecx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047bd95  750d                   -jne 0x47bda4
    if (!cpu.flags.zf)
    {
        goto L_0x0047bda4;
    }
    // 0047bd97  8b8c90c4000000         -mov ecx, dword ptr [eax + edx*4 + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 0047bd9e  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047bda0  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0047bda3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047bda4:
    // 0047bda4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047bda6  7c05                   -jl 0x47bdad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bdad;
    }
    // 0047bda8  d1e1                   +shl ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047bdaa  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047bdab  ebf7                   -jmp 0x47bda4
    goto L_0x0047bda4;
L_0x0047bdad:
    // 0047bdad  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047bdb0  8b54f904               -mov edx, dword ptr [ecx + edi*8 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 0047bdb4  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047bdb6  2b4df0                 -sub ecx, dword ptr [ebp - 0x10]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0047bdb9  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047bdbb  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0047bdbe  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0047bdc1  4e                     -dec esi
    (cpu.esi)--;
    // 0047bdc2  83fe3f                 +cmp esi, 0x3f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bdc5  7e03                   -jle 0x47bdca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047bdca;
    }
    // 0047bdc7  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047bdc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047bdca:
    // 0047bdca  3bf7                   +cmp esi, edi
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
    // 0047bdcc  0f840d010000           -je 0x47bedf
    if (cpu.flags.zf)
    {
        goto L_0x0047bedf;
    }
    // 0047bdd2  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047bdd5  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bdd8  7561                   -jne 0x47be3b
    if (!cpu.flags.zf)
    {
        goto L_0x0047be3b;
    }
    // 0047bdda  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bddd  7d2b                   -jge 0x47be0a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047be0a;
    }
    // 0047bddf  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047bde4  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047bde6  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047bde8  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047bdeb  8d7c3804               -lea edi, [eax + edi + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 0047bdef  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047bdf1  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047bdf4  235c8844               +and ebx, dword ptr [eax + ecx*4 + 0x44]
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4)))));
    // 0047bdf8  895c8844               -mov dword ptr [eax + ecx*4 + 0x44], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4) = cpu.ebx;
    // 0047bdfc  fe0f                   +dec byte ptr [edi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.edi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047bdfe  7538                   -jne 0x47be38
    if (!cpu.flags.zf)
    {
        goto L_0x0047be38;
    }
    // 0047be00  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047be03  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047be06  210b                   +and dword ptr [ebx], ecx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebx) &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047be08  eb31                   -jmp 0x47be3b
    goto L_0x0047be3b;
L_0x0047be0a:
    // 0047be0a  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 0047be0d  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047be12  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047be14  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047be17  8d7c3804               -lea edi, [eax + edi + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 0047be1b  8d8c88c4000000         -lea ecx, [eax + ecx*4 + 0xc4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4);
    // 0047be22  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047be24  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047be26  fe0f                   +dec byte ptr [edi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.edi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047be28  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0047be2b  750b                   -jne 0x47be38
    if (!cpu.flags.zf)
    {
        goto L_0x0047be38;
    }
    // 0047be2d  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047be30  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0047be33  214b04                 +and dword ptr [ebx + 4], ecx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047be36  eb03                   -jmp 0x47be3b
    goto L_0x0047be3b;
L_0x0047be38:
    // 0047be38  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047be3b:
    // 0047be3b  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047be3e  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047be41  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 0047be45  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047be48  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047be4b  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047be4e  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0047be51  0f8494000000           -je 0x47beeb
    if (cpu.flags.zf)
    {
        goto L_0x0047beeb;
    }
    // 0047be57  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047be5a  8b7cf104               -mov edi, dword ptr [ecx + esi*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 0047be5e  8d0cf1                 -lea ecx, [ecx + esi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.esi * 8);
    // 0047be61  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047be64  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047be67  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047be6a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047be6d  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047be70  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047be73  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be76  7564                   -jne 0x47bedc
    if (!cpu.flags.zf)
    {
        goto L_0x0047bedc;
    }
    // 0047be78  8a4c0604               -mov cl, byte ptr [esi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047be7c  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be7f  884d0b                 -mov byte ptr [ebp + 0xb], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) = cpu.cl;
    // 0047be82  7d29                   -jge 0x47bead
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bead;
    }
    // 0047be84  fec1                   -inc cl
    (cpu.cl)++;
    // 0047be86  807d0b00               +cmp byte ptr [ebp + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047be8a  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 0047be8e  750b                   -jne 0x47be9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047be9b;
    }
    // 0047be90  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0047be95  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047be97  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 0047be99  093b                   -or dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047be9b:
    // 0047be9b  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0047bea0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047bea2  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 0047bea4  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047bea7  097c8844               +or dword ptr [eax + ecx*4 + 0x44], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4) |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047beab  eb2f                   -jmp 0x47bedc
    goto L_0x0047bedc;
L_0x0047bead:
    // 0047bead  fec1                   -inc cl
    (cpu.cl)++;
    // 0047beaf  807d0b00               +cmp byte ptr [ebp + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047beb3  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 0047beb7  750d                   -jne 0x47bec6
    if (!cpu.flags.zf)
    {
        goto L_0x0047bec6;
    }
    // 0047beb9  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 0047bebc  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0047bec1  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 0047bec3  097b04                 -or dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047bec6:
    // 0047bec6  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047bec9  8dbc88c4000000         -lea edi, [eax + ecx*4 + 0xc4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4);
    // 0047bed0  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 0047bed3  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 0047bed8  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0047beda  0937                   -or dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) |= x86::reg32(x86::sreg32(cpu.esi));
L_0x0047bedc:
    // 0047bedc  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x0047bedf:
    // 0047bedf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047bee1  740b                   -je 0x47beee
    if (cpu.flags.zf)
    {
        goto L_0x0047beee;
    }
    // 0047bee3  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0047bee5  894c11fc               -mov dword ptr [ecx + edx - 4], ecx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edx * 1) = cpu.ecx;
    // 0047bee9  eb03                   -jmp 0x47beee
    goto L_0x0047beee;
L_0x0047beeb:
    // 0047beeb  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x0047beee:
    // 0047beee  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047bef1  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bef3  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047bef6  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0047bef8  894c32fc               -mov dword ptr [edx + esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1) = cpu.ecx;
    // 0047befc  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047beff  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047bf01  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047bf03  8d7901                 -lea edi, [ecx + 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047bf06  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0047bf08  751a                   -jne 0x47bf24
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf24;
    }
    // 0047bf0a  3b1d00205200           +cmp ebx, dword ptr [0x522000]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bf10  7512                   -jne 0x47bf24
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf24;
    }
    // 0047bf12  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047bf15  3b0df81f5200           +cmp ecx, dword ptr [0x521ff8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382136) /* 0x521ff8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bf1b  7507                   -jne 0x47bf24
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf24;
    }
    // 0047bf1d  83250020520000         -and dword ptr [0x522000], 0
    app->getMemory<x86::reg32>(x86::reg32(5382144) /* 0x522000 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047bf24:
    // 0047bf24  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047bf27  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047bf29  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
L_0x0047bf2c:
    // 0047bf2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf2f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47bf31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bf31  a104205200             -mov eax, dword ptr [0x522004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */);
    // 0047bf36  8b0df41f5200           -mov ecx, dword ptr [0x521ff4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382132) /* 0x521ff4 */);
    // 0047bf3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bf3d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bf3e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047bf40  3bc1                   +cmp eax, ecx
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
    // 0047bf42  7530                   -jne 0x47bf74
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf74;
    }
    // 0047bf44  8d448950               -lea eax, [ecx + ecx*4 + 0x50]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */ + cpu.ecx * 4);
    // 0047bf48  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047bf4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047bf4c  ff3508205200           -push dword ptr [0x522008]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */);
    cpu.esp -= 4;
    // 0047bf52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bf53  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047bf59  ff159c714800           -call dword ptr [0x48719c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747676) /* 0x48719c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047bf5f  3bc7                   +cmp eax, edi
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
    // 0047bf61  7461                   -je 0x47bfc4
    if (cpu.flags.zf)
    {
        goto L_0x0047bfc4;
    }
    // 0047bf63  8305f41f520010         -add dword ptr [0x521ff4], 0x10
    (app->getMemory<x86::reg32>(x86::reg32(5382132) /* 0x521ff4 */)) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047bf6a  a308205200             -mov dword ptr [0x522008], eax
    app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */) = cpu.eax;
    // 0047bf6f  a104205200             -mov eax, dword ptr [0x522004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */);
L_0x0047bf74:
    // 0047bf74  8b0d08205200           -mov ecx, dword ptr [0x522008]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382152) /* 0x522008 */);
    // 0047bf7a  68c4410000             -push 0x41c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 16836 /*0x41c4*/;
    cpu.esp -= 4;
    // 0047bf7f  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0047bf81  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0047bf84  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047bf8a  8d3481                 -lea esi, [ecx + eax*4]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 0047bf8d  ff15e0704800           -call dword ptr [0x4870e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747488) /* 0x4870e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047bf93  3bc7                   +cmp eax, edi
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
    // 0047bf95  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047bf98  742a                   -je 0x47bfc4
    if (cpu.flags.zf)
    {
        goto L_0x0047bfc4;
    }
    // 0047bf9a  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047bf9c  6800200000             -push 0x2000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 0047bfa1  6800001000             -push 0x100000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576 /*0x100000*/;
    cpu.esp -= 4;
    // 0047bfa6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bfa7  ff15f0704800           -call dword ptr [0x4870f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747504) /* 0x4870f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047bfad  3bc7                   +cmp eax, edi
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
    // 0047bfaf  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047bfb2  7514                   -jne 0x47bfc8
    if (!cpu.flags.zf)
    {
        goto L_0x0047bfc8;
    }
    // 0047bfb4  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047bfb7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bfb8  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047bfbe  ff15a4714800           -call dword ptr [0x4871a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747684) /* 0x4871a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047bfc4:
    // 0047bfc4  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047bfc6  eb17                   -jmp 0x47bfdf
    goto L_0x0047bfdf;
L_0x0047bfc8:
    // 0047bfc8  834e08ff               -or dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047bfcc  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0047bfce  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047bfd1  ff0504205200           -inc dword ptr [0x522004]
    (app->getMemory<x86::reg32>(x86::reg32(5382148) /* 0x522004 */))++;
    // 0047bfd7  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047bfda  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047bfdd  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047bfdf:
    // 0047bfdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bfe0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bfe1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47bfe2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bfe2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047bfe3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047bfe5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bfe6  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047bfe9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bfea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bfeb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bfec  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047bfef  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047bff2  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047bff4:
    // 0047bff4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bff6  7c05                   -jl 0x47bffd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bffd;
    }
    // 0047bff8  d1e0                   +shl eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047bffa  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047bffb  ebf7                   -jmp 0x47bff4
    goto L_0x0047bff4;
L_0x0047bffd:
    // 0047bffd  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bfff  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047c001  69c004020000           -imul eax, eax, 0x204
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 0047c007  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c008  8d843044010000         -lea eax, [eax + esi + 0x144]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(324) /* 0x144 */ + cpu.esi * 1);
    // 0047c00f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0047c012:
    // 0047c012  894008                 -mov dword ptr [eax + 8], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047c015  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c018  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c01b  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c01c  75f4                   -jne 0x47c012
    if (!cpu.flags.zf)
    {
        goto L_0x0047c012;
    }
    // 0047c01e  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047c020  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047c022  c1e70f                 -shl edi, 0xf
    cpu.edi <<= 15 /*0xf*/ % 32;
    // 0047c025  03790c                 -add edi, dword ptr [ecx + 0xc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 0047c028  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0047c02d  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0047c032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c033  ff15f0704800           -call dword ptr [0x4870f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747504) /* 0x4870f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c03b  7508                   -jne 0x47c045
    if (!cpu.flags.zf)
    {
        goto L_0x0047c045;
    }
    // 0047c03d  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047c040  e993000000             -jmp 0x47c0d8
    goto L_0x0047c0d8;
L_0x0047c045:
    // 0047c045  8d9700700000           -lea edx, [edi + 0x7000]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(28672) /* 0x7000 */);
    // 0047c04b  3bfa                   +cmp edi, edx
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
    // 0047c04d  773c                   -ja 0x47c08b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047c08b;
    }
    // 0047c04f  8d4710                 -lea eax, [edi + 0x10]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
L_0x0047c052:
    // 0047c052  8348f8ff               -or dword ptr [eax - 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047c056  8388ec0f0000ff         -or dword ptr [eax + 0xfec], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4076) /* 0xfec */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047c05d  8d88fc0f0000           -lea ecx, [eax + 0xffc]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4092) /* 0xffc */);
    // 0047c063  c740fcf00f0000         -mov dword ptr [eax - 4], 0xff0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = 4080 /*0xff0*/;
    // 0047c06a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047c06c  8d88fcefffff           -lea ecx, [eax - 0x1004]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4100) /* -0x1004 */);
    // 0047c072  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047c075  c780e80f0000f00f0000   -mov dword ptr [eax + 0xfe8], 0xff0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4072) /* 0xfe8 */) = 4080 /*0xff0*/;
    // 0047c07f  0500100000             -add eax, 0x1000
    (cpu.eax) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0047c084  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 0047c087  3bca                   +cmp ecx, edx
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
    // 0047c089  76c7                   -jbe 0x47c052
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c052;
    }
L_0x0047c08b:
    // 0047c08b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c08e  8d4f0c                 -lea ecx, [edi + 0xc]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0047c091  05f8010000             -add eax, 0x1f8
    (cpu.eax) += x86::reg32(x86::sreg32(504 /*0x1f8*/));
    // 0047c096  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047c098  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c099  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047c09c  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047c09f  8d4a0c                 -lea ecx, [edx + 0xc]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047c0a2  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047c0a5  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c0a8  83649e4400             -and dword ptr [esi + ebx*4 + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */ + cpu.ebx * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047c0ad  89bc9ec4000000         -mov dword ptr [esi + ebx*4 + 0xc4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */ + cpu.ebx * 4) = cpu.edi;
    // 0047c0b4  8a4643                 -mov al, byte ptr [esi + 0x43]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(67) /* 0x43 */);
    // 0047c0b7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047c0b9  fec1                   -inc cl
    (cpu.cl)++;
    // 0047c0bb  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047c0bd  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c0c0  884e43                 -mov byte ptr [esi + 0x43], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(67) /* 0x43 */) = cpu.cl;
    // 0047c0c3  7503                   -jne 0x47c0c8
    if (!cpu.flags.zf)
    {
        goto L_0x0047c0c8;
    }
    // 0047c0c5  097804                 -or dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047c0c8:
    // 0047c0c8  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 0047c0cd  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047c0cf  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0047c0d1  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 0047c0d3  215008                 -and dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c0d6  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047c0d8:
    // 0047c0d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c0d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c0da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c0db  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c0dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c0dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c0dd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c0de  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047c0e0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047c0e3  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c0e6  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c0e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c0ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c0eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c0ec  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047c0ef  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047c0f1  8d7017                 -lea esi, [eax + 0x17]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 0047c0f4  2b510c                 -sub edx, dword ptr [ecx + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 0047c0f7  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c0fa  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0047c0fd  c1ea0f                 -shr edx, 0xf
    cpu.edx >>= 15 /*0xf*/ % 32;
    // 0047c100  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047c102  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 0047c108  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 0047c10f  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0047c112  8b4ffc                 -mov ecx, dword ptr [edi - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0047c115  49                     -dec ecx
    (cpu.ecx)--;
    // 0047c116  3bf1                   +cmp esi, ecx
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
    // 0047c118  894d10                 -mov dword ptr [ebp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047c11b  8b5c39fc               -mov ebx, dword ptr [ecx + edi - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 0047c11f  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 0047c123  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0047c126  0f8e5f010000           -jle 0x47c28b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c28b;
    }
    // 0047c12c  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0047c12f  0f854f010000           -jne 0x47c284
    if (!cpu.flags.zf)
    {
        goto L_0x0047c284;
    }
    // 0047c135  03d9                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c137  3bf3                   +cmp esi, ebx
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
    // 0047c139  0f8f45010000           -jg 0x47c284
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047c284;
    }
    // 0047c13f  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c142  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0047c145  49                     -dec ecx
    (cpu.ecx)--;
    // 0047c146  83f93f                 +cmp ecx, 0x3f
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
    // 0047c149  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0047c14c  7606                   -jbe 0x47c154
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c154;
    }
    // 0047c14e  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047c150  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c151  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
L_0x0047c154:
    // 0047c154  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047c157  3b5f08                 +cmp ebx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c15a  7548                   -jne 0x47c1a4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c1a4;
    }
    // 0047c15c  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c15f  731f                   -jae 0x47c180
    if (!cpu.flags.cf)
    {
        goto L_0x0047c180;
    }
    // 0047c161  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047c166  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047c168  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047c16b  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047c16f  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047c171  215c9044               +and dword ptr [eax + edx*4 + 0x44], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047c175  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047c177  752b                   -jne 0x47c1a4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c1a4;
    }
    // 0047c179  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c17c  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047c17e  eb24                   -jmp 0x47c1a4
    goto L_0x0047c1a4;
L_0x0047c180:
    // 0047c180  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 0047c183  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047c188  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047c18a  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047c18d  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047c191  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047c193  219c90c4000000         +and dword ptr [eax + edx*4 + 0xc4], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047c19a  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047c19c  7506                   -jne 0x47c1a4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c1a4;
    }
    // 0047c19e  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c1a1  215904                 -and dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047c1a4:
    // 0047c1a4  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c1a7  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047c1aa  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047c1ad  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047c1b0  8b7f08                 -mov edi, dword ptr [edi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c1b3  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0047c1b6  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c1b9  2bce                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047c1bb  014dfc                 -add dword ptr [ebp - 4], ecx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c1be  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c1c2  0f8eaa000000           -jle 0x47c272
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c272;
    }
    // 0047c1c8  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c1cb  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047c1ce  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 0047c1d1  4f                     -dec edi
    (cpu.edi)--;
    // 0047c1d2  8d4c31fc               -lea ecx, [ecx + esi - 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 0047c1d6  83ff3f                 +cmp edi, 0x3f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c1d9  7603                   -jbe 0x47c1de
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c1de;
    }
    // 0047c1db  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047c1dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c1de:
    // 0047c1de  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047c1e1  8d1cfb                 -lea ebx, [ebx + edi*8]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.edi * 8);
    // 0047c1e4  895d10                 -mov dword ptr [ebp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047c1e7  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047c1ea  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047c1ed  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c1f0  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047c1f3  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047c1f6  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047c1f9  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047c1fc  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047c1ff  3b5908                 +cmp ebx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c202  755c                   -jne 0x47c260
    if (!cpu.flags.zf)
    {
        goto L_0x0047c260;
    }
    // 0047c204  8a4c0704               -mov cl, byte ptr [edi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047c208  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c20b  884d13                 -mov byte ptr [ebp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(19) /* 0x13 */) = cpu.cl;
    // 0047c20e  fec1                   +inc cl
    {
        x86::reg8& tmp = cpu.cl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047c210  884c0704               -mov byte ptr [edi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 0047c214  7321                   -jae 0x47c237
    if (!cpu.flags.cf)
    {
        goto L_0x0047c237;
    }
    // 0047c216  807d1300               +cmp byte ptr [ebp + 0x13], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(19) /* 0x13 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c21a  750e                   -jne 0x47c22a
    if (!cpu.flags.zf)
    {
        goto L_0x0047c22a;
    }
    // 0047c21c  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047c221  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047c223  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047c225  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c228  0919                   +or dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0047c22a:
    // 0047c22a  8d449044               -lea eax, [eax + edx*4 + 0x44]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 0047c22e  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 0047c233  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047c235  eb25                   -jmp 0x47c25c
    goto L_0x0047c25c;
L_0x0047c237:
    // 0047c237  807d1300               +cmp byte ptr [ebp + 0x13], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(19) /* 0x13 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c23b  7510                   -jne 0x47c24d
    if (!cpu.flags.zf)
    {
        goto L_0x0047c24d;
    }
    // 0047c23d  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 0047c240  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047c245  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047c247  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c24a  095904                 -or dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047c24d:
    // 0047c24d  8d8490c4000000         -lea eax, [eax + edx*4 + 0xc4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 0047c254  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 0047c257  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
L_0x0047c25c:
    // 0047c25c  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0047c25e  0910                   +or dword ptr [eax], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx))));
L_0x0047c260:
    // 0047c260  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047c263  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c266  8d4432fc               -lea eax, [edx + esi - 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 0047c26a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047c26c  894c01fc               -mov dword ptr [ecx + eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ecx;
    // 0047c270  eb03                   -jmp 0x47c275
    goto L_0x0047c275;
L_0x0047c272:
    // 0047c272  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x0047c275:
    // 0047c275  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047c278  8942fc                 -mov dword ptr [edx - 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047c27b  894432f8               -mov dword ptr [edx + esi - 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */ + cpu.esi * 1) = cpu.eax;
    // 0047c27f  e947010000             -jmp 0x47c3cb
    goto L_0x0047c3cb;
L_0x0047c284:
    // 0047c284  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c286  e943010000             -jmp 0x47c3ce
    goto L_0x0047c3ce;
L_0x0047c28b:
    // 0047c28b  0f8d3a010000           -jge 0x47c3cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047c3cb;
    }
    // 0047c291  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047c294  297510                 -sub dword ptr [ebp + 0x10], esi
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047c297  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047c29a  894bfc                 -mov dword ptr [ebx - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047c29d  8d5c33fc               -lea ebx, [ebx + esi - 4]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 0047c2a1  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c2a4  895d0c                 -mov dword ptr [ebp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047c2a7  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0047c2aa  4e                     -dec esi
    (cpu.esi)--;
    // 0047c2ab  894bfc                 -mov dword ptr [ebx - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047c2ae  83fe3f                 +cmp esi, 0x3f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c2b1  7603                   -jbe 0x47c2b6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c2b6;
    }
    // 0047c2b3  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047c2b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c2b6:
    // 0047c2b6  f645fc01               +test byte ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 1 /*0x1*/));
    // 0047c2ba  0f8585000000           -jne 0x47c345
    if (!cpu.flags.zf)
    {
        goto L_0x0047c345;
    }
    // 0047c2c0  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c2c3  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0047c2c6  4e                     -dec esi
    (cpu.esi)--;
    // 0047c2c7  83fe3f                 +cmp esi, 0x3f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c2ca  7603                   -jbe 0x47c2cf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c2cf;
    }
    // 0047c2cc  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047c2ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c2cf:
    // 0047c2cf  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047c2d2  3b4f08                 +cmp ecx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c2d5  7547                   -jne 0x47c31e
    if (!cpu.flags.zf)
    {
        goto L_0x0047c31e;
    }
    // 0047c2d7  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c2da  731e                   -jae 0x47c2fa
    if (!cpu.flags.cf)
    {
        goto L_0x0047c2fa;
    }
    // 0047c2dc  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047c2e1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047c2e3  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047c2e5  8d740604               -lea esi, [esi + eax + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047c2e9  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047c2eb  215c9044               +and dword ptr [eax + edx*4 + 0x44], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047c2ef  fe0e                   +dec byte ptr [esi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.esi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047c2f1  7528                   -jne 0x47c31b
    if (!cpu.flags.zf)
    {
        goto L_0x0047c31b;
    }
    // 0047c2f3  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c2f6  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047c2f8  eb21                   -jmp 0x47c31b
    goto L_0x0047c31b;
L_0x0047c2fa:
    // 0047c2fa  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 0047c2fd  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 0047c302  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0047c304  8d4c0604               -lea ecx, [esi + eax + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047c308  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0047c30a  219c90c4000000         +and dword ptr [eax + edx*4 + 0xc4], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047c311  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0047c313  7506                   -jne 0x47c31b
    if (!cpu.flags.zf)
    {
        goto L_0x0047c31b;
    }
    // 0047c315  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c318  215904                 -and dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047c31b:
    // 0047c31b  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x0047c31e:
    // 0047c31e  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c321  8b7704                 -mov esi, dword ptr [edi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047c324  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047c327  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047c32a  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c32d  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0047c330  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c333  0375fc                 -add esi, dword ptr [ebp - 4]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0047c336  897510                 -mov dword ptr [ebp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0047c339  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0047c33c  4e                     -dec esi
    (cpu.esi)--;
    // 0047c33d  83fe3f                 +cmp esi, 0x3f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c340  7603                   -jbe 0x47c345
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c345;
    }
    // 0047c342  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0047c344  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c345:
    // 0047c345  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047c348  8b7cf104               -mov edi, dword ptr [ecx + esi*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 0047c34c  8d0cf1                 -lea ecx, [ecx + esi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.esi * 8);
    // 0047c34f  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047c352  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047c355  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047c358  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047c35b  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047c35e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047c361  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c364  755c                   -jne 0x47c3c2
    if (!cpu.flags.zf)
    {
        goto L_0x0047c3c2;
    }
    // 0047c366  8a4c0604               -mov cl, byte ptr [esi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047c36a  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c36d  884d0f                 -mov byte ptr [ebp + 0xf], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */) = cpu.cl;
    // 0047c370  fec1                   +inc cl
    {
        x86::reg8& tmp = cpu.cl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0047c372  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 0047c376  7321                   -jae 0x47c399
    if (!cpu.flags.cf)
    {
        goto L_0x0047c399;
    }
    // 0047c378  807d0f00               +cmp byte ptr [ebp + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c37c  750e                   -jne 0x47c38c
    if (!cpu.flags.zf)
    {
        goto L_0x0047c38c;
    }
    // 0047c37e  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0047c383  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047c385  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 0047c387  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c38a  0939                   +or dword ptr [ecx], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.edi))));
L_0x0047c38c:
    // 0047c38c  8d449044               -lea eax, [eax + edx*4 + 0x44]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 0047c390  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 0047c395  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047c397  eb25                   -jmp 0x47c3be
    goto L_0x0047c3be;
L_0x0047c399:
    // 0047c399  807d0f00               +cmp byte ptr [ebp + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c39d  7510                   -jne 0x47c3af
    if (!cpu.flags.zf)
    {
        goto L_0x0047c3af;
    }
    // 0047c39f  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 0047c3a2  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0047c3a7  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 0047c3a9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c3ac  097904                 -or dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047c3af:
    // 0047c3af  8d8490c4000000         -lea eax, [eax + edx*4 + 0xc4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 0047c3b6  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 0047c3b9  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
L_0x0047c3be:
    // 0047c3be  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0047c3c0  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047c3c2:
    // 0047c3c2  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c3c5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0047c3c7  894418fc               -mov dword ptr [eax + ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.ebx * 1) = cpu.eax;
L_0x0047c3cb:
    // 0047c3cb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047c3cd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c3ce:
    // 0047c3ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c3cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c3d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c3d1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c3d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c3d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c3d3  833d20404a00ff         +cmp dword ptr [0x4a4020], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4866080) /* 0x4a4020 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c3da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c3db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c3dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c3dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c3de  7507                   -jne 0x47c3e7
    if (!cpu.flags.zf)
    {
        goto L_0x0047c3e7;
    }
    // 0047c3e0  be10404a00             -mov esi, 0x4a4010
    cpu.esi = 4866064 /*0x4a4010*/;
    // 0047c3e5  eb1d                   -jmp 0x47c404
    goto L_0x0047c404;
L_0x0047c3e7:
    // 0047c3e7  6820200000             -push 0x2020
    app->getMemory<x86::reg32>(cpu.esp-4) = 8224 /*0x2020*/;
    cpu.esp -= 4;
    // 0047c3ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c3ee  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047c3f4  ff15e0704800           -call dword ptr [0x4870e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747488) /* 0x4870e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c3fa  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047c3fc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047c3fe  0f840c010000           -je 0x47c510
    if (cpu.flags.zf)
    {
        goto L_0x0047c510;
    }
L_0x0047c404:
    // 0047c404  8b2df0704800           -mov ebp, dword ptr [0x4870f0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747504) /* 0x4870f0 */);
    // 0047c40a  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047c40c  6800200000             -push 0x2000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 0047c411  6800004000             -push 0x400000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4194304 /*0x400000*/;
    cpu.esp -= 4;
    // 0047c416  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c418  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c41a  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c41c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047c41e  0f84d5000000           -je 0x47c4f9
    if (cpu.flags.zf)
    {
        goto L_0x0047c4f9;
    }
    // 0047c424  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047c426  bb00000100             -mov ebx, 0x10000
    cpu.ebx = 65536 /*0x10000*/;
    // 0047c42b  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0047c430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c431  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c432  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c434  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c436  0f84af000000           -je 0x47c4eb
    if (cpu.flags.zf)
    {
        goto L_0x0047c4eb;
    }
    // 0047c43c  b810404a00             -mov eax, 0x4a4010
    cpu.eax = 4866064 /*0x4a4010*/;
    // 0047c441  3bf0                   +cmp esi, eax
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
    // 0047c443  751e                   -jne 0x47c463
    if (!cpu.flags.zf)
    {
        goto L_0x0047c463;
    }
    // 0047c445  833d10404a0000         +cmp dword ptr [0x4a4010], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4866064) /* 0x4a4010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c44c  7505                   -jne 0x47c453
    if (!cpu.flags.zf)
    {
        goto L_0x0047c453;
    }
    // 0047c44e  a310404a00             -mov dword ptr [0x4a4010], eax
    app->getMemory<x86::reg32>(x86::reg32(4866064) /* 0x4a4010 */) = cpu.eax;
L_0x0047c453:
    // 0047c453  833d14404a0000         +cmp dword ptr [0x4a4014], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4866068) /* 0x4a4014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c45a  751c                   -jne 0x47c478
    if (!cpu.flags.zf)
    {
        goto L_0x0047c478;
    }
    // 0047c45c  a314404a00             -mov dword ptr [0x4a4014], eax
    app->getMemory<x86::reg32>(x86::reg32(4866068) /* 0x4a4014 */) = cpu.eax;
    // 0047c461  eb15                   -jmp 0x47c478
    goto L_0x0047c478;
L_0x0047c463:
    // 0047c463  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047c465  a114404a00             -mov eax, dword ptr [0x4a4014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4866068) /* 0x4a4014 */);
    // 0047c46a  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c46d  893514404a00           -mov dword ptr [0x4a4014], esi
    app->getMemory<x86::reg32>(x86::reg32(4866068) /* 0x4a4014 */) = cpu.esi;
    // 0047c473  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047c476  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x0047c478:
    // 0047c478  8d8700004000           -lea eax, [edi + 0x400000]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(4194304) /* 0x400000 */);
    // 0047c47e  8d8e98000000           -lea ecx, [esi + 0x98]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 0047c484  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047c487  8d4618                 -lea eax, [esi + 0x18]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0047c48a  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0047c48d  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0047c490  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047c493  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047c495  b9f1000000             -mov ecx, 0xf1
    cpu.ecx = 241 /*0xf1*/;
L_0x0047c49a:
    // 0047c49a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c49c  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c49f  0f9dc2                 -setge dl
    cpu.dl = (cpu.flags.sf == cpu.flags.of);
    // 0047c4a2  4a                     -dec edx
    (cpu.edx)--;
    // 0047c4a3  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c4a5  4a                     -dec edx
    (cpu.edx)--;
    // 0047c4a6  45                     -inc ebp
    (cpu.ebp)++;
    // 0047c4a7  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0047c4a9  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047c4ac  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047c4af  81fd00040000           +cmp ebp, 0x400
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c4b5  7ce3                   -jl 0x47c49a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c49a;
    }
    // 0047c4b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c4b8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c4ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c4bb  e860520000             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 0047c4c0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0047c4c3:
    // 0047c4c3  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047c4c6  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c4c8  3bf8                   +cmp edi, eax
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
    // 0047c4ca  731b                   -jae 0x47c4e7
    if (!cpu.flags.cf)
    {
        goto L_0x0047c4e7;
    }
    // 0047c4cc  808ff8000000ff         -or byte ptr [edi + 0xf8], 0xff
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(248) /* 0xf8 */) |= x86::reg8(x86::sreg8(255 /*0xff*/));
    // 0047c4d3  8d4708                 -lea eax, [edi + 8]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c4d6  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047c4d8  c74704f0000000         -mov dword ptr [edi + 4], 0xf0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 240 /*0xf0*/;
    // 0047c4df  81c700100000           +add edi, 0x1000
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c4e5  ebdc                   -jmp 0x47c4c3
    goto L_0x0047c4c3;
L_0x0047c4e7:
    // 0047c4e7  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c4e9  eb27                   -jmp 0x47c512
    goto L_0x0047c512;
L_0x0047c4eb:
    // 0047c4eb  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0047c4f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c4f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c4f3  ff15f4704800           -call dword ptr [0x4870f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747508) /* 0x4870f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047c4f9:
    // 0047c4f9  81fe10404a00           +cmp esi, 0x4a4010
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4866064 /*0x4a4010*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c4ff  740f                   -je 0x47c510
    if (cpu.flags.zf)
    {
        goto L_0x0047c510;
    }
    // 0047c501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c502  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c504  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047c50a  ff15a4714800           -call dword ptr [0x4871a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747684) /* 0x4871a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047c510:
    // 0047c510  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047c512:
    // 0047c512  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c513  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c514  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c515  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c516  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c517(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c517  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c518  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c51c  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 0047c521  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c523  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047c526  ff15f4704800           -call dword ptr [0x4870f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747508) /* 0x4870f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c52c  393530604a00           +cmp dword ptr [0x4a6030], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4874288) /* 0x4a6030 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c532  7508                   -jne 0x47c53c
    if (!cpu.flags.zf)
    {
        goto L_0x0047c53c;
    }
    // 0047c534  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047c537  a330604a00             -mov dword ptr [0x4a6030], eax
    app->getMemory<x86::reg32>(x86::reg32(4874288) /* 0x4a6030 */) = cpu.eax;
L_0x0047c53c:
    // 0047c53c  81fe10404a00           +cmp esi, 0x4a4010
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4866064 /*0x4a4010*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c542  7420                   -je 0x47c564
    if (cpu.flags.zf)
    {
        goto L_0x0047c564;
    }
    // 0047c544  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047c547  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047c549  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c54a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c54c  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0047c54e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047c550  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047c553  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047c556  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047c55c  ff15a4714800           -call dword ptr [0x4871a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747684) /* 0x4871a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c562  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c563  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c564:
    // 0047c564  830d20404a00ff         -or dword ptr [0x4a4020], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4866080) /* 0x4a4020 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047c56b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c56c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c56d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c56d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c56e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047c570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c571  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c573  8b3514404a00           -mov esi, dword ptr [0x4a4014]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4866068) /* 0x4a4014 */);
    // 0047c579  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047c57a:
    // 0047c57a  837e10ff               +cmp dword ptr [esi + 0x10], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c57e  0f8494000000           -je 0x47c618
    if (cpu.flags.zf)
    {
        goto L_0x0047c618;
    }
    // 0047c584  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047c588  8dbe10200000           -lea edi, [esi + 0x2010]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(8208) /* 0x2010 */);
    // 0047c58e  bb00f03f00             -mov ebx, 0x3ff000
    cpu.ebx = 4190208 /*0x3ff000*/;
L_0x0047c593:
    // 0047c593  813ff0000000           +cmp dword ptr [edi], 0xf0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(240 /*0xf0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c599  7539                   -jne 0x47c5d4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c5d4;
    }
    // 0047c59b  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c59d  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 0047c5a2  034610                 -add eax, dword ptr [esi + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0047c5a5  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0047c5aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c5ab  ff15f4704800           -call dword ptr [0x4870f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747508) /* 0x4870f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c5b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c5b3  741f                   -je 0x47c5d4
    if (cpu.flags.zf)
    {
        goto L_0x0047c5d4;
    }
    // 0047c5b5  830fff                 -or dword ptr [edi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edi) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047c5b8  ff0d40eb5100           -dec dword ptr [0x51eb40]
    (app->getMemory<x86::reg32>(x86::reg32(5368640) /* 0x51eb40 */))--;
    // 0047c5be  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047c5c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c5c3  7404                   -je 0x47c5c9
    if (cpu.flags.zf)
    {
        goto L_0x0047c5c9;
    }
    // 0047c5c5  3bc7                   +cmp eax, edi
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
    // 0047c5c7  7603                   -jbe 0x47c5cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c5cc;
    }
L_0x0047c5c9:
    // 0047c5c9  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0047c5cc:
    // 0047c5cc  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047c5cf  ff4d08                 +dec dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c5d2  740d                   -je 0x47c5e1
    if (cpu.flags.zf)
    {
        goto L_0x0047c5e1;
    }
L_0x0047c5d4:
    // 0047c5d4  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0047c5da  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047c5dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c5df  7db2                   -jge 0x47c593
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047c593;
    }
L_0x0047c5e1:
    // 0047c5e1  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c5e5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047c5e7  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047c5ea  742c                   -je 0x47c618
    if (cpu.flags.zf)
    {
        goto L_0x0047c618;
    }
    // 0047c5ec  837918ff               +cmp dword ptr [ecx + 0x18], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c5f0  7526                   -jne 0x47c618
    if (!cpu.flags.zf)
    {
        goto L_0x0047c618;
    }
    // 0047c5f2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047c5f4  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047c5f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c5f8:
    // 0047c5f8  8338ff                 +cmp dword ptr [eax], -1
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
    // 0047c5fb  750c                   -jne 0x47c609
    if (!cpu.flags.zf)
    {
        goto L_0x0047c609;
    }
    // 0047c5fd  42                     -inc edx
    (cpu.edx)++;
    // 0047c5fe  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047c601  81fa00040000           +cmp edx, 0x400
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c607  7cef                   -jl 0x47c5f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c5f8;
    }
L_0x0047c609:
    // 0047c609  81fa00040000           +cmp edx, 0x400
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c60f  7507                   -jne 0x47c618
    if (!cpu.flags.zf)
    {
        goto L_0x0047c618;
    }
    // 0047c611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c612  e800ffffff             -call 0x47c517
    cpu.esp -= 4;
    sub_47c517(app, cpu);
    // 0047c617  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c618:
    // 0047c618  3b3514404a00           +cmp esi, dword ptr [0x4a4014]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4866068) /* 0x4a4014 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c61e  740a                   -je 0x47c62a
    if (cpu.flags.zf)
    {
        goto L_0x0047c62a;
    }
    // 0047c620  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0047c624  0f8f50ffffff           -jg 0x47c57a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047c57a;
    }
L_0x0047c62a:
    // 0047c62a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c62b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c62c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c62d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c62e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c62f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c62f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c633  ba10404a00             -mov edx, 0x4a4010
    cpu.edx = 4866064 /*0x4a4010*/;
    // 0047c638  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c639  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x0047c63b:
    // 0047c63b  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c63e  7605                   -jbe 0x47c645
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c645;
    }
    // 0047c640  3b4114                 +cmp eax, dword ptr [ecx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c643  7208                   -jb 0x47c64d
    if (cpu.flags.cf)
    {
        goto L_0x0047c64d;
    }
L_0x0047c645:
    // 0047c645  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047c647  3bca                   +cmp ecx, edx
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
    // 0047c649  7437                   -je 0x47c682
    if (cpu.flags.zf)
    {
        goto L_0x0047c682;
    }
    // 0047c64b  ebee                   -jmp 0x47c63b
    goto L_0x0047c63b;
L_0x0047c64d:
    // 0047c64d  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 0047c64f  7531                   -jne 0x47c682
    if (!cpu.flags.zf)
    {
        goto L_0x0047c682;
    }
    // 0047c651  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047c653  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0047c658  81e6ff0f0000           -and esi, 0xfff
    cpu.esi &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0047c65e  3bf2                   +cmp esi, edx
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
    // 0047c660  7220                   -jb 0x47c682
    if (cpu.flags.cf)
    {
        goto L_0x0047c682;
    }
    // 0047c662  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047c666  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047c668  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047c66c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c66e  6681e100f0             -and cx, 0xf000
    cpu.cx &= x86::reg16(x86::sreg16(61440 /*0xf000*/));
    // 0047c673  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c675  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047c677  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c679  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c67a  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047c67d  8d440808               -lea eax, [eax + ecx + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ecx * 1);
    // 0047c681  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c682:
    // 0047c682  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c684  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c685  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c686(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c686  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c68a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c68e  2b4810                 -sub ecx, dword ptr [eax + 0x10]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 0047c691  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 0047c694  8d44c818               -lea eax, [eax + ecx*8 + 0x18]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */ + cpu.ecx * 8);
    // 0047c698  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047c69c  0fb611                 -movzx edx, byte ptr [ecx]
    cpu.edx = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0047c69f  0110                   -add dword ptr [eax], edx
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c6a1  802100                 -and byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047c6a4  8138f0000000           +cmp dword ptr [eax], 0xf0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(240 /*0xf0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c6aa  c74004f1000000         -mov dword ptr [eax + 4], 0xf1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 241 /*0xf1*/;
    // 0047c6b1  7517                   -jne 0x47c6ca
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6ca;
    }
    // 0047c6b3  ff0540eb5100           -inc dword ptr [0x51eb40]
    (app->getMemory<x86::reg32>(x86::reg32(5368640) /* 0x51eb40 */))++;
    // 0047c6b9  833d40eb510020         +cmp dword ptr [0x51eb40], 0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368640) /* 0x51eb40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c6c0  7508                   -jne 0x47c6ca
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6ca;
    }
    // 0047c6c2  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0047c6c4  e8a4feffff             -call 0x47c56d
    cpu.esp -= 4;
    sub_47c56d(app, cpu);
    // 0047c6c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c6ca:
    // 0047c6ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c6cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c6cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c6cc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047c6ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c6cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c6d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c6d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c6d2  8b3530604a00           -mov esi, dword ptr [0x4a6030]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4874288) /* 0x4a6030 */);
    // 0047c6d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047c6d9:
    // 0047c6d9  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047c6dc  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c6df  0f849f000000           -je 0x47c784
    if (cpu.flags.zf)
    {
        goto L_0x0047c784;
    }
    // 0047c6e5  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047c6e8  8d8e18200000           -lea ecx, [esi + 0x2018]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8216) /* 0x2018 */);
    // 0047c6ee  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047c6f0  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047c6f2  83e818                 -sub eax, 0x18
    (cpu.eax) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047c6f5  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0047c6f8  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 0047c6fb  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c6fd  3bf9                   +cmp edi, ecx
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
    // 0047c6ff  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047c702  733a                   -jae 0x47c73e
    if (!cpu.flags.cf)
    {
        goto L_0x0047c73e;
    }
L_0x0047c704:
    // 0047c704  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0047c706  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c709  3bcb                   +cmp ecx, ebx
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
    // 0047c70b  7c1a                   -jl 0x47c727
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c727;
    }
    // 0047c70d  395f04                 +cmp dword ptr [edi + 4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c710  7615                   -jbe 0x47c727
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c727;
    }
    // 0047c712  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c713  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c714  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c715  e8b9010000             -call 0x47c8d3
    cpu.esp -= 4;
    sub_47c8d3(app, cpu);
    // 0047c71a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047c71d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c71f  7575                   -jne 0x47c796
    if (!cpu.flags.zf)
    {
        goto L_0x0047c796;
    }
    // 0047c721  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c724  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0047c727:
    // 0047c727  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047c72a  8d8e18200000           -lea ecx, [esi + 0x2018]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8216) /* 0x2018 */);
    // 0047c730  0500100000             -add eax, 0x1000
    (cpu.eax) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0047c735  3bf9                   +cmp edi, ecx
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
    // 0047c737  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047c73a  72c8                   -jb 0x47c704
    if (cpu.flags.cf)
    {
        goto L_0x0047c704;
    }
    // 0047c73c  eb03                   -jmp 0x47c741
    goto L_0x0047c741;
L_0x0047c73e:
    // 0047c73e  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047c741:
    // 0047c741  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047c744  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047c747  8d7e18                 -lea edi, [esi + 0x18]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0047c74a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047c74d  3bf8                   +cmp edi, eax
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
    // 0047c74f  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047c752  7333                   -jae 0x47c787
    if (!cpu.flags.cf)
    {
        goto L_0x0047c787;
    }
L_0x0047c754:
    // 0047c754  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047c756  3bc3                   +cmp eax, ebx
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
    // 0047c758  7c19                   -jl 0x47c773
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c773;
    }
    // 0047c75a  395f04                 +cmp dword ptr [edi + 4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c75d  7614                   -jbe 0x47c773
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c773;
    }
    // 0047c75f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c760  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c761  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0047c764  e86a010000             -call 0x47c8d3
    cpu.esp -= 4;
    sub_47c8d3(app, cpu);
    // 0047c769  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047c76c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c76e  7526                   -jne 0x47c796
    if (!cpu.flags.zf)
    {
        goto L_0x0047c796;
    }
    // 0047c770  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0047c773:
    // 0047c773  8145fc00100000         -add dword ptr [ebp - 4], 0x1000
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0047c77a  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047c77d  3b7df8                 +cmp edi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c780  72d2                   -jb 0x47c754
    if (cpu.flags.cf)
    {
        goto L_0x0047c754;
    }
    // 0047c782  eb03                   -jmp 0x47c787
    goto L_0x0047c787;
L_0x0047c784:
    // 0047c784  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047c787:
    // 0047c787  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047c789  3b3530604a00           +cmp esi, dword ptr [0x4a6030]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4874288) /* 0x4a6030 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c78f  7415                   -je 0x47c7a6
    if (cpu.flags.zf)
    {
        goto L_0x0047c7a6;
    }
    // 0047c791  e943ffffff             -jmp 0x47c6d9
    goto L_0x0047c6d9;
L_0x0047c796:
    // 0047c796  893530604a00           -mov dword ptr [0x4a6030], esi
    app->getMemory<x86::reg32>(x86::reg32(4874288) /* 0x4a6030 */) = cpu.esi;
    // 0047c79c  291f                   +sub dword ptr [edi], ebx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c79e  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0047c7a1  e928010000             -jmp 0x47c8ce
    goto L_0x0047c8ce;
L_0x0047c7a6:
    // 0047c7a6  b810404a00             -mov eax, 0x4a4010
    cpu.eax = 4866064 /*0x4a4010*/;
    // 0047c7ab  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047c7ad:
    // 0047c7ad  837f10ff               +cmp dword ptr [edi + 0x10], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c7b1  7406                   -je 0x47c7b9
    if (cpu.flags.zf)
    {
        goto L_0x0047c7b9;
    }
    // 0047c7b3  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c7b7  750c                   -jne 0x47c7c5
    if (!cpu.flags.zf)
    {
        goto L_0x0047c7c5;
    }
L_0x0047c7b9:
    // 0047c7b9  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0047c7bb  3bf8                   +cmp edi, eax
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
    // 0047c7bd  0f84d7000000           -je 0x47c89a
    if (cpu.flags.zf)
    {
        goto L_0x0047c89a;
    }
    // 0047c7c3  ebe8                   -jmp 0x47c7ad
    goto L_0x0047c7ad;
L_0x0047c7c5:
    // 0047c7c5  8b5f0c                 -mov ebx, dword ptr [edi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0047c7c8  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047c7cc  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047c7ce  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c7d0  2bf7                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047c7d2  83ee18                 -sub esi, 0x18
    (cpu.esi) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047c7d5  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 0047c7d8  c1e60c                 -shl esi, 0xc
    cpu.esi <<= 12 /*0xc*/ % 32;
    // 0047c7db  037710                 -add esi, dword ptr [edi + 0x10]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0047c7de  833bff                 +cmp dword ptr [ebx], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c7e1  7511                   -jne 0x47c7f4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c7f4;
    }
L_0x0047c7e3:
    // 0047c7e3  837dfc10               +cmp dword ptr [ebp - 4], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c7e7  7d0b                   -jge 0x47c7f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047c7f4;
    }
    // 0047c7e9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047c7ec  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0047c7ef  8338ff                 +cmp dword ptr [eax], -1
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
    // 0047c7f2  74ef                   -je 0x47c7e3
    if (cpu.flags.zf)
    {
        goto L_0x0047c7e3;
    }
L_0x0047c7f4:
    // 0047c7f4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c7f7  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047c7f9  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 0047c7fc  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0047c801  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c802  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c803  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0047c806  ff15f0704800           -call dword ptr [0x4870f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747504) /* 0x4870f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047c80c  3bc6                   +cmp eax, esi
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
    // 0047c80e  0f85b8000000           -jne 0x47c8cc
    if (!cpu.flags.zf)
    {
        goto L_0x0047c8cc;
    }
    // 0047c814  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c816  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0047c819  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c81a  e8014f0000             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 0047c81f  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c822  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047c825  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c827  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047c829  7e30                   -jle 0x47c85b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c85b;
    }
    // 0047c82b  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047c82e  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x0047c831:
    // 0047c831  8088f4000000ff         -or byte ptr [eax + 0xf4], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(244) /* 0xf4 */) |= x86::reg8(x86::sreg8(255 /*0xff*/));
    // 0047c838  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047c83b  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0047c83e  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 0047c843  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0047c845  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0047c847  c74104f1000000         -mov dword ptr [ecx + 4], 0xf1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 241 /*0xf1*/;
    // 0047c84e  0500100000             -add eax, 0x1000
    (cpu.eax) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0047c853  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c856  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c859  75d6                   -jne 0x47c831
    if (!cpu.flags.zf)
    {
        goto L_0x0047c831;
    }
L_0x0047c85b:
    // 0047c85b  893d30604a00           -mov dword ptr [0x4a6030], edi
    app->getMemory<x86::reg32>(x86::reg32(4874288) /* 0x4a6030 */) = cpu.edi;
    // 0047c861  8d8718200000           -lea eax, [edi + 0x2018]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(8216) /* 0x2018 */);
L_0x0047c867:
    // 0047c867  3bc8                   +cmp ecx, eax
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
    // 0047c869  730c                   -jae 0x47c877
    if (!cpu.flags.cf)
    {
        goto L_0x0047c877;
    }
    // 0047c86b  8339ff                 +cmp dword ptr [ecx], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c86e  7405                   -je 0x47c875
    if (cpu.flags.zf)
    {
        goto L_0x0047c875;
    }
    // 0047c870  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c873  ebf2                   -jmp 0x47c867
    goto L_0x0047c867;
L_0x0047c875:
    // 0047c875  3bc8                   +cmp ecx, eax
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
L_0x0047c877:
    // 0047c877  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047c879  23c1                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c87b  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047c87e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c881  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0047c884  895f08                 -mov dword ptr [edi + 8], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047c887  2903                   -sub dword ptr [ebx], eax
    (app->getMemory<x86::reg32>(cpu.ebx)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c889  294604                 +sub dword ptr [esi + 4], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c88c  8d4c0608               -lea ecx, [esi + eax + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1);
    // 0047c890  8d8600010000           -lea eax, [esi + 0x100]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(256) /* 0x100 */);
    // 0047c896  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047c898  eb34                   -jmp 0x47c8ce
    goto L_0x0047c8ce;
L_0x0047c89a:
    // 0047c89a  e834fbffff             -call 0x47c3d3
    cpu.esp -= 4;
    sub_47c3d3(app, cpu);
    // 0047c89f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c8a1  7429                   -je 0x47c8cc
    if (cpu.flags.zf)
    {
        goto L_0x0047c8cc;
    }
    // 0047c8a3  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047c8a6  885908                 -mov byte ptr [ecx + 8], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 0047c8a9  8d541908               -lea edx, [ecx + ebx + 8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.ebx * 1);
    // 0047c8ad  a330604a00             -mov dword ptr [0x4a6030], eax
    app->getMemory<x86::reg32>(x86::reg32(4874288) /* 0x4a6030 */) = cpu.eax;
    // 0047c8b2  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0047c8b4  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 0047c8b9  2bd3                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c8bb  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047c8be  0fb6d3                 -movzx edx, bl
    cpu.edx = x86::reg32(cpu.bl);
    // 0047c8c1  295018                 +sub dword ptr [eax + 0x18], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c8c4  8d8100010000           -lea eax, [ecx + 0x100]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(256) /* 0x100 */);
    // 0047c8ca  eb02                   -jmp 0x47c8ce
    goto L_0x0047c8ce;
L_0x0047c8cc:
    // 0047c8cc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047c8ce:
    // 0047c8ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8d1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c8d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c8d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c8d4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047c8d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c8d7  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047c8da  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c8dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c8de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c8df  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047c8e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c8e3  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047c8e5  8d99f8000000           -lea ebx, [ecx + 0xf8]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(248) /* 0xf8 */);
    // 0047c8eb  3bf2                   +cmp esi, edx
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
    // 0047c8ed  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0047c8f0  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047c8f2  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047c8f5  7221                   -jb 0x47c918
    if (cpu.flags.cf)
    {
        goto L_0x0047c918;
    }
    // 0047c8f7  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
    // 0047c8fa  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0047c8fc  3bc3                   +cmp eax, ebx
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
    // 0047c8fe  7307                   -jae 0x47c907
    if (!cpu.flags.cf)
    {
        goto L_0x0047c907;
    }
    // 0047c900  0111                   -add dword ptr [ecx], edx
    (app->getMemory<x86::reg32>(cpu.ecx)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c902  295104                 +sub dword ptr [ecx + 4], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c905  eb09                   -jmp 0x47c910
    goto L_0x0047c910;
L_0x0047c907:
    // 0047c907  83610400               +and dword ptr [ecx + 4], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0047c90b  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047c90e  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0047c910:
    // 0047c910  8d4708                 -lea eax, [edi + 8]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c913  e9ce000000             -jmp 0x47c9e6
    goto L_0x0047c9e6;
L_0x0047c918:
    // 0047c918  03f7                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047c91a  803e00                 +cmp byte ptr [esi], 0
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
    // 0047c91d  7402                   -je 0x47c921
    if (cpu.flags.zf)
    {
        goto L_0x0047c921;
    }
    // 0047c91f  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047c921:
    // 0047c921  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0047c924  3bf3                   +cmp esi, ebx
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
    // 0047c926  7343                   -jae 0x47c96b
    if (!cpu.flags.cf)
    {
        goto L_0x0047c96b;
    }
L_0x0047c928:
    // 0047c928  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047c92a  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047c92c  7530                   -jne 0x47c95e
    if (!cpu.flags.zf)
    {
        goto L_0x0047c95e;
    }
    // 0047c92e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047c930  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047c933  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c934:
    // 0047c934  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c937  7504                   -jne 0x47c93d
    if (!cpu.flags.zf)
    {
        goto L_0x0047c93d;
    }
    // 0047c939  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047c93a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047c93b  ebf7                   -jmp 0x47c934
    goto L_0x0047c934;
L_0x0047c93d:
    // 0047c93d  3bf2                   +cmp esi, edx
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
    // 0047c93f  734e                   -jae 0x47c98f
    if (!cpu.flags.cf)
    {
        goto L_0x0047c98f;
    }
    // 0047c941  3b45fc                 +cmp eax, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c944  7505                   -jne 0x47c94b
    if (!cpu.flags.zf)
    {
        goto L_0x0047c94b;
    }
    // 0047c946  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047c949  eb0c                   -jmp 0x47c957
    goto L_0x0047c957;
L_0x0047c94b:
    // 0047c94b  29750c                 -sub dword ptr [ebp + 0xc], esi
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047c94e  39550c                 +cmp dword ptr [ebp + 0xc], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c951  0f8299000000           -jb 0x47c9f0
    if (cpu.flags.cf)
    {
        goto L_0x0047c9f0;
    }
L_0x0047c957:
    // 0047c957  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047c95a  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c95c  eb05                   -jmp 0x47c963
    goto L_0x0047c963;
L_0x0047c95e:
    // 0047c95e  0fb6f3                 -movzx esi, bl
    cpu.esi = x86::reg32(cpu.bl);
    // 0047c961  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0047c963:
    // 0047c963  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0047c966  3b7508                 +cmp esi, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c969  72bd                   -jb 0x47c928
    if (cpu.flags.cf)
    {
        goto L_0x0047c928;
    }
L_0x0047c96b:
    // 0047c96b  8d7108                 -lea esi, [ecx + 8]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x0047c96e:
    // 0047c96e  3bf7                   +cmp esi, edi
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
    // 0047c970  737e                   -jae 0x47c9f0
    if (!cpu.flags.cf)
    {
        goto L_0x0047c9f0;
    }
    // 0047c972  8d0416                 -lea eax, [esi + edx]
    cpu.eax = x86::reg32(cpu.esi + cpu.edx * 1);
    // 0047c975  3b4508                 +cmp eax, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c978  7376                   -jae 0x47c9f0
    if (!cpu.flags.cf)
    {
        goto L_0x0047c9f0;
    }
    // 0047c97a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047c97c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047c97e  7540                   -jne 0x47c9c0
    if (!cpu.flags.zf)
    {
        goto L_0x0047c9c0;
    }
    // 0047c980  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047c982  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047c985  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c986:
    // 0047c986  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c989  7525                   -jne 0x47c9b0
    if (!cpu.flags.zf)
    {
        goto L_0x0047c9b0;
    }
    // 0047c98b  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047c98c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047c98d  ebf7                   -jmp 0x47c986
    goto L_0x0047c986;
L_0x0047c98f:
    // 0047c98f  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0047c992  3b5d08                 +cmp ebx, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c995  7309                   -jae 0x47c9a0
    if (!cpu.flags.cf)
    {
        goto L_0x0047c9a0;
    }
    // 0047c997  2bf2                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c999  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0047c99b  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047c99e  eb09                   -jmp 0x47c9a9
    goto L_0x0047c9a9;
L_0x0047c9a0:
    // 0047c9a0  83610400               -and dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047c9a4  8d7108                 -lea esi, [ecx + 8]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047c9a7  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
L_0x0047c9a9:
    // 0047c9a9  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0047c9ab  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c9ae  eb36                   -jmp 0x47c9e6
    goto L_0x0047c9e6;
L_0x0047c9b0:
    // 0047c9b0  3bc2                   +cmp eax, edx
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
    // 0047c9b2  7313                   -jae 0x47c9c7
    if (!cpu.flags.cf)
    {
        goto L_0x0047c9c7;
    }
    // 0047c9b4  29450c                 -sub dword ptr [ebp + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c9b7  39550c                 +cmp dword ptr [ebp + 0xc], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c9ba  7234                   -jb 0x47c9f0
    if (cpu.flags.cf)
    {
        goto L_0x0047c9f0;
    }
    // 0047c9bc  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047c9be  ebae                   -jmp 0x47c96e
    goto L_0x0047c96e;
L_0x0047c9c0:
    // 0047c9c0  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0047c9c3  03f0                   +add esi, eax
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
    // 0047c9c5  eba7                   -jmp 0x47c96e
    goto L_0x0047c96e;
L_0x0047c9c7:
    // 0047c9c7  8d1c16                 -lea ebx, [esi + edx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 0047c9ca  3b5d08                 +cmp ebx, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c9cd  7309                   -jae 0x47c9d8
    if (!cpu.flags.cf)
    {
        goto L_0x0047c9d8;
    }
    // 0047c9cf  2bc2                   +sub eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c9d1  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0047c9d3  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c9d6  eb09                   -jmp 0x47c9e1
    goto L_0x0047c9e1;
L_0x0047c9d8:
    // 0047c9d8  83610400               -and dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047c9dc  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047c9df  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0047c9e1:
    // 0047c9e1  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0047c9e3  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x0047c9e6:
    // 0047c9e6  6bc90f                 -imul ecx, ecx, 0xf
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 0047c9e9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047c9ec  2bc1                   +sub eax, ecx
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
    // 0047c9ee  eb02                   -jmp 0x47c9f2
    goto L_0x0047c9f2;
L_0x0047c9f0:
    // 0047c9f0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047c9f2:
    // 0047c9f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9f5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c9f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c9f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c9f8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047c9fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c9fb  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047c9fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c9ff  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ca02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ca03  0fb60a                 -movzx ecx, byte ptr [edx]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.edx));
    // 0047ca06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ca07  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ca0a  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047ca0e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ca10  2b4710                 -sub eax, dword ptr [edi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0047ca13  c1f80c                 -sar eax, 0xc
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (12 /*0xc*/ % 32));
    // 0047ca16  3b4d14                 +cmp ecx, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ca19  8d7cc718               -lea edi, [edi + eax*8 + 0x18]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(24) /* 0x18 */ + cpu.eax * 8);
    // 0047ca1d  7612                   -jbe 0x47ca31
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047ca31;
    }
    // 0047ca1f  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047ca22  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca24  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047ca26  010f                   +add dword ptr [edi], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ca28  c74704f1000000         -mov dword ptr [edi + 4], 0xf1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 241 /*0xf1*/;
    // 0047ca2f  eb60                   -jmp 0x47ca91
    goto L_0x0047ca91;
L_0x0047ca31:
    // 0047ca31  7365                   -jae 0x47ca98
    if (!cpu.flags.cf)
    {
        goto L_0x0047ca98;
    }
    // 0047ca33  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047ca36  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0047ca39  8d83f8000000           -lea eax, [ebx + 0xf8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(248) /* 0xf8 */);
    // 0047ca3f  3bc6                   +cmp eax, esi
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
    // 0047ca41  7255                   -jb 0x47ca98
    if (cpu.flags.cf)
    {
        goto L_0x0047ca98;
    }
    // 0047ca43  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
L_0x0047ca46:
    // 0047ca46  3bc6                   +cmp eax, esi
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
    // 0047ca48  730a                   -jae 0x47ca54
    if (!cpu.flags.cf)
    {
        goto L_0x0047ca54;
    }
    // 0047ca4a  803800                 +cmp byte ptr [eax], 0
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
    // 0047ca4d  7503                   -jne 0x47ca52
    if (!cpu.flags.zf)
    {
        goto L_0x0047ca52;
    }
    // 0047ca4f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ca50  ebf4                   -jmp 0x47ca46
    goto L_0x0047ca46;
L_0x0047ca52:
    // 0047ca52  3bc6                   +cmp eax, esi
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
L_0x0047ca54:
    // 0047ca54  7542                   -jne 0x47ca98
    if (!cpu.flags.zf)
    {
        goto L_0x0047ca98;
    }
    // 0047ca56  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047ca59  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047ca5b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047ca5d  3bd0                   +cmp edx, eax
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
    // 0047ca5f  772b                   -ja 0x47ca8c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ca8c;
    }
    // 0047ca61  3bf0                   +cmp esi, eax
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
    // 0047ca63  7627                   -jbe 0x47ca8c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047ca8c;
    }
    // 0047ca65  8d83f8000000           -lea eax, [ebx + 0xf8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(248) /* 0xf8 */);
    // 0047ca6b  3bf0                   +cmp esi, eax
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
    // 0047ca6d  7314                   -jae 0x47ca83
    if (!cpu.flags.cf)
    {
        goto L_0x0047ca83;
    }
    // 0047ca6f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca71  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 0047ca73  3806                   +cmp byte ptr [esi], al
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ca75  7507                   -jne 0x47ca7e
    if (!cpu.flags.zf)
    {
        goto L_0x0047ca7e;
    }
L_0x0047ca77:
    // 0047ca77  40                     -inc eax
    (cpu.eax)++;
    // 0047ca78  803c0600               +cmp byte ptr [esi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ca7c  74f9                   -je 0x47ca77
    if (cpu.flags.zf)
    {
        goto L_0x0047ca77;
    }
L_0x0047ca7e:
    // 0047ca7e  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047ca81  eb09                   -jmp 0x47ca8c
    goto L_0x0047ca8c;
L_0x0047ca83:
    // 0047ca83  83630400               -and dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047ca87  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047ca8a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0047ca8c:
    // 0047ca8c  2b4d14                 -sub ecx, dword ptr [ebp + 0x14]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
    // 0047ca8f  010f                   -add dword ptr [edi], ecx
    (app->getMemory<x86::reg32>(cpu.edi)) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047ca91:
    // 0047ca91  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
L_0x0047ca98:
    // 0047ca98  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047ca9b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47caa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047caa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047caa1  8b35ec704800           -mov esi, dword ptr [0x4870ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747500) /* 0x4870ec */);
    // 0047caa7  ff357c604a00           -push dword ptr [0x4a607c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4874364) /* 0x4a607c */);
    cpu.esp -= 4;
    // 0047caad  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047caaf  ff356c604a00           -push dword ptr [0x4a606c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4874348) /* 0x4a606c */);
    cpu.esp -= 4;
    // 0047cab5  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cab7  ff355c604a00           -push dword ptr [0x4a605c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4874332) /* 0x4a605c */);
    cpu.esp -= 4;
    // 0047cabd  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cabf  ff353c604a00           -push dword ptr [0x4a603c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4874300) /* 0x4a603c */);
    cpu.esp -= 4;
    // 0047cac5  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cac7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cac8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cac9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cac9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047caca  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047cacc  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047cacf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cad0  833c8538604a0000       +cmp dword ptr [eax*4 + 0x4a6038], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4874296) /* 0x4a6038 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cad8  8d348538604a00         -lea esi, [eax*4 + 0x4a6038]
    cpu.esi = x86::reg32(x86::reg32(4874296) /* 0x4a6038 */ + cpu.eax * 4);
    // 0047cadf  753e                   -jne 0x47cb1f
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb1f;
    }
    // 0047cae1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cae2  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0047cae4  e891a7ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0047cae9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047caeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047caec  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047caee  7508                   -jne 0x47caf8
    if (!cpu.flags.zf)
    {
        goto L_0x0047caf8;
    }
    // 0047caf0  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047caf2  e842d6ffff             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 0047caf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047caf8:
    // 0047caf8  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047cafa  e8caffffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047caff  833e00                 +cmp dword ptr [esi], 0
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
    // 0047cb02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cb04  750a                   -jne 0x47cb10
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb10;
    }
    // 0047cb06  ff15ec704800           -call dword ptr [0x4870ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747500) /* 0x4870ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cb0c  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0047cb0e  eb06                   -jmp 0x47cb16
    goto L_0x0047cb16;
L_0x0047cb10:
    // 0047cb10  e89fa8ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047cb15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047cb16:
    // 0047cb16  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047cb18  e80d000000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047cb1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047cb1f:
    // 0047cb1f  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0047cb21  ff15b0714800           -call dword ptr [0x4871b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747696) /* 0x4871b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cb27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cb2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cb2b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047cb2d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047cb30  ff348538604a00         -push dword ptr [eax*4 + 0x4a6038]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4874296) /* 0x4a6038 */ + cpu.eax * 4);
    cpu.esp -= 4;
    // 0047cb37  ff15b4714800           -call dword ptr [0x4871b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747700) /* 0x4871b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cb3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cb3f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb3f  a1a8eb5100             -mov eax, dword ptr [0x51eba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368744) /* 0x51eba8 */);
    // 0047cb44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cb46  740f                   -je 0x47cb57
    if (cpu.flags.zf)
    {
        goto L_0x0047cb57;
    }
    // 0047cb48  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0047cb4c  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cb4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cb50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb51  7404                   -je 0x47cb57
    if (cpu.flags.zf)
    {
        goto L_0x0047cb57;
    }
    // 0047cb53  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047cb55  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cb57:
    // 0047cb57  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cb59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cb5a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb5a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cb5b  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cb5f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047cb61  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047cb64  ff1568704800           -call dword ptr [0x487068]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747368) /* 0x487068 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cb6a  6681384d5a             +cmp word ptr [eax], 0x5a4d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(23117 /*0x5a4d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047cb6f  7514                   -jne 0x47cb85
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb85;
    }
    // 0047cb71  8b483c                 -mov ecx, dword ptr [eax + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 0047cb74  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047cb76  740d                   -je 0x47cb85
    if (cpu.flags.zf)
    {
        goto L_0x0047cb85;
    }
    // 0047cb78  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cb7a  8a481a                 -mov cl, byte ptr [eax + 0x1a]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 0047cb7d  880e                   -mov byte ptr [esi], cl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.cl;
    // 0047cb7f  8a401b                 -mov al, byte ptr [eax + 0x1b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 0047cb82  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x0047cb85:
    // 0047cb85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cb87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cb88  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047cb8a  b82c120000             -mov eax, 0x122c
    cpu.eax = 4652 /*0x122c*/;
    // 0047cb8f  e89cb1ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047cb94  8d8568ffffff           -lea eax, [ebp - 0x98]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 0047cb9a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cb9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cb9c  c78568ffffff94000000   -mov dword ptr [ebp - 0x98], 0x94
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 148 /*0x94*/;
    // 0047cba6  ff1560714800           -call dword ptr [0x487160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747616) /* 0x487160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cbac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cbae  741a                   -je 0x47cbca
    if (cpu.flags.zf)
    {
        goto L_0x0047cbca;
    }
    // 0047cbb0  83bd78ffffff02         +cmp dword ptr [ebp - 0x88], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-136) /* -0x88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cbb7  7511                   -jne 0x47cbca
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbca;
    }
    // 0047cbb9  83bd6cffffff05         +cmp dword ptr [ebp - 0x94], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-148) /* -0x94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cbc0  7208                   -jb 0x47cbca
    if (cpu.flags.cf)
    {
        goto L_0x0047cbca;
    }
    // 0047cbc2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047cbc4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbc5  e902010000             -jmp 0x47cccc
    goto L_0x0047cccc;
L_0x0047cbca:
    // 0047cbca  8d85d4edffff           -lea eax, [ebp - 0x122c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4652) /* -0x122c */);
    // 0047cbd0  6890100000             -push 0x1090
    app->getMemory<x86::reg32>(cpu.esp-4) = 4240 /*0x1090*/;
    cpu.esp -= 4;
    // 0047cbd5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cbd6  682c7e4800             -push 0x487e2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750892 /*0x487e2c*/;
    cpu.esp -= 4;
    // 0047cbdb  ff1564714800           -call dword ptr [0x487164]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747620) /* 0x487164 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cbe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cbe3  0f84d0000000           -je 0x47ccb9
    if (cpu.flags.zf)
    {
        goto L_0x0047ccb9;
    }
    // 0047cbe9  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cbeb  8d8dd4edffff           -lea ecx, [ebp - 0x122c]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4652) /* -0x122c */);
    // 0047cbf1  389dd4edffff           +cmp byte ptr [ebp - 0x122c], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4652) /* -0x122c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cbf7  7413                   -je 0x47cc0c
    if (cpu.flags.zf)
    {
        goto L_0x0047cc0c;
    }
L_0x0047cbf9:
    // 0047cbf9  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047cbfb  3c61                   +cmp al, 0x61
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
    // 0047cbfd  7c08                   -jl 0x47cc07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cc07;
    }
    // 0047cbff  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cc01  7f04                   -jg 0x47cc07
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047cc07;
    }
    // 0047cc03  2c20                   -sub al, 0x20
    (cpu.al) -= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0047cc05  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
L_0x0047cc07:
    // 0047cc07  41                     -inc ecx
    (cpu.ecx)++;
    // 0047cc08  3819                   +cmp byte ptr [ecx], bl
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
    // 0047cc0a  75ed                   -jne 0x47cbf9
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbf9;
    }
L_0x0047cc0c:
    // 0047cc0c  8d85d4edffff           -lea eax, [ebp - 0x122c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4652) /* -0x122c */);
    // 0047cc12  6a16                   -push 0x16
    app->getMemory<x86::reg32>(cpu.esp-4) = 22 /*0x16*/;
    cpu.esp -= 4;
    // 0047cc14  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cc15  68147e4800             -push 0x487e14
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750868 /*0x487e14*/;
    cpu.esp -= 4;
    // 0047cc1a  e8b1b4ffff             -call 0x4780d0
    cpu.esp -= 4;
    _strncmp(app, cpu);
    // 0047cc1f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cc22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cc24  7508                   -jne 0x47cc2e
    if (!cpu.flags.zf)
    {
        goto L_0x0047cc2e;
    }
    // 0047cc26  8d85d4edffff           -lea eax, [ebp - 0x122c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4652) /* -0x122c */);
    // 0047cc2c  eb49                   -jmp 0x47cc77
    goto L_0x0047cc77;
L_0x0047cc2e:
    // 0047cc2e  8d8564feffff           -lea eax, [ebp - 0x19c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-412) /* -0x19c */);
    // 0047cc34  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0047cc39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cc3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cc3b  ff1568714800           -call dword ptr [0x487168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747624) /* 0x487168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cc41  389d64feffff           +cmp byte ptr [ebp - 0x19c], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-412) /* -0x19c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cc47  8d8d64feffff           -lea ecx, [ebp - 0x19c]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-412) /* -0x19c */);
    // 0047cc4d  7413                   -je 0x47cc62
    if (cpu.flags.zf)
    {
        goto L_0x0047cc62;
    }
L_0x0047cc4f:
    // 0047cc4f  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047cc51  3c61                   +cmp al, 0x61
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
    // 0047cc53  7c08                   -jl 0x47cc5d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cc5d;
    }
    // 0047cc55  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cc57  7f04                   -jg 0x47cc5d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047cc5d;
    }
    // 0047cc59  2c20                   -sub al, 0x20
    (cpu.al) -= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0047cc5b  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
L_0x0047cc5d:
    // 0047cc5d  41                     -inc ecx
    (cpu.ecx)++;
    // 0047cc5e  3819                   +cmp byte ptr [ecx], bl
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
    // 0047cc60  75ed                   -jne 0x47cc4f
    if (!cpu.flags.zf)
    {
        goto L_0x0047cc4f;
    }
L_0x0047cc62:
    // 0047cc62  8d8564feffff           -lea eax, [ebp - 0x19c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-412) /* -0x19c */);
    // 0047cc68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cc69  8d85d4edffff           -lea eax, [ebp - 0x122c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4652) /* -0x122c */);
    // 0047cc6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cc70  e83b5a0000             -call 0x4826b0
    cpu.esp -= 4;
    _strstr(app, cpu);
    // 0047cc75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047cc77:
    // 0047cc77  3bc3                   +cmp eax, ebx
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
    // 0047cc79  743e                   -je 0x47ccb9
    if (cpu.flags.zf)
    {
        goto L_0x0047ccb9;
    }
    // 0047cc7b  6a2c                   -push 0x2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 44 /*0x2c*/;
    cpu.esp -= 4;
    // 0047cc7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cc7e  e8edd1ffff             -call 0x479e70
    cpu.esp -= 4;
    _strchr(app, cpu);
    // 0047cc83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc84  3bc3                   +cmp eax, ebx
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
    // 0047cc86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc87  7430                   -je 0x47ccb9
    if (cpu.flags.zf)
    {
        goto L_0x0047ccb9;
    }
    // 0047cc89  40                     -inc eax
    (cpu.eax)++;
    // 0047cc8a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cc8c  3818                   +cmp byte ptr [eax], bl
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
    // 0047cc8e  740e                   -je 0x47cc9e
    if (cpu.flags.zf)
    {
        goto L_0x0047cc9e;
    }
L_0x0047cc90:
    // 0047cc90  80393b                 +cmp byte ptr [ecx], 0x3b
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(59 /*0x3b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cc93  7504                   -jne 0x47cc99
    if (!cpu.flags.zf)
    {
        goto L_0x0047cc99;
    }
    // 0047cc95  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 0047cc97  eb01                   -jmp 0x47cc9a
    goto L_0x0047cc9a;
L_0x0047cc99:
    // 0047cc99  41                     -inc ecx
    (cpu.ecx)++;
L_0x0047cc9a:
    // 0047cc9a  3819                   +cmp byte ptr [ecx], bl
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
    // 0047cc9c  75f2                   -jne 0x47cc90
    if (!cpu.flags.zf)
    {
        goto L_0x0047cc90;
    }
L_0x0047cc9e:
    // 0047cc9e  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0047cca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cca1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cca2  e8e2570000             -call 0x482489
    cpu.esp -= 4;
    sub_482489(app, cpu);
    // 0047cca7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ccaa  83f802                 +cmp eax, 2
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
    // 0047ccad  741d                   -je 0x47cccc
    if (cpu.flags.zf)
    {
        goto L_0x0047cccc;
    }
    // 0047ccaf  83f803                 +cmp eax, 3
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
    // 0047ccb2  7418                   -je 0x47cccc
    if (cpu.flags.zf)
    {
        goto L_0x0047cccc;
    }
    // 0047ccb4  83f801                 +cmp eax, 1
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
    // 0047ccb7  7413                   -je 0x47cccc
    if (cpu.flags.zf)
    {
        goto L_0x0047cccc;
    }
L_0x0047ccb9:
    // 0047ccb9  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047ccbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ccbd  e898feffff             -call 0x47cb5a
    cpu.esp -= 4;
    sub_47cb5a(app, cpu);
    // 0047ccc2  807dfc06               +cmp byte ptr [ebp - 4], 6
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ccc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ccc7  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047ccc9  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0047cccc:
    // 0047cccc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cccd  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ccce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cccf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cccf  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ccd1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ccd3  39442408               +cmp dword ptr [esp + 8], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ccd7  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0047ccdc  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0047ccdf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cce0  ff1554714800           -call dword ptr [0x487154]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747604) /* 0x487154 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047cce6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cce8  a3ec1f5200             -mov dword ptr [0x521fec], eax
    app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */) = cpu.eax;
    // 0047cced  7436                   -je 0x47cd25
    if (cpu.flags.zf)
    {
        goto L_0x0047cd25;
    }
    // 0047ccef  e893feffff             -call 0x47cb87
    cpu.esp -= 4;
    sub_47cb87(app, cpu);
    // 0047ccf4  83f803                 +cmp eax, 3
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
    // 0047ccf7  a3f01f5200             -mov dword ptr [0x521ff0], eax
    app->getMemory<x86::reg32>(x86::reg32(5382128) /* 0x521ff0 */) = cpu.eax;
    // 0047ccfc  750d                   -jne 0x47cd0b
    if (!cpu.flags.zf)
    {
        goto L_0x0047cd0b;
    }
    // 0047ccfe  68f8030000             -push 0x3f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1016 /*0x3f8*/;
    cpu.esp -= 4;
    // 0047cd03  e884ebffff             -call 0x47b88c
    cpu.esp -= 4;
    sub_47b88c(app, cpu);
    // 0047cd08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd09  eb0a                   -jmp 0x47cd15
    goto L_0x0047cd15;
L_0x0047cd0b:
    // 0047cd0b  83f802                 +cmp eax, 2
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
    // 0047cd0e  7518                   -jne 0x47cd28
    if (!cpu.flags.zf)
    {
        goto L_0x0047cd28;
    }
    // 0047cd10  e8bef6ffff             -call 0x47c3d3
    cpu.esp -= 4;
    sub_47c3d3(app, cpu);
L_0x0047cd15:
    // 0047cd15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cd17  750f                   -jne 0x47cd28
    if (!cpu.flags.zf)
    {
        goto L_0x0047cd28;
    }
    // 0047cd19  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047cd1f  ff1558714800           -call dword ptr [0x487158]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747608) /* 0x487158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047cd25:
    // 0047cd25  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cd27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cd28:
    // 0047cd28  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047cd2a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047cd30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cd31  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047cd33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cd34  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cd35  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047cd38  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047cd3b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047cd3e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047cd40  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047cd42  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047cd44  3bfe                   +cmp edi, esi
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
    // 0047cd46  7608                   -jbe 0x47cd50
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047cd50;
    }
    // 0047cd48  3bf8                   +cmp edi, eax
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
    // 0047cd4a  0f8278010000           -jb 0x47cec8
    if (cpu.flags.cf)
    {
        goto L_0x0047cec8;
    }
L_0x0047cd50:
    // 0047cd50  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0047cd56  7514                   -jne 0x47cd6c
    if (!cpu.flags.zf)
    {
        goto L_0x0047cd6c;
    }
    // 0047cd58  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cd5b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cd5e  83f908                 +cmp ecx, 8
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
    // 0047cd61  7229                   -jb 0x47cd8c
    if (cpu.flags.cf)
    {
        goto L_0x0047cd8c;
    }
    // 0047cd63  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cd65  ff249578ce4700         -jmp dword ptr [edx*4 + 0x47ce78]
    cpu.ip = app->getMemory<x86::reg32>(4705912 + cpu.edx * 4); goto dynamic_jump;
L_0x0047cd6c:
    // 0047cd6c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047cd6e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047cd73  83e904                 +sub ecx, 4
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
    // 0047cd76  720c                   -jb 0x47cd84
    if (cpu.flags.cf)
    {
        goto L_0x0047cd84;
    }
    // 0047cd78  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cd7b  03c8                   +add ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047cd7d  ff248590cd4700         -jmp dword ptr [eax*4 + 0x47cd90]
    cpu.ip = app->getMemory<x86::reg32>(4705680 + cpu.eax * 4); goto dynamic_jump;
L_0x0047cd84:
    // 0047cd84  ff248d88ce4700         -jmp dword ptr [ecx*4 + 0x47ce88]
    cpu.ip = app->getMemory<x86::reg32>(4705928 + cpu.ecx * 4); goto dynamic_jump;
L_0x0047cd8c:
    // 0047cd8c  ff248d0cce4700         -jmp dword ptr [ecx*4 + 0x47ce0c]
    cpu.ip = app->getMemory<x86::reg32>(4705804 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0047cda0:
    // 0047cda0  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cda2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047cda4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047cda6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047cda9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047cdac  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047cdaf  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cdb2  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047cdb5  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cdb8  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cdbb  83f908                 +cmp ecx, 8
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
    // 0047cdbe  72cc                   -jb 0x47cd8c
    if (cpu.flags.cf)
    {
        goto L_0x0047cd8c;
    }
    // 0047cdc0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cdc2  ff249578ce4700         -jmp dword ptr [edx*4 + 0x47ce78]
    cpu.ip = app->getMemory<x86::reg32>(4705912 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047cdcc:
    // 0047cdcc  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cdce  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047cdd0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047cdd2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047cdd5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cdd8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047cddb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cdde  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cde1  83f908                 +cmp ecx, 8
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
    // 0047cde4  72a6                   -jb 0x47cd8c
    if (cpu.flags.cf)
    {
        goto L_0x0047cd8c;
    }
    // 0047cde6  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cde8  ff249578ce4700         -jmp dword ptr [edx*4 + 0x47ce78]
    cpu.ip = app->getMemory<x86::reg32>(4705912 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047cdf0:
    // 0047cdf0  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cdf2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047cdf4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047cdf6  46                     -inc esi
    (cpu.esi)++;
    // 0047cdf7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cdfa  47                     -inc edi
    (cpu.edi)++;
    // 0047cdfb  83f908                 +cmp ecx, 8
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
    // 0047cdfe  728c                   -jb 0x47cd8c
    if (cpu.flags.cf)
    {
        goto L_0x0047cd8c;
    }
    // 0047ce00  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047ce02  ff249578ce4700         -jmp dword ptr [edx*4 + 0x47ce78]
    cpu.ip = app->getMemory<x86::reg32>(4705912 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047ce2c:
    // 0047ce2c  8b448ee4               -mov eax, dword ptr [esi + ecx*4 - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4);
    // 0047ce30  89448fe4               -mov dword ptr [edi + ecx*4 - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047ce34:
    // 0047ce34  8b448ee8               -mov eax, dword ptr [esi + ecx*4 - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4);
    // 0047ce38  89448fe8               -mov dword ptr [edi + ecx*4 - 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047ce3c:
    // 0047ce3c  8b448eec               -mov eax, dword ptr [esi + ecx*4 - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4);
    // 0047ce40  89448fec               -mov dword ptr [edi + ecx*4 - 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047ce44:
    // 0047ce44  8b448ef0               -mov eax, dword ptr [esi + ecx*4 - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4);
    // 0047ce48  89448ff0               -mov dword ptr [edi + ecx*4 - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047ce4c:
    // 0047ce4c  8b448ef4               -mov eax, dword ptr [esi + ecx*4 - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4);
    // 0047ce50  89448ff4               -mov dword ptr [edi + ecx*4 - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047ce54:
    // 0047ce54  8b448ef8               -mov eax, dword ptr [esi + ecx*4 - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4);
    // 0047ce58  89448ff8               -mov dword ptr [edi + ecx*4 - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047ce5c:
    // 0047ce5c  8b448efc               -mov eax, dword ptr [esi + ecx*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 0047ce60  89448ffc               -mov dword ptr [edi + ecx*4 - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 0047ce64  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0047ce6b  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ce6d  03f8                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
  [[fallthrough]];
  case 0x0047ce6f:
    // 0047ce6f  ff249578ce4700         -jmp dword ptr [edx*4 + 0x47ce78]
    cpu.ip = app->getMemory<x86::reg32>(4705912 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047ce88:
    // 0047ce88  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ce8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce8d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce8e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047ce90:
    // 0047ce90  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047ce92  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047ce94  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ce97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce99  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce9a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047ce9c:
    // 0047ce9c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047ce9e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047cea0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047cea3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047cea6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047cea9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceab  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceac  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047ceb0:
    // 0047ceb0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047ceb2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047ceb4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047ceb7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047ceba  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047cebd  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047cec0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047cec3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cec8:
    // 0047cec8  8d7431fc               -lea esi, [ecx + esi - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 0047cecc  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 0047ced0  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0047ced6  7524                   -jne 0x47cefc
    if (!cpu.flags.zf)
    {
        goto L_0x0047cefc;
    }
    // 0047ced8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cedb  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cede  83f908                 +cmp ecx, 8
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
    // 0047cee1  720d                   -jb 0x47cef0
    if (cpu.flags.cf)
    {
        goto L_0x0047cef0;
    }
    // 0047cee3  fd                     -std 
    cpu.flags.df = 1;
    // 0047cee4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cee6  fc                     -cld 
    cpu.flags.df = 0;
    // 0047cee7  ff249510d04700         -jmp dword ptr [edx*4 + 0x47d010]
    cpu.ip = app->getMemory<x86::reg32>(4706320 + cpu.edx * 4); goto dynamic_jump;
L_0x0047cef0:
    // 0047cef0  f7d9                   +neg ecx
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
    // 0047cef2  ff248dc0cf4700         -jmp dword ptr [ecx*4 + 0x47cfc0]
    cpu.ip = app->getMemory<x86::reg32>(4706240 + cpu.ecx * 4); goto dynamic_jump;
L_0x0047cefc:
    // 0047cefc  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047cefe  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047cf03  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cf06  720c                   -jb 0x47cf14
    if (cpu.flags.cf)
    {
        goto L_0x0047cf14;
    }
    // 0047cf08  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cf0b  2bc8                   +sub ecx, eax
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
    // 0047cf0d  ff248518cf4700         -jmp dword ptr [eax*4 + 0x47cf18]
    cpu.ip = app->getMemory<x86::reg32>(4706072 + cpu.eax * 4); goto dynamic_jump;
L_0x0047cf14:
    // 0047cf14  ff248d10d04700         -jmp dword ptr [ecx*4 + 0x47d010]
    cpu.ip = app->getMemory<x86::reg32>(4706320 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0047cf28:
    // 0047cf28  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0047cf2b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cf2d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047cf30  4e                     -dec esi
    (cpu.esi)--;
    // 0047cf31  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cf34  4f                     -dec edi
    (cpu.edi)--;
    // 0047cf35  83f908                 +cmp ecx, 8
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
    // 0047cf38  72b6                   -jb 0x47cef0
    if (cpu.flags.cf)
    {
        goto L_0x0047cef0;
    }
    // 0047cf3a  fd                     -std 
    cpu.flags.df = 1;
    // 0047cf3b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cf3d  fc                     -cld 
    cpu.flags.df = 0;
    // 0047cf3e  ff249510d04700         -jmp dword ptr [edx*4 + 0x47d010]
    cpu.ip = app->getMemory<x86::reg32>(4706320 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047cf48:
    // 0047cf48  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0047cf4b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cf4d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047cf50  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047cf53  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cf56  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047cf59  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cf5c  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cf5f  83f908                 +cmp ecx, 8
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
    // 0047cf62  728c                   -jb 0x47cef0
    if (cpu.flags.cf)
    {
        goto L_0x0047cef0;
    }
    // 0047cf64  fd                     -std 
    cpu.flags.df = 1;
    // 0047cf65  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cf67  fc                     -cld 
    cpu.flags.df = 0;
    // 0047cf68  ff249510d04700         -jmp dword ptr [edx*4 + 0x47d010]
    cpu.ip = app->getMemory<x86::reg32>(4706320 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047cf70:
    // 0047cf70  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0047cf73  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cf75  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047cf78  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047cf7b  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047cf7e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047cf81  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cf84  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047cf87  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cf8a  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cf8d  83f908                 +cmp ecx, 8
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
    // 0047cf90  0f825affffff           -jb 0x47cef0
    if (cpu.flags.cf)
    {
        goto L_0x0047cef0;
    }
    // 0047cf96  fd                     -std 
    cpu.flags.df = 1;
    // 0047cf97  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cf99  fc                     -cld 
    cpu.flags.df = 0;
    // 0047cf9a  ff249510d04700         -jmp dword ptr [edx*4 + 0x47d010]
    cpu.ip = app->getMemory<x86::reg32>(4706320 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047cfc4:
    // 0047cfc4  8b448e1c               -mov eax, dword ptr [esi + ecx*4 + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4);
    // 0047cfc8  89448f1c               -mov dword ptr [edi + ecx*4 + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047cfcc:
    // 0047cfcc  8b448e18               -mov eax, dword ptr [esi + ecx*4 + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4);
    // 0047cfd0  89448f18               -mov dword ptr [edi + ecx*4 + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047cfd4:
    // 0047cfd4  8b448e14               -mov eax, dword ptr [esi + ecx*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4);
    // 0047cfd8  89448f14               -mov dword ptr [edi + ecx*4 + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047cfdc:
    // 0047cfdc  8b448e10               -mov eax, dword ptr [esi + ecx*4 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4);
    // 0047cfe0  89448f10               -mov dword ptr [edi + ecx*4 + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047cfe4:
    // 0047cfe4  8b448e0c               -mov eax, dword ptr [esi + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 0047cfe8  89448f0c               -mov dword ptr [edi + ecx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047cfec:
    // 0047cfec  8b448e08               -mov eax, dword ptr [esi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 0047cff0  89448f08               -mov dword ptr [edi + ecx*4 + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0047cff4:
    // 0047cff4  8b448e04               -mov eax, dword ptr [esi + ecx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 0047cff8  89448f04               -mov dword ptr [edi + ecx*4 + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 0047cffc  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0047d003  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047d005  03f8                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
  [[fallthrough]];
  case 0x0047d007:
    // 0047d007  ff249510d04700         -jmp dword ptr [edx*4 + 0x47d010]
    cpu.ip = app->getMemory<x86::reg32>(4706320 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047d020:
    // 0047d020  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d023  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d024  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d025  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d026  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047d028:
    // 0047d028  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0047d02b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047d02e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d031  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d032  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d033  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d034  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047d038:
    // 0047d038  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0047d03b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047d03e  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047d041  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047d044  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d047  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d048  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d049  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d04a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047d04c:
    // 0047d04c  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0047d04f  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047d052  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047d055  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047d058  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047d05b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047d05e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d061  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d062  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d063  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d064  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_47d065(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d065  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d066  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047d068  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0047d06a  68507e4800             -push 0x487e50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750928 /*0x487e50*/;
    cpu.esp -= 4;
    // 0047d06f  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 0047d074  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0047d07a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d07b  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 0047d082  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047d085  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d086  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d087  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d088  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047d08b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d08d  393ddceb5100           +cmp dword ptr [0x51ebdc], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368796) /* 0x51ebdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d093  7546                   -jne 0x47d0db
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0db;
    }
    // 0047d095  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d096  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d097  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d099  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d09a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d09b  68487e4800             -push 0x487e48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750920 /*0x487e48*/;
    cpu.esp -= 4;
    // 0047d0a0  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
    // 0047d0a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d0a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d0a7  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d0ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d0af  7408                   -je 0x47d0b9
    if (cpu.flags.zf)
    {
        goto L_0x0047d0b9;
    }
    // 0047d0b1  891ddceb5100           -mov dword ptr [0x51ebdc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5368796) /* 0x51ebdc */) = cpu.ebx;
    // 0047d0b7  eb22                   -jmp 0x47d0db
    goto L_0x0047d0db;
L_0x0047d0b9:
    // 0047d0b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d0ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d0bb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d0bc  68447e4800             -push 0x487e44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750916 /*0x487e44*/;
    cpu.esp -= 4;
    // 0047d0c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d0c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d0c3  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d0c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d0cb  0f8422010000           -je 0x47d1f3
    if (cpu.flags.zf)
    {
        return sub_47d1f3(app, cpu);
    }
    // 0047d0d1  c705dceb510002000000   -mov dword ptr [0x51ebdc], 2
    app->getMemory<x86::reg32>(x86::reg32(5368796) /* 0x51ebdc */) = 2 /*0x2*/;
L_0x0047d0db:
    // 0047d0db  397d14                 +cmp dword ptr [ebp + 0x14], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d0de  7e10                   -jle 0x47d0f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d0f0;
    }
    // 0047d0e0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047d0e3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047d0e6  e8932b0000             -call 0x47fc7e
    cpu.esp -= 4;
    sub_47fc7e(app, cpu);
    // 0047d0eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0ed  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0047d0f0:
    // 0047d0f0  a1dceb5100             -mov eax, dword ptr [0x51ebdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368796) /* 0x51ebdc */);
    // 0047d0f5  83f802                 +cmp eax, 2
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
    // 0047d0f8  751d                   -jne 0x47d117
    if (!cpu.flags.zf)
    {
        goto L_0x0047d117;
    }
    // 0047d0fa  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047d0fd  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047d100  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047d103  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047d106  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d109  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d10c  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d112  e9de000000             -jmp 0x47d1f5
    return sub_47d1f5(app, cpu);
L_0x0047d117:
    // 0047d117  83f801                 +cmp eax, 1
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
    // 0047d11a  0f85d3000000           -jne 0x47d1f3
    if (!cpu.flags.zf)
    {
        return sub_47d1f3(app, cpu);
    }
    // 0047d120  397d20                 +cmp dword ptr [ebp + 0x20], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d123  7508                   -jne 0x47d12d
    if (!cpu.flags.zf)
    {
        goto L_0x0047d12d;
    }
    // 0047d125  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 0047d12a  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0047d12d:
    // 0047d12d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d12e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d12f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047d132  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047d135  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0047d138  f7d8                   +neg eax
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
    // 0047d13a  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047d13c  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047d13f  40                     -inc eax
    (cpu.eax)++;
    // 0047d140  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d141  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047d144  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d14a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d14c  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 0047d14f  3bdf                   +cmp ebx, edi
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
    // 0047d151  0f849c000000           -je 0x47d1f3
    if (cpu.flags.zf)
    {
        return sub_47d1f3(app, cpu);
    }
    // 0047d157  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0047d15a  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 0047d15d  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047d160  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047d162  e8c9abffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047d167  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047d16a  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d16c  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0047d16f  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047d173  eb13                   -jmp 0x47d188
    return sub_47d188(app, cpu);
}

/* align: skip  */
void Application::sub_47d175(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d175  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d177  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d178  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d179(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d179  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047d17c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d17e  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0047d181  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047d185  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0047d188  397ddc                 +cmp dword ptr [ebp - 0x24], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d18b  7466                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d18d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d18e  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d191  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047d194  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047d197  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d199  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047d19c  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1a4  744d                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1a9  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1ac  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1af  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1b2  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1b8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d1ba  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0047d1bd  3bf7                   +cmp esi, edi
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
    // 0047d1bf  7432                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1c1  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0047d1c5  7440                   -je 0x47d207
    if (cpu.flags.zf)
    {
        goto L_0x0047d207;
    }
    // 0047d1c7  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0047d1ca  0f84b2000000           -je 0x47d282
    if (cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
    // 0047d1d0  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0047d1d3  7f1e                   -jg 0x47d1f3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d1f3;
    }
    // 0047d1d5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047d1d8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047d1db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1dc  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1df  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1e2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1e5  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1ed  0f858f000000           -jne 0x47d282
    if (!cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
L_0x0047d1f3:
    // 0047d1f3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d1f5  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0047d1f8  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047d1fb  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047d202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d205  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d206  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d207:
    // 0047d207  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047d20e  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0047d211  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047d214  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047d216  e815abffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047d21b  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047d21e  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047d220  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0047d223  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047d227  eb12                   -jmp 0x47d23b
    return sub_47d23b(app, cpu);
}

/* align: skip  */
void Application::sub_47d1f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047d1f5;
    // 0047d179  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047d17c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d17e  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0047d181  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047d185  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0047d188  397ddc                 +cmp dword ptr [ebp - 0x24], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d18b  7466                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d18d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d18e  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d191  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047d194  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047d197  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d199  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047d19c  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1a4  744d                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1a9  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1ac  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1af  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1b2  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1b8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d1ba  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0047d1bd  3bf7                   +cmp esi, edi
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
    // 0047d1bf  7432                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1c1  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0047d1c5  7440                   -je 0x47d207
    if (cpu.flags.zf)
    {
        goto L_0x0047d207;
    }
    // 0047d1c7  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0047d1ca  0f84b2000000           -je 0x47d282
    if (cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
    // 0047d1d0  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0047d1d3  7f1e                   -jg 0x47d1f3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d1f3;
    }
    // 0047d1d5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047d1d8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047d1db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1dc  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1df  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1e2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1e5  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1ed  0f858f000000           -jne 0x47d282
    if (!cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
L_0x0047d1f3:
    // 0047d1f3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_entry_0x0047d1f5:
    // 0047d1f5  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0047d1f8  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047d1fb  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047d202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d205  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d206  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d207:
    // 0047d207  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047d20e  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0047d211  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047d214  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047d216  e815abffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047d21b  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047d21e  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047d220  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0047d223  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047d227  eb12                   -jmp 0x47d23b
    return sub_47d23b(app, cpu);
}

/* align: skip  */
void Application::sub_47d1f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047d1f3;
    // 0047d179  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047d17c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d17e  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0047d181  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047d185  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0047d188  397ddc                 +cmp dword ptr [ebp - 0x24], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d18b  7466                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d18d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d18e  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d191  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047d194  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047d197  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d199  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047d19c  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1a4  744d                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1a9  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1ac  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1af  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1b2  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1b8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d1ba  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0047d1bd  3bf7                   +cmp esi, edi
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
    // 0047d1bf  7432                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1c1  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0047d1c5  7440                   -je 0x47d207
    if (cpu.flags.zf)
    {
        goto L_0x0047d207;
    }
    // 0047d1c7  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0047d1ca  0f84b2000000           -je 0x47d282
    if (cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
    // 0047d1d0  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0047d1d3  7f1e                   -jg 0x47d1f3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d1f3;
    }
    // 0047d1d5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047d1d8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047d1db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1dc  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1df  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1e2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1e5  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1ed  0f858f000000           -jne 0x47d282
    if (!cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
L_0x0047d1f3:
L_entry_0x0047d1f3:
    // 0047d1f3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d1f5  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0047d1f8  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047d1fb  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047d202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d205  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d206  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d207:
    // 0047d207  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047d20e  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0047d211  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047d214  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047d216  e815abffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047d21b  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047d21e  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047d220  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0047d223  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047d227  eb12                   -jmp 0x47d23b
    return sub_47d23b(app, cpu);
}

/* align: skip  */
void Application::sub_47d188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047d188;
    // 0047d179  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0047d17c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d17e  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0047d181  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047d185  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
L_entry_0x0047d188:
    // 0047d188  397ddc                 +cmp dword ptr [ebp - 0x24], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d18b  7466                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d18d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d18e  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d191  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047d194  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047d197  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d199  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047d19c  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1a4  744d                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1a9  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1ac  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1af  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1b2  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1b8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d1ba  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 0047d1bd  3bf7                   +cmp esi, edi
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
    // 0047d1bf  7432                   -je 0x47d1f3
    if (cpu.flags.zf)
    {
        goto L_0x0047d1f3;
    }
    // 0047d1c1  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0047d1c5  7440                   -je 0x47d207
    if (cpu.flags.zf)
    {
        goto L_0x0047d207;
    }
    // 0047d1c7  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 0047d1ca  0f84b2000000           -je 0x47d282
    if (cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
    // 0047d1d0  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 0047d1d3  7f1e                   -jg 0x47d1f3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d1f3;
    }
    // 0047d1d5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0047d1d8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047d1db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1dc  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047d1df  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047d1e2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047d1e5  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047d1eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1ed  0f858f000000           -jne 0x47d282
    if (!cpu.flags.zf)
    {
        return sub_47d282(app, cpu);
    }
L_0x0047d1f3:
    // 0047d1f3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d1f5  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0047d1f8  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047d1fb  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0047d202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d205  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d206  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d207:
    // 0047d207  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047d20e  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0047d211  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047d214  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047d216  e815abffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 0047d21b  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0047d21e  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047d220  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0047d223  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047d227  eb12                   -jmp 0x47d23b
    return sub_47d23b(app, cpu);
}

/* align: skip  */
void Application::sub_47d229(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d229  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d22b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d22c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d22d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
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
    // 0047d282  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d284  e96cffffff             -jmp 0x47d1f5
    return sub_47d1f5(app, cpu);
}

/* align: skip  */
void Application::sub_47d23b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047d23b;
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
L_entry_0x0047d23b:
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
    // 0047d282  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d284  e96cffffff             -jmp 0x47d1f5
    return sub_47d1f5(app, cpu);
}

}
