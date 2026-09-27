#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_476d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476d40  e813000000             -call 0x476d58
    cpu.esp -= 4;
    sub_476d58(app, cpu);
    // 00476d45  e8ab380000             -call 0x47a5f5
    cpu.esp -= 4;
    sub_47a5f5(app, cpu);
    // 00476d4a  a3e0ea5100             -mov dword ptr [0x51eae0], eax
    app->getMemory<x86::reg32>(x86::reg32(5368544) /* 0x51eae0 */) = cpu.eax;
    // 00476d4f  e851380000             -call 0x47a5a5
    cpu.esp -= 4;
    sub_47a5a5(app, cpu);
    // 00476d54  dbe2                   -fnclex 
    /*nothing*/;
    // 00476d56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476d57(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476d57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476d58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476d58  b8cea94700             -mov eax, 0x47a9ce
    cpu.eax = 4696526 /*0x47a9ce*/;
    // 00476d5d  c705bc3f4a0078a64700   -mov dword ptr [0x4a3fbc], 0x47a678
    app->getMemory<x86::reg32>(x86::reg32(4865980) /* 0x4a3fbc */) = 4695672 /*0x47a678*/;
    // 00476d67  a3b83f4a00             -mov dword ptr [0x4a3fb8], eax
    app->getMemory<x86::reg32>(x86::reg32(4865976) /* 0x4a3fb8 */) = cpu.eax;
    // 00476d6c  c705c03f4a00dea64700   -mov dword ptr [0x4a3fc0], 0x47a6de
    app->getMemory<x86::reg32>(x86::reg32(4865984) /* 0x4a3fc0 */) = 4695774 /*0x47a6de*/;
    // 00476d76  c705c43f4a001ea64700   -mov dword ptr [0x4a3fc4], 0x47a61e
    app->getMemory<x86::reg32>(x86::reg32(4865988) /* 0x4a3fc4 */) = 4695582 /*0x47a61e*/;
    // 00476d80  c705c83f4a00c6a64700   -mov dword ptr [0x4a3fc8], 0x47a6c6
    app->getMemory<x86::reg32>(x86::reg32(4865992) /* 0x4a3fc8 */) = 4695750 /*0x47a6c6*/;
    // 00476d8a  a3cc3f4a00             -mov dword ptr [0x4a3fcc], eax
    app->getMemory<x86::reg32>(x86::reg32(4865996) /* 0x4a3fcc */) = cpu.eax;
    // 00476d8f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__ftol(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476d90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476d91  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00476d93  83c4f4                 -add esp, -0xc
    (cpu.esp) += x86::reg32(x86::sreg32(-12 /*-0xc*/));
    // 00476d96  9b                     -wait 
    /*nothing*/;
    // 00476d97  d97dfe                 -fnstcw word ptr [ebp - 2]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.fpu.control.word;
    // 00476d9a  9b                     -wait 
    /*nothing*/;
    // 00476d9b  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00476d9f  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00476da2  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
    // 00476da6  d96dfc                 -fldcw word ptr [ebp - 4]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00476da9  df7df4                 -fistp qword ptr [ebp - 0xc]
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(-12) /* -0xc */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00476dac  d96dfe                 -fldcw word ptr [ebp - 2]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00476daf  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00476db2  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00476db5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476db6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476db7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476db7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476db8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476db9  be283d4a00             -mov esi, 0x4a3d28
    cpu.esi = 4865320 /*0x4a3d28*/;
    // 00476dbe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476dbf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476dc0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00476dc2  e8f10d0000             -call 0x477bb8
    cpu.esp -= 4;
    sub_477bb8(app, cpu);
    // 00476dc7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476dc8  e8773c0000             -call 0x47aa44
    cpu.esp -= 4;
    sub_47aa44(app, cpu);
    // 00476dcd  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00476dcf  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00476dd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476dd4  ff742420               -push dword ptr [esp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00476dd8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476dd9  e81d3d0000             -call 0x47aafb
    cpu.esp -= 4;
    sub_47aafb(app, cpu);
    // 00476dde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476ddf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476de0  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476de2  e8ea3c0000             -call 0x47aad1
    cpu.esp -= 4;
    sub_47aad1(app, cpu);
    // 00476de7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476de8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00476dea  e81b0e0000             -call 0x477c0a
    cpu.esp -= 4;
    sub_477c0a(app, cpu);
    // 00476def  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00476df2  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476df4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476df5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476df6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476df7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476df8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476df8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476df9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00476dfb  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00476dfe  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00476e01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476e02  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00476e05  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00476e08  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00476e0b  c745ec42000000         -mov dword ptr [ebp - 0x14], 0x42
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 66 /*0x42*/;
    // 00476e12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476e13  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00476e16  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00476e19  c745e4ffffff7f         -mov dword ptr [ebp - 0x1c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 2147483647 /*0x7fffffff*/;
    // 00476e20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476e21  e8d53c0000             -call 0x47aafb
    cpu.esp -= 4;
    sub_47aafb(app, cpu);
    // 00476e26  83c40c                 +add esp, 0xc
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
    // 00476e29  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476e2c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476e2e  7808                   -js 0x476e38
    if (cpu.flags.sf)
    {
        goto L_0x00476e38;
    }
    // 00476e30  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00476e33  802000                 +and byte ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00476e36  eb0d                   -jmp 0x476e45
    goto L_0x00476e45;
L_0x00476e38:
    // 00476e38  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00476e3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476e3c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476e3e  e8a5440000             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 00476e43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00476e45:
    // 00476e45  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476e47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e48  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476e4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476e4a  e818460000             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00476e4f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476e53  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00476e56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_rand(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476e57  e80b460000             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00476e5c  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00476e5f  69c9fd430300           -imul ecx, ecx, 0x343fd
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(214013 /*0x343fd*/)));
    // 00476e65  81c1c39e2600           -add ecx, 0x269ec3
    (cpu.ecx) += x86::reg32(x86::sreg32(2531011 /*0x269ec3*/));
    // 00476e6b  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00476e6e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00476e70  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00476e73  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 00476e78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476e80  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00476e83  dd1424                 -fst qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    // 00476e86  e8fd480000             -call 0x47b788
    cpu.esp -= 4;
    sub_47b788(app, cpu);
    // 00476e8b  e80d000000             -call 0x476e9d
    cpu.esp -= 4;
    sub_476e9d(app, cpu);
    // 00476e90  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00476e93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476e9d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476e9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476e9e  9b                     -wait 
    /*nothing*/;
    // 00476e9f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00476ea2  746d                   -je 0x476f11
    if (cpu.flags.zf)
    {
        goto L_0x00476f11;
    }
    // 00476ea4  66813c247f02           +cmp word ptr [esp], 0x27f
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(639 /*0x27f*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00476eaa  7405                   -je 0x476eb1
    if (cpu.flags.zf)
    {
        goto L_0x00476eb1;
    }
    // 00476eac  e864480000             -call 0x47b715
    cpu.esp -= 4;
    sub_47b715(app, cpu);
L_0x00476eb1:
    // 00476eb1  3d0000f03f             +cmp eax, 0x3ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1072693248 /*0x3ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476eb6  732d                   -jae 0x476ee5
    if (!cpu.flags.cf)
    {
        goto L_0x00476ee5;
    }
    // 00476eb8  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00476eba  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00476ebc  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00476ebe  d8e2                   -fsub st(2)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(2));
    // 00476ec0  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00476ec2  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 00476ec4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00476ec6  d9f3                   -fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
L_0x00476ec8:
    // 00476ec8  833ddcea510000         +cmp dword ptr [0x51eadc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368540) /* 0x51eadc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476ecf  0f85c9480000           -jne 0x47b79e
    if (!cpu.flags.zf)
    {
        goto L_0x0047b79e;
    }
    // 00476ed5  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 00476eda  8d0d003d4a00           -lea ecx, [0x4a3d00]
    cpu.ecx = x86::reg32(x86::reg32(4865280) /* 0x4a3d00 */);
    // 00476ee0  e9c6480000             -jmp 0x47b7ab
    return __math_exit(app, cpu);
L_0x00476ee5:
    // 00476ee5  7738                   -ja 0x476f1f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00476f1f;
    }
    // 00476ee7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476eeb  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476eed  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00476ef2  0b442408               +or eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 00476ef6  7527                   -jne 0x476f1f
    if (!cpu.flags.zf)
    {
        goto L_0x00476f1f;
    }
    // 00476ef8  81e100000080           +and ecx, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 00476efe  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00476f00  7404                   -je 0x476f06
    if (cpu.flags.zf)
    {
        goto L_0x00476f06;
    }
    // 00476f02  d9eb                   +fldpi 
    cpu.fpu.push(3.1415926535897932);
    // 00476f04  ebc2                   -jmp 0x476ec8
    goto L_0x00476ec8;
L_0x00476f06:
    // 00476f06  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00476f08  ebbe                   -jmp 0x476ec8
    goto L_0x00476ec8;
L_0x00476f0a:
    // 00476f0a  e81d480000             -call 0x47b72c
    cpu.esp -= 4;
    sub_47b72c(app, cpu);
    // 00476f0f  eb1b                   -jmp 0x476f2c
    goto L_0x00476f2c;
L_0x00476f11:
    // 00476f11  a9ffff0f00             +test eax, 0xfffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1048575 /*0xfffff*/));
    // 00476f16  75f2                   -jne 0x476f0a
    if (!cpu.flags.zf)
    {
        goto L_0x00476f0a;
    }
    // 00476f18  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476f1d  75eb                   -jne 0x476f0a
    if (!cpu.flags.zf)
    {
        goto L_0x00476f0a;
    }
L_0x00476f1f:
    // 00476f1f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00476f21  db2de03f4a00           -fld xword ptr [0x4a3fe0]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(4866016) /* 0x4a3fe0 */)));
    // 00476f27  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00476f2c:
    // 00476f2c  833ddcea510000         +cmp dword ptr [0x51eadc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368540) /* 0x51eadc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476f33  0f8565480000           -jne 0x47b79e
    if (!cpu.flags.zf)
    {
        goto L_0x0047b79e;
    }
    // 00476f39  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 00476f3e  8d0d003d4a00           -lea ecx, [0x4a3d00]
    cpu.ecx = x86::reg32(x86::reg32(4865280) /* 0x4a3d00 */);
    // 00476f44  e86e470000             -call 0x47b6b7
    cpu.esp -= 4;
    __startOneArgErrorHandling(app, cpu);
    // 00476f49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b79e:
    // 0047b79e  66813c247f02           +cmp word ptr [esp], 0x27f
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(639 /*0x27f*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047b7a4  7403                   -je 0x47b7a9
    if (cpu.flags.zf)
    {
        goto L_0x0047b7a9;
    }
    // 0047b7a6  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
L_0x0047b7a9:
    // 0047b7a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476f4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476f4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476f4c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00476f4e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00476f50  68887c4800             -push 0x487c88
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750472 /*0x487c88*/;
    cpu.esp -= 4;
    // 00476f55  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 00476f5a  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00476f60  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476f61  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00476f68  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00476f6b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476f6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476f6d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476f6e  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00476f71  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00476f73  3bdf                   +cmp ebx, edi
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
    // 00476f75  750e                   -jne 0x476f85
    if (!cpu.flags.zf)
    {
        goto L_0x00476f85;
    }
    // 00476f77  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00476f7a  e8fb020000             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00476f7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f80  e9e6020000             -jmp 0x47726b
    goto L_0x0047726b;
L_0x00476f85:
    // 00476f85  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00476f88  3bf7                   +cmp esi, edi
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
    // 00476f8a  750c                   -jne 0x476f98
    if (!cpu.flags.zf)
    {
        goto L_0x00476f98;
    }
    // 00476f8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476f8d  e822040000             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00476f92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f93  e9d1020000             -jmp 0x477269
    goto L_0x00477269;
L_0x00476f98:
    // 00476f98  a1f01f5200             -mov eax, dword ptr [0x521ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382128) /* 0x521ff0 */);
    // 00476f9d  83f803                 +cmp eax, 3
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
    // 00476fa0  0f8539010000           -jne 0x4770df
    if (!cpu.flags.zf)
    {
        goto L_0x004770df;
    }
L_0x00476fa6:
    // 00476fa6  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 00476fa9  83fee0                 +cmp esi, -0x20
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
    // 00476fac  0f87f1000000           -ja 0x4770a3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004770a3;
    }
    // 00476fb2  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00476fb4  e8105b0000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00476fb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fba  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00476fbd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476fbe  e811490000             -call 0x47b8d4
    cpu.esp -= 4;
    sub_47b8d4(app, cpu);
    // 00476fc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fc4  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00476fc7  3bc7                   +cmp eax, edi
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
    // 00476fc9  0f84a4000000           -je 0x477073
    if (cpu.flags.zf)
    {
        goto L_0x00477073;
    }
    // 00476fcf  3b350c205200           +cmp esi, dword ptr [0x52200c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382156) /* 0x52200c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476fd5  774c                   -ja 0x477023
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00477023;
    }
    // 00476fd7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476fd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476fd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476fda  e8fe500000             -call 0x47c0dd
    cpu.esp -= 4;
    sub_47c0dd(app, cpu);
    // 00476fdf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476fe2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476fe4  7405                   -je 0x476feb
    if (cpu.flags.zf)
    {
        goto L_0x00476feb;
    }
    // 00476fe6  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 00476fe9  eb38                   -jmp 0x477023
    goto L_0x00477023;
L_0x00476feb:
    // 00476feb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476fec  e8374c0000             -call 0x47bc28
    cpu.esp -= 4;
    sub_47bc28(app, cpu);
    // 00476ff1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ff2  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00476ff5  3bc7                   +cmp eax, edi
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
    // 00476ff7  742a                   -je 0x477023
    if (cpu.flags.zf)
    {
        goto L_0x00477023;
    }
    // 00476ff9  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00476ffc  48                     -dec eax
    (cpu.eax)--;
    // 00476ffd  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00477000  3bc6                   +cmp eax, esi
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
    // 00477002  7202                   -jb 0x477006
    if (cpu.flags.cf)
    {
        goto L_0x00477006;
    }
    // 00477004  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00477006:
    // 00477006  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477007  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477008  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0047700b  e8205d0000             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 00477010  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477011  e8be480000             -call 0x47b8d4
    cpu.esp -= 4;
    sub_47b8d4(app, cpu);
    // 00477016  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00477019  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047701a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047701b  e8df480000             -call 0x47b8ff
    cpu.esp -= 4;
    sub_47b8ff(app, cpu);
    // 00477020  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x00477023:
    // 00477023  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 00477026  754b                   -jne 0x477073
    if (!cpu.flags.zf)
    {
        goto L_0x00477073;
    }
    // 00477028  3bf7                   +cmp esi, edi
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
    // 0047702a  7506                   -jne 0x477032
    if (!cpu.flags.zf)
    {
        goto L_0x00477032;
    }
    // 0047702c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047702e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047702f  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x00477032:
    // 00477032  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00477035  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 00477038  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047703b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047703c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047703d  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 00477043  ff15e0704800           -call dword ptr [0x4870e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747488) /* 0x4870e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477049  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0047704c  3bc7                   +cmp eax, edi
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
    // 0047704e  7423                   -je 0x477073
    if (cpu.flags.zf)
    {
        goto L_0x00477073;
    }
    // 00477050  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00477053  48                     -dec eax
    (cpu.eax)--;
    // 00477054  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00477057  3bc6                   +cmp eax, esi
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
    // 00477059  7202                   -jb 0x47705d
    if (cpu.flags.cf)
    {
        goto L_0x0047705d;
    }
    // 0047705b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047705d:
    // 0047705d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047705e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047705f  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00477062  e8c95c0000             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 00477067  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477068  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 0047706b  e88f480000             -call 0x47b8ff
    cpu.esp -= 4;
    sub_47b8ff(app, cpu);
    // 00477070  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00477073:
    // 00477073  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00477077  e85a000000             -call 0x4770d6
    cpu.esp -= 4;
    sub_4770d6(app, cpu);
    // 0047707c  397dd8                 +cmp dword ptr [ebp - 0x28], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047707f  7522                   -jne 0x4770a3
    if (!cpu.flags.zf)
    {
        goto L_0x004770a3;
    }
    // 00477081  3bf7                   +cmp esi, edi
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
    // 00477083  7503                   -jne 0x477088
    if (!cpu.flags.zf)
    {
        goto L_0x00477088;
    }
    // 00477085  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477087  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477088:
    // 00477088  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047708b  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0047708e  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00477091  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477092  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477093  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477094  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047709a  ff159c714800           -call dword ptr [0x48719c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747676) /* 0x48719c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004770a0  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_0x004770a3:
    // 004770a3  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004770a6  3bc7                   +cmp eax, edi
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
    // 004770a8  0f85bd010000           -jne 0x47726b
    if (!cpu.flags.zf)
    {
        goto L_0x0047726b;
    }
    // 004770ae  393daceb5100           +cmp dword ptr [0x51ebac], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368748) /* 0x51ebac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004770b4  0f84b1010000           -je 0x47726b
    if (cpu.flags.zf)
    {
        goto L_0x0047726b;
    }
    // 004770ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004770bb  e87f5a0000             -call 0x47cb3f
    cpu.esp -= 4;
    sub_47cb3f(app, cpu);
    // 004770c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004770c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004770c3  0f85ddfeffff           -jne 0x476fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00476fa6;
    }
    // 004770c9  e99b010000             -jmp 0x477269
    goto L_0x00477269;
L_0x004770df:
    // 004770df  83f802                 +cmp eax, 2
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
    // 004770e2  0f8547010000           -jne 0x47722f
    if (!cpu.flags.zf)
    {
        goto L_0x0047722f;
    }
    // 004770e8  83fee0                 +cmp esi, -0x20
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
    // 004770eb  7712                   -ja 0x4770ff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004770ff;
    }
    // 004770ed  3bf7                   +cmp esi, edi
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
    // 004770ef  7608                   -jbe 0x4770f9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004770f9;
    }
    // 004770f1  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004770f4  83e6f0                 +and esi, 0xfffffff0
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/))));
    // 004770f7  eb03                   -jmp 0x4770fc
    goto L_0x004770fc;
L_0x004770f9:
    // 004770f9  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004770fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004770fc:
    // 004770fc  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x004770ff:
    // 004770ff  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 00477102  83fee0                 +cmp esi, -0x20
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
    // 00477105  0f87f3000000           -ja 0x4771fe
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004771fe;
    }
    // 0047710b  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047710d  e8b7590000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00477112  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477113  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047711a  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0047711d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047711e  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00477121  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477122  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477123  e807550000             -call 0x47c62f
    cpu.esp -= 4;
    sub_47c62f(app, cpu);
    // 00477128  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047712b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047712d  897dd0                 -mov dword ptr [ebp - 0x30], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.edi;
    // 00477130  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00477132  0f84aa000000           -je 0x4771e2
    if (cpu.flags.zf)
    {
        goto L_0x004771e2;
    }
    // 00477138  3b3534604a00           +cmp esi, dword ptr [0x4a6034]
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
    // 0047713e  735c                   -jae 0x47719c
    if (!cpu.flags.cf)
    {
        goto L_0x0047719c;
    }
    // 00477140  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00477142  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 00477145  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477146  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477147  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 0047714a  ff75c8                 -push dword ptr [ebp - 0x38]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    cpu.esp -= 4;
    // 0047714d  e8a5580000             -call 0x47c9f7
    cpu.esp -= 4;
    sub_47c9f7(app, cpu);
    // 00477152  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477155  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477157  7408                   -je 0x477161
    if (cpu.flags.zf)
    {
        goto L_0x00477161;
    }
    // 00477159  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047715c  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0047715f  eb38                   -jmp 0x477199
    goto L_0x00477199;
L_0x00477161:
    // 00477161  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477162  e864550000             -call 0x47c6cb
    cpu.esp -= 4;
    sub_47c6cb(app, cpu);
    // 00477167  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477168  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0047716b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047716d  742a                   -je 0x477199
    if (cpu.flags.zf)
    {
        goto L_0x00477199;
    }
    // 0047716f  0fb607                 -movzx eax, byte ptr [edi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 00477172  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00477175  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00477178  3bc6                   +cmp eax, esi
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
    // 0047717a  7202                   -jb 0x47717e
    if (cpu.flags.cf)
    {
        goto L_0x0047717e;
    }
    // 0047717c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047717e:
    // 0047717e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047717f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477182  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00477185  e8a65b0000             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 0047718a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047718b  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 0047718e  ff75c8                 -push dword ptr [ebp - 0x38]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    cpu.esp -= 4;
    // 00477191  e8f0540000             -call 0x47c686
    cpu.esp -= 4;
    sub_47c686(app, cpu);
    // 00477196  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x00477199:
    // 00477199  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0047719c:
    // 0047719c  837ddc00               +cmp dword ptr [ebp - 0x24], 0
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
    // 004771a0  7553                   -jne 0x4771f5
    if (!cpu.flags.zf)
    {
        goto L_0x004771f5;
    }
    // 004771a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004771a3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004771a5  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 004771ab  ff15e0704800           -call dword ptr [0x4870e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747488) /* 0x4870e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004771b1  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004771b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004771b6  743d                   -je 0x4771f5
    if (cpu.flags.zf)
    {
        goto L_0x004771f5;
    }
    // 004771b8  0fb607                 -movzx eax, byte ptr [edi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004771bb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004771be  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004771c1  3bc6                   +cmp eax, esi
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
    // 004771c3  7202                   -jb 0x4771c7
    if (cpu.flags.cf)
    {
        goto L_0x004771c7;
    }
    // 004771c5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004771c7:
    // 004771c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004771c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004771c9  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004771cc  e85f5b0000             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 004771d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004771d2  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 004771d5  ff75c8                 -push dword ptr [ebp - 0x38]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    cpu.esp -= 4;
    // 004771d8  e8a9540000             -call 0x47c686
    cpu.esp -= 4;
    sub_47c686(app, cpu);
    // 004771dd  83c418                 +add esp, 0x18
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
    // 004771e0  eb13                   -jmp 0x4771f5
    goto L_0x004771f5;
L_0x004771e2:
    // 004771e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004771e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004771e4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004771e6  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 004771ec  ff159c714800           -call dword ptr [0x48719c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747676) /* 0x48719c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004771f2  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_0x004771f5:
    // 004771f5  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004771f9  e826000000             -call 0x477224
    cpu.esp -= 4;
    sub_477224(app, cpu);
L_0x004771fe:
    // 004771fe  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00477201  3bc7                   +cmp eax, edi
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
    // 00477203  7566                   -jne 0x47726b
    if (!cpu.flags.zf)
    {
        goto L_0x0047726b;
    }
    // 00477205  393daceb5100           +cmp dword ptr [0x51ebac], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368748) /* 0x51ebac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047720b  745e                   -je 0x47726b
    if (cpu.flags.zf)
    {
        goto L_0x0047726b;
    }
    // 0047720d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047720e  e82c590000             -call 0x47cb3f
    cpu.esp -= 4;
    sub_47cb3f(app, cpu);
    // 00477213  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477214  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477216  0f85e3feffff           -jne 0x4770ff
    if (!cpu.flags.zf)
    {
        goto L_0x004770ff;
    }
    // 0047721c  eb4b                   -jmp 0x477269
    goto L_0x00477269;
L_0x0047722f:
    // 0047722f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477231  83fee0                 +cmp esi, -0x20
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
    // 00477234  771c                   -ja 0x477252
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00477252;
    }
    // 00477236  3bf7                   +cmp esi, edi
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
    // 00477238  7503                   -jne 0x47723d
    if (!cpu.flags.zf)
    {
        goto L_0x0047723d;
    }
    // 0047723a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047723c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047723d:
    // 0047723d  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00477240  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 00477243  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477244  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477245  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477246  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047724c  ff159c714800           -call dword ptr [0x48719c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747676) /* 0x48719c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00477252:
    // 00477252  3bc7                   +cmp eax, edi
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
    // 00477254  7515                   -jne 0x47726b
    if (!cpu.flags.zf)
    {
        goto L_0x0047726b;
    }
    // 00477256  393daceb5100           +cmp dword ptr [0x51ebac], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368748) /* 0x51ebac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047725c  740d                   -je 0x47726b
    if (cpu.flags.zf)
    {
        goto L_0x0047726b;
    }
    // 0047725e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047725f  e8db580000             -call 0x47cb3f
    cpu.esp -= 4;
    sub_47cb3f(app, cpu);
    // 00477264  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477265  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477267  75c6                   -jne 0x47722f
    if (!cpu.flags.zf)
    {
        goto L_0x0047722f;
    }
L_0x00477269:
    // 00477269  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047726b:
    // 0047726b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047726e  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00477275  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477276  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477277  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477278  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477279  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4770ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004770ce  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004770d1  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004770d4  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    return sub_4770d6(app, cpu);
}

/* align: skip  */
void Application::sub_4770d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004770d6  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004770d8  e84d5a0000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 004770dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004770de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47721e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047721e  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00477221  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    return sub_477224(app, cpu);
}

/* align: skip  */
void Application::sub_477224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477224  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00477226  e8ff580000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047722b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047722c  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047722e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_malloc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047727a  ff35aceb5100           -push dword ptr [0x51ebac]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368748) /* 0x51ebac */);
    cpu.esp -= 4;
    // 00477280  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477284  e803000000             -call 0x47728c
    cpu.esp -= 4;
    __nh_malloc(app, cpu);
    // 00477289  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047728a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047728b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__nh_malloc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047728c  837c2404e0             +cmp dword ptr [esp + 4], -0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-32 /*-0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477291  7722                   -ja 0x4772b5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004772b5;
    }
L_0x00477293:
    // 00477293  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00477297  e81c000000             -call 0x4772b8
    cpu.esp -= 4;
    sub_4772b8(app, cpu);
    // 0047729c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047729e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047729f  7516                   -jne 0x4772b7
    if (!cpu.flags.zf)
    {
        goto L_0x004772b7;
    }
    // 004772a1  39442408               +cmp dword ptr [esp + 8], eax
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
    // 004772a5  7410                   -je 0x4772b7
    if (cpu.flags.zf)
    {
        goto L_0x004772b7;
    }
    // 004772a7  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004772ab  e88f580000             -call 0x47cb3f
    cpu.esp -= 4;
    sub_47cb3f(app, cpu);
    // 004772b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004772b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004772b3  75de                   -jne 0x477293
    if (!cpu.flags.zf)
    {
        goto L_0x00477293;
    }
L_0x004772b5:
    // 004772b5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004772b7:
    // 004772b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4772b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004772b9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004772bb  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004772bd  68a07c4800             -push 0x487ca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750496 /*0x487ca0*/;
    cpu.esp -= 4;
    // 004772c2  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 004772c7  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004772cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004772ce  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004772d5  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004772d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004772d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004772da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004772db  a1f01f5200             -mov eax, dword ptr [0x521ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382128) /* 0x521ff0 */);
    // 004772e0  83f803                 +cmp eax, 3
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
    // 004772e3  7543                   -jne 0x477328
    if (!cpu.flags.zf)
    {
        goto L_0x00477328;
    }
    // 004772e5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004772e8  3b350c205200           +cmp esi, dword ptr [0x52200c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382156) /* 0x52200c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004772ee  0f8793000000           -ja 0x477387
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00477387;
    }
    // 004772f4  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004772f6  e8ce570000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004772fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004772fc  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00477300  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477301  e822490000             -call 0x47bc28
    cpu.esp -= 4;
    sub_47bc28(app, cpu);
    // 00477306  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477307  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0047730a  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047730e  e80c000000             -call 0x47731f
    cpu.esp -= 4;
    sub_47731f(app, cpu);
    // 00477313  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00477316  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477318  746d                   -je 0x477387
    if (cpu.flags.zf)
    {
        goto L_0x00477387;
    }
    // 0047731a  e986000000             -jmp 0x4773a5
    goto L_0x004773a5;
L_0x00477328:
    // 00477328  83f802                 +cmp eax, 2
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
    // 0047732b  755a                   -jne 0x477387
    if (!cpu.flags.zf)
    {
        goto L_0x00477387;
    }
    // 0047732d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00477330  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477332  7408                   -je 0x47733c
    if (cpu.flags.zf)
    {
        goto L_0x0047733c;
    }
    // 00477334  8d700f                 -lea esi, [eax + 0xf]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(15) /* 0xf */);
    // 00477337  83e6f0                 +and esi, 0xfffffff0
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/))));
    // 0047733a  eb03                   -jmp 0x47733f
    goto L_0x0047733f;
L_0x0047733c:
    // 0047733c  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0047733e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047733f:
    // 0047733f  897508                 -mov dword ptr [ebp + 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00477342  3b3534604a00           +cmp esi, dword ptr [0x4a6034]
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
    // 00477348  772e                   -ja 0x477378
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00477378;
    }
    // 0047734a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047734c  e878570000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00477351  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477352  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00477359  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047735b  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047735e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047735f  e867530000             -call 0x47c6cb
    cpu.esp -= 4;
    sub_47c6cb(app, cpu);
    // 00477364  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477365  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00477368  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047736c  e80d000000             -call 0x47737e
    cpu.esp -= 4;
    sub_47737e(app, cpu);
    // 00477371  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00477374  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477376  752d                   -jne 0x4773a5
    if (!cpu.flags.zf)
    {
        goto L_0x004773a5;
    }
L_0x00477378:
    // 00477378  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477379  eb1c                   -jmp 0x477397
    goto L_0x00477397;
L_0x00477387:
    // 00477387  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047738a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047738c  7503                   -jne 0x477391
    if (!cpu.flags.zf)
    {
        goto L_0x00477391;
    }
    // 0047738e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477390  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477391:
    // 00477391  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00477394  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00477396  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x00477397:
    // 00477397  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477399  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 0047739f  ff15e0704800           -call dword ptr [0x4870e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747488) /* 0x4870e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004773a5:
    // 004773a5  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004773a8  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004773af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773b2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47731f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047731f  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00477321  e804580000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00477326  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477327  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47737b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047737b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    return sub_47737e(app, cpu);
}

/* align: skip  */
void Application::sub_47737e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047737e  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00477380  e8a5570000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00477385  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4773b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004773b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004773b5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004773b7  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004773b9  68b87c4800             -push 0x487cb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750520 /*0x487cb8*/;
    cpu.esp -= 4;
    // 004773be  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 004773c3  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004773c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004773ca  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004773d1  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004773d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004773d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004773d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004773d7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004773da  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004773dc  0f84ac000000           -je 0x47748e
    if (cpu.flags.zf)
    {
        goto L_0x0047748e;
    }
    // 004773e2  a1f01f5200             -mov eax, dword ptr [0x521ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382128) /* 0x521ff0 */);
    // 004773e7  83f803                 +cmp eax, 3
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
    // 004773ea  753b                   -jne 0x477427
    if (!cpu.flags.zf)
    {
        goto L_0x00477427;
    }
    // 004773ec  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004773ee  e8d6560000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004773f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773f4  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004773f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004773f9  e8d6440000             -call 0x47b8d4
    cpu.esp -= 4;
    sub_47b8d4(app, cpu);
    // 004773fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773ff  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00477402  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477404  7409                   -je 0x47740f
    if (cpu.flags.zf)
    {
        goto L_0x0047740f;
    }
    // 00477406  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477407  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477408  e8f2440000             -call 0x47b8ff
    cpu.esp -= 4;
    sub_47b8ff(app, cpu);
    // 0047740d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047740e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047740f:
    // 0047740f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00477413  e806000000             -call 0x47741e
    cpu.esp -= 4;
    sub_47741e(app, cpu);
    // 00477418  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 0047741c  eb51                   -jmp 0x47746f
    goto L_0x0047746f;
L_0x00477427:
    // 00477427  83f802                 +cmp eax, 2
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
    // 0047742a  7553                   -jne 0x47747f
    if (!cpu.flags.zf)
    {
        goto L_0x0047747f;
    }
    // 0047742c  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047742e  e896560000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00477433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477434  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0047743b  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047743e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047743f  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00477442  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477444  e8e6510000             -call 0x47c62f
    cpu.esp -= 4;
    sub_47c62f(app, cpu);
    // 00477449  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047744c  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0047744f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477451  740f                   -je 0x477462
    if (cpu.flags.zf)
    {
        goto L_0x00477462;
    }
    // 00477453  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477454  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00477457  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 0047745a  e827520000             -call 0x47c686
    cpu.esp -= 4;
    sub_47c686(app, cpu);
    // 0047745f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00477462:
    // 00477462  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00477466  e80b000000             -call 0x477476
    cpu.esp -= 4;
    sub_477476(app, cpu);
    // 0047746b  837ddc00               +cmp dword ptr [ebp - 0x24], 0
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
L_0x0047746f:
    // 0047746f  751d                   -jne 0x47748e
    if (!cpu.flags.zf)
    {
        goto L_0x0047748e;
    }
    // 00477471  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477474  eb0a                   -jmp 0x477480
    goto L_0x00477480;
L_0x0047747f:
    // 0047747f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00477480:
    // 00477480  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477482  ff35ec1f5200           -push dword ptr [0x521fec]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5382124) /* 0x521fec */);
    cpu.esp -= 4;
    // 00477488  ff15a4714800           -call dword ptr [0x4871a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747684) /* 0x4871a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047748e:
    // 0047748e  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00477491  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00477498  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477499  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047749a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047749b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047749c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47741e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047741e  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00477420  e805570000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00477425  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477426  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477476(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477476  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00477478  e8ad560000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047747d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047747e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47749d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047749d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047749e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004774a0  391dc4eb5100           +cmp dword ptr [0x51ebc4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004774a6  7513                   -jne 0x4774bb
    if (!cpu.flags.zf)
    {
        goto L_0x004774bb;
    }
    // 004774a8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004774ac  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004774af  7c59                   -jl 0x47750a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047750a;
    }
    // 004774b1  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004774b4  7f54                   -jg 0x47750a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047750a;
    }
    // 004774b6  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004774b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004774bb:
    // 004774bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004774bc  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 004774c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004774c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004774c3  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004774c9  391de41f5200           +cmp dword ptr [0x521fe4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004774cf  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 004774d5  740e                   -je 0x4774e5
    if (cpu.flags.zf)
    {
        goto L_0x004774e5;
    }
    // 004774d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004774d8  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004774da  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004774dc  e8e8550000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004774e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774e2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004774e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004774e5:
    // 004774e5  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004774e9  e81e000000             -call 0x47750c
    cpu.esp -= 4;
    sub_47750c(app, cpu);
    // 004774ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004774f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774f1  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004774f5  740a                   -je 0x477501
    if (cpu.flags.zf)
    {
        goto L_0x00477501;
    }
    // 004774f7  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004774f9  e82c560000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 004774fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774ff  eb03                   -jmp 0x477504
    goto L_0x00477504;
L_0x00477501:
    // 00477501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477502  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00477504:
    // 00477504  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00477508  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477509  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047750a:
    // 0047750a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047750b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47750c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047750c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047750d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047750f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477510  833dc4eb510000         +cmp dword ptr [0x51ebc4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477517  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477518  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477519  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047751a  751d                   -jne 0x477539
    if (!cpu.flags.zf)
    {
        goto L_0x00477539;
    }
    // 0047751c  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047751f  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477522  0f8caa000000           -jl 0x4775d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004775d2;
    }
    // 00477528  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047752b  0f8fa1000000           -jg 0x4775d2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004775d2;
    }
    // 00477531  83c020                 +add eax, 0x20
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
    // 00477534  e999000000             -jmp 0x4775d2
    goto L_0x004775d2;
L_0x00477539:
    // 00477539  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047753c  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 00477541  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477543  3bdf                   +cmp ebx, edi
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
    // 00477545  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477546  7d25                   -jge 0x47756d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047756d;
    }
    // 00477548  393518644a00           +cmp dword ptr [0x4a6418], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047754e  7e0b                   -jle 0x47755b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047755b;
    }
    // 00477550  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477551  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477552  e8325d0000             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00477557  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477558  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477559  eb0a                   -jmp 0x477565
    goto L_0x00477565;
L_0x0047755b:
    // 0047755b  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00477560  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 00477563  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x00477565:
    // 00477565  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477567  7504                   -jne 0x47756d
    if (!cpu.flags.zf)
    {
        goto L_0x0047756d;
    }
L_0x00477569:
    // 00477569  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047756b  eb65                   -jmp 0x4775d2
    goto L_0x004775d2;
L_0x0047756d:
    // 0047756d  8b150c624a00           -mov edx, dword ptr [0x4a620c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00477573  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477575  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00477578  0fb6c8                 -movzx ecx, al
    cpu.ecx = x86::reg32(cpu.al);
    // 0047757b  f6444a0180             +test byte ptr [edx + ecx*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.ecx * 2) & 128 /*0x80*/));
    // 00477580  740f                   -je 0x477591
    if (cpu.flags.zf)
    {
        goto L_0x00477591;
    }
    // 00477582  80650a00               +and byte ptr [ebp + 0xa], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00477586  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477588  884508                 -mov byte ptr [ebp + 8], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0047758b  885d09                 -mov byte ptr [ebp + 9], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) = cpu.bl;
    // 0047758e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047758f  eb09                   -jmp 0x47759a
    goto L_0x0047759a;
L_0x00477591:
    // 00477591  80650900               -and byte ptr [ebp + 9], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00477595  885d08                 -mov byte ptr [ebp + 8], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 00477598  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047759a:
    // 0047759a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047759b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047759d  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004775a0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004775a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004775a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004775a4  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004775a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004775a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004775a9  ff35c4eb5100           -push dword ptr [0x51ebc4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
    cpu.esp -= 4;
    // 004775af  e8b15a0000             -call 0x47d065
    cpu.esp -= 4;
    sub_47d065(app, cpu);
    // 004775b4  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004775b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004775b9  74ae                   -je 0x477569
    if (cpu.flags.zf)
    {
        goto L_0x00477569;
    }
    // 004775bb  3bc6                   +cmp eax, esi
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
    // 004775bd  7506                   -jne 0x4775c5
    if (!cpu.flags.zf)
    {
        goto L_0x004775c5;
    }
    // 004775bf  0fb645fc               -movzx eax, byte ptr [ebp - 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 004775c3  eb0d                   -jmp 0x4775d2
    goto L_0x004775d2;
L_0x004775c5:
    // 004775c5  0fb645fd               -movzx eax, byte ptr [ebp - 3]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */));
    // 004775c9  0fb64dfc               -movzx ecx, byte ptr [ebp - 4]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 004775cd  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004775d0  0bc1                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004775d2:
    // 004775d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775d5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4775d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004775d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004775d8  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004775dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004775dd  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004775e0  f6460c40               +test byte ptr [esi + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 004775e4  7406                   -je 0x4775ec
    if (cpu.flags.zf)
    {
        goto L_0x004775ec;
    }
    // 004775e6  83660c00               +and dword ptr [esi + 0xc], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 004775ea  eb17                   -jmp 0x477603
    goto L_0x00477603;
L_0x004775ec:
    // 004775ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004775ed  e897050000             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 004775f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004775f3  e810000000             -call 0x477608
    cpu.esp -= 4;
    __fclose_lk(app, cpu);
    // 004775f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004775f9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004775fb  e8db050000             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 00477600  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00477603:
    // 00477603  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00477605  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477606  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477607  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__fclose_lk(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477608  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477609  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047760d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047760e  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00477611  f6460c83               +test byte ptr [esi + 0xc], 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 131 /*0x83*/));
    // 00477615  7434                   -je 0x47764b
    if (cpu.flags.zf)
    {
        goto L_0x0047764b;
    }
    // 00477617  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477618  e8a7030000             -call 0x4779c4
    cpu.esp -= 4;
    sub_4779c4(app, cpu);
    // 0047761d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047761e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00477620  e8d95c0000             -call 0x47d2fe
    cpu.esp -= 4;
    __freebuf(app, cpu);
    // 00477625  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00477628  e856110000             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 0047762d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477630  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477632  7d05                   -jge 0x477639
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477639;
    }
    // 00477634  83cfff                 +or edi, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00477637  eb12                   -jmp 0x47764b
    goto L_0x0047764b;
L_0x00477639:
    // 00477639  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0047763c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047763e  740b                   -je 0x47764b
    if (cpu.flags.zf)
    {
        goto L_0x0047764b;
    }
    // 00477640  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477641  e86efdffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00477646  83661c00               -and dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047764a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047764b:
    // 0047764b  83660c00               -and dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047764f  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00477651  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477652  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477654  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477655  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00477657  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047765a  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047765d  c745ec49000000         -mov dword ptr [ebp - 0x14], 0x49
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 73 /*0x49*/;
    // 00477664  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477665  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00477668  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0047766b  e870670000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00477670  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00477673  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00477676  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477677  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0047767a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047767d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047767e  e8a65c0000             -call 0x47d329
    cpu.esp -= 4;
    sub_47d329(app, cpu);
    // 00477683  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477686  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477687  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477688(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477688  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477689  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047768b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047768c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047768f  e8f5040000             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 00477694  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00477697  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047769a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047769d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004776a0  e812000000             -call 0x4776b7
    cpu.esp -= 4;
    sub_4776b7(app, cpu);
    // 004776a5  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004776a8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004776aa  e82c050000             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 004776af  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004776b2  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004776b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4776b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004776b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004776b8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004776ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004776bb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004776bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004776bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004776be  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004776c1  0faf7d10               -imul edi, dword ptr [ebp + 0x10]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004776c5  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004776c8  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004776ca  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004776cc  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004776cf  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004776d2  7507                   -jne 0x4776db
    if (!cpu.flags.zf)
    {
        goto L_0x004776db;
    }
    // 004776d4  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004776d6  e9a9000000             -jmp 0x477784
    goto L_0x00477784;
L_0x004776db:
    // 004776db  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004776de  66f7460c0c01           +test word ptr [esi + 0xc], 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 268 /*0x10c*/));
    // 004776e4  7408                   -je 0x4776ee
    if (cpu.flags.zf)
    {
        goto L_0x004776ee;
    }
    // 004776e6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004776e9  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004776ec  eb0c                   -jmp 0x4776fa
    goto L_0x004776fa;
L_0x004776ee:
    // 004776ee  c7451400100000         -mov dword ptr [ebp + 0x14], 0x1000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
    // 004776f5  eb03                   -jmp 0x4776fa
    goto L_0x004776fa;
L_0x004776f7:
    // 004776f7  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x004776fa:
    // 004776fa  66f7460c0c01           +test word ptr [esi + 0xc], 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 268 /*0x10c*/));
    // 00477700  742a                   -je 0x47772c
    if (cpu.flags.zf)
    {
        goto L_0x0047772c;
    }
    // 00477702  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00477705  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477707  7423                   -je 0x47772c
    if (cpu.flags.zf)
    {
        goto L_0x0047772c;
    }
    // 00477709  3bc8                   +cmp ecx, eax
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
    // 0047770b  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047770d  7202                   -jb 0x477711
    if (cpu.flags.cf)
    {
        goto L_0x00477711;
    }
    // 0047770f  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00477711:
    // 00477711  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477712  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00477714  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477715  e816560000             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 0047771a  297d08                 -sub dword ptr [ebp + 8], edi
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047771d  297e04                 -sub dword ptr [esi + 4], edi
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00477720  013e                   -add dword ptr [esi], edi
    (app->getMemory<x86::reg32>(cpu.esi)) += x86::reg32(x86::sreg32(cpu.edi));
    // 00477722  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477725  03df                   +add ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00477727  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047772a  eb4b                   -jmp 0x477777
    goto L_0x00477777;
L_0x0047772c:
    // 0047772c  3b4d14                 +cmp ecx, dword ptr [ebp + 0x14]
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
    // 0047772f  722e                   -jb 0x47775f
    if (cpu.flags.cf)
    {
        goto L_0x0047775f;
    }
    // 00477731  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477735  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477737  7409                   -je 0x477742
    if (cpu.flags.zf)
    {
        goto L_0x00477742;
    }
    // 00477739  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047773b  f77514                 -div dword ptr [ebp + 0x14]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0047773e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477740  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00477742:
    // 00477742  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477743  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477744  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00477747  e817110000             -call 0x478863
    cpu.esp -= 4;
    sub_478863(app, cpu);
    // 0047774c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047774f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477751  7436                   -je 0x477789
    if (cpu.flags.zf)
    {
        goto L_0x00477789;
    }
    // 00477753  83f8ff                 +cmp eax, -1
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
    // 00477756  7437                   -je 0x47778f
    if (cpu.flags.zf)
    {
        goto L_0x0047778f;
    }
    // 00477758  294508                 -sub dword ptr [ebp + 8], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047775b  03d8                   +add ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047775d  eb18                   -jmp 0x477777
    goto L_0x00477777;
L_0x0047775f:
    // 0047775f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477760  e8f6660000             -call 0x47de5b
    cpu.esp -= 4;
    sub_47de5b(app, cpu);
    // 00477765  83f8ff                 +cmp eax, -1
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
    // 00477768  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477769  7428                   -je 0x477793
    if (cpu.flags.zf)
    {
        goto L_0x00477793;
    }
    // 0047776b  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 0047776d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00477770  43                     -inc ebx
    (cpu.ebx)++;
    // 00477771  ff4d08                 -dec dword ptr [ebp + 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */))--;
    // 00477774  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00477777:
    // 00477777  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0047777b  0f8576ffffff           -jne 0x4776f7
    if (!cpu.flags.zf)
    {
        goto L_0x004776f7;
    }
    // 00477781  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x00477784:
    // 00477784  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477785  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477786  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477787  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477788  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477789:
    // 00477789  834e0c10               +or dword ptr [esi + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(16 /*0x10*/))));
    // 0047778d  eb04                   -jmp 0x477793
    goto L_0x00477793;
L_0x0047778f:
    // 0047778f  834e0c20               -or dword ptr [esi + 0xc], 0x20
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00477793:
    // 00477793  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00477795  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477797  2b4508                 -sub eax, dword ptr [ebp + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0047779a  f7750c                 +div dword ptr [ebp + 0xc]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0047779d  ebe5                   -jmp 0x477784
    goto L_0x00477784;
}

/* align: skip  */
void Application::sub_47779f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047779f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004777a0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004777a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004777a3  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004777a6  e8de030000             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 004777ab  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004777ae  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004777b1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004777b4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004777b7  e812000000             -call 0x4777ce
    cpu.esp -= 4;
    sub_4777ce(app, cpu);
    // 004777bc  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004777bf  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004777c1  e815040000             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 004777c6  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004777c9  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004777cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4777ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004777ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004777cf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004777d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004777d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004777d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004777d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004777d5  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004777d8  0faf7d10               -imul edi, dword ptr [ebp + 0x10]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004777dc  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004777df  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004777e2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004777e4  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004777e7  8bdf                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004777e9  7507                   -jne 0x4777f2
    if (!cpu.flags.zf)
    {
        goto L_0x004777f2;
    }
    // 004777eb  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004777ed  e9cd000000             -jmp 0x4778bf
    goto L_0x004778bf;
L_0x004777f2:
    // 004777f2  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004777f5  66f7460c0c01           +test word ptr [esi + 0xc], 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 268 /*0x10c*/));
    // 004777fb  7408                   -je 0x477805
    if (cpu.flags.zf)
    {
        goto L_0x00477805;
    }
    // 004777fd  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00477800  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00477803  eb07                   -jmp 0x47780c
    goto L_0x0047780c;
L_0x00477805:
    // 00477805  c7451400100000         -mov dword ptr [ebp + 0x14], 0x1000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
L_0x0047780c:
    // 0047780c  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047780f  81e108010000           +and ecx, 0x108
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(264 /*0x108*/))));
    // 00477815  7429                   -je 0x477840
    if (cpu.flags.zf)
    {
        goto L_0x00477840;
    }
    // 00477817  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047781a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047781c  7422                   -je 0x477840
    if (cpu.flags.zf)
    {
        goto L_0x00477840;
    }
    // 0047781e  3bd8                   +cmp ebx, eax
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
    // 00477820  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00477822  7202                   -jb 0x477826
    if (cpu.flags.cf)
    {
        goto L_0x00477826;
    }
    // 00477824  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00477826:
    // 00477826  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477827  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047782a  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0047782c  e8ff540000             -call 0x47cd30
    cpu.esp -= 4;
    sub_47cd30(app, cpu);
    // 00477831  297e04                 -sub dword ptr [esi + 4], edi
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00477834  013e                   -add dword ptr [esi], edi
    (app->getMemory<x86::reg32>(cpu.esi)) += x86::reg32(x86::sreg32(cpu.edi));
    // 00477836  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477839  2bdf                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047783b  017d08                 +add dword ptr [ebp + 8], edi
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047783e  eb46                   -jmp 0x477886
    goto L_0x00477886;
L_0x00477840:
    // 00477840  3b5d14                 +cmp ebx, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477843  7246                   -jb 0x47788b
    if (cpu.flags.cf)
    {
        goto L_0x0047788b;
    }
    // 00477845  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477847  740b                   -je 0x477854
    if (cpu.flags.zf)
    {
        goto L_0x00477854;
    }
    // 00477849  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047784a  e875010000             -call 0x4779c4
    cpu.esp -= 4;
    sub_4779c4(app, cpu);
    // 0047784f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477851  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477852  7579                   -jne 0x4778cd
    if (!cpu.flags.zf)
    {
        goto L_0x004778cd;
    }
L_0x00477854:
    // 00477854  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477858  740d                   -je 0x477867
    if (cpu.flags.zf)
    {
        goto L_0x00477867;
    }
    // 0047785a  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047785c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047785e  f77514                 -div dword ptr [ebp + 0x14]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00477861  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00477863  2bfa                   +sub edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00477865  eb02                   -jmp 0x477869
    goto L_0x00477869;
L_0x00477867:
    // 00477867  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00477869:
    // 00477869  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047786a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047786d  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00477870  e8aa200000             -call 0x47991f
    cpu.esp -= 4;
    sub_47991f(app, cpu);
    // 00477875  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477878  83f8ff                 +cmp eax, -1
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
    // 0047787b  7447                   -je 0x4778c4
    if (cpu.flags.zf)
    {
        goto L_0x004778c4;
    }
    // 0047787d  014508                 -add dword ptr [ebp + 8], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477880  2bd8                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00477882  3bc7                   +cmp eax, edi
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
    // 00477884  723e                   -jb 0x4778c4
    if (cpu.flags.cf)
    {
        goto L_0x004778c4;
    }
L_0x00477886:
    // 00477886  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00477889  eb29                   -jmp 0x4778b4
    goto L_0x004778b4;
L_0x0047788b:
    // 0047788b  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047788e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047788f  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 00477892  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477893  e8503a0000             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 00477898  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477899  83f8ff                 +cmp eax, -1
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
    // 0047789c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047789d  742e                   -je 0x4778cd
    if (cpu.flags.zf)
    {
        goto L_0x004778cd;
    }
    // 0047789f  ff4508                 -inc dword ptr [ebp + 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */))++;
    // 004778a2  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004778a5  4b                     -dec ebx
    (cpu.ebx)--;
    // 004778a6  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004778a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004778ab  7f07                   -jg 0x4778b4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004778b4;
    }
    // 004778ad  c7451401000000         -mov dword ptr [ebp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x004778b4:
    // 004778b4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004778b6  0f8550ffffff           -jne 0x47780c
    if (!cpu.flags.zf)
    {
        goto L_0x0047780c;
    }
    // 004778bc  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x004778bf:
    // 004778bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004778c4:
    // 004778c4  834e0c20               +or dword ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 004778c8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004778cb  eb02                   -jmp 0x4778cf
    goto L_0x004778cf;
L_0x004778cd:
    // 004778cd  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004778cf:
    // 004778cf  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004778d1  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004778d3  f7750c                 +div dword ptr [ebp + 0xc]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004778d6  ebe7                   -jmp 0x4778bf
    goto L_0x004778bf;
}

/* align: skip  */
void Application::sub_4778d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004778d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004778d9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004778db  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 004778df  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004778e0  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004778e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004778e4  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004778e6  7f04                   -jg 0x4778ec
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004778ec;
    }
    // 004778e8  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004778ea  eb4a                   -jmp 0x477936
    goto L_0x00477936;
L_0x004778ec:
    // 004778ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004778ed  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004778f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004778f1  e893020000             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 004778f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004778f7:
    // 004778f7  ff4d0c                 +dec dword ptr [ebp + 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004778fa  742d                   -je 0x477929
    if (cpu.flags.zf)
    {
        goto L_0x00477929;
    }
    // 004778fc  ff4e04                 +dec dword ptr [esi + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004778ff  780a                   -js 0x47790b
    if (cpu.flags.sf)
    {
        goto L_0x0047790b;
    }
    // 00477901  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00477903  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 00477906  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477907  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00477909  eb07                   -jmp 0x477912
    goto L_0x00477912;
L_0x0047790b:
    // 0047790b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047790c  e84a650000             -call 0x47de5b
    cpu.esp -= 4;
    sub_47de5b(app, cpu);
    // 00477911  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477912:
    // 00477912  83f8ff                 +cmp eax, -1
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
    // 00477915  7409                   -je 0x477920
    if (cpu.flags.zf)
    {
        goto L_0x00477920;
    }
    // 00477917  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00477919  47                     -inc edi
    (cpu.edi)++;
    // 0047791a  3c0a                   +cmp al, 0xa
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
    // 0047791c  740b                   -je 0x477929
    if (cpu.flags.zf)
    {
        goto L_0x00477929;
    }
    // 0047791e  ebd7                   -jmp 0x4778f7
    goto L_0x004778f7;
L_0x00477920:
    // 00477920  3b7d08                 +cmp edi, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477923  7504                   -jne 0x477929
    if (!cpu.flags.zf)
    {
        goto L_0x00477929;
    }
    // 00477925  33db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00477927  eb03                   -jmp 0x47792c
    goto L_0x0047792c;
L_0x00477929:
    // 00477929  802700                 -and byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0047792c:
    // 0047792c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047792d  e8a9020000             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 00477932  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477933  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477935  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477936:
    // 00477936  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477937  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477938  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477939  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47793a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047793a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047793b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047793d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047793e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477941  e843020000             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 00477946  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00477949  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047794a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047794d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477950  e8d4590000             -call 0x47d329
    cpu.esp -= 4;
    sub_47d329(app, cpu);
    // 00477955  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477958  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047795a  e87c020000             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 0047795f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00477962  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477964  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477965  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477967(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477967  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477968  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047796c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047796e  7509                   -jne 0x477979
    if (!cpu.flags.zf)
    {
        goto L_0x00477979;
    }
    // 00477970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477971  e8b3000000             -call 0x477a29
    cpu.esp -= 4;
    sub_477a29(app, cpu);
    // 00477976  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477977  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477978  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477979:
    // 00477979  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047797a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047797b  e809020000             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 00477980  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477981  e810000000             -call 0x477996
    cpu.esp -= 4;
    sub_477996(app, cpu);
    // 00477986  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477987  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00477989  e84d020000             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 0047798e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477991  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00477993  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477994  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477995  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477996(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477996  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477997  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047799b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047799c  e823000000             -call 0x4779c4
    cpu.esp -= 4;
    sub_4779c4(app, cpu);
    // 004779a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004779a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779a4  7405                   -je 0x4779ab
    if (cpu.flags.zf)
    {
        goto L_0x004779ab;
    }
    // 004779a6  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004779a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779ab:
    // 004779ab  f6460d40               +test byte ptr [esi + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004779af  740f                   -je 0x4779c0
    if (cpu.flags.zf)
    {
        goto L_0x004779c0;
    }
    // 004779b1  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004779b4  e87e650000             -call 0x47df37
    cpu.esp -= 4;
    sub_47df37(app, cpu);
    // 004779b9  f7d8                   +neg eax
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
    // 004779bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779bd  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004779bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779c0:
    // 004779c0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004779c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4779c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004779c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004779c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004779c6  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004779ca  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004779cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004779cd  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004779d0  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004779d2  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004779d5  80f902                 +cmp cl, 2
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
    // 004779d8  7537                   -jne 0x477a11
    if (!cpu.flags.zf)
    {
        goto L_0x00477a11;
    }
    // 004779da  66a90801               +test ax, 0x108
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 264 /*0x108*/));
    // 004779de  7431                   -je 0x477a11
    if (cpu.flags.zf)
    {
        goto L_0x00477a11;
    }
    // 004779e0  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004779e3  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004779e5  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004779e7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004779e9  7e26                   -jle 0x477a11
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477a11;
    }
    // 004779eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004779ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004779ed  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004779f0  e82a1f0000             -call 0x47991f
    cpu.esp -= 4;
    sub_47991f(app, cpu);
    // 004779f5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004779f8  3bc7                   +cmp eax, edi
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
    // 004779fa  750e                   -jne 0x477a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00477a0a;
    }
    // 004779fc  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004779ff  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00477a01  740e                   -je 0x477a11
    if (cpu.flags.zf)
    {
        goto L_0x00477a11;
    }
    // 00477a03  24fd                   +and al, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 00477a05  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00477a08  eb07                   -jmp 0x477a11
    goto L_0x00477a11;
L_0x00477a0a:
    // 00477a0a  834e0c20               -or dword ptr [esi + 0xc], 0x20
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477a0e  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00477a11:
    // 00477a11  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00477a14  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00477a18  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00477a1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a1b  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477a1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477a20  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477a22  e802000000             -call 0x477a29
    cpu.esp -= 4;
    sub_477a29(app, cpu);
    // 00477a27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477a29(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477a29  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477a2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477a2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477a2c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477a2e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477a30  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00477a32  e892500000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00477a37  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00477a39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a3a  393540305200           +cmp dword ptr [0x523040], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477a40  7e74                   -jle 0x477ab6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477ab6;
    }
L_0x00477a42:
    // 00477a42  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 00477a47  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00477a4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477a4c  745f                   -je 0x477aad
    if (cpu.flags.zf)
    {
        goto L_0x00477aad;
    }
    // 00477a4e  f6400c83               +test byte ptr [eax + 0xc], 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 131 /*0x83*/));
    // 00477a52  7459                   -je 0x477aad
    if (cpu.flags.zf)
    {
        goto L_0x00477aad;
    }
    // 00477a54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477a55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477a56  e85d010000             -call 0x477bb8
    cpu.esp -= 4;
    sub_477bb8(app, cpu);
    // 00477a5b  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 00477a60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a62  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00477a65  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00477a68  f6c183                 +test cl, 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 131 /*0x83*/));
    // 00477a6b  7430                   -je 0x477a9d
    if (cpu.flags.zf)
    {
        goto L_0x00477a9d;
    }
    // 00477a6d  837c241001             +cmp dword ptr [esp + 0x10], 1
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
    // 00477a72  750f                   -jne 0x477a83
    if (!cpu.flags.zf)
    {
        goto L_0x00477a83;
    }
    // 00477a74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477a75  e81cffffff             -call 0x477996
    cpu.esp -= 4;
    sub_477996(app, cpu);
    // 00477a7a  83f8ff                 +cmp eax, -1
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
    // 00477a7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a7e  741d                   -je 0x477a9d
    if (cpu.flags.zf)
    {
        goto L_0x00477a9d;
    }
    // 00477a80  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477a81  eb1a                   -jmp 0x477a9d
    goto L_0x00477a9d;
L_0x00477a83:
    // 00477a83  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477a88  7513                   -jne 0x477a9d
    if (!cpu.flags.zf)
    {
        goto L_0x00477a9d;
    }
    // 00477a8a  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00477a8d  740e                   -je 0x477a9d
    if (cpu.flags.zf)
    {
        goto L_0x00477a9d;
    }
    // 00477a8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477a90  e801ffffff             -call 0x477996
    cpu.esp -= 4;
    sub_477996(app, cpu);
    // 00477a95  83f8ff                 +cmp eax, -1
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
    // 00477a98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a99  7502                   -jne 0x477a9d
    if (!cpu.flags.zf)
    {
        goto L_0x00477a9d;
    }
    // 00477a9b  0bf8                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00477a9d:
    // 00477a9d  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 00477aa2  ff34b0                 -push dword ptr [eax + esi*4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    cpu.esp -= 4;
    // 00477aa5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477aa6  e85f010000             -call 0x477c0a
    cpu.esp -= 4;
    sub_477c0a(app, cpu);
    // 00477aab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477aac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477aad:
    // 00477aad  46                     -inc esi
    (cpu.esi)++;
    // 00477aae  3b3540305200           +cmp esi, dword ptr [0x523040]
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
    // 00477ab4  7c8c                   -jl 0x477a42
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477a42;
    }
L_0x00477ab6:
    // 00477ab6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477ab8  e86d500000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00477abd  837c241401             +cmp dword ptr [esp + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477ac2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ac3  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477ac5  7402                   -je 0x477ac9
    if (cpu.flags.zf)
    {
        goto L_0x00477ac9;
    }
    // 00477ac7  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00477ac9:
    // 00477ac9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477aca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477acb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477acc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477acd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477acd  a140305200             -mov eax, dword ptr [0x523040]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */);
    // 00477ad2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477ad3  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 00477ad5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477ad7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ad8  7507                   -jne 0x477ae1
    if (!cpu.flags.zf)
    {
        goto L_0x00477ae1;
    }
    // 00477ada  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 00477adf  eb06                   -jmp 0x477ae7
    goto L_0x00477ae7;
L_0x00477ae1:
    // 00477ae1  3bc6                   +cmp eax, esi
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
    // 00477ae3  7d07                   -jge 0x477aec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477aec;
    }
    // 00477ae5  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00477ae7:
    // 00477ae7  a340305200             -mov dword ptr [0x523040], eax
    app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */) = cpu.eax;
L_0x00477aec:
    // 00477aec  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00477aee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477aef  e874290000             -call 0x47a468
    cpu.esp -= 4;
    sub_47a468(app, cpu);
    // 00477af4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477af5  a324205200             -mov dword ptr [0x522024], eax
    app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */) = cpu.eax;
    // 00477afa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477afc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477afd  7521                   -jne 0x477b20
    if (!cpu.flags.zf)
    {
        goto L_0x00477b20;
    }
    // 00477aff  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00477b01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477b02  893540305200           -mov dword ptr [0x523040], esi
    app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */) = cpu.esi;
    // 00477b08  e85b290000             -call 0x47a468
    cpu.esp -= 4;
    sub_47a468(app, cpu);
    // 00477b0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b0e  a324205200             -mov dword ptr [0x522024], eax
    app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */) = cpu.eax;
    // 00477b13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477b15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b16  7508                   -jne 0x477b20
    if (!cpu.flags.zf)
    {
        goto L_0x00477b20;
    }
    // 00477b18  6a1a                   -push 0x1a
    app->getMemory<x86::reg32>(cpu.esp-4) = 26 /*0x1a*/;
    cpu.esp -= 4;
    // 00477b1a  e81a260000             -call 0x47a139
    cpu.esp -= 4;
    __amsg_exit(app, cpu);
    // 00477b1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477b20:
    // 00477b20  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477b22  b8083d4a00             -mov eax, 0x4a3d08
    cpu.eax = 4865288 /*0x4a3d08*/;
L_0x00477b27:
    // 00477b27  8b1524205200           -mov edx, dword ptr [0x522024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 00477b2d  890411                 -mov dword ptr [ecx + edx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 00477b30  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477b33  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477b36  3d883f4a00             +cmp eax, 0x4a3f88
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865928 /*0x4a3f88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477b3b  7cea                   -jl 0x477b27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477b27;
    }
    // 00477b3d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477b3f  ba183d4a00             -mov edx, 0x4a3d18
    cpu.edx = 4865304 /*0x4a3d18*/;
L_0x00477b44:
    // 00477b44  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00477b46  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477b48  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00477b4b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00477b4e  8b34b5e01e5200         -mov esi, dword ptr [esi*4 + 0x521ee0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.esi * 4);
    // 00477b55  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00477b58  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00477b5b  83f8ff                 +cmp eax, -1
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
    // 00477b5e  7404                   -je 0x477b64
    if (cpu.flags.zf)
    {
        goto L_0x00477b64;
    }
    // 00477b60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477b62  7503                   -jne 0x477b67
    if (!cpu.flags.zf)
    {
        goto L_0x00477b67;
    }
L_0x00477b64:
    // 00477b64  830aff                 -or dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00477b67:
    // 00477b67  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477b6a  41                     -inc ecx
    (cpu.ecx)++;
    // 00477b6b  81fa783d4a00           +cmp edx, 0x4a3d78
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865400 /*0x4a3d78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477b71  7cd1                   -jl 0x477b44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477b44;
    }
    // 00477b73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477b75(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477b75  e8a6feffff             -call 0x477a20
    cpu.esp -= 4;
    sub_477a20(app, cpu);
    // 00477b7a  803d20eb510000         +cmp byte ptr [0x51eb20], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5368608) /* 0x51eb20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477b81  7405                   -je 0x477b88
    if (cpu.flags.zf)
    {
        goto L_0x00477b88;
    }
    // 00477b83  e9fe650000             -jmp 0x47e186
    goto L_0x0047e186;
L_0x00477b88:
    // 00477b88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e186:
    // 0047e186  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e187  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e188  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047e18a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e18c  e838e9ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047e191  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e192  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0047e194  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e195  393d40305200           +cmp dword ptr [0x523040], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e19b  7e5d                   -jle 0x47e1fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e1fa;
    }
    // 0047e19d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0047e19e:
    // 0047e19e  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e1a3  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047e1a5  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047e1a8  8b0406                 -mov eax, dword ptr [esi + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0047e1ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e1ad  7441                   -je 0x47e1f0
    if (cpu.flags.zf)
    {
        goto L_0x0047e1f0;
    }
    // 0047e1af  f6400c83               +test byte ptr [eax + 0xc], 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 131 /*0x83*/));
    // 0047e1b3  740d                   -je 0x47e1c2
    if (cpu.flags.zf)
    {
        goto L_0x0047e1c2;
    }
    // 0047e1b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e1b6  e81c94ffff             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0047e1bb  83f8ff                 +cmp eax, -1
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
    // 0047e1be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e1bf  7401                   -je 0x47e1c2
    if (cpu.flags.zf)
    {
        goto L_0x0047e1c2;
    }
    // 0047e1c1  43                     -inc ebx
    (cpu.ebx)++;
L_0x0047e1c2:
    // 0047e1c2  83ff14                 +cmp edi, 0x14
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e1c5  7c29                   -jl 0x47e1f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e1f0;
    }
    // 0047e1c7  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e1cc  8b0406                 -mov eax, dword ptr [esi + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0047e1cf  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047e1d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e1d3  ff15e8704800           -call dword ptr [0x4870e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747496) /* 0x4870e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047e1d9  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e1de  ff3406                 -push dword ptr [esi + eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    cpu.esp -= 4;
    // 0047e1e1  e8ce91ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0047e1e6  a124205200             -mov eax, dword ptr [0x522024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382180) /* 0x522024 */);
    // 0047e1eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e1ec  83240600               -and dword ptr [esi + eax], 0
    app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0047e1f0:
    // 0047e1f0  47                     -inc edi
    (cpu.edi)++;
    // 0047e1f1  3b3d40305200           +cmp edi, dword ptr [0x523040]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5386304) /* 0x523040 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e1f7  7ca5                   -jl 0x47e19e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e19e;
    }
    // 0047e1f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e1fa:
    // 0047e1fa  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047e1fc  e829e9ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047e201  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e202  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047e204  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e205  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e206  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477b89(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477b89  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477b8d  b9083d4a00             -mov ecx, 0x4a3d08
    cpu.ecx = 4865288 /*0x4a3d08*/;
    // 00477b92  3bc1                   +cmp eax, ecx
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
    // 00477b94  7217                   -jb 0x477bad
    if (cpu.flags.cf)
    {
        goto L_0x00477bad;
    }
    // 00477b96  3d683f4a00             +cmp eax, 0x4a3f68
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865896 /*0x4a3f68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477b9b  7710                   -ja 0x477bad
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00477bad;
    }
    // 00477b9d  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477b9f  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00477ba2  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00477ba5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477ba6  e81e4f0000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00477bab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477bad:
    // 00477bad  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477bb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477bb1  ff15b0714800           -call dword ptr [0x4871b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747696) /* 0x4871b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477bb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477bb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477bb8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477bbc  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477bbf  7d0b                   -jge 0x477bcc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477bcc;
    }
    // 00477bc1  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00477bc4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477bc5  e8ff4e0000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00477bca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bcb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477bcc:
    // 00477bcc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477bd0  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477bd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477bd4  ff15b0714800           -call dword ptr [0x4871b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747696) /* 0x4871b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477bda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477bdb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477bdb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477bdf  b9083d4a00             -mov ecx, 0x4a3d08
    cpu.ecx = 4865288 /*0x4a3d08*/;
    // 00477be4  3bc1                   +cmp eax, ecx
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
    // 00477be6  7217                   -jb 0x477bff
    if (cpu.flags.cf)
    {
        goto L_0x00477bff;
    }
    // 00477be8  3d683f4a00             +cmp eax, 0x4a3f68
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865896 /*0x4a3f68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477bed  7710                   -ja 0x477bff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00477bff;
    }
    // 00477bef  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477bf1  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00477bf4  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00477bf7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477bf8  e82d4f0000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00477bfd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477bff:
    // 00477bff  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477c02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477c03  ff15b4714800           -call dword ptr [0x4871b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747700) /* 0x4871b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477c09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477c0a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c0a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477c0e  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477c11  7d0b                   -jge 0x477c1e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477c1e;
    }
    // 00477c13  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00477c16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477c17  e80e4f0000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00477c1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477c1e:
    // 00477c1e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477c22  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477c25  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477c26  ff15b4714800           -call dword ptr [0x4871b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747700) /* 0x4871b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477c2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477c2d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c2e  e844670000             -call 0x47e377
    cpu.esp -= 4;
    sub_47e377(app, cpu);
    // 00477c33  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477c35  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00477c37  7502                   -jne 0x477c3b
    if (!cpu.flags.zf)
    {
        goto L_0x00477c3b;
    }
    // 00477c39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477c3b:
    // 00477c3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c3d  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00477c41  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00477c45  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00477c49  e8b9650000             -call 0x47e207
    cpu.esp -= 4;
    sub_47e207(app, cpu);
    // 00477c4e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c4f  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00477c51  e885ffffff             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 00477c56  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00477c59  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00477c5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477c5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c5e  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00477c60  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00477c64  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00477c68  e8c0ffffff             -call 0x477c2d
    cpu.esp -= 4;
    sub_477c2d(app, cpu);
    // 00477c6d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477c70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477c71(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477c72  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00477c74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c75  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477c78  e80cffffff             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 00477c7d  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00477c80  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00477c83  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477c86  e812000000             -call 0x477c9d
    cpu.esp -= 4;
    sub_477c9d(app, cpu);
    // 00477c8b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477c8e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477c90  e846ffffff             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 00477c95  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00477c98  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477c9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477c9d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c9d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c9e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477ca2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477ca3  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00477ca6  a883                   +test al, 0x83
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 131 /*0x83*/));
    // 00477ca8  746f                   -je 0x477d19
    if (cpu.flags.zf)
    {
        goto L_0x00477d19;
    }
    // 00477caa  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477cae  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00477cb0  740a                   -je 0x477cbc
    if (cpu.flags.zf)
    {
        goto L_0x00477cbc;
    }
    // 00477cb2  83ff01                 +cmp edi, 1
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
    // 00477cb5  7405                   -je 0x477cbc
    if (cpu.flags.zf)
    {
        goto L_0x00477cbc;
    }
    // 00477cb7  83ff02                 +cmp edi, 2
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
    // 00477cba  755d                   -jne 0x477d19
    if (!cpu.flags.zf)
    {
        goto L_0x00477d19;
    }
L_0x00477cbc:
    // 00477cbc  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00477cbe  83ff01                 +cmp edi, 1
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
    // 00477cc1  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00477cc4  750d                   -jne 0x477cd3
    if (!cpu.flags.zf)
    {
        goto L_0x00477cd3;
    }
    // 00477cc6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477cc7  e814070000             -call 0x4783e0
    cpu.esp -= 4;
    sub_4783e0(app, cpu);
    // 00477ccc  01442414               -add dword ptr [esp + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477cd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477cd1  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00477cd3:
    // 00477cd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477cd4  e8ebfcffff             -call 0x4779c4
    cpu.esp -= 4;
    sub_4779c4(app, cpu);
    // 00477cd9  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00477cdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477cdd  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00477cdf  7407                   -je 0x477ce8
    if (cpu.flags.zf)
    {
        goto L_0x00477ce8;
    }
    // 00477ce1  24fc                   +and al, 0xfc
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/))));
    // 00477ce3  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00477ce6  eb14                   -jmp 0x477cfc
    goto L_0x00477cfc;
L_0x00477ce8:
    // 00477ce8  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00477cea  7410                   -je 0x477cfc
    if (cpu.flags.zf)
    {
        goto L_0x00477cfc;
    }
    // 00477cec  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00477cee  740c                   -je 0x477cfc
    if (cpu.flags.zf)
    {
        goto L_0x00477cfc;
    }
    // 00477cf0  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00477cf3  7507                   -jne 0x477cfc
    if (!cpu.flags.zf)
    {
        goto L_0x00477cfc;
    }
    // 00477cf5  c7461800020000         -mov dword ptr [esi + 0x18], 0x200
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 512 /*0x200*/;
L_0x00477cfc:
    // 00477cfc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477cfd  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00477d01  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00477d04  e8bb670000             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    // 00477d09  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477d0c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477d0e  83f8ff                 +cmp eax, -1
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
    // 00477d11  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 00477d14  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477d15  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477d17  eb0e                   -jmp 0x477d27
    goto L_0x00477d27;
L_0x00477d19:
    // 00477d19  e894670000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00477d1e  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 00477d24  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00477d27:
    // 00477d27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477d31  3d00100000             +cmp eax, 0x1000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477d36  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477d3a  7214                   -jb 0x477d50
    if (cpu.flags.cf)
    {
        goto L_0x00477d50;
    }
L_0x00477d3c:
    // 00477d3c  81e900100000           -sub ecx, 0x1000
    (cpu.ecx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 00477d42  2d00100000             -sub eax, 0x1000
    (cpu.eax) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 00477d47  8501                   -test dword ptr [ecx], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx) & cpu.eax));
    // 00477d49  3d00100000             +cmp eax, 0x1000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477d4e  73ec                   -jae 0x477d3c
    if (!cpu.flags.cf)
    {
        goto L_0x00477d3c;
    }
L_0x00477d50:
    // 00477d50  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00477d52  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00477d54  8501                   -test dword ptr [ecx], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx) & cpu.eax));
    // 00477d56  8be1                   -mov esp, ecx
    cpu.esp = cpu.ecx;
    // 00477d58  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00477d5a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00477d5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477d5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::operator_new(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d5f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477d61  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477d65  e822f5ffff             -call 0x47728c
    cpu.esp -= 4;
    __nh_malloc(app, cpu);
    // 00477d6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477d6d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d6d  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00477d71  e83ef6ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00477d76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477d78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d78  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477d7c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477d80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477d81  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 00477d84  8d7002                 -lea esi, [eax + 2]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00477d87  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
L_0x00477d8a:
    // 00477d8a  41                     -inc ecx
    (cpu.ecx)++;
    // 00477d8b  41                     -inc ecx
    (cpu.ecx)++;
    // 00477d8c  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00477d8f  740a                   -je 0x477d9b
    if (cpu.flags.zf)
    {
        goto L_0x00477d9b;
    }
    // 00477d91  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 00477d94  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 00477d97  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477d98  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477d99  ebef                   -jmp 0x477d8a
    goto L_0x00477d8a;
L_0x00477d9b:
    // 00477d9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477d9d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d9d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477da1  66833900               +cmp word ptr [ecx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00477da5  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00477da8  740a                   -je 0x477db4
    if (cpu.flags.zf)
    {
        goto L_0x00477db4;
    }
L_0x00477daa:
    // 00477daa  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00477dad  40                     -inc eax
    (cpu.eax)++;
    // 00477dae  40                     -inc eax
    (cpu.eax)++;
    // 00477daf  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00477db2  75f6                   -jne 0x477daa
    if (!cpu.flags.zf)
    {
        goto L_0x00477daa;
    }
L_0x00477db4:
    // 00477db4  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477db6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00477db8  48                     -dec eax
    (cpu.eax)--;
    // 00477db9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_strncpy(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477dc0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477dc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477dc5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477dc7  747a                   -je 0x477e43
    if (cpu.flags.zf)
    {
        goto L_0x00477e43;
    }
    // 00477dc9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477dca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477dcb  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00477dcd  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477dd1  f7c603000000           +test esi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 3 /*0x3*/));
    // 00477dd7  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00477ddb  7507                   -jne 0x477de4
    if (!cpu.flags.zf)
    {
        goto L_0x00477de4;
    }
    // 00477ddd  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00477de0  756f                   -jne 0x477e51
    if (!cpu.flags.zf)
    {
        goto L_0x00477e51;
    }
    // 00477de2  eb21                   -jmp 0x477e05
    goto L_0x00477e05;
L_0x00477de4:
    // 00477de4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00477de6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477de7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00477de9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477dea  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477deb  7425                   -je 0x477e12
    if (cpu.flags.zf)
    {
        goto L_0x00477e12;
    }
    // 00477ded  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00477def  7429                   -je 0x477e1a
    if (cpu.flags.zf)
    {
        goto L_0x00477e1a;
    }
    // 00477df1  f7c603000000           +test esi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 3 /*0x3*/));
    // 00477df7  75eb                   -jne 0x477de4
    if (!cpu.flags.zf)
    {
        goto L_0x00477de4;
    }
    // 00477df9  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00477dfb  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00477dfe  7551                   -jne 0x477e51
    if (!cpu.flags.zf)
    {
        goto L_0x00477e51;
    }
L_0x00477e00:
    // 00477e00  83e303                 +and ebx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00477e03  740d                   -je 0x477e12
    if (cpu.flags.zf)
    {
        goto L_0x00477e12;
    }
L_0x00477e05:
    // 00477e05  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00477e07  46                     -inc esi
    (cpu.esi)++;
    // 00477e08  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00477e0a  47                     -inc edi
    (cpu.edi)++;
    // 00477e0b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00477e0d  742f                   -je 0x477e3e
    if (cpu.flags.zf)
    {
        goto L_0x00477e3e;
    }
    // 00477e0f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477e10  75f3                   -jne 0x477e05
    if (!cpu.flags.zf)
    {
        goto L_0x00477e05;
    }
L_0x00477e12:
    // 00477e12  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00477e16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477e1a:
    // 00477e1a  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00477e20  7412                   -je 0x477e34
    if (cpu.flags.zf)
    {
        goto L_0x00477e34;
    }
L_0x00477e22:
    // 00477e22  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00477e24  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477e25  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477e26  0f848a000000           -je 0x477eb6
    if (cpu.flags.zf)
    {
        goto L_0x00477eb6;
    }
    // 00477e2c  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00477e32  75ee                   -jne 0x477e22
    if (!cpu.flags.zf)
    {
        goto L_0x00477e22;
    }
L_0x00477e34:
    // 00477e34  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00477e36  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00477e39  756c                   -jne 0x477ea7
    if (!cpu.flags.zf)
    {
        goto L_0x00477ea7;
    }
L_0x00477e3b:
    // 00477e3b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00477e3d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00477e3e:
    // 00477e3e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477e3f  75fa                   -jne 0x477e3b
    if (!cpu.flags.zf)
    {
        goto L_0x00477e3b;
    }
    // 00477e41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477e43:
    // 00477e43  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477e47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477e49:
    // 00477e49  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00477e4b  83c704                 +add edi, 4
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
    // 00477e4e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477e4f  74af                   -je 0x477e00
    if (cpu.flags.zf)
    {
        goto L_0x00477e00;
    }
L_0x00477e51:
    // 00477e51  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 00477e56  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00477e58  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477e5a  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00477e5d  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477e5f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00477e61  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477e64  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 00477e69  74de                   -je 0x477e49
    if (cpu.flags.zf)
    {
        goto L_0x00477e49;
    }
    // 00477e6b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00477e6d  742c                   -je 0x477e9b
    if (cpu.flags.zf)
    {
        goto L_0x00477e9b;
    }
    // 00477e6f  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00477e71  741e                   -je 0x477e91
    if (cpu.flags.zf)
    {
        goto L_0x00477e91;
    }
    // 00477e73  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 00477e79  740c                   -je 0x477e87
    if (cpu.flags.zf)
    {
        goto L_0x00477e87;
    }
    // 00477e7b  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 00477e81  75c6                   -jne 0x477e49
    if (!cpu.flags.zf)
    {
        goto L_0x00477e49;
    }
    // 00477e83  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00477e85  eb18                   -jmp 0x477e9f
    goto L_0x00477e9f;
L_0x00477e87:
    // 00477e87  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00477e8d  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00477e8f  eb0e                   -jmp 0x477e9f
    goto L_0x00477e9f;
L_0x00477e91:
    // 00477e91  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00477e97  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00477e99  eb04                   -jmp 0x477e9f
    goto L_0x00477e9f;
L_0x00477e9b:
    // 00477e9b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477e9d  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x00477e9f:
    // 00477e9f  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477ea2  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00477ea4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477ea5  740a                   -je 0x477eb1
    if (cpu.flags.zf)
    {
        goto L_0x00477eb1;
    }
L_0x00477ea7:
    // 00477ea7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00477ea9:
    // 00477ea9  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00477eab  83c704                 +add edi, 4
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
    // 00477eae  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477eaf  75f8                   -jne 0x477ea9
    if (!cpu.flags.zf)
    {
        goto L_0x00477ea9;
    }
L_0x00477eb1:
    // 00477eb1  83e303                 +and ebx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00477eb4  7585                   -jne 0x477e3b
    if (!cpu.flags.zf)
    {
        goto L_0x00477e3b;
    }
L_0x00477eb6:
    // 00477eb6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00477eba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ebb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ebc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ebd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477ebe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477ebe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477ebf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00477ec1  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477ec4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00477ec7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477ec8  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00477ecb  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00477ece  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00477ed1  c745ec42000000         -mov dword ptr [ebp - 0x14], 0x42
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 66 /*0x42*/;
    // 00477ed8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477ed9  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00477edc  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00477edf  c745e4ffffff7f         -mov dword ptr [ebp - 0x1c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 2147483647 /*0x7fffffff*/;
    // 00477ee6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477ee7  e8b0660000             -call 0x47e59c
    cpu.esp -= 4;
    sub_47e59c(app, cpu);
    // 00477eec  83c40c                 +add esp, 0xc
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
    // 00477eef  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477ef2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477ef4  780b                   -js 0x477f01
    if (cpu.flags.sf)
    {
        goto L_0x00477f01;
    }
    // 00477ef6  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00477ef9  802000                 +and byte ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00477efc  ff45e0                 +inc dword ptr [ebp - 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477eff  eb0d                   -jmp 0x477f0e
    goto L_0x00477f0e;
L_0x00477f01:
    // 00477f01  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00477f04  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477f05  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477f07  e8dc330000             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 00477f0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477f0e:
    // 00477f0e  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477f11  7808                   -js 0x477f1b
    if (cpu.flags.sf)
    {
        goto L_0x00477f1b;
    }
    // 00477f13  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00477f16  802000                 +and byte ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00477f19  eb0d                   -jmp 0x477f28
    goto L_0x00477f28;
L_0x00477f1b:
    // 00477f1b  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00477f1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477f1f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477f21  e8c2330000             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 00477f26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477f28:
    // 00477f28  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477f2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f2b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477f2d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477f2d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477f2e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00477f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477f32  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 00477f37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477f38  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477f39  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477f3f  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 00477f45  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477f47  391de41f5200           +cmp dword ptr [0x521fe4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477f4d  740e                   -je 0x477f5d
    if (cpu.flags.zf)
    {
        goto L_0x00477f5d;
    }
    // 00477f4f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477f50  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477f52  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00477f54  e8704b0000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00477f59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f5a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477f5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477f5d:
    // 00477f5d  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00477f60  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00477f63  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00477f66  e81f000000             -call 0x477f8a
    cpu.esp -= 4;
    sub_477f8a(app, cpu);
    // 00477f6b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477f6e  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00477f71  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477f73  740a                   -je 0x477f7f
    if (cpu.flags.zf)
    {
        goto L_0x00477f7f;
    }
    // 00477f75  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00477f77  e8ae4b0000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00477f7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f7d  eb03                   -jmp 0x477f82
    goto L_0x00477f82;
L_0x00477f7f:
    // 00477f7f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477f80  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00477f82:
    // 00477f82  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00477f85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f88  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477f8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477f8a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477f8b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00477f8d  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00477f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477f92  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00477f94  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477f96  3bd6                   +cmp edx, esi
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
    // 00477f98  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477f99  0f84b9000000           -je 0x478058
    if (cpu.flags.zf)
    {
        goto L_0x00478058;
    }
    // 00477f9f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00477fa2  3bfe                   +cmp edi, esi
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
    // 00477fa4  0f84db000000           -je 0x478085
    if (cpu.flags.zf)
    {
        goto L_0x00478085;
    }
    // 00477faa  3935c4eb5100           +cmp dword ptr [0x51ebc4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477fb0  7529                   -jne 0x477fdb
    if (!cpu.flags.zf)
    {
        goto L_0x00477fdb;
    }
    // 00477fb2  3bfe                   +cmp edi, esi
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
    // 00477fb4  0f86cb000000           -jbe 0x478085
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00478085;
    }
L_0x00477fba:
    // 00477fba  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00477fbd  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477fbf  660fb631               -movzx si, byte ptr [ecx]
    cpu.si = x86::reg16(app->getMemory<x86::reg8>(cpu.ecx));
    // 00477fc3  668932                 -mov word ptr [edx], si
    app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
    // 00477fc6  803900                 +cmp byte ptr [ecx], 0
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
    // 00477fc9  0f84b6000000           -je 0x478085
    if (cpu.flags.zf)
    {
        goto L_0x00478085;
    }
    // 00477fcf  40                     -inc eax
    (cpu.eax)++;
    // 00477fd0  42                     -inc edx
    (cpu.edx)++;
    // 00477fd1  42                     -inc edx
    (cpu.edx)++;
    // 00477fd2  3bc7                   +cmp eax, edi
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
    // 00477fd4  72e4                   -jb 0x477fba
    if (cpu.flags.cf)
    {
        goto L_0x00477fba;
    }
    // 00477fd6  e9aa000000             -jmp 0x478085
    goto L_0x00478085;
L_0x00477fdb:
    // 00477fdb  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00477fde  8b35bc714800           -mov esi, dword ptr [0x4871bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    // 00477fe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477fe5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477fe6  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00477fe8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477fe9  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00477feb  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00477ff1  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00477ff3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477ff5  0f8589000000           -jne 0x478084
    if (!cpu.flags.zf)
    {
        goto L_0x00478084;
    }
    // 00477ffb  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478001  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478004  7410                   -je 0x478016
    if (cpu.flags.zf)
    {
        goto L_0x00478016;
    }
L_0x00478006:
    // 00478006  e8a7640000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047800b  c7002a000000           -mov dword ptr [eax], 0x2a
    app->getMemory<x86::reg32>(cpu.eax) = 42 /*0x2a*/;
    // 00478011  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00478014  eb6f                   -jmp 0x478085
    goto L_0x00478085;
L_0x00478016:
    // 00478016  8d4fff                 -lea ecx, [edi - 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00478019  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047801b  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x0047801e:
    // 0047801e  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00478020  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00478022  741c                   -je 0x478040
    if (cpu.flags.zf)
    {
        goto L_0x00478040;
    }
    // 00478024  8b150c624a00           -mov edx, dword ptr [0x4a620c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0047802a  0fb6c9                 -movzx ecx, cl
    cpu.ecx = x86::reg32(cpu.cl);
    // 0047802d  f6444a0180             +test byte ptr [edx + ecx*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.ecx * 2) & 128 /*0x80*/));
    // 00478032  7401                   -je 0x478035
    if (cpu.flags.zf)
    {
        goto L_0x00478035;
    }
    // 00478034  40                     -inc eax
    (cpu.eax)++;
L_0x00478035:
    // 00478035  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478038  40                     -inc eax
    (cpu.eax)++;
    // 00478039  ff4d0c                 -dec dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))--;
    // 0047803c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047803e  75de                   -jne 0x47801e
    if (!cpu.flags.zf)
    {
        goto L_0x0047801e;
    }
L_0x00478040:
    // 00478040  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478041  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478043  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00478046  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478047  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478048  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047804a  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00478050  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478052  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478054  752f                   -jne 0x478085
    if (!cpu.flags.zf)
    {
        goto L_0x00478085;
    }
    // 00478056  ebae                   -jmp 0x478006
    goto L_0x00478006;
L_0x00478058:
    // 00478058  3935c4eb5100           +cmp dword ptr [0x51ebc4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047805e  750b                   -jne 0x47806b
    if (!cpu.flags.zf)
    {
        goto L_0x0047806b;
    }
    // 00478060  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478063  e8785d0000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00478068  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478069  eb1a                   -jmp 0x478085
    goto L_0x00478085;
L_0x0047806b:
    // 0047806b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047806c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047806d  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0047806f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478072  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00478074  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 0047807a  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478080  3bc6                   +cmp eax, esi
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
    // 00478082  7482                   -je 0x478006
    if (cpu.flags.zf)
    {
        goto L_0x00478006;
    }
L_0x00478084:
    // 00478084  48                     -dec eax
    (cpu.eax)--;
L_0x00478085:
    // 00478085  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478086  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478088  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478089  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47808a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047808a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047808b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047808c  be283d4a00             -mov esi, 0x4a3d28
    cpu.esi = 4865320 /*0x4a3d28*/;
    // 00478091  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478092  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478093  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478095  e81efbffff             -call 0x477bb8
    cpu.esp -= 4;
    sub_477bb8(app, cpu);
    // 0047809a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047809b  e8a4290000             -call 0x47aa44
    cpu.esp -= 4;
    sub_47aa44(app, cpu);
    // 004780a0  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004780a2  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004780a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004780a7  ff742420               -push dword ptr [esp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004780ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004780ac  e8eb640000             -call 0x47e59c
    cpu.esp -= 4;
    sub_47e59c(app, cpu);
    // 004780b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004780b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004780b3  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004780b5  e8172a0000             -call 0x47aad1
    cpu.esp -= 4;
    sub_47aad1(app, cpu);
    // 004780ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004780bb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004780bd  e848fbffff             -call 0x477c0a
    cpu.esp -= 4;
    sub_477c0a(app, cpu);
    // 004780c2  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004780c5  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004780c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004780c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004780c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004780ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_strncmp(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004780d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004780d1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004780d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004780d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004780d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004780d6  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004780d9  e326                   -jecxz 0x478101
    if (cpu.ecx == 0)
    {
        goto L_0x00478101;
    }
    // 004780db  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004780dd  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004780e0  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004780e2  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004780e4  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004780e6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004780e8  03cb                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004780ea  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004780ec  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004780ef  f3a6                   -repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004780f1  8a46ff                 -mov al, byte ptr [esi - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004780f4  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004780f6  3a47ff                 +cmp al, byte ptr [edi - 1]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004780f9  7704                   -ja 0x4780ff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004780ff;
    }
    // 004780fb  7404                   -je 0x478101
    if (cpu.flags.zf)
    {
        goto L_0x00478101;
    }
    // 004780fd  49                     -dec ecx
    (cpu.ecx)--;
    // 004780fe  49                     -dec ecx
    (cpu.ecx)--;
L_0x004780ff:
    // 004780ff  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
L_0x00478101:
    // 00478101  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478103  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478104  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478105  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478106  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478107  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478108(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478108  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0047810c  ff15b8704800           -call dword ptr [0x4870b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747448) /* 0x4870b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478112  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478114  7508                   -jne 0x47811e
    if (!cpu.flags.zf)
    {
        goto L_0x0047811e;
    }
    // 00478116  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047811c  eb02                   -jmp 0x478120
    goto L_0x00478120;
L_0x0047811e:
    // 0047811e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478120:
    // 00478120  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478122  740b                   -je 0x47812f
    if (cpu.flags.zf)
    {
        goto L_0x0047812f;
    }
    // 00478124  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478125  e815630000             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 0047812a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047812b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0047812e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047812f:
    // 0047812f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478131  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478132(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478133  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00478135  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478136  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478137  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 0047813c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047813d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047813e  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478144  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 0047814a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047814c  391de41f5200           +cmp dword ptr [0x521fe4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478152  740e                   -je 0x478162
    if (cpu.flags.zf)
    {
        goto L_0x00478162;
    }
    // 00478154  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478155  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478157  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00478159  e86b490000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047815e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047815f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478161  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478162:
    // 00478162  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00478165  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478168  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047816b  e81f000000             -call 0x47818f
    cpu.esp -= 4;
    sub_47818f(app, cpu);
    // 00478170  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478173  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00478176  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00478178  740a                   -je 0x478184
    if (cpu.flags.zf)
    {
        goto L_0x00478184;
    }
    // 0047817a  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0047817c  e8a9490000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00478181  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478182  eb03                   -jmp 0x478187
    goto L_0x00478187;
L_0x00478184:
    // 00478184  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478185  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00478187:
    // 00478187  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047818a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047818b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047818c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047818d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047818e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47818f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047818f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478190  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00478192  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478195  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478196  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478197  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047819a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047819b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047819d  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047819f  3bf3                   +cmp esi, ebx
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
    // 004781a1  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004781a4  0f8445010000           -je 0x4782ef
    if (cpu.flags.zf)
    {
        goto L_0x004782ef;
    }
    // 004781aa  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004781ad  3bd3                   +cmp edx, ebx
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
    // 004781af  7507                   -jne 0x4781b8
    if (!cpu.flags.zf)
    {
        goto L_0x004781b8;
    }
    // 004781b1  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004781b3  e981010000             -jmp 0x478339
    goto L_0x00478339;
L_0x004781b8:
    // 004781b8  391dc4eb5100           +cmp dword ptr [0x51ebc4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004781be  752d                   -jne 0x4781ed
    if (!cpu.flags.zf)
    {
        goto L_0x004781ed;
    }
    // 004781c0  3bd3                   +cmp edx, ebx
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
    // 004781c2  7622                   -jbe 0x4781e6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004781e6;
    }
    // 004781c4  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004781c7:
    // 004781c7  668139ff00             +cmp word ptr [ecx], 0xff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(255 /*0xff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004781cc  0f8759010000           -ja 0x47832b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 004781d2  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004781d4  880437                 -mov byte ptr [edi + esi], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.esi * 1) = cpu.al;
    // 004781d7  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004781da  41                     -inc ecx
    (cpu.ecx)++;
    // 004781db  41                     -inc ecx
    (cpu.ecx)++;
    // 004781dc  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004781df  7405                   -je 0x4781e6
    if (cpu.flags.zf)
    {
        goto L_0x004781e6;
    }
    // 004781e1  47                     -inc edi
    (cpu.edi)++;
    // 004781e2  3bfa                   +cmp edi, edx
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
    // 004781e4  72e1                   -jb 0x4781c7
    if (cpu.flags.cf)
    {
        goto L_0x004781c7;
    }
L_0x004781e6:
    // 004781e6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004781e8  e94c010000             -jmp 0x478339
    goto L_0x00478339;
L_0x004781ed:
    // 004781ed  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 004781f4  7550                   -jne 0x478246
    if (!cpu.flags.zf)
    {
        goto L_0x00478246;
    }
    // 004781f6  3bd3                   +cmp edx, ebx
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
    // 004781f8  7610                   -jbe 0x47820a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047820a;
    }
    // 004781fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004781fb  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004781fe  e83b010000             -call 0x47833e
    cpu.esp -= 4;
    sub_47833e(app, cpu);
    // 00478203  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478204  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00478207  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478208  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0047820a:
    // 0047820a  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047820d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047820e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047820f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478210  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478211  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478212  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478215  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 0047821a  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00478220  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478226  3bc3                   +cmp eax, ebx
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
    // 00478228  0f84fd000000           -je 0x47832b
    if (cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 0047822e  395df8                 +cmp dword ptr [ebp - 8], ebx
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
    // 00478231  0f85f4000000           -jne 0x47832b
    if (!cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 00478237  385c30ff               +cmp byte ptr [eax + esi - 1], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */ + cpu.esi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047823b  0f85f8000000           -jne 0x478339
    if (!cpu.flags.zf)
    {
        goto L_0x00478339;
    }
    // 00478241  e9e2000000             -jmp 0x478328
    goto L_0x00478328;
L_0x00478246:
    // 00478246  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00478249  8b3da8714800           -mov edi, dword ptr [0x4871a8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    // 0047824f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478251  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478252  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478253  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00478255  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478258  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 0047825d  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00478263  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478265  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478267  3bf3                   +cmp esi, ebx
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
    // 00478269  7411                   -je 0x47827c
    if (cpu.flags.zf)
    {
        goto L_0x0047827c;
    }
    // 0047826b  395df8                 +cmp dword ptr [ebp - 8], ebx
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
    // 0047826e  0f85b7000000           -jne 0x47832b
    if (!cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 00478274  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00478277  e9bd000000             -jmp 0x478339
    goto L_0x00478339;
L_0x0047827c:
    // 0047827c  395df8                 +cmp dword ptr [ebp - 8], ebx
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
    // 0047827f  0f85a6000000           -jne 0x47832b
    if (!cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 00478285  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047828b  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047828e  0f8597000000           -jne 0x47832b
    if (!cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
L_0x00478294:
    // 00478294  3b7510                 +cmp esi, dword ptr [ebp + 0x10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478297  7352                   -jae 0x4782eb
    if (!cpu.flags.cf)
    {
        goto L_0x004782eb;
    }
    // 00478299  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047829c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047829d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047829e  ff3518644a00           -push dword ptr [0x4a6418]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
    cpu.esp -= 4;
    // 004782a4  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 004782a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004782a8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004782aa  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004782ad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004782ae  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 004782b4  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004782b6  3bc3                   +cmp eax, ebx
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
    // 004782b8  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004782bb  746e                   -je 0x47832b
    if (cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 004782bd  395df8                 +cmp dword ptr [ebp - 8], ebx
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
    // 004782c0  7569                   -jne 0x47832b
    if (!cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 004782c2  8d0c30                 -lea ecx, [eax + esi]
    cpu.ecx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004782c5  3b4d10                 +cmp ecx, dword ptr [ebp + 0x10]
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
    // 004782c8  7721                   -ja 0x4782eb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004782eb;
    }
    // 004782ca  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004782cc  3bc3                   +cmp eax, ebx
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
    // 004782ce  7e15                   -jle 0x4782e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004782e5;
    }
L_0x004782d0:
    // 004782d0  8a4c15fe               -mov cl, byte ptr [ebp + edx - 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1);
    // 004782d4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004782d7  3acb                   +cmp cl, bl
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
    // 004782d9  880c06                 -mov byte ptr [esi + eax], cl
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.cl;
    // 004782dc  740d                   -je 0x4782eb
    if (cpu.flags.zf)
    {
        goto L_0x004782eb;
    }
    // 004782de  42                     -inc edx
    (cpu.edx)++;
    // 004782df  46                     -inc esi
    (cpu.esi)++;
    // 004782e0  3b55f4                 +cmp edx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004782e3  7ceb                   -jl 0x4782d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004782d0;
    }
L_0x004782e5:
    // 004782e5  83450c02               +add dword ptr [ebp + 0xc], 2
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004782e9  eba9                   -jmp 0x478294
    goto L_0x00478294;
L_0x004782eb:
    // 004782eb  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004782ed  eb4a                   -jmp 0x478339
    goto L_0x00478339;
L_0x004782ef:
    // 004782ef  391dc4eb5100           +cmp dword ptr [0x51ebc4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004782f5  750b                   -jne 0x478302
    if (!cpu.flags.zf)
    {
        goto L_0x00478302;
    }
    // 004782f7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004782fa  e89efaffff             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 004782ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478300  eb37                   -jmp 0x478339
    goto L_0x00478339;
L_0x00478302:
    // 00478302  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00478305  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478306  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478307  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478308  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478309  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0047830b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047830e  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00478313  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00478319  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047831f  3bc3                   +cmp eax, ebx
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
    // 00478321  7408                   -je 0x47832b
    if (cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
    // 00478323  395df8                 +cmp dword ptr [ebp - 8], ebx
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
    // 00478326  7503                   -jne 0x47832b
    if (!cpu.flags.zf)
    {
        goto L_0x0047832b;
    }
L_0x00478328:
    // 00478328  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478329  eb0e                   -jmp 0x478339
    goto L_0x00478339;
L_0x0047832b:
    // 0047832b  e882610000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00478330  c7002a000000           -mov dword ptr [eax], 0x2a
    app->getMemory<x86::reg32>(cpu.eax) = 42 /*0x2a*/;
    // 00478336  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x00478339:
    // 00478339  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047833a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047833b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047833c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047833d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47833e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047833e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047833f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00478341  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478344  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00478347  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478349  3bca                   +cmp ecx, edx
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
    // 0047834b  741b                   -je 0x478368
    if (cpu.flags.zf)
    {
        goto L_0x00478368;
    }
L_0x0047834d:
    // 0047834d  663910                 +cmp word ptr [eax], dx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.dx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00478350  7405                   -je 0x478357
    if (cpu.flags.zf)
    {
        goto L_0x00478357;
    }
    // 00478352  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00478353  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00478354  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478355  75f6                   -jne 0x47834d
    if (!cpu.flags.zf)
    {
        goto L_0x0047834d;
    }
L_0x00478357:
    // 00478357  3bca                   +cmp ecx, edx
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
    // 00478359  740d                   -je 0x478368
    if (cpu.flags.zf)
    {
        goto L_0x00478368;
    }
    // 0047835b  663910                 +cmp word ptr [eax], dx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.dx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047835e  7508                   -jne 0x478368
    if (!cpu.flags.zf)
    {
        goto L_0x00478368;
    }
    // 00478360  2b4508                 -sub eax, dword ptr [ebp + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00478363  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00478365  40                     -inc eax
    (cpu.eax)++;
    // 00478366  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478367  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478368:
    // 00478368  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047836b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047836c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47836d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047836d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047836e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00478370  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478373  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00478376  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478377  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047837a  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0047837d  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00478380  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00478383  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478386  c745ec42000000         -mov dword ptr [ebp - 0x14], 0x42
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 66 /*0x42*/;
    // 0047838d  c745e4ffffff7f         -mov dword ptr [ebp - 0x1c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 2147483647 /*0x7fffffff*/;
    // 00478394  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478395  e861270000             -call 0x47aafb
    cpu.esp -= 4;
    sub_47aafb(app, cpu);
    // 0047839a  83c40c                 +add esp, 0xc
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
    // 0047839d  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004783a0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004783a2  7808                   -js 0x4783ac
    if (cpu.flags.sf)
    {
        goto L_0x004783ac;
    }
    // 004783a4  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004783a7  802000                 +and byte ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 004783aa  eb0d                   -jmp 0x4783b9
    goto L_0x004783b9;
L_0x004783ac:
    // 004783ac  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004783af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004783b0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004783b2  e8312f0000             -call 0x47b2e8
    cpu.esp -= 4;
    sub_47b2e8(app, cpu);
    // 004783b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004783b9:
    // 004783b9  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004783bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783bc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4783be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004783be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004783bf  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004783c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004783c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004783c5  e8bff7ffff             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 004783ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004783cb  e810000000             -call 0x4783e0
    cpu.esp -= 4;
    sub_4783e0(app, cpu);
    // 004783d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004783d1  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004783d3  e803f8ffff             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 004783d8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004783db  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004783dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004783df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4783e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004783e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004783e1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004783e3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004783e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004783e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004783e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004783e9  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004783ec  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004783ee  8b7710                 -mov esi, dword ptr [edi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004783f1  395f04                 +cmp dword ptr [edi + 4], ebx
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
    // 004783f4  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004783f7  7d03                   -jge 0x4783fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004783fc;
    }
    // 004783f9  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004783fc:
    // 004783fc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004783fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004783ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478400  e8bf600000             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    // 00478405  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478408  3bc3                   +cmp eax, ebx
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
    // 0047840a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047840d  7c5f                   -jl 0x47846e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047846e;
    }
    // 0047840f  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00478412  66f7c10801             +test cx, 0x108
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & 264 /*0x108*/));
    // 00478417  7508                   -jne 0x478421
    if (!cpu.flags.zf)
    {
        goto L_0x00478421;
    }
    // 00478419  2b4704                 +sub eax, dword ptr [edi + 4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047841c  e91b010000             -jmp 0x47853c
    goto L_0x0047853c;
L_0x00478421:
    // 00478421  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478423  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00478426  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478428  2bda                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047842a  f6c103                 +test cl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 3 /*0x3*/));
    // 0047842d  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00478430  742c                   -je 0x47845e
    if (cpu.flags.zf)
    {
        goto L_0x0047845e;
    }
    // 00478432  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00478434  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00478436  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 00478439  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047843c  8b1c9de01e5200         -mov ebx, dword ptr [ebx*4 + 0x521ee0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ebx * 4);
    // 00478443  8d0cc9                 -lea ecx, [ecx + ecx*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 8);
    // 00478446  f6448b0480             +test byte ptr [ebx + ecx*4 + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) & 128 /*0x80*/));
    // 0047844b  7429                   -je 0x478476
    if (cpu.flags.zf)
    {
        goto L_0x00478476;
    }
    // 0047844d  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x0047844f:
    // 0047844f  3bc8                   +cmp ecx, eax
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
    // 00478451  7323                   -jae 0x478476
    if (!cpu.flags.cf)
    {
        goto L_0x00478476;
    }
    // 00478453  80390a                 +cmp byte ptr [ecx], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478456  7503                   -jne 0x47845b
    if (!cpu.flags.zf)
    {
        goto L_0x0047845b;
    }
    // 00478458  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0047845b:
    // 0047845b  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047845c  ebf1                   -jmp 0x47844f
    goto L_0x0047844f;
L_0x0047845e:
    // 0047845e  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 00478461  7513                   -jne 0x478476
    if (!cpu.flags.zf)
    {
        goto L_0x00478476;
    }
    // 00478463  e84a600000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00478468  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
L_0x0047846e:
    // 0047846e  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00478471  e9c6000000             -jmp 0x47853c
    goto L_0x0047853c;
L_0x00478476:
    // 00478476  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 0047847a  7508                   -jne 0x478484
    if (!cpu.flags.zf)
    {
        goto L_0x00478484;
    }
    // 0047847c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047847f  e9b8000000             -jmp 0x47853c
    goto L_0x0047853c;
L_0x00478484:
    // 00478484  f6470c01               +test byte ptr [edi + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 00478488  0f84a6000000           -je 0x478534
    if (cpu.flags.zf)
    {
        goto L_0x00478534;
    }
    // 0047848e  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00478491  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00478493  7508                   -jne 0x47849d
    if (!cpu.flags.zf)
    {
        goto L_0x0047849d;
    }
    // 00478495  214df8                 +and dword ptr [ebp - 8], ecx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00478498  e997000000             -jmp 0x478534
    goto L_0x00478534;
L_0x0047849d:
    // 0047849d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047849f  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004784a1  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004784a4  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004784a6  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 004784a9  8d1c85e01e5200         -lea ebx, [eax*4 + 0x521ee0]
    cpu.ebx = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 004784b0  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004784b2  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004784b5  8d34c0                 -lea esi, [eax + eax*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004784b8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004784ba  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004784bd  f644060480             +test byte ptr [esi + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 004784c2  746a                   -je 0x47852e
    if (cpu.flags.zf)
    {
        goto L_0x0047852e;
    }
    // 004784c4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004784c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004784c8  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 004784cb  e8f45f0000             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    // 004784d0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004784d3  3b45fc                 +cmp eax, dword ptr [ebp - 4]
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
    // 004784d6  751d                   -jne 0x4784f5
    if (!cpu.flags.zf)
    {
        goto L_0x004784f5;
    }
    // 004784d8  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004784db  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004784de  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004784e0:
    // 004784e0  3bc1                   +cmp eax, ecx
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
    // 004784e2  730b                   -jae 0x4784ef
    if (!cpu.flags.cf)
    {
        goto L_0x004784ef;
    }
    // 004784e4  80380a                 +cmp byte ptr [eax], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004784e7  7503                   -jne 0x4784ec
    if (!cpu.flags.zf)
    {
        goto L_0x004784ec;
    }
    // 004784e9  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004784ec:
    // 004784ec  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004784ed  ebf1                   -jmp 0x4784e0
    goto L_0x004784e0;
L_0x004784ef:
    // 004784ef  f6470d20               +test byte ptr [edi + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 004784f3  eb34                   -jmp 0x478529
    goto L_0x00478529;
L_0x004784f5:
    // 004784f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004784f7  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 004784fa  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 004784fd  e8c25f0000             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    // 00478502  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 00478507  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047850a  394508                 +cmp dword ptr [ebp + 8], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047850d  770d                   -ja 0x47851c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047851c;
    }
    // 0047850f  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00478512  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00478515  7405                   -je 0x47851c
    if (cpu.flags.zf)
    {
        goto L_0x0047851c;
    }
    // 00478517  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0047851a  7403                   -je 0x47851f
    if (cpu.flags.zf)
    {
        goto L_0x0047851f;
    }
L_0x0047851c:
    // 0047851c  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
L_0x0047851f:
    // 0047851f  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00478522  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00478524  f644060404             +test byte ptr [esi + eax + 4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 4 /*0x4*/));
L_0x00478529:
    // 00478529  7403                   -je 0x47852e
    if (cpu.flags.zf)
    {
        goto L_0x0047852e;
    }
    // 0047852b  ff4508                 -inc dword ptr [ebp + 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */))++;
L_0x0047852e:
    // 0047852e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00478531  2945fc                 -sub dword ptr [ebp - 4], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478534:
    // 00478534  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00478537  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047853a  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047853c:
    // 0047853c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047853d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047853e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047853f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478541(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478541  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478542  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478543  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478547  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478548  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478549  e83bf6ffff             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 0047854e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047854f  e8f0240000             -call 0x47aa44
    cpu.esp -= 4;
    sub_47aa44(app, cpu);
    // 00478554  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478556  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047855a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047855b  ff742420               -push dword ptr [esp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0047855f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478560  e896250000             -call 0x47aafb
    cpu.esp -= 4;
    sub_47aafb(app, cpu);
    // 00478565  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478566  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478567  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478569  e863250000             -call 0x47aad1
    cpu.esp -= 4;
    sub_47aad1(app, cpu);
    // 0047856e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047856f  e867f6ffff             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 00478574  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478577  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478579  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047857a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047857b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047857c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47857d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047857d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047857e  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00478580  e844450000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00478585  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478589  e810000000             -call 0x47859e
    cpu.esp -= 4;
    sub_47859e(app, cpu);
    // 0047858e  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00478590  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478592  e893450000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00478597  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047859a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047859c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047859d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47859e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047859e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047859f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004785a0  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004785a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004785a3  392d14205200           +cmp dword ptr [0x522014], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382164) /* 0x522014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004785a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004785aa  747a                   -je 0x478626
    if (cpu.flags.zf)
    {
        goto L_0x00478626;
    }
    // 004785ac  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004785b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004785b1  e82a580000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 004785b6  40                     -inc eax
    (cpu.eax)++;
    // 004785b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004785b8  e8bdecffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 004785bd  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004785bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785c0  3bf5                   +cmp esi, ebp
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
    // 004785c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785c3  7461                   -je 0x478626
    if (cpu.flags.zf)
    {
        goto L_0x00478626;
    }
    // 004785c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004785c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004785c7  e8646c0000             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 004785cc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004785ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004785cf  e8126a0000             -call 0x47efe6
    cpu.esp -= 4;
    sub_47efe6(app, cpu);
    // 004785d4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004785d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004785d9  754b                   -jne 0x478626
    if (!cpu.flags.zf)
    {
        goto L_0x00478626;
    }
    // 004785db  392d10eb5100           +cmp dword ptr [0x51eb10], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368592) /* 0x51eb10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004785e1  7448                   -je 0x47862b
    if (cpu.flags.zf)
    {
        goto L_0x0047862b;
    }
    // 004785e3  8b3dbc714800           -mov edi, dword ptr [0x4871bc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    // 004785e9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004785ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004785eb  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004785ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004785ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004785ef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004785f1  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004785f3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004785f5  3bf5                   +cmp esi, ebp
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
    // 004785f7  742d                   -je 0x478626
    if (cpu.flags.zf)
    {
        goto L_0x00478626;
    }
    // 004785f9  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004785fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004785fd  e878ecffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00478602  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00478604  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478605  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00478607  741d                   -je 0x478626
    if (cpu.flags.zf)
    {
        goto L_0x00478626;
    }
    // 00478609  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047860a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047860b  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0047860d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047860e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478610  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478612  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478614  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478616  740e                   -je 0x478626
    if (cpu.flags.zf)
    {
        goto L_0x00478626;
    }
    // 00478618  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047861a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047861b  e870670000             -call 0x47ed90
    cpu.esp -= 4;
    sub_47ed90(app, cpu);
    // 00478620  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478621  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478623  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478624  7405                   -je 0x47862b
    if (cpu.flags.zf)
    {
        goto L_0x0047862b;
    }
L_0x00478626:
    // 00478626  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00478629  eb02                   -jmp 0x47862d
    goto L_0x0047862d;
L_0x0047862b:
    // 0047862b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047862d:
    // 0047862d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047862e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047862f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478630  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478631  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478632(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478632  a1ec3c4a00             -mov eax, dword ptr [0x4a3cec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4865260) /* 0x4a3cec */);
    // 00478637  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478639  7402                   -je 0x47863d
    if (cpu.flags.zf)
    {
        goto L_0x0047863d;
    }
    // 0047863b  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047863d:
    // 0047863d  6820a04800             -push 0x48a020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759584 /*0x48a020*/;
    cpu.esp -= 4;
    // 00478642  6810a04800             -push 0x48a010
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759568 /*0x48a010*/;
    cpu.esp -= 4;
    // 00478647  e8ec000000             -call 0x478738
    cpu.esp -= 4;
    sub_478738(app, cpu);
    // 0047864c  680ca04800             -push 0x48a00c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759564 /*0x48a00c*/;
    cpu.esp -= 4;
    // 00478651  6800a04800             -push 0x48a000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759552 /*0x48a000*/;
    cpu.esp -= 4;
    // 00478656  e8dd000000             -call 0x478738
    cpu.esp -= 4;
    sub_478738(app, cpu);
    // 0047865b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047865e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47865f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047865f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478661  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478663  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478667  e815000000             -call 0x478681
    cpu.esp -= 4;
    sub_478681(app, cpu);
    // 0047866c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047866f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::__exit(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478670  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478672  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478674  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478678  e804000000             -call 0x478681
    cpu.esp -= 4;
    sub_478681(app, cpu);
    // 0047867d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478680  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478681(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478681  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478682  e89f000000             -call 0x478726
    cpu.esp -= 4;
    sub_478726(app, cpu);
    // 00478687  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478689  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047868a  393d28eb5100           +cmp dword ptr [0x51eb28], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368616) /* 0x51eb28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478690  7511                   -jne 0x4786a3
    if (!cpu.flags.zf)
    {
        goto L_0x004786a3;
    }
    // 00478692  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00478696  ff1590704800           -call dword ptr [0x487090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747408) /* 0x487090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047869c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047869d  ff158c704800           -call dword ptr [0x48708c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747404) /* 0x48708c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004786a3:
    // 004786a3  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004786a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004786a9  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004786ad  893d24eb5100           -mov dword ptr [0x51eb24], edi
    app->getMemory<x86::reg32>(x86::reg32(5368612) /* 0x51eb24 */) = cpu.edi;
    // 004786b3  881d20eb5100           -mov byte ptr [0x51eb20], bl
    app->getMemory<x86::reg8>(x86::reg32(5368608) /* 0x51eb20 */) = cpu.bl;
    // 004786b9  753c                   -jne 0x4786f7
    if (!cpu.flags.zf)
    {
        goto L_0x004786f7;
    }
    // 004786bb  a120205200             -mov eax, dword ptr [0x522020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5382176) /* 0x522020 */);
    // 004786c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004786c2  7422                   -je 0x4786e6
    if (cpu.flags.zf)
    {
        goto L_0x004786e6;
    }
    // 004786c4  8b0d1c205200           -mov ecx, dword ptr [0x52201c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5382172) /* 0x52201c */);
    // 004786ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004786cb  8d71fc                 -lea esi, [ecx - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004786ce  3bf0                   +cmp esi, eax
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
    // 004786d0  7213                   -jb 0x4786e5
    if (cpu.flags.cf)
    {
        goto L_0x004786e5;
    }
L_0x004786d2:
    // 004786d2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004786d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004786d6  7402                   -je 0x4786da
    if (cpu.flags.zf)
    {
        goto L_0x004786da;
    }
    // 004786d8  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004786da:
    // 004786da  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004786dd  3b3520205200           +cmp esi, dword ptr [0x522020]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5382176) /* 0x522020 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004786e3  73ed                   -jae 0x4786d2
    if (!cpu.flags.cf)
    {
        goto L_0x004786d2;
    }
L_0x004786e5:
    // 004786e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004786e6:
    // 004786e6  682ca04800             -push 0x48a02c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759596 /*0x48a02c*/;
    cpu.esp -= 4;
    // 004786eb  6824a04800             -push 0x48a024
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759588 /*0x48a024*/;
    cpu.esp -= 4;
    // 004786f0  e843000000             -call 0x478738
    cpu.esp -= 4;
    sub_478738(app, cpu);
    // 004786f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004786f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004786f7:
    // 004786f7  6838a04800             -push 0x48a038
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759608 /*0x48a038*/;
    cpu.esp -= 4;
    // 004786fc  6830a04800             -push 0x48a030
    app->getMemory<x86::reg32>(cpu.esp-4) = 4759600 /*0x48a030*/;
    cpu.esp -= 4;
    // 00478701  e832000000             -call 0x478738
    cpu.esp -= 4;
    sub_478738(app, cpu);
    // 00478706  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478707  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478708  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047870a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047870b  7407                   -je 0x478714
    if (cpu.flags.zf)
    {
        goto L_0x00478714;
    }
    // 0047870d  e81d000000             -call 0x47872f
    cpu.esp -= 4;
    sub_47872f(app, cpu);
    // 00478712  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478713  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478714:
    // 00478714  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00478718  893d28eb5100           -mov dword ptr [0x51eb28], edi
    app->getMemory<x86::reg32>(x86::reg32(5368616) /* 0x51eb28 */) = cpu.edi;
    // 0047871e  ff15c0714800           -call dword ptr [0x4871c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747712) /* 0x4871c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    NFS2_ASSERT(false);  // falls off the end of the routine
}

/* align: skip  */
void Application::sub_478726(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478726  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00478728  e89c430000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 0047872d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047872e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47872f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047872f  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00478731  e8f4430000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00478736  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478737  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478738(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478738  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478739  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0047873d:
    // 0047873d  3b74240c               +cmp esi, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478741  730d                   -jae 0x478750
    if (!cpu.flags.cf)
    {
        goto L_0x00478750;
    }
    // 00478743  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00478745  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478747  7402                   -je 0x47874b
    if (cpu.flags.zf)
    {
        goto L_0x0047874b;
    }
    // 00478749  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047874b:
    // 0047874b  83c604                 +add esi, 4
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
    // 0047874e  ebed                   -jmp 0x47873d
    goto L_0x0047873d;
L_0x00478750:
    // 00478750  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478751  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478752(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478752  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478753  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478757  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478758  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478759  e82bf4ffff             -call 0x477b89
    cpu.esp -= 4;
    sub_477b89(app, cpu);
    // 0047875e  ff4e04                 +dec dword ptr [esi + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478761  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478762  780a                   -js 0x47876e
    if (cpu.flags.sf)
    {
        goto L_0x0047876e;
    }
    // 00478764  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00478766  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00478769  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047876a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047876c  eb09                   -jmp 0x478777
    goto L_0x00478777;
L_0x0047876e:
    // 0047876e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047876f  e8e7560000             -call 0x47de5b
    cpu.esp -= 4;
    sub_47de5b(app, cpu);
    // 00478774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478775  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00478777:
    // 00478777  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478778  e85ef4ffff             -call 0x477bdb
    cpu.esp -= 4;
    sub_477bdb(app, cpu);
    // 0047877d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047877e  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00478780  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478781  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478782  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478783(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478784  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478788  3b35e01f5200           +cmp esi, dword ptr [0x521fe0]
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
    // 0047878e  7338                   -jae 0x4787c8
    if (!cpu.flags.cf)
    {
        goto L_0x004787c8;
    }
    // 00478790  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00478792  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478794  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00478797  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047879a  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 004787a1  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004787a4  f644810401             +test byte ptr [ecx + eax*4 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) & 1 /*0x1*/));
    // 004787a9  741d                   -je 0x4787c8
    if (cpu.flags.zf)
    {
        goto L_0x004787c8;
    }
    // 004787ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004787ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004787ad  e8ce6d0000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 004787b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004787b3  e828000000             -call 0x4787e0
    cpu.esp -= 4;
    sub_4787e0(app, cpu);
    // 004787b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004787b9  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004787bb  e81f6e0000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 004787c0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004787c3  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004787c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004787c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004787c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004787c8:
    // 004787c8  e8e55c0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 004787cd  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 004787d3  e8e35c0000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 004787d8  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004787db  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004787de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004787df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4787e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004787e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004787e1  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004787e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004787e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004787e7  e8526d0000             -call 0x47f53e
    cpu.esp -= 4;
    sub_47f53e(app, cpu);
    // 004787ec  83f8ff                 +cmp eax, -1
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
    // 004787ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004787f0  743c                   -je 0x47882e
    if (cpu.flags.zf)
    {
        goto L_0x0047882e;
    }
    // 004787f2  83fe01                 +cmp esi, 1
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
    // 004787f5  7405                   -je 0x4787fc
    if (cpu.flags.zf)
    {
        goto L_0x004787fc;
    }
    // 004787f7  83fe02                 +cmp esi, 2
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
    // 004787fa  7516                   -jne 0x478812
    if (!cpu.flags.zf)
    {
        goto L_0x00478812;
    }
L_0x004787fc:
    // 004787fc  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004787fe  e83b6d0000             -call 0x47f53e
    cpu.esp -= 4;
    sub_47f53e(app, cpu);
    // 00478803  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478805  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478807  e8326d0000             -call 0x47f53e
    cpu.esp -= 4;
    sub_47f53e(app, cpu);
    // 0047880c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047880d  3bc7                   +cmp eax, edi
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
    // 0047880f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478810  741c                   -je 0x47882e
    if (cpu.flags.zf)
    {
        goto L_0x0047882e;
    }
L_0x00478812:
    // 00478812  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478813  e8266d0000             -call 0x47f53e
    cpu.esp -= 4;
    sub_47f53e(app, cpu);
    // 00478818  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478819  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047881a  ff15d4704800           -call dword ptr [0x4870d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747476) /* 0x4870d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478820  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478822  750a                   -jne 0x47882e
    if (!cpu.flags.zf)
    {
        goto L_0x0047882e;
    }
    // 00478824  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047882a  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047882c  eb02                   -jmp 0x478830
    goto L_0x00478830;
L_0x0047882e:
    // 0047882e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00478830:
    // 00478830  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478831  e8896c0000             -call 0x47f4bf
    cpu.esp -= 4;
    sub_47f4bf(app, cpu);
    // 00478836  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478838  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047883b  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047883e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047883f  8b0485e01e5200         -mov eax, dword ptr [eax*4 + 0x521ee0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 00478846  8d0cf6                 -lea ecx, [esi + esi*8]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 8);
    // 00478849  8064880400             -and byte ptr [eax + ecx*4 + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0047884e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00478850  740c                   -je 0x47885e
    if (cpu.flags.zf)
    {
        goto L_0x0047885e;
    }
    // 00478852  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478853  e8e75b0000             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00478858  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478859  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047885c  eb02                   -jmp 0x478860
    goto L_0x00478860;
L_0x0047885e:
    // 0047885e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478860:
    // 00478860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478862  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478863(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478863  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478864  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478868  3b35e01f5200           +cmp esi, dword ptr [0x521fe0]
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
    // 0047886e  7340                   -jae 0x4788b0
    if (!cpu.flags.cf)
    {
        goto L_0x004788b0;
    }
    // 00478870  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00478872  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478874  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00478877  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047887a  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 00478881  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00478884  f644810401             +test byte ptr [ecx + eax*4 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) & 1 /*0x1*/));
    // 00478889  7425                   -je 0x4788b0
    if (cpu.flags.zf)
    {
        goto L_0x004788b0;
    }
    // 0047888b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047888c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047888d  e8ee6c0000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 00478892  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00478896  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047889a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047889b  e828000000             -call 0x4788c8
    cpu.esp -= 4;
    sub_4788c8(app, cpu);
    // 004788a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004788a1  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004788a3  e8376d0000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 004788a8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004788ab  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004788ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004788b0:
    // 004788b0  e8fd5b0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 004788b5  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 004788bb  e8fb5b0000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 004788c0  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004788c3  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004788c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4788c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004788c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004788c9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004788cb  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004788ce  8365f800               -and dword ptr [ebp - 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004788d2  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 004788d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004788d7  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004788da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004788db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004788dc  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004788de  0f84b6010000           -je 0x478a9a
    if (cpu.flags.zf)
    {
        goto L_0x00478a9a;
    }
    // 004788e4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004788e7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004788e9  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004788ec  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004788ef  8d34c0                 -lea esi, [eax + eax*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004788f2  8b048de01e5200         -mov eax, dword ptr [ecx*4 + 0x521ee0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 004788f9  8d3c8de01e5200         -lea edi, [ecx*4 + 0x521ee0]
    cpu.edi = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 00478900  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00478903  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00478905  8a4804                 -mov cl, byte ptr [eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00478908  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0047890b  0f8589010000           -jne 0x478a9a
    if (!cpu.flags.zf)
    {
        goto L_0x00478a9a;
    }
    // 00478911  f6c148                 +test cl, 0x48
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 72 /*0x48*/));
    // 00478914  741d                   -je 0x478933
    if (cpu.flags.zf)
    {
        goto L_0x00478933;
    }
    // 00478916  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00478919  3c0a                   +cmp al, 0xa
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
    // 0047891b  7416                   -je 0x478933
    if (cpu.flags.zf)
    {
        goto L_0x00478933;
    }
    // 0047891d  ff4d10                 -dec dword ptr [ebp + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))--;
    // 00478920  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00478922  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478924  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00478927  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 0047892e  c64430050a             -mov byte ptr [eax + esi + 5], 0xa
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */ + cpu.esi * 1) = 10 /*0xa*/;
L_0x00478933:
    // 00478933  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00478936  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478938  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478939  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047893b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0047893e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047893f  ff3430                 -push dword ptr [eax + esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
    cpu.esp -= 4;
    // 00478942  ff15c4714800           -call dword ptr [0x4871c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747716) /* 0x4871c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478948  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047894a  7539                   -jne 0x478985
    if (!cpu.flags.zf)
    {
        goto L_0x00478985;
    }
    // 0047894c  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478952  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00478954  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478955  3bc6                   +cmp eax, esi
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
    // 00478957  7514                   -jne 0x47896d
    if (!cpu.flags.zf)
    {
        goto L_0x0047896d;
    }
    // 00478959  e8545b0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047895e  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 00478964  e8525b0000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00478969  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0047896b  eb10                   -jmp 0x47897d
    goto L_0x0047897d;
L_0x0047896d:
    // 0047896d  83f86d                 +cmp eax, 0x6d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478970  0f8424010000           -je 0x478a9a
    if (cpu.flags.zf)
    {
        goto L_0x00478a9a;
    }
    // 00478976  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478977  e8c35a0000             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 0047897c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047897d:
    // 0047897d  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00478980  e917010000             -jmp 0x478a9c
    goto L_0x00478a9c;
L_0x00478985:
    // 00478985  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478987  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047898a  0155f8                 -add dword ptr [ebp - 8], edx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047898d  8d4c3004               -lea ecx, [eax + esi + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00478991  8a443004               -mov al, byte ptr [eax + esi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00478995  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00478997  0f84f8000000           -je 0x478a95
    if (cpu.flags.zf)
    {
        goto L_0x00478a95;
    }
    // 0047899d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047899f  7409                   -je 0x4789aa
    if (cpu.flags.zf)
    {
        goto L_0x004789aa;
    }
    // 004789a1  803b0a                 +cmp byte ptr [ebx], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004789a4  7504                   -jne 0x4789aa
    if (!cpu.flags.zf)
    {
        goto L_0x004789aa;
    }
    // 004789a6  0c04                   +or al, 4
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004789a8  eb02                   -jmp 0x4789ac
    goto L_0x004789ac;
L_0x004789aa:
    // 004789aa  24fb                   -and al, 0xfb
    cpu.al &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x004789ac:
    // 004789ac  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004789ae  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004789b1  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004789b4  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004789b7  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004789b9  3bc1                   +cmp eax, ecx
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
    // 004789bb  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 004789be  0f83cb000000           -jae 0x478a8f
    if (!cpu.flags.cf)
    {
        goto L_0x00478a8f;
    }
L_0x004789c4:
    // 004789c4  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004789c7  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004789c9  3c1a                   +cmp al, 0x1a
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
    // 004789cb  0f84ae000000           -je 0x478a7f
    if (cpu.flags.zf)
    {
        goto L_0x00478a7f;
    }
    // 004789d1  3c0d                   +cmp al, 0xd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004789d3  740b                   -je 0x4789e0
    if (cpu.flags.zf)
    {
        goto L_0x004789e0;
    }
    // 004789d5  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004789d7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004789d8  ff4510                 +inc dword ptr [ebp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004789db  e991000000             -jmp 0x478a71
    goto L_0x00478a71;
L_0x004789e0:
    // 004789e0  49                     -dec ecx
    (cpu.ecx)--;
    // 004789e1  394d10                 +cmp dword ptr [ebp + 0x10], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004789e4  7318                   -jae 0x4789fe
    if (!cpu.flags.cf)
    {
        goto L_0x004789fe;
    }
    // 004789e6  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004789e9  40                     -inc eax
    (cpu.eax)++;
    // 004789ea  80380a                 +cmp byte ptr [eax], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004789ed  7506                   -jne 0x4789f5
    if (!cpu.flags.zf)
    {
        goto L_0x004789f5;
    }
    // 004789ef  83451002               +add dword ptr [ebp + 0x10], 2
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004789f3  eb5e                   -jmp 0x478a53
    goto L_0x00478a53;
L_0x004789f5:
    // 004789f5  c6030d                 -mov byte ptr [ebx], 0xd
    app->getMemory<x86::reg8>(cpu.ebx) = 13 /*0xd*/;
    // 004789f8  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004789f9  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004789fc  eb73                   -jmp 0x478a71
    goto L_0x00478a71;
L_0x004789fe:
    // 004789fe  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00478a01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478a03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478a04  ff4510                 -inc dword ptr [ebp + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))++;
    // 00478a07  8d45ff                 -lea eax, [ebp - 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00478a0a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478a0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478a0d  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478a0f  ff3430                 -push dword ptr [eax + esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1);
    cpu.esp -= 4;
    // 00478a12  ff15c4714800           -call dword ptr [0x4871c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747716) /* 0x4871c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478a18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478a1a  750a                   -jne 0x478a26
    if (!cpu.flags.zf)
    {
        goto L_0x00478a26;
    }
    // 00478a1c  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478a22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478a24  7547                   -jne 0x478a6d
    if (!cpu.flags.zf)
    {
        goto L_0x00478a6d;
    }
L_0x00478a26:
    // 00478a26  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00478a2a  7441                   -je 0x478a6d
    if (cpu.flags.zf)
    {
        goto L_0x00478a6d;
    }
    // 00478a2c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478a2e  f644300448             +test byte ptr [eax + esi + 4], 0x48
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) & 72 /*0x48*/));
    // 00478a33  7413                   -je 0x478a48
    if (cpu.flags.zf)
    {
        goto L_0x00478a48;
    }
    // 00478a35  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00478a38  3c0a                   +cmp al, 0xa
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
    // 00478a3a  7417                   -je 0x478a53
    if (cpu.flags.zf)
    {
        goto L_0x00478a53;
    }
    // 00478a3c  c6030d                 -mov byte ptr [ebx], 0xd
    app->getMemory<x86::reg8>(cpu.ebx) = 13 /*0xd*/;
    // 00478a3f  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00478a41  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00478a42  88443105               -mov byte ptr [ecx + esi + 5], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */ + cpu.esi * 1) = cpu.al;
    // 00478a46  eb29                   -jmp 0x478a71
    goto L_0x00478a71;
L_0x00478a48:
    // 00478a48  3b5d0c                 +cmp ebx, dword ptr [ebp + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478a4b  750b                   -jne 0x478a58
    if (!cpu.flags.zf)
    {
        goto L_0x00478a58;
    }
    // 00478a4d  807dff0a               +cmp byte ptr [ebp - 1], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478a51  7505                   -jne 0x478a58
    if (!cpu.flags.zf)
    {
        goto L_0x00478a58;
    }
L_0x00478a53:
    // 00478a53  c6030a                 -mov byte ptr [ebx], 0xa
    app->getMemory<x86::reg8>(cpu.ebx) = 10 /*0xa*/;
    // 00478a56  eb18                   -jmp 0x478a70
    goto L_0x00478a70;
L_0x00478a58:
    // 00478a58  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478a5a  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00478a5c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00478a5f  e8c55a0000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 00478a64  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478a67  807dff0a               +cmp byte ptr [ebp - 1], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478a6b  7404                   -je 0x478a71
    if (cpu.flags.zf)
    {
        goto L_0x00478a71;
    }
L_0x00478a6d:
    // 00478a6d  c6030d                 -mov byte ptr [ebx], 0xd
    app->getMemory<x86::reg8>(cpu.ebx) = 13 /*0xd*/;
L_0x00478a70:
    // 00478a70  43                     -inc ebx
    (cpu.ebx)++;
L_0x00478a71:
    // 00478a71  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00478a74  394d10                 +cmp dword ptr [ebp + 0x10], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478a77  0f8247ffffff           -jb 0x4789c4
    if (cpu.flags.cf)
    {
        goto L_0x004789c4;
    }
    // 00478a7d  eb10                   -jmp 0x478a8f
    goto L_0x00478a8f;
L_0x00478a7f:
    // 00478a7f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478a81  8d743004               -lea esi, [eax + esi + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00478a85  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00478a87  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00478a89  7504                   -jne 0x478a8f
    if (!cpu.flags.zf)
    {
        goto L_0x00478a8f;
    }
    // 00478a8b  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00478a8d  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x00478a8f:
    // 00478a8f  2b5d0c                 +sub ebx, dword ptr [ebp + 0xc]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478a92  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
L_0x00478a95:
    // 00478a95  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00478a98  eb02                   -jmp 0x478a9c
    goto L_0x00478a9c;
L_0x00478a9a:
    // 00478a9a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478a9c:
    // 00478a9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a9f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478aa0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478aa1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478aa1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478aa2  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478aa6  3b35e01f5200           +cmp esi, dword ptr [0x521fe0]
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
    // 00478aac  7365                   -jae 0x478b13
    if (!cpu.flags.cf)
    {
        goto L_0x00478b13;
    }
    // 00478aae  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00478ab0  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478ab2  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00478ab5  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478ab8  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 00478abf  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00478ac2  f644810401             +test byte ptr [ecx + eax*4 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) & 1 /*0x1*/));
    // 00478ac7  744a                   -je 0x478b13
    if (cpu.flags.zf)
    {
        goto L_0x00478b13;
    }
    // 00478ac9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478aca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478acb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478acc  e8af6a0000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 00478ad1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478ad3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478ad5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478ad6  e84e5a0000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 00478adb  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478add  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00478ae0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00478ae3  3bfb                   +cmp edi, ebx
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
    // 00478ae5  741f                   -je 0x478b06
    if (cpu.flags.zf)
    {
        goto L_0x00478b06;
    }
    // 00478ae7  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00478ae9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478aeb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478aec  e8385a0000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 00478af1  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478af3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478af6  3bfb                   +cmp edi, ebx
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
    // 00478af8  740c                   -je 0x478b06
    if (cpu.flags.zf)
    {
        goto L_0x00478b06;
    }
    // 00478afa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478afc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478afd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478afe  e8265a0000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 00478b03  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00478b06:
    // 00478b06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478b07  e8d36a0000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 00478b0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b0d  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478b0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478b13:
    // 00478b13  e89a590000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00478b18  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 00478b1e  e898590000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00478b23  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00478b26  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00478b29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478b2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478b2b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00478b2f  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00478b31  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00478b35  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00478b39  e804000000             -call 0x478b42
    cpu.esp -= 4;
    sub_478b42(app, cpu);
    // 00478b3e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00478b41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478b42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478b42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478b43  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00478b45  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00478b48  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478b4b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478b4c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478b4e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478b4f  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 00478b52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478b53  c745e40c000000         -mov dword ptr [ebp - 0x1c], 0xc
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 12 /*0xc*/;
    // 00478b5a  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00478b5d  7409                   -je 0x478b68
    if (cpu.flags.zf)
    {
        goto L_0x00478b68;
    }
    // 00478b5f  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00478b62  c645ff10               -mov byte ptr [ebp - 1], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = 16 /*0x10*/;
    // 00478b66  eb0b                   -jmp 0x478b73
    goto L_0x00478b73;
L_0x00478b68:
    // 00478b68  8065ff00               -and byte ptr [ebp - 1], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00478b6c  c745ec01000000         -mov dword ptr [ebp - 0x14], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 1 /*0x1*/;
L_0x00478b73:
    // 00478b73  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 00478b78  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 00478b7a  7511                   -jne 0x478b8d
    if (!cpu.flags.zf)
    {
        goto L_0x00478b8d;
    }
    // 00478b7c  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 00478b7f  7508                   -jne 0x478b89
    if (!cpu.flags.zf)
    {
        goto L_0x00478b89;
    }
    // 00478b81  3905e0eb5100           +cmp dword ptr [0x51ebe0], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368800) /* 0x51ebe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478b87  7404                   -je 0x478b8d
    if (cpu.flags.zf)
    {
        goto L_0x00478b8d;
    }
L_0x00478b89:
    // 00478b89  804dff80               -or byte ptr [ebp - 1], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00478b8d:
    // 00478b8d  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00478b8f  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478b91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b92  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 00478b94  2bc3                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478b96  741c                   -je 0x478bb4
    if (cpu.flags.zf)
    {
        goto L_0x00478bb4;
    }
    // 00478b98  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478b99  7410                   -je 0x478bab
    if (cpu.flags.zf)
    {
        goto L_0x00478bab;
    }
    // 00478b9b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478b9c  0f85a4000000           -jne 0x478c46
    if (!cpu.flags.zf)
    {
        goto L_0x00478c46;
    }
    // 00478ba2  c745f4000000c0         -mov dword ptr [ebp - 0xc], 0xc0000000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 3221225472 /*0xc0000000*/;
    // 00478ba9  eb10                   -jmp 0x478bbb
    goto L_0x00478bbb;
L_0x00478bab:
    // 00478bab  c745f400000040         -mov dword ptr [ebp - 0xc], 0x40000000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 1073741824 /*0x40000000*/;
    // 00478bb2  eb07                   -jmp 0x478bbb
    goto L_0x00478bbb;
L_0x00478bb4:
    // 00478bb4  c745f400000080         -mov dword ptr [ebp - 0xc], 0x80000000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 2147483648 /*0x80000000*/;
L_0x00478bbb:
    // 00478bbb  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00478bbe  83f810                 +cmp eax, 0x10
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
    // 00478bc1  7426                   -je 0x478be9
    if (cpu.flags.zf)
    {
        goto L_0x00478be9;
    }
    // 00478bc3  83f820                 +cmp eax, 0x20
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
    // 00478bc6  7418                   -je 0x478be0
    if (cpu.flags.zf)
    {
        goto L_0x00478be0;
    }
    // 00478bc8  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478bcb  740a                   -je 0x478bd7
    if (cpu.flags.zf)
    {
        goto L_0x00478bd7;
    }
    // 00478bcd  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478bd0  7574                   -jne 0x478c46
    if (!cpu.flags.zf)
    {
        goto L_0x00478c46;
    }
    // 00478bd2  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 00478bd5  eb15                   -jmp 0x478bec
    goto L_0x00478bec;
L_0x00478bd7:
    // 00478bd7  c745f002000000         -mov dword ptr [ebp - 0x10], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 2 /*0x2*/;
    // 00478bde  eb0c                   -jmp 0x478bec
    goto L_0x00478bec;
L_0x00478be0:
    // 00478be0  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 00478be7  eb03                   -jmp 0x478bec
    goto L_0x00478bec;
L_0x00478be9:
    // 00478be9  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
L_0x00478bec:
    // 00478bec  ba00070000             -mov edx, 0x700
    cpu.edx = 1792 /*0x700*/;
    // 00478bf1  b800040000             -mov eax, 0x400
    cpu.eax = 1024 /*0x400*/;
    // 00478bf6  23ca                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 00478bf8  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 00478bfd  3bc8                   +cmp ecx, eax
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
    // 00478bff  7f31                   -jg 0x478c32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00478c32;
    }
    // 00478c01  742a                   -je 0x478c2d
    if (cpu.flags.zf)
    {
        goto L_0x00478c2d;
    }
    // 00478c03  3bcb                   +cmp ecx, ebx
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
    // 00478c05  7426                   -je 0x478c2d
    if (cpu.flags.zf)
    {
        goto L_0x00478c2d;
    }
    // 00478c07  3bcf                   +cmp ecx, edi
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
    // 00478c09  7419                   -je 0x478c24
    if (cpu.flags.zf)
    {
        goto L_0x00478c24;
    }
    // 00478c0b  81f900020000           +cmp ecx, 0x200
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478c11  744d                   -je 0x478c60
    if (cpu.flags.zf)
    {
        goto L_0x00478c60;
    }
    // 00478c13  81f900030000           +cmp ecx, 0x300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478c19  752b                   -jne 0x478c46
    if (!cpu.flags.zf)
    {
        goto L_0x00478c46;
    }
    // 00478c1b  c745f802000000         -mov dword ptr [ebp - 8], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 2 /*0x2*/;
    // 00478c22  eb4c                   -jmp 0x478c70
    goto L_0x00478c70;
L_0x00478c24:
    // 00478c24  c745f804000000         -mov dword ptr [ebp - 8], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 4 /*0x4*/;
    // 00478c2b  eb43                   -jmp 0x478c70
    goto L_0x00478c70;
L_0x00478c2d:
    // 00478c2d  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 00478c30  eb3e                   -jmp 0x478c70
    goto L_0x00478c70;
L_0x00478c32:
    // 00478c32  81f900050000           +cmp ecx, 0x500
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1280 /*0x500*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478c38  742f                   -je 0x478c69
    if (cpu.flags.zf)
    {
        goto L_0x00478c69;
    }
    // 00478c3a  81f900060000           +cmp ecx, 0x600
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1536 /*0x600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478c40  741e                   -je 0x478c60
    if (cpu.flags.zf)
    {
        goto L_0x00478c60;
    }
    // 00478c42  3bca                   +cmp ecx, edx
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
    // 00478c44  7423                   -je 0x478c69
    if (cpu.flags.zf)
    {
        goto L_0x00478c69;
    }
L_0x00478c46:
    // 00478c46  e867580000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00478c4b  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 00478c51  e865580000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00478c56  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00478c58  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00478c5b  e9ac010000             -jmp 0x478e0c
    goto L_0x00478e0c;
L_0x00478c60:
    // 00478c60  c745f805000000         -mov dword ptr [ebp - 8], 5
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 5 /*0x5*/;
    // 00478c67  eb07                   -jmp 0x478c70
    goto L_0x00478c70;
L_0x00478c69:
    // 00478c69  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
L_0x00478c70:
    // 00478c70  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478c73  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 00478c78  85c7                   +test edi, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.eax));
    // 00478c7a  7413                   -je 0x478c8f
    if (cpu.flags.zf)
    {
        goto L_0x00478c8f;
    }
    // 00478c7c  8b0de8ea5100           -mov ecx, dword ptr [0x51eae8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5368552) /* 0x51eae8 */);
    // 00478c82  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00478c84  234d14                 -and ecx, dword ptr [ebp + 0x14]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
    // 00478c87  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 00478c8a  7503                   -jne 0x478c8f
    if (!cpu.flags.zf)
    {
        goto L_0x00478c8f;
    }
    // 00478c8c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478c8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478c8f:
    // 00478c8f  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00478c91  740a                   -je 0x478c9d
    if (cpu.flags.zf)
    {
        goto L_0x00478c9d;
    }
    // 00478c93  81ce00000004           -or esi, 0x4000000
    cpu.esi |= x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
    // 00478c99  804df601               -or byte ptr [ebp - 0xa], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-10) /* -0xa */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00478c9d:
    // 00478c9d  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00478ca0  7402                   -je 0x478ca4
    if (cpu.flags.zf)
    {
        goto L_0x00478ca4;
    }
    // 00478ca2  0bf7                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
L_0x00478ca4:
    // 00478ca4  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00478ca6  7408                   -je 0x478cb0
    if (cpu.flags.zf)
    {
        goto L_0x00478cb0;
    }
    // 00478ca8  81ce00000008           +or esi, 0x8000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(134217728 /*0x8000000*/))));
    // 00478cae  eb0a                   -jmp 0x478cba
    goto L_0x00478cba;
L_0x00478cb0:
    // 00478cb0  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00478cb2  7406                   -je 0x478cba
    if (cpu.flags.zf)
    {
        goto L_0x00478cba;
    }
    // 00478cb4  81ce00000010           -or esi, 0x10000000
    cpu.esi |= x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
L_0x00478cba:
    // 00478cba  e861660000             -call 0x47f320
    cpu.esp -= 4;
    sub_47f320(app, cpu);
    // 00478cbf  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478cc1  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00478cc4  3bdf                   +cmp ebx, edi
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
    // 00478cc6  751a                   -jne 0x478ce2
    if (!cpu.flags.zf)
    {
        goto L_0x00478ce2;
    }
    // 00478cc8  e8e5570000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00478ccd  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
    // 00478cd3  e8e3570000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00478cd8  832000                 +and dword ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 00478cdb  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00478cdd  e92a010000             -jmp 0x478e0c
    goto L_0x00478e0c;
L_0x00478ce2:
    // 00478ce2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478ce4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478ce5  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 00478ce8  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00478ceb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478cec  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 00478cef  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 00478cf2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00478cf5  ff15cc714800           -call dword ptr [0x4871cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747724) /* 0x4871cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478cfb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478cfd  3bf7                   +cmp esi, edi
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
    // 00478cff  7514                   -jne 0x478d15
    if (!cpu.flags.zf)
    {
        goto L_0x00478d15;
    }
L_0x00478d01:
    // 00478d01  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478d07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478d08  e832570000             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00478d0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d0e  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00478d10  e9ee000000             -jmp 0x478e03
    goto L_0x00478e03;
L_0x00478d15:
    // 00478d15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478d16  ff15c8714800           -call dword ptr [0x4871c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747720) /* 0x4871c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478d1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478d1e  7509                   -jne 0x478d29
    if (!cpu.flags.zf)
    {
        goto L_0x00478d29;
    }
    // 00478d20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478d21  ff15d4704800           -call dword ptr [0x4870d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747476) /* 0x4870d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478d27  ebd8                   -jmp 0x478d01
    goto L_0x00478d01;
L_0x00478d29:
    // 00478d29  83f802                 +cmp eax, 2
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
    // 00478d2c  7506                   -jne 0x478d34
    if (!cpu.flags.zf)
    {
        goto L_0x00478d34;
    }
    // 00478d2e  804dff40               +or byte ptr [ebp - 1], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00478d32  eb09                   -jmp 0x478d3d
    goto L_0x00478d3d;
L_0x00478d34:
    // 00478d34  83f803                 +cmp eax, 3
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
    // 00478d37  7504                   -jne 0x478d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00478d3d;
    }
    // 00478d39  804dff08               -or byte ptr [ebp - 1], 8
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00478d3d:
    // 00478d3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478d3e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478d3f  e8ff660000             -call 0x47f443
    cpu.esp -= 4;
    sub_47f443(app, cpu);
    // 00478d44  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478d46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d47  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00478d4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d4b  8a4dff                 -mov cl, byte ptr [ebp - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00478d4e  8d3c85e01e5200         -lea edi, [eax*4 + 0x521ee0]
    cpu.edi = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 00478d55  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478d57  80c901                 -or cl, 1
    cpu.cl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00478d5a  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478d5d  884d0b                 -mov byte ptr [ebp + 0xb], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) = cpu.cl;
    // 00478d60  8d34c0                 -lea esi, [eax + eax*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00478d63  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478d65  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00478d68  80650b48               +and byte ptr [ebp + 0xb], 0x48
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) &= x86::reg8(x86::sreg8(72 /*0x48*/))));
    // 00478d6c  884c3004               -mov byte ptr [eax + esi + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) = cpu.cl;
    // 00478d70  7578                   -jne 0x478dea
    if (!cpu.flags.zf)
    {
        goto L_0x00478dea;
    }
    // 00478d72  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 00478d75  7473                   -je 0x478dea
    if (cpu.flags.zf)
    {
        goto L_0x00478dea;
    }
    // 00478d77  f6450c02               +test byte ptr [ebp + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 00478d7b  746d                   -je 0x478dea
    if (cpu.flags.zf)
    {
        goto L_0x00478dea;
    }
    // 00478d7d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00478d7f  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00478d81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478d82  e8a2570000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 00478d87  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478d8a  83f8ff                 +cmp eax, -1
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
    // 00478d8d  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00478d90  7519                   -jne 0x478dab
    if (!cpu.flags.zf)
    {
        goto L_0x00478dab;
    }
    // 00478d92  e824570000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00478d97  813883000000           +cmp dword ptr [eax], 0x83
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478d9d  744b                   -je 0x478dea
    if (cpu.flags.zf)
    {
        goto L_0x00478dea;
    }
L_0x00478d9f:
    // 00478d9f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478da0  e8def9ffff             -call 0x478783
    cpu.esp -= 4;
    sub_478783(app, cpu);
    // 00478da5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478da6  83ceff                 +or esi, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00478da9  eb58                   -jmp 0x478e03
    goto L_0x00478e03;
L_0x00478dab:
    // 00478dab  80651300               -and byte ptr [ebp + 0x13], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(19) /* 0x13 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00478daf  8d4513                 -lea eax, [ebp + 0x13]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(19) /* 0x13 */);
    // 00478db2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478db4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478db5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478db6  e80dfbffff             -call 0x4788c8
    cpu.esp -= 4;
    sub_4788c8(app, cpu);
    // 00478dbb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478dbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478dc0  7516                   -jne 0x478dd8
    if (!cpu.flags.zf)
    {
        goto L_0x00478dd8;
    }
    // 00478dc2  807d131a               +cmp byte ptr [ebp + 0x13], 0x1a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(19) /* 0x13 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(26 /*0x1a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478dc6  7510                   -jne 0x478dd8
    if (!cpu.flags.zf)
    {
        goto L_0x00478dd8;
    }
    // 00478dc8  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 00478dcb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478dcc  e830680000             -call 0x47f601
    cpu.esp -= 4;
    sub_47f601(app, cpu);
    // 00478dd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478dd2  83f8ff                 +cmp eax, -1
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
    // 00478dd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478dd6  74c7                   -je 0x478d9f
    if (cpu.flags.zf)
    {
        goto L_0x00478d9f;
    }
L_0x00478dd8:
    // 00478dd8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478dda  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478ddc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478ddd  e847570000             -call 0x47e529
    cpu.esp -= 4;
    sub_47e529(app, cpu);
    // 00478de2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478de5  83f8ff                 +cmp eax, -1
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
    // 00478de8  74b5                   -je 0x478d9f
    if (cpu.flags.zf)
    {
        goto L_0x00478d9f;
    }
L_0x00478dea:
    // 00478dea  807d0b00               +cmp byte ptr [ebp + 0xb], 0
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
    // 00478dee  7511                   -jne 0x478e01
    if (!cpu.flags.zf)
    {
        goto L_0x00478e01;
    }
    // 00478df0  f6450c08               +test byte ptr [ebp + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 00478df4  740b                   -je 0x478e01
    if (cpu.flags.zf)
    {
        goto L_0x00478e01;
    }
    // 00478df6  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00478df8  804c300420             -or byte ptr [eax + esi + 4], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00478dfd  8d443004               -lea eax, [eax + esi + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
L_0x00478e01:
    // 00478e01  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x00478e03:
    // 00478e03  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478e04  e8d6670000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 00478e09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e0a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00478e0c:
    // 00478e0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e0f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e11(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e11  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478e15  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478e17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478e18  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00478e1c  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00478e20  e801690000             -call 0x47f726
    cpu.esp -= 4;
    sub_47f726(app, cpu);
    // 00478e25  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00478e28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478e29(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e29  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478e2a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00478e2c  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00478e2f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00478e32  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00478e36  3b0de01f5200           +cmp ecx, dword ptr [0x521fe0]
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
    // 00478e3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478e3d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478e3e  0f8366020000           -jae 0x4790aa
    if (!cpu.flags.cf)
    {
        goto L_0x004790aa;
    }
    // 00478e44  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478e46  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00478e49  8d1c85e01e5200         -lea ebx, [eax*4 + 0x521ee0]
    cpu.ebx = x86::reg32(x86::reg32(5381856) /* 0x521ee0 */ + cpu.eax * 4);
    // 00478e50  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478e52  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00478e55  8d3cc0                 -lea edi, [eax + eax*8]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00478e58  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00478e5a  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00478e5d  f644380401             +test byte ptr [eax + edi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1) & 1 /*0x1*/));
    // 00478e62  0f8442020000           -je 0x4790aa
    if (cpu.flags.zf)
    {
        goto L_0x004790aa;
    }
    // 00478e68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478e69  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478e6a  e811670000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 00478e6f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00478e71  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e72  ff3438                 -push dword ptr [eax + edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 1);
    cpu.esp -= 4;
    // 00478e75  ff15c8714800           -call dword ptr [0x4871c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747720) /* 0x4871c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478e7b  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00478e7e  83f801                 +cmp eax, 1
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
    // 00478e81  0f849b000000           -je 0x478f22
    if (cpu.flags.zf)
    {
        goto L_0x00478f22;
    }
    // 00478e87  83f802                 +cmp eax, 2
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
    // 00478e8a  742e                   -je 0x478eba
    if (cpu.flags.zf)
    {
        goto L_0x00478eba;
    }
    // 00478e8c  83f803                 +cmp eax, 3
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
    // 00478e8f  7434                   -je 0x478ec5
    if (cpu.flags.zf)
    {
        goto L_0x00478ec5;
    }
    // 00478e91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478e93  0f85b7000000           -jne 0x478f50
    if (!cpu.flags.zf)
    {
        goto L_0x00478f50;
    }
    // 00478e99  e814560000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00478e9e  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
L_0x00478ea4:
    // 00478ea4  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
L_0x00478ea8:
    // 00478ea8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00478eab  e82f670000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 00478eb0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00478eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478eb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478eb5  e9fe010000             -jmp 0x4790b8
    goto L_0x004790b8;
L_0x00478eba:
    // 00478eba  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478ebd  66c746060020           -mov word ptr [esi + 6], 0x2000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 8192 /*0x2000*/;
    // 00478ec3  eb09                   -jmp 0x478ece
    goto L_0x00478ece;
L_0x00478ec5:
    // 00478ec5  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478ec8  66c746060010           -mov word ptr [esi + 6], 0x1000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 4096 /*0x1000*/;
L_0x00478ece:
    // 00478ece  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00478ed1  66c746080100           -mov word ptr [esi + 8], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00478ed7  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00478ed9  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00478edc  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478ede  83f802                 +cmp eax, 2
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
    // 00478ee1  66894e04               -mov word ptr [esi + 4], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.cx;
    // 00478ee5  66894e0c               -mov word ptr [esi + 0xc], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.cx;
    // 00478ee9  66894e0a               -mov word ptr [esi + 0xa], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.cx;
    // 00478eed  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00478ef0  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00478ef3  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00478ef6  7505                   -jne 0x478efd
    if (!cpu.flags.zf)
    {
        goto L_0x00478efd;
    }
    // 00478ef8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00478efb  ebab                   -jmp 0x478ea8
    goto L_0x00478ea8;
L_0x00478efd:
    // 00478efd  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478f00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478f01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f02  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00478f04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478f05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478f06  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478f07  ff3438                 -push dword ptr [eax + edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 1);
    cpu.esp -= 4;
    // 00478f0a  ff1580714800           -call dword ptr [0x487180]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747648) /* 0x487180 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478f10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478f12  7408                   -je 0x478f1c
    if (cpu.flags.zf)
    {
        goto L_0x00478f1c;
    }
    // 00478f14  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478f17  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00478f1a  eb8c                   -jmp 0x478ea8
    goto L_0x00478ea8;
L_0x00478f1c:
    // 00478f1c  83661400               +and dword ptr [esi + 0x14], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 00478f20  eb86                   -jmp 0x478ea8
    goto L_0x00478ea8;
L_0x00478f22:
    // 00478f22  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00478f25  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478f27  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00478f2b  6689460c               -mov word ptr [esi + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 00478f2f  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00478f33  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00478f37  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00478f3a  66c746080100           -mov word ptr [esi + 8], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00478f40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f41  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00478f43  ff3438                 -push dword ptr [eax + edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 1);
    cpu.esp -= 4;
    // 00478f46  ff15a0714800           -call dword ptr [0x4871a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747680) /* 0x4871a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478f4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478f4e  7512                   -jne 0x478f62
    if (!cpu.flags.zf)
    {
        goto L_0x00478f62;
    }
L_0x00478f50:
    // 00478f50  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478f56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f57  e8e3540000             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00478f5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f5d  e942ffffff             -jmp 0x478ea4
    goto L_0x00478ea4;
L_0x00478f62:
    // 00478f62  f645b001               +test byte ptr [ebp - 0x50], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-80) /* -0x50 */) & 1 /*0x1*/));
    // 00478f66  7408                   -je 0x478f70
    if (cpu.flags.zf)
    {
        goto L_0x00478f70;
    }
    // 00478f68  66814e062401           +or word ptr [esi + 6], 0x124
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) |= x86::reg16(x86::sreg16(292 /*0x124*/))));
    // 00478f6e  eb06                   -jmp 0x478f76
    goto L_0x00478f76;
L_0x00478f70:
    // 00478f70  66814e06b601           -or word ptr [esi + 6], 0x1b6
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) |= x86::reg16(x86::sreg16(438 /*0x1b6*/));
L_0x00478f76:
    // 00478f76  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00478f79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f7a  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 00478f7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f7e  ff157c714800           -call dword ptr [0x48717c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747644) /* 0x48717c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478f84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478f86  0f8418ffffff           -je 0x478ea4
    if (cpu.flags.zf)
    {
        goto L_0x00478ea4;
    }
    // 00478f8c  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00478f8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f90  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00478f93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478f94  ff15d0714800           -call dword ptr [0x4871d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747728) /* 0x4871d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478f9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478f9c  0f8402ffffff           -je 0x478ea4
    if (cpu.flags.zf)
    {
        goto L_0x00478ea4;
    }
    // 00478fa2  0fb745f0               -movzx eax, word ptr [ebp - 0x10]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 00478fa6  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00478fa9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478faa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fab  0fb745ee               -movzx eax, word ptr [ebp - 0x12]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-18) /* -0x12 */));
    // 00478faf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fb0  0fb745ec               -movzx eax, word ptr [ebp - 0x14]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 00478fb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fb5  0fb745ea               -movzx eax, word ptr [ebp - 0x16]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */));
    // 00478fb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fba  0fb745e6               -movzx eax, word ptr [ebp - 0x1a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */));
    // 00478fbe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fbf  0fb745e4               -movzx eax, word ptr [ebp - 0x1c]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 00478fc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fc4  e8f7680000             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 00478fc9  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00478fcb  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00478fce  397dbc                 +cmp dword ptr [ebp - 0x44], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478fd1  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00478fd4  7505                   -jne 0x478fdb
    if (!cpu.flags.zf)
    {
        goto L_0x00478fdb;
    }
    // 00478fd6  397dc0                 +cmp dword ptr [ebp - 0x40], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478fd9  7453                   -je 0x47902e
    if (cpu.flags.zf)
    {
        goto L_0x0047902e;
    }
L_0x00478fdb:
    // 00478fdb  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00478fde  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fdf  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 00478fe2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478fe3  ff157c714800           -call dword ptr [0x48717c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747644) /* 0x48717c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478fe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478feb  0f84b1000000           -je 0x4790a2
    if (cpu.flags.zf)
    {
        goto L_0x004790a2;
    }
    // 00478ff1  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00478ff4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478ff5  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00478ff8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478ff9  ff15d0714800           -call dword ptr [0x4871d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747728) /* 0x4871d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00478fff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479001  0f849b000000           -je 0x4790a2
    if (cpu.flags.zf)
    {
        goto L_0x004790a2;
    }
    // 00479007  0fb745f0               -movzx eax, word ptr [ebp - 0x10]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 0047900b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047900c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047900d  0fb745ee               -movzx eax, word ptr [ebp - 0x12]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-18) /* -0x12 */));
    // 00479011  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479012  0fb745ec               -movzx eax, word ptr [ebp - 0x14]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 00479016  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479017  0fb745ea               -movzx eax, word ptr [ebp - 0x16]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */));
    // 0047901b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047901c  0fb745e6               -movzx eax, word ptr [ebp - 0x1a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */));
    // 00479020  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479021  0fb745e4               -movzx eax, word ptr [ebp - 0x1c]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 00479025  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479026  e895680000             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 0047902b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x0047902e:
    // 0047902e  397db4                 +cmp dword ptr [ebp - 0x4c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479031  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00479034  750a                   -jne 0x479040
    if (!cpu.flags.zf)
    {
        goto L_0x00479040;
    }
    // 00479036  397db8                 +cmp dword ptr [ebp - 0x48], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479039  7505                   -jne 0x479040
    if (!cpu.flags.zf)
    {
        goto L_0x00479040;
    }
    // 0047903b  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0047903e  eb4b                   -jmp 0x47908b
    goto L_0x0047908b;
L_0x00479040:
    // 00479040  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00479043  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479044  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00479047  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479048  ff157c714800           -call dword ptr [0x48717c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747644) /* 0x48717c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047904e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479050  7450                   -je 0x4790a2
    if (cpu.flags.zf)
    {
        goto L_0x004790a2;
    }
    // 00479052  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00479055  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479056  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00479059  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047905a  ff15d0714800           -call dword ptr [0x4871d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747728) /* 0x4871d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479060  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479062  743e                   -je 0x4790a2
    if (cpu.flags.zf)
    {
        goto L_0x004790a2;
    }
    // 00479064  0fb745f0               -movzx eax, word ptr [ebp - 0x10]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 00479068  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479069  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047906a  0fb745ee               -movzx eax, word ptr [ebp - 0x12]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-18) /* -0x12 */));
    // 0047906e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047906f  0fb745ec               -movzx eax, word ptr [ebp - 0x14]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 00479073  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479074  0fb745ea               -movzx eax, word ptr [ebp - 0x16]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */));
    // 00479078  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479079  0fb745e6               -movzx eax, word ptr [ebp - 0x1a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */));
    // 0047907d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047907e  0fb745e4               -movzx eax, word ptr [ebp - 0x1c]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 00479082  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479083  e838680000             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 00479088  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x0047908b:
    // 0047908b  804e0780               +or byte ptr [esi + 7], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 0047908f  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00479092  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00479095  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00479097  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047909a  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0047909d  e906feffff             -jmp 0x478ea8
    goto L_0x00478ea8;
L_0x004790a2:
    // 004790a2  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004790a5  e9fefdffff             -jmp 0x478ea8
    goto L_0x00478ea8;
L_0x004790aa:
    // 004790aa  e803540000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 004790af  c70009000000           -mov dword ptr [eax], 9
    app->getMemory<x86::reg32>(cpu.eax) = 9 /*0x9*/;
    // 004790b5  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x004790b8:
    // 004790b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790ba  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4790bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004790bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004790bd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004790bf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004790c2  8365f400               -and dword ptr [ebp - 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004790c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004790c7  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004790ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004790cb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004790cd  81e380000000           +and ebx, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(128 /*0x80*/))));
    // 004790d3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790d4  c745f00c000000         -mov dword ptr [ebp - 0x10], 0xc
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 12 /*0xc*/;
    // 004790db  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004790de  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004790e1  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004790e4  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004790e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004790e8  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004790eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004790ec  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004790ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004790f0  ff1514714800           -call dword ptr [0x487114]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747540) /* 0x487114 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004790f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004790f8  7512                   -jne 0x47910c
    if (!cpu.flags.zf)
    {
        goto L_0x0047910c;
    }
    // 004790fa  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479100  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479101  e839530000             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00479106  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479107  e967010000             -jmp 0x479273
    goto L_0x00479273;
L_0x0047910c:
    // 0047910c  e80f620000             -call 0x47f320
    cpu.esp -= 4;
    sub_47f320(app, cpu);
    // 00479111  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00479114  83f8ff                 +cmp eax, -1
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
    // 00479117  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00479119  0f8427010000           -je 0x479246
    if (cpu.flags.zf)
    {
        goto L_0x00479246;
    }
    // 0047911f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479120  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 00479122  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479124  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479125  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00479128  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 0047912a  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 00479131  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00479134  c644810489             -mov byte ptr [ecx + eax*4 + 4], 0x89
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 137 /*0x89*/;
    // 00479139  e8e2610000             -call 0x47f320
    cpu.esp -= 4;
    sub_47f320(app, cpu);
    // 0047913e  83f8ff                 +cmp eax, -1
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
    // 00479141  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00479144  0f84ce000000           -je 0x479218
    if (cpu.flags.zf)
    {
        goto L_0x00479218;
    }
    // 0047914a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047914c  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 0047914e  c1f905                 +sar ecx, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00479151  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00479154  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047915b  c644810489             -mov byte ptr [ecx + eax*4 + 4], 0x89
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 137 /*0x89*/;
    // 00479160  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 00479165  854510                 -test dword ptr [ebp + 0x10], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) & cpu.eax));
    // 00479168  750e                   -jne 0x479178
    if (!cpu.flags.zf)
    {
        goto L_0x00479178;
    }
    // 0047916a  f6451140               +test byte ptr [ebp + 0x11], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(17) /* 0x11 */) & 64 /*0x40*/));
    // 0047916e  7541                   -jne 0x4791b1
    if (!cpu.flags.zf)
    {
        goto L_0x004791b1;
    }
    // 00479170  3905e0eb5100           +cmp dword ptr [0x51ebe0], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368800) /* 0x51ebe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479176  7539                   -jne 0x4791b1
    if (!cpu.flags.zf)
    {
        goto L_0x004791b1;
    }
L_0x00479178:
    // 00479178  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047917a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047917c  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 0047917e  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00479181  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00479184  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047918b  806481047f             -and byte ptr [ecx + eax*4 + 4], 0x7f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00479190  8d448104               -lea eax, [ecx + eax*4 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 00479194  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00479197  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479199  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 0047919b  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0047919e  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004791a1  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 004791a8  806481047f             -and byte ptr [ecx + eax*4 + 4], 0x7f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004791ad  8d448104               -lea eax, [ecx + eax*4 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
L_0x004791b1:
    // 004791b1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004791b3  7439                   -je 0x4791ee
    if (cpu.flags.zf)
    {
        goto L_0x004791ee;
    }
    // 004791b5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004791b7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004791b9  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004791bb  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004791be  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004791c1  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 004791c8  804c810410             -or byte ptr [ecx + eax*4 + 4], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004791cd  8d448104               -lea eax, [ecx + eax*4 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004791d1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004791d4  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004791d6  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004791d8  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004791db  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 004791de  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 004791e5  804c810410             -or byte ptr [ecx + eax*4 + 4], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004791ea  8d448104               -lea eax, [ecx + eax*4 + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
L_0x004791ee:
    // 004791ee  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004791f1  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 004791f3  e84b620000             -call 0x47f443
    cpu.esp -= 4;
    sub_47f443(app, cpu);
    // 004791f8  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 004791fb  ff7604                 -push dword ptr [esi + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004791fe  e840620000             -call 0x47f443
    cpu.esp -= 4;
    sub_47f443(app, cpu);
    // 00479203  e8aa520000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479208  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0047920b  ff7604                 -push dword ptr [esi + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0047920e  e8cc630000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 00479213  83c414                 +add esp, 0x14
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
    // 00479216  eb23                   -jmp 0x47923b
    goto L_0x0047923b;
L_0x00479218:
    // 00479218  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047921a  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047921c  23c7                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 0047921e  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00479221  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00479224  8b0c8de01e5200         -mov ecx, dword ptr [ecx*4 + 0x521ee0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.ecx * 4);
    // 0047922b  8064810400             +and byte ptr [ecx + eax*4 + 4], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00479230  e87d520000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479235  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
L_0x0047923b:
    // 0047923b  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0047923d  e89d630000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 00479242  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479243  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479244  eb0b                   -jmp 0x479251
    goto L_0x00479251;
L_0x00479246:
    // 00479246  e867520000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047924b  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
L_0x00479251:
    // 00479251  e85c520000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479256  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479259  741d                   -je 0x479278
    if (cpu.flags.zf)
    {
        goto L_0x00479278;
    }
    // 0047925b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0047925e  8b35d4704800           -mov esi, dword ptr [0x4870d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747476) /* 0x4870d4 */);
    // 00479264  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479266  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00479269  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047926b  e84b520000             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00479270  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00479273:
    // 00479273  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00479276  eb02                   -jmp 0x47927a
    goto L_0x0047927a;
L_0x00479278:
    // 00479278  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047927a:
    // 0047927a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047927b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047927c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047927d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47927e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047927e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047927f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00479281  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479283  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 00479288  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479289  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047928a  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479290  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 00479296  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479298  391de41f5200           +cmp dword ptr [0x521fe4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047929e  740e                   -je 0x4792ae
    if (cpu.flags.zf)
    {
        goto L_0x004792ae;
    }
    // 004792a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004792a1  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004792a3  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004792a5  e81f380000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004792aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792ab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004792ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004792ae:
    // 004792ae  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004792b1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004792b4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004792b7  e81f000000             -call 0x4792db
    cpu.esp -= 4;
    sub_4792db(app, cpu);
    // 004792bc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004792bf  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004792c2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004792c4  740a                   -je 0x4792d0
    if (cpu.flags.zf)
    {
        goto L_0x004792d0;
    }
    // 004792c6  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004792c8  e85d380000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 004792cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792ce  eb03                   -jmp 0x4792d3
    goto L_0x004792d3;
L_0x004792d0:
    // 004792d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004792d1  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004792d3:
    // 004792d3  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004792d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4792db(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004792db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004792dc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004792de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004792df  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004792e0  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004792e3  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004792e5  3bf3                   +cmp esi, ebx
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
    // 004792e7  7415                   -je 0x4792fe
    if (cpu.flags.zf)
    {
        goto L_0x004792fe;
    }
    // 004792e9  395d10                 +cmp dword ptr [ebp + 0x10], ebx
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
    // 004792ec  7410                   -je 0x4792fe
    if (cpu.flags.zf)
    {
        goto L_0x004792fe;
    }
    // 004792ee  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004792f0  3ac3                   +cmp al, bl
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
    // 004792f2  7510                   -jne 0x479304
    if (!cpu.flags.zf)
    {
        goto L_0x00479304;
    }
    // 004792f4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004792f7  3bc3                   +cmp eax, ebx
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
    // 004792f9  7403                   -je 0x4792fe
    if (cpu.flags.zf)
    {
        goto L_0x004792fe;
    }
    // 004792fb  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
L_0x004792fe:
    // 004792fe  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479300:
    // 00479300  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479301  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479302  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479304:
    // 00479304  391dc4eb5100           +cmp dword ptr [0x51ebc4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047930a  7513                   -jne 0x47931f
    if (!cpu.flags.zf)
    {
        goto L_0x0047931f;
    }
    // 0047930c  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047930f  3bcb                   +cmp ecx, ebx
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
    // 00479311  7407                   -je 0x47931a
    if (cpu.flags.zf)
    {
        goto L_0x0047931a;
    }
    // 00479313  660fb6c0               -movzx ax, al
    cpu.ax = x86::reg16(cpu.al);
    // 00479317  668901                 -mov word ptr [ecx], ax
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.ax;
L_0x0047931a:
    // 0047931a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047931c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047931d  ebe1                   -jmp 0x479300
    goto L_0x00479300;
L_0x0047931f:
    // 0047931f  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00479325  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00479328  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0047932d  744e                   -je 0x47937d
    if (cpu.flags.zf)
    {
        goto L_0x0047937d;
    }
    // 0047932f  a118644a00             -mov eax, dword ptr [0x4a6418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
    // 00479334  83f801                 +cmp eax, 1
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
    // 00479337  7e2a                   -jle 0x479363
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00479363;
    }
    // 00479339  394510                 +cmp dword ptr [ebp + 0x10], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047933c  7c2f                   -jl 0x47936d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047936d;
    }
    // 0047933e  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479340  395d08                 +cmp dword ptr [ebp + 8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479343  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 00479346  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479347  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047934a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047934b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047934c  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047934e  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00479354  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047935a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047935c  a118644a00             -mov eax, dword ptr [0x4a6418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
    // 00479361  759d                   -jne 0x479300
    if (!cpu.flags.zf)
    {
        goto L_0x00479300;
    }
L_0x00479363:
    // 00479363  394510                 +cmp dword ptr [ebp + 0x10], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479366  7205                   -jb 0x47936d
    if (cpu.flags.cf)
    {
        goto L_0x0047936d;
    }
    // 00479368  385e01                 +cmp byte ptr [esi + 1], bl
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
    // 0047936b  7593                   -jne 0x479300
    if (!cpu.flags.zf)
    {
        goto L_0x00479300;
    }
L_0x0047936d:
    // 0047936d  e840510000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479372  c7002a000000           -mov dword ptr [eax], 0x2a
    app->getMemory<x86::reg32>(cpu.eax) = 42 /*0x2a*/;
    // 00479378  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0047937b  eb83                   -jmp 0x479300
    goto L_0x00479300;
L_0x0047937d:
    // 0047937d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047937f  395d08                 +cmp dword ptr [ebp + 8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479382  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00479385  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479386  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00479389  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047938b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047938c  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047938e  ff35d4eb5100           -push dword ptr [0x51ebd4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    cpu.esp -= 4;
    // 00479394  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047939a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047939c  0f8578ffffff           -jne 0x47931a
    if (!cpu.flags.zf)
    {
        goto L_0x0047931a;
    }
    // 004793a2  ebc9                   -jmp 0x47936d
    goto L_0x0047936d;
}

/* align: skip  */
void Application::sub_4793a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004793a5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004793a7  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004793aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004793ab  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x004793ae:
    // 004793ae  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 004793b5  7e0f                   -jle 0x4793c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004793c6;
    }
    // 004793b7  0fb606                 -movzx eax, byte ptr [esi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004793ba  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004793bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004793bd  e8c73e0000             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 004793c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793c4  eb0f                   -jmp 0x4793d5
    goto L_0x004793d5;
L_0x004793c6:
    // 004793c6  0fb606                 -movzx eax, byte ptr [esi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004793c9  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 004793cf  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 004793d2  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004793d5:
    // 004793d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004793d7  7403                   -je 0x4793dc
    if (cpu.flags.zf)
    {
        goto L_0x004793dc;
    }
    // 004793d9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004793da  ebd2                   -jmp 0x4793ae
    goto L_0x004793ae;
L_0x004793dc:
    // 004793dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004793de  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004793e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004793e1  e8fa490000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 004793e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004793e8  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004793eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004793ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004793ed  e890650000             -call 0x47f982
    cpu.esp -= 4;
    sub_47f982(app, cpu);
    // 004793f2  dd4010                 -fld qword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004793f5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004793f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793f9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4793fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004793fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004793fd  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004793ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479400  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479401  e87a610000             -call 0x47f580
    cpu.esp -= 4;
    sub_47f580(app, cpu);
    // 00479406  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047940a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047940b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047940d  7422                   -je 0x479431
    if (cpu.flags.zf)
    {
        goto L_0x00479431;
    }
    // 0047940f  803e00                 +cmp byte ptr [esi], 0
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
    // 00479412  741d                   -je 0x479431
    if (cpu.flags.zf)
    {
        goto L_0x00479431;
    }
    // 00479414  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479415  e8c6490000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 0047941a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047941b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047941c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047941d  e862050000             -call 0x479984
    cpu.esp -= 4;
    sub_479984(app, cpu);
    // 00479422  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479423  68d07c4800             -push 0x487cd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750544 /*0x487cd0*/;
    cpu.esp -= 4;
    // 00479428  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479429  e856050000             -call 0x479984
    cpu.esp -= 4;
    sub_479984(app, cpu);
    // 0047942e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00479431:
    // 00479431  e87c500000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479436  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479439  7c18                   -jl 0x479453
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479453;
    }
    // 0047943b  e872500000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479440  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00479442  3b0580664a00           +cmp eax, dword ptr [0x4a6680]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4875904) /* 0x4a6680 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479448  7d09                   -jge 0x479453
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479453;
    }
    // 0047944a  e863500000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047944f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00479451  eb05                   -jmp 0x479458
    goto L_0x00479458;
L_0x00479453:
    // 00479453  a180664a00             -mov eax, dword ptr [0x4a6680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4875904) /* 0x4a6680 */);
L_0x00479458:
    // 00479458  8b3485d0654a00         -mov esi, dword ptr [eax*4 + 0x4a65d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4875728) /* 0x4a65d0 */ + cpu.eax * 4);
    // 0047945f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479460  e87b490000             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00479465  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479466  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479467  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479468  e817050000             -call 0x479984
    cpu.esp -= 4;
    sub_479984(app, cpu);
    // 0047946d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047946f  6800284900             -push 0x492800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4794368 /*0x492800*/;
    cpu.esp -= 4;
    // 00479474  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479475  e80a050000             -call 0x479984
    cpu.esp -= 4;
    sub_479984(app, cpu);
    // 0047947a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047947b  e85f610000             -call 0x47f5df
    cpu.esp -= 4;
    sub_47f5df(app, cpu);
    // 00479480  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00479483  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479484  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479485  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479486(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479486  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479487  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00479489  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047948a  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047948d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047948e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047948f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479491  7507                   -jne 0x47949a
    if (!cpu.flags.zf)
    {
        goto L_0x0047949a;
    }
    // 00479493  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479495  e9bb000000             -jmp 0x479555
    goto L_0x00479555;
L_0x0047949a:
    // 0047949a  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 0047949f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004794a0  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004794a6  833de41f520000         +cmp dword ptr [0x521fe4], 0
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
    // 004794ad  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 004794b3  7414                   -je 0x4794c9
    if (cpu.flags.zf)
    {
        goto L_0x004794c9;
    }
    // 004794b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004794b6  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004794b8  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004794ba  e80a360000             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004794bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004794c0  c7451001000000         -mov dword ptr [ebp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004794c7  eb04                   -jmp 0x4794cd
    goto L_0x004794cd;
L_0x004794c9:
    // 004794c9  83651000               -and dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x004794cd:
    // 004794cd  a1c0eb5100             -mov eax, dword ptr [0x51ebc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368768) /* 0x51ebc0 */);
    // 004794d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004794d4  7523                   -jne 0x4794f9
    if (!cpu.flags.zf)
    {
        goto L_0x004794f9;
    }
    // 004794d6  394510                 +cmp dword ptr [ebp + 0x10], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004794d9  740a                   -je 0x4794e5
    if (cpu.flags.zf)
    {
        goto L_0x004794e5;
    }
    // 004794db  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004794dd  e848360000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 004794e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004794e3  eb03                   -jmp 0x4794e8
    goto L_0x004794e8;
L_0x004794e5:
    // 004794e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004794e6  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004794e8:
    // 004794e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004794e9  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004794ec  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004794ef  e83c0a0000             -call 0x479f30
    cpu.esp -= 4;
    sub_479f30(app, cpu);
    // 004794f4  83c40c                 +add esp, 0xc
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
    // 004794f7  eb5c                   -jmp 0x479555
    goto L_0x00479555;
L_0x004794f9:
    // 004794f9  ff35d8eb5100           -push dword ptr [0x51ebd8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368792) /* 0x51ebd8 */);
    cpu.esp -= 4;
    // 004794ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479500  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00479503  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479504  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00479507  6801100000             -push 0x1001
    app->getMemory<x86::reg32>(cpu.esp-4) = 4097 /*0x1001*/;
    cpu.esp -= 4;
    // 0047950c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047950d  e8ef640000             -call 0x47fa01
    cpu.esp -= 4;
    sub_47fa01(app, cpu);
    // 00479512  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479514  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479517  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479519  7524                   -jne 0x47953f
    if (!cpu.flags.zf)
    {
        goto L_0x0047953f;
    }
    // 0047951b  394510                 +cmp dword ptr [ebp + 0x10], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047951e  740a                   -je 0x47952a
    if (cpu.flags.zf)
    {
        goto L_0x0047952a;
    }
    // 00479520  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00479522  e803360000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00479527  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479528  eb03                   -jmp 0x47952d
    goto L_0x0047952d;
L_0x0047952a:
    // 0047952a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047952b  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0047952d:
    // 0047952d  e8804f0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479532  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 00479538  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 0047953d  eb16                   -jmp 0x479555
    goto L_0x00479555;
L_0x0047953f:
    // 0047953f  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 00479543  740a                   -je 0x47954f
    if (cpu.flags.zf)
    {
        goto L_0x0047954f;
    }
    // 00479545  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00479547  e8de350000             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0047954c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047954d  eb03                   -jmp 0x479552
    goto L_0x00479552;
L_0x0047954f:
    // 0047954f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479550  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00479552:
    // 00479552  8d43fe                 -lea eax, [ebx - 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-2) /* -0x2 */);
L_0x00479555:
    // 00479555  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479556  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479557  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479558  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479559  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47955a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047955a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047955b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047955c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047955d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047955e  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x00479562:
    // 00479562  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 00479569  7e0f                   -jle 0x47957a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047957a;
    }
    // 0047956b  0fb607                 -movzx eax, byte ptr [edi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0047956e  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00479570  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479571  e8133d0000             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00479576  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479577  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479578  eb0f                   -jmp 0x479589
    goto L_0x00479589;
L_0x0047957a:
    // 0047957a  0fb607                 -movzx eax, byte ptr [edi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0047957d  8b0d0c624a00           -mov ecx, dword ptr [0x4a620c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00479583  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 00479586  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00479589:
    // 00479589  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047958b  7403                   -je 0x479590
    if (cpu.flags.zf)
    {
        goto L_0x00479590;
    }
    // 0047958d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047958e  ebd2                   -jmp 0x479562
    goto L_0x00479562;
L_0x00479590:
    // 00479590  0fb637                 -movzx esi, byte ptr [edi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 00479593  47                     -inc edi
    (cpu.edi)++;
    // 00479594  83fe2d                 +cmp esi, 0x2d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479597  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00479599  7405                   -je 0x4795a0
    if (cpu.flags.zf)
    {
        goto L_0x004795a0;
    }
    // 0047959b  83fe2b                 +cmp esi, 0x2b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047959e  7504                   -jne 0x4795a4
    if (!cpu.flags.zf)
    {
        goto L_0x004795a4;
    }
L_0x004795a0:
    // 004795a0  0fb637                 -movzx esi, byte ptr [edi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004795a3  47                     -inc edi
    (cpu.edi)++;
L_0x004795a4:
    // 004795a4  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004795a6:
    // 004795a6  833d18644a0001         +cmp dword ptr [0x4a6418], 1
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
    // 004795ad  7e0c                   -jle 0x4795bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004795bb;
    }
    // 004795af  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004795b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004795b2  e8d23c0000             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 004795b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004795b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004795b9  eb0b                   -jmp 0x4795c6
    goto L_0x004795c6;
L_0x004795bb:
    // 004795bb  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 004795c0  8a0470                 -mov al, byte ptr [eax + esi*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.esi * 2);
    // 004795c3  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004795c6:
    // 004795c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004795c8  740d                   -je 0x4795d7
    if (cpu.flags.zf)
    {
        goto L_0x004795d7;
    }
    // 004795ca  8d049b                 -lea eax, [ebx + ebx*4]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 4);
    // 004795cd  8d5c46d0               -lea ebx, [esi + eax*2 - 0x30]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 004795d1  0fb637                 -movzx esi, byte ptr [edi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004795d4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004795d5  ebcf                   -jmp 0x4795a6
    goto L_0x004795a6;
L_0x004795d7:
    // 004795d7  83fd2d                 +cmp ebp, 0x2d
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004795da  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004795dc  7502                   -jne 0x4795e0
    if (!cpu.flags.zf)
    {
        goto L_0x004795e0;
    }
    // 004795de  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004795e0:
    // 004795e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004795e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004795e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004795e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004795e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4795e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004795e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004795e6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004795e8  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004795ee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004795ef  8d85c0feffff           -lea eax, [ebp - 0x140]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-320) /* -0x140 */);
    // 004795f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004795f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004795f7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004795fa  ff1578714800           -call dword ptr [0x487178]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747640) /* 0x487178 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479600  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00479602  83ffff                 +cmp edi, -1
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
    // 00479605  7542                   -jne 0x479649
    if (!cpu.flags.zf)
    {
        goto L_0x00479649;
    }
    // 00479607  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0047960d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047960f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479610  3bc6                   +cmp eax, esi
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
    // 00479612  720f                   -jb 0x479623
    if (cpu.flags.cf)
    {
        goto L_0x00479623;
    }
    // 00479614  83f803                 +cmp eax, 3
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
    // 00479617  7627                   -jbe 0x479640
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00479640;
    }
    // 00479619  83f808                 +cmp eax, 8
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
    // 0047961c  7415                   -je 0x479633
    if (cpu.flags.zf)
    {
        goto L_0x00479633;
    }
    // 0047961e  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479621  741d                   -je 0x479640
    if (cpu.flags.zf)
    {
        goto L_0x00479640;
    }
L_0x00479623:
    // 00479623  e88a4e0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479628  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
L_0x0047962e:
    // 0047962e  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00479631  eb7b                   -jmp 0x4796ae
    goto L_0x004796ae;
L_0x00479633:
    // 00479633  e87a4e0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479638  c7000c000000           -mov dword ptr [eax], 0xc
    app->getMemory<x86::reg32>(cpu.eax) = 12 /*0xc*/;
    // 0047963e  ebee                   -jmp 0x47962e
    goto L_0x0047962e;
L_0x00479640:
    // 00479640  e86d4e0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479645  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00479647  ebe5                   -jmp 0x47962e
    goto L_0x0047962e;
L_0x00479649:
    // 00479649  8b85c0feffff           -mov eax, dword ptr [ebp - 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-320) /* -0x140 */);
    // 0047964f  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00479652  2d80000000             -sub eax, 0x80
    (cpu.eax) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00479657  f7d8                   +neg eax
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
    // 00479659  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047965b  2385c0feffff           -and eax, dword ptr [ebp - 0x140]
    cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-320) /* -0x140 */)));
    // 00479661  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00479663  8d85c4feffff           -lea eax, [ebp - 0x13c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-316) /* -0x13c */);
    // 00479669  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047966a  e82b010000             -call 0x47979a
    cpu.esp -= 4;
    ___timet_from_ft(app, cpu);
    // 0047966f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00479672  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00479678  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479679  e81c010000             -call 0x47979a
    cpu.esp -= 4;
    ___timet_from_ft(app, cpu);
    // 0047967e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479681  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 00479687  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479688  e80d010000             -call 0x47979a
    cpu.esp -= 4;
    ___timet_from_ft(app, cpu);
    // 0047968d  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00479690  8b85e0feffff           -mov eax, dword ptr [ebp - 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-288) /* -0x120 */);
    // 00479696  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00479699  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0047969f  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004796a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004796a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004796a4  e8875b0000             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 004796a9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004796ac  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004796ae:
    // 004796ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796b0  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4796b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004796b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004796b3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004796b5  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004796bb  8d85c0feffff           -lea eax, [ebp - 0x140]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-320) /* -0x140 */);
    // 004796c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004796c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004796c3  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004796c6  ff1574714800           -call dword ptr [0x487174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747636) /* 0x487174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004796cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004796ce  7542                   -jne 0x479712
    if (!cpu.flags.zf)
    {
        goto L_0x00479712;
    }
    // 004796d0  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004796d6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004796d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796d9  3bc6                   +cmp eax, esi
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
    // 004796db  720f                   -jb 0x4796ec
    if (cpu.flags.cf)
    {
        goto L_0x004796ec;
    }
    // 004796dd  83f803                 +cmp eax, 3
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
    // 004796e0  7627                   -jbe 0x479709
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00479709;
    }
    // 004796e2  83f808                 +cmp eax, 8
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
    // 004796e5  7415                   -je 0x4796fc
    if (cpu.flags.zf)
    {
        goto L_0x004796fc;
    }
    // 004796e7  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004796ea  741d                   -je 0x479709
    if (cpu.flags.zf)
    {
        goto L_0x00479709;
    }
L_0x004796ec:
    // 004796ec  e8c14d0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 004796f1  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
L_0x004796f7:
    // 004796f7  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004796fa  eb7b                   -jmp 0x479777
    goto L_0x00479777;
L_0x004796fc:
    // 004796fc  e8b14d0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00479701  c7000c000000           -mov dword ptr [eax], 0xc
    app->getMemory<x86::reg32>(cpu.eax) = 12 /*0xc*/;
    // 00479707  ebee                   -jmp 0x4796f7
    goto L_0x004796f7;
L_0x00479709:
    // 00479709  e8a44d0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047970e  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00479710  ebe5                   -jmp 0x4796f7
    goto L_0x004796f7;
L_0x00479712:
    // 00479712  8b85c0feffff           -mov eax, dword ptr [ebp - 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-320) /* -0x140 */);
    // 00479718  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047971b  2d80000000             -sub eax, 0x80
    (cpu.eax) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00479720  f7d8                   +neg eax
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
    // 00479722  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00479724  2385c0feffff           -and eax, dword ptr [ebp - 0x140]
    cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-320) /* -0x140 */)));
    // 0047972a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047972c  8d85c4feffff           -lea eax, [ebp - 0x13c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-316) /* -0x13c */);
    // 00479732  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479733  e862000000             -call 0x47979a
    cpu.esp -= 4;
    ___timet_from_ft(app, cpu);
    // 00479738  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047973b  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00479741  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479742  e853000000             -call 0x47979a
    cpu.esp -= 4;
    ___timet_from_ft(app, cpu);
    // 00479747  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047974a  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 00479750  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479751  e844000000             -call 0x47979a
    cpu.esp -= 4;
    ___timet_from_ft(app, cpu);
    // 00479756  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00479759  8b85e0feffff           -mov eax, dword ptr [ebp - 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-288) /* -0x120 */);
    // 0047975f  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00479762  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00479768  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047976b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047976c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047976d  e8be5a0000             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00479772  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00479775  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479777:
    // 00479777  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479778  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479779  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47977a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047977a  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0047977e  ff1570714800           -call dword ptr [0x487170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747632) /* 0x487170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00479784  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479786  750f                   -jne 0x479797
    if (!cpu.flags.zf)
    {
        goto L_0x00479797;
    }
    // 00479788  e8254d0000             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 0047978d  c70016000000           -mov dword ptr [eax], 0x16
    app->getMemory<x86::reg32>(cpu.eax) = 22 /*0x16*/;
    // 00479793  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00479796  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479797:
    // 00479797  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479799  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::___timet_from_ft(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047979a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047979b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047979d  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004797a0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004797a3  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004797a6  7506                   -jne 0x4797ae
    if (!cpu.flags.zf)
    {
        goto L_0x004797ae;
    }
    // 004797a8  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004797ac  744b                   -je 0x4797f9
    if (cpu.flags.zf)
    {
        goto L_0x004797f9;
    }
L_0x004797ae:
    // 004797ae  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004797b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004797b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797b3  ff157c714800           -call dword ptr [0x48717c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747644) /* 0x48717c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004797b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004797bb  743c                   -je 0x4797f9
    if (cpu.flags.zf)
    {
        goto L_0x004797f9;
    }
    // 004797bd  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004797c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797c1  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004797c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797c5  ff15d0714800           -call dword ptr [0x4871d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747728) /* 0x4871d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004797cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004797cd  742a                   -je 0x4797f9
    if (cpu.flags.zf)
    {
        goto L_0x004797f9;
    }
    // 004797cf  0fb745f4               -movzx eax, word ptr [ebp - 0xc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */));
    // 004797d3  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004797d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797d6  0fb745f2               -movzx eax, word ptr [ebp - 0xe]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-14) /* -0xe */));
    // 004797da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797db  0fb745f0               -movzx eax, word ptr [ebp - 0x10]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 004797df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797e0  0fb745ee               -movzx eax, word ptr [ebp - 0x12]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-18) /* -0x12 */));
    // 004797e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797e5  0fb745ea               -movzx eax, word ptr [ebp - 0x16]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */));
    // 004797e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797ea  0fb745e8               -movzx eax, word ptr [ebp - 0x18]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    // 004797ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004797ef  e8cc600000             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 004797f4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004797f7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004797f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004797f9:
    // 004797f9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004797fc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004797fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4797fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004797fe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004797ff  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00479801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479802  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479803  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479804  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479805  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479806  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479808  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047980a  e8216d0000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 0047980f  beffff0000             -mov esi, 0xffff
    cpu.esi = 65535 /*0xffff*/;
    // 00479814  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479816  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479817  ff35903f4a00           -push dword ptr [0x4a3f90]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4865936) /* 0x4a3f90 */);
    cpu.esp -= 4;
    // 0047981d  e80e6d0000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 00479822  8b450e                 -mov eax, dword ptr [ebp + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 00479825  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479828  6625f07f               -and ax, 0x7ff0
    cpu.ax &= x86::reg16(x86::sreg16(32752 /*0x7ff0*/));
    // 0047982c  663df07f               +cmp ax, 0x7ff0
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32752 /*0x7ff0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00479830  0f859d000000           -jne 0x4798d3
    if (!cpu.flags.zf)
    {
        goto L_0x004798d3;
    }
    // 00479836  dd0570674a00           -fld qword ptr [0x4a6770]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4876144) /* 0x4a6770 */)));
    // 0047983c  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047983f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479840  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479841  dd1f                   -fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00479843  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00479846  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00479849  e8aa6b0000             -call 0x4803f8
    cpu.esp -= 4;
    sub_4803f8(app, cpu);
    // 0047984e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047984f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479851  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479852  7e4f                   -jle 0x4798a3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004798a3;
    }
    // 00479854  83f802                 +cmp eax, 2
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
    // 00479857  7e22                   -jle 0x47987b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047987b;
    }
    // 00479859  83f803                 +cmp eax, 3
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
    // 0047985c  7545                   -jne 0x4798a3
    if (!cpu.flags.zf)
    {
        goto L_0x004798a3;
    }
    // 0047985e  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00479861  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479862  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479863  dd1f                   -fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00479865  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00479868  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479869  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047986c  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0047986e  e883640000             -call 0x47fcf6
    cpu.esp -= 4;
    sub_47fcf6(app, cpu);
    // 00479873  83c410                 +add esp, 0x10
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
    // 00479876  e99f000000             -jmp 0x47991a
    goto L_0x0047991a;
L_0x0047987b:
    // 0047987b  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0047987e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047987f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479880  dd1f                   -fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00479882  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00479885  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00479888  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479889  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047988a  d9ee                   -fldz 
    cpu.fpu.push(0.0);
    // 0047988c  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047988f  e81a6b0000             -call 0x4803ae
    cpu.esp -= 4;
    __copysign(app, cpu);
    // 00479894  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00479897  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479898  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479899  e8926c0000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 0047989e  83c418                 +add esp, 0x18
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
    // 004798a1  eb74                   -jmp 0x479917
    goto L_0x00479917;
L_0x004798a3:
    // 004798a3  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004798a6  dc05e07c4800           -fadd qword ptr [0x487ce0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4750560) /* 0x487ce0 */));
    // 004798ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004798ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798ae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798af  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004798b2  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004798b5  dd1f                   -fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004798b7  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004798ba  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004798bd  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004798c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798c2  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004798c5  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004798c7  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004798c9  e87c640000             -call 0x47fd4a
    cpu.esp -= 4;
    sub_47fd4a(app, cpu);
    // 004798ce  83c41c                 +add esp, 0x1c
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
    // 004798d1  eb47                   -jmp 0x47991a
    goto L_0x0047991a;
L_0x004798d3:
    // 004798d3  dd4508                 +fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004798d6  dc1dd87c4800           +fcomp qword ptr [0x487cd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4750552) /* 0x487cd8 */)));
    cpu.fpu.pop();
    // 004798dc  dd4508                 +fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004798df  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004798e1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004798e2  750a                   -jne 0x4798ee
    if (!cpu.flags.zf)
    {
        goto L_0x004798ee;
    }
    // 004798e4  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004798e7  dd18                   +fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004798e9  dd4508                 +fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004798ec  eb1d                   -jmp 0x47990b
    goto L_0x0047990b;
L_0x004798ee:
    // 004798ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798f0  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004798f3  e8ec630000             -call 0x47fce4
    cpu.esp -= 4;
    __frnd(app, cpu);
    // 004798f8  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004798fb  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004798fe  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479901  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479902  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479903  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00479905  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00479908  dc65f8                 -fsub qword ptr [ebp - 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
L_0x0047990b:
    // 0047990b  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047990e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047990f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479910  e81b6c0000             -call 0x480530
    cpu.esp -= 4;
    sub_480530(app, cpu);
    // 00479915  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479916  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479917:
    // 00479917  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
L_0x0047991a:
    // 0047991a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047991b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047991c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047991d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047991e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
