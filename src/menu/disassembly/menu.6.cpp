#include "menu.h"
namespace menu
{

/* align: skip  */
void Application::asm_sub_429551(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429552  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429556  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 00429559  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042955a  e877270000             -call 0x42bcd6
    cpu.esp -= 4;
    sub_42bcd6(app, cpu);
    // 0042955f  83f865                 +cmp eax, 0x65
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
    // 00429562  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429563  742c                   -je 0x429591
    if (cpu.flags.zf)
    {
        goto L_0x00429591;
    }
L_0x00429565:
    // 00429565  46                     -inc esi
    (cpu.esi)++;
    // 00429566  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042956d  7e0f                   -jle 0x42957e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042957e;
    }
    // 0042956f  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 00429572  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429574  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429575  e8e7260000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042957a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042957b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042957c  eb0f                   -jmp 0x42958d
    goto L_0x0042958d;
L_0x0042957e:
    // 0042957e  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 00429581  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 00429587  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042958a  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042958d:
    // 0042958d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042958f  75d4                   -jne 0x429565
    if (!cpu.flags.zf)
    {
        goto L_0x00429565;
    }
L_0x00429591:
    // 00429591  8a0d34d84300           -mov cl, byte ptr [0x43d834]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */);
    // 00429597  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00429599  880e                   -mov byte ptr [esi], cl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.cl;
    // 0042959b  46                     -inc esi
    (cpu.esi)++;
L_0x0042959c:
    // 0042959c  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0042959e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004295a0  8ac1                   -mov al, cl
    cpu.al = cpu.cl;
    // 004295a2  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004295a4  46                     -inc esi
    (cpu.esi)++;
    // 004295a5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004295a7  75f3                   -jne 0x42959c
    if (!cpu.flags.zf)
    {
        goto L_0x0042959c;
    }
    // 004295a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004295aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4295ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004295ab  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004295af  8a1534d84300           -mov dl, byte ptr [0x43d834]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */);
    // 004295b5  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004295b7  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004295b9  740c                   -je 0x4295c7
    if (cpu.flags.zf)
    {
        goto L_0x004295c7;
    }
L_0x004295bb:
    // 004295bb  3aca                   +cmp cl, dl
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
    // 004295bd  7408                   -je 0x4295c7
    if (cpu.flags.zf)
    {
        goto L_0x004295c7;
    }
    // 004295bf  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004295c2  40                     -inc eax
    (cpu.eax)++;
    // 004295c3  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004295c5  75f4                   -jne 0x4295bb
    if (!cpu.flags.zf)
    {
        goto L_0x004295bb;
    }
L_0x004295c7:
    // 004295c7  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004295c9  40                     -inc eax
    (cpu.eax)++;
    // 004295ca  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004295cc  742a                   -je 0x4295f8
    if (cpu.flags.zf)
    {
        goto L_0x004295f8;
    }
L_0x004295ce:
    // 004295ce  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004295d0  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004295d2  740d                   -je 0x4295e1
    if (cpu.flags.zf)
    {
        goto L_0x004295e1;
    }
    // 004295d4  80f965                 +cmp cl, 0x65
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
    // 004295d7  7408                   -je 0x4295e1
    if (cpu.flags.zf)
    {
        goto L_0x004295e1;
    }
    // 004295d9  80f945                 +cmp cl, 0x45
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
    // 004295dc  7403                   -je 0x4295e1
    if (cpu.flags.zf)
    {
        goto L_0x004295e1;
    }
    // 004295de  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004295df  ebed                   -jmp 0x4295ce
    goto L_0x004295ce;
L_0x004295e1:
    // 004295e1  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004295e3:
    // 004295e3  48                     -dec eax
    (cpu.eax)--;
    // 004295e4  803830                 +cmp byte ptr [eax], 0x30
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
    // 004295e7  74fa                   -je 0x4295e3
    if (cpu.flags.zf)
    {
        goto L_0x004295e3;
    }
    // 004295e9  3810                   +cmp byte ptr [eax], dl
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
    // 004295eb  7501                   -jne 0x4295ee
    if (!cpu.flags.zf)
    {
        goto L_0x004295ee;
    }
    // 004295ed  48                     -dec eax
    (cpu.eax)--;
L_0x004295ee:
    // 004295ee  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004295f0  40                     -inc eax
    (cpu.eax)++;
    // 004295f1  41                     -inc ecx
    (cpu.ecx)++;
    // 004295f2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004295f4  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004295f6  75f6                   -jne 0x4295ee
    if (!cpu.flags.zf)
    {
        goto L_0x004295ee;
    }
L_0x004295f8:
    // 004295f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4295f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004295f9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004295fd  dd00                   +fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 004295ff  dc1df80a4300           +fcomp qword ptr [0x430af8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4393720) /* 0x430af8 */)));
    cpu.fpu.pop();
    // 00429605  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00429607  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00429608  7204                   -jb 0x42960e
    if (cpu.flags.cf)
    {
        goto L_0x0042960e;
    }
    // 0042960a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042960c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042960d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042960e:
    // 0042960e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429610  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429611(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429611  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429612  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429614  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429616  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0042961a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042961d  741b                   -je 0x42963a
    if (cpu.flags.zf)
    {
        goto L_0x0042963a;
    }
    // 0042961f  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00429622  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429623  e80b2b0000             -call 0x42c133
    cpu.esp -= 4;
    sub_42c133(app, cpu);
    // 00429628  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042962b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042962c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042962d  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00429630  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00429632  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00429635  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00429638  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429639  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042963a:
    // 0042963a  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042963d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042963e  e81d2b0000             -call 0x42c160
    cpu.esp -= 4;
    sub_42c160(app, cpu);
    // 00429643  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00429646  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429647  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429648  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042964b  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0042964d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042964e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42964f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042964f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429650  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429652  803d4c54490000         +cmp byte ptr [0x49544c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00429659  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042965a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042965b  7427                   -je 0x429684
    if (cpu.flags.zf)
    {
        goto L_0x00429684;
    }
    // 0042965d  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00429660  a148544900             -mov eax, dword ptr [0x495448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805704) /* 0x495448 */);
    // 00429665  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00429667  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429669  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042966b  0f9fc1                 -setg cl
    cpu.cl = (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of));
    // 0042966e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042966f  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00429671  83382d                 +cmp dword ptr [eax], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429674  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 00429677  034d0c                 +add ecx, dword ptr [ebp + 0xc]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042967a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042967b  e8e7020000             -call 0x429967
    cpu.esp -= 4;
    sub_429967(app, cpu);
    // 00429680  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429681  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429682  eb38                   -jmp 0x4296bc
    goto L_0x004296bc;
L_0x00429684:
    // 00429684  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00429687  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429688  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429689  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 0042968b  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042968e  e8642c0000             -call 0x42c2f7
    cpu.esp -= 4;
    sub_42c2f7(app, cpu);
    // 00429693  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00429696  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429698  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429699  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042969c  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0042969f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004296a0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004296a2  833e2d                 +cmp dword ptr [esi], 0x2d
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
    // 004296a5  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004296a8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004296aa  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004296ac  0f9fc1                 -setg cl
    cpu.cl = (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of));
    // 004296af  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004296b1  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004296b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004296b4  e8c72b0000             -call 0x42c280
    cpu.esp -= 4;
    sub_42c280(app, cpu);
    // 004296b9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x004296bc:
    // 004296bc  833e2d                 +cmp dword ptr [esi], 0x2d
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
    // 004296bf  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004296c2  7504                   -jne 0x4296c8
    if (!cpu.flags.zf)
    {
        goto L_0x004296c8;
    }
    // 004296c4  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 004296c7  40                     -inc eax
    (cpu.eax)++;
L_0x004296c8:
    // 004296c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004296ca  7e14                   -jle 0x4296e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004296e0;
    }
    // 004296cc  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004296cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004296d0  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004296d3  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004296d5  8a0d34d84300           -mov cl, byte ptr [0x43d834]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */);
    // 004296db  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004296dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004296de  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
L_0x004296e0:
    // 004296e0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004296e2  68000b4300             -push 0x430b00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393728 /*0x430b00*/;
    cpu.esp -= 4;
    // 004296e7  380d4c544900           +cmp byte ptr [0x49544c], cl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004296ed  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 004296f0  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004296f2  03cb                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004296f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004296f5  e8962a0000             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 004296fa  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 004296fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004296ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429700  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00429702  7403                   -je 0x429707
    if (cpu.flags.zf)
    {
        goto L_0x00429707;
    }
    // 00429704  c60145                 -mov byte ptr [ecx], 0x45
    app->getMemory<x86::reg8>(cpu.ecx) = 69 /*0x45*/;
L_0x00429707:
    // 00429707  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042970a  41                     -inc ecx
    (cpu.ecx)++;
    // 0042970b  803830                 +cmp byte ptr [eax], 0x30
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
    // 0042970e  743c                   -je 0x42974c
    if (cpu.flags.zf)
    {
        goto L_0x0042974c;
    }
    // 00429710  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00429713  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00429714  7905                   -jns 0x42971b
    if (!cpu.flags.sf)
    {
        goto L_0x0042971b;
    }
    // 00429716  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00429718  c6012d                 -mov byte ptr [ecx], 0x2d
    app->getMemory<x86::reg8>(cpu.ecx) = 45 /*0x2d*/;
L_0x0042971b:
    // 0042971b  41                     -inc ecx
    (cpu.ecx)++;
    // 0042971c  83fb64                 +cmp ebx, 0x64
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
    // 0042971f  7c11                   -jl 0x429732
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00429732;
    }
    // 00429721  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00429723  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 00429725  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00429726  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429727  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00429729  0001                   -add byte ptr [ecx], al
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.al));
    // 0042972b  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042972d  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042972e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00429730  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00429732:
    // 00429732  41                     -inc ecx
    (cpu.ecx)++;
    // 00429733  83fb0a                 +cmp ebx, 0xa
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
    // 00429736  7c11                   -jl 0x429749
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00429749;
    }
    // 00429738  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042973a  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0042973c  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042973d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042973e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00429740  0001                   -add byte ptr [ecx], al
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.al));
    // 00429742  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00429744  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00429745  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00429747  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00429749:
    // 00429749  005901                 -add byte ptr [ecx + 1], bl
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */)) += x86::reg8(x86::sreg8(cpu.bl));
L_0x0042974c:
    // 0042974c  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042974f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429750  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429751  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429752  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429753(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429753  803d4c54490000         +cmp byte ptr [0x49544c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042975a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042975b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042975c  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00429760  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429761  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429762  742a                   -je 0x42978e
    if (cpu.flags.zf)
    {
        goto L_0x0042978e;
    }
    // 00429764  a150544900             -mov eax, dword ptr [0x495450]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805712) /* 0x495450 */);
    // 00429769  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042976d  8b3548544900           -mov esi, dword ptr [0x495448]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805704) /* 0x495448 */);
    // 00429773  3bc3                   +cmp eax, ebx
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
    // 00429775  7547                   -jne 0x4297be
    if (!cpu.flags.zf)
    {
        goto L_0x004297be;
    }
    // 00429777  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00429779  833e2d                 +cmp dword ptr [esi], 0x2d
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
    // 0042977c  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 0042977f  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00429781  03cd                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00429783  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00429785  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 00429788  80600100               +and byte ptr [eax + 1], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042978c  eb30                   -jmp 0x4297be
    goto L_0x004297be;
L_0x0042978e:
    // 0042978e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00429792  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429793  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429794  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 00429796  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429799  e8592b0000             -call 0x42c2f7
    cpu.esp -= 4;
    sub_42c2f7(app, cpu);
    // 0042979e  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004297a2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004297a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004297a5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004297a8  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004297aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004297ab  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004297ad  833e2d                 +cmp dword ptr [esi], 0x2d
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
    // 004297b0  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004297b3  03c5                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004297b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004297b6  e8c52a0000             -call 0x42c280
    cpu.esp -= 4;
    sub_42c280(app, cpu);
    // 004297bb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x004297be:
    // 004297be  833e2d                 +cmp dword ptr [esi], 0x2d
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
    // 004297c1  8bfd                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004297c3  7507                   -jne 0x4297cc
    if (!cpu.flags.zf)
    {
        goto L_0x004297cc;
    }
    // 004297c5  c645002d               -mov byte ptr [ebp], 0x2d
    app->getMemory<x86::reg8>(cpu.ebp) = 45 /*0x2d*/;
    // 004297c9  8d7d01                 -lea edi, [ebp + 1]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
L_0x004297cc:
    // 004297cc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004297cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004297d1  7f10                   -jg 0x4297e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004297e3;
    }
    // 004297d3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004297d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004297d6  e88c010000             -call 0x429967
    cpu.esp -= 4;
    sub_429967(app, cpu);
    // 004297db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004297dc  c60730                 -mov byte ptr [edi], 0x30
    app->getMemory<x86::reg8>(cpu.edi) = 48 /*0x30*/;
    // 004297df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004297e0  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004297e1  eb02                   -jmp 0x4297e5
    goto L_0x004297e5;
L_0x004297e3:
    // 004297e3  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004297e5:
    // 004297e5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004297e7  7e41                   -jle 0x42982a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042982a;
    }
    // 004297e9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004297eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004297ec  e876010000             -call 0x429967
    cpu.esp -= 4;
    sub_429967(app, cpu);
    // 004297f1  a034d84300             -mov al, byte ptr [0x43d834]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */);
    // 004297f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004297f7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004297f9  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004297fc  47                     -inc edi
    (cpu.edi)++;
    // 004297fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004297fe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429800  7d28                   -jge 0x42982a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042982a;
    }
    // 00429802  803d4c54490000         +cmp byte ptr [0x49544c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00429809  7404                   -je 0x42980f
    if (cpu.flags.zf)
    {
        goto L_0x0042980f;
    }
    // 0042980b  f7de                   +neg esi
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
    // 0042980d  eb06                   -jmp 0x429815
    goto L_0x00429815;
L_0x0042980f:
    // 0042980f  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00429811  3bde                   +cmp ebx, esi
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
    // 00429813  7c02                   -jl 0x429817
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00429817;
    }
L_0x00429815:
    // 00429815  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00429817:
    // 00429817  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429818  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429819  e849010000             -call 0x429967
    cpu.esp -= 4;
    sub_429967(app, cpu);
    // 0042981e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042981f  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00429821  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429822  e8e9190000             -call 0x42b210
    cpu.esp -= 4;
    sub_42b210(app, cpu);
    // 00429827  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0042982a:
    // 0042982a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042982b  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0042982d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042982e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042982f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429830  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429831(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429831  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429832  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429834  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429835  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429836  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429837  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042983a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042983b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042983c  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 0042983e  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429841  e8b12a0000             -call 0x42c2f7
    cpu.esp -= 4;
    sub_42c2f7(app, cpu);
    // 00429846  a348544900             -mov dword ptr [0x495448], eax
    app->getMemory<x86::reg32>(x86::reg32(4805704) /* 0x495448 */) = cpu.eax;
    // 0042984b  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042984e  49                     -dec ecx
    (cpu.ecx)--;
    // 0042984f  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00429852  890d50544900           -mov dword ptr [0x495450], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805712) /* 0x495450 */) = cpu.ecx;
    // 00429858  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042985a  83382d                 +cmp dword ptr [eax], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042985d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042985e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042985f  0f94c1                 -sete cl
    cpu.cl = cpu.flags.zf;
    // 00429862  034d0c                 -add ecx, dword ptr [ebp + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00429865  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00429867  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429868  e8132a0000             -call 0x42c280
    cpu.esp -= 4;
    sub_42c280(app, cpu);
    // 0042986d  a148544900             -mov eax, dword ptr [0x495448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805704) /* 0x495448 */);
    // 00429872  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00429875  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00429878  49                     -dec ecx
    (cpu.ecx)--;
    // 00429879  390d50544900           +cmp dword ptr [0x495450], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805712) /* 0x495450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042987f  0f9cc1                 -setl cl
    cpu.cl = (cpu.flags.sf != cpu.flags.of);
    // 00429882  880d54544900           -mov byte ptr [0x495454], cl
    app->getMemory<x86::reg8>(x86::reg32(4805716) /* 0x495454 */) = cpu.cl;
    // 00429888  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042988b  48                     -dec eax
    (cpu.eax)--;
    // 0042988c  83f8fc                 +cmp eax, -4
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
    // 0042988f  a350544900             -mov dword ptr [0x495450], eax
    app->getMemory<x86::reg32>(x86::reg32(4805712) /* 0x495450 */) = cpu.eax;
    // 00429894  7c21                   -jl 0x4298b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004298b7;
    }
    // 00429896  3bc3                   +cmp eax, ebx
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
    // 00429898  7d1d                   -jge 0x4298b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004298b7;
    }
    // 0042989a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042989c  740a                   -je 0x4298a8
    if (cpu.flags.zf)
    {
        goto L_0x004298a8;
    }
L_0x0042989e:
    // 0042989e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004298a0  46                     -inc esi
    (cpu.esi)++;
    // 004298a1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004298a3  75f9                   -jne 0x42989e
    if (!cpu.flags.zf)
    {
        goto L_0x0042989e;
    }
    // 004298a5  2046fe                 -and byte ptr [esi - 2], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */) &= x86::reg8(x86::sreg8(cpu.al));
L_0x004298a8:
    // 004298a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004298a9  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004298ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004298ad  e841000000             -call 0x4298f3
    cpu.esp -= 4;
    sub_4298f3(app, cpu);
    // 004298b2  83c40c                 +add esp, 0xc
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
    // 004298b5  eb10                   -jmp 0x4298c7
    goto L_0x004298c7;
L_0x004298b7:
    // 004298b7  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004298ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004298bb  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004298be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004298bf  e808000000             -call 0x4298cc
    cpu.esp -= 4;
    sub_4298cc(app, cpu);
    // 004298c4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004298c7:
    // 004298c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004298c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004298c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004298ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004298cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4298cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004298cc  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004298d0  c6054c54490001         -mov byte ptr [0x49544c], 1
    app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */) = 1 /*0x1*/;
    // 004298d7  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004298db  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004298df  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004298e3  e867fdffff             -call 0x42964f
    cpu.esp -= 4;
    sub_42964f(app, cpu);
    // 004298e8  80254c54490000         -and byte ptr [0x49544c], 0
    app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 004298ef  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004298f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4298f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004298f3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004298f7  c6054c54490001         -mov byte ptr [0x49544c], 1
    app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */) = 1 /*0x1*/;
    // 004298fe  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00429902  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00429906  e848feffff             -call 0x429753
    cpu.esp -= 4;
    sub_429753(app, cpu);
    // 0042990b  80254c54490000         -and byte ptr [0x49544c], 0
    app->getMemory<x86::reg8>(x86::reg32(4805708) /* 0x49544c */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429912  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00429915  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429916(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429916  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429917  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429919  837d1065               +cmp dword ptr [ebp + 0x10], 0x65
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
    // 0042991d  7432                   -je 0x429951
    if (cpu.flags.zf)
    {
        goto L_0x00429951;
    }
    // 0042991f  837d1045               +cmp dword ptr [ebp + 0x10], 0x45
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
    // 00429923  742c                   -je 0x429951
    if (cpu.flags.zf)
    {
        goto L_0x00429951;
    }
    // 00429925  837d1066               +cmp dword ptr [ebp + 0x10], 0x66
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
    // 00429929  7513                   -jne 0x42993e
    if (!cpu.flags.zf)
    {
        goto L_0x0042993e;
    }
    // 0042992b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042992e  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00429931  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429934  e81afeffff             -call 0x429753
    cpu.esp -= 4;
    sub_429753(app, cpu);
    // 00429939  83c40c                 +add esp, 0xc
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
    // 0042993c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042993d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042993e:
    // 0042993e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00429941  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429944  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00429947  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042994a  e8e2feffff             -call 0x429831
    cpu.esp -= 4;
    sub_429831(app, cpu);
    // 0042994f  eb11                   -jmp 0x429962
    goto L_0x00429962;
L_0x00429951:
    // 00429951  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00429954  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429957  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042995a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042995d  e8edfcffff             -call 0x42964f
    cpu.esp -= 4;
    sub_42964f(app, cpu);
L_0x00429962:
    // 00429962  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429965  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429967(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429967  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429968  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042996c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042996e  741a                   -je 0x42998a
    if (cpu.flags.zf)
    {
        goto L_0x0042998a;
    }
    // 00429970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429971  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00429975  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429976  e855e4ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042997b  40                     -inc eax
    (cpu.eax)++;
    // 0042997c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042997d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042997e  03f7                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00429980  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429981  e8ea180000             -call 0x42b270
    cpu.esp -= 4;
    sub_42b270(app, cpu);
    // 00429986  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429989  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042998a:
    // 0042998a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042998b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4299a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004299a6;
L_0x00429990:
    // 00429990  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00429993  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429994  c3                     -ret 
    cpu.esp += 4;
    return;
L_entry_0x004299a6:
    // 004299a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004299a7  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004299a9  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004299ac  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004299b0  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 004299b6  7413                   -je 0x4299cb
    if (cpu.flags.zf)
    {
        goto L_0x004299cb;
    }
L_0x004299b8:
    // 004299b8  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004299ba  42                     -inc edx
    (cpu.edx)++;
    // 004299bb  38d9                   +cmp cl, bl
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
    // 004299bd  74d1                   -je 0x429990
    if (cpu.flags.zf)
    {
        goto L_0x00429990;
    }
    // 004299bf  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004299c1  7451                   -je 0x429a14
    if (cpu.flags.zf)
    {
        goto L_0x00429a14;
    }
    // 004299c3  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 004299c9  75ed                   -jne 0x4299b8
    if (!cpu.flags.zf)
    {
        goto L_0x004299b8;
    }
L_0x004299cb:
    // 004299cb  0bd8                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004299cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004299ce  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004299d0  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004299d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004299d4  0bd8                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004299d6:
    // 004299d6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004299d8  bffffefe7e             -mov edi, 0x7efefeff
    cpu.edi = 2130640639 /*0x7efefeff*/;
    // 004299dd  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004299df  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004299e1  33cb                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004299e3  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004299e5  03f9                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004299e7  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004299ea  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004299ed  33cf                   -xor ecx, edi
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004299ef  33c6                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004299f1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004299f4  81e100010181           +and ecx, 0x81010100
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(2164326656 /*0x81010100*/))));
    // 004299fa  751c                   -jne 0x429a18
    if (!cpu.flags.zf)
    {
        goto L_0x00429a18;
    }
    // 004299fc  2500010181             +and eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2164326656 /*0x81010100*/))));
    // 00429a01  74d3                   -je 0x4299d6
    if (cpu.flags.zf)
    {
        goto L_0x004299d6;
    }
    // 00429a03  2500010101             +and eax, 0x1010100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16843008 /*0x1010100*/))));
    // 00429a08  7508                   -jne 0x429a12
    if (!cpu.flags.zf)
    {
        goto L_0x00429a12;
    }
    // 00429a0a  81e600000080           +and esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 00429a10  75c4                   -jne 0x4299d6
    if (!cpu.flags.zf)
    {
        goto L_0x004299d6;
    }
L_0x00429a12:
    // 00429a12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00429a14:
    // 00429a14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a15  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429a17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429a18:
    // 00429a18  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00429a1b  38d8                   +cmp al, bl
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
    // 00429a1d  7436                   -je 0x429a55
    if (cpu.flags.zf)
    {
        goto L_0x00429a55;
    }
    // 00429a1f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00429a21  74ef                   -je 0x429a12
    if (cpu.flags.zf)
    {
        goto L_0x00429a12;
    }
    // 00429a23  38dc                   +cmp ah, bl
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
    // 00429a25  7427                   -je 0x429a4e
    if (cpu.flags.zf)
    {
        goto L_0x00429a4e;
    }
    // 00429a27  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00429a29  74e7                   -je 0x429a12
    if (cpu.flags.zf)
    {
        goto L_0x00429a12;
    }
    // 00429a2b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00429a2e  38d8                   +cmp al, bl
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
    // 00429a30  7415                   -je 0x429a47
    if (cpu.flags.zf)
    {
        goto L_0x00429a47;
    }
    // 00429a32  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00429a34  74dc                   -je 0x429a12
    if (cpu.flags.zf)
    {
        goto L_0x00429a12;
    }
    // 00429a36  38dc                   +cmp ah, bl
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
    // 00429a38  7406                   -je 0x429a40
    if (cpu.flags.zf)
    {
        goto L_0x00429a40;
    }
    // 00429a3a  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00429a3c  74d4                   -je 0x429a12
    if (cpu.flags.zf)
    {
        goto L_0x00429a12;
    }
    // 00429a3e  eb96                   -jmp 0x4299d6
    goto L_0x004299d6;
L_0x00429a40:
    // 00429a40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a42  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00429a45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429a47:
    // 00429a47  8d42fe                 -lea eax, [edx - 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00429a4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429a4e:
    // 00429a4e  8d42fd                 -lea eax, [edx - 3]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-3) /* -0x3 */);
    // 00429a51  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429a55:
    // 00429a55  8d42fc                 -lea eax, [edx - 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00429a58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4299a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004299a0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004299a2  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    return sub_4299a6(app, cpu);
}

/* align: skip  */
void Application::asm_sub_429a5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429a5c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a5d  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429a61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a62  e875d0ffff             -call 0x426adc
    cpu.esp -= 4;
    sub_426adc(app, cpu);
    // 00429a67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429a69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a6a  7408                   -je 0x429a74
    if (cpu.flags.zf)
    {
        goto L_0x00429a74;
    }
    // 00429a6c  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00429a6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a70  83e809                 -sub eax, 9
    (cpu.eax) -= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00429a73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429a74:
    // 00429a74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a75  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00429a77  ff352c5e4900           -push dword ptr [0x495e2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4808236) /* 0x495e2c */);
    cpu.esp -= 4;
    // 00429a7d  ff15fc004300           -call dword ptr [0x4300fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391164) /* 0x4300fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429a83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429a85(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429a85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429a86  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429a88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429a89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429a8a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429a8b  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00429a8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429a90  6a5c                   -push 0x5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 92 /*0x5c*/;
    cpu.esp -= 4;
    // 00429a92  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429a93  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00429a95  e8372a0000             -call 0x42c4d1
    cpu.esp -= 4;
    sub_42c4d1(app, cpu);
    // 00429a9a  6a2f                   -push 0x2f
    app->getMemory<x86::reg32>(cpu.esp-4) = 47 /*0x2f*/;
    cpu.esp -= 4;
    // 00429a9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429a9d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429a9f  e82d2a0000             -call 0x42c4d1
    cpu.esp -= 4;
    sub_42c4d1(app, cpu);
    // 00429aa4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429aa7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429aa9  7545                   -jne 0x429af0
    if (!cpu.flags.zf)
    {
        goto L_0x00429af0;
    }
    // 00429aab  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429aad  754b                   -jne 0x429afa
    if (!cpu.flags.zf)
    {
        goto L_0x00429afa;
    }
    // 00429aaf  6a3a                   -push 0x3a
    app->getMemory<x86::reg32>(cpu.esp-4) = 58 /*0x3a*/;
    cpu.esp -= 4;
    // 00429ab1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429ab2  e8a7290000             -call 0x42c45e
    cpu.esp -= 4;
    sub_42c45e(app, cpu);
    // 00429ab7  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429ab9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429aba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429abc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429abd  753b                   -jne 0x429afa
    if (!cpu.flags.zf)
    {
        goto L_0x00429afa;
    }
    // 00429abf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429ac0  e80be3ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 00429ac5  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00429ac8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429ac9  e8a7b3ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 00429ace  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00429ad0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429ad1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00429ad3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429ad4  747d                   -je 0x429b53
    if (cpu.flags.zf)
    {
        goto L_0x00429b53;
    }
    // 00429ad6  68280b4300             -push 0x430b28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4393768 /*0x430b28*/;
    cpu.esp -= 4;
    // 00429adb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429adc  e8af260000             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 00429ae1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429ae2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429ae3  e8b8260000             -call 0x42c1a0
    cpu.esp -= 4;
    sub_42c1a0(app, cpu);
    // 00429ae8  83c410                 +add esp, 0x10
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
    // 00429aeb  8d7702                 -lea esi, [edi + 2]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00429aee  eb0a                   -jmp 0x429afa
    goto L_0x00429afa;
L_0x00429af0:
    // 00429af0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429af2  7404                   -je 0x429af8
    if (cpu.flags.zf)
    {
        goto L_0x00429af8;
    }
    // 00429af4  3bc6                   +cmp eax, esi
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
    // 00429af6  7602                   -jbe 0x429afa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00429afa;
    }
L_0x00429af8:
    // 00429af8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00429afa:
    // 00429afa  834df8ff               -or dword ptr [ebp - 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00429afe  6a2e                   -push 0x2e
    app->getMemory<x86::reg32>(cpu.esp-4) = 46 /*0x2e*/;
    cpu.esp -= 4;
    // 00429b00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429b01  e8cb290000             -call 0x42c4d1
    cpu.esp -= 4;
    sub_42c4d1(app, cpu);
    // 00429b06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429b09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b0a  742d                   -je 0x429b39
    if (cpu.flags.zf)
    {
        goto L_0x00429b39;
    }
    // 00429b0c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00429b0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429b0f  e806290000             -call 0x42c41a
    cpu.esp -= 4;
    sub_42c41a(app, cpu);
    // 00429b14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b15  83f8ff                 +cmp eax, -1
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
    // 00429b18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b19  0f849c000000           -je 0x429bbb
    if (cpu.flags.zf)
    {
        goto L_0x00429bbb;
    }
    // 00429b1f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429b22  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00429b25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429b26  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429b29  e8a0000000             -call 0x429bce
    cpu.esp -= 4;
    sub_429bce(app, cpu);
    // 00429b2e  83c410                 +add esp, 0x10
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
    // 00429b31  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00429b34  e982000000             -jmp 0x429bbb
    goto L_0x00429bbb;
L_0x00429b39:
    // 00429b39  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429b3a  e891e2ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 00429b3f  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00429b42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429b43  e82db3ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 00429b48  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00429b4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b4b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00429b4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b4e  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00429b51  7505                   -jne 0x429b58
    if (!cpu.flags.zf)
    {
        goto L_0x00429b58;
    }
L_0x00429b53:
    // 00429b53  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00429b56  eb71                   -jmp 0x429bc9
    goto L_0x00429bc9;
L_0x00429b58:
    // 00429b58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429b59  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429b5a  e831260000             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 00429b5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429b60  e86be2ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 00429b65  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429b67  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00429b6a  03f3                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00429b6c  bb8cd34300             -mov ebx, 0x43d38c
    cpu.ebx = 4445068 /*0x43d38c*/;
L_0x00429b71:
    // 00429b71  ff33                   -push dword ptr [ebx]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebx);
    cpu.esp -= 4;
    // 00429b73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429b74  e817260000             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 00429b79  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00429b7b  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00429b7e  e897280000             -call 0x42c41a
    cpu.esp -= 4;
    sub_42c41a(app, cpu);
    // 00429b83  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429b86  83f8ff                 +cmp eax, -1
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
    // 00429b89  750d                   -jne 0x429b98
    if (!cpu.flags.zf)
    {
        goto L_0x00429b98;
    }
    // 00429b8b  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429b8e  81fb80d34300           +cmp ebx, 0x43d380
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4445056 /*0x43d380*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429b94  7ddb                   -jge 0x429b71
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00429b71;
    }
    // 00429b96  eb17                   -jmp 0x429baf
    goto L_0x00429baf;
L_0x00429b98:
    // 00429b98  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429b9b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00429b9e  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00429ba1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429ba4  e825000000             -call 0x429bce
    cpu.esp -= 4;
    sub_429bce(app, cpu);
    // 00429ba9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429bac  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00429baf:
    // 00429baf  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00429bb2  e88fb2ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00429bb7  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00429bba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00429bbb:
    // 00429bbb  3bfb                   +cmp edi, ebx
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
    // 00429bbd  7407                   -je 0x429bc6
    if (cpu.flags.zf)
    {
        goto L_0x00429bc6;
    }
    // 00429bbf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429bc0  e881b2ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00429bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00429bc6:
    // 00429bc6  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x00429bc9:
    // 00429bc9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429bca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429bcb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429bcc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429bcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429bce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429bce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429bcf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429bd1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00429bd4  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00429bd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429bd8  8d4514                 -lea eax, [ebp + 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00429bdb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429bdc  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429bdf  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00429be2  e8292b0000             -call 0x42c710
    cpu.esp -= 4;
    sub_42c710(app, cpu);
    // 00429be7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00429bea  83f8ff                 +cmp eax, -1
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
    // 00429bed  7504                   -jne 0x429bf3
    if (!cpu.flags.zf)
    {
        goto L_0x00429bf3;
    }
    // 00429bef  0bc0                   -or eax, eax
    cpu.eax |= x86::reg32(x86::sreg32(cpu.eax));
    // 00429bf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429bf2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429bf3:
    // 00429bf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429bf4  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00429bf7  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429bfa  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00429bfd  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429c00  e82c290000             -call 0x42c531
    cpu.esp -= 4;
    sub_42c531(app, cpu);
    // 00429c05  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00429c08  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429c0a  e837b2ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00429c0f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00429c12  e82fb2ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 00429c17  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00429c1a  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00429c1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429c1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429c1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_429c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429c20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429c21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429c22  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00429c26  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00429c28  7518                   -jne 0x429c42
    if (!cpu.flags.zf)
    {
        goto L_0x00429c42;
    }
    // 00429c2a  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00429c2e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00429c32  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00429c34  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00429c36  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00429c38  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00429c3c  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00429c3e  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00429c40  eb41                   -jmp 0x429c83
    goto L_0x00429c83;
L_0x00429c42:
    // 00429c42  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00429c44  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00429c48  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00429c4c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00429c50:
    // 00429c50  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00429c52  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
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
    // 00429c54  d1ea                   +shr edx, 1
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
    // 00429c56  d1d8                   -rcr eax, 1
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
    // 00429c58  0bc9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00429c5a  75f4                   -jne 0x429c50
    if (!cpu.flags.zf)
    {
        goto L_0x00429c50;
    }
    // 00429c5c  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00429c5e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429c60  f7642418               -mul dword ptr [esp + 0x18]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00429c64  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00429c66  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00429c6a  f7e6                   -mul esi
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.esi);
    // 00429c6c  03d1                   +add edx, ecx
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
    // 00429c6e  720e                   -jb 0x429c7e
    if (cpu.flags.cf)
    {
        goto L_0x00429c7e;
    }
    // 00429c70  3b542410               +cmp edx, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429c74  7708                   -ja 0x429c7e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00429c7e;
    }
    // 00429c76  7207                   -jb 0x429c7f
    if (cpu.flags.cf)
    {
        goto L_0x00429c7f;
    }
    // 00429c78  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429c7c  7601                   -jbe 0x429c7f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00429c7f;
    }
L_0x00429c7e:
    // 00429c7e  4e                     -dec esi
    (cpu.esi)--;
L_0x00429c7f:
    // 00429c7f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00429c81  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00429c83:
    // 00429c83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429c84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429c85  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_429c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429c90  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429c94  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00429c98  0bc8                   +or ecx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00429c9a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00429c9e  7509                   -jne 0x429ca9
    if (!cpu.flags.zf)
    {
        goto L_0x00429ca9;
    }
    // 00429ca0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00429ca4  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00429ca6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00429ca9:
    // 00429ca9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429caa  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00429cac  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00429cae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429cb2  f7642414               -mul dword ptr [esp + 0x14]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00429cb6  03d8                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00429cb8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429cbc  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00429cbe  03d3                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00429cc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429cc1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_429cc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429cc4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429cc5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00429cc7  81ecc4010000           -sub esp, 0x1c4
    (cpu.esp) -= x86::reg32(x86::sreg32(452 /*0x1c4*/));
    // 00429ccd  8065eb00               -and byte ptr [ebp - 0x15], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429cd1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429cd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429cd3  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00429cd6  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00429cd8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429cd9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00429cdb  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00429cde  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00429ce0  895dcc                 -mov dword ptr [ebp - 0x34], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.ebx;
    // 00429ce3  0f84e1090000           -je 0x42a6ca
    if (cpu.flags.zf)
    {
        goto L_0x0042a6ca;
    }
    // 00429ce9  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00429cec  eb05                   -jmp 0x429cf3
    goto L_0x00429cf3;
L_0x00429cee:
    // 00429cee  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00429cf1  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00429cf3:
    // 00429cf3  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429cfa  7e0f                   -jle 0x429d0b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429d0b;
    }
    // 00429cfc  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00429cff  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00429d01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429d02  e85a1f0000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 00429d07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429d08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429d09  eb0f                   -jmp 0x429d1a
    goto L_0x00429d1a;
L_0x00429d0b:
    // 00429d0b  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 00429d11  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00429d14  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 00429d17  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00429d1a:
    // 00429d1a  3bc3                   +cmp eax, ebx
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
    // 00429d1c  7436                   -je 0x429d54
    if (cpu.flags.zf)
    {
        goto L_0x00429d54;
    }
    // 00429d1e  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 00429d21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429d22  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00429d25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429d26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429d27  e8250a0000             -call 0x42a751
    cpu.esp -= 4;
    sub_42a751(app, cpu);
    // 00429d2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429d2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429d2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429d2f  e8060a0000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 00429d34  0fb64601               -movzx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 00429d38  46                     -inc esi
    (cpu.esi)++;
    // 00429d39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429d3a  e89d2c0000             -call 0x42c9dc
    cpu.esp -= 4;
    sub_42c9dc(app, cpu);
    // 00429d3f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00429d42:
    // 00429d42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429d44  740e                   -je 0x429d54
    if (cpu.flags.zf)
    {
        goto L_0x00429d54;
    }
    // 00429d46  0fb64601               -movzx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 00429d4a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00429d4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429d4c  e88b2c0000             -call 0x42c9dc
    cpu.esp -= 4;
    sub_42c9dc(app, cpu);
    // 00429d51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429d52  ebee                   -jmp 0x429d42
    goto L_0x00429d42;
L_0x00429d54:
    // 00429d54  803e25                 +cmp byte ptr [esi], 0x25
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
    // 00429d57  0f85d9080000           -jne 0x42a636
    if (!cpu.flags.zf)
    {
        goto L_0x0042a636;
    }
    // 00429d5d  8065cb00               -and byte ptr [ebp - 0x35], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-53) /* -0x35 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429d61  8065e800               -and byte ptr [ebp - 0x18], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429d65  8065e900               -and byte ptr [ebp - 0x17], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429d69  8065f200               -and byte ptr [ebp - 0xe], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429d6d  8065f100               -and byte ptr [ebp - 0xf], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429d71  8065ea00               -and byte ptr [ebp - 0x16], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429d75  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00429d77  8065fb00               -and byte ptr [ebp - 5], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429d7b  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00429d7e  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00429d81  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00429d84  c645f301               -mov byte ptr [ebp - 0xd], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */) = 1 /*0x1*/;
    // 00429d88  895dd0                 -mov dword ptr [ebp - 0x30], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.ebx;
L_0x00429d8b:
    // 00429d8b  0fb65e01               -movzx ebx, byte ptr [esi + 1]
    cpu.ebx = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 00429d8f  46                     -inc esi
    (cpu.esi)++;
    // 00429d90  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429d97  7e0f                   -jle 0x429da8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429da8;
    }
    // 00429d99  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00429d9c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429d9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429d9f  e8bd1e0000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 00429da4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429da5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429da6  eb0f                   -jmp 0x429db7
    goto L_0x00429db7;
L_0x00429da8:
    // 00429da8  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 00429dae  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 00429db1  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 00429db4  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00429db7:
    // 00429db7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429db9  7412                   -je 0x429dcd
    if (cpu.flags.zf)
    {
        goto L_0x00429dcd;
    }
    // 00429dbb  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00429dbe  ff45e0                 +inc dword ptr [ebp - 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00429dc1  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00429dc4  8d4443d0               -lea eax, [ebx + eax*2 - 0x30]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-48) /* -0x30 */ + cpu.eax * 2);
    // 00429dc8  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00429dcb  eb65                   -jmp 0x429e32
    goto L_0x00429e32;
L_0x00429dcd:
    // 00429dcd  83fb4e                 +cmp ebx, 0x4e
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
    // 00429dd0  7f3e                   -jg 0x429e10
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00429e10;
    }
    // 00429dd2  745e                   -je 0x429e32
    if (cpu.flags.zf)
    {
        goto L_0x00429e32;
    }
    // 00429dd4  83fb2a                 +cmp ebx, 0x2a
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
    // 00429dd7  7432                   -je 0x429e0b
    if (cpu.flags.zf)
    {
        goto L_0x00429e0b;
    }
    // 00429dd9  83fb46                 +cmp ebx, 0x46
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
    // 00429ddc  7454                   -je 0x429e32
    if (cpu.flags.zf)
    {
        goto L_0x00429e32;
    }
    // 00429dde  83fb49                 +cmp ebx, 0x49
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
    // 00429de1  740a                   -je 0x429ded
    if (cpu.flags.zf)
    {
        goto L_0x00429ded;
    }
    // 00429de3  83fb4c                 +cmp ebx, 0x4c
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
    // 00429de6  7537                   -jne 0x429e1f
    if (!cpu.flags.zf)
    {
        goto L_0x00429e1f;
    }
    // 00429de8  fe45f3                 +inc byte ptr [ebp - 0xd]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00429deb  eb45                   -jmp 0x429e32
    goto L_0x00429e32;
L_0x00429ded:
    // 00429ded  807e0136               +cmp byte ptr [esi + 1], 0x36
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
    // 00429df1  752c                   -jne 0x429e1f
    if (!cpu.flags.zf)
    {
        goto L_0x00429e1f;
    }
    // 00429df3  807e0234               +cmp byte ptr [esi + 2], 0x34
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
    // 00429df7  8d4602                 -lea eax, [esi + 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00429dfa  7523                   -jne 0x429e1f
    if (!cpu.flags.zf)
    {
        goto L_0x00429e1f;
    }
    // 00429dfc  ff45d0                 -inc dword ptr [ebp - 0x30]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */))++;
    // 00429dff  8365d800               -and dword ptr [ebp - 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00429e03  8365dc00               +and dword ptr [ebp - 0x24], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 00429e07  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429e09  eb27                   -jmp 0x429e32
    goto L_0x00429e32;
L_0x00429e0b:
    // 00429e0b  fe45f2                 +inc byte ptr [ebp - 0xe]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00429e0e  eb22                   -jmp 0x429e32
    goto L_0x00429e32;
L_0x00429e10:
    // 00429e10  83fb68                 +cmp ebx, 0x68
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
    // 00429e13  7417                   -je 0x429e2c
    if (cpu.flags.zf)
    {
        goto L_0x00429e2c;
    }
    // 00429e15  83fb6c                 +cmp ebx, 0x6c
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
    // 00429e18  740a                   -je 0x429e24
    if (cpu.flags.zf)
    {
        goto L_0x00429e24;
    }
    // 00429e1a  83fb77                 +cmp ebx, 0x77
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
    // 00429e1d  7408                   -je 0x429e27
    if (cpu.flags.zf)
    {
        goto L_0x00429e27;
    }
L_0x00429e1f:
    // 00429e1f  fe45f1                 +inc byte ptr [ebp - 0xf]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00429e22  eb0e                   -jmp 0x429e32
    goto L_0x00429e32;
L_0x00429e24:
    // 00429e24  fe45f3                 +inc byte ptr [ebp - 0xd]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
L_0x00429e27:
    // 00429e27  fe45fb                 +inc byte ptr [ebp - 5]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00429e2a  eb06                   -jmp 0x429e32
    goto L_0x00429e32;
L_0x00429e2c:
    // 00429e2c  fe4df3                 -dec byte ptr [ebp - 0xd]
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */))--;
    // 00429e2f  fe4dfb                 -dec byte ptr [ebp - 5]
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */))--;
L_0x00429e32:
    // 00429e32  807df100               +cmp byte ptr [ebp - 0xf], 0
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
    // 00429e36  0f844fffffff           -je 0x429d8b
    if (cpu.flags.zf)
    {
        goto L_0x00429d8b;
    }
    // 00429e3c  807df200               +cmp byte ptr [ebp - 0xe], 0
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
    // 00429e40  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00429e43  7512                   -jne 0x429e57
    if (!cpu.flags.zf)
    {
        goto L_0x00429e57;
    }
    // 00429e45  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00429e48  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
    // 00429e4b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429e4e  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00429e51  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00429e54  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
L_0x00429e57:
    // 00429e57  8065f100               -and byte ptr [ebp - 0xf], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00429e5b  807dfb00               +cmp byte ptr [ebp - 5], 0
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
    // 00429e5f  7514                   -jne 0x429e75
    if (!cpu.flags.zf)
    {
        goto L_0x00429e75;
    }
    // 00429e61  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00429e63  3c53                   +cmp al, 0x53
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
    // 00429e65  740a                   -je 0x429e71
    if (cpu.flags.zf)
    {
        goto L_0x00429e71;
    }
    // 00429e67  3c43                   +cmp al, 0x43
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
    // 00429e69  7406                   -je 0x429e71
    if (cpu.flags.zf)
    {
        goto L_0x00429e71;
    }
    // 00429e6b  804dfbff               +or byte ptr [ebp - 5], 0xff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) |= x86::reg8(x86::sreg8(255 /*0xff*/))));
    // 00429e6f  eb04                   -jmp 0x429e75
    goto L_0x00429e75;
L_0x00429e71:
    // 00429e71  c645fb01               -mov byte ptr [ebp - 5], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = 1 /*0x1*/;
L_0x00429e75:
    // 00429e75  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00429e78  0fb633                 -movzx esi, byte ptr [ebx]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx));
    // 00429e7b  83ce20                 -or esi, 0x20
    cpu.esi |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00429e7e  83fe6e                 +cmp esi, 0x6e
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
    // 00429e81  8975c4                 -mov dword ptr [ebp - 0x3c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.esi;
    // 00429e84  7428                   -je 0x429eae
    if (cpu.flags.zf)
    {
        goto L_0x00429eae;
    }
    // 00429e86  83fe63                 +cmp esi, 0x63
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
    // 00429e89  7414                   -je 0x429e9f
    if (cpu.flags.zf)
    {
        goto L_0x00429e9f;
    }
    // 00429e8b  83fe7b                 +cmp esi, 0x7b
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
    // 00429e8e  740f                   -je 0x429e9f
    if (cpu.flags.zf)
    {
        goto L_0x00429e9f;
    }
    // 00429e90  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429e93  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00429e96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429e97  e8b5080000             -call 0x42a751
    cpu.esp -= 4;
    sub_42a751(app, cpu);
    // 00429e9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429e9d  eb0b                   -jmp 0x429eaa
    goto L_0x00429eaa;
L_0x00429e9f:
    // 00429e9f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00429ea2  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00429ea5  e876080000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
L_0x00429eaa:
    // 00429eaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429eab  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x00429eae:
    // 00429eae  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429eb0  3945e0                 +cmp dword ptr [ebp - 0x20], eax
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
    // 00429eb3  7409                   -je 0x429ebe
    if (cpu.flags.zf)
    {
        goto L_0x00429ebe;
    }
    // 00429eb5  3945f4                 +cmp dword ptr [ebp - 0xc], eax
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
    // 00429eb8  0f84dc070000           -je 0x42a69a
    if (cpu.flags.zf)
    {
        goto L_0x0042a69a;
    }
L_0x00429ebe:
    // 00429ebe  83fe6f                 +cmp esi, 0x6f
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
    // 00429ec1  0f8f5e020000           -jg 0x42a125
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042a125;
    }
    // 00429ec7  0f840a050000           -je 0x42a3d7
    if (cpu.flags.zf)
    {
        goto L_0x0042a3d7;
    }
    // 00429ecd  83fe63                 +cmp esi, 0x63
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
    // 00429ed0  0f842c020000           -je 0x42a102
    if (cpu.flags.zf)
    {
        goto L_0x0042a102;
    }
    // 00429ed6  83fe64                 +cmp esi, 0x64
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
    // 00429ed9  0f84f8040000           -je 0x42a3d7
    if (cpu.flags.zf)
    {
        goto L_0x0042a3d7;
    }
    // 00429edf  0f8e6a020000           -jle 0x42a14f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a14f;
    }
    // 00429ee5  83fe67                 +cmp esi, 0x67
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
    // 00429ee8  7e38                   -jle 0x429f22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429f22;
    }
    // 00429eea  83fe69                 +cmp esi, 0x69
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
    // 00429eed  741b                   -je 0x429f0a
    if (cpu.flags.zf)
    {
        goto L_0x00429f0a;
    }
    // 00429eef  83fe6e                 +cmp esi, 0x6e
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
    // 00429ef2  0f8557020000           -jne 0x42a14f
    if (!cpu.flags.zf)
    {
        goto L_0x0042a14f;
    }
    // 00429ef8  807df200               +cmp byte ptr [ebp - 0xe], 0
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
    // 00429efc  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00429eff  0f8400070000           -je 0x42a605
    if (cpu.flags.zf)
    {
        goto L_0x0042a605;
    }
    // 00429f05  e921070000             -jmp 0x42a62b
    goto L_0x0042a62b;
L_0x00429f0a:
    // 00429f0a  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 00429f0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00429f0d:
    // 00429f0d  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00429f10  83fb2d                 +cmp ebx, 0x2d
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
    // 00429f13  0f857e020000           -jne 0x42a197
    if (!cpu.flags.zf)
    {
        goto L_0x0042a197;
    }
    // 00429f19  c645e901               -mov byte ptr [ebp - 0x17], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) = 1 /*0x1*/;
    // 00429f1d  e97a020000             -jmp 0x42a19c
    goto L_0x0042a19c;
L_0x00429f22:
    // 00429f22  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00429f25  8db53cfeffff           -lea esi, [ebp - 0x1c4]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-452) /* -0x1c4 */);
    // 00429f2b  83fb2d                 +cmp ebx, 0x2d
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
    // 00429f2e  750e                   -jne 0x429f3e
    if (!cpu.flags.zf)
    {
        goto L_0x00429f3e;
    }
    // 00429f30  889d3cfeffff           -mov byte ptr [ebp - 0x1c4], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-452) /* -0x1c4 */) = cpu.bl;
    // 00429f36  8db53dfeffff           -lea esi, [ebp - 0x1c3]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-451) /* -0x1c3 */);
    // 00429f3c  eb05                   -jmp 0x429f43
    goto L_0x00429f43;
L_0x00429f3e:
    // 00429f3e  83fb2b                 +cmp ebx, 0x2b
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
    // 00429f41  7517                   -jne 0x429f5a
    if (!cpu.flags.zf)
    {
        goto L_0x00429f5a;
    }
L_0x00429f43:
    // 00429f43  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00429f46  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00429f49  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00429f4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429f4d  e8ce070000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 00429f52  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00429f54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f55  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00429f58  eb03                   -jmp 0x429f5d
    goto L_0x00429f5d;
L_0x00429f5a:
    // 00429f5a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00429f5d:
    // 00429f5d  837de000               +cmp dword ptr [ebp - 0x20], 0
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
    // 00429f61  7409                   -je 0x429f6c
    if (cpu.flags.zf)
    {
        goto L_0x00429f6c;
    }
    // 00429f63  817df45d010000         +cmp dword ptr [ebp - 0xc], 0x15d
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
    // 00429f6a  7e07                   -jle 0x429f73
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429f73;
    }
L_0x00429f6c:
    // 00429f6c  c745f45d010000         -mov dword ptr [ebp - 0xc], 0x15d
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 349 /*0x15d*/;
L_0x00429f73:
    // 00429f73  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429f7a  7e0c                   -jle 0x429f88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429f88;
    }
    // 00429f7c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429f7e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429f7f  e8dd1c0000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 00429f84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f86  eb0b                   -jmp 0x429f93
    goto L_0x00429f93;
L_0x00429f88:
    // 00429f88  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 00429f8d  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 00429f90  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00429f93:
    // 00429f93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429f95  7421                   -je 0x429fb8
    if (cpu.flags.zf)
    {
        goto L_0x00429fb8;
    }
    // 00429f97  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00429f9a  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00429f9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429f9f  7417                   -je 0x429fb8
    if (cpu.flags.zf)
    {
        goto L_0x00429fb8;
    }
    // 00429fa1  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00429fa4  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 00429fa6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00429fa7  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00429faa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429fab  e870070000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 00429fb0  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00429fb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429fb3  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00429fb6  ebbb                   -jmp 0x429f73
    goto L_0x00429f73;
L_0x00429fb8:
    // 00429fb8  381d34d84300           +cmp byte ptr [0x43d834], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00429fbe  7566                   -jne 0x42a026
    if (!cpu.flags.zf)
    {
        goto L_0x0042a026;
    }
    // 00429fc0  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00429fc3  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00429fc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429fc8  745c                   -je 0x42a026
    if (cpu.flags.zf)
    {
        goto L_0x0042a026;
    }
    // 00429fca  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00429fcd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429fce  e84d070000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 00429fd3  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00429fd5  a034d84300             -mov al, byte ptr [0x43d834]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4446260) /* 0x43d834 */);
    // 00429fda  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00429fdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429fdd  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00429fe0  46                     -inc esi
    (cpu.esi)++;
L_0x00429fe1:
    // 00429fe1  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429fe8  7e0c                   -jle 0x429ff6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429ff6;
    }
    // 00429fea  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429fec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429fed  e86f1c0000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 00429ff2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429ff3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429ff4  eb0b                   -jmp 0x42a001
    goto L_0x0042a001;
L_0x00429ff6:
    // 00429ff6  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 00429ffb  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 00429ffe  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042a001:
    // 0042a001  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a003  7421                   -je 0x42a026
    if (cpu.flags.zf)
    {
        goto L_0x0042a026;
    }
    // 0042a005  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042a008  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0042a00b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a00d  7417                   -je 0x42a026
    if (cpu.flags.zf)
    {
        goto L_0x0042a026;
    }
    // 0042a00f  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a012  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0042a014  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a015  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a018  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a019  e802070000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a01e  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a020  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a021  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a024  ebbb                   -jmp 0x429fe1
    goto L_0x00429fe1;
L_0x0042a026:
    // 0042a026  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 0042a02a  0f848e000000           -je 0x42a0be
    if (cpu.flags.zf)
    {
        goto L_0x0042a0be;
    }
    // 0042a030  83fb65                 +cmp ebx, 0x65
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
    // 0042a033  7409                   -je 0x42a03e
    if (cpu.flags.zf)
    {
        goto L_0x0042a03e;
    }
    // 0042a035  83fb45                 +cmp ebx, 0x45
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
    // 0042a038  0f8580000000           -jne 0x42a0be
    if (!cpu.flags.zf)
    {
        goto L_0x0042a0be;
    }
L_0x0042a03e:
    // 0042a03e  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042a041  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0042a044  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a046  7476                   -je 0x42a0be
    if (cpu.flags.zf)
    {
        goto L_0x0042a0be;
    }
    // 0042a048  c60665                 -mov byte ptr [esi], 0x65
    app->getMemory<x86::reg8>(cpu.esi) = 101 /*0x65*/;
    // 0042a04b  46                     -inc esi
    (cpu.esi)++;
    // 0042a04c  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a04f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a050  e8cb060000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a055  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a057  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a058  83fb2d                 +cmp ebx, 0x2d
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
    // 0042a05b  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a05e  7505                   -jne 0x42a065
    if (!cpu.flags.zf)
    {
        goto L_0x0042a065;
    }
    // 0042a060  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0042a062  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a063  eb05                   -jmp 0x42a06a
    goto L_0x0042a06a;
L_0x0042a065:
    // 0042a065  83fb2b                 +cmp ebx, 0x2b
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
    // 0042a068  751e                   -jne 0x42a088
    if (!cpu.flags.zf)
    {
        goto L_0x0042a088;
    }
L_0x0042a06a:
    // 0042a06a  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042a06d  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0042a070  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a072  7505                   -jne 0x42a079
    if (!cpu.flags.zf)
    {
        goto L_0x0042a079;
    }
    // 0042a074  2145f4                 +and dword ptr [ebp - 0xc], eax
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042a077  eb0f                   -jmp 0x42a088
    goto L_0x0042a088;
L_0x0042a079:
    // 0042a079  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a07c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a07d  e89e060000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a082  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a085  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0042a088:
    // 0042a088  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a08f  7e0c                   -jle 0x42a09d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a09d;
    }
    // 0042a091  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042a093  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a094  e8c81b0000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042a099  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a09a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a09b  eb0b                   -jmp 0x42a0a8
    goto L_0x0042a0a8;
L_0x0042a09d:
    // 0042a09d  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a0a2  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0042a0a5  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042a0a8:
    // 0042a0a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a0aa  7412                   -je 0x42a0be
    if (cpu.flags.zf)
    {
        goto L_0x0042a0be;
    }
    // 0042a0ac  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042a0af  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0042a0b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a0b4  7408                   -je 0x42a0be
    if (cpu.flags.zf)
    {
        goto L_0x0042a0be;
    }
    // 0042a0b6  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a0b9  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0042a0bb  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a0bc  ebbb                   -jmp 0x42a079
    goto L_0x0042a079;
L_0x0042a0be:
    // 0042a0be  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0042a0c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a0c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a0c3  e872060000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a0c8  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 0042a0cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a0cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a0ce  0f84f6050000           -je 0x42a6ca
    if (cpu.flags.zf)
    {
        goto L_0x0042a6ca;
    }
    // 0042a0d4  807df200               +cmp byte ptr [ebp - 0xe], 0
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
    // 0042a0d8  0f854d050000           -jne 0x42a62b
    if (!cpu.flags.zf)
    {
        goto L_0x0042a62b;
    }
    // 0042a0de  ff45cc                 -inc dword ptr [ebp - 0x34]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */))++;
    // 0042a0e1  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042a0e4  8d853cfeffff           -lea eax, [ebp - 0x1c4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-452) /* -0x1c4 */);
    // 0042a0ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a0eb  0fbe45f3               -movsx eax, byte ptr [ebp - 0xd]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */)));
    // 0042a0ef  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 0042a0f2  48                     -dec eax
    (cpu.eax)--;
    // 0042a0f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a0f4  ff1570d34300           -call dword ptr [0x43d370]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4445040) /* 0x43d370 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a0fa  83c40c                 +add esp, 0xc
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
    // 0042a0fd  e929050000             -jmp 0x42a62b
    goto L_0x0042a62b;
L_0x0042a102:
    // 0042a102  3945e0                 +cmp dword ptr [ebp - 0x20], eax
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
    // 0042a105  750a                   -jne 0x42a111
    if (!cpu.flags.zf)
    {
        goto L_0x0042a111;
    }
    // 0042a107  ff45f4                 -inc dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))++;
    // 0042a10a  c745e001000000         -mov dword ptr [ebp - 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = 1 /*0x1*/;
L_0x0042a111:
    // 0042a111  807dfb00               +cmp byte ptr [ebp - 5], 0
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
    // 0042a115  7e04                   -jle 0x42a11b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a11b;
    }
    // 0042a117  c645ea01               -mov byte ptr [ebp - 0x16], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 1 /*0x1*/;
L_0x0042a11b:
    // 0042a11b  bf98d34300             -mov edi, 0x43d398
    cpu.edi = 4445080 /*0x43d398*/;
    // 0042a120  e90b010000             -jmp 0x42a230
    goto L_0x0042a230;
L_0x0042a125:
    // 0042a125  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042a127  83e870                 +sub eax, 0x70
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
    // 0042a12a  0f84a3020000           -je 0x42a3d3
    if (cpu.flags.zf)
    {
        goto L_0x0042a3d3;
    }
    // 0042a130  83e803                 +sub eax, 3
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
    // 0042a133  0f84e8000000           -je 0x42a221
    if (cpu.flags.zf)
    {
        goto L_0x0042a221;
    }
    // 0042a139  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a13a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a13b  0f8496020000           -je 0x42a3d7
    if (cpu.flags.zf)
    {
        goto L_0x0042a3d7;
    }
    // 0042a141  83e803                 +sub eax, 3
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
    // 0042a144  0f84c3fdffff           -je 0x429f0d
    if (cpu.flags.zf)
    {
        goto L_0x00429f0d;
    }
    // 0042a14a  83e803                 +sub eax, 3
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
    // 0042a14d  7424                   -je 0x42a173
    if (cpu.flags.zf)
    {
        goto L_0x0042a173;
    }
L_0x0042a14f:
    // 0042a14f  0fb603                 -movzx eax, byte ptr [ebx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx));
    // 0042a152  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
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
    // 0042a155  0f853f050000           -jne 0x42a69a
    if (!cpu.flags.zf)
    {
        goto L_0x0042a69a;
    }
    // 0042a15b  fe4deb                 -dec byte ptr [ebp - 0x15]
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */))--;
    // 0042a15e  807df200               +cmp byte ptr [ebp - 0xe], 0
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
    // 0042a162  0f85c3040000           -jne 0x42a62b
    if (!cpu.flags.zf)
    {
        goto L_0x0042a62b;
    }
    // 0042a168  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0042a16b  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042a16e  e9b8040000             -jmp 0x42a62b
    goto L_0x0042a62b;
L_0x0042a173:
    // 0042a173  807dfb00               +cmp byte ptr [ebp - 5], 0
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
    // 0042a177  7e04                   -jle 0x42a17d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a17d;
    }
    // 0042a179  c645ea01               -mov byte ptr [ebp - 0x16], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 1 /*0x1*/;
L_0x0042a17d:
    // 0042a17d  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042a180  47                     -inc edi
    (cpu.edi)++;
    // 0042a181  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0042a184  803f5e                 +cmp byte ptr [edi], 0x5e
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
    // 0042a187  0f85a7000000           -jne 0x42a234
    if (!cpu.flags.zf)
    {
        goto L_0x0042a234;
    }
    // 0042a18d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042a18f  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042a192  e999000000             -jmp 0x42a230
    goto L_0x0042a230;
L_0x0042a197:
    // 0042a197  83fb2b                 +cmp ebx, 0x2b
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
    // 0042a19a  7522                   -jne 0x42a1be
    if (!cpu.flags.zf)
    {
        goto L_0x0042a1be;
    }
L_0x0042a19c:
    // 0042a19c  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a19f  750c                   -jne 0x42a1ad
    if (!cpu.flags.zf)
    {
        goto L_0x0042a1ad;
    }
    // 0042a1a1  837de000               +cmp dword ptr [ebp - 0x20], 0
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
    // 0042a1a5  7406                   -je 0x42a1ad
    if (cpu.flags.zf)
    {
        goto L_0x0042a1ad;
    }
    // 0042a1a7  c645f101               -mov byte ptr [ebp - 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) = 1 /*0x1*/;
    // 0042a1ab  eb11                   -jmp 0x42a1be
    goto L_0x0042a1be;
L_0x0042a1ad:
    // 0042a1ad  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a1b0  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a1b3  e868050000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a1b8  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a1ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a1bb  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0042a1be:
    // 0042a1be  83fb30                 +cmp ebx, 0x30
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
    // 0042a1c1  0f8545020000           -jne 0x42a40c
    if (!cpu.flags.zf)
    {
        goto L_0x0042a40c;
    }
    // 0042a1c7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a1ca  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a1cd  e84e050000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a1d2  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a1d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a1d5  80fb78                 +cmp bl, 0x78
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
    // 0042a1d8  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a1db  742f                   -je 0x42a20c
    if (cpu.flags.zf)
    {
        goto L_0x0042a20c;
    }
    // 0042a1dd  80fb58                 +cmp bl, 0x58
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
    // 0042a1e0  742a                   -je 0x42a20c
    if (cpu.flags.zf)
    {
        goto L_0x0042a20c;
    }
    // 0042a1e2  83fe78                 +cmp esi, 0x78
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
    // 0042a1e5  c745e401000000         -mov dword ptr [ebp - 0x1c], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 1 /*0x1*/;
    // 0042a1ec  7408                   -je 0x42a1f6
    if (cpu.flags.zf)
    {
        goto L_0x0042a1f6;
    }
    // 0042a1ee  6a6f                   -push 0x6f
    app->getMemory<x86::reg32>(cpu.esp-4) = 111 /*0x6f*/;
    cpu.esp -= 4;
L_0x0042a1f0:
    // 0042a1f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a1f1  e916020000             -jmp 0x42a40c
    goto L_0x0042a40c;
L_0x0042a1f6:
    // 0042a1f6  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a1f9  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a1fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a1fd  e838050000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a202  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a203  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a204  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0042a206  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a207  e9fd010000             -jmp 0x42a409
    goto L_0x0042a409;
L_0x0042a20c:
    // 0042a20c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a20f  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a212  e809050000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a217  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a218  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a21a  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a21d  6a78                   -push 0x78
    app->getMemory<x86::reg32>(cpu.esp-4) = 120 /*0x78*/;
    cpu.esp -= 4;
    // 0042a21f  ebcf                   -jmp 0x42a1f0
    goto L_0x0042a1f0;
L_0x0042a221:
    // 0042a221  807dfb00               +cmp byte ptr [ebp - 5], 0
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
    // 0042a225  7e04                   -jle 0x42a22b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a22b;
    }
    // 0042a227  c645ea01               -mov byte ptr [ebp - 0x16], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 1 /*0x1*/;
L_0x0042a22b:
    // 0042a22b  bf90d34300             -mov edi, 0x43d390
    cpu.edi = 4445072 /*0x43d390*/;
L_0x0042a230:
    // 0042a230  804de8ff               -or byte ptr [ebp - 0x18], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) |= x86::reg8(x86::sreg8(255 /*0xff*/));
L_0x0042a234:
    // 0042a234  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0042a236  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0042a239  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a23b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a23c  e8cf0f0000             -call 0x42b210
    cpu.esp -= 4;
    sub_42b210(app, cpu);
    // 0042a241  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042a244  837dc47b               +cmp dword ptr [ebp - 0x3c], 0x7b
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
    // 0042a248  750e                   -jne 0x42a258
    if (!cpu.flags.zf)
    {
        goto L_0x0042a258;
    }
    // 0042a24a  803f5d                 +cmp byte ptr [edi], 0x5d
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
    // 0042a24d  7509                   -jne 0x42a258
    if (!cpu.flags.zf)
    {
        goto L_0x0042a258;
    }
    // 0042a24f  b25d                   -mov dl, 0x5d
    cpu.dl = 93 /*0x5d*/;
    // 0042a251  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a252  c645a720               -mov byte ptr [ebp - 0x59], 0x20
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-89) /* -0x59 */) = 32 /*0x20*/;
    // 0042a256  eb03                   -jmp 0x42a25b
    goto L_0x0042a25b;
L_0x0042a258:
    // 0042a258  8a55cb                 -mov dl, byte ptr [ebp - 0x35]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-53) /* -0x35 */);
L_0x0042a25b:
    // 0042a25b  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0042a25d  3c5d                   +cmp al, 0x5d
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
    // 0042a25f  745f                   -je 0x42a2c0
    if (cpu.flags.zf)
    {
        goto L_0x0042a2c0;
    }
    // 0042a261  47                     -inc edi
    (cpu.edi)++;
    // 0042a262  3c2d                   +cmp al, 0x2d
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
    // 0042a264  7541                   -jne 0x42a2a7
    if (!cpu.flags.zf)
    {
        goto L_0x0042a2a7;
    }
    // 0042a266  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042a268  743d                   -je 0x42a2a7
    if (cpu.flags.zf)
    {
        goto L_0x0042a2a7;
    }
    // 0042a26a  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042a26c  80f95d                 +cmp cl, 0x5d
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
    // 0042a26f  7436                   -je 0x42a2a7
    if (cpu.flags.zf)
    {
        goto L_0x0042a2a7;
    }
    // 0042a271  47                     -inc edi
    (cpu.edi)++;
    // 0042a272  3ad1                   +cmp dl, cl
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
    // 0042a274  7304                   -jae 0x42a27a
    if (!cpu.flags.cf)
    {
        goto L_0x0042a27a;
    }
    // 0042a276  8ac1                   -mov al, cl
    cpu.al = cpu.cl;
    // 0042a278  eb04                   -jmp 0x42a27e
    goto L_0x0042a27e;
L_0x0042a27a:
    // 0042a27a  8ac2                   -mov al, dl
    cpu.al = cpu.dl;
    // 0042a27c  8ad1                   -mov dl, cl
    cpu.dl = cpu.cl;
L_0x0042a27e:
    // 0042a27e  3ad0                   +cmp dl, al
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
    // 0042a280  7721                   -ja 0x42a2a3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042a2a3;
    }
    // 0042a282  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 0042a285  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 0042a288  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042a28a  46                     -inc esi
    (cpu.esi)++;
L_0x0042a28b:
    // 0042a28b  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042a28d  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042a28f  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0042a292  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0042a294  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0042a297  d2e3                   -shl bl, cl
    cpu.bl <<= cpu.cl % 32;
    // 0042a299  8d44059c               -lea eax, [ebp + eax - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */ + cpu.eax * 1);
    // 0042a29d  0818                   +or byte ptr [eax], bl
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.bl))));
    // 0042a29f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a2a0  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a2a1  75e8                   -jne 0x42a28b
    if (!cpu.flags.zf)
    {
        goto L_0x0042a28b;
    }
L_0x0042a2a3:
    // 0042a2a3  32d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 0042a2a5  ebb4                   -jmp 0x42a25b
    goto L_0x0042a25b;
L_0x0042a2a7:
    // 0042a2a7  0fb6c8                 -movzx ecx, al
    cpu.ecx = x86::reg32(cpu.al);
    // 0042a2aa  8ad0                   -mov dl, al
    cpu.dl = cpu.al;
    // 0042a2ac  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042a2ae  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0042a2b1  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0042a2b3  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0042a2b6  d2e3                   -shl bl, cl
    cpu.bl <<= cpu.cl % 32;
    // 0042a2b8  8d44059c               -lea eax, [ebp + eax - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */ + cpu.eax * 1);
    // 0042a2bc  0818                   +or byte ptr [eax], bl
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.bl))));
    // 0042a2be  eb9b                   -jmp 0x42a25b
    goto L_0x0042a25b;
L_0x0042a2c0:
    // 0042a2c0  803f00                 +cmp byte ptr [edi], 0
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
    // 0042a2c3  0f8401040000           -je 0x42a6ca
    if (cpu.flags.zf)
    {
        goto L_0x0042a6ca;
    }
    // 0042a2c9  837dc47b               +cmp dword ptr [ebp - 0x3c], 0x7b
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
    // 0042a2cd  7503                   -jne 0x42a2d2
    if (!cpu.flags.zf)
    {
        goto L_0x0042a2d2;
    }
    // 0042a2cf  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0042a2d2:
    // 0042a2d2  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042a2d5  8b75d4                 -mov esi, dword ptr [ebp - 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0042a2d8  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0042a2db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a2dc  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 0042a2df  8975d0                 -mov dword ptr [ebp - 0x30], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.esi;
    // 0042a2e2  e853040000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a2e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a2e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042a2e9:
    // 0042a2e9  837de000               +cmp dword ptr [ebp - 0x20], 0
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
    // 0042a2ed  740e                   -je 0x42a2fd
    if (cpu.flags.zf)
    {
        goto L_0x0042a2fd;
    }
    // 0042a2ef  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042a2f2  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0042a2f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a2f7  0f849c000000           -je 0x42a399
    if (cpu.flags.zf)
    {
        goto L_0x0042a399;
    }
L_0x0042a2fd:
    // 0042a2fd  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a300  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a301  e81a040000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a306  83f8ff                 +cmp eax, -1
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
    // 0042a309  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a30a  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0042a30d  747e                   -je 0x42a38d
    if (cpu.flags.zf)
    {
        goto L_0x0042a38d;
    }
    // 0042a30f  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042a311  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042a313  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0042a316  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a317  0fbe5de8               -movsx ebx, byte ptr [ebp - 0x18]
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0042a31b  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0042a31d  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042a31f  c1f903                 -sar ecx, 3
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (3 /*0x3*/ % 32));
    // 0042a322  0fbe4c0d9c             -movsx ecx, byte ptr [ebp + ecx - 0x64]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-100) /* -0x64 */ + cpu.ecx * 1)));
    // 0042a327  33cb                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042a329  85d1                   +test ecx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.edx));
    // 0042a32b  7460                   -je 0x42a38d
    if (cpu.flags.zf)
    {
        goto L_0x0042a38d;
    }
    // 0042a32d  807df200               +cmp byte ptr [ebp - 0xe], 0
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
    // 0042a331  7552                   -jne 0x42a385
    if (!cpu.flags.zf)
    {
        goto L_0x0042a385;
    }
    // 0042a333  807dea00               +cmp byte ptr [ebp - 0x16], 0
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
    // 0042a337  7441                   -je 0x42a37a
    if (cpu.flags.zf)
    {
        goto L_0x0042a37a;
    }
    // 0042a339  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a33f  8845c8                 -mov byte ptr [ebp - 0x38], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.al;
    // 0042a342  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0042a345  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0042a34a  740d                   -je 0x42a359
    if (cpu.flags.zf)
    {
        goto L_0x0042a359;
    }
    // 0042a34c  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a34f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a350  e8cb030000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a355  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a356  8845c9                 -mov byte ptr [ebp - 0x37], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-55) /* -0x37 */) = cpu.al;
L_0x0042a359:
    // 0042a359  ff3530d84300           -push dword ptr [0x43d830]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
    cpu.esp -= 4;
    // 0042a35f  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0042a362  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a363  8d45c2                 -lea eax, [ebp - 0x3e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-62) /* -0x3e */);
    // 0042a366  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a367  e8a8250000             -call 0x42c914
    cpu.esp -= 4;
    sub_42c914(app, cpu);
    // 0042a36c  668b45c2               -mov ax, word ptr [ebp - 0x3e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-62) /* -0x3e */);
    // 0042a370  83c40c                 +add esp, 0xc
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
    // 0042a373  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 0042a376  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a377  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a378  eb03                   -jmp 0x42a37d
    goto L_0x0042a37d;
L_0x0042a37a:
    // 0042a37a  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0042a37c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042a37d:
    // 0042a37d  8975d4                 -mov dword ptr [ebp - 0x2c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.esi;
    // 0042a380  e964ffffff             -jmp 0x42a2e9
    goto L_0x0042a2e9;
L_0x0042a385:
    // 0042a385  ff45d0                 +inc dword ptr [ebp - 0x30]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a388  e95cffffff             -jmp 0x42a2e9
    goto L_0x0042a2e9;
L_0x0042a38d:
    // 0042a38d  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0042a390  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a391  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a392  e8a3030000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a397  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a398  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042a399:
    // 0042a399  3975d0                 +cmp dword ptr [ebp - 0x30], esi
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
    // 0042a39c  0f8428030000           -je 0x42a6ca
    if (cpu.flags.zf)
    {
        goto L_0x0042a6ca;
    }
    // 0042a3a2  807df200               +cmp byte ptr [ebp - 0xe], 0
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
    // 0042a3a6  0f857f020000           -jne 0x42a62b
    if (!cpu.flags.zf)
    {
        goto L_0x0042a62b;
    }
    // 0042a3ac  ff45cc                 -inc dword ptr [ebp - 0x34]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */))++;
    // 0042a3af  837dc463               +cmp dword ptr [ebp - 0x3c], 0x63
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
    // 0042a3b3  0f8472020000           -je 0x42a62b
    if (cpu.flags.zf)
    {
        goto L_0x0042a62b;
    }
    // 0042a3b9  807dea00               +cmp byte ptr [ebp - 0x16], 0
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
    // 0042a3bd  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0042a3c0  7409                   -je 0x42a3cb
    if (cpu.flags.zf)
    {
        goto L_0x0042a3cb;
    }
    // 0042a3c2  66832000               +and word ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.eax) &= x86::reg16(x86::sreg16(0 /*0x0*/))));
    // 0042a3c6  e960020000             -jmp 0x42a62b
    goto L_0x0042a62b;
L_0x0042a3cb:
    // 0042a3cb  802000                 +and byte ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042a3ce  e958020000             -jmp 0x42a62b
    goto L_0x0042a62b;
L_0x0042a3d3:
    // 0042a3d3  c645f301               -mov byte ptr [ebp - 0xd], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */) = 1 /*0x1*/;
L_0x0042a3d7:
    // 0042a3d7  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042a3da  83fb2d                 +cmp ebx, 0x2d
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
    // 0042a3dd  7506                   -jne 0x42a3e5
    if (!cpu.flags.zf)
    {
        goto L_0x0042a3e5;
    }
    // 0042a3df  c645e901               -mov byte ptr [ebp - 0x17], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) = 1 /*0x1*/;
    // 0042a3e3  eb05                   -jmp 0x42a3ea
    goto L_0x0042a3ea;
L_0x0042a3e5:
    // 0042a3e5  83fb2b                 +cmp ebx, 0x2b
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
    // 0042a3e8  7522                   -jne 0x42a40c
    if (!cpu.flags.zf)
    {
        goto L_0x0042a40c;
    }
L_0x0042a3ea:
    // 0042a3ea  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a3ed  750c                   -jne 0x42a3fb
    if (!cpu.flags.zf)
    {
        goto L_0x0042a3fb;
    }
    // 0042a3ef  837de000               +cmp dword ptr [ebp - 0x20], 0
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
    // 0042a3f3  7406                   -je 0x42a3fb
    if (cpu.flags.zf)
    {
        goto L_0x0042a3fb;
    }
    // 0042a3f5  c645f101               -mov byte ptr [ebp - 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) = 1 /*0x1*/;
    // 0042a3f9  eb11                   -jmp 0x42a40c
    goto L_0x0042a40c;
L_0x0042a3fb:
    // 0042a3fb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a3fe  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a401  e81a030000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a406  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a407  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0042a409:
    // 0042a409  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0042a40c:
    // 0042a40c  837dd000               +cmp dword ptr [ebp - 0x30], 0
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
    // 0042a410  0f840f010000           -je 0x42a525
    if (cpu.flags.zf)
    {
        goto L_0x0042a525;
    }
    // 0042a416  807df100               +cmp byte ptr [ebp - 0xf], 0
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
    // 0042a41a  0f85e3000000           -jne 0x42a503
    if (!cpu.flags.zf)
    {
        goto L_0x0042a503;
    }
L_0x0042a420:
    // 0042a420  83fe78                 +cmp esi, 0x78
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
    // 0042a423  754f                   -jne 0x42a474
    if (!cpu.flags.zf)
    {
        goto L_0x0042a474;
    }
    // 0042a425  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a42c  7e0f                   -jle 0x42a43d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a43d;
    }
    // 0042a42e  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0042a433  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a434  e828180000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042a439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a43a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a43b  eb0d                   -jmp 0x42a44a
    goto L_0x0042a44a;
L_0x0042a43d:
    // 0042a43d  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a442  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0042a445  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
L_0x0042a44a:
    // 0042a44a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a44c  0f84a3000000           -je 0x42a4f5
    if (cpu.flags.zf)
    {
        goto L_0x0042a4f5;
    }
    // 0042a452  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0042a455  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042a458  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042a45a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a45b  e8b0250000             -call 0x42ca10
    cpu.esp -= 4;
    sub_42ca10(app, cpu);
    // 0042a460  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a461  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0042a464  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0042a467  e87d020000             -call 0x42a6e9
    cpu.esp -= 4;
    sub_42a6e9(app, cpu);
    // 0042a46c  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a46e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a46f  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a472  eb53                   -jmp 0x42a4c7
    goto L_0x0042a4c7;
L_0x0042a474:
    // 0042a474  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a47b  7e0c                   -jle 0x42a489
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a489;
    }
    // 0042a47d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042a47f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a480  e8dc170000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042a485  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a486  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a487  eb0b                   -jmp 0x42a494
    goto L_0x0042a494;
L_0x0042a489:
    // 0042a489  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a48e  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0042a491  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042a494:
    // 0042a494  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a496  745d                   -je 0x42a4f5
    if (cpu.flags.zf)
    {
        goto L_0x0042a4f5;
    }
    // 0042a498  83fe6f                 +cmp esi, 0x6f
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
    // 0042a49b  7515                   -jne 0x42a4b2
    if (!cpu.flags.zf)
    {
        goto L_0x0042a4b2;
    }
    // 0042a49d  83fb38                 +cmp ebx, 0x38
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
    // 0042a4a0  7d53                   -jge 0x42a4f5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042a4f5;
    }
    // 0042a4a2  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0042a4a5  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042a4a8  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042a4aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a4ab  e860250000             -call 0x42ca10
    cpu.esp -= 4;
    sub_42ca10(app, cpu);
    // 0042a4b0  eb0f                   -jmp 0x42a4c1
    goto L_0x0042a4c1;
L_0x0042a4b2:
    // 0042a4b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a4b4  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0042a4b6  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 0042a4b9  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 0042a4bc  e8cff7ffff             -call 0x429c90
    cpu.esp -= 4;
    sub_429c90(app, cpu);
L_0x0042a4c1:
    // 0042a4c1  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0042a4c4  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x0042a4c7:
    // 0042a4c7  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
    // 0042a4ca  8d43d0                 -lea eax, [ebx - 0x30]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-48) /* -0x30 */);
    // 0042a4cd  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042a4ce  0145d8                 +add dword ptr [ebp - 0x28], eax
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
    // 0042a4d1  1155dc                 -adc dword ptr [ebp - 0x24], edx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */)) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0042a4d4  837de000               +cmp dword ptr [ebp - 0x20], 0
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
    // 0042a4d8  7405                   -je 0x42a4df
    if (cpu.flags.zf)
    {
        goto L_0x0042a4df;
    }
    // 0042a4da  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a4dd  7424                   -je 0x42a503
    if (cpu.flags.zf)
    {
        goto L_0x0042a503;
    }
L_0x0042a4df:
    // 0042a4df  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a4e2  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a4e5  e836020000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a4ea  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a4ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a4ed  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a4f0  e92bffffff             -jmp 0x42a420
    goto L_0x0042a420;
L_0x0042a4f5:
    // 0042a4f5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a4f8  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0042a4fb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a4fc  e839020000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a501  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a502  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042a503:
    // 0042a503  807de900               +cmp byte ptr [ebp - 0x17], 0
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
    // 0042a507  0f84dc000000           -je 0x42a5e9
    if (cpu.flags.zf)
    {
        goto L_0x0042a5e9;
    }
    // 0042a50d  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0042a510  8b4ddc                 -mov ecx, dword ptr [ebp - 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042a513  f7d8                   +neg eax
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
    // 0042a515  83d100                 -adc ecx, 0
    (cpu.ecx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 0042a518  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0042a51b  f7d9                   +neg ecx
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
    // 0042a51d  894ddc                 -mov dword ptr [ebp - 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ecx;
    // 0042a520  e9c4000000             -jmp 0x42a5e9
    goto L_0x0042a5e9;
L_0x0042a525:
    // 0042a525  807df100               +cmp byte ptr [ebp - 0xf], 0
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
    // 0042a529  0f85b2000000           -jne 0x42a5e1
    if (!cpu.flags.zf)
    {
        goto L_0x0042a5e1;
    }
L_0x0042a52f:
    // 0042a52f  83fe78                 +cmp esi, 0x78
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
    // 0042a532  743f                   -je 0x42a573
    if (cpu.flags.zf)
    {
        goto L_0x0042a573;
    }
    // 0042a534  83fe70                 +cmp esi, 0x70
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
    // 0042a537  743a                   -je 0x42a573
    if (cpu.flags.zf)
    {
        goto L_0x0042a573;
    }
    // 0042a539  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a540  7e0c                   -jle 0x42a54e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a54e;
    }
    // 0042a542  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042a544  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a545  e817170000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042a54a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a54b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a54c  eb0b                   -jmp 0x42a559
    goto L_0x0042a559;
L_0x0042a54e:
    // 0042a54e  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a553  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0042a556  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042a559:
    // 0042a559  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a55b  7476                   -je 0x42a5d3
    if (cpu.flags.zf)
    {
        goto L_0x0042a5d3;
    }
    // 0042a55d  83fe6f                 +cmp esi, 0x6f
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
    // 0042a560  750a                   -jne 0x42a56c
    if (!cpu.flags.zf)
    {
        goto L_0x0042a56c;
    }
    // 0042a562  83fb38                 +cmp ebx, 0x38
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
    // 0042a565  7d6c                   -jge 0x42a5d3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042a5d3;
    }
    // 0042a567  c1e703                 +shl edi, 3
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
    // 0042a56a  eb3f                   -jmp 0x42a5ab
    goto L_0x0042a5ab;
L_0x0042a56c:
    // 0042a56c  8d3cbf                 -lea edi, [edi + edi*4]
    cpu.edi = x86::reg32(cpu.edi + cpu.edi * 4);
    // 0042a56f  d1e7                   +shl edi, 1
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
    // 0042a571  eb38                   -jmp 0x42a5ab
    goto L_0x0042a5ab;
L_0x0042a573:
    // 0042a573  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a57a  7e0f                   -jle 0x42a58b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a58b;
    }
    // 0042a57c  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0042a581  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a582  e8da160000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042a587  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a588  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a589  eb0d                   -jmp 0x42a598
    goto L_0x0042a598;
L_0x0042a58b:
    // 0042a58b  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a590  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0042a593  2580000000             -and eax, 0x80
    cpu.eax &= x86::reg32(x86::sreg32(128 /*0x80*/));
L_0x0042a598:
    // 0042a598  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a59a  7437                   -je 0x42a5d3
    if (cpu.flags.zf)
    {
        goto L_0x0042a5d3;
    }
    // 0042a59c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a59d  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0042a5a0  e844010000             -call 0x42a6e9
    cpu.esp -= 4;
    sub_42a6e9(app, cpu);
    // 0042a5a5  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a5a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a5a8  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
L_0x0042a5ab:
    // 0042a5ab  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
    // 0042a5ae  837de000               +cmp dword ptr [ebp - 0x20], 0
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
    // 0042a5b2  8d7c1fd0               -lea edi, [edi + ebx - 0x30]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(-48) /* -0x30 */ + cpu.ebx * 1);
    // 0042a5b6  7405                   -je 0x42a5bd
    if (cpu.flags.zf)
    {
        goto L_0x0042a5bd;
    }
    // 0042a5b8  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a5bb  7424                   -je 0x42a5e1
    if (cpu.flags.zf)
    {
        goto L_0x0042a5e1;
    }
L_0x0042a5bd:
    // 0042a5bd  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a5c0  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a5c3  e858010000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a5c8  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a5ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a5cb  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a5ce  e95cffffff             -jmp 0x42a52f
    goto L_0x0042a52f;
L_0x0042a5d3:
    // 0042a5d3  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a5d6  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0042a5d9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a5da  e85b010000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a5df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a5e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042a5e1:
    // 0042a5e1  807de900               +cmp byte ptr [ebp - 0x17], 0
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
    // 0042a5e5  7402                   -je 0x42a5e9
    if (cpu.flags.zf)
    {
        goto L_0x0042a5e9;
    }
    // 0042a5e7  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
L_0x0042a5e9:
    // 0042a5e9  83fe46                 +cmp esi, 0x46
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
    // 0042a5ec  7504                   -jne 0x42a5f2
    if (!cpu.flags.zf)
    {
        goto L_0x0042a5f2;
    }
    // 0042a5ee  8365e400               -and dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042a5f2:
    // 0042a5f2  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 0042a5f6  0f84ce000000           -je 0x42a6ca
    if (cpu.flags.zf)
    {
        goto L_0x0042a6ca;
    }
    // 0042a5fc  807df200               +cmp byte ptr [ebp - 0xe], 0
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
    // 0042a600  7529                   -jne 0x42a62b
    if (!cpu.flags.zf)
    {
        goto L_0x0042a62b;
    }
    // 0042a602  ff45cc                 -inc dword ptr [ebp - 0x34]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */))++;
L_0x0042a605:
    // 0042a605  837dd000               +cmp dword ptr [ebp - 0x30], 0
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
    // 0042a609  7410                   -je 0x42a61b
    if (cpu.flags.zf)
    {
        goto L_0x0042a61b;
    }
    // 0042a60b  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0042a60e  8b4dd8                 -mov ecx, dword ptr [ebp - 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0042a611  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0042a613  8b4ddc                 -mov ecx, dword ptr [ebp - 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042a616  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0042a619  eb10                   -jmp 0x42a62b
    goto L_0x0042a62b;
L_0x0042a61b:
    // 0042a61b  807df300               +cmp byte ptr [ebp - 0xd], 0
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
    // 0042a61f  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0042a622  7404                   -je 0x42a628
    if (cpu.flags.zf)
    {
        goto L_0x0042a628;
    }
    // 0042a624  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0042a626  eb03                   -jmp 0x42a62b
    goto L_0x0042a62b;
L_0x0042a628:
    // 0042a628  668938                 -mov word ptr [eax], di
    app->getMemory<x86::reg16>(cpu.eax) = cpu.di;
L_0x0042a62b:
    // 0042a62b  fe45eb                 +inc byte ptr [ebp - 0x15]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */);
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0042a62e  ff450c                 +inc dword ptr [ebp + 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042a631  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042a634  eb42                   -jmp 0x42a678
    goto L_0x0042a678;
L_0x0042a636:
    // 0042a636  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a639  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a63a  e8e1000000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a63f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a641  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a642  0fb606                 -movzx eax, byte ptr [esi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0042a645  46                     -inc esi
    (cpu.esi)++;
    // 0042a646  3bc3                   +cmp eax, ebx
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
    // 0042a648  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042a64b  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0042a64e  7555                   -jne 0x42a6a5
    if (!cpu.flags.zf)
    {
        goto L_0x0042a6a5;
    }
    // 0042a650  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a656  0fb6c3                 -movzx eax, bl
    cpu.eax = x86::reg32(cpu.bl);
    // 0042a659  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0042a65e  7418                   -je 0x42a678
    if (cpu.flags.zf)
    {
        goto L_0x0042a678;
    }
    // 0042a660  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042a663  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a664  e8b7000000             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a669  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a66a  0fb60e                 -movzx ecx, byte ptr [esi]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0042a66d  46                     -inc esi
    (cpu.esi)++;
    // 0042a66e  3bc8                   +cmp ecx, eax
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
    // 0042a670  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0042a673  753e                   -jne 0x42a6b3
    if (!cpu.flags.zf)
    {
        goto L_0x0042a6b3;
    }
    // 0042a675  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
L_0x0042a678:
    // 0042a678  837decff               +cmp dword ptr [ebp - 0x14], -1
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
    // 0042a67c  7510                   -jne 0x42a68e
    if (!cpu.flags.zf)
    {
        goto L_0x0042a68e;
    }
    // 0042a67e  803e25                 +cmp byte ptr [esi], 0x25
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
    // 0042a681  754d                   -jne 0x42a6d0
    if (!cpu.flags.zf)
    {
        goto L_0x0042a6d0;
    }
    // 0042a683  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042a686  8078016e               +cmp byte ptr [eax + 1], 0x6e
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
    // 0042a68a  7544                   -jne 0x42a6d0
    if (!cpu.flags.zf)
    {
        goto L_0x0042a6d0;
    }
    // 0042a68c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0042a68e:
    // 0042a68e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042a690  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042a692  0f8556f6ffff           -jne 0x429cee
    if (!cpu.flags.zf)
    {
        goto L_0x00429cee;
    }
    // 0042a698  eb30                   -jmp 0x42a6ca
    goto L_0x0042a6ca;
L_0x0042a69a:
    // 0042a69a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a69d  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a6a0  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 0042a6a3  eb05                   -jmp 0x42a6aa
    goto L_0x0042a6aa;
L_0x0042a6a5:
    // 0042a6a5  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a6a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a6a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0042a6aa:
    // 0042a6aa  e88b000000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a6af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6b1  eb17                   -jmp 0x42a6ca
    goto L_0x0042a6ca;
L_0x0042a6b3:
    // 0042a6b3  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0042a6b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a6b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a6b8  e87d000000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a6bd  ff4dfc                 -dec dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))--;
    // 0042a6c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a6c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a6c2  e873000000             -call 0x42a73a
    cpu.esp -= 4;
    sub_42a73a(app, cpu);
    // 0042a6c7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042a6ca:
    // 0042a6ca  837decff               +cmp dword ptr [ebp - 0x14], -1
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
    // 0042a6ce  7511                   -jne 0x42a6e1
    if (!cpu.flags.zf)
    {
        goto L_0x0042a6e1;
    }
L_0x0042a6d0:
    // 0042a6d0  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0042a6d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a6d5  750d                   -jne 0x42a6e4
    if (!cpu.flags.zf)
    {
        goto L_0x0042a6e4;
    }
    // 0042a6d7  3845eb                 +cmp byte ptr [ebp - 0x15], al
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
    // 0042a6da  7508                   -jne 0x42a6e4
    if (!cpu.flags.zf)
    {
        goto L_0x0042a6e4;
    }
    // 0042a6dc  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042a6df  eb03                   -jmp 0x42a6e4
    goto L_0x0042a6e4;
L_0x0042a6e1:
    // 0042a6e1  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
L_0x0042a6e4:
    // 0042a6e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6e7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a6e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a6e9  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a6f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a6f1  7e10                   -jle 0x42a703
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a703;
    }
    // 0042a6f3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042a6f7  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042a6f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a6fa  e862150000             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042a6ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a700  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a701  eb0f                   -jmp 0x42a712
    goto L_0x0042a712;
L_0x0042a703:
    // 0042a703  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042a707  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042a70c  8a0470                 -mov al, byte ptr [eax + esi*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.esi * 2);
    // 0042a70f  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042a712:
    // 0042a712  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a714  7506                   -jne 0x42a71c
    if (!cpu.flags.zf)
    {
        goto L_0x0042a71c;
    }
    // 0042a716  83e6df                 -and esi, 0xffffffdf
    cpu.esi &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0042a719  83ee07                 -sub esi, 7
    (cpu.esi) -= x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x0042a71c:
    // 0042a71c  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042a71e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a71f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a720  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042a724  ff4a04                 +dec dword ptr [edx + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a727  7809                   -js 0x42a732
    if (cpu.flags.sf)
    {
        goto L_0x0042a732;
    }
    // 0042a729  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0042a72b  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0042a72e  41                     -inc ecx
    (cpu.ecx)++;
    // 0042a72f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0042a731  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a732:
    // 0042a732  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042a733  e8bdd4ffff             -call 0x427bf5
    cpu.esp -= 4;
    sub_427bf5(app, cpu);
    // 0042a738  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a739  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a73a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a73a  837c2404ff             +cmp dword ptr [esp + 4], -1
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
    // 0042a73f  740f                   -je 0x42a750
    if (cpu.flags.zf)
    {
        goto L_0x0042a750;
    }
    // 0042a741  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a745  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042a749  e8e1220000             -call 0x42ca2f
    cpu.esp -= 4;
    sub_42ca2f(app, cpu);
    // 0042a74e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a74f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042a750:
    // 0042a750  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a751(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a751  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a752  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042a756  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042a757:
    // 0042a757  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042a75b  ff06                   -inc dword ptr [esi]
    (app->getMemory<x86::reg32>(cpu.esi))++;
    // 0042a75d  e8beffffff             -call 0x42a720
    cpu.esp -= 4;
    sub_42a720(app, cpu);
    // 0042a762  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042a764  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a765  e872220000             -call 0x42c9dc
    cpu.esp -= 4;
    sub_42c9dc(app, cpu);
    // 0042a76a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a76b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a76d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a76e  75e7                   -jne 0x42a757
    if (!cpu.flags.zf)
    {
        goto L_0x0042a757;
    }
    // 0042a770  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042a772  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a773  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a774  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a775(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a775  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042a779  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042a77b  890de8534900           -mov dword ptr [0x4953e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.ecx;
    // 0042a781  b8a0d34300             -mov eax, 0x43d3a0
    cpu.eax = 4445088 /*0x43d3a0*/;
L_0x0042a786:
    // 0042a786  3b08                   +cmp ecx, dword ptr [eax]
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
    // 0042a788  7420                   -je 0x42a7aa
    if (cpu.flags.zf)
    {
        goto L_0x0042a7aa;
    }
    // 0042a78a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a78d  42                     -inc edx
    (cpu.edx)++;
    // 0042a78e  3d08d54300             +cmp eax, 0x43d508
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4445448 /*0x43d508*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a793  7cf1                   -jl 0x42a786
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042a786;
    }
    // 0042a795  83f913                 +cmp ecx, 0x13
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
    // 0042a798  721d                   -jb 0x42a7b7
    if (cpu.flags.cf)
    {
        goto L_0x0042a7b7;
    }
    // 0042a79a  83f924                 +cmp ecx, 0x24
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
    // 0042a79d  7718                   -ja 0x42a7b7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042a7b7;
    }
    // 0042a79f  c705e45349000d000000   -mov dword ptr [0x4953e4], 0xd
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 13 /*0xd*/;
    // 0042a7a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a7aa:
    // 0042a7aa  8b04d5a4d34300         -mov eax, dword ptr [edx*8 + 0x43d3a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445092) /* 0x43d3a4 */ + cpu.edx * 8);
    // 0042a7b1  a3e4534900             -mov dword ptr [0x4953e4], eax
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = cpu.eax;
    // 0042a7b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a7b7:
    // 0042a7b7  81f9bc000000           +cmp ecx, 0xbc
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
    // 0042a7bd  7212                   -jb 0x42a7d1
    if (cpu.flags.cf)
    {
        goto L_0x0042a7d1;
    }
    // 0042a7bf  81f9ca000000           +cmp ecx, 0xca
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
    // 0042a7c5  c705e453490008000000   -mov dword ptr [0x4953e4], 8
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 8 /*0x8*/;
    // 0042a7cf  760a                   -jbe 0x42a7db
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042a7db;
    }
L_0x0042a7d1:
    // 0042a7d1  c705e453490016000000   -mov dword ptr [0x4953e4], 0x16
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 22 /*0x16*/;
L_0x0042a7db:
    // 0042a7db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a7dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a7dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042a7dd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042a7df  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0042a7e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a7e3  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042a7e6  81eb6c070000           -sub ebx, 0x76c
    (cpu.ebx) -= x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 0042a7ec  83fb46                 +cmp ebx, 0x46
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
    // 0042a7ef  0f8ca3000000           -jl 0x42a898
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042a898;
    }
    // 0042a7f5  81fb8a000000           +cmp ebx, 0x8a
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
    // 0042a7fb  0f8f97000000           -jg 0x42a898
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042a898;
    }
    // 0042a801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a802  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a803  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042a806  8b34bd64d94300         -mov esi, dword ptr [edi*4 + 0x43d964]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4446564) /* 0x43d964 */ + cpu.edi * 4);
    // 0042a80d  037510                 -add esi, dword ptr [ebp + 0x10]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    // 0042a810  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 0042a813  7506                   -jne 0x42a81b
    if (!cpu.flags.zf)
    {
        goto L_0x0042a81b;
    }
    // 0042a815  83ff02                 +cmp edi, 2
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
    // 0042a818  7e01                   -jle 0x42a81b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a81b;
    }
    // 0042a81a  46                     -inc esi
    (cpu.esi)++;
L_0x0042a81b:
    // 0042a81b  e87d220000             -call 0x42ca9d
    cpu.esp -= 4;
    sub_42ca9d(app, cpu);
    // 0042a820  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042a822  8d4bff                 -lea ecx, [ebx - 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0042a825  69c06d010000           -imul eax, eax, 0x16d
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(365 /*0x16d*/)));
    // 0042a82b  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0042a82e  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042a830  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0042a833  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042a835  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0042a838  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0042a83a  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0042a83d  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0042a840  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042a843  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0042a846  8d0cc8                 -lea ecx, [eax + ecx*8]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ecx * 8);
    // 0042a849  6bc93c                 -imul ecx, ecx, 0x3c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042a84c  034d18                 -add ecx, dword ptr [ebp + 0x18]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0042a84f  6bc93c                 -imul ecx, ecx, 0x3c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042a852  030d80d84300           -add ecx, dword ptr [0x43d880]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */)));
    // 0042a858  4f                     -dec edi
    (cpu.edi)--;
    // 0042a859  837d2001               +cmp dword ptr [ebp + 0x20], 1
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
    // 0042a85d  897dec                 -mov dword ptr [ebp - 0x14], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edi;
    // 0042a860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a862  8d8c118081557c         -lea ecx, [ecx + edx + 0x7c558180]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(2085978496) /* 0x7c558180 */ + cpu.edx * 1);
    // 0042a869  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042a86c  7420                   -je 0x42a88e
    if (cpu.flags.zf)
    {
        goto L_0x0042a88e;
    }
    // 0042a86e  837d20ff               +cmp dword ptr [ebp + 0x20], -1
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
    // 0042a872  7520                   -jne 0x42a894
    if (!cpu.flags.zf)
    {
        goto L_0x0042a894;
    }
    // 0042a874  833d84d8430000         +cmp dword ptr [0x43d884], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446340) /* 0x43d884 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a87b  7417                   -je 0x42a894
    if (cpu.flags.zf)
    {
        goto L_0x0042a894;
    }
    // 0042a87d  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0042a880  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a881  e88a240000             -call 0x42cd10
    cpu.esp -= 4;
    sub_42cd10(app, cpu);
    // 0042a886  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a887  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042a88a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a88c  7406                   -je 0x42a894
    if (cpu.flags.zf)
    {
        goto L_0x0042a894;
    }
L_0x0042a88e:
    // 0042a88e  030d88d84300           +add ecx, dword ptr [0x43d888]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4446344) /* 0x43d888 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0042a894:
    // 0042a894  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042a896  eb03                   -jmp 0x42a89b
    goto L_0x0042a89b;
L_0x0042a898:
    // 0042a898  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042a89b:
    // 0042a89b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a89c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a89d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a89e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a89e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a89f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a8a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a8a1  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042a8a4  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042a8a6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042a8a8  b9005d4900             -mov ecx, 0x495d00
    cpu.ecx = 4807936 /*0x495d00*/;
L_0x0042a8ad:
    // 0042a8ad  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042a8af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a8b1  7437                   -je 0x42a8ea
    if (cpu.flags.zf)
    {
        goto L_0x0042a8ea;
    }
    // 0042a8b3  8d9000010000           -lea edx, [eax + 0x100]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
L_0x0042a8b9:
    // 0042a8b9  3bc2                   +cmp eax, edx
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
    // 0042a8bb  731c                   -jae 0x42a8d9
    if (!cpu.flags.cf)
    {
        goto L_0x0042a8d9;
    }
    // 0042a8bd  f6400401               +test byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0042a8c1  7405                   -je 0x42a8c8
    if (cpu.flags.zf)
    {
        goto L_0x0042a8c8;
    }
    // 0042a8c3  83c008                 +add eax, 8
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
    // 0042a8c6  ebf1                   -jmp 0x42a8b9
    goto L_0x0042a8b9;
L_0x0042a8c8:
    // 0042a8c8  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042a8cb  2b01                   -sub eax, dword ptr [ecx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0042a8cd  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0042a8d0  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042a8d2  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042a8d4  83fbff                 +cmp ebx, -1
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
    // 0042a8d7  7554                   -jne 0x42a92d
    if (!cpu.flags.zf)
    {
        goto L_0x0042a92d;
    }
L_0x0042a8d9:
    // 0042a8d9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a8dc  47                     -inc edi
    (cpu.edi)++;
    // 0042a8dd  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0042a8e0  81f9005e4900           +cmp ecx, 0x495e00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4808192 /*0x495e00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a8e6  7cc5                   -jl 0x42a8ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042a8ad;
    }
    // 0042a8e8  eb43                   -jmp 0x42a92d
    goto L_0x0042a92d;
L_0x0042a8ea:
    // 0042a8ea  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
    // 0042a8ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a8f0  e880a5ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042a8f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a8f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a8f8  7433                   -je 0x42a92d
    if (cpu.flags.zf)
    {
        goto L_0x0042a92d;
    }
    // 0042a8fa  8305005e490020         -add dword ptr [0x495e00], 0x20
    (app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0042a901  8d0cbd005d4900         -lea ecx, [edi*4 + 0x495d00]
    cpu.ecx = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.edi * 4);
    // 0042a908  8d9000010000           -lea edx, [eax + 0x100]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0042a90e  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0042a910:
    // 0042a910  3bc2                   +cmp eax, edx
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
    // 0042a912  7314                   -jae 0x42a928
    if (!cpu.flags.cf)
    {
        goto L_0x0042a928;
    }
    // 0042a914  80600400               -and byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042a918  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042a91b  c640050a               -mov byte ptr [eax + 5], 0xa
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 0042a91f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042a921  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a924  03d6                   +add edx, esi
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
    // 0042a926  ebe8                   -jmp 0x42a910
    goto L_0x0042a910;
L_0x0042a928:
    // 0042a928  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0042a92b  8bdf                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0042a92d:
    // 0042a92d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a92e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042a930  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a931  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a932  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a933(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a933  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042a937  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a938  3b05005e4900           +cmp eax, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a93e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a93f  7352                   -jae 0x42a993
    if (!cpu.flags.cf)
    {
        goto L_0x0042a993;
    }
    // 0042a941  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042a943  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a945  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0042a948  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042a94b  8d3c8d005d4900         -lea edi, [ecx*4 + 0x495d00]
    cpu.edi = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 0042a952  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0042a955  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042a957  833c31ff               +cmp dword ptr [ecx + esi], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a95b  7536                   -jne 0x42a993
    if (!cpu.flags.zf)
    {
        goto L_0x0042a993;
    }
    // 0042a95d  833d74d2430001         +cmp dword ptr [0x43d274], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4444788) /* 0x43d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a964  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a965  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042a969  751e                   -jne 0x42a989
    if (!cpu.flags.zf)
    {
        goto L_0x0042a989;
    }
    // 0042a96b  83e800                 +sub eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042a96e  7410                   -je 0x42a980
    if (cpu.flags.zf)
    {
        goto L_0x0042a980;
    }
    // 0042a970  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a971  7408                   -je 0x42a97b
    if (cpu.flags.zf)
    {
        goto L_0x0042a97b;
    }
    // 0042a973  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a974  7513                   -jne 0x42a989
    if (!cpu.flags.zf)
    {
        goto L_0x0042a989;
    }
    // 0042a976  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a977  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 0042a979  eb08                   -jmp 0x42a983
    goto L_0x0042a983;
L_0x0042a97b:
    // 0042a97b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a97c  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 0042a97e  eb03                   -jmp 0x42a983
    goto L_0x0042a983;
L_0x0042a980:
    // 0042a980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042a981  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
L_0x0042a983:
    // 0042a983  ff1500014300           -call dword ptr [0x430100]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391168) /* 0x430100 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042a989:
    // 0042a989  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042a98b  891c30                 -mov dword ptr [eax + esi], ebx
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1) = cpu.ebx;
    // 0042a98e  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042a990  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a991  eb14                   -jmp 0x42a9a7
    goto L_0x0042a9a7;
L_0x0042a993:
    // 0042a993  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042a99a  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 0042a9a4  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042a9a7:
    // 0042a9a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a9a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a9a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42a9aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a9aa  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042a9ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a9af  3b0d005e4900           +cmp ecx, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a9b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a9b6  7355                   -jae 0x42aa0d
    if (!cpu.flags.cf)
    {
        goto L_0x0042aa0d;
    }
    // 0042a9b8  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042a9ba  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042a9bc  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0042a9bf  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042a9c2  8d3c85005d4900         -lea edi, [eax*4 + 0x495d00]
    cpu.edi = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 0042a9c9  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0042a9cc  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042a9ce  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042a9d0  f6400401               +test byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0042a9d4  7437                   -je 0x42aa0d
    if (cpu.flags.zf)
    {
        goto L_0x0042aa0d;
    }
    // 0042a9d6  8338ff                 +cmp dword ptr [eax], -1
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
    // 0042a9d9  7432                   -je 0x42aa0d
    if (cpu.flags.zf)
    {
        goto L_0x0042aa0d;
    }
    // 0042a9db  833d74d2430001         +cmp dword ptr [0x43d274], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4444788) /* 0x43d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a9e2  751f                   -jne 0x42aa03
    if (!cpu.flags.zf)
    {
        goto L_0x0042aa03;
    }
    // 0042a9e4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a9e6  2bc8                   +sub ecx, eax
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
    // 0042a9e8  7410                   -je 0x42a9fa
    if (cpu.flags.zf)
    {
        goto L_0x0042a9fa;
    }
    // 0042a9ea  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a9eb  7408                   -je 0x42a9f5
    if (cpu.flags.zf)
    {
        goto L_0x0042a9f5;
    }
    // 0042a9ed  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042a9ee  7513                   -jne 0x42aa03
    if (!cpu.flags.zf)
    {
        goto L_0x0042aa03;
    }
    // 0042a9f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a9f1  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 0042a9f3  eb08                   -jmp 0x42a9fd
    goto L_0x0042a9fd;
L_0x0042a9f5:
    // 0042a9f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a9f6  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 0042a9f8  eb03                   -jmp 0x42a9fd
    goto L_0x0042a9fd;
L_0x0042a9fa:
    // 0042a9fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a9fb  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
L_0x0042a9fd:
    // 0042a9fd  ff1500014300           -call dword ptr [0x430100]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391168) /* 0x430100 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042aa03:
    // 0042aa03  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042aa05  830c30ff               -or dword ptr [eax + esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 1) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042aa09  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042aa0b  eb14                   -jmp 0x42aa21
    goto L_0x0042aa21;
L_0x0042aa0d:
    // 0042aa0d  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042aa14  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 0042aa1e  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042aa21:
    // 0042aa21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042aa22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042aa23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42aa24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042aa24  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042aa28  3b05005e4900           +cmp eax, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042aa2e  731c                   -jae 0x42aa4c
    if (!cpu.flags.cf)
    {
        goto L_0x0042aa4c;
    }
    // 0042aa30  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042aa32  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042aa35  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0042aa38  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 0042aa3f  f644c10401             +test byte ptr [ecx + eax*8 + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) & 1 /*0x1*/));
    // 0042aa44  8d04c1                 -lea eax, [ecx + eax*8]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 8);
    // 0042aa47  7403                   -je 0x42aa4c
    if (cpu.flags.zf)
    {
        goto L_0x0042aa4c;
    }
    // 0042aa49  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042aa4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042aa4c:
    // 0042aa4c  8325e853490000         -and dword ptr [0x4953e8], 0
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042aa53  c705e453490009000000   -mov dword ptr [0x4953e4], 9
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 9 /*0x9*/;
    // 0042aa5d  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042aa60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42aa61(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042aa61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042aa62  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042aa64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042aa65  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042aa68  e835010000             -call 0x42aba2
    cpu.esp -= 4;
    sub_42aba2(app, cpu);
    // 0042aa6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042aa6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042aa70  0f8420010000           -je 0x42ab96
    if (cpu.flags.zf)
    {
        goto L_0x0042ab96;
    }
    // 0042aa76  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042aa79  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042aa7b  0f8415010000           -je 0x42ab96
    if (cpu.flags.zf)
    {
        goto L_0x0042ab96;
    }
    // 0042aa81  83fb05                 +cmp ebx, 5
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
    // 0042aa84  750c                   -jne 0x42aa92
    if (!cpu.flags.zf)
    {
        goto L_0x0042aa92;
    }
    // 0042aa86  83600800               +and dword ptr [eax + 8], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0042aa8a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042aa8c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042aa8d  e90d010000             -jmp 0x42ab9f
    goto L_0x0042ab9f;
L_0x0042aa92:
    // 0042aa92  83fb01                 +cmp ebx, 1
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
    // 0042aa95  0f84f6000000           -je 0x42ab91
    if (cpu.flags.zf)
    {
        goto L_0x0042ab91;
    }
    // 0042aa9b  8b0d5c544900           -mov ecx, dword ptr [0x49545c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4805724) /* 0x49545c */);
    // 0042aaa1  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042aaa4  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042aaa7  890d5c544900           -mov dword ptr [0x49545c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4805724) /* 0x49545c */) = cpu.ecx;
    // 0042aaad  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042aab0  83f908                 +cmp ecx, 8
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
    // 0042aab3  0f85c8000000           -jne 0x42ab81
    if (!cpu.flags.zf)
    {
        goto L_0x0042ab81;
    }
    // 0042aab9  8b0d80d54300           -mov ecx, dword ptr [0x43d580]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445568) /* 0x43d580 */);
    // 0042aabf  8b1584d54300           -mov edx, dword ptr [0x43d584]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4445572) /* 0x43d584 */);
    // 0042aac5  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042aac7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042aac8  3bca                   +cmp ecx, edx
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
    // 0042aaca  7d15                   -jge 0x42aae1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042aae1;
    }
    // 0042aacc  8d3449                 -lea esi, [ecx + ecx*2]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042aacf  2bd1                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042aad1  8d34b510d54300         -lea esi, [esi*4 + 0x43d510]
    cpu.esi = x86::reg32(x86::reg32(4445456) /* 0x43d510 */ + cpu.esi * 4);
L_0x0042aad8:
    // 0042aad8  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042aadb  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042aade  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042aadf  75f7                   -jne 0x42aad8
    if (!cpu.flags.zf)
    {
        goto L_0x0042aad8;
    }
L_0x0042aae1:
    // 0042aae1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042aae3  8b358cd54300           -mov esi, dword ptr [0x43d58c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */);
    // 0042aae9  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 0042aaee  750c                   -jne 0x42aafc
    if (!cpu.flags.zf)
    {
        goto L_0x0042aafc;
    }
    // 0042aaf0  c7058cd5430083000000   -mov dword ptr [0x43d58c], 0x83
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 131 /*0x83*/;
    // 0042aafa  eb70                   -jmp 0x42ab6c
    goto L_0x0042ab6c;
L_0x0042aafc:
    // 0042aafc  3d900000c0             +cmp eax, 0xc0000090
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
    // 0042ab01  750c                   -jne 0x42ab0f
    if (!cpu.flags.zf)
    {
        goto L_0x0042ab0f;
    }
    // 0042ab03  c7058cd5430081000000   -mov dword ptr [0x43d58c], 0x81
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 129 /*0x81*/;
    // 0042ab0d  eb5d                   -jmp 0x42ab6c
    goto L_0x0042ab6c;
L_0x0042ab0f:
    // 0042ab0f  3d910000c0             +cmp eax, 0xc0000091
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
    // 0042ab14  750c                   -jne 0x42ab22
    if (!cpu.flags.zf)
    {
        goto L_0x0042ab22;
    }
    // 0042ab16  c7058cd5430084000000   -mov dword ptr [0x43d58c], 0x84
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 132 /*0x84*/;
    // 0042ab20  eb4a                   -jmp 0x42ab6c
    goto L_0x0042ab6c;
L_0x0042ab22:
    // 0042ab22  3d930000c0             +cmp eax, 0xc0000093
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
    // 0042ab27  750c                   -jne 0x42ab35
    if (!cpu.flags.zf)
    {
        goto L_0x0042ab35;
    }
    // 0042ab29  c7058cd5430085000000   -mov dword ptr [0x43d58c], 0x85
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 133 /*0x85*/;
    // 0042ab33  eb37                   -jmp 0x42ab6c
    goto L_0x0042ab6c;
L_0x0042ab35:
    // 0042ab35  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 0042ab3a  750c                   -jne 0x42ab48
    if (!cpu.flags.zf)
    {
        goto L_0x0042ab48;
    }
    // 0042ab3c  c7058cd5430082000000   -mov dword ptr [0x43d58c], 0x82
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 130 /*0x82*/;
    // 0042ab46  eb24                   -jmp 0x42ab6c
    goto L_0x0042ab6c;
L_0x0042ab48:
    // 0042ab48  3d8f0000c0             +cmp eax, 0xc000008f
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
    // 0042ab4d  750c                   -jne 0x42ab5b
    if (!cpu.flags.zf)
    {
        goto L_0x0042ab5b;
    }
    // 0042ab4f  c7058cd5430086000000   -mov dword ptr [0x43d58c], 0x86
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 134 /*0x86*/;
    // 0042ab59  eb11                   -jmp 0x42ab6c
    goto L_0x0042ab6c;
L_0x0042ab5b:
    // 0042ab5b  3d920000c0             +cmp eax, 0xc0000092
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
    // 0042ab60  750a                   -jne 0x42ab6c
    if (!cpu.flags.zf)
    {
        goto L_0x0042ab6c;
    }
    // 0042ab62  c7058cd543008a000000   -mov dword ptr [0x43d58c], 0x8a
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = 138 /*0x8a*/;
L_0x0042ab6c:
    // 0042ab6c  ff358cd54300           -push dword ptr [0x43d58c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */);
    cpu.esp -= 4;
    // 0042ab72  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042ab74  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ab76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ab77  89358cd54300           -mov dword ptr [0x43d58c], esi
    app->getMemory<x86::reg32>(x86::reg32(4445580) /* 0x43d58c */) = cpu.esi;
    // 0042ab7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ab7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ab7f  eb08                   -jmp 0x42ab89
    goto L_0x0042ab89;
L_0x0042ab81:
    // 0042ab81  83600800               -and dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042ab85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042ab86  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ab88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ab89:
    // 0042ab89  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042ab8c  a35c544900             -mov dword ptr [0x49545c], eax
    app->getMemory<x86::reg32>(x86::reg32(4805724) /* 0x49545c */) = cpu.eax;
L_0x0042ab91:
    // 0042ab91  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042ab94  eb09                   -jmp 0x42ab9f
    goto L_0x0042ab9f;
L_0x0042ab96:
    // 0042ab96  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042ab99  ff1504014300           -call dword ptr [0x430104]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391172) /* 0x430104 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042ab9f:
    // 0042ab9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042aba0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042aba1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42aba2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042aba2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042aba6  8b0d88d54300           -mov ecx, dword ptr [0x43d588]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445576) /* 0x43d588 */);
    // 0042abac  391508d54300           +cmp dword ptr [0x43d508], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4445448) /* 0x43d508 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042abb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042abb3  b808d54300             -mov eax, 0x43d508
    cpu.eax = 4445448 /*0x43d508*/;
    // 0042abb8  7415                   -je 0x42abcf
    if (cpu.flags.zf)
    {
        goto L_0x0042abcf;
    }
    // 0042abba  8d3449                 -lea esi, [ecx + ecx*2]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042abbd  8d34b508d54300         -lea esi, [esi*4 + 0x43d508]
    cpu.esi = x86::reg32(x86::reg32(4445448) /* 0x43d508 */ + cpu.esi * 4);
L_0x0042abc4:
    // 0042abc4  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042abc7  3bc6                   +cmp eax, esi
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
    // 0042abc9  7304                   -jae 0x42abcf
    if (!cpu.flags.cf)
    {
        goto L_0x0042abcf;
    }
    // 0042abcb  3910                   +cmp dword ptr [eax], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042abcd  75f5                   -jne 0x42abc4
    if (!cpu.flags.zf)
    {
        goto L_0x0042abc4;
    }
L_0x0042abcf:
    // 0042abcf  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042abd2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042abd3  8d0c8d08d54300         -lea ecx, [ecx*4 + 0x43d508]
    cpu.ecx = x86::reg32(x86::reg32(4445448) /* 0x43d508 */ + cpu.ecx * 4);
    // 0042abda  3bc1                   +cmp eax, ecx
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
    // 0042abdc  7304                   -jae 0x42abe2
    if (!cpu.flags.cf)
    {
        goto L_0x0042abe2;
    }
    // 0042abde  3910                   +cmp dword ptr [eax], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042abe0  7402                   -je 0x42abe4
    if (cpu.flags.zf)
    {
        goto L_0x0042abe4;
    }
L_0x0042abe2:
    // 0042abe2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042abe4:
    // 0042abe4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42abe5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042abe5  833d085e490000         +cmp dword ptr [0x495e08], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4808200) /* 0x495e08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042abec  7505                   -jne 0x42abf3
    if (!cpu.flags.zf)
    {
        goto L_0x0042abf3;
    }
    // 0042abee  e80f280000             -call 0x42d402
    cpu.esp -= 4;
    sub_42d402(app, cpu);
L_0x0042abf3:
    // 0042abf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042abf4  8b35305e4900           -mov esi, dword ptr [0x495e30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4808240) /* 0x495e30 */);
    // 0042abfa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042abfc  3c22                   +cmp al, 0x22
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
    // 0042abfe  7525                   -jne 0x42ac25
    if (!cpu.flags.zf)
    {
        goto L_0x0042ac25;
    }
L_0x0042ac00:
    // 0042ac00  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042ac03  46                     -inc esi
    (cpu.esi)++;
    // 0042ac04  3c22                   +cmp al, 0x22
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
    // 0042ac06  7415                   -je 0x42ac1d
    if (cpu.flags.zf)
    {
        goto L_0x0042ac1d;
    }
    // 0042ac08  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042ac0a  7411                   -je 0x42ac1d
    if (cpu.flags.zf)
    {
        goto L_0x0042ac1d;
    }
    // 0042ac0c  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0042ac0f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ac10  e8e7230000             -call 0x42cffc
    cpu.esp -= 4;
    sub_42cffc(app, cpu);
    // 0042ac15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ac17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ac18  74e6                   -je 0x42ac00
    if (cpu.flags.zf)
    {
        goto L_0x0042ac00;
    }
    // 0042ac1a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042ac1b  ebe3                   -jmp 0x42ac00
    goto L_0x0042ac00;
L_0x0042ac1d:
    // 0042ac1d  803e22                 +cmp byte ptr [esi], 0x22
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
    // 0042ac20  750d                   -jne 0x42ac2f
    if (!cpu.flags.zf)
    {
        goto L_0x0042ac2f;
    }
L_0x0042ac22:
    // 0042ac22  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042ac23  eb0a                   -jmp 0x42ac2f
    goto L_0x0042ac2f;
L_0x0042ac25:
    // 0042ac25  3c20                   +cmp al, 0x20
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
    // 0042ac27  7606                   -jbe 0x42ac2f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042ac2f;
    }
L_0x0042ac29:
    // 0042ac29  46                     -inc esi
    (cpu.esi)++;
    // 0042ac2a  803e20                 +cmp byte ptr [esi], 0x20
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
    // 0042ac2d  77fa                   -ja 0x42ac29
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042ac29;
    }
L_0x0042ac2f:
    // 0042ac2f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042ac31  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042ac33  7404                   -je 0x42ac39
    if (cpu.flags.zf)
    {
        goto L_0x0042ac39;
    }
    // 0042ac35  3c20                   +cmp al, 0x20
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
    // 0042ac37  76e9                   -jbe 0x42ac22
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042ac22;
    }
L_0x0042ac39:
    // 0042ac39  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ac3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ac3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ac3d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ac3d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ac3e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042ac40  391d085e4900           +cmp dword ptr [0x495e08], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4808200) /* 0x495e08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ac46  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ac47  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ac48  7505                   -jne 0x42ac4f
    if (!cpu.flags.zf)
    {
        goto L_0x0042ac4f;
    }
    // 0042ac4a  e8b3270000             -call 0x42d402
    cpu.esp -= 4;
    sub_42d402(app, cpu);
L_0x0042ac4f:
    // 0042ac4f  8b35d0534900           -mov esi, dword ptr [0x4953d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    // 0042ac55  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0042ac57:
    // 0042ac57  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042ac59  3ac3                   +cmp al, bl
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
    // 0042ac5b  7412                   -je 0x42ac6f
    if (cpu.flags.zf)
    {
        goto L_0x0042ac6f;
    }
    // 0042ac5d  3c3d                   +cmp al, 0x3d
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
    // 0042ac5f  7401                   -je 0x42ac62
    if (cpu.flags.zf)
    {
        goto L_0x0042ac62;
    }
    // 0042ac61  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042ac62:
    // 0042ac62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ac63  e868d1ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042ac68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ac69  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0042ac6d  ebe8                   -jmp 0x42ac57
    goto L_0x0042ac57;
L_0x0042ac6f:
    // 0042ac6f  8d04bd04000000         -lea eax, [edi*4 + 4]
    cpu.eax = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.edi * 4);
    // 0042ac76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ac77  e8f9a1ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042ac7c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ac7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ac7f  3bf3                   +cmp esi, ebx
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
    // 0042ac81  89350c544900           -mov dword ptr [0x49540c], esi
    app->getMemory<x86::reg32>(x86::reg32(4805644) /* 0x49540c */) = cpu.esi;
    // 0042ac87  7508                   -jne 0x42ac91
    if (!cpu.flags.zf)
    {
        goto L_0x0042ac91;
    }
    // 0042ac89  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042ac8b  e82ebcffff             -call 0x4268be
    cpu.esp -= 4;
    sub_4268be(app, cpu);
    // 0042ac90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ac91:
    // 0042ac91  8b3dd0534900           -mov edi, dword ptr [0x4953d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    // 0042ac97  381f                   +cmp byte ptr [edi], bl
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
    // 0042ac99  7439                   -je 0x42acd4
    if (cpu.flags.zf)
    {
        goto L_0x0042acd4;
    }
    // 0042ac9b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0042ac9c:
    // 0042ac9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ac9d  e82ed1ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042aca2  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042aca4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042aca5  45                     -inc ebp
    (cpu.ebp)++;
    // 0042aca6  803f3d                 +cmp byte ptr [edi], 0x3d
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
    // 0042aca9  7422                   -je 0x42accd
    if (cpu.flags.zf)
    {
        goto L_0x0042accd;
    }
    // 0042acab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042acac  e8c4a1ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042acb1  3bc3                   +cmp eax, ebx
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
    // 0042acb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042acb4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0042acb6  7508                   -jne 0x42acc0
    if (!cpu.flags.zf)
    {
        goto L_0x0042acc0;
    }
    // 0042acb8  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042acba  e8ffbbffff             -call 0x4268be
    cpu.esp -= 4;
    sub_4268be(app, cpu);
    // 0042acbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042acc0:
    // 0042acc0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042acc1  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0042acc3  e8c8140000             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042acc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042acc9  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042accc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042accd:
    // 0042accd  03fd                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0042accf  381f                   +cmp byte ptr [edi], bl
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
    // 0042acd1  75c9                   -jne 0x42ac9c
    if (!cpu.flags.zf)
    {
        goto L_0x0042ac9c;
    }
    // 0042acd3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042acd4:
    // 0042acd4  ff35d0534900           -push dword ptr [0x4953d0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    cpu.esp -= 4;
    // 0042acda  e867a1ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042acdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ace0  891dd0534900           -mov dword ptr [0x4953d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */) = cpu.ebx;
    // 0042ace6  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0042ace8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ace9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042acea  c705045e490001000000   -mov dword ptr [0x495e04], 1
    app->getMemory<x86::reg32>(x86::reg32(4808196) /* 0x495e04 */) = 1 /*0x1*/;
    // 0042acf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042acf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42acf6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042acf6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042acf7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042acf9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042acfa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042acfb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042acfc  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042acfe  391d085e4900           +cmp dword ptr [0x495e08], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4808200) /* 0x495e08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ad04  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ad05  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ad06  7505                   -jne 0x42ad0d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ad0d;
    }
    // 0042ad08  e8f5260000             -call 0x42d402
    cpu.esp -= 4;
    sub_42d402(app, cpu);
L_0x0042ad0d:
    // 0042ad0d  be60544900             -mov esi, 0x495460
    cpu.esi = 4805728 /*0x495460*/;
    // 0042ad12  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0042ad17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ad18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ad19  ff1508014300           -call dword ptr [0x430108]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391176) /* 0x430108 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ad1f  a1305e4900             -mov eax, dword ptr [0x495e30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4808240) /* 0x495e30 */);
    // 0042ad24  89351c544900           -mov dword ptr [0x49541c], esi
    app->getMemory<x86::reg32>(x86::reg32(4805660) /* 0x49541c */) = cpu.esi;
    // 0042ad2a  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0042ad2c  3818                   +cmp byte ptr [eax], bl
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
    // 0042ad2e  7402                   -je 0x42ad32
    if (cpu.flags.zf)
    {
        goto L_0x0042ad32;
    }
    // 0042ad30  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0042ad32:
    // 0042ad32  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042ad35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ad36  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042ad39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ad3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ad3b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ad3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ad3d  e84d000000             -call 0x42ad8f
    cpu.esp -= 4;
    sub_42ad8f(app, cpu);
    // 0042ad42  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042ad45  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042ad48  8d0488                 -lea eax, [eax + ecx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 0042ad4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ad4c  e824a1ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042ad51  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ad53  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042ad56  3bf3                   +cmp esi, ebx
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
    // 0042ad58  7508                   -jne 0x42ad62
    if (!cpu.flags.zf)
    {
        goto L_0x0042ad62;
    }
    // 0042ad5a  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042ad5c  e85dbbffff             -call 0x4268be
    cpu.esp -= 4;
    sub_4268be(app, cpu);
    // 0042ad61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ad62:
    // 0042ad62  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042ad65  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ad66  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042ad69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ad6a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042ad6d  8d0486                 -lea eax, [esi + eax*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.eax * 4);
    // 0042ad70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ad71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ad72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ad73  e817000000             -call 0x42ad8f
    cpu.esp -= 4;
    sub_42ad8f(app, cpu);
    // 0042ad78  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042ad7b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042ad7e  48                     -dec eax
    (cpu.eax)--;
    // 0042ad7f  893504544900           -mov dword ptr [0x495404], esi
    app->getMemory<x86::reg32>(x86::reg32(4805636) /* 0x495404 */) = cpu.esi;
    // 0042ad85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ad86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ad87  a300544900             -mov dword ptr [0x495400], eax
    app->getMemory<x86::reg32>(x86::reg32(4805632) /* 0x495400 */) = cpu.eax;
    // 0042ad8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ad8d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ad8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ad8f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ad8f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ad90  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042ad92  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0042ad95  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042ad98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ad99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ad9a  832100                 -and dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042ad9d  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042ada0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ada1  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042ada4  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0042adaa  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042adad  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042adaf  7408                   -je 0x42adb9
    if (cpu.flags.zf)
    {
        goto L_0x0042adb9;
    }
    // 0042adb1  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0042adb3  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042adb6  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0042adb9:
    // 0042adb9  803822                 +cmp byte ptr [eax], 0x22
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
    // 0042adbc  7544                   -jne 0x42ae02
    if (!cpu.flags.zf)
    {
        goto L_0x0042ae02;
    }
L_0x0042adbe:
    // 0042adbe  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042adc1  40                     -inc eax
    (cpu.eax)++;
    // 0042adc2  80fa22                 +cmp dl, 0x22
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
    // 0042adc5  7429                   -je 0x42adf0
    if (cpu.flags.zf)
    {
        goto L_0x0042adf0;
    }
    // 0042adc7  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042adc9  7425                   -je 0x42adf0
    if (cpu.flags.zf)
    {
        goto L_0x0042adf0;
    }
    // 0042adcb  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 0042adce  f682e15b490004         +test byte ptr [edx + 0x495be1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4807649) /* 0x495be1 */) & 4 /*0x4*/));
    // 0042add5  740c                   -je 0x42ade3
    if (cpu.flags.zf)
    {
        goto L_0x0042ade3;
    }
    // 0042add7  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 0042add9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042addb  7406                   -je 0x42ade3
    if (cpu.flags.zf)
    {
        goto L_0x0042ade3;
    }
    // 0042addd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042addf  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042ade1  46                     -inc esi
    (cpu.esi)++;
    // 0042ade2  40                     -inc eax
    (cpu.eax)++;
L_0x0042ade3:
    // 0042ade3  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 0042ade5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ade7  74d5                   -je 0x42adbe
    if (cpu.flags.zf)
    {
        goto L_0x0042adbe;
    }
    // 0042ade9  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042adeb  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042aded  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042adee  ebce                   -jmp 0x42adbe
    goto L_0x0042adbe;
L_0x0042adf0:
    // 0042adf0  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 0042adf2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042adf4  7404                   -je 0x42adfa
    if (cpu.flags.zf)
    {
        goto L_0x0042adfa;
    }
    // 0042adf6  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042adf9  46                     -inc esi
    (cpu.esi)++;
L_0x0042adfa:
    // 0042adfa  803822                 +cmp byte ptr [eax], 0x22
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
    // 0042adfd  7546                   -jne 0x42ae45
    if (!cpu.flags.zf)
    {
        goto L_0x0042ae45;
    }
    // 0042adff  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042ae00  eb43                   -jmp 0x42ae45
    goto L_0x0042ae45;
L_0x0042ae02:
    // 0042ae02  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 0042ae04  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ae06  7405                   -je 0x42ae0d
    if (cpu.flags.zf)
    {
        goto L_0x0042ae0d;
    }
    // 0042ae08  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042ae0a  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042ae0c  46                     -inc esi
    (cpu.esi)++;
L_0x0042ae0d:
    // 0042ae0d  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042ae0f  40                     -inc eax
    (cpu.eax)++;
    // 0042ae10  0fb6da                 -movzx ebx, dl
    cpu.ebx = x86::reg32(cpu.dl);
    // 0042ae13  f683e15b490004         +test byte ptr [ebx + 0x495be1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4807649) /* 0x495be1 */) & 4 /*0x4*/));
    // 0042ae1a  740c                   -je 0x42ae28
    if (cpu.flags.zf)
    {
        goto L_0x0042ae28;
    }
    // 0042ae1c  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 0042ae1e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ae20  7405                   -je 0x42ae27
    if (cpu.flags.zf)
    {
        goto L_0x0042ae27;
    }
    // 0042ae22  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042ae24  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0042ae26  46                     -inc esi
    (cpu.esi)++;
L_0x0042ae27:
    // 0042ae27  40                     -inc eax
    (cpu.eax)++;
L_0x0042ae28:
    // 0042ae28  80fa20                 +cmp dl, 0x20
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
    // 0042ae2b  7409                   -je 0x42ae36
    if (cpu.flags.zf)
    {
        goto L_0x0042ae36;
    }
    // 0042ae2d  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042ae2f  7409                   -je 0x42ae3a
    if (cpu.flags.zf)
    {
        goto L_0x0042ae3a;
    }
    // 0042ae31  80fa09                 +cmp dl, 9
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
    // 0042ae34  75cc                   -jne 0x42ae02
    if (!cpu.flags.zf)
    {
        goto L_0x0042ae02;
    }
L_0x0042ae36:
    // 0042ae36  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042ae38  7503                   -jne 0x42ae3d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ae3d;
    }
L_0x0042ae3a:
    // 0042ae3a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042ae3b  eb08                   -jmp 0x42ae45
    goto L_0x0042ae45;
L_0x0042ae3d:
    // 0042ae3d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ae3f  7404                   -je 0x42ae45
    if (cpu.flags.zf)
    {
        goto L_0x0042ae45;
    }
    // 0042ae41  8066ff00               -and byte ptr [esi - 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042ae45:
    // 0042ae45  83651800               -and dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042ae49:
    // 0042ae49  803800                 +cmp byte ptr [eax], 0
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
    // 0042ae4c  0f84e0000000           -je 0x42af32
    if (cpu.flags.zf)
    {
        goto L_0x0042af32;
    }
L_0x0042ae52:
    // 0042ae52  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042ae54  80fa20                 +cmp dl, 0x20
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
    // 0042ae57  7405                   -je 0x42ae5e
    if (cpu.flags.zf)
    {
        goto L_0x0042ae5e;
    }
    // 0042ae59  80fa09                 +cmp dl, 9
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
    // 0042ae5c  7503                   -jne 0x42ae61
    if (!cpu.flags.zf)
    {
        goto L_0x0042ae61;
    }
L_0x0042ae5e:
    // 0042ae5e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042ae5f  ebf1                   -jmp 0x42ae52
    goto L_0x0042ae52;
L_0x0042ae61:
    // 0042ae61  803800                 +cmp byte ptr [eax], 0
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
    // 0042ae64  0f84c8000000           -je 0x42af32
    if (cpu.flags.zf)
    {
        goto L_0x0042af32;
    }
    // 0042ae6a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042ae6c  7408                   -je 0x42ae76
    if (cpu.flags.zf)
    {
        goto L_0x0042ae76;
    }
    // 0042ae6e  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0042ae70  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ae73  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0042ae76:
    // 0042ae76  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042ae79  ff02                   -inc dword ptr [edx]
    (app->getMemory<x86::reg32>(cpu.edx))++;
L_0x0042ae7b:
    // 0042ae7b  c7450801000000         -mov dword ptr [ebp + 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0042ae82  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042ae84:
    // 0042ae84  80385c                 +cmp byte ptr [eax], 0x5c
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
    // 0042ae87  7504                   -jne 0x42ae8d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ae8d;
    }
    // 0042ae89  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042ae8a  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042ae8b  ebf7                   -jmp 0x42ae84
    goto L_0x0042ae84;
L_0x0042ae8d:
    // 0042ae8d  803822                 +cmp byte ptr [eax], 0x22
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
    // 0042ae90  752c                   -jne 0x42aebe
    if (!cpu.flags.zf)
    {
        goto L_0x0042aebe;
    }
    // 0042ae92  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0042ae95  7525                   -jne 0x42aebc
    if (!cpu.flags.zf)
    {
        goto L_0x0042aebc;
    }
    // 0042ae97  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042ae99  397d18                 +cmp dword ptr [ebp + 0x18], edi
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
    // 0042ae9c  740d                   -je 0x42aeab
    if (cpu.flags.zf)
    {
        goto L_0x0042aeab;
    }
    // 0042ae9e  80780122               +cmp byte ptr [eax + 1], 0x22
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
    // 0042aea2  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042aea5  7504                   -jne 0x42aeab
    if (!cpu.flags.zf)
    {
        goto L_0x0042aeab;
    }
    // 0042aea7  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042aea9  eb03                   -jmp 0x42aeae
    goto L_0x0042aeae;
L_0x0042aeab:
    // 0042aeab  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x0042aeae:
    // 0042aeae  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042aeb1  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042aeb3  395518                 +cmp dword ptr [ebp + 0x18], edx
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
    // 0042aeb6  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0042aeb9  895518                 -mov dword ptr [ebp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0042aebc:
    // 0042aebc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
L_0x0042aebe:
    // 0042aebe  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042aec0  4b                     -dec ebx
    (cpu.ebx)--;
    // 0042aec1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042aec3  740e                   -je 0x42aed3
    if (cpu.flags.zf)
    {
        goto L_0x0042aed3;
    }
    // 0042aec5  43                     -inc ebx
    (cpu.ebx)++;
L_0x0042aec6:
    // 0042aec6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042aec8  7404                   -je 0x42aece
    if (cpu.flags.zf)
    {
        goto L_0x0042aece;
    }
    // 0042aeca  c6065c                 -mov byte ptr [esi], 0x5c
    app->getMemory<x86::reg8>(cpu.esi) = 92 /*0x5c*/;
    // 0042aecd  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042aece:
    // 0042aece  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042aed0  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042aed1  75f3                   -jne 0x42aec6
    if (!cpu.flags.zf)
    {
        goto L_0x0042aec6;
    }
L_0x0042aed3:
    // 0042aed3  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042aed5  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042aed7  744a                   -je 0x42af23
    if (cpu.flags.zf)
    {
        goto L_0x0042af23;
    }
    // 0042aed9  837d1800               +cmp dword ptr [ebp + 0x18], 0
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
    // 0042aedd  750a                   -jne 0x42aee9
    if (!cpu.flags.zf)
    {
        goto L_0x0042aee9;
    }
    // 0042aedf  80fa20                 +cmp dl, 0x20
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
    // 0042aee2  743f                   -je 0x42af23
    if (cpu.flags.zf)
    {
        goto L_0x0042af23;
    }
    // 0042aee4  80fa09                 +cmp dl, 9
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
    // 0042aee7  743a                   -je 0x42af23
    if (cpu.flags.zf)
    {
        goto L_0x0042af23;
    }
L_0x0042aee9:
    // 0042aee9  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0042aeed  742e                   -je 0x42af1d
    if (cpu.flags.zf)
    {
        goto L_0x0042af1d;
    }
    // 0042aeef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042aef1  7419                   -je 0x42af0c
    if (cpu.flags.zf)
    {
        goto L_0x0042af0c;
    }
    // 0042aef3  0fb6da                 -movzx ebx, dl
    cpu.ebx = x86::reg32(cpu.dl);
    // 0042aef6  f683e15b490004         +test byte ptr [ebx + 0x495be1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4807649) /* 0x495be1 */) & 4 /*0x4*/));
    // 0042aefd  7406                   -je 0x42af05
    if (cpu.flags.zf)
    {
        goto L_0x0042af05;
    }
    // 0042aeff  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042af01  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042af02  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042af03  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042af05:
    // 0042af05  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042af07  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042af09  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042af0a  eb0f                   -jmp 0x42af1b
    goto L_0x0042af1b;
L_0x0042af0c:
    // 0042af0c  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 0042af0f  f682e15b490004         +test byte ptr [edx + 0x495be1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4807649) /* 0x495be1 */) & 4 /*0x4*/));
    // 0042af16  7403                   -je 0x42af1b
    if (cpu.flags.zf)
    {
        goto L_0x0042af1b;
    }
    // 0042af18  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042af19  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042af1b:
    // 0042af1b  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042af1d:
    // 0042af1d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042af1e  e958ffffff             -jmp 0x42ae7b
    goto L_0x0042ae7b;
L_0x0042af23:
    // 0042af23  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042af25  7404                   -je 0x42af2b
    if (cpu.flags.zf)
    {
        goto L_0x0042af2b;
    }
    // 0042af27  802600                 +and byte ptr [esi], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042af2a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0042af2b:
    // 0042af2b  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042af2d  e917ffffff             -jmp 0x42ae49
    goto L_0x0042ae49;
L_0x0042af32:
    // 0042af32  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042af34  7403                   -je 0x42af39
    if (cpu.flags.zf)
    {
        goto L_0x0042af39;
    }
    // 0042af36  832700                 -and dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042af39:
    // 0042af39  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042af3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042af3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042af3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042af3f  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 0042af41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042af42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42af43(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042af43  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042af44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042af45  a164554900             -mov eax, dword ptr [0x495564]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805988) /* 0x495564 */);
    // 0042af4a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042af4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042af4c  8b2d1c014300           -mov ebp, dword ptr [0x43011c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4391196) /* 0x43011c */);
    // 0042af52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042af53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042af54  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042af56  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042af58  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042af5a  3bc3                   +cmp eax, ebx
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
    // 0042af5c  7533                   -jne 0x42af91
    if (!cpu.flags.zf)
    {
        goto L_0x0042af91;
    }
    // 0042af5e  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042af60  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042af62  3bf3                   +cmp esi, ebx
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
    // 0042af64  740c                   -je 0x42af72
    if (cpu.flags.zf)
    {
        goto L_0x0042af72;
    }
    // 0042af66  c7056455490001000000   -mov dword ptr [0x495564], 1
    app->getMemory<x86::reg32>(x86::reg32(4805988) /* 0x495564 */) = 1 /*0x1*/;
    // 0042af70  eb28                   -jmp 0x42af9a
    goto L_0x0042af9a;
L_0x0042af72:
    // 0042af72  ff1518014300           -call dword ptr [0x430118]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391192) /* 0x430118 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042af78  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042af7a  3bfb                   +cmp edi, ebx
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
    // 0042af7c  0f84ea000000           -je 0x42b06c
    if (cpu.flags.zf)
    {
        goto L_0x0042b06c;
    }
    // 0042af82  c7056455490002000000   -mov dword ptr [0x495564], 2
    app->getMemory<x86::reg32>(x86::reg32(4805988) /* 0x495564 */) = 2 /*0x2*/;
    // 0042af8c  e98f000000             -jmp 0x42b020
    goto L_0x0042b020;
L_0x0042af91:
    // 0042af91  83f801                 +cmp eax, 1
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
    // 0042af94  0f8581000000           -jne 0x42b01b
    if (!cpu.flags.zf)
    {
        goto L_0x0042b01b;
    }
L_0x0042af9a:
    // 0042af9a  3bf3                   +cmp esi, ebx
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
    // 0042af9c  750c                   -jne 0x42afaa
    if (!cpu.flags.zf)
    {
        goto L_0x0042afaa;
    }
    // 0042af9e  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042afa0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042afa2  3bf3                   +cmp esi, ebx
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
    // 0042afa4  0f84c2000000           -je 0x42b06c
    if (cpu.flags.zf)
    {
        goto L_0x0042b06c;
    }
L_0x0042afaa:
    // 0042afaa  66391e                 +cmp word ptr [esi], bx
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
    // 0042afad  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042afaf  740e                   -je 0x42afbf
    if (cpu.flags.zf)
    {
        goto L_0x0042afbf;
    }
L_0x0042afb1:
    // 0042afb1  40                     -inc eax
    (cpu.eax)++;
    // 0042afb2  40                     -inc eax
    (cpu.eax)++;
    // 0042afb3  663918                 +cmp word ptr [eax], bx
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
    // 0042afb6  75f9                   -jne 0x42afb1
    if (!cpu.flags.zf)
    {
        goto L_0x0042afb1;
    }
    // 0042afb8  40                     -inc eax
    (cpu.eax)++;
    // 0042afb9  40                     -inc eax
    (cpu.eax)++;
    // 0042afba  663918                 +cmp word ptr [eax], bx
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
    // 0042afbd  75f2                   -jne 0x42afb1
    if (!cpu.flags.zf)
    {
        goto L_0x0042afb1;
    }
L_0x0042afbf:
    // 0042afbf  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0042afc1  8b3d14014300           -mov edi, dword ptr [0x430114]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4391188) /* 0x430114 */);
    // 0042afc7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0042afc9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afcb  40                     -inc eax
    (cpu.eax)++;
    // 0042afcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afcd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042afcf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042afd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afd1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afd2  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0042afd6  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042afd8  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042afda  3beb                   +cmp ebp, ebx
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
    // 0042afdc  7432                   -je 0x42b010
    if (cpu.flags.zf)
    {
        goto L_0x0042b010;
    }
    // 0042afde  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042afdf  e8919effff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042afe4  3bc3                   +cmp eax, ebx
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
    // 0042afe6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042afe7  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042afeb  7423                   -je 0x42b010
    if (cpu.flags.zf)
    {
        goto L_0x0042b010;
    }
    // 0042afed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042afef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042aff0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042aff1  ff742424               -push dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 0042aff5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042aff6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042aff7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042aff8  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042affa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042affc  750e                   -jne 0x42b00c
    if (!cpu.flags.zf)
    {
        goto L_0x0042b00c;
    }
    // 0042affe  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0042b002  e83f9effff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042b007  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b008  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x0042b00c:
    // 0042b00c  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0042b010:
    // 0042b010  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b011  ff1510014300           -call dword ptr [0x430110]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391184) /* 0x430110 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b017  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042b019  eb53                   -jmp 0x42b06e
    goto L_0x0042b06e;
L_0x0042b01b:
    // 0042b01b  83f802                 +cmp eax, 2
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
    // 0042b01e  754c                   -jne 0x42b06c
    if (!cpu.flags.zf)
    {
        goto L_0x0042b06c;
    }
L_0x0042b020:
    // 0042b020  3bfb                   +cmp edi, ebx
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
    // 0042b022  750c                   -jne 0x42b030
    if (!cpu.flags.zf)
    {
        goto L_0x0042b030;
    }
    // 0042b024  ff1518014300           -call dword ptr [0x430118]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391192) /* 0x430118 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b02a  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042b02c  3bfb                   +cmp edi, ebx
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
    // 0042b02e  743c                   -je 0x42b06c
    if (cpu.flags.zf)
    {
        goto L_0x0042b06c;
    }
L_0x0042b030:
    // 0042b030  381f                   +cmp byte ptr [edi], bl
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
    // 0042b032  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042b034  740a                   -je 0x42b040
    if (cpu.flags.zf)
    {
        goto L_0x0042b040;
    }
L_0x0042b036:
    // 0042b036  40                     -inc eax
    (cpu.eax)++;
    // 0042b037  3818                   +cmp byte ptr [eax], bl
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
    // 0042b039  75fb                   -jne 0x42b036
    if (!cpu.flags.zf)
    {
        goto L_0x0042b036;
    }
    // 0042b03b  40                     -inc eax
    (cpu.eax)++;
    // 0042b03c  3818                   +cmp byte ptr [eax], bl
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
    // 0042b03e  75f6                   -jne 0x42b036
    if (!cpu.flags.zf)
    {
        goto L_0x0042b036;
    }
L_0x0042b040:
    // 0042b040  2bc7                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0042b042  40                     -inc eax
    (cpu.eax)++;
    // 0042b043  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042b045  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b046  e82a9effff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042b04b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042b04d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b04e  3bf3                   +cmp esi, ebx
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
    // 0042b050  7504                   -jne 0x42b056
    if (!cpu.flags.zf)
    {
        goto L_0x0042b056;
    }
    // 0042b052  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0042b054  eb0b                   -jmp 0x42b061
    goto L_0x0042b061;
L_0x0042b056:
    // 0042b056  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b057  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b058  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b059  e862c8ffff             -call 0x4278c0
    cpu.esp -= 4;
    sub_4278c0(app, cpu);
    // 0042b05e  83c40c                 +add esp, 0xc
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
L_0x0042b061:
    // 0042b061  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b062  ff150c014300           -call dword ptr [0x43010c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391180) /* 0x43010c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b068  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042b06a  eb02                   -jmp 0x42b06e
    goto L_0x0042b06e;
L_0x0042b06c:
    // 0042b06c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042b06e:
    // 0042b06e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b06f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b070  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b071  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b072  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b073  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b074  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b075(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b075  a1d8534900             -mov eax, dword ptr [0x4953d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805592) /* 0x4953d8 */);
    // 0042b07a  83f801                 +cmp eax, 1
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
    // 0042b07d  740d                   -je 0x42b08c
    if (cpu.flags.zf)
    {
        goto L_0x0042b08c;
    }
    // 0042b07f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b081  752a                   -jne 0x42b0ad
    if (!cpu.flags.zf)
    {
        goto L_0x0042b0ad;
    }
    // 0042b083  833d74d2430001         +cmp dword ptr [0x43d274], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4444788) /* 0x43d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b08a  7521                   -jne 0x42b0ad
    if (!cpu.flags.zf)
    {
        goto L_0x0042b0ad;
    }
L_0x0042b08c:
    // 0042b08c  68fc000000             -push 0xfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 252 /*0xfc*/;
    cpu.esp -= 4;
    // 0042b091  e818000000             -call 0x42b0ae
    cpu.esp -= 4;
    sub_42b0ae(app, cpu);
    // 0042b096  a168554900             -mov eax, dword ptr [0x495568]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805992) /* 0x495568 */);
    // 0042b09b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b09c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b09e  7402                   -je 0x42b0a2
    if (cpu.flags.zf)
    {
        goto L_0x0042b0a2;
    }
    // 0042b0a0  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042b0a2:
    // 0042b0a2  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 0042b0a7  e802000000             -call 0x42b0ae
    cpu.esp -= 4;
    sub_42b0ae(app, cpu);
    // 0042b0ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042b0ad:
    // 0042b0ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b0ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b0ae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b0af  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042b0b1  81eca4010000           -sub esp, 0x1a4
    (cpu.esp) -= x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 0042b0b7  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b0ba  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b0bc  b890d54300             -mov eax, 0x43d590
    cpu.eax = 4445584 /*0x43d590*/;
L_0x0042b0c1:
    // 0042b0c1  3b10                   +cmp edx, dword ptr [eax]
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
    // 0042b0c3  740b                   -je 0x42b0d0
    if (cpu.flags.zf)
    {
        goto L_0x0042b0d0;
    }
    // 0042b0c5  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042b0c8  41                     -inc ecx
    (cpu.ecx)++;
    // 0042b0c9  3d20d64300             +cmp eax, 0x43d620
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4445728 /*0x43d620*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b0ce  7cf1                   -jl 0x42b0c1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042b0c1;
    }
L_0x0042b0d0:
    // 0042b0d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b0d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042b0d3  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0042b0d6  3b9690d54300           +cmp edx, dword ptr [esi + 0x43d590]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4445584) /* 0x43d590 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b0dc  0f851c010000           -jne 0x42b1fe
    if (!cpu.flags.zf)
    {
        goto L_0x0042b1fe;
    }
    // 0042b0e2  a1d8534900             -mov eax, dword ptr [0x4953d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805592) /* 0x4953d8 */);
    // 0042b0e7  83f801                 +cmp eax, 1
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
    // 0042b0ea  0f84e8000000           -je 0x42b1d8
    if (cpu.flags.zf)
    {
        goto L_0x0042b1d8;
    }
    // 0042b0f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b0f2  750d                   -jne 0x42b101
    if (!cpu.flags.zf)
    {
        goto L_0x0042b101;
    }
    // 0042b0f4  833d74d2430001         +cmp dword ptr [0x43d274], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4444788) /* 0x43d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b0fb  0f84d7000000           -je 0x42b1d8
    if (cpu.flags.zf)
    {
        goto L_0x0042b1d8;
    }
L_0x0042b101:
    // 0042b101  81fafc000000           +cmp edx, 0xfc
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
    // 0042b107  0f84f1000000           -je 0x42b1fe
    if (cpu.flags.zf)
    {
        goto L_0x0042b1fe;
    }
    // 0042b10d  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 0042b113  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0042b118  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b119  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042b11b  ff1508014300           -call dword ptr [0x430108]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391176) /* 0x430108 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b123  7513                   -jne 0x42b138
    if (!cpu.flags.zf)
    {
        goto L_0x0042b138;
    }
    // 0042b125  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 0042b12b  68040e4300             -push 0x430e04
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394500 /*0x430e04*/;
    cpu.esp -= 4;
    // 0042b130  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b131  e85a100000             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042b136  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b137  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042b138:
    // 0042b138  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 0042b13e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b13f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b140  8dbd5cfeffff           -lea edi, [ebp - 0x1a4]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 0042b146  e885ccffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042b14b  40                     -inc eax
    (cpu.eax)++;
    // 0042b14c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b14d  83f83c                 +cmp eax, 0x3c
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
    // 0042b150  7629                   -jbe 0x42b17b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042b17b;
    }
    // 0042b152  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 0042b158  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b159  e872ccffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042b15e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042b160  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 0042b166  83e83b                 -sub eax, 0x3b
    (cpu.eax) -= x86::reg32(x86::sreg32(59 /*0x3b*/));
    // 0042b169  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042b16b  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b16d  68000e4300             -push 0x430e00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394496 /*0x430e00*/;
    cpu.esp -= 4;
    // 0042b172  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b173  e858a4ffff             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0042b178  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042b17b:
    // 0042b17b  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 0042b181  68e40d4300             -push 0x430de4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394468 /*0x430de4*/;
    cpu.esp -= 4;
    // 0042b186  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b187  e804100000             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042b18c  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 0042b192  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b193  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b194  e807100000             -call 0x42c1a0
    cpu.esp -= 4;
    sub_42c1a0(app, cpu);
    // 0042b199  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 0042b19f  68e00d4300             -push 0x430de0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394464 /*0x430de0*/;
    cpu.esp -= 4;
    // 0042b1a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b1a5  e8f60f0000             -call 0x42c1a0
    cpu.esp -= 4;
    sub_42c1a0(app, cpu);
    // 0042b1aa  ffb694d54300           -push dword ptr [esi + 0x43d594]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4445588) /* 0x43d594 */);
    cpu.esp -= 4;
    // 0042b1b0  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 0042b1b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b1b7  e8e40f0000             -call 0x42c1a0
    cpu.esp -= 4;
    sub_42c1a0(app, cpu);
    // 0042b1bc  6810200100             -push 0x12010
    app->getMemory<x86::reg32>(cpu.esp-4) = 73744 /*0x12010*/;
    cpu.esp -= 4;
    // 0042b1c1  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 0042b1c7  68b80d4300             -push 0x430db8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394424 /*0x430db8*/;
    cpu.esp -= 4;
    // 0042b1cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b1cd  e84c220000             -call 0x42d41e
    cpu.esp -= 4;
    sub_42d41e(app, cpu);
    // 0042b1d2  83c42c                 +add esp, 0x2c
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
    // 0042b1d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b1d6  eb26                   -jmp 0x42b1fe
    goto L_0x0042b1fe;
L_0x0042b1d8:
    // 0042b1d8  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b1db  8db694d54300           -lea esi, [esi + 0x43d594]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4445588) /* 0x43d594 */);
    // 0042b1e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042b1e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b1e4  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0042b1e6  e8e5cbffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042b1eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b1ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b1ed  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0042b1ef  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 0042b1f1  ff15ec004300           -call dword ptr [0x4300ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391148) /* 0x4300ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b1f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b1f8  ff15dc004300           -call dword ptr [0x4300dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391132) /* 0x4300dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042b1fe:
    // 0042b1fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b1ff  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b210  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b214  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042b218  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042b21a  7447                   -je 0x42b263
    if (cpu.flags.zf)
    {
        goto L_0x0042b263;
    }
    // 0042b21c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b21e  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042b222  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b223  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042b225  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b228  722d                   -jb 0x42b257
    if (cpu.flags.cf)
    {
        goto L_0x0042b257;
    }
    // 0042b22a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0042b22c  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0042b22f  7408                   -je 0x42b239
    if (cpu.flags.zf)
    {
        goto L_0x0042b239;
    }
    // 0042b231  2bd1                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0042b233:
    // 0042b233  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b235  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042b236  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042b237  75fa                   -jne 0x42b233
    if (!cpu.flags.zf)
    {
        goto L_0x0042b233;
    }
L_0x0042b239:
    // 0042b239  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042b23b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0042b23e  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b240  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042b242  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0042b245  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b247  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042b249  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b24c  c1e902                 +shr ecx, 2
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
    // 0042b24f  7406                   -je 0x42b257
    if (cpu.flags.zf)
    {
        goto L_0x0042b257;
    }
    // 0042b251  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042b253  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042b255  7406                   -je 0x42b25d
    if (cpu.flags.zf)
    {
        goto L_0x0042b25d;
    }
L_0x0042b257:
    // 0042b257  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b259  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042b25a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042b25b  75fa                   -jne 0x42b257
    if (!cpu.flags.zf)
    {
        goto L_0x0042b257;
    }
L_0x0042b25d:
    // 0042b25d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042b261  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b262  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b263:
    // 0042b263  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042b267  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0042b270  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b271  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042b273  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b274  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b275  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042b278  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042b27b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b27e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042b280  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042b282  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042b284  3bfe                   +cmp edi, esi
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
    // 0042b286  7608                   -jbe 0x42b290
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042b290;
    }
    // 0042b288  3bf8                   +cmp edi, eax
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
    // 0042b28a  0f8278010000           -jb 0x42b408
    if (cpu.flags.cf)
    {
        goto L_0x0042b408;
    }
L_0x0042b290:
    // 0042b290  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0042b296  7514                   -jne 0x42b2ac
    if (!cpu.flags.zf)
    {
        goto L_0x0042b2ac;
    }
    // 0042b298  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b29b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b29e  83f908                 +cmp ecx, 8
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
    // 0042b2a1  7229                   -jb 0x42b2cc
    if (cpu.flags.cf)
    {
        goto L_0x0042b2cc;
    }
    // 0042b2a3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b2a5  ff2495b8b34200         -jmp dword ptr [edx*4 + 0x42b3b8]
    cpu.ip = app->getMemory<x86::reg32>(4371384 + cpu.edx * 4); goto dynamic_jump;
L_0x0042b2ac:
    // 0042b2ac  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042b2ae  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0042b2b3  83e904                 +sub ecx, 4
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
    // 0042b2b6  720c                   -jb 0x42b2c4
    if (cpu.flags.cf)
    {
        goto L_0x0042b2c4;
    }
    // 0042b2b8  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b2bb  03c8                   +add ecx, eax
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
    // 0042b2bd  ff2485d0b24200         -jmp dword ptr [eax*4 + 0x42b2d0]
    cpu.ip = app->getMemory<x86::reg32>(4371152 + cpu.eax * 4); goto dynamic_jump;
L_0x0042b2c4:
    // 0042b2c4  ff248dc8b34200         -jmp dword ptr [ecx*4 + 0x42b3c8]
    cpu.ip = app->getMemory<x86::reg32>(4371400 + cpu.ecx * 4); goto dynamic_jump;
L_0x0042b2cc:
    // 0042b2cc  ff248d4cb34200         -jmp dword ptr [ecx*4 + 0x42b34c]
    cpu.ip = app->getMemory<x86::reg32>(4371276 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0042b2e0:
    // 0042b2e0  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b2e2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042b2e4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b2e6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042b2e9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042b2ec  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0042b2ef  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b2f2  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0042b2f5  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b2f8  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b2fb  83f908                 +cmp ecx, 8
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
    // 0042b2fe  72cc                   -jb 0x42b2cc
    if (cpu.flags.cf)
    {
        goto L_0x0042b2cc;
    }
    // 0042b300  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b302  ff2495b8b34200         -jmp dword ptr [edx*4 + 0x42b3b8]
    cpu.ip = app->getMemory<x86::reg32>(4371384 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b30c:
    // 0042b30c  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b30e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042b310  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b312  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042b315  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b318  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042b31b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042b31e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042b321  83f908                 +cmp ecx, 8
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
    // 0042b324  72a6                   -jb 0x42b2cc
    if (cpu.flags.cf)
    {
        goto L_0x0042b2cc;
    }
    // 0042b326  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b328  ff2495b8b34200         -jmp dword ptr [edx*4 + 0x42b3b8]
    cpu.ip = app->getMemory<x86::reg32>(4371384 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b330:
    // 0042b330  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b332  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042b334  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b336  46                     -inc esi
    (cpu.esi)++;
    // 0042b337  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b33a  47                     -inc edi
    (cpu.edi)++;
    // 0042b33b  83f908                 +cmp ecx, 8
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
    // 0042b33e  728c                   -jb 0x42b2cc
    if (cpu.flags.cf)
    {
        goto L_0x0042b2cc;
    }
    // 0042b340  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b342  ff2495b8b34200         -jmp dword ptr [edx*4 + 0x42b3b8]
    cpu.ip = app->getMemory<x86::reg32>(4371384 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b36c:
    // 0042b36c  8b448ee4               -mov eax, dword ptr [esi + ecx*4 - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4);
    // 0042b370  89448fe4               -mov dword ptr [edi + ecx*4 - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b374:
    // 0042b374  8b448ee8               -mov eax, dword ptr [esi + ecx*4 - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4);
    // 0042b378  89448fe8               -mov dword ptr [edi + ecx*4 - 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b37c:
    // 0042b37c  8b448eec               -mov eax, dword ptr [esi + ecx*4 - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4);
    // 0042b380  89448fec               -mov dword ptr [edi + ecx*4 - 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b384:
    // 0042b384  8b448ef0               -mov eax, dword ptr [esi + ecx*4 - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4);
    // 0042b388  89448ff0               -mov dword ptr [edi + ecx*4 - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b38c:
    // 0042b38c  8b448ef4               -mov eax, dword ptr [esi + ecx*4 - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4);
    // 0042b390  89448ff4               -mov dword ptr [edi + ecx*4 - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b394:
    // 0042b394  8b448ef8               -mov eax, dword ptr [esi + ecx*4 - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4);
    // 0042b398  89448ff8               -mov dword ptr [edi + ecx*4 - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b39c:
    // 0042b39c  8b448efc               -mov eax, dword ptr [esi + ecx*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 0042b3a0  89448ffc               -mov dword ptr [edi + ecx*4 - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 0042b3a4  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0042b3ab  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b3ad  03f8                   +add edi, eax
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
  case 0x0042b3af:
    // 0042b3af  ff2495b8b34200         -jmp dword ptr [edx*4 + 0x42b3b8]
    cpu.ip = app->getMemory<x86::reg32>(4371384 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b3c8:
    // 0042b3c8  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b3cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3cd  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3ce  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042b3d0:
    // 0042b3d0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042b3d2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b3d4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b3d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3d9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3da  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042b3dc:
    // 0042b3dc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042b3de  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b3e0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042b3e3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042b3e6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b3e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3eb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3ec  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042b3f0:
    // 0042b3f0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042b3f2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042b3f4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042b3f7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042b3fa  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0042b3fd  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0042b400  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b403  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b404  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b405  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b406  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b408:
    // 0042b408  8d7431fc               -lea esi, [ecx + esi - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 0042b40c  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 0042b410  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0042b416  7524                   -jne 0x42b43c
    if (!cpu.flags.zf)
    {
        goto L_0x0042b43c;
    }
    // 0042b418  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b41b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b41e  83f908                 +cmp ecx, 8
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
    // 0042b421  720d                   -jb 0x42b430
    if (cpu.flags.cf)
    {
        goto L_0x0042b430;
    }
    // 0042b423  fd                     -std 
    cpu.flags.df = 1;
    // 0042b424  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b426  fc                     -cld 
    cpu.flags.df = 0;
    // 0042b427  ff249550b54200         -jmp dword ptr [edx*4 + 0x42b550]
    cpu.ip = app->getMemory<x86::reg32>(4371792 + cpu.edx * 4); goto dynamic_jump;
L_0x0042b430:
    // 0042b430  f7d9                   +neg ecx
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
    // 0042b432  ff248d00b54200         -jmp dword ptr [ecx*4 + 0x42b500]
    cpu.ip = app->getMemory<x86::reg32>(4371712 + cpu.ecx * 4); goto dynamic_jump;
L_0x0042b43c:
    // 0042b43c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042b43e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0042b443  83f904                 +cmp ecx, 4
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
    // 0042b446  720c                   -jb 0x42b454
    if (cpu.flags.cf)
    {
        goto L_0x0042b454;
    }
    // 0042b448  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b44b  2bc8                   +sub ecx, eax
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
    // 0042b44d  ff248558b44200         -jmp dword ptr [eax*4 + 0x42b458]
    cpu.ip = app->getMemory<x86::reg32>(4371544 + cpu.eax * 4); goto dynamic_jump;
L_0x0042b454:
    // 0042b454  ff248d50b54200         -jmp dword ptr [ecx*4 + 0x42b550]
    cpu.ip = app->getMemory<x86::reg32>(4371792 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0042b468:
    // 0042b468  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0042b46b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b46d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0042b470  4e                     -dec esi
    (cpu.esi)--;
    // 0042b471  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b474  4f                     -dec edi
    (cpu.edi)--;
    // 0042b475  83f908                 +cmp ecx, 8
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
    // 0042b478  72b6                   -jb 0x42b430
    if (cpu.flags.cf)
    {
        goto L_0x0042b430;
    }
    // 0042b47a  fd                     -std 
    cpu.flags.df = 1;
    // 0042b47b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b47d  fc                     -cld 
    cpu.flags.df = 0;
    // 0042b47e  ff249550b54200         -jmp dword ptr [edx*4 + 0x42b550]
    cpu.ip = app->getMemory<x86::reg32>(4371792 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b488:
    // 0042b488  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0042b48b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b48d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0042b490  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0042b493  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b496  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0042b499  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042b49c  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042b49f  83f908                 +cmp ecx, 8
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
    // 0042b4a2  728c                   -jb 0x42b430
    if (cpu.flags.cf)
    {
        goto L_0x0042b430;
    }
    // 0042b4a4  fd                     -std 
    cpu.flags.df = 1;
    // 0042b4a5  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b4a7  fc                     -cld 
    cpu.flags.df = 0;
    // 0042b4a8  ff249550b54200         -jmp dword ptr [edx*4 + 0x42b550]
    cpu.ip = app->getMemory<x86::reg32>(4371792 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b4b0:
    // 0042b4b0  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0042b4b3  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b4b5  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0042b4b8  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0042b4bb  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0042b4be  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042b4c1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042b4c4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042b4c7  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b4ca  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042b4cd  83f908                 +cmp ecx, 8
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
    // 0042b4d0  0f825affffff           -jb 0x42b430
    if (cpu.flags.cf)
    {
        goto L_0x0042b430;
    }
    // 0042b4d6  fd                     -std 
    cpu.flags.df = 1;
    // 0042b4d7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042b4d9  fc                     -cld 
    cpu.flags.df = 0;
    // 0042b4da  ff249550b54200         -jmp dword ptr [edx*4 + 0x42b550]
    cpu.ip = app->getMemory<x86::reg32>(4371792 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b504:
    // 0042b504  8b448e1c               -mov eax, dword ptr [esi + ecx*4 + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4);
    // 0042b508  89448f1c               -mov dword ptr [edi + ecx*4 + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b50c:
    // 0042b50c  8b448e18               -mov eax, dword ptr [esi + ecx*4 + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4);
    // 0042b510  89448f18               -mov dword ptr [edi + ecx*4 + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b514:
    // 0042b514  8b448e14               -mov eax, dword ptr [esi + ecx*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4);
    // 0042b518  89448f14               -mov dword ptr [edi + ecx*4 + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b51c:
    // 0042b51c  8b448e10               -mov eax, dword ptr [esi + ecx*4 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4);
    // 0042b520  89448f10               -mov dword ptr [edi + ecx*4 + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b524:
    // 0042b524  8b448e0c               -mov eax, dword ptr [esi + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 0042b528  89448f0c               -mov dword ptr [edi + ecx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b52c:
    // 0042b52c  8b448e08               -mov eax, dword ptr [esi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 0042b530  89448f08               -mov dword ptr [edi + ecx*4 + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0042b534:
    // 0042b534  8b448e04               -mov eax, dword ptr [esi + ecx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 0042b538  89448f04               -mov dword ptr [edi + ecx*4 + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 0042b53c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0042b543  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b545  03f8                   +add edi, eax
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
  case 0x0042b547:
    // 0042b547  ff249550b54200         -jmp dword ptr [edx*4 + 0x42b550]
    cpu.ip = app->getMemory<x86::reg32>(4371792 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042b560:
    // 0042b560  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b563  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b564  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b565  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b566  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042b568:
    // 0042b568  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0042b56b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0042b56e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b571  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b572  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b573  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b574  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042b578:
    // 0042b578  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0042b57b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0042b57e  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0042b581  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0042b584  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b587  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b588  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b589  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b58a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042b58c:
    // 0042b58c  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0042b58f  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0042b592  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0042b595  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0042b598  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042b59b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042b59e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b5a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b5a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b5a3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b5a4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_42b5a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b5a5  ff05bc534900           -inc dword ptr [0x4953bc]
    (app->getMemory<x86::reg32>(x86::reg32(4805564) /* 0x4953bc */))++;
    // 0042b5ab  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0042b5b0  e8c098ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042b5b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b5b6  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042b5ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b5bc  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042b5bf  740d                   -je 0x42b5ce
    if (cpu.flags.zf)
    {
        goto L_0x0042b5ce;
    }
    // 0042b5c1  83490c08               +or dword ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(8 /*0x8*/))));
    // 0042b5c5  c7411800100000         -mov dword ptr [ecx + 0x18], 0x1000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 4096 /*0x1000*/;
    // 0042b5cc  eb11                   -jmp 0x42b5df
    goto L_0x0042b5df;
L_0x0042b5ce:
    // 0042b5ce  83490c04               -or dword ptr [ecx + 0xc], 4
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b5d2  8d4114                 -lea eax, [ecx + 0x14]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0042b5d5  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042b5d8  c7411802000000         -mov dword ptr [ecx + 0x18], 2
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 2 /*0x2*/;
L_0x0042b5df:
    // 0042b5df  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0042b5e2  83610400               -and dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042b5e6  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042b5e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b5e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b5e9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042b5ed  3b05005e4900           +cmp eax, dword ptr [0x495e00]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b5f3  7203                   -jb 0x42b5f8
    if (cpu.flags.cf)
    {
        goto L_0x0042b5f8;
    }
    // 0042b5f5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b5f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b5f8:
    // 0042b5f8  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042b5fa  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042b5fd  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0042b600  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 0042b607  8a44c104               -mov al, byte ptr [ecx + eax*8 + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 0042b60b  83e040                 -and eax, 0x40
    cpu.eax &= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0042b60e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b60f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b60f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b610  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042b612  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042b615  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042b618  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b619  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042b61b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b61c  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 0042b61f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b620  c745e40c000000         -mov dword ptr [ebp - 0x1c], 0xc
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 12 /*0xc*/;
    // 0042b627  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 0042b62a  7409                   -je 0x42b635
    if (cpu.flags.zf)
    {
        goto L_0x0042b635;
    }
    // 0042b62c  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0042b62f  c645ff10               -mov byte ptr [ebp - 1], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = 16 /*0x10*/;
    // 0042b633  eb0b                   -jmp 0x42b640
    goto L_0x0042b640;
L_0x0042b635:
    // 0042b635  8065ff00               -and byte ptr [ebp - 1], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042b639  c745ec01000000         -mov dword ptr [ebp - 0x14], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 1 /*0x1*/;
L_0x0042b640:
    // 0042b640  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 0042b645  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 0042b647  7511                   -jne 0x42b65a
    if (!cpu.flags.zf)
    {
        goto L_0x0042b65a;
    }
    // 0042b649  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 0042b64c  7508                   -jne 0x42b656
    if (!cpu.flags.zf)
    {
        goto L_0x0042b656;
    }
    // 0042b64e  390558544900           +cmp dword ptr [0x495458], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805720) /* 0x495458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b654  7404                   -je 0x42b65a
    if (cpu.flags.zf)
    {
        goto L_0x0042b65a;
    }
L_0x0042b656:
    // 0042b656  804dff80               -or byte ptr [ebp - 1], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0042b65a:
    // 0042b65a  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042b65c  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042b65e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b65f  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 0042b661  2bc3                   +sub eax, ebx
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
    // 0042b663  742d                   -je 0x42b692
    if (cpu.flags.zf)
    {
        goto L_0x0042b692;
    }
    // 0042b665  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042b666  7421                   -je 0x42b689
    if (cpu.flags.zf)
    {
        goto L_0x0042b689;
    }
    // 0042b668  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042b669  7415                   -je 0x42b680
    if (cpu.flags.zf)
    {
        goto L_0x0042b680;
    }
L_0x0042b66b:
    // 0042b66b  c705e453490016000000   -mov dword ptr [0x4953e4], 0x16
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 22 /*0x16*/;
    // 0042b675  891de8534900           -mov dword ptr [0x4953e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.ebx;
    // 0042b67b  e925020000             -jmp 0x42b8a5
    goto L_0x0042b8a5;
L_0x0042b680:
    // 0042b680  c745f4000000c0         -mov dword ptr [ebp - 0xc], 0xc0000000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 3221225472 /*0xc0000000*/;
    // 0042b687  eb10                   -jmp 0x42b699
    goto L_0x0042b699;
L_0x0042b689:
    // 0042b689  c745f400000040         -mov dword ptr [ebp - 0xc], 0x40000000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 1073741824 /*0x40000000*/;
    // 0042b690  eb07                   -jmp 0x42b699
    goto L_0x0042b699;
L_0x0042b692:
    // 0042b692  c745f400000080         -mov dword ptr [ebp - 0xc], 0x80000000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 2147483648 /*0x80000000*/;
L_0x0042b699:
    // 0042b699  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042b69c  83f810                 +cmp eax, 0x10
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
    // 0042b69f  7426                   -je 0x42b6c7
    if (cpu.flags.zf)
    {
        goto L_0x0042b6c7;
    }
    // 0042b6a1  83f820                 +cmp eax, 0x20
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
    // 0042b6a4  7418                   -je 0x42b6be
    if (cpu.flags.zf)
    {
        goto L_0x0042b6be;
    }
    // 0042b6a6  83f830                 +cmp eax, 0x30
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
    // 0042b6a9  740a                   -je 0x42b6b5
    if (cpu.flags.zf)
    {
        goto L_0x0042b6b5;
    }
    // 0042b6ab  83f840                 +cmp eax, 0x40
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
    // 0042b6ae  75bb                   -jne 0x42b66b
    if (!cpu.flags.zf)
    {
        goto L_0x0042b66b;
    }
    // 0042b6b0  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 0042b6b3  eb15                   -jmp 0x42b6ca
    goto L_0x0042b6ca;
L_0x0042b6b5:
    // 0042b6b5  c745f002000000         -mov dword ptr [ebp - 0x10], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 2 /*0x2*/;
    // 0042b6bc  eb0c                   -jmp 0x42b6ca
    goto L_0x0042b6ca;
L_0x0042b6be:
    // 0042b6be  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 0042b6c5  eb03                   -jmp 0x42b6ca
    goto L_0x0042b6ca;
L_0x0042b6c7:
    // 0042b6c7  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
L_0x0042b6ca:
    // 0042b6ca  ba00070000             -mov edx, 0x700
    cpu.edx = 1792 /*0x700*/;
    // 0042b6cf  b800040000             -mov eax, 0x400
    cpu.eax = 1024 /*0x400*/;
    // 0042b6d4  23ca                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 0042b6d6  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 0042b6db  3bc8                   +cmp ecx, eax
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
    // 0042b6dd  7f35                   -jg 0x42b714
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042b714;
    }
    // 0042b6df  742e                   -je 0x42b70f
    if (cpu.flags.zf)
    {
        goto L_0x0042b70f;
    }
    // 0042b6e1  3bcb                   +cmp ecx, ebx
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
    // 0042b6e3  742a                   -je 0x42b70f
    if (cpu.flags.zf)
    {
        goto L_0x0042b70f;
    }
    // 0042b6e5  3bcf                   +cmp ecx, edi
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
    // 0042b6e7  741d                   -je 0x42b706
    if (cpu.flags.zf)
    {
        goto L_0x0042b706;
    }
    // 0042b6e9  81f900020000           +cmp ecx, 0x200
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
    // 0042b6ef  743c                   -je 0x42b72d
    if (cpu.flags.zf)
    {
        goto L_0x0042b72d;
    }
    // 0042b6f1  81f900030000           +cmp ecx, 0x300
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
    // 0042b6f7  0f856effffff           -jne 0x42b66b
    if (!cpu.flags.zf)
    {
        goto L_0x0042b66b;
    }
    // 0042b6fd  c745f802000000         -mov dword ptr [ebp - 8], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 2 /*0x2*/;
    // 0042b704  eb37                   -jmp 0x42b73d
    goto L_0x0042b73d;
L_0x0042b706:
    // 0042b706  c745f804000000         -mov dword ptr [ebp - 8], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 4 /*0x4*/;
    // 0042b70d  eb2e                   -jmp 0x42b73d
    goto L_0x0042b73d;
L_0x0042b70f:
    // 0042b70f  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0042b712  eb29                   -jmp 0x42b73d
    goto L_0x0042b73d;
L_0x0042b714:
    // 0042b714  81f900050000           +cmp ecx, 0x500
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
    // 0042b71a  741a                   -je 0x42b736
    if (cpu.flags.zf)
    {
        goto L_0x0042b736;
    }
    // 0042b71c  81f900060000           +cmp ecx, 0x600
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
    // 0042b722  7409                   -je 0x42b72d
    if (cpu.flags.zf)
    {
        goto L_0x0042b72d;
    }
    // 0042b724  3bca                   +cmp ecx, edx
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
    // 0042b726  740e                   -je 0x42b736
    if (cpu.flags.zf)
    {
        goto L_0x0042b736;
    }
    // 0042b728  e93effffff             -jmp 0x42b66b
    goto L_0x0042b66b;
L_0x0042b72d:
    // 0042b72d  c745f805000000         -mov dword ptr [ebp - 8], 5
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 5 /*0x5*/;
    // 0042b734  eb07                   -jmp 0x42b73d
    goto L_0x0042b73d;
L_0x0042b736:
    // 0042b736  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
L_0x0042b73d:
    // 0042b73d  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042b740  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 0042b745  85c7                   +test edi, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.eax));
    // 0042b747  7413                   -je 0x42b75c
    if (cpu.flags.zf)
    {
        goto L_0x0042b75c;
    }
    // 0042b749  8b0dec534900           -mov ecx, dword ptr [0x4953ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4805612) /* 0x4953ec */);
    // 0042b74f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0042b751  234d14                 -and ecx, dword ptr [ebp + 0x14]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
    // 0042b754  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 0042b757  7503                   -jne 0x42b75c
    if (!cpu.flags.zf)
    {
        goto L_0x0042b75c;
    }
    // 0042b759  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b75b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042b75c:
    // 0042b75c  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0042b75e  740a                   -je 0x42b76a
    if (cpu.flags.zf)
    {
        goto L_0x0042b76a;
    }
    // 0042b760  81ce00000004           -or esi, 0x4000000
    cpu.esi |= x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
    // 0042b766  804df601               -or byte ptr [ebp - 0xa], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-10) /* -0xa */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0042b76a:
    // 0042b76a  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0042b76d  7402                   -je 0x42b771
    if (cpu.flags.zf)
    {
        goto L_0x0042b771;
    }
    // 0042b76f  0bf7                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
L_0x0042b771:
    // 0042b771  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0042b773  7408                   -je 0x42b77d
    if (cpu.flags.zf)
    {
        goto L_0x0042b77d;
    }
    // 0042b775  81ce00000008           +or esi, 0x8000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(134217728 /*0x8000000*/))));
    // 0042b77b  eb0a                   -jmp 0x42b787
    goto L_0x0042b787;
L_0x0042b77d:
    // 0042b77d  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0042b77f  7406                   -je 0x42b787
    if (cpu.flags.zf)
    {
        goto L_0x0042b787;
    }
    // 0042b781  81ce00000010           -or esi, 0x10000000
    cpu.esi |= x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
L_0x0042b787:
    // 0042b787  e812f1ffff             -call 0x42a89e
    cpu.esp -= 4;
    sub_42a89e(app, cpu);
    // 0042b78c  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042b78e  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042b791  3bdf                   +cmp ebx, edi
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
    // 0042b793  7513                   -jne 0x42b7a8
    if (!cpu.flags.zf)
    {
        goto L_0x0042b7a8;
    }
    // 0042b795  8325e853490000         +and dword ptr [0x4953e8], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0042b79c  c705e453490018000000   -mov dword ptr [0x4953e4], 0x18
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 24 /*0x18*/;
    // 0042b7a6  eb3e                   -jmp 0x42b7e6
    goto L_0x0042b7e6;
L_0x0042b7a8:
    // 0042b7a8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042b7aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b7ab  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0042b7ae  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042b7b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b7b2  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0042b7b5  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0042b7b8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042b7bb  ff1520014300           -call dword ptr [0x430120]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391200) /* 0x430120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b7c1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042b7c3  3bf7                   +cmp esi, edi
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
    // 0042b7c5  7412                   -je 0x42b7d9
    if (cpu.flags.zf)
    {
        goto L_0x0042b7d9;
    }
    // 0042b7c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b7c8  ff15a8004300           -call dword ptr [0x4300a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391080) /* 0x4300a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b7ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b7d0  751b                   -jne 0x42b7ed
    if (!cpu.flags.zf)
    {
        goto L_0x0042b7ed;
    }
    // 0042b7d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b7d3  ff15ac004300           -call dword ptr [0x4300ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391084) /* 0x4300ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042b7d9:
    // 0042b7d9  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b7df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b7e0  e890efffff             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 0042b7e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042b7e6:
    // 0042b7e6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042b7e8  e9d6000000             -jmp 0x42b8c3
    goto L_0x0042b8c3;
L_0x0042b7ed:
    // 0042b7ed  83f802                 +cmp eax, 2
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
    // 0042b7f0  7506                   -jne 0x42b7f8
    if (!cpu.flags.zf)
    {
        goto L_0x0042b7f8;
    }
    // 0042b7f2  804dff40               +or byte ptr [ebp - 1], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0042b7f6  eb09                   -jmp 0x42b801
    goto L_0x0042b801;
L_0x0042b7f8:
    // 0042b7f8  83f803                 +cmp eax, 3
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
    // 0042b7fb  7504                   -jne 0x42b801
    if (!cpu.flags.zf)
    {
        goto L_0x0042b801;
    }
    // 0042b7fd  804dff08               -or byte ptr [ebp - 1], 8
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0042b801:
    // 0042b801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b802  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b803  e82bf1ffff             -call 0x42a933
    cpu.esp -= 4;
    sub_42a933(app, cpu);
    // 0042b808  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b809  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 0042b80c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b80d  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0042b80f  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042b811  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0042b813  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0042b816  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042b819  88450b                 -mov byte ptr [ebp + 0xb], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) = cpu.al;
    // 0042b81c  8d3c8d005d4900         -lea edi, [ecx*4 + 0x495d00]
    cpu.edi = x86::reg32(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 0042b823  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0042b826  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042b828  80650b48               +and byte ptr [ebp + 0xb], 0x48
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) &= x86::reg8(x86::sreg8(72 /*0x48*/))));
    // 0042b82c  88443104               -mov byte ptr [ecx + esi + 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) = cpu.al;
    // 0042b830  7578                   -jne 0x42b8aa
    if (!cpu.flags.zf)
    {
        goto L_0x0042b8aa;
    }
    // 0042b832  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0042b834  7474                   -je 0x42b8aa
    if (cpu.flags.zf)
    {
        goto L_0x0042b8aa;
    }
    // 0042b836  f6450c02               +test byte ptr [ebp + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 0042b83a  746e                   -je 0x42b8aa
    if (cpu.flags.zf)
    {
        goto L_0x0042b8aa;
    }
    // 0042b83c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042b83e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042b840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b841  e86cd2ffff             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 0042b846  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042b849  83f8ff                 +cmp eax, -1
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
    // 0042b84c  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0042b84f  750e                   -jne 0x42b85f
    if (!cpu.flags.zf)
    {
        goto L_0x0042b85f;
    }
    // 0042b851  813de853490083000000   +cmp dword ptr [0x4953e8], 0x83
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b85b  744d                   -je 0x42b8aa
    if (cpu.flags.zf)
    {
        goto L_0x0042b8aa;
    }
    // 0042b85d  eb3f                   -jmp 0x42b89e
    goto L_0x0042b89e;
L_0x0042b85f:
    // 0042b85f  80651300               -and byte ptr [ebp + 0x13], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(19) /* 0x13 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042b863  8d4513                 -lea eax, [ebp + 0x13]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(19) /* 0x13 */);
    // 0042b866  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b868  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b869  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b86a  e813a7ffff             -call 0x425f82
    cpu.esp -= 4;
    sub_425f82(app, cpu);
    // 0042b86f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042b872  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b874  7516                   -jne 0x42b88c
    if (!cpu.flags.zf)
    {
        goto L_0x0042b88c;
    }
    // 0042b876  807d131a               +cmp byte ptr [ebp + 0x13], 0x1a
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
    // 0042b87a  7510                   -jne 0x42b88c
    if (!cpu.flags.zf)
    {
        goto L_0x0042b88c;
    }
    // 0042b87c  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0042b87f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b880  e8221c0000             -call 0x42d4a7
    cpu.esp -= 4;
    sub_42d4a7(app, cpu);
    // 0042b885  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b886  83f8ff                 +cmp eax, -1
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
    // 0042b889  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b88a  7412                   -je 0x42b89e
    if (cpu.flags.zf)
    {
        goto L_0x0042b89e;
    }
L_0x0042b88c:
    // 0042b88c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042b88e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042b890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b891  e81cd2ffff             -call 0x428ab2
    cpu.esp -= 4;
    sub_428ab2(app, cpu);
    // 0042b896  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042b899  83f8ff                 +cmp eax, -1
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
    // 0042b89c  750c                   -jne 0x42b8aa
    if (!cpu.flags.zf)
    {
        goto L_0x0042b8aa;
    }
L_0x0042b89e:
    // 0042b89e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b89f  e8e0b0ffff             -call 0x426984
    cpu.esp -= 4;
    sub_426984(app, cpu);
    // 0042b8a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042b8a5:
    // 0042b8a5  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042b8a8  eb19                   -jmp 0x42b8c3
    goto L_0x0042b8c3;
L_0x0042b8aa:
    // 0042b8aa  807d0b00               +cmp byte ptr [ebp + 0xb], 0
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
    // 0042b8ae  7511                   -jne 0x42b8c1
    if (!cpu.flags.zf)
    {
        goto L_0x0042b8c1;
    }
    // 0042b8b0  f6450c08               +test byte ptr [ebp + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 0042b8b4  740b                   -je 0x42b8c1
    if (cpu.flags.zf)
    {
        goto L_0x0042b8c1;
    }
    // 0042b8b6  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042b8b8  804c300420             -or byte ptr [eax + esi + 4], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0042b8bd  8d443004               -lea eax, [eax + esi + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
L_0x0042b8c1:
    // 0042b8c1  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0042b8c3:
    // 0042b8c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b8c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b8c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b8c6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b8c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b8c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b8c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b8c9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042b8cb  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b8ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b8d0  7502                   -jne 0x42b8d4
    if (!cpu.flags.zf)
    {
        goto L_0x0042b8d4;
    }
    // 0042b8d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b8d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b8d4:
    // 0042b8d4  833d7c56490000         +cmp dword ptr [0x49567c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806268) /* 0x49567c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b8db  7512                   -jne 0x42b8ef
    if (!cpu.flags.zf)
    {
        goto L_0x0042b8ef;
    }
    // 0042b8dd  668b4d0c               -mov cx, word ptr [ebp + 0xc]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042b8e1  6681f9ff00             +cmp cx, 0xff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(255 /*0xff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042b8e6  7739                   -ja 0x42b921
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042b921;
    }
    // 0042b8e8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b8ea  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0042b8ec  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b8ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b8ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b8ef:
    // 0042b8ef  8d4d08                 -lea ecx, [ebp + 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042b8f2  83650800               -and dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042b8f6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b8f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042b8f9  ff3530d84300           -push dword ptr [0x43d830]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
    cpu.esp -= 4;
    // 0042b8ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b900  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042b903  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b905  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b906  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 0042b90b  ff358c564900           -push dword ptr [0x49568c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    cpu.esp -= 4;
    // 0042b911  ff1514014300           -call dword ptr [0x430114]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391188) /* 0x430114 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b917  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b919  7406                   -je 0x42b921
    if (cpu.flags.zf)
    {
        goto L_0x0042b921;
    }
    // 0042b91b  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0042b91f  740d                   -je 0x42b92e
    if (cpu.flags.zf)
    {
        goto L_0x0042b92e;
    }
L_0x0042b921:
    // 0042b921  c705e45349002a000000   -mov dword ptr [0x4953e4], 0x2a
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 42 /*0x2a*/;
    // 0042b92b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042b92e:
    // 0042b92e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b92f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b931  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042b935  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042b937  7518                   -jne 0x42b951
    if (!cpu.flags.zf)
    {
        goto L_0x0042b951;
    }
    // 0042b939  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042b93d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b941  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042b943  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0042b945  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042b949  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0042b94b  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042b94d  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0042b94f  eb50                   -jmp 0x42b9a1
    goto L_0x0042b9a1;
L_0x0042b951:
    // 0042b951  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042b953  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042b957  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b95b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0042b95f:
    // 0042b95f  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0042b961  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
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
    // 0042b963  d1ea                   +shr edx, 1
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
    // 0042b965  d1d8                   -rcr eax, 1
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
    // 0042b967  0bc9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0042b969  75f4                   -jne 0x42b95f
    if (!cpu.flags.zf)
    {
        goto L_0x0042b95f;
    }
    // 0042b96b  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0042b96d  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042b96f  f7642414               -mul dword ptr [esp + 0x14]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0042b973  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0042b974  f7642410               -mul dword ptr [esp + 0x10]
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0042b978  03d1                   +add edx, ecx
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
    // 0042b97a  720e                   -jb 0x42b98a
    if (cpu.flags.cf)
    {
        goto L_0x0042b98a;
    }
    // 0042b97c  3b54240c               +cmp edx, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b980  7708                   -ja 0x42b98a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042b98a;
    }
    // 0042b982  720e                   -jb 0x42b992
    if (cpu.flags.cf)
    {
        goto L_0x0042b992;
    }
    // 0042b984  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b988  7608                   -jbe 0x42b992
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042b992;
    }
L_0x0042b98a:
    // 0042b98a  2b442410               +sub eax, dword ptr [esp + 0x10]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042b98e  1b542414               -sbb edx, dword ptr [esp + 0x14]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)) + cpu.flags.cf);
L_0x0042b992:
    // 0042b992  2b442408               +sub eax, dword ptr [esp + 8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042b996  1b54240c               -sbb edx, dword ptr [esp + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)) + cpu.flags.cf);
    // 0042b99a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0042b99c  f7d8                   +neg eax
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
    // 0042b99e  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x0042b9a1:
    // 0042b9a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b9a2  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_42b9a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b9a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b9a6  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042b9aa  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042b9ac  813863736de0           +cmp dword ptr [eax], 0xe06d7363
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
    // 0042b9b2  7514                   -jne 0x42b9c8
    if (!cpu.flags.zf)
    {
        goto L_0x0042b9c8;
    }
    // 0042b9b4  83781003               +cmp dword ptr [eax + 0x10], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b9b8  750e                   -jne 0x42b9c8
    if (!cpu.flags.zf)
    {
        goto L_0x0042b9c8;
    }
    // 0042b9ba  81781420059319         +cmp dword ptr [eax + 0x14], 0x19930520
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(429065504 /*0x19930520*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b9c1  7505                   -jne 0x42b9c8
    if (!cpu.flags.zf)
    {
        goto L_0x0042b9c8;
    }
    // 0042b9c3  e964daffff             -jmp 0x42942c
    return sub_42942c(app, cpu);
L_0x0042b9c8:
    // 0042b9c8  a170554900             -mov eax, dword ptr [0x495570]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806000) /* 0x495570 */);
    // 0042b9cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b9cf  7414                   -je 0x42b9e5
    if (cpu.flags.zf)
    {
        goto L_0x0042b9e5;
    }
    // 0042b9d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b9d2  e86a000000             -call 0x42ba41
    cpu.esp -= 4;
    sub_42ba41(app, cpu);
    // 0042b9d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b9d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b9da  7409                   -je 0x42b9e5
    if (cpu.flags.zf)
    {
        goto L_0x0042b9e5;
    }
    // 0042b9dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b9dd  ff1570554900           -call dword ptr [0x495570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4806000) /* 0x495570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b9e3  eb02                   -jmp 0x42b9e7
    goto L_0x0042b9e7;
L_0x0042b9e5:
    // 0042b9e5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042b9e7:
    // 0042b9e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b9e8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_42b9eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b9eb  68a5b94200             -push 0x42b9a5
    app->getMemory<x86::reg32>(cpu.esp-4) = 4372901 /*0x42b9a5*/;
    cpu.esp -= 4;
    // 0042b9f0  ff1524014300           -call dword ptr [0x430124]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391204) /* 0x430124 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b9f6  a370554900             -mov dword ptr [0x495570], eax
    app->getMemory<x86::reg32>(x86::reg32(4806000) /* 0x495570 */) = cpu.eax;
    // 0042b9fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42b9fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b9fc  ff3570554900           -push dword ptr [0x495570]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806000) /* 0x495570 */);
    cpu.esp -= 4;
    // 0042ba02  ff1524014300           -call dword ptr [0x430124]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391204) /* 0x430124 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ba08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ba09(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ba09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ba0a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042ba0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba0d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042ba11  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042ba15  ff15d0004300           -call dword ptr [0x4300d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391120) /* 0x4300d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ba1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ba1d  7402                   -je 0x42ba21
    if (cpu.flags.zf)
    {
        goto L_0x0042ba21;
    }
    // 0042ba1f  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042ba21:
    // 0042ba21  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ba23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ba25(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ba25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ba26  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042ba28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba29  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042ba2d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042ba31  ff15d8004300           -call dword ptr [0x4300d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391128) /* 0x4300d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ba37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ba39  7402                   -je 0x42ba3d
    if (cpu.flags.zf)
    {
        goto L_0x0042ba3d;
    }
    // 0042ba3b  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042ba3d:
    // 0042ba3d  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ba3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ba41(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ba41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ba42  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042ba44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba45  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042ba49  ff15d4004300           -call dword ptr [0x4300d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391124) /* 0x4300d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042ba4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ba51  7402                   -je 0x42ba55
    if (cpu.flags.zf)
    {
        goto L_0x0042ba55;
    }
    // 0042ba53  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042ba55:
    // 0042ba55  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ba57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ba60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ba60  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042ba64  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042ba68  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 0042ba6e  753c                   -jne 0x42baac
    if (!cpu.flags.zf)
    {
        goto L_0x0042baac;
    }
L_0x0042ba70:
    // 0042ba70  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042ba72  3a01                   +cmp al, byte ptr [ecx]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ba74  752e                   -jne 0x42baa4
    if (!cpu.flags.zf)
    {
        goto L_0x0042baa4;
    }
    // 0042ba76  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0042ba78  7426                   -je 0x42baa0
    if (cpu.flags.zf)
    {
        goto L_0x0042baa0;
    }
    // 0042ba7a  3a6101                 +cmp ah, byte ptr [ecx + 1]
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ba7d  7525                   -jne 0x42baa4
    if (!cpu.flags.zf)
    {
        goto L_0x0042baa4;
    }
    // 0042ba7f  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 0042ba81  741d                   -je 0x42baa0
    if (cpu.flags.zf)
    {
        goto L_0x0042baa0;
    }
    // 0042ba83  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0042ba86  3a4102                 +cmp al, byte ptr [ecx + 2]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ba89  7519                   -jne 0x42baa4
    if (!cpu.flags.zf)
    {
        goto L_0x0042baa4;
    }
    // 0042ba8b  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0042ba8d  7411                   -je 0x42baa0
    if (cpu.flags.zf)
    {
        goto L_0x0042baa0;
    }
    // 0042ba8f  3a6103                 +cmp ah, byte ptr [ecx + 3]
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ba92  7510                   -jne 0x42baa4
    if (!cpu.flags.zf)
    {
        goto L_0x0042baa4;
    }
    // 0042ba94  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ba97  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ba9a  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 0042ba9c  75d2                   -jne 0x42ba70
    if (!cpu.flags.zf)
    {
        goto L_0x0042ba70;
    }
    // 0042ba9e  8bff                   -mov edi, edi
    cpu.edi = cpu.edi;
L_0x0042baa0:
    // 0042baa0  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042baa2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042baa4:
    // 0042baa4  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0042baa6  d1e0                   -shl eax, 1
    cpu.eax <<= 1 /*0x1*/ % 32;
    // 0042baa8  40                     -inc eax
    (cpu.eax)++;
    // 0042baa9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042baac:
    // 0042baac  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0042bab2  7414                   -je 0x42bac8
    if (cpu.flags.zf)
    {
        goto L_0x0042bac8;
    }
    // 0042bab4  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0042bab6  42                     -inc edx
    (cpu.edx)++;
    // 0042bab7  3a01                   +cmp al, byte ptr [ecx]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042bab9  75e9                   -jne 0x42baa4
    if (!cpu.flags.zf)
    {
        goto L_0x0042baa4;
    }
    // 0042babb  41                     -inc ecx
    (cpu.ecx)++;
    // 0042babc  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0042babe  74e0                   -je 0x42baa0
    if (cpu.flags.zf)
    {
        goto L_0x0042baa0;
    }
    // 0042bac0  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0042bac6  74a8                   -je 0x42ba70
    if (cpu.flags.zf)
    {
        goto L_0x0042ba70;
    }
L_0x0042bac8:
    // 0042bac8  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 0042bacb  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042bace  3a01                   +cmp al, byte ptr [ecx]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042bad0  75d2                   -jne 0x42baa4
    if (!cpu.flags.zf)
    {
        goto L_0x0042baa4;
    }
    // 0042bad2  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 0042bad4  74ca                   -je 0x42baa0
    if (cpu.flags.zf)
    {
        goto L_0x0042baa0;
    }
    // 0042bad6  3a6101                 +cmp ah, byte ptr [ecx + 1]
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042bad9  75c9                   -jne 0x42baa4
    if (!cpu.flags.zf)
    {
        goto L_0x0042baa4;
    }
    // 0042badb  0ae4                   +or ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(cpu.ah))));
    // 0042badd  74c1                   -je 0x42baa0
    if (cpu.flags.zf)
    {
        goto L_0x0042baa0;
    }
    // 0042badf  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042bae2  eb8c                   -jmp 0x42ba70
    goto L_0x0042ba70;
}

/* align: skip  */
void Application::asm_sub_42bae4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bae4  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0042bae6  e8c3f5ffff             -call 0x42b0ae
    cpu.esp -= 4;
    sub_42b0ae(app, cpu);
    // 0042baeb  6a16                   -push 0x16
    app->getMemory<x86::reg32>(cpu.esp-4) = 22 /*0x16*/;
    cpu.esp -= 4;
    // 0042baed  e8fb1a0000             -call 0x42d5ed
    cpu.esp -= 4;
    sub_42d5ed(app, cpu);
    // 0042baf2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042baf3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042baf4  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042baf6  e811c2ffff             -call 0x427d0c
    cpu.esp -= 4;
    sub_427d0c(app, cpu);
    return sub_42bafb(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42bafb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bafb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042bafc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042bafe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042baff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bb00  9b                     -wait 
    /*nothing*/;
    // 0042bb01  d97dfc                 -fnstcw word ptr [ebp - 4]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.control.word;
    // 0042bb04  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0042bb07  e83a000000             -call 0x42bb46
    cpu.esp -= 4;
    sub_42bb46(app, cpu);
    // 0042bb0c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042bb0e  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042bb11  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0042bb13  23f0                   -and esi, eax
    cpu.esi &= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bb15  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bb18  23450c                 -and eax, dword ptr [ebp + 0xc]
    cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0042bb1b  0bf0                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bb1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bb1e  e8b5000000             -call 0x42bbd8
    cpu.esp -= 4;
    sub_42bbd8(app, cpu);
    // 0042bb23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bb24  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042bb27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bb28  d96d0c                 -fldcw word ptr [ebp + 0xc]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042bb2b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042bb2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bb2e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bb2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bb30  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bb34  25fffff7ff             -and eax, 0xfff7ffff
    cpu.eax &= x86::reg32(x86::sreg32(4294443007 /*0xfff7ffff*/));
    // 0042bb39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bb3a  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042bb3e  e8b8ffffff             -call 0x42bafb
    cpu.esp -= 4;
    sub_42bafb(app, cpu);
    // 0042bb43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bb44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bb45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bb46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bb46  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042bb47  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bb4b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bb4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042bb4e  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0042bb51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bb52  7403                   -je 0x42bb57
    if (cpu.flags.zf)
    {
        goto L_0x0042bb57;
    }
    // 0042bb54  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0042bb56  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042bb57:
    // 0042bb57  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0042bb5a  7402                   -je 0x42bb5e
    if (cpu.flags.zf)
    {
        goto L_0x0042bb5e;
    }
    // 0042bb5c  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0042bb5e:
    // 0042bb5e  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0042bb61  7402                   -je 0x42bb65
    if (cpu.flags.zf)
    {
        goto L_0x0042bb65;
    }
    // 0042bb63  0c04                   -or al, 4
    cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0042bb65:
    // 0042bb65  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0042bb68  7402                   -je 0x42bb6c
    if (cpu.flags.zf)
    {
        goto L_0x0042bb6c;
    }
    // 0042bb6a  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0042bb6c:
    // 0042bb6c  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 0042bb6f  7402                   -je 0x42bb73
    if (cpu.flags.zf)
    {
        goto L_0x0042bb73;
    }
    // 0042bb71  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0042bb73:
    // 0042bb73  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0042bb76  7405                   -je 0x42bb7d
    if (cpu.flags.zf)
    {
        goto L_0x0042bb7d;
    }
    // 0042bb78  0d00000800             -or eax, 0x80000
    cpu.eax |= x86::reg32(x86::sreg32(524288 /*0x80000*/));
L_0x0042bb7d:
    // 0042bb7d  0fb7cb                 -movzx ecx, bx
    cpu.ecx = x86::reg32(cpu.bx);
    // 0042bb80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bb81  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042bb83  be000c0000             -mov esi, 0xc00
    cpu.esi = 3072 /*0xc00*/;
    // 0042bb88  bf00030000             -mov edi, 0x300
    cpu.edi = 768 /*0x300*/;
    // 0042bb8d  23d6                   +and edx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(cpu.esi))));
    // 0042bb8f  bd00020000             -mov ebp, 0x200
    cpu.ebp = 512 /*0x200*/;
    // 0042bb94  741f                   -je 0x42bbb5
    if (cpu.flags.zf)
    {
        goto L_0x0042bbb5;
    }
    // 0042bb96  81fa00040000           +cmp edx, 0x400
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
    // 0042bb9c  7414                   -je 0x42bbb2
    if (cpu.flags.zf)
    {
        goto L_0x0042bbb2;
    }
    // 0042bb9e  81fa00080000           +cmp edx, 0x800
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bba4  7408                   -je 0x42bbae
    if (cpu.flags.zf)
    {
        goto L_0x0042bbae;
    }
    // 0042bba6  3bd6                   +cmp edx, esi
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
    // 0042bba8  750b                   -jne 0x42bbb5
    if (!cpu.flags.zf)
    {
        goto L_0x0042bbb5;
    }
    // 0042bbaa  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0042bbac  eb07                   -jmp 0x42bbb5
    goto L_0x0042bbb5;
L_0x0042bbae:
    // 0042bbae  0bc5                   +or eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0042bbb0  eb03                   -jmp 0x42bbb5
    goto L_0x0042bbb5;
L_0x0042bbb2:
    // 0042bbb2  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0042bbb5:
    // 0042bbb5  23cf                   +and ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.edi))));
    // 0042bbb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbb8  740b                   -je 0x42bbc5
    if (cpu.flags.zf)
    {
        goto L_0x0042bbc5;
    }
    // 0042bbba  3bcd                   +cmp ecx, ebp
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
    // 0042bbbc  750c                   -jne 0x42bbca
    if (!cpu.flags.zf)
    {
        goto L_0x0042bbca;
    }
    // 0042bbbe  0d00000100             +or eax, 0x10000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(65536 /*0x10000*/))));
    // 0042bbc3  eb05                   -jmp 0x42bbca
    goto L_0x0042bbca;
L_0x0042bbc5:
    // 0042bbc5  0d00000200             -or eax, 0x20000
    cpu.eax |= x86::reg32(x86::sreg32(131072 /*0x20000*/));
L_0x0042bbca:
    // 0042bbca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbcc  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 0042bbcf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbd0  7405                   -je 0x42bbd7
    if (cpu.flags.zf)
    {
        goto L_0x0042bbd7;
    }
    // 0042bbd2  0d00000400             -or eax, 0x40000
    cpu.eax |= x86::reg32(x86::sreg32(262144 /*0x40000*/));
L_0x0042bbd7:
    // 0042bbd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bbd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bbd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042bbd9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bbdd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bbdf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bbe0  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0042bbe3  7403                   -je 0x42bbe8
    if (cpu.flags.zf)
    {
        goto L_0x0042bbe8;
    }
    // 0042bbe5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042bbe7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042bbe8:
    // 0042bbe8  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0042bbeb  7402                   -je 0x42bbef
    if (cpu.flags.zf)
    {
        goto L_0x0042bbef;
    }
    // 0042bbed  0c04                   -or al, 4
    cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0042bbef:
    // 0042bbef  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0042bbf2  7402                   -je 0x42bbf6
    if (cpu.flags.zf)
    {
        goto L_0x0042bbf6;
    }
    // 0042bbf4  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0042bbf6:
    // 0042bbf6  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0042bbf9  7402                   -je 0x42bbfd
    if (cpu.flags.zf)
    {
        goto L_0x0042bbfd;
    }
    // 0042bbfb  0c10                   -or al, 0x10
    cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0042bbfd:
    // 0042bbfd  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0042bc00  7402                   -je 0x42bc04
    if (cpu.flags.zf)
    {
        goto L_0x0042bc04;
    }
    // 0042bc02  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0042bc04:
    // 0042bc04  f7c300000800           +test ebx, 0x80000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 524288 /*0x80000*/));
    // 0042bc0a  7402                   -je 0x42bc0e
    if (cpu.flags.zf)
    {
        goto L_0x0042bc0e;
    }
    // 0042bc0c  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0042bc0e:
    // 0042bc0e  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042bc10  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0042bc15  23ca                   +and ecx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx))));
    // 0042bc17  be00020000             -mov esi, 0x200
    cpu.esi = 512 /*0x200*/;
    // 0042bc1c  741d                   -je 0x42bc3b
    if (cpu.flags.zf)
    {
        goto L_0x0042bc3b;
    }
    // 0042bc1e  81f900010000           +cmp ecx, 0x100
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
    // 0042bc24  7412                   -je 0x42bc38
    if (cpu.flags.zf)
    {
        goto L_0x0042bc38;
    }
    // 0042bc26  3bce                   +cmp ecx, esi
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
    // 0042bc28  7409                   -je 0x42bc33
    if (cpu.flags.zf)
    {
        goto L_0x0042bc33;
    }
    // 0042bc2a  3bca                   +cmp ecx, edx
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
    // 0042bc2c  750d                   -jne 0x42bc3b
    if (!cpu.flags.zf)
    {
        goto L_0x0042bc3b;
    }
    // 0042bc2e  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 0042bc31  eb08                   -jmp 0x42bc3b
    goto L_0x0042bc3b;
L_0x0042bc33:
    // 0042bc33  80cc08                 +or ah, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0042bc36  eb03                   -jmp 0x42bc3b
    goto L_0x0042bc3b;
L_0x0042bc38:
    // 0042bc38  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0042bc3b:
    // 0042bc3b  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042bc3d  81e100000300           +and ecx, 0x30000
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(196608 /*0x30000*/))));
    // 0042bc43  740c                   -je 0x42bc51
    if (cpu.flags.zf)
    {
        goto L_0x0042bc51;
    }
    // 0042bc45  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bc4b  7506                   -jne 0x42bc53
    if (!cpu.flags.zf)
    {
        goto L_0x0042bc53;
    }
    // 0042bc4d  0bc6                   +or eax, esi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.esi))));
    // 0042bc4f  eb02                   -jmp 0x42bc53
    goto L_0x0042bc53;
L_0x0042bc51:
    // 0042bc51  0bc2                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x0042bc53:
    // 0042bc53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bc54  f7c300000400           +test ebx, 0x40000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 262144 /*0x40000*/));
    // 0042bc5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bc5b  7403                   -je 0x42bc60
    if (cpu.flags.zf)
    {
        goto L_0x0042bc60;
    }
    // 0042bc5d  80cc10                 -or ah, 0x10
    cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0042bc60:
    // 0042bc60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bc61(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bc61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042bc62  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042bc64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042bc65  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bc68  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042bc6b  81f900010000           +cmp ecx, 0x100
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
    // 0042bc71  770c                   -ja 0x42bc7f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042bc7f;
    }
    // 0042bc73  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042bc79  0fb70441               -movzx eax, word ptr [ecx + eax*2]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2));
    // 0042bc7d  eb52                   -jmp 0x42bcd1
    goto L_0x0042bcd1;
L_0x0042bc7f:
    // 0042bc7f  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042bc81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bc82  8b3520d64300           -mov esi, dword ptr [0x43d620]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042bc88  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0042bc8b  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 0042bc8e  f644560180             +test byte ptr [esi + edx*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edx * 2) & 128 /*0x80*/));
    // 0042bc93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bc94  740e                   -je 0x42bca4
    if (cpu.flags.zf)
    {
        goto L_0x0042bca4;
    }
    // 0042bc96  8065fe00               +and byte ptr [ebp - 2], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-2) /* -0x2 */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042bc9a  884dfc                 -mov byte ptr [ebp - 4], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.cl;
    // 0042bc9d  8845fd                 -mov byte ptr [ebp - 3], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 0042bca0  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042bca2  eb09                   -jmp 0x42bcad
    goto L_0x0042bcad;
L_0x0042bca4:
    // 0042bca4  8065fd00               -and byte ptr [ebp - 3], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042bca8  8845fc                 -mov byte ptr [ebp - 4], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0042bcab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
L_0x0042bcad:
    // 0042bcad  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bcae  8d4d0a                 -lea ecx, [ebp + 0xa]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(10) /* 0xa */);
    // 0042bcb1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042bcb3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bcb5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bcb7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042bcb8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bcb9  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042bcbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bcbd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042bcbf  e89b1a0000             -call 0x42d75f
    cpu.esp -= 4;
    sub_42d75f(app, cpu);
    // 0042bcc4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042bcc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042bcc9  7502                   -jne 0x42bccd
    if (!cpu.flags.zf)
    {
        goto L_0x0042bccd;
    }
    // 0042bccb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bccc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042bccd:
    // 0042bccd  0fb7450a               -movzx eax, word ptr [ebp + 0xa]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */));
L_0x0042bcd1:
    // 0042bcd1  23450c                 -and eax, dword ptr [ebp + 0xc]
    cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0042bcd4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bcd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bcd6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bcd6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042bcd7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042bcd9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042bcda  833d7c56490000         +cmp dword ptr [0x49567c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806268) /* 0x49567c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bce1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042bce2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bce3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bce4  751d                   -jne 0x42bd03
    if (!cpu.flags.zf)
    {
        goto L_0x0042bd03;
    }
    // 0042bce6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bce9  83f841                 +cmp eax, 0x41
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
    // 0042bcec  0f8caa000000           -jl 0x42bd9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042bd9c;
    }
    // 0042bcf2  83f85a                 +cmp eax, 0x5a
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
    // 0042bcf5  0f8fa1000000           -jg 0x42bd9c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042bd9c;
    }
    // 0042bcfb  83c020                 +add eax, 0x20
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
    // 0042bcfe  e999000000             -jmp 0x42bd9c
    goto L_0x0042bd9c;
L_0x0042bd03:
    // 0042bd03  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bd06  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 0042bd0b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042bd0d  3bdf                   +cmp ebx, edi
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
    // 0042bd0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd10  7d25                   -jge 0x42bd37
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042bd37;
    }
    // 0042bd12  393530d84300           +cmp dword ptr [0x43d830], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bd18  7e0b                   -jle 0x42bd25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042bd25;
    }
    // 0042bd1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bd1b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042bd1c  e840ffffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042bd21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd23  eb0a                   -jmp 0x42bd2f
    goto L_0x0042bd2f;
L_0x0042bd25:
    // 0042bd25  a120d64300             -mov eax, dword ptr [0x43d620]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042bd2a  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 0042bd2d  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042bd2f:
    // 0042bd2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042bd31  7504                   -jne 0x42bd37
    if (!cpu.flags.zf)
    {
        goto L_0x0042bd37;
    }
L_0x0042bd33:
    // 0042bd33  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042bd35  eb65                   -jmp 0x42bd9c
    goto L_0x0042bd9c;
L_0x0042bd37:
    // 0042bd37  8b1520d64300           -mov edx, dword ptr [0x43d620]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042bd3d  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042bd3f  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0042bd42  0fb6c8                 -movzx ecx, al
    cpu.ecx = x86::reg32(cpu.al);
    // 0042bd45  f6444a0180             +test byte ptr [edx + ecx*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.ecx * 2) & 128 /*0x80*/));
    // 0042bd4a  740f                   -je 0x42bd5b
    if (cpu.flags.zf)
    {
        goto L_0x0042bd5b;
    }
    // 0042bd4c  80650a00               +and byte ptr [ebp + 0xa], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042bd50  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042bd52  884508                 -mov byte ptr [ebp + 8], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0042bd55  885d09                 -mov byte ptr [ebp + 9], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) = cpu.bl;
    // 0042bd58  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd59  eb09                   -jmp 0x42bd64
    goto L_0x0042bd64;
L_0x0042bd5b:
    // 0042bd5b  80650900               -and byte ptr [ebp + 9], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042bd5f  885d08                 -mov byte ptr [ebp + 8], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 0042bd62  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0042bd64:
    // 0042bd64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bd65  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bd67  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042bd6a  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042bd6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042bd6d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bd6e  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bd71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bd72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bd73  ff357c564900           -push dword ptr [0x49567c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806268) /* 0x49567c */);
    cpu.esp -= 4;
    // 0042bd79  e82a1b0000             -call 0x42d8a8
    cpu.esp -= 4;
    sub_42d8a8(app, cpu);
    // 0042bd7e  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0042bd81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042bd83  74ae                   -je 0x42bd33
    if (cpu.flags.zf)
    {
        goto L_0x0042bd33;
    }
    // 0042bd85  3bc6                   +cmp eax, esi
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
    // 0042bd87  7506                   -jne 0x42bd8f
    if (!cpu.flags.zf)
    {
        goto L_0x0042bd8f;
    }
    // 0042bd89  0fb645fc               -movzx eax, byte ptr [ebp - 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 0042bd8d  eb0d                   -jmp 0x42bd9c
    goto L_0x0042bd9c;
L_0x0042bd8f:
    // 0042bd8f  0fb645fd               -movzx eax, byte ptr [ebp - 3]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */));
    // 0042bd93  0fb64dfc               -movzx ecx, byte ptr [ebp - 4]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 0042bd97  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0042bd9a  0bc1                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0042bd9c:
    // 0042bd9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd9f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bda0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bda1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bda1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bda5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bda6  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0042bda8  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042bda9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bdaa  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042bdac  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 0042bdae  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042bdb0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042bdb4  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042bdb5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042bdb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bdb8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bdbc  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042bdbe  83caff                 -or edx, 0xffffffff
    cpu.edx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042bdc1  d3e2                   +shl edx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042bdc3  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 0042bdc5  8514b0                 -test dword ptr [eax + esi*4], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4) & cpu.edx));
    // 0042bdc8  751c                   -jne 0x42bde6
    if (!cpu.flags.zf)
    {
        goto L_0x0042bde6;
    }
    // 0042bdca  46                     -inc esi
    (cpu.esi)++;
    // 0042bdcb  83fe03                 +cmp esi, 3
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
    // 0042bdce  7d11                   -jge 0x42bde1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042bde1;
    }
    // 0042bdd0  8d04b0                 -lea eax, [eax + esi*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.esi * 4);
L_0x0042bdd3:
    // 0042bdd3  833800                 +cmp dword ptr [eax], 0
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
    // 0042bdd6  750e                   -jne 0x42bde6
    if (!cpu.flags.zf)
    {
        goto L_0x0042bde6;
    }
    // 0042bdd8  46                     -inc esi
    (cpu.esi)++;
    // 0042bdd9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bddc  83fe03                 +cmp esi, 3
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
    // 0042bddf  7cf2                   -jl 0x42bdd3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042bdd3;
    }
L_0x0042bde1:
    // 0042bde1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042bde3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bde4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bde5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042bde6:
    // 0042bde6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bde8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bde9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bdea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bdea  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bdee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042bdef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bdf0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bdf1  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0042bdf3  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042bdf7  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042bdf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bdf9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042bdfb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042bdfd  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042be01  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042be02  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042be04  8d3cb3                 -lea edi, [ebx + esi*4]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 4);
    // 0042be07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042be08  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 0042be0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be0b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042be0d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be0e  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042be10  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0042be12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042be13  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 0042be15  e8dd1c0000             -call 0x42daf7
    cpu.esp -= 4;
    sub_42daf7(app, cpu);
    // 0042be1a  83c40c                 +add esp, 0xc
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
    // 0042be1d  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042be1e  781c                   -js 0x42be3c
    if (cpu.flags.sf)
    {
        goto L_0x0042be3c;
    }
    // 0042be20  8d3cb3                 -lea edi, [ebx + esi*4]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 4);
L_0x0042be23:
    // 0042be23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042be25  7415                   -je 0x42be3c
    if (cpu.flags.zf)
    {
        goto L_0x0042be3c;
    }
    // 0042be27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042be28  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042be2a  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 0042be2c  e8c61c0000             -call 0x42daf7
    cpu.esp -= 4;
    sub_42daf7(app, cpu);
    // 0042be31  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042be34  4e                     -dec esi
    (cpu.esi)--;
    // 0042be35  83ef04                 -sub edi, 4
    (cpu.edi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042be38  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042be3a  7de7                   -jge 0x42be23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042be23;
    }
L_0x0042be3c:
    // 0042be3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42be40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042be40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042be41  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042be43  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042be44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042be45  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042be48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042be49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042be4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042be4b  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0042be4e  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0042be50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be51  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042be55  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0042be58  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0042be5a  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042be5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be5d  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042be5e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042be60  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 0042be62  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042be64  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042be66  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042be67  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042be69  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042be6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be6d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042be6f  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0042be72  8d0488                 -lea eax, [eax + ecx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 0042be75  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042be78  2bf2                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042be7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be7b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042be7d  d3e2                   +shl edx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.edx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042be7f  8510                   -test dword ptr [eax], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax) & cpu.edx));
    // 0042be81  7421                   -je 0x42bea4
    if (cpu.flags.zf)
    {
        goto L_0x0042bea4;
    }
    // 0042be83  43                     -inc ebx
    (cpu.ebx)++;
    // 0042be84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042be85  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042be88  e814ffffff             -call 0x42bda1
    cpu.esp -= 4;
    sub_42bda1(app, cpu);
    // 0042be8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042be90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be91  750e                   -jne 0x42bea1
    if (!cpu.flags.zf)
    {
        goto L_0x0042bea1;
    }
    // 0042be93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042be94  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042be97  e84effffff             -call 0x42bdea
    cpu.esp -= 4;
    sub_42bdea(app, cpu);
    // 0042be9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042be9d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0042bea0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042bea1:
    // 0042bea1  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x0042bea4:
    // 0042bea4  83caff                 -or edx, 0xffffffff
    cpu.edx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042bea7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042bea9  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0042beab  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042bead  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042beae  2110                   -and dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(cpu.edx));
    // 0042beb0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042beb3  40                     -inc eax
    (cpu.eax)++;
    // 0042beb4  3bc1                   +cmp eax, ecx
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
    // 0042beb6  7d0c                   -jge 0x42bec4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042bec4;
    }
    // 0042beb8  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bebb  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bebd  8d3c82                 -lea edi, [edx + eax*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.eax * 4);
    // 0042bec0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bec2  f3ab                   -rep stosd dword ptr es:[edi], eax
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
L_0x0042bec4:
    // 0042bec4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042bec7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bec8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bec9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042beca  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042becb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42becc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042becc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bed0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042bed4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bed5  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042bed7  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bed9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042beda:
    // 0042beda  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0042bedc  893401                 -mov dword ptr [ecx + eax], esi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.esi;
    // 0042bedf  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042bee2  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042bee3  75f5                   -jne 0x42beda
    if (!cpu.flags.zf)
    {
        goto L_0x0042beda;
    }
    // 0042bee5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bee6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bee7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bee7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bee8  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042beec  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042beee  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042beef  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042bef0  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042bef1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bef2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bef3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bef3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042bef7  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0042bef9:
    // 0042bef9  833800                 +cmp dword ptr [eax], 0
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
    // 0042befc  750d                   -jne 0x42bf0b
    if (!cpu.flags.zf)
    {
        goto L_0x0042bf0b;
    }
    // 0042befe  41                     -inc ecx
    (cpu.ecx)++;
    // 0042beff  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bf02  83f903                 +cmp ecx, 3
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
    // 0042bf05  7cf2                   -jl 0x42bef9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042bef9;
    }
    // 0042bf07  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042bf09  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042bf0b:
    // 0042bf0b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bf0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bf0e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bf0e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042bf0f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042bf11  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042bf14  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042bf17  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042bf18  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bf19  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bf1a  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0042bf1c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bf1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf20  83ceff                 -or esi, 0xffffffff
    cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042bf23  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042bf24  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042bf26  c745fc03000000         -mov dword ptr [ebp - 4], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 3 /*0x3*/;
    // 0042bf2d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042bf2f  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0042bf32  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042bf35  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042bf36  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042bf38  83650c00               -and dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042bf3c  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042bf3e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0042bf40  2bda                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042bf42  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
L_0x0042bf44:
    // 0042bf44  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042bf46  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042bf48  23ce                   -and ecx, esi
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.esi));
    // 0042bf4a  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0042bf4d  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042bf4f  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0042bf51  0b450c                 -or eax, dword ptr [ebp + 0xc]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0042bf54  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0042bf56  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042bf59  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042bf5b  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bf5e  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042bf60  ff4dfc                 +dec dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042bf63  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042bf66  75dc                   -jne 0x42bf44
    if (!cpu.flags.zf)
    {
        goto L_0x0042bf44;
    }
    // 0042bf68  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042bf6b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042bf6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf6e  8bf7                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0042bf70  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042bf72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf73  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
L_0x0042bf76:
    // 0042bf76  3bdf                   +cmp ebx, edi
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
    // 0042bf78  7c0f                   -jl 0x42bf89
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042bf89;
    }
    // 0042bf7a  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bf7d  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042bf7f  2bc6                   +sub eax, esi
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
    // 0042bf81  8b0410                 -mov eax, dword ptr [eax + edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 1);
    // 0042bf84  890411                 -mov dword ptr [ecx + edx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 0042bf87  eb07                   -jmp 0x42bf90
    goto L_0x0042bf90;
L_0x0042bf89:
    // 0042bf89  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bf8c  83240100               -and dword ptr [ecx + eax], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042bf90:
    // 0042bf90  4b                     -dec ebx
    (cpu.ebx)--;
    // 0042bf91  83e904                 +sub ecx, 4
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
    // 0042bf94  79e0                   -jns 0x42bf76
    if (!cpu.flags.sf)
    {
        goto L_0x0042bf76;
    }
    // 0042bf96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf99  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42bf9b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bf9b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042bf9c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042bf9e  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042bfa1  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042bfa4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042bfa5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bfa6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bfa7  0fb7480a               -movzx ecx, word ptr [eax + 0xa]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */));
    // 0042bfab  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042bfad  81e100800000           -and ecx, 0x8000
    cpu.ecx &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0042bfb3  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042bfb6  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0042bfb9  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0042bfbc  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0042bfbf  0fb700                 -movzx eax, word ptr [eax]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.eax));
    // 0042bfc2  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042bfc5  81e3ff7f0000           -and ebx, 0x7fff
    cpu.ebx &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 0042bfcb  81ebff3f0000           -sub ebx, 0x3fff
    (cpu.ebx) -= x86::reg32(x86::sreg32(16383 /*0x3fff*/));
    // 0042bfd1  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0042bfd4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0042bfd7  81fb01c0ffff           +cmp ebx, 0xffffc001
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294950913 /*0xffffc001*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bfdd  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0042bfe0  7526                   -jne 0x42c008
    if (!cpu.flags.zf)
    {
        goto L_0x0042c008;
    }
    // 0042bfe2  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042bfe5  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042bfe7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bfe8  e806ffffff             -call 0x42bef3
    cpu.esp -= 4;
    sub_42bef3(app, cpu);
    // 0042bfed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042bfef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bff0  0f85d1000000           -jne 0x42c0c7
    if (!cpu.flags.zf)
    {
        goto L_0x0042c0c7;
    }
    // 0042bff6  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042bff9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bffa  e8e8feffff             -call 0x42bee7
    cpu.esp -= 4;
    sub_42bee7(app, cpu);
    // 0042bfff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042c000:
    // 0042c000  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
L_0x0042c002:
    // 0042c002  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c003  e9c1000000             -jmp 0x42c0c9
    goto L_0x0042c0c9;
L_0x0042c008:
    // 0042c008  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c00b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c00c  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042c00f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c010  e8b7feffff             -call 0x42becc
    cpu.esp -= 4;
    sub_42becc(app, cpu);
    // 0042c015  ff7708                 -push dword ptr [edi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c018  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c01b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c01c  e81ffeffff             -call 0x42be40
    cpu.esp -= 4;
    sub_42be40(app, cpu);
    // 0042c021  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042c024  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c026  7401                   -je 0x42c029
    if (cpu.flags.zf)
    {
        goto L_0x0042c029;
    }
    // 0042c028  43                     -inc ebx
    (cpu.ebx)++;
L_0x0042c029:
    // 0042c029  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c02c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042c02e  2b4f08                 -sub ecx, dword ptr [edi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0042c031  3bd9                   +cmp ebx, ecx
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
    // 0042c033  7d0c                   -jge 0x42c041
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042c041;
    }
    // 0042c035  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c038  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c039  e8a9feffff             -call 0x42bee7
    cpu.esp -= 4;
    sub_42bee7(app, cpu);
    // 0042c03e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c03f  eb3c                   -jmp 0x42c07d
    goto L_0x0042c07d;
L_0x0042c041:
    // 0042c041  3bd8                   +cmp ebx, eax
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
    // 0042c043  7f3f                   -jg 0x42c084
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042c084;
    }
    // 0042c045  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c047  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042c049  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042c04c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c04d  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c050  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c051  e876feffff             -call 0x42becc
    cpu.esp -= 4;
    sub_42becc(app, cpu);
    // 0042c056  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c059  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c05a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c05b  e8aefeffff             -call 0x42bf0e
    cpu.esp -= 4;
    sub_42bf0e(app, cpu);
    // 0042c060  ff7708                 -push dword ptr [edi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c063  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c066  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c067  e8d4fdffff             -call 0x42be40
    cpu.esp -= 4;
    sub_42be40(app, cpu);
    // 0042c06c  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0042c06f  40                     -inc eax
    (cpu.eax)++;
    // 0042c070  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c071  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c074  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c075  e894feffff             -call 0x42bf0e
    cpu.esp -= 4;
    sub_42bf0e(app, cpu);
    // 0042c07a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0042c07d:
    // 0042c07d  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0042c07f  e97cffffff             -jmp 0x42c000
    goto L_0x0042c000;
L_0x0042c084:
    // 0042c084  3b1f                   +cmp ebx, dword ptr [edi]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c086  7c28                   -jl 0x42c0b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c0b0;
    }
    // 0042c088  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c08b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c08c  e856feffff             -call 0x42bee7
    cpu.esp -= 4;
    sub_42bee7(app, cpu);
    // 0042c091  ff770c                 -push dword ptr [edi + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c094  804df780               -or byte ptr [ebp - 9], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-9) /* -0x9 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0042c098  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c09b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c09c  e86dfeffff             -call 0x42bf0e
    cpu.esp -= 4;
    sub_42bf0e(app, cpu);
    // 0042c0a1  8b7714                 -mov esi, dword ptr [edi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0042c0a4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c0a7  0337                   +add esi, dword ptr [edi]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042c0a9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042c0ab  e952ffffff             -jmp 0x42c002
    goto L_0x0042c002;
L_0x0042c0b0:
    // 0042c0b0  ff770c                 -push dword ptr [edi + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c0b3  8b7714                 -mov esi, dword ptr [edi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0042c0b6  8065f77f               -and byte ptr [ebp - 9], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-9) /* -0x9 */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0042c0ba  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c0bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c0be  03f3                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c0c0  e849feffff             -call 0x42bf0e
    cpu.esp -= 4;
    sub_42bf0e(app, cpu);
    // 0042c0c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c0c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042c0c7:
    // 0042c0c7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042c0c9:
    // 0042c0c9  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 0042c0cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c0cc  2b4f0c                 -sub ecx, dword ptr [edi + 0xc]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 0042c0cf  8b7f10                 -mov edi, dword ptr [edi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0042c0d2  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0042c0d4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c0d7  f7d9                   +neg ecx
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
    // 0042c0d9  1bc9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0042c0db  81e100000080           -and ecx, 0x80000000
    cpu.ecx &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0042c0e1  0bf1                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c0e3  0b75f4                 -or esi, dword ptr [ebp - 0xc]
    cpu.esi |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0042c0e6  83ff40                 +cmp edi, 0x40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c0e9  750d                   -jne 0x42c0f8
    if (!cpu.flags.zf)
    {
        goto L_0x0042c0f8;
    }
    // 0042c0eb  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c0ee  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042c0f1  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0042c0f4  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0042c0f6  eb0a                   -jmp 0x42c102
    goto L_0x0042c102;
L_0x0042c0f8:
    // 0042c0f8  83ff20                 +cmp edi, 0x20
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
    // 0042c0fb  7505                   -jne 0x42c102
    if (!cpu.flags.zf)
    {
        goto L_0x0042c102;
    }
    // 0042c0fd  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c100  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
L_0x0042c102:
    // 0042c102  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c103  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c104  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c105  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c106  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c107(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c107  6840d84300             -push 0x43d840
    app->getMemory<x86::reg32>(cpu.esp-4) = 4446272 /*0x43d840*/;
    cpu.esp -= 4;
    // 0042c10c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c110  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c114  e882feffff             -call 0x42bf9b
    cpu.esp -= 4;
    sub_42bf9b(app, cpu);
    // 0042c119  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c11c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c11d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c11d  6858d84300             -push 0x43d858
    app->getMemory<x86::reg32>(cpu.esp-4) = 4446296 /*0x43d858*/;
    cpu.esp -= 4;
    // 0042c122  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c126  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c12a  e86cfeffff             -call 0x42bf9b
    cpu.esp -= 4;
    sub_42bf9b(app, cpu);
    // 0042c12f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c133(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c133  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c134  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c136  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c139  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042c13b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c13c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c13d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c13e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c13f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c142  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c145  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c146  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c149  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c14a  e8491b0000             -call 0x42dc98
    cpu.esp -= 4;
    sub_42dc98(app, cpu);
    // 0042c14f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c152  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c155  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c156  e8acffffff             -call 0x42c107
    cpu.esp -= 4;
    sub_42c107(app, cpu);
    // 0042c15b  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0042c15e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c15f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c160  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c161  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c163  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c166  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042c168  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c169  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c16a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c16b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c16c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c16f  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c172  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c173  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c176  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c177  e81c1b0000             -call 0x42dc98
    cpu.esp -= 4;
    sub_42dc98(app, cpu);
    // 0042c17c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c17f  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c182  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c183  e895ffffff             -call 0x42c11d
    cpu.esp -= 4;
    sub_42c11d(app, cpu);
    // 0042c188  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0042c18b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c18c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c190  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c191  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c195  eb6a                   -jmp 0x42c201
    return sub_42c201(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42c1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c1a0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042c1a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c1a5  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c1ab  740f                   -je 0x42c1bc
    if (cpu.flags.zf)
    {
        goto L_0x0042c1bc;
    }
L_0x0042c1ad:
    // 0042c1ad  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042c1af  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c1b0  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042c1b2  743b                   -je 0x42c1ef
    if (cpu.flags.zf)
    {
        goto L_0x0042c1ef;
    }
    // 0042c1b4  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c1ba  75f1                   -jne 0x42c1ad
    if (!cpu.flags.zf)
    {
        goto L_0x0042c1ad;
    }
L_0x0042c1bc:
    // 0042c1bc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c1be  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0042c1c3  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c1c5  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042c1c8  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042c1ca  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c1cd  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0042c1d2  74e8                   -je 0x42c1bc
    if (cpu.flags.zf)
    {
        goto L_0x0042c1bc;
    }
    // 0042c1d4  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0042c1d7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042c1d9  7423                   -je 0x42c1fe
    if (cpu.flags.zf)
    {
        goto L_0x0042c1fe;
    }
    // 0042c1db  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0042c1dd  741a                   -je 0x42c1f9
    if (cpu.flags.zf)
    {
        goto L_0x0042c1f9;
    }
    // 0042c1df  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 0042c1e4  740e                   -je 0x42c1f4
    if (cpu.flags.zf)
    {
        goto L_0x0042c1f4;
    }
    // 0042c1e6  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0042c1eb  7402                   -je 0x42c1ef
    if (cpu.flags.zf)
    {
        goto L_0x0042c1ef;
    }
    // 0042c1ed  ebcd                   -jmp 0x42c1bc
    goto L_0x0042c1bc;
L_0x0042c1ef:
    // 0042c1ef  8d79ff                 -lea edi, [ecx - 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0042c1f2  eb0d                   -jmp 0x42c201
    goto L_0x0042c201;
L_0x0042c1f4:
    // 0042c1f4  8d79fe                 -lea edi, [ecx - 2]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0042c1f7  eb08                   -jmp 0x42c201
    goto L_0x0042c201;
L_0x0042c1f9:
    // 0042c1f9  8d79fd                 -lea edi, [ecx - 3]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 0042c1fc  eb03                   -jmp 0x42c201
    goto L_0x0042c201;
L_0x0042c1fe:
    // 0042c1fe  8d79fc                 -lea edi, [ecx - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
L_0x0042c201:
    // 0042c201  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042c205  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c20b  7419                   -je 0x42c226
    if (cpu.flags.zf)
    {
        goto L_0x0042c226;
    }
L_0x0042c20d:
    // 0042c20d  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042c20f  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c210  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042c212  7464                   -je 0x42c278
    if (cpu.flags.zf)
    {
        goto L_0x0042c278;
    }
    // 0042c214  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0042c216  47                     -inc edi
    (cpu.edi)++;
    // 0042c217  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c21d  75ee                   -jne 0x42c20d
    if (!cpu.flags.zf)
    {
        goto L_0x0042c20d;
    }
    // 0042c21f  eb05                   -jmp 0x42c226
    goto L_0x0042c226;
L_0x0042c221:
    // 0042c221  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0042c223  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042c226:
    // 0042c226  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0042c22b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c22d  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c22f  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042c232  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042c234  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c236  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c239  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0042c23e  74e1                   -je 0x42c221
    if (cpu.flags.zf)
    {
        goto L_0x0042c221;
    }
    // 0042c240  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042c242  7434                   -je 0x42c278
    if (cpu.flags.zf)
    {
        goto L_0x0042c278;
    }
    // 0042c244  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0042c246  7427                   -je 0x42c26f
    if (cpu.flags.zf)
    {
        goto L_0x0042c26f;
    }
    // 0042c248  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 0042c24e  7412                   -je 0x42c262
    if (cpu.flags.zf)
    {
        goto L_0x0042c262;
    }
    // 0042c250  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 0042c256  7402                   -je 0x42c25a
    if (cpu.flags.zf)
    {
        goto L_0x0042c25a;
    }
    // 0042c258  ebc7                   -jmp 0x42c221
    goto L_0x0042c221;
L_0x0042c25a:
    // 0042c25a  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0042c25c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c260  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c261  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c262:
    // 0042c262  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0042c265  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c269  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0042c26d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c26e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c26f:
    // 0042c26f  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0042c272  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c276  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c277  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c278:
    // 0042c278  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0042c27a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c27e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c27f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c201(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0042c201;
    // 0042c1a0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042c1a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c1a5  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c1ab  740f                   -je 0x42c1bc
    if (cpu.flags.zf)
    {
        goto L_0x0042c1bc;
    }
L_0x0042c1ad:
    // 0042c1ad  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042c1af  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c1b0  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042c1b2  743b                   -je 0x42c1ef
    if (cpu.flags.zf)
    {
        goto L_0x0042c1ef;
    }
    // 0042c1b4  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c1ba  75f1                   -jne 0x42c1ad
    if (!cpu.flags.zf)
    {
        goto L_0x0042c1ad;
    }
L_0x0042c1bc:
    // 0042c1bc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c1be  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0042c1c3  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c1c5  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042c1c8  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042c1ca  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c1cd  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0042c1d2  74e8                   -je 0x42c1bc
    if (cpu.flags.zf)
    {
        goto L_0x0042c1bc;
    }
    // 0042c1d4  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0042c1d7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042c1d9  7423                   -je 0x42c1fe
    if (cpu.flags.zf)
    {
        goto L_0x0042c1fe;
    }
    // 0042c1db  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0042c1dd  741a                   -je 0x42c1f9
    if (cpu.flags.zf)
    {
        goto L_0x0042c1f9;
    }
    // 0042c1df  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 0042c1e4  740e                   -je 0x42c1f4
    if (cpu.flags.zf)
    {
        goto L_0x0042c1f4;
    }
    // 0042c1e6  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0042c1eb  7402                   -je 0x42c1ef
    if (cpu.flags.zf)
    {
        goto L_0x0042c1ef;
    }
    // 0042c1ed  ebcd                   -jmp 0x42c1bc
    goto L_0x0042c1bc;
L_0x0042c1ef:
    // 0042c1ef  8d79ff                 -lea edi, [ecx - 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0042c1f2  eb0d                   -jmp 0x42c201
    goto L_0x0042c201;
L_0x0042c1f4:
    // 0042c1f4  8d79fe                 -lea edi, [ecx - 2]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0042c1f7  eb08                   -jmp 0x42c201
    goto L_0x0042c201;
L_0x0042c1f9:
    // 0042c1f9  8d79fd                 -lea edi, [ecx - 3]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 0042c1fc  eb03                   -jmp 0x42c201
    goto L_0x0042c201;
L_0x0042c1fe:
    // 0042c1fe  8d79fc                 -lea edi, [ecx - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
L_0x0042c201:
L_entry_0x0042c201:
    // 0042c201  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042c205  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c20b  7419                   -je 0x42c226
    if (cpu.flags.zf)
    {
        goto L_0x0042c226;
    }
L_0x0042c20d:
    // 0042c20d  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042c20f  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c210  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042c212  7464                   -je 0x42c278
    if (cpu.flags.zf)
    {
        goto L_0x0042c278;
    }
    // 0042c214  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0042c216  47                     -inc edi
    (cpu.edi)++;
    // 0042c217  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0042c21d  75ee                   -jne 0x42c20d
    if (!cpu.flags.zf)
    {
        goto L_0x0042c20d;
    }
    // 0042c21f  eb05                   -jmp 0x42c226
    goto L_0x0042c226;
L_0x0042c221:
    // 0042c221  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0042c223  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042c226:
    // 0042c226  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0042c22b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c22d  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c22f  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042c232  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042c234  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c236  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c239  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0042c23e  74e1                   -je 0x42c221
    if (cpu.flags.zf)
    {
        goto L_0x0042c221;
    }
    // 0042c240  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042c242  7434                   -je 0x42c278
    if (cpu.flags.zf)
    {
        goto L_0x0042c278;
    }
    // 0042c244  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0042c246  7427                   -je 0x42c26f
    if (cpu.flags.zf)
    {
        goto L_0x0042c26f;
    }
    // 0042c248  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 0042c24e  7412                   -je 0x42c262
    if (cpu.flags.zf)
    {
        goto L_0x0042c262;
    }
    // 0042c250  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 0042c256  7402                   -je 0x42c25a
    if (cpu.flags.zf)
    {
        goto L_0x0042c25a;
    }
    // 0042c258  ebc7                   -jmp 0x42c221
    goto L_0x0042c221;
L_0x0042c25a:
    // 0042c25a  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0042c25c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c260  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c261  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c262:
    // 0042c262  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0042c265  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c269  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0042c26d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c26e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c26f:
    // 0042c26f  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 0042c272  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c276  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c277  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c278:
    // 0042c278  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0042c27a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042c27e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c27f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c280  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c281  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c283  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c286  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c287  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c28a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c28b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c28e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042c291  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c292  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042c295  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 0042c298  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042c29a  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042c29c  7e1f                   -jle 0x42c2bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c2bd;
    }
    // 0042c29e  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0042c2a1  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042c2a3:
    // 0042c2a3  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042c2a5  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042c2a7  7406                   -je 0x42c2af
    if (cpu.flags.zf)
    {
        goto L_0x0042c2af;
    }
    // 0042c2a9  0fbed2                 -movsx edx, dl
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 0042c2ac  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042c2ad  eb03                   -jmp 0x42c2b2
    goto L_0x0042c2b2;
L_0x0042c2af:
    // 0042c2af  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 0042c2b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042c2b2:
    // 0042c2b2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0042c2b4  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042c2b5  ff4d08                 +dec dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042c2b8  75e9                   -jne 0x42c2a3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c2a3;
    }
    // 0042c2ba  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x0042c2bd:
    // 0042c2bd  802000                 -and byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042c2c0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042c2c2  7c12                   -jl 0x42c2d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c2d6;
    }
    // 0042c2c4  803935                 +cmp byte ptr [ecx], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c2c7  7c0d                   -jl 0x42c2d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c2d6;
    }
L_0x0042c2c9:
    // 0042c2c9  48                     -dec eax
    (cpu.eax)--;
    // 0042c2ca  803839                 +cmp byte ptr [eax], 0x39
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c2cd  7505                   -jne 0x42c2d4
    if (!cpu.flags.zf)
    {
        goto L_0x0042c2d4;
    }
    // 0042c2cf  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 0042c2d2  ebf5                   -jmp 0x42c2c9
    goto L_0x0042c2c9;
L_0x0042c2d4:
    // 0042c2d4  fe00                   -inc byte ptr [eax]
    (app->getMemory<x86::reg8>(cpu.eax))++;
L_0x0042c2d6:
    // 0042c2d6  803e31                 +cmp byte ptr [esi], 0x31
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(49 /*0x31*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c2d9  7505                   -jne 0x42c2e0
    if (!cpu.flags.zf)
    {
        goto L_0x0042c2e0;
    }
    // 0042c2db  ff4204                 +inc dword ptr [edx + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042c2de  eb12                   -jmp 0x42c2f2
    goto L_0x0042c2f2;
L_0x0042c2e0:
    // 0042c2e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c2e1  e8eabaffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c2e6  40                     -inc eax
    (cpu.eax)++;
    // 0042c2e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c2e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c2e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c2ea  e881efffff             -call 0x42b270
    cpu.esp -= 4;
    sub_42b270(app, cpu);
    // 0042c2ef  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042c2f2:
    // 0042c2f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c2f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c2f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c2f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c2f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c2f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c2f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c2f8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c2fa  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c2fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c2fe  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c301  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c302  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c303  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c306  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c307  e84f000000             -call 0x42c35b
    cpu.esp -= 4;
    sub_42c35b(app, cpu);
    // 0042c30c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c30d  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0042c310  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c311  6878554900             -push 0x495578
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806008 /*0x495578*/;
    cpu.esp -= 4;
    // 0042c316  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042c318  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0042c31a  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c31d  8bfc                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0042c31f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042c320  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042c321  66a5                   -movsw word ptr es:[edi], word ptr [esi]
    app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 2;
        cpu.esi -= 2;
    }
    else
    {
        cpu.edi += 2;
        cpu.esi += 2;
    }
    // 0042c323  e8411e0000             -call 0x42e169
    cpu.esp -= 4;
    sub_42e169(app, cpu);
    // 0042c328  a3a0554900             -mov dword ptr [0x4955a0], eax
    app->getMemory<x86::reg32>(x86::reg32(4806048) /* 0x4955a0 */) = cpu.eax;
    // 0042c32d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042c330  0fbe057a554900         -movsx eax, byte ptr [0x49557a]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(4806010) /* 0x49557a */)));
    // 0042c337  a398554900             -mov dword ptr [0x495598], eax
    app->getMemory<x86::reg32>(x86::reg32(4806040) /* 0x495598 */) = cpu.eax;
    // 0042c33c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c33d  0fbf0578554900         -movsx eax, word ptr [0x495578]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(4806008) /* 0x495578 */)));
    // 0042c344  a39c554900             -mov dword ptr [0x49559c], eax
    app->getMemory<x86::reg32>(x86::reg32(4806044) /* 0x49559c */) = cpu.eax;
    // 0042c349  c705a45549007c554900   -mov dword ptr [0x4955a4], 0x49557c
    app->getMemory<x86::reg32>(x86::reg32(4806052) /* 0x4955a4 */) = 4806012 /*0x49557c*/;
    // 0042c353  b898554900             -mov eax, 0x495598
    cpu.eax = 4806040 /*0x495598*/;
    // 0042c358  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c359  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c35a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c35b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c35b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c35c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c35e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042c35f  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c362  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c363  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c364  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c365  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0042c369  bfff070000             -mov edi, 0x7ff
    cpu.edi = 2047 /*0x7ff*/;
    // 0042c36e  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042c370  2500800000             -and eax, 0x8000
    cpu.eax &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0042c375  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0042c378  23cf                   -and ecx, edi
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edi));
    // 0042c37a  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042c37d  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0042c380  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0042c382  0fb7d9                 -movzx ebx, cx
    cpu.ebx = x86::reg32(cpu.cx);
    // 0042c385  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 0042c38a  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0042c38f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042c391  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0042c394  7413                   -je 0x42c3a9
    if (cpu.flags.zf)
    {
        goto L_0x0042c3a9;
    }
    // 0042c396  3bdf                   +cmp ebx, edi
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
    // 0042c398  7408                   -je 0x42c3a2
    if (cpu.flags.zf)
    {
        goto L_0x0042c3a2;
    }
    // 0042c39a  8db9003c0000           -lea edi, [ecx + 0x3c00]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(15360) /* 0x3c00 */);
    // 0042c3a0  eb28                   -jmp 0x42c3ca
    goto L_0x0042c3ca;
L_0x0042c3a2:
    // 0042c3a2  bfff7f0000             -mov edi, 0x7fff
    cpu.edi = 32767 /*0x7fff*/;
    // 0042c3a7  eb21                   -jmp 0x42c3ca
    goto L_0x0042c3ca;
L_0x0042c3a9:
    // 0042c3a9  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c3ab  3bc3                   +cmp eax, ebx
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
    // 0042c3ad  7512                   -jne 0x42c3c1
    if (!cpu.flags.zf)
    {
        goto L_0x0042c3c1;
    }
    // 0042c3af  3bd3                   +cmp edx, ebx
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
    // 0042c3b1  750e                   -jne 0x42c3c1
    if (!cpu.flags.zf)
    {
        goto L_0x0042c3c1;
    }
    // 0042c3b3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c3b6  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0042c3b9  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0042c3bb  66895808               -mov word ptr [eax + 8], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 0042c3bf  eb4b                   -jmp 0x42c40c
    goto L_0x0042c40c;
L_0x0042c3c1:
    // 0042c3c1  8db9013c0000           -lea edi, [ecx + 0x3c01]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(15361) /* 0x3c01 */);
    // 0042c3c7  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
L_0x0042c3ca:
    // 0042c3ca  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042c3cc  c1e915                 -shr ecx, 0x15
    cpu.ecx >>= 21 /*0x15*/ % 32;
    // 0042c3cf  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 0042c3d2  0bc8                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0042c3d4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c3d7  0b4dfc                 -or ecx, dword ptr [ebp - 4]
    cpu.ecx |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0042c3da  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 0042c3dd  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0042c3e0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0042c3e2:
    // 0042c3e2  85ce                   +test esi, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.ecx));
    // 0042c3e4  751d                   -jne 0x42c403
    if (!cpu.flags.zf)
    {
        goto L_0x0042c403;
    }
    // 0042c3e6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c3e8  03c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c3ea  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042c3ec  c1eb1f                 -shr ebx, 0x1f
    cpu.ebx >>= 31 /*0x1f*/ % 32;
    // 0042c3ef  0bd9                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c3f1  8d0c12                 -lea ecx, [edx + edx]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0042c3f4  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0042c3f6  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0042c3f9  81c7ffff0000           +add edi, 0xffff
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042c3ff  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042c401  ebdf                   -jmp 0x42c3e2
    goto L_0x0042c3e2;
L_0x0042c403:
    // 0042c403  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c406  0bcf                   -or ecx, edi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0042c408  66894808               -mov word ptr [eax + 8], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.cx;
L_0x0042c40c:
    // 0042c40c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c40d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c40e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c40f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c410  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c411(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c411  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042c413  e8a6a4ffff             -call 0x4268be
    cpu.esp -= 4;
    sub_4268be(app, cpu);
    // 0042c418  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c419  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c41a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c41a  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0042c41e  ff1580004300           -call dword ptr [0x430080]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391040) /* 0x430080 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c424  83f8ff                 +cmp eax, -1
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
    // 0042c427  7511                   -jne 0x42c43a
    if (!cpu.flags.zf)
    {
        goto L_0x0042c43a;
    }
    // 0042c429  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c42f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c430  e840e3ffff             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 0042c435  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042c436:
    // 0042c436  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042c439  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c43a:
    // 0042c43a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0042c43c  741d                   -je 0x42c45b
    if (cpu.flags.zf)
    {
        goto L_0x0042c45b;
    }
    // 0042c43e  f644240802             +test byte ptr [esp + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 0042c443  7416                   -je 0x42c45b
    if (cpu.flags.zf)
    {
        goto L_0x0042c45b;
    }
    // 0042c445  c705e45349000d000000   -mov dword ptr [0x4953e4], 0xd
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 13 /*0xd*/;
    // 0042c44f  c705e853490005000000   -mov dword ptr [0x4953e8], 5
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = 5 /*0x5*/;
    // 0042c459  ebdb                   -jmp 0x42c436
    goto L_0x0042c436;
L_0x0042c45b:
    // 0042c45b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042c45d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c45e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c45e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c45f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c461  833ddc5a490000         +cmp dword ptr [0x495adc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4807388) /* 0x495adc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c468  750f                   -jne 0x42c479
    if (!cpu.flags.zf)
    {
        goto L_0x0042c479;
    }
    // 0042c46a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c46d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c470  e82bd5ffff             -call 0x4299a0
    cpu.esp -= 4;
    sub_4299a0(app, cpu);
    // 0042c475  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c477  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c478  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c479:
    // 0042c479  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x0042c47c:
    // 0042c47c  660fb601               -movzx ax, byte ptr [ecx]
    cpu.ax = x86::reg16(app->getMemory<x86::reg8>(cpu.ecx));
    // 0042c480  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0042c483  743a                   -je 0x42c4bf
    if (cpu.flags.zf)
    {
        goto L_0x0042c4bf;
    }
    // 0042c485  0fb6d0                 -movzx edx, al
    cpu.edx = x86::reg32(cpu.al);
    // 0042c488  f682e15b490004         +test byte ptr [edx + 0x495be1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4807649) /* 0x495be1 */) & 4 /*0x4*/));
    // 0042c48f  741a                   -je 0x42c4ab
    if (cpu.flags.zf)
    {
        goto L_0x0042c4ab;
    }
    // 0042c491  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0042c494  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c495  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042c497  741d                   -je 0x42c4b6
    if (cpu.flags.zf)
    {
        goto L_0x0042c4b6;
    }
    // 0042c499  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 0042c49c  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 0042c49f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0042c4a2  0bc2                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0042c4a4  39450c                 +cmp dword ptr [ebp + 0xc], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c4a7  7411                   -je 0x42c4ba
    if (cpu.flags.zf)
    {
        goto L_0x0042c4ba;
    }
    // 0042c4a9  eb08                   -jmp 0x42c4b3
    goto L_0x0042c4b3;
L_0x0042c4ab:
    // 0042c4ab  0fb7d0                 -movzx edx, ax
    cpu.edx = x86::reg32(cpu.ax);
    // 0042c4ae  39550c                 +cmp dword ptr [ebp + 0xc], edx
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
    // 0042c4b1  740c                   -je 0x42c4bf
    if (cpu.flags.zf)
    {
        goto L_0x0042c4bf;
    }
L_0x0042c4b3:
    // 0042c4b3  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042c4b4  ebc6                   -jmp 0x42c47c
    goto L_0x0042c47c;
L_0x0042c4b6:
    // 0042c4b6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042c4b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c4b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c4ba:
    // 0042c4ba  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0042c4bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c4be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c4bf:
    // 0042c4bf  0fb7d0                 -movzx edx, ax
    cpu.edx = x86::reg32(cpu.ax);
    // 0042c4c2  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c4c5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042c4c7  f7d8                   +neg eax
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
    // 0042c4c9  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0042c4cb  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0042c4cd  23c1                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c4cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c4d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c4d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c4d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c4d2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c4d4  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042c4d6  3905dc5a4900           +cmp dword ptr [0x495adc], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4807388) /* 0x495adc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c4dc  750f                   -jne 0x42c4ed
    if (!cpu.flags.zf)
    {
        goto L_0x0042c4ed;
    }
    // 0042c4de  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c4e1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c4e4  e8171f0000             -call 0x42e400
    cpu.esp -= 4;
    sub_42e400(app, cpu);
    // 0042c4e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c4ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c4eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c4ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c4ed:
    // 0042c4ed  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c4f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042c4f2:
    // 0042c4f2  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0042c4f4  0fb6cb                 -movzx ecx, bl
    cpu.ecx = x86::reg32(cpu.bl);
    // 0042c4f7  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 0042c4fa  f686e15b490004         +test byte ptr [esi + 0x495be1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4807649) /* 0x495be1 */) & 4 /*0x4*/));
    // 0042c501  741e                   -je 0x42c521
    if (cpu.flags.zf)
    {
        goto L_0x0042c521;
    }
    // 0042c503  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0042c506  42                     -inc edx
    (cpu.edx)++;
    // 0042c507  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0042c509  7412                   -je 0x42c51d
    if (cpu.flags.zf)
    {
        goto L_0x0042c51d;
    }
    // 0042c50b  0fb6f3                 -movzx esi, bl
    cpu.esi = x86::reg32(cpu.bl);
    // 0042c50e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0042c511  0bce                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0042c513  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c516  7510                   -jne 0x42c528
    if (!cpu.flags.zf)
    {
        goto L_0x0042c528;
    }
    // 0042c518  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0042c51b  eb0b                   -jmp 0x42c528
    goto L_0x0042c528;
L_0x0042c51d:
    // 0042c51d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c51f  eb03                   -jmp 0x42c524
    goto L_0x0042c524;
L_0x0042c521:
    // 0042c521  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x0042c524:
    // 0042c524  7502                   -jne 0x42c528
    if (!cpu.flags.zf)
    {
        goto L_0x0042c528;
    }
    // 0042c526  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0042c528:
    // 0042c528  42                     -inc edx
    (cpu.edx)++;
    // 0042c529  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0042c52b  75c5                   -jne 0x42c4f2
    if (!cpu.flags.zf)
    {
        goto L_0x0042c4f2;
    }
    // 0042c52d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c52e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c52f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c530  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c531(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c531  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c532  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c534  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0042c537  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c53a  8065ff00               -and byte ptr [ebp - 1], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042c53e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c53f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c540  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c541  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042c543  3bc7                   +cmp eax, edi
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
    // 0042c545  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 0042c548  7415                   -je 0x42c55f
    if (cpu.flags.zf)
    {
        goto L_0x0042c55f;
    }
    // 0042c54a  83f801                 +cmp eax, 1
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
    // 0042c54d  7410                   -je 0x42c55f
    if (cpu.flags.zf)
    {
        goto L_0x0042c55f;
    }
    // 0042c54f  7e30                   -jle 0x42c581
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c581;
    }
    // 0042c551  83f803                 +cmp eax, 3
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
    // 0042c554  7e09                   -jle 0x42c55f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c55f;
    }
    // 0042c556  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c559  7526                   -jne 0x42c581
    if (!cpu.flags.zf)
    {
        goto L_0x0042c581;
    }
    // 0042c55b  c645ff01               -mov byte ptr [ebp - 1], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = 1 /*0x1*/;
L_0x0042c55f:
    // 0042c55f  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c562  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0042c565:
    // 0042c565  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042c567  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042c569  742b                   -je 0x42c596
    if (cpu.flags.zf)
    {
        goto L_0x0042c596;
    }
L_0x0042c56b:
    // 0042c56b  40                     -inc eax
    (cpu.eax)++;
    // 0042c56c  803800                 +cmp byte ptr [eax], 0
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
    // 0042c56f  75fa                   -jne 0x42c56b
    if (!cpu.flags.zf)
    {
        goto L_0x0042c56b;
    }
    // 0042c571  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c575  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042c578  74eb                   -je 0x42c565
    if (cpu.flags.zf)
    {
        goto L_0x0042c565;
    }
    // 0042c57a  c60020                 -mov byte ptr [eax], 0x20
    app->getMemory<x86::reg8>(cpu.eax) = 32 /*0x20*/;
    // 0042c57d  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042c57f  ebe4                   -jmp 0x42c565
    goto L_0x0042c565;
L_0x0042c581:
    // 0042c581  c705e453490016000000   -mov dword ptr [0x4953e4], 0x16
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 22 /*0x16*/;
    // 0042c58b  893de8534900           -mov dword ptr [0x4953e8], edi
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.edi;
    // 0042c591  e91c010000             -jmp 0x42c6b2
    goto L_0x0042c6b2;
L_0x0042c596:
    // 0042c596  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 0042c598  8d45a0                 -lea eax, [ebp - 0x60]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 0042c59b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c59c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c59d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c59e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c59f  e86cecffff             -call 0x42b210
    cpu.esp -= 4;
    sub_42b210(app, cpu);
    // 0042c5a4  8975a0                 -mov dword ptr [ebp - 0x60], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.esi;
    // 0042c5a7  8b35005e4900           -mov esi, dword ptr [0x495e00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4808192) /* 0x495e00 */);
    // 0042c5ad  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c5b0  3bf7                   +cmp esi, edi
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
    // 0042c5b2  7421                   -je 0x42c5d5
    if (cpu.flags.zf)
    {
        goto L_0x0042c5d5;
    }
    // 0042c5b4  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
L_0x0042c5b7:
    // 0042c5b7  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042c5b9  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042c5bb  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0042c5be  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042c5c1  8b0c8d005d4900         -mov ecx, dword ptr [ecx*4 + 0x495d00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.ecx * 4);
    // 0042c5c8  807cd10400             +cmp byte ptr [ecx + edx*8 + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edx * 8);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c5cd  7506                   -jne 0x42c5d5
    if (!cpu.flags.zf)
    {
        goto L_0x0042c5d5;
    }
    // 0042c5cf  4e                     -dec esi
    (cpu.esi)--;
    // 0042c5d0  48                     -dec eax
    (cpu.eax)--;
    // 0042c5d1  3bf7                   +cmp esi, edi
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
    // 0042c5d3  75e2                   -jne 0x42c5b7
    if (!cpu.flags.zf)
    {
        goto L_0x0042c5b7;
    }
L_0x0042c5d5:
    // 0042c5d5  8d44b604               -lea eax, [esi + esi*4 + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.esi * 4);
    // 0042c5d9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042c5db  668945d2               -mov word ptr [ebp - 0x2e], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-46) /* -0x2e */) = cpu.ax;
    // 0042c5df  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 0042c5e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c5e3  e81fa3ffff             -call 0x426907
    cpu.esp -= 4;
    sub_426907(app, cpu);
    // 0042c5e8  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0042c5eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c5ec  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0042c5ee  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0042c5f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c5f2  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c5f4  3bf7                   +cmp esi, edi
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
    // 0042c5f6  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042c5f9  8d543004               -lea edx, [eax + esi + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 0042c5fd  7e37                   -jle 0x42c636
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c636;
    }
L_0x0042c5ff:
    // 0042c5ff  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042c601  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0042c603  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0042c606  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0042c609  8b0485005d4900         -mov eax, dword ptr [eax*4 + 0x495d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4807936) /* 0x495d00 */ + cpu.eax * 4);
    // 0042c610  8d3cf8                 -lea edi, [eax + edi*8]
    cpu.edi = x86::reg32(cpu.eax + cpu.edi * 8);
    // 0042c613  8a4704                 -mov al, byte ptr [edi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c616  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0042c618  7508                   -jne 0x42c622
    if (!cpu.flags.zf)
    {
        goto L_0x0042c622;
    }
    // 0042c61a  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 0042c61c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042c61e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0042c620  eb06                   -jmp 0x42c628
    goto L_0x0042c628;
L_0x0042c622:
    // 0042c622  802100                 -and byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042c625  830aff                 -or dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042c628:
    // 0042c628  43                     -inc ebx
    (cpu.ebx)++;
    // 0042c629  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c62a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c62d  3bde                   +cmp ebx, esi
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
    // 0042c62f  7cce                   -jl 0x42c5ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c5ff;
    }
    // 0042c631  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0042c634  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0042c636:
    // 0042c636  807dff00               +cmp byte ptr [ebp - 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c63a  742d                   -je 0x42c669
    if (cpu.flags.zf)
    {
        goto L_0x0042c669;
    }
    // 0042c63c  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042c63f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042c641  8d443004               -lea eax, [eax + esi + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
L_0x0042c645:
    // 0042c645  83fe03                 +cmp esi, 3
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
    // 0042c648  7d04                   -jge 0x42c64e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042c64e;
    }
    // 0042c64a  8bde                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0042c64c  eb03                   -jmp 0x42c651
    goto L_0x0042c651;
L_0x0042c64e:
    // 0042c64e  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042c650  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042c651:
    // 0042c651  3bd3                   +cmp edx, ebx
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
    // 0042c653  7d0d                   -jge 0x42c662
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042c662;
    }
    // 0042c655  802100                 -and byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042c658  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042c65b  42                     -inc edx
    (cpu.edx)++;
    // 0042c65c  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c65d  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042c660  ebe3                   -jmp 0x42c645
    goto L_0x0042c645;
L_0x0042c662:
    // 0042c662  c745f808000000         -mov dword ptr [ebp - 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 8 /*0x8*/;
L_0x0042c669:
    // 0042c669  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042c66c  893de4534900           -mov dword ptr [0x4953e4], edi
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = cpu.edi;
    // 0042c672  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c673  8d45a0                 -lea eax, [ebp - 0x60]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 0042c676  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c677  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c678  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042c67b  893de8534900           -mov dword ptr [0x4953e8], edi
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = cpu.edi;
    // 0042c681  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0042c684  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042c686  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c687  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c688  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0042c68b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042c68e  ff1574004300           -call dword ptr [0x430074]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391028) /* 0x430074 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c694  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042c696  ff1594004300           -call dword ptr [0x430094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391060) /* 0x430094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c69c  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 0042c69f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042c6a1  e8a087ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042c6a6  3bf7                   +cmp esi, edi
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
    // 0042c6a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c6a9  750c                   -jne 0x42c6b7
    if (!cpu.flags.zf)
    {
        goto L_0x0042c6b7;
    }
    // 0042c6ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c6ac  e8c4e0ffff             -call 0x42a775
    cpu.esp -= 4;
    sub_42a775(app, cpu);
    // 0042c6b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042c6b2:
    // 0042c6b2  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042c6b5  eb54                   -jmp 0x42c70b
    goto L_0x0042c70b;
L_0x0042c6b7:
    // 0042c6b7  837d0802               +cmp dword ptr [ebp + 8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c6bb  7506                   -jne 0x42c6c3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c6c3;
    }
    // 0042c6bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c6be  e849b6ffff             -call 0x427d0c
    cpu.esp -= 4;
    sub_427d0c(app, cpu);
L_0x0042c6c3:
    // 0042c6c3  397d08                 +cmp dword ptr [ebp + 8], edi
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
    // 0042c6c6  8b35ac004300           -mov esi, dword ptr [0x4300ac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4391084) /* 0x4300ac */);
    // 0042c6cc  751f                   -jne 0x42c6ed
    if (!cpu.flags.zf)
    {
        goto L_0x0042c6ed;
    }
    // 0042c6ce  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0042c6d0  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042c6d3  ff1578004300           -call dword ptr [0x430078]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391032) /* 0x430078 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c6d9  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c6dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c6dd  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042c6e0  ff157c004300           -call dword ptr [0x43007c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391036) /* 0x43007c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c6e6  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042c6e9  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c6eb  eb16                   -jmp 0x42c703
    goto L_0x0042c703;
L_0x0042c6ed:
    // 0042c6ed  837d0804               +cmp dword ptr [ebp + 8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c6f1  750a                   -jne 0x42c6fd
    if (!cpu.flags.zf)
    {
        goto L_0x0042c6fd;
    }
    // 0042c6f3  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0042c6f6  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c6f8  897d10                 -mov dword ptr [ebp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0042c6fb  eb06                   -jmp 0x42c703
    goto L_0x0042c703;
L_0x0042c6fd:
    // 0042c6fd  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0042c700  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042c703:
    // 0042c703  ff75e8                 -push dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    // 0042c706  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c708  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x0042c70b:
    // 0042c70b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c70c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c70d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c70e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c70f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c710  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c711  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c713  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c714  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c717  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c718  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c719  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042c71b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c71c  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0042c71e:
    // 0042c71e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042c720  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c722  7410                   -je 0x42c734
    if (cpu.flags.zf)
    {
        goto L_0x0042c734;
    }
    // 0042c724  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c725  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042c728  e8a3b6ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c72d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c72e  8d7c0701               -lea edi, [edi + eax + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0042c732  ebea                   -jmp 0x42c71e
    goto L_0x0042c71e;
L_0x0042c734:
    // 0042c734  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c735  e83b87ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042c73a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c73b  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c73e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c740  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042c742  750b                   -jne 0x42c74f
    if (!cpu.flags.zf)
    {
        goto L_0x0042c74f;
    }
    // 0042c744  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042c747  832000                 +and dword ptr [eax], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0042c74a  e9e2000000             -jmp 0x42c831
    goto L_0x0042c831;
L_0x0042c74f:
    // 0042c74f  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c752  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042c754  7416                   -je 0x42c76c
    if (cpu.flags.zf)
    {
        goto L_0x0042c76c;
    }
L_0x0042c756:
    // 0042c756  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042c758  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c75a  7437                   -je 0x42c793
    if (cpu.flags.zf)
    {
        goto L_0x0042c793;
    }
    // 0042c75c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c75d  83c704                 +add edi, 4
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
    // 0042c760  e86bb6ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c765  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c766  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0042c76a  ebea                   -jmp 0x42c756
    goto L_0x0042c756;
L_0x0042c76c:
    // 0042c76c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042c76f  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042c772  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042c775  832000                 -and dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x0042c778:
    // 0042c778  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c77b  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c77d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c780  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042c783  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c785  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c787  0f85c0000000           -jne 0x42c84d
    if (!cpu.flags.zf)
    {
        goto L_0x0042c84d;
    }
L_0x0042c78d:
    // 0042c78d  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042c78e  e9d9000000             -jmp 0x42c86c
    goto L_0x0042c86c;
L_0x0042c793:
    // 0042c793  a1d0534900             -mov eax, dword ptr [0x4953d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    // 0042c798  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c79a  7512                   -jne 0x42c7ae
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7ae;
    }
    // 0042c79c  e8a2e7ffff             -call 0x42af43
    cpu.esp -= 4;
    sub_42af43(app, cpu);
    // 0042c7a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c7a3  a3d0534900             -mov dword ptr [0x4953d0], eax
    app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */) = cpu.eax;
    // 0042c7a8  0f8497000000           -je 0x42c845
    if (cpu.flags.zf)
    {
        goto L_0x0042c845;
    }
L_0x0042c7ae:
    // 0042c7ae  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c7b0  3818                   +cmp byte ptr [eax], bl
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
    // 0042c7b2  7423                   -je 0x42c7d7
    if (cpu.flags.zf)
    {
        goto L_0x0042c7d7;
    }
    // 0042c7b4  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042c7b6  8a0f                   -mov cl, byte ptr [edi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi);
L_0x0042c7b8:
    // 0042c7b8  80f93d                 +cmp cl, 0x3d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c7bb  741a                   -je 0x42c7d7
    if (cpu.flags.zf)
    {
        goto L_0x0042c7d7;
    }
    // 0042c7bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c7be  e80db6ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c7c3  8d5c0301               -lea ebx, [ebx + eax + 1]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0042c7c7  a1d0534900             -mov eax, dword ptr [0x4953d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    // 0042c7cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c7cd  8a0c18                 -mov cl, byte ptr [eax + ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 0042c7d0  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0042c7d3  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042c7d5  75e1                   -jne 0x42c7b8
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7b8;
    }
L_0x0042c7d7:
    // 0042c7d7  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0042c7d9  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042c7db:
    // 0042c7db  80383d                 +cmp byte ptr [eax], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c7de  7529                   -jne 0x42c809
    if (!cpu.flags.zf)
    {
        goto L_0x0042c809;
    }
    // 0042c7e0  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c7e4  7423                   -je 0x42c809
    if (cpu.flags.zf)
    {
        goto L_0x0042c809;
    }
    // 0042c7e6  8078023a               +cmp byte ptr [eax + 2], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c7ea  751d                   -jne 0x42c809
    if (!cpu.flags.zf)
    {
        goto L_0x0042c809;
    }
    // 0042c7ec  8078033d               +cmp byte ptr [eax + 3], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042c7f0  7517                   -jne 0x42c809
    if (!cpu.flags.zf)
    {
        goto L_0x0042c809;
    }
    // 0042c7f2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c7f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c7f6  e8d5b5ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c7fb  8d7c0705               -lea edi, [edi + eax + 5]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5) /* 0x5 */ + cpu.eax * 1);
    // 0042c7ff  a1d0534900             -mov eax, dword ptr [0x4953d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    // 0042c804  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c805  03c7                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042c807  ebd2                   -jmp 0x42c7db
    goto L_0x0042c7db;
L_0x0042c809:
    // 0042c809  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042c80b  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c80d  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042c80f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c810  e86086ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042c815  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c816  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042c819  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c81b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042c81d  0f8555ffffff           -jne 0x42c778
    if (!cpu.flags.zf)
    {
        goto L_0x0042c778;
    }
    // 0042c823  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c826  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 0042c828  e81986ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042c82d  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042c830  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042c831:
    // 0042c831  c705e45349000c000000   -mov dword ptr [0x4953e4], 0xc
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 12 /*0xc*/;
    // 0042c83b  c705e853490008000000   -mov dword ptr [0x4953e8], 8
    app->getMemory<x86::reg32>(x86::reg32(4805608) /* 0x4953e8 */) = 8 /*0x8*/;
L_0x0042c845:
    // 0042c845  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042c848  e9c2000000             -jmp 0x42c90f
    goto L_0x0042c90f;
L_0x0042c84d:
    // 0042c84d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c84e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c84f  e83cf9ffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042c854  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c857  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c859  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c85c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042c85d  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042c860  e86bb5ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c865  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c868  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
L_0x0042c86c:
    // 0042c86c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c86f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c871  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c873  7423                   -je 0x42c898
    if (cpu.flags.zf)
    {
        goto L_0x0042c898;
    }
    // 0042c875  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c876  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c877  e814f9ffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042c87c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042c87f  83451004               -add dword ptr [ebp + 0x10], 4
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c883  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c885  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c886  e845b5ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c88b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c88e  03f0                   +add esi, eax
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
    // 0042c890  c60620                 -mov byte ptr [esi], 0x20
    app->getMemory<x86::reg8>(cpu.esi) = 32 /*0x20*/;
    // 0042c893  e9f5feffff             -jmp 0x42c78d
    goto L_0x0042c78d;
L_0x0042c898:
    // 0042c898  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042c89b  8066ff00               -and byte ptr [esi - 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042c89f  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042c8a2  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 0042c8a6  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c8a8  743e                   -je 0x42c8e8
    if (cpu.flags.zf)
    {
        goto L_0x0042c8e8;
    }
    // 0042c8aa  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042c8ac  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c8ae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c8af  a1d0534900             -mov eax, dword ptr [0x4953d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    // 0042c8b4  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c8b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c8b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c8b8  e803b0ffff             -call 0x4278c0
    cpu.esp -= 4;
    sub_4278c0(app, cpu);
    // 0042c8bd  2bfb                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c8bf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042c8c2  03f7                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0042c8c4  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x0042c8c7:
    // 0042c8c7  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042c8c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c8cb  741b                   -je 0x42c8e8
    if (cpu.flags.zf)
    {
        goto L_0x0042c8e8;
    }
    // 0042c8cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c8ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c8cf  e8bcf8ffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042c8d4  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042c8d6  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c8d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c8da  e8f1b4ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042c8df  83c40c                 +add esp, 0xc
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
    // 0042c8e2  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0042c8e6  ebdf                   -jmp 0x42c8c7
    goto L_0x0042c8c7;
L_0x0042c8e8:
    // 0042c8e8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042c8ea  740e                   -je 0x42c8fa
    if (cpu.flags.zf)
    {
        goto L_0x0042c8fa;
    }
    // 0042c8ec  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042c8ef  3b30                   +cmp esi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c8f1  7504                   -jne 0x42c8f7
    if (!cpu.flags.zf)
    {
        goto L_0x0042c8f7;
    }
    // 0042c8f3  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042c8f6  46                     -inc esi
    (cpu.esi)++;
L_0x0042c8f7:
    // 0042c8f7  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042c8fa:
    // 0042c8fa  ff35d0534900           -push dword ptr [0x4953d0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */);
    cpu.esp -= 4;
    // 0042c900  e84185ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042c905  8325d053490000         -and dword ptr [0x4953d0], 0
    app->getMemory<x86::reg32>(x86::reg32(4805584) /* 0x4953d0 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042c90c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c90d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042c90f:
    // 0042c90f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c910  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c911  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c912  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c913  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42c914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c914  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c915  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042c917  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c918  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c919  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042c91c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c91e  3bf3                   +cmp esi, ebx
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
    // 0042c920  7415                   -je 0x42c937
    if (cpu.flags.zf)
    {
        goto L_0x0042c937;
    }
    // 0042c922  395d10                 +cmp dword ptr [ebp + 0x10], ebx
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
    // 0042c925  7410                   -je 0x42c937
    if (cpu.flags.zf)
    {
        goto L_0x0042c937;
    }
    // 0042c927  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042c929  3ac3                   +cmp al, bl
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
    // 0042c92b  7510                   -jne 0x42c93d
    if (!cpu.flags.zf)
    {
        goto L_0x0042c93d;
    }
    // 0042c92d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c930  3bc3                   +cmp eax, ebx
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
    // 0042c932  7403                   -je 0x42c937
    if (cpu.flags.zf)
    {
        goto L_0x0042c937;
    }
    // 0042c934  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
L_0x0042c937:
    // 0042c937  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042c939:
    // 0042c939  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c93a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c93b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c93c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c93d:
    // 0042c93d  391d7c564900           +cmp dword ptr [0x49567c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806268) /* 0x49567c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c943  7513                   -jne 0x42c958
    if (!cpu.flags.zf)
    {
        goto L_0x0042c958;
    }
    // 0042c945  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042c948  3bcb                   +cmp ecx, ebx
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
    // 0042c94a  7407                   -je 0x42c953
    if (cpu.flags.zf)
    {
        goto L_0x0042c953;
    }
    // 0042c94c  660fb6c0               -movzx ax, al
    cpu.ax = x86::reg16(cpu.al);
    // 0042c950  668901                 -mov word ptr [ecx], ax
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.ax;
L_0x0042c953:
    // 0042c953  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042c955  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c956  ebe1                   -jmp 0x42c939
    goto L_0x0042c939;
L_0x0042c958:
    // 0042c958  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042c95e  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0042c961  f644410180             +test byte ptr [ecx + eax*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 2) & 128 /*0x80*/));
    // 0042c966  744d                   -je 0x42c9b5
    if (cpu.flags.zf)
    {
        goto L_0x0042c9b5;
    }
    // 0042c968  a130d84300             -mov eax, dword ptr [0x43d830]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
    // 0042c96d  83f801                 +cmp eax, 1
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
    // 0042c970  7e2a                   -jle 0x42c99c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c99c;
    }
    // 0042c972  394510                 +cmp dword ptr [ebp + 0x10], eax
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
    // 0042c975  7c2f                   -jl 0x42c9a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c9a6;
    }
    // 0042c977  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c979  395d08                 +cmp dword ptr [ebp + 8], ebx
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
    // 0042c97c  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 0042c97f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042c980  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c983  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c984  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c985  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042c987  ff358c564900           -push dword ptr [0x49568c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    cpu.esp -= 4;
    // 0042c98d  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c993  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c995  a130d84300             -mov eax, dword ptr [0x43d830]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
    // 0042c99a  759d                   -jne 0x42c939
    if (!cpu.flags.zf)
    {
        goto L_0x0042c939;
    }
L_0x0042c99c:
    // 0042c99c  394510                 +cmp dword ptr [ebp + 0x10], eax
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
    // 0042c99f  7205                   -jb 0x42c9a6
    if (cpu.flags.cf)
    {
        goto L_0x0042c9a6;
    }
    // 0042c9a1  385e01                 +cmp byte ptr [esi + 1], bl
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
    // 0042c9a4  7593                   -jne 0x42c939
    if (!cpu.flags.zf)
    {
        goto L_0x0042c939;
    }
L_0x0042c9a6:
    // 0042c9a6  c705e45349002a000000   -mov dword ptr [0x4953e4], 0x2a
    app->getMemory<x86::reg32>(x86::reg32(4805604) /* 0x4953e4 */) = 42 /*0x2a*/;
    // 0042c9b0  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042c9b3  eb84                   -jmp 0x42c939
    goto L_0x0042c939;
L_0x0042c9b5:
    // 0042c9b5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042c9b7  395d08                 +cmp dword ptr [ebp + 8], ebx
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
    // 0042c9ba  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0042c9bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042c9be  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c9c1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042c9c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c9c4  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0042c9c6  ff358c564900           -push dword ptr [0x49568c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    cpu.esp -= 4;
    // 0042c9cc  ff1570004300           -call dword ptr [0x430070]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391024) /* 0x430070 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042c9d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042c9d4  0f8579ffffff           -jne 0x42c953
    if (!cpu.flags.zf)
    {
        goto L_0x0042c953;
    }
    // 0042c9da  ebca                   -jmp 0x42c9a6
    goto L_0x0042c9a6;
}

/* align: skip  */
void Application::asm_sub_42c9dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c9dc  833d30d8430001         +cmp dword ptr [0x43d830], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446256) /* 0x43d830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c9e3  7e0e                   -jle 0x42c9f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c9f3;
    }
    // 0042c9e5  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042c9e7  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042c9eb  e871f2ffff             -call 0x42bc61
    cpu.esp -= 4;
    sub_42bc61(app, cpu);
    // 0042c9f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c9f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c9f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042c9f3:
    // 0042c9f3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042c9f7  8b0d20d64300           -mov ecx, dword ptr [0x43d620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4445728) /* 0x43d620 */);
    // 0042c9fd  8a0441                 -mov al, byte ptr [ecx + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 2);
    // 0042ca00  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042ca03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ca10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ca10  80f940                 +cmp cl, 0x40
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ca13  7315                   -jae 0x42ca2a
    if (!cpu.flags.cf)
    {
        goto L_0x0042ca2a;
    }
    // 0042ca15  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ca18  7306                   -jae 0x42ca20
    if (!cpu.flags.cf)
    {
        goto L_0x0042ca20;
    }
    // 0042ca1a  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 0042ca1d  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0042ca1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ca20:
    // 0042ca20  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042ca22  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ca24  80e11f                 -and cl, 0x1f
    cpu.cl &= x86::reg8(x86::sreg8(31 /*0x1f*/));
    // 0042ca27  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0042ca29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ca2a:
    // 0042ca2a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ca2c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042ca2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42ca2f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ca2f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ca30  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042ca34  83fbff                 +cmp ebx, -1
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
    // 0042ca37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ca38  7441                   -je 0x42ca7b
    if (cpu.flags.zf)
    {
        goto L_0x0042ca7b;
    }
    // 0042ca3a  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042ca3e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042ca41  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0042ca43  7508                   -jne 0x42ca4d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ca4d;
    }
    // 0042ca45  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0042ca47  7432                   -je 0x42ca7b
    if (cpu.flags.zf)
    {
        goto L_0x0042ca7b;
    }
    // 0042ca49  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0042ca4b  752e                   -jne 0x42ca7b
    if (!cpu.flags.zf)
    {
        goto L_0x0042ca7b;
    }
L_0x0042ca4d:
    // 0042ca4d  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 0042ca51  7507                   -jne 0x42ca5a
    if (!cpu.flags.zf)
    {
        goto L_0x0042ca5a;
    }
    // 0042ca53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ca54  e84cebffff             -call 0x42b5a5
    cpu.esp -= 4;
    sub_42b5a5(app, cpu);
    // 0042ca59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ca5a:
    // 0042ca5a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ca5c  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ca5f  7509                   -jne 0x42ca6a
    if (!cpu.flags.zf)
    {
        goto L_0x0042ca6a;
    }
    // 0042ca61  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 0042ca65  7514                   -jne 0x42ca7b
    if (!cpu.flags.zf)
    {
        goto L_0x0042ca7b;
    }
    // 0042ca67  40                     -inc eax
    (cpu.eax)++;
    // 0042ca68  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0042ca6a:
    // 0042ca6a  f6460c40               +test byte ptr [esi + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 0042ca6e  7411                   -je 0x42ca81
    if (cpu.flags.zf)
    {
        goto L_0x0042ca81;
    }
    // 0042ca70  ff0e                   -dec dword ptr [esi]
    (app->getMemory<x86::reg32>(cpu.esi))--;
    // 0042ca72  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ca74  3818                   +cmp byte ptr [eax], bl
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
    // 0042ca76  740f                   -je 0x42ca87
    if (cpu.flags.zf)
    {
        goto L_0x0042ca87;
    }
    // 0042ca78  40                     -inc eax
    (cpu.eax)++;
    // 0042ca79  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0042ca7b:
    // 0042ca7b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042ca7e:
    // 0042ca7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ca7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ca80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ca81:
    // 0042ca81  ff0e                   -dec dword ptr [esi]
    (app->getMemory<x86::reg32>(cpu.esi))--;
    // 0042ca83  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042ca85  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x0042ca87:
    // 0042ca87  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0042ca8a  ff4604                 -inc dword ptr [esi + 4]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */))++;
    // 0042ca8d  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0042ca8f  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0042ca91  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042ca94  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042ca96  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0042ca9b  ebe1                   -jmp 0x42ca7e
    goto L_0x0042ca7e;
}

/* align: skip  */
void Application::asm_sub_42ca9d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ca9d  833d6056490000         +cmp dword ptr [0x495660], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806240) /* 0x495660 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042caa4  750b                   -jne 0x42cab1
    if (!cpu.flags.zf)
    {
        goto L_0x0042cab1;
    }
    // 0042caa6  e807000000             -call 0x42cab2
    cpu.esp -= 4;
    sub_42cab2(app, cpu);
    // 0042caab  ff0560564900           -inc dword ptr [0x495660]
    (app->getMemory<x86::reg32>(x86::reg32(4806240) /* 0x495660 */))++;
L_0x0042cab1:
    // 0042cab1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42cab2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042cab2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cab3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042cab4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042cab5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cab6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cab7  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042cab9  83cbff                 -or ebx, 0xffffffff
    cpu.ebx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0042cabc  685c0e4300             -push 0x430e5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394588 /*0x430e5c*/;
    cpu.esp -= 4;
    // 0042cac1  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042cac3  892da8554900           -mov dword ptr [0x4955a8], ebp
    app->getMemory<x86::reg32>(x86::reg32(4806056) /* 0x4955a8 */) = cpu.ebp;
    // 0042cac9  891d28d94300           -mov dword ptr [0x43d928], ebx
    app->getMemory<x86::reg32>(x86::reg32(4446504) /* 0x43d928 */) = cpu.ebx;
    // 0042cacf  891d18d94300           -mov dword ptr [0x43d918], ebx
    app->getMemory<x86::reg32>(x86::reg32(4446488) /* 0x43d918 */) = cpu.ebx;
    // 0042cad5  e8d8190000             -call 0x42e4b2
    cpu.esp -= 4;
    sub_42e4b2(app, cpu);
    // 0042cada  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042cadc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cadd  3bf5                   +cmp esi, ebp
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
    // 0042cadf  0f85f6000000           -jne 0x42cbdb
    if (!cpu.flags.zf)
    {
        goto L_0x0042cbdb;
    }
    // 0042cae5  68b0554900             -push 0x4955b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806064 /*0x4955b0*/;
    cpu.esp -= 4;
    // 0042caea  ff1564004300           -call dword ptr [0x430064]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391012) /* 0x430064 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042caf0  3bc3                   +cmp eax, ebx
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
    // 0042caf2  0f8412020000           -je 0x42cd0a
    if (cpu.flags.zf)
    {
        goto L_0x0042cd0a;
    }
    // 0042caf8  a1b0554900             -mov eax, dword ptr [0x4955b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806064) /* 0x4955b0 */);
    // 0042cafd  8b0d04564900           -mov ecx, dword ptr [0x495604]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4806148) /* 0x495604 */);
    // 0042cb03  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042cb06  66392df6554900         +cmp word ptr [0x4955f6], bp
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(4806134) /* 0x4955f6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bp));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042cb0d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042cb0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cb10  a380d84300             -mov dword ptr [0x43d880], eax
    app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */) = cpu.eax;
    // 0042cb15  8915a8554900           -mov dword ptr [0x4955a8], edx
    app->getMemory<x86::reg32>(x86::reg32(4806056) /* 0x4955a8 */) = cpu.edx;
    // 0042cb1b  740c                   -je 0x42cb29
    if (cpu.flags.zf)
    {
        goto L_0x0042cb29;
    }
    // 0042cb1d  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042cb1f  6bf63c                 -imul esi, esi, 0x3c
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042cb22  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042cb24  a380d84300             -mov dword ptr [0x43d880], eax
    app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */) = cpu.eax;
L_0x0042cb29:
    // 0042cb29  66392d4a564900         +cmp word ptr [0x49564a], bp
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(4806218) /* 0x49564a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bp));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042cb30  741b                   -je 0x42cb4d
    if (cpu.flags.zf)
    {
        goto L_0x0042cb4d;
    }
    // 0042cb32  a158564900             -mov eax, dword ptr [0x495658]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806232) /* 0x495658 */);
    // 0042cb37  3bc5                   +cmp eax, ebp
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
    // 0042cb39  7412                   -je 0x42cb4d
    if (cpu.flags.zf)
    {
        goto L_0x0042cb4d;
    }
    // 0042cb3b  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042cb3d  891584d84300           -mov dword ptr [0x43d884], edx
    app->getMemory<x86::reg32>(x86::reg32(4446340) /* 0x43d884 */) = cpu.edx;
    // 0042cb43  6bc03c                 +imul eax, eax, 0x3c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0042cb46  a388d84300             -mov dword ptr [0x43d888], eax
    app->getMemory<x86::reg32>(x86::reg32(4446344) /* 0x43d888 */) = cpu.eax;
    // 0042cb4b  eb0c                   -jmp 0x42cb59
    goto L_0x0042cb59;
L_0x0042cb4d:
    // 0042cb4d  892d84d84300           -mov dword ptr [0x43d884], ebp
    app->getMemory<x86::reg32>(x86::reg32(4446340) /* 0x43d884 */) = cpu.ebp;
    // 0042cb53  892d88d84300           -mov dword ptr [0x43d888], ebp
    app->getMemory<x86::reg32>(x86::reg32(4446344) /* 0x43d888 */) = cpu.ebp;
L_0x0042cb59:
    // 0042cb59  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042cb5d  8b3514014300           -mov esi, dword ptr [0x430114]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4391188) /* 0x430114 */);
    // 0042cb63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cb64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042cb65  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0042cb67  bf20020000             -mov edi, 0x220
    cpu.edi = 544 /*0x220*/;
    // 0042cb6c  ff350cd94300           -push dword ptr [0x43d90c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4446476) /* 0x43d90c */);
    cpu.esp -= 4;
    // 0042cb72  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042cb73  68b4554900             -push 0x4955b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806068 /*0x4955b4*/;
    cpu.esp -= 4;
    // 0042cb78  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cb79  ff358c564900           -push dword ptr [0x49568c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    cpu.esp -= 4;
    // 0042cb7f  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042cb81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042cb83  7411                   -je 0x42cb96
    if (cpu.flags.zf)
    {
        goto L_0x0042cb96;
    }
    // 0042cb85  396c2410               +cmp dword ptr [esp + 0x10], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cb89  750b                   -jne 0x42cb96
    if (!cpu.flags.zf)
    {
        goto L_0x0042cb96;
    }
    // 0042cb8b  a10cd94300             -mov eax, dword ptr [0x43d90c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446476) /* 0x43d90c */);
    // 0042cb90  80603f00               +and byte ptr [eax + 0x3f], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042cb94  eb08                   -jmp 0x42cb9e
    goto L_0x0042cb9e;
L_0x0042cb96:
    // 0042cb96  a10cd94300             -mov eax, dword ptr [0x43d90c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446476) /* 0x43d90c */);
    // 0042cb9b  802000                 -and byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042cb9e:
    // 0042cb9e  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042cba2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cba3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042cba4  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0042cba6  ff3510d94300           -push dword ptr [0x43d910]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4446480) /* 0x43d910 */);
    cpu.esp -= 4;
    // 0042cbac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042cbad  6808564900             -push 0x495608
    app->getMemory<x86::reg32>(cpu.esp-4) = 4806152 /*0x495608*/;
    cpu.esp -= 4;
    // 0042cbb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cbb3  ff358c564900           -push dword ptr [0x49568c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    cpu.esp -= 4;
    // 0042cbb9  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042cbbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042cbbd  0f843f010000           -je 0x42cd02
    if (cpu.flags.zf)
    {
        goto L_0x0042cd02;
    }
    // 0042cbc3  396c2410               +cmp dword ptr [esp + 0x10], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cbc7  0f8535010000           -jne 0x42cd02
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd02;
    }
    // 0042cbcd  a110d94300             -mov eax, dword ptr [0x43d910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446480) /* 0x43d910 */);
    // 0042cbd2  80603f00               +and byte ptr [eax + 0x3f], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042cbd6  e92f010000             -jmp 0x42cd0a
    goto L_0x0042cd0a;
L_0x0042cbdb:
    // 0042cbdb  803e00                 +cmp byte ptr [esi], 0
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
    // 0042cbde  0f8426010000           -je 0x42cd0a
    if (cpu.flags.zf)
    {
        goto L_0x0042cd0a;
    }
    // 0042cbe4  a15c564900             -mov eax, dword ptr [0x49565c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806236) /* 0x49565c */);
    // 0042cbe9  3bc5                   +cmp eax, ebp
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
    // 0042cbeb  7411                   -je 0x42cbfe
    if (cpu.flags.zf)
    {
        goto L_0x0042cbfe;
    }
    // 0042cbed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cbee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cbef  e86ceeffff             -call 0x42ba60
    cpu.esp -= 4;
    sub_42ba60(app, cpu);
    // 0042cbf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cbf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042cbf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cbf8  0f840c010000           -je 0x42cd0a
    if (cpu.flags.zf)
    {
        goto L_0x0042cd0a;
    }
L_0x0042cbfe:
    // 0042cbfe  ff355c564900           -push dword ptr [0x49565c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4806236) /* 0x49565c */);
    cpu.esp -= 4;
    // 0042cc04  e83d82ffff             -call 0x424e46
    cpu.esp -= 4;
    sub_424e46(app, cpu);
    // 0042cc09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cc0a  e8c1b1ffff             -call 0x427dd0
    cpu.esp -= 4;
    sub_427dd0(app, cpu);
    // 0042cc0f  40                     -inc eax
    (cpu.eax)++;
    // 0042cc10  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cc11  e85f82ffff             -call 0x424e75
    cpu.esp -= 4;
    sub_424e75(app, cpu);
    // 0042cc16  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042cc19  3bc5                   +cmp eax, ebp
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
    // 0042cc1b  a35c564900             -mov dword ptr [0x49565c], eax
    app->getMemory<x86::reg32>(x86::reg32(4806236) /* 0x49565c */) = cpu.eax;
    // 0042cc20  0f84e4000000           -je 0x42cd0a
    if (cpu.flags.zf)
    {
        goto L_0x0042cd0a;
    }
    // 0042cc26  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cc27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cc28  e863f5ffff             -call 0x42c190
    cpu.esp -= 4;
    sub_42c190(app, cpu);
    // 0042cc2d  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042cc2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cc30  ff350cd94300           -push dword ptr [0x43d90c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4446476) /* 0x43d90c */);
    cpu.esp -= 4;
    // 0042cc36  e89589ffff             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0042cc3b  a10cd94300             -mov eax, dword ptr [0x43d90c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446476) /* 0x43d90c */);
    // 0042cc40  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042cc43  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042cc46  80600300               -and byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 0042cc4a  803e2d                 +cmp byte ptr [esi], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042cc4d  7504                   -jne 0x42cc53
    if (!cpu.flags.zf)
    {
        goto L_0x0042cc53;
    }
    // 0042cc4f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042cc51  46                     -inc esi
    (cpu.esi)++;
    // 0042cc52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042cc53:
    // 0042cc53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cc54  e8ce170000             -call 0x42e427
    cpu.esp -= 4;
    sub_42e427(app, cpu);
    // 0042cc59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cc5a  b330                   -mov bl, 0x30
    cpu.bl = 48 /*0x30*/;
    // 0042cc5c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042cc5e  69c9100e0000           -imul ecx, ecx, 0xe10
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(3600 /*0xe10*/)));
    // 0042cc64  890d80d84300           -mov dword ptr [0x43d880], ecx
    app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */) = cpu.ecx;
L_0x0042cc6a:
    // 0042cc6a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042cc6c  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042cc6e  7408                   -je 0x42cc78
    if (cpu.flags.zf)
    {
        goto L_0x0042cc78;
    }
    // 0042cc70  3ac3                   +cmp al, bl
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
    // 0042cc72  7c07                   -jl 0x42cc7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042cc7b;
    }
    // 0042cc74  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042cc76  7f03                   -jg 0x42cc7b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042cc7b;
    }
L_0x0042cc78:
    // 0042cc78  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042cc79  ebef                   -jmp 0x42cc6a
    goto L_0x0042cc6a;
L_0x0042cc7b:
    // 0042cc7b  803e3a                 +cmp byte ptr [esi], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042cc7e  754e                   -jne 0x42ccce
    if (!cpu.flags.zf)
    {
        goto L_0x0042ccce;
    }
    // 0042cc80  46                     -inc esi
    (cpu.esi)++;
    // 0042cc81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cc82  e8a0170000             -call 0x42e427
    cpu.esp -= 4;
    sub_42e427(app, cpu);
    // 0042cc87  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042cc8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cc8b  8b0d80d84300           -mov ecx, dword ptr [0x43d880]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */);
    // 0042cc91  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042cc93  890d80d84300           -mov dword ptr [0x43d880], ecx
    app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */) = cpu.ecx;
L_0x0042cc99:
    // 0042cc99  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042cc9b  3ac3                   +cmp al, bl
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
    // 0042cc9d  7c07                   -jl 0x42cca6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042cca6;
    }
    // 0042cc9f  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042cca1  7f03                   -jg 0x42cca6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042cca6;
    }
    // 0042cca3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042cca4  ebf3                   -jmp 0x42cc99
    goto L_0x0042cc99;
L_0x0042cca6:
    // 0042cca6  803e3a                 +cmp byte ptr [esi], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042cca9  7523                   -jne 0x42ccce
    if (!cpu.flags.zf)
    {
        goto L_0x0042ccce;
    }
    // 0042ccab  46                     -inc esi
    (cpu.esi)++;
    // 0042ccac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ccad  e875170000             -call 0x42e427
    cpu.esp -= 4;
    sub_42e427(app, cpu);
    // 0042ccb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ccb3  8b0d80d84300           -mov ecx, dword ptr [0x43d880]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */);
    // 0042ccb9  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042ccbb  890d80d84300           -mov dword ptr [0x43d880], ecx
    app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */) = cpu.ecx;
L_0x0042ccc1:
    // 0042ccc1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042ccc3  3ac3                   +cmp al, bl
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
    // 0042ccc5  7c07                   -jl 0x42ccce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ccce;
    }
    // 0042ccc7  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042ccc9  7f03                   -jg 0x42ccce
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ccce;
    }
    // 0042cccb  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042cccc  ebf3                   -jmp 0x42ccc1
    goto L_0x0042ccc1;
L_0x0042ccce:
    // 0042ccce  3bfd                   +cmp edi, ebp
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
    // 0042ccd0  7408                   -je 0x42ccda
    if (cpu.flags.zf)
    {
        goto L_0x0042ccda;
    }
    // 0042ccd2  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0042ccd4  890d80d84300           -mov dword ptr [0x43d880], ecx
    app->getMemory<x86::reg32>(x86::reg32(4446336) /* 0x43d880 */) = cpu.ecx;
L_0x0042ccda:
    // 0042ccda  0fbe06                 -movsx eax, byte ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi)));
    // 0042ccdd  3bc5                   +cmp eax, ebp
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
    // 0042ccdf  a384d84300             -mov dword ptr [0x43d884], eax
    app->getMemory<x86::reg32>(x86::reg32(4446340) /* 0x43d884 */) = cpu.eax;
    // 0042cce4  741c                   -je 0x42cd02
    if (cpu.flags.zf)
    {
        goto L_0x0042cd02;
    }
    // 0042cce6  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0042cce8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cce9  ff3510d94300           -push dword ptr [0x43d910]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4446480) /* 0x43d910 */);
    cpu.esp -= 4;
    // 0042ccef  e8dc88ffff             -call 0x4255d0
    cpu.esp -= 4;
    sub_4255d0(app, cpu);
    // 0042ccf4  a110d94300             -mov eax, dword ptr [0x43d910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446480) /* 0x43d910 */);
    // 0042ccf9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042ccfc  80600300               +and byte ptr [eax + 3], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 0042cd00  eb08                   -jmp 0x42cd0a
    goto L_0x0042cd0a;
L_0x0042cd02:
    // 0042cd02  a110d94300             -mov eax, dword ptr [0x43d910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446480) /* 0x43d910 */);
    // 0042cd07  802000                 -and byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042cd0a:
    // 0042cd0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cd0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cd0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cd0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cd0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cd0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42cd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042cd10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042cd11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cd12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cd13  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042cd15  393d84d84300           +cmp dword ptr [0x43d884], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4446340) /* 0x43d884 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cd1b  7507                   -jne 0x42cd24
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd24;
    }
L_0x0042cd1d:
    // 0042cd1d  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042cd1f  e94c010000             -jmp 0x42ce70
    goto L_0x0042ce70;
L_0x0042cd24:
    // 0042cd24  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042cd28  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042cd2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cd2b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0042cd2e  3b0518d94300           +cmp eax, dword ptr [0x43d918]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4446488) /* 0x43d918 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cd34  750c                   -jne 0x42cd42
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd42;
    }
    // 0042cd36  3b0528d94300           +cmp eax, dword ptr [0x43d928]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4446504) /* 0x43d928 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cd3c  0f8402010000           -je 0x42ce44
    if (cpu.flags.zf)
    {
        goto L_0x0042ce44;
    }
L_0x0042cd42:
    // 0042cd42  393da8554900           +cmp dword ptr [0x4955a8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806056) /* 0x4955a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cd48  0f84cc000000           -je 0x42ce1a
    if (cpu.flags.zf)
    {
        goto L_0x0042ce1a;
    }
    // 0042cd4e  0fb70d56564900         -movzx ecx, word ptr [0x495656]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806230) /* 0x495656 */));
    // 0042cd55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd56  66393d48564900         +cmp word ptr [0x495648], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(4806216) /* 0x495648 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042cd5d  0fb70d54564900         -movzx ecx, word ptr [0x495654]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806228) /* 0x495654 */));
    // 0042cd64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd65  0fb70d52564900         -movzx ecx, word ptr [0x495652]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806226) /* 0x495652 */));
    // 0042cd6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd6d  0fb70d50564900         -movzx ecx, word ptr [0x495650]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806224) /* 0x495650 */));
    // 0042cd74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd75  751d                   -jne 0x42cd94
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd94;
    }
    // 0042cd77  0fb70d4c564900         -movzx ecx, word ptr [0x49564c]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806220) /* 0x49564c */));
    // 0042cd7e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cd7f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd80  0fb70d4e564900         -movzx ecx, word ptr [0x49564e]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806222) /* 0x49564e */));
    // 0042cd87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd88  0fb70d4a564900         -movzx ecx, word ptr [0x49564a]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806218) /* 0x49564a */));
    // 0042cd8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cd91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042cd92  eb14                   -jmp 0x42cda8
    goto L_0x0042cda8;
L_0x0042cd94:
    // 0042cd94  0fb70d4e564900         -movzx ecx, word ptr [0x49564e]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806222) /* 0x49564e */));
    // 0042cd9b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cd9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cd9d  0fb70d4a564900         -movzx ecx, word ptr [0x49564a]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806218) /* 0x49564a */));
    // 0042cda4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cda5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042cda6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cda7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042cda8:
    // 0042cda8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042cda9  e80e010000             -call 0x42cebc
    cpu.esp -= 4;
    sub_42cebc(app, cpu);
    // 0042cdae  0fb70502564900         -movzx eax, word ptr [0x495602]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806146) /* 0x495602 */));
    // 0042cdb5  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0042cdb8  66393df4554900         +cmp word ptr [0x4955f4], di
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(4806132) /* 0x4955f4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042cdbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cdc0  0fb70500564900         -movzx eax, word ptr [0x495600]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806144) /* 0x495600 */));
    // 0042cdc7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cdc8  0fb705fe554900         -movzx eax, word ptr [0x4955fe]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806142) /* 0x4955fe */));
    // 0042cdcf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cdd0  0fb705fc554900         -movzx eax, word ptr [0x4955fc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806140) /* 0x4955fc */));
    // 0042cdd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cdd8  7528                   -jne 0x42ce02
    if (!cpu.flags.zf)
    {
        goto L_0x0042ce02;
    }
    // 0042cdda  0fb705f8554900         -movzx eax, word ptr [0x4955f8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806136) /* 0x4955f8 */));
    // 0042cde1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cde2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cde3  0fb705fa554900         -movzx eax, word ptr [0x4955fa]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806138) /* 0x4955fa */));
    // 0042cdea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cdeb  0fb705f6554900         -movzx eax, word ptr [0x4955f6]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806134) /* 0x4955f6 */));
    // 0042cdf2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042cdf3  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042cdf6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0042cdf7:
    // 0042cdf7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042cdf8  e8bf000000             -call 0x42cebc
    cpu.esp -= 4;
    sub_42cebc(app, cpu);
    // 0042cdfd  83c42c                 +add esp, 0x2c
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
    // 0042ce00  eb42                   -jmp 0x42ce44
    goto L_0x0042ce44;
L_0x0042ce02:
    // 0042ce02  0fb705fa554900         -movzx eax, word ptr [0x4955fa]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806138) /* 0x4955fa */));
    // 0042ce09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ce0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce0b  0fb705f6554900         -movzx eax, word ptr [0x4955f6]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4806134) /* 0x4955f6 */));
    // 0042ce12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ce14  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042ce17  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce18  ebdd                   -jmp 0x42cdf7
    goto L_0x0042cdf7;
L_0x0042ce1a:
    // 0042ce1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce1d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042ce1f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce21  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ce22  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042ce24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ce25  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ce26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ce27  e890000000             -call 0x42cebc
    cpu.esp -= 4;
    sub_42cebc(app, cpu);
    // 0042ce2c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce2f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042ce31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce33  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0042ce35  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0042ce37  ff7614                 -push dword ptr [esi + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0042ce3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ce3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce3c  e87b000000             -call 0x42cebc
    cpu.esp -= 4;
    sub_42cebc(app, cpu);
    // 0042ce41  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
L_0x0042ce44:
    // 0042ce44  8b151cd94300           -mov edx, dword ptr [0x43d91c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4446492) /* 0x43d91c */);
    // 0042ce4a  a12cd94300             -mov eax, dword ptr [0x43d92c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4446508) /* 0x43d92c */);
    // 0042ce4f  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0042ce52  3bd0                   +cmp edx, eax
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
    // 0042ce54  7d1e                   -jge 0x42ce74
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042ce74;
    }
    // 0042ce56  3bca                   +cmp ecx, edx
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
    // 0042ce58  0f8cbffeffff           -jl 0x42cd1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042cd1d;
    }
    // 0042ce5e  3bc8                   +cmp ecx, eax
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
    // 0042ce60  0f8fb7feffff           -jg 0x42cd1d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042cd1d;
    }
    // 0042ce66  3bca                   +cmp ecx, edx
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
    // 0042ce68  7e1e                   -jle 0x42ce88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ce88;
    }
    // 0042ce6a  3bc8                   +cmp ecx, eax
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
    // 0042ce6c  7d1a                   -jge 0x42ce88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042ce88;
    }
L_0x0042ce6e:
    // 0042ce6e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0042ce70:
    // 0042ce70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ce71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ce72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ce73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ce74:
    // 0042ce74  3bc8                   +cmp ecx, eax
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
    // 0042ce76  7cf6                   -jl 0x42ce6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ce6e;
    }
    // 0042ce78  3bca                   +cmp ecx, edx
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
    // 0042ce7a  7ff2                   -jg 0x42ce6e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ce6e;
    }
    // 0042ce7c  3bc8                   +cmp ecx, eax
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
    // 0042ce7e  7e08                   -jle 0x42ce88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ce88;
    }
    // 0042ce80  3bca                   +cmp ecx, edx
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
    // 0042ce82  0f8c95feffff           -jl 0x42cd1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042cd1d;
    }
L_0x0042ce88:
    // 0042ce88  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0042ce8b  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042ce8e  034604                 -add eax, dword ptr [esi + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0042ce91  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042ce94  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 0042ce96  69c0e8030000           -imul eax, eax, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 0042ce9c  3bca                   +cmp ecx, edx
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
    // 0042ce9e  750f                   -jne 0x42ceaf
    if (!cpu.flags.zf)
    {
        goto L_0x0042ceaf;
    }
    // 0042cea0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042cea2  3b0520d94300           +cmp eax, dword ptr [0x43d920]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4446496) /* 0x43d920 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cea8  0f9dc1                 -setge cl
    cpu.cl = (cpu.flags.sf == cpu.flags.of);
L_0x0042ceab:
    // 0042ceab  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042cead  ebc1                   -jmp 0x42ce70
    goto L_0x0042ce70;
L_0x0042ceaf:
    // 0042ceaf  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042ceb1  3b0530d94300           +cmp eax, dword ptr [0x43d930]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4446512) /* 0x43d930 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ceb7  0f9cc1                 -setl cl
    cpu.cl = (cpu.flags.sf != cpu.flags.of);
    // 0042ceba  ebef                   -jmp 0x42ceab
    goto L_0x0042ceab;
}

/* align: skip  */
void Application::asm_sub_42cebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042cebc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042cebd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042cebf  837d0c01               +cmp dword ptr [ebp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cec3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042cec4  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0042cec7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042cec8  0f8589000000           -jne 0x42cf57
    if (!cpu.flags.zf)
    {
        goto L_0x0042cf57;
    }
    // 0042cece  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042ced1  895d10                 -mov dword ptr [ebp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0042ced4  83651003               +and dword ptr [ebp + 0x10], 3
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0042ced8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ceda  750b                   -jne 0x42cee7
    if (!cpu.flags.zf)
    {
        goto L_0x0042cee7;
    }
    // 0042cedc  c1e602                 +shl esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.esi);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042cedf  8b8630d94300           -mov eax, dword ptr [esi + 0x43d930]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4446512) /* 0x43d930 */);
    // 0042cee5  eb09                   -jmp 0x42cef0
    goto L_0x0042cef0;
L_0x0042cee7:
    // 0042cee7  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0042ceea  8b8664d94300           -mov eax, dword ptr [esi + 0x43d964]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4446564) /* 0x43d964 */);
L_0x0042cef0:
    // 0042cef0  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042cef2  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042cef5  69d26d010000           -imul edx, edx, 0x16d
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(365 /*0x16d*/)));
    // 0042cefb  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0042cefe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ceff  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0042cf02  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042cf04  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0042cf06  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042cf08  8d843a259cffff         -lea eax, [edx + edi - 0x63db]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-25563) /* -0x63db */ + cpu.edi * 1);
    // 0042cf0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cf10  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042cf11  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042cf13  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0042cf16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cf17  3b551c                 +cmp edx, dword ptr [ebp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cf1a  7d0e                   -jge 0x42cf2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042cf2a;
    }
    // 0042cf1c  6bc007                 -imul eax, eax, 7
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(7 /*0x7*/)));
    // 0042cf1f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042cf21  03451c                 +add eax, dword ptr [ebp + 0x1c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042cf24  8d4c01f9               -lea ecx, [ecx + eax - 7]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-7) /* -0x7 */ + cpu.eax * 1);
    // 0042cf28  eb0a                   -jmp 0x42cf34
    goto L_0x0042cf34;
L_0x0042cf2a:
    // 0042cf2a  6bc007                 -imul eax, eax, 7
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(7 /*0x7*/)));
    // 0042cf2d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042cf2f  03451c                 -add eax, dword ptr [ebp + 0x1c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042cf32  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0042cf34:
    // 0042cf34  837d1805               +cmp dword ptr [ebp + 0x18], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cf38  7538                   -jne 0x42cf72
    if (!cpu.flags.zf)
    {
        goto L_0x0042cf72;
    }
    // 0042cf3a  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 0042cf3e  7508                   -jne 0x42cf48
    if (!cpu.flags.zf)
    {
        goto L_0x0042cf48;
    }
    // 0042cf40  8bb634d94300           -mov esi, dword ptr [esi + 0x43d934]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4446516) /* 0x43d934 */);
    // 0042cf46  eb06                   -jmp 0x42cf4e
    goto L_0x0042cf4e;
L_0x0042cf48:
    // 0042cf48  8bb668d94300           -mov esi, dword ptr [esi + 0x43d968]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4446568) /* 0x43d968 */);
L_0x0042cf4e:
    // 0042cf4e  3bce                   +cmp ecx, esi
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
    // 0042cf50  7e20                   -jle 0x42cf72
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042cf72;
    }
    // 0042cf52  83e907                 +sub ecx, 7
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042cf55  eb1b                   -jmp 0x42cf72
    goto L_0x0042cf72;
L_0x0042cf57:
    // 0042cf57  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0042cf5a  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 0042cf5d  7509                   -jne 0x42cf68
    if (!cpu.flags.zf)
    {
        goto L_0x0042cf68;
    }
    // 0042cf5f  8b0c8530d94300         -mov ecx, dword ptr [eax*4 + 0x43d930]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4446512) /* 0x43d930 */ + cpu.eax * 4);
    // 0042cf66  eb07                   -jmp 0x42cf6f
    goto L_0x0042cf6f;
L_0x0042cf68:
    // 0042cf68  8b0c8564d94300         -mov ecx, dword ptr [eax*4 + 0x43d964]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4446564) /* 0x43d964 */ + cpu.eax * 4);
L_0x0042cf6f:
    // 0042cf6f  034d20                 -add ecx, dword ptr [ebp + 0x20]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
L_0x0042cf72:
    // 0042cf72  837d0801               +cmp dword ptr [ebp + 8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042cf76  752b                   -jne 0x42cfa3
    if (!cpu.flags.zf)
    {
        goto L_0x0042cfa3;
    }
    // 0042cf78  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0042cf7b  890d1cd94300           -mov dword ptr [0x43d91c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4446492) /* 0x43d91c */) = cpu.ecx;
    // 0042cf81  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042cf84  034528                 -add eax, dword ptr [ebp + 0x28]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */)));
    // 0042cf87  891d18d94300           -mov dword ptr [0x43d918], ebx
    app->getMemory<x86::reg32>(x86::reg32(4446488) /* 0x43d918 */) = cpu.ebx;
    // 0042cf8d  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042cf90  03452c                 -add eax, dword ptr [ebp + 0x2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 0042cf93  69c0e8030000           -imul eax, eax, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 0042cf99  034530                 +add eax, dword ptr [ebp + 0x30]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042cf9c  a320d94300             -mov dword ptr [0x43d920], eax
    app->getMemory<x86::reg32>(x86::reg32(4446496) /* 0x43d920 */) = cpu.eax;
    // 0042cfa1  eb55                   -jmp 0x42cff8
    goto L_0x0042cff8;
L_0x0042cfa3:
    // 0042cfa3  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0042cfa6  890d2cd94300           -mov dword ptr [0x43d92c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4446508) /* 0x43d92c */) = cpu.ecx;
    // 0042cfac  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042cfaf  034528                 -add eax, dword ptr [ebp + 0x28]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */)));
    // 0042cfb2  6bc03c                 -imul eax, eax, 0x3c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(60 /*0x3c*/)));
    // 0042cfb5  030588d84300           -add eax, dword ptr [0x43d888]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4446344) /* 0x43d888 */)));
    // 0042cfbb  03452c                 -add eax, dword ptr [ebp + 0x2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 0042cfbe  69c0e8030000           -imul eax, eax, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 0042cfc4  034530                 +add eax, dword ptr [ebp + 0x30]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042cfc7  a330d94300             -mov dword ptr [0x43d930], eax
    app->getMemory<x86::reg32>(x86::reg32(4446512) /* 0x43d930 */) = cpu.eax;
    // 0042cfcc  790d                   -jns 0x42cfdb
    if (!cpu.flags.sf)
    {
        goto L_0x0042cfdb;
    }
    // 0042cfce  05005c2605             +add eax, 0x5265c00
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400000 /*0x5265c00*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042cfd3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042cfd4  a330d94300             -mov dword ptr [0x43d930], eax
    app->getMemory<x86::reg32>(x86::reg32(4446512) /* 0x43d930 */) = cpu.eax;
    // 0042cfd9  eb11                   -jmp 0x42cfec
    goto L_0x0042cfec;
L_0x0042cfdb:
    // 0042cfdb  ba005c2605             -mov edx, 0x5265c00
    cpu.edx = 86400000 /*0x5265c00*/;
    // 0042cfe0  3bc2                   +cmp eax, edx
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
    // 0042cfe2  7c0e                   -jl 0x42cff2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042cff2;
    }
    // 0042cfe4  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042cfe6  41                     -inc ecx
    (cpu.ecx)++;
    // 0042cfe7  a330d94300             -mov dword ptr [0x43d930], eax
    app->getMemory<x86::reg32>(x86::reg32(4446512) /* 0x43d930 */) = cpu.eax;
L_0x0042cfec:
    // 0042cfec  890d2cd94300           -mov dword ptr [0x43d92c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4446508) /* 0x43d92c */) = cpu.ecx;
L_0x0042cff2:
    // 0042cff2  891d28d94300           -mov dword ptr [0x43d928], ebx
    app->getMemory<x86::reg32>(x86::reg32(4446504) /* 0x43d928 */) = cpu.ebx;
L_0x0042cff8:
    // 0042cff8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cff9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cffa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cffb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42cffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042cffc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042cffe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042d000  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0042d004  e804000000             -call 0x42d00d
    cpu.esp -= 4;
    sub_42d00d(app, cpu);
    // 0042d009  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d00c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d00d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d00d  0fb6442404             -movzx eax, byte ptr [esp + 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0042d012  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042d016  8488e15b4900           -test byte ptr [eax + 0x495be1], cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) & cpu.cl));
    // 0042d01c  751c                   -jne 0x42d03a
    if (!cpu.flags.zf)
    {
        goto L_0x0042d03a;
    }
    // 0042d01e  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0042d023  740e                   -je 0x42d033
    if (cpu.flags.zf)
    {
        goto L_0x0042d033;
    }
    // 0042d025  0fb704452ad64300       -movzx eax, word ptr [eax*2 + 0x43d62a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4445738) /* 0x43d62a */ + cpu.eax * 2));
    // 0042d02d  23442408               +and eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 0042d031  eb02                   -jmp 0x42d035
    goto L_0x0042d035;
L_0x0042d033:
    // 0042d033  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042d035:
    // 0042d035  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d037  7501                   -jne 0x42d03a
    if (!cpu.flags.zf)
    {
        goto L_0x0042d03a;
    }
    // 0042d039  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d03a:
    // 0042d03a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d03c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d03d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d03e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d03e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d03f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042d041  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042d044  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d045  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d046  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d047  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0042d04a  e888010000             -call 0x42d1d7
    cpu.esp -= 4;
    sub_42d1d7(app, cpu);
    // 0042d04f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d051  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d052  3b35cc5a4900           +cmp esi, dword ptr [0x495acc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d058  897508                 -mov dword ptr [ebp + 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0042d05b  0f846a010000           -je 0x42d1cb
    if (cpu.flags.zf)
    {
        goto L_0x0042d1cb;
    }
    // 0042d061  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d063  3bf3                   +cmp esi, ebx
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
    // 0042d065  0f8456010000           -je 0x42d1c1
    if (cpu.flags.zf)
    {
        goto L_0x0042d1c1;
    }
    // 0042d06b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042d06d  b8a8d94300             -mov eax, 0x43d9a8
    cpu.eax = 4446632 /*0x43d9a8*/;
L_0x0042d072:
    // 0042d072  3930                   +cmp dword ptr [eax], esi
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
    // 0042d074  7472                   -je 0x42d0e8
    if (cpu.flags.zf)
    {
        goto L_0x0042d0e8;
    }
    // 0042d076  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0042d079  42                     -inc edx
    (cpu.edx)++;
    // 0042d07a  3d98da4300             +cmp eax, 0x43da98
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4446872 /*0x43da98*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d07f  7cf1                   -jl 0x42d072
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d072;
    }
    // 0042d081  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0042d084  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d085  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d086  ff1560004300           -call dword ptr [0x430060]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391008) /* 0x430060 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d08c  83f801                 +cmp eax, 1
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
    // 0042d08f  0f8524010000           -jne 0x42d1b9
    if (!cpu.flags.zf)
    {
        goto L_0x0042d1b9;
    }
    // 0042d095  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0042d097  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d099  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d09a  bfe05b4900             -mov edi, 0x495be0
    cpu.edi = 4807648 /*0x495be0*/;
    // 0042d09f  837de801               +cmp dword ptr [ebp - 0x18], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d0a3  8935cc5a4900           -mov dword ptr [0x495acc], esi
    app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */) = cpu.esi;
    // 0042d0a9  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042d0ab  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0042d0ac  891de45c4900           -mov dword ptr [0x495ce4], ebx
    app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */) = cpu.ebx;
    // 0042d0b2  0f86ef000000           -jbe 0x42d1a7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042d1a7;
    }
    // 0042d0b8  807dee00               +cmp byte ptr [ebp - 0x12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-18) /* -0x12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042d0bc  0f84bb000000           -je 0x42d17d
    if (cpu.flags.zf)
    {
        goto L_0x0042d17d;
    }
    // 0042d0c2  8d4def                 -lea ecx, [ebp - 0x11]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-17) /* -0x11 */);
L_0x0042d0c5:
    // 0042d0c5  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042d0c7  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042d0c9  0f84ae000000           -je 0x42d17d
    if (cpu.flags.zf)
    {
        goto L_0x0042d17d;
    }
    // 0042d0cf  0fb641ff               -movzx eax, byte ptr [ecx - 1]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */));
    // 0042d0d3  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
L_0x0042d0d6:
    // 0042d0d6  3bc2                   +cmp eax, edx
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
    // 0042d0d8  0f8793000000           -ja 0x42d171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042d171;
    }
    // 0042d0de  8088e15b490004         +or byte ptr [eax + 0x495be1], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0042d0e5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042d0e6  ebee                   -jmp 0x42d0d6
    goto L_0x0042d0d6;
L_0x0042d0e8:
    // 0042d0e8  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0042d0ea  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d0ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d0ed  bfe05b4900             -mov edi, 0x495be0
    cpu.edi = 4807648 /*0x495be0*/;
    // 0042d0f2  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042d0f4  8d3452                 -lea esi, [edx + edx*2]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 2);
    // 0042d0f7  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0042d0fa  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0042d0fd  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0042d0fe  8d9eb8d94300           -lea ebx, [esi + 0x43d9b8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(4446648) /* 0x43d9b8 */);
L_0x0042d104:
    // 0042d104  803b00                 +cmp byte ptr [ebx], 0
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
    // 0042d107  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042d109  742c                   -je 0x42d137
    if (cpu.flags.zf)
    {
        goto L_0x0042d137;
    }
L_0x0042d10b:
    // 0042d10b  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0042d10e  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042d110  7425                   -je 0x42d137
    if (cpu.flags.zf)
    {
        goto L_0x0042d137;
    }
    // 0042d112  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0042d115  0fb6fa                 -movzx edi, dl
    cpu.edi = x86::reg32(cpu.dl);
    // 0042d118  3bc7                   +cmp eax, edi
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
    // 0042d11a  7714                   -ja 0x42d130
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042d130;
    }
    // 0042d11c  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042d11f  8a92a0d94300           -mov dl, byte ptr [edx + 0x43d9a0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4446624) /* 0x43d9a0 */);
L_0x0042d125:
    // 0042d125  0890e15b4900           -or byte ptr [eax + 0x495be1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) |= x86::reg8(x86::sreg8(cpu.dl));
    // 0042d12b  40                     -inc eax
    (cpu.eax)++;
    // 0042d12c  3bc7                   +cmp eax, edi
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
    // 0042d12e  76f5                   -jbe 0x42d125
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042d125;
    }
L_0x0042d130:
    // 0042d130  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d131  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d132  803900                 +cmp byte ptr [ecx], 0
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
    // 0042d135  75d4                   -jne 0x42d10b
    if (!cpu.flags.zf)
    {
        goto L_0x0042d10b;
    }
L_0x0042d137:
    // 0042d137  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 0042d13a  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042d13d  837dfc04               +cmp dword ptr [ebp - 4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d141  72c1                   -jb 0x42d104
    if (cpu.flags.cf)
    {
        goto L_0x0042d104;
    }
    // 0042d143  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042d146  c705dc5a490001000000   -mov dword ptr [0x495adc], 1
    app->getMemory<x86::reg32>(x86::reg32(4807388) /* 0x495adc */) = 1 /*0x1*/;
    // 0042d150  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d151  a3cc5a4900             -mov dword ptr [0x495acc], eax
    app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */) = cpu.eax;
    // 0042d156  e8c6000000             -call 0x42d221
    cpu.esp -= 4;
    sub_42d221(app, cpu);
    // 0042d15b  8db6acd94300           -lea esi, [esi + 0x43d9ac]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4446636) /* 0x43d9ac */);
    // 0042d161  bfd05a4900             -mov edi, 0x495ad0
    cpu.edi = 4807376 /*0x495ad0*/;
    // 0042d166  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042d167  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042d168  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d169  a3e45c4900             -mov dword ptr [0x495ce4], eax
    app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */) = cpu.eax;
    // 0042d16e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042d16f  eb55                   -jmp 0x42d1c6
    goto L_0x0042d1c6;
L_0x0042d171:
    // 0042d171  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d172  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d173  8079ff00               +cmp byte ptr [ecx - 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042d177  0f8548ffffff           -jne 0x42d0c5
    if (!cpu.flags.zf)
    {
        goto L_0x0042d0c5;
    }
L_0x0042d17d:
    // 0042d17d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d17f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042d180:
    // 0042d180  8088e15b490008         -or byte ptr [eax + 0x495be1], 8
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0042d187  40                     -inc eax
    (cpu.eax)++;
    // 0042d188  3dff000000             +cmp eax, 0xff
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
    // 0042d18d  72f1                   -jb 0x42d180
    if (cpu.flags.cf)
    {
        goto L_0x0042d180;
    }
    // 0042d18f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d190  e88c000000             -call 0x42d221
    cpu.esp -= 4;
    sub_42d221(app, cpu);
    // 0042d195  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d196  a3e45c4900             -mov dword ptr [0x495ce4], eax
    app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */) = cpu.eax;
    // 0042d19b  c705dc5a490001000000   -mov dword ptr [0x495adc], 1
    app->getMemory<x86::reg32>(x86::reg32(4807388) /* 0x495adc */) = 1 /*0x1*/;
    // 0042d1a5  eb06                   -jmp 0x42d1ad
    goto L_0x0042d1ad;
L_0x0042d1a7:
    // 0042d1a7  891ddc5a4900           -mov dword ptr [0x495adc], ebx
    app->getMemory<x86::reg32>(x86::reg32(4807388) /* 0x495adc */) = cpu.ebx;
L_0x0042d1ad:
    // 0042d1ad  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042d1af  bfd05a4900             -mov edi, 0x495ad0
    cpu.edi = 4807376 /*0x495ad0*/;
    // 0042d1b4  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042d1b5  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042d1b6  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042d1b7  eb0d                   -jmp 0x42d1c6
    goto L_0x0042d1c6;
L_0x0042d1b9:
    // 0042d1b9  391d64564900           +cmp dword ptr [0x495664], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806244) /* 0x495664 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d1bf  740e                   -je 0x42d1cf
    if (cpu.flags.zf)
    {
        goto L_0x0042d1cf;
    }
L_0x0042d1c1:
    // 0042d1c1  e88e000000             -call 0x42d254
    cpu.esp -= 4;
    sub_42d254(app, cpu);
L_0x0042d1c6:
    // 0042d1c6  e8b2000000             -call 0x42d27d
    cpu.esp -= 4;
    sub_42d27d(app, cpu);
L_0x0042d1cb:
    // 0042d1cb  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042d1cd  eb03                   -jmp 0x42d1d2
    goto L_0x0042d1d2;
L_0x0042d1cf:
    // 0042d1cf  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0042d1d2:
    // 0042d1d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d1d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d1d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d1d5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d1d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d1d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d1d7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042d1db  83256456490000         -and dword ptr [0x495664], 0
    app->getMemory<x86::reg32>(x86::reg32(4806244) /* 0x495664 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0042d1e2  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d1e5  7510                   -jne 0x42d1f7
    if (!cpu.flags.zf)
    {
        goto L_0x0042d1f7;
    }
    // 0042d1e7  c7056456490001000000   -mov dword ptr [0x495664], 1
    app->getMemory<x86::reg32>(x86::reg32(4806244) /* 0x495664 */) = 1 /*0x1*/;
    // 0042d1f1  ff2558004300           -jmp dword ptr [0x430058]
    return app->dynamic_call(app->getMemory<x86::reg32>(4391000), cpu);
L_0x0042d1f7:
    // 0042d1f7  83f8fd                 +cmp eax, -3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d1fa  7510                   -jne 0x42d20c
    if (!cpu.flags.zf)
    {
        goto L_0x0042d20c;
    }
    // 0042d1fc  c7056456490001000000   -mov dword ptr [0x495664], 1
    app->getMemory<x86::reg32>(x86::reg32(4806244) /* 0x495664 */) = 1 /*0x1*/;
    // 0042d206  ff255c004300           -jmp dword ptr [0x43005c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4391004), cpu);
L_0x0042d20c:
    // 0042d20c  83f8fc                 +cmp eax, -4
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
    // 0042d20f  750f                   -jne 0x42d220
    if (!cpu.flags.zf)
    {
        goto L_0x0042d220;
    }
    // 0042d211  a18c564900             -mov eax, dword ptr [0x49568c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806284) /* 0x49568c */);
    // 0042d216  c7056456490001000000   -mov dword ptr [0x495664], 1
    app->getMemory<x86::reg32>(x86::reg32(4806244) /* 0x495664 */) = 1 /*0x1*/;
L_0x0042d220:
    // 0042d220  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d221(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d221  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042d225  2da4030000             +sub eax, 0x3a4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042d22a  7422                   -je 0x42d24e
    if (cpu.flags.zf)
    {
        goto L_0x0042d24e;
    }
    // 0042d22c  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042d22f  7417                   -je 0x42d248
    if (cpu.flags.zf)
    {
        goto L_0x0042d248;
    }
    // 0042d231  83e80d                 +sub eax, 0xd
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042d234  740c                   -je 0x42d242
    if (cpu.flags.zf)
    {
        goto L_0x0042d242;
    }
    // 0042d236  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d237  7403                   -je 0x42d23c
    if (cpu.flags.zf)
    {
        goto L_0x0042d23c;
    }
    // 0042d239  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d23b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d23c:
    // 0042d23c  b804040000             -mov eax, 0x404
    cpu.eax = 1028 /*0x404*/;
    // 0042d241  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d242:
    // 0042d242  b812040000             -mov eax, 0x412
    cpu.eax = 1042 /*0x412*/;
    // 0042d247  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d248:
    // 0042d248  b804080000             -mov eax, 0x804
    cpu.eax = 2052 /*0x804*/;
    // 0042d24d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d24e:
    // 0042d24e  b811040000             -mov eax, 0x411
    cpu.eax = 1041 /*0x411*/;
    // 0042d253  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d254  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d255  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0042d257  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d258  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d25a  bfe05b4900             -mov edi, 0x495be0
    cpu.edi = 4807648 /*0x495be0*/;
    // 0042d25f  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042d261  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0042d262  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d264  bfd05a4900             -mov edi, 0x495ad0
    cpu.edi = 4807376 /*0x495ad0*/;
    // 0042d269  a3cc5a4900             -mov dword ptr [0x495acc], eax
    app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */) = cpu.eax;
    // 0042d26e  a3dc5a4900             -mov dword ptr [0x495adc], eax
    app->getMemory<x86::reg32>(x86::reg32(4807388) /* 0x495adc */) = cpu.eax;
    // 0042d273  a3e45c4900             -mov dword ptr [0x495ce4], eax
    app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */) = cpu.eax;
    // 0042d278  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042d279  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042d27a  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0042d27b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d27c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d27d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d27d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d27e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0042d280  81ec14050000           -sub esp, 0x514
    (cpu.esp) -= x86::reg32(x86::sreg32(1300 /*0x514*/));
    // 0042d286  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042d289  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d28a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d28b  ff35cc5a4900           -push dword ptr [0x495acc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */);
    cpu.esp -= 4;
    // 0042d291  ff1560004300           -call dword ptr [0x430060]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4391008) /* 0x430060 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d297  83f801                 +cmp eax, 1
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
    // 0042d29a  0f8516010000           -jne 0x42d3b6
    if (!cpu.flags.zf)
    {
        goto L_0x0042d3b6;
    }
    // 0042d2a0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d2a2  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
L_0x0042d2a7:
    // 0042d2a7  888405ecfeffff         -mov byte ptr [ebp + eax - 0x114], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-276) /* -0x114 */ + cpu.eax * 1) = cpu.al;
    // 0042d2ae  40                     -inc eax
    (cpu.eax)++;
    // 0042d2af  3bc6                   +cmp eax, esi
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
    // 0042d2b1  72f4                   -jb 0x42d2a7
    if (cpu.flags.cf)
    {
        goto L_0x0042d2a7;
    }
    // 0042d2b3  8a45f2                 -mov al, byte ptr [ebp - 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 0042d2b6  c685ecfeffff20         -mov byte ptr [ebp - 0x114], 0x20
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-276) /* -0x114 */) = 32 /*0x20*/;
    // 0042d2bd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042d2bf  7437                   -je 0x42d2f8
    if (cpu.flags.zf)
    {
        goto L_0x0042d2f8;
    }
    // 0042d2c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d2c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d2c3  8d55f3                 -lea edx, [ebp - 0xd]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-13) /* -0xd */);
L_0x0042d2c6:
    // 0042d2c6  0fb60a                 -movzx ecx, byte ptr [edx]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.edx));
    // 0042d2c9  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0042d2cc  3bc1                   +cmp eax, ecx
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
    // 0042d2ce  771d                   -ja 0x42d2ed
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042d2ed;
    }
    // 0042d2d0  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d2d2  8dbc05ecfeffff         -lea edi, [ebp + eax - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */ + cpu.eax * 1);
    // 0042d2d9  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d2da  b820202020             -mov eax, 0x20202020
    cpu.eax = 538976288 /*0x20202020*/;
    // 0042d2df  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042d2e1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042d2e4  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042d2e6  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042d2e8  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042d2eb  f3aa                   -rep stosb byte ptr es:[edi], al
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
L_0x0042d2ed:
    // 0042d2ed  42                     -inc edx
    (cpu.edx)++;
    // 0042d2ee  42                     -inc edx
    (cpu.edx)++;
    // 0042d2ef  8a42ff                 -mov al, byte ptr [edx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0042d2f2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042d2f4  75d0                   -jne 0x42d2c6
    if (!cpu.flags.zf)
    {
        goto L_0x0042d2c6;
    }
    // 0042d2f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d2f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042d2f8:
    // 0042d2f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042d2fa  8d85ecfaffff           -lea eax, [ebp - 0x514]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 0042d300  ff35e45c4900           -push dword ptr [0x495ce4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */);
    cpu.esp -= 4;
    // 0042d306  ff35cc5a4900           -push dword ptr [0x495acc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */);
    cpu.esp -= 4;
    // 0042d30c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d30d  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0042d313  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d314  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d315  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d317  e843040000             -call 0x42d75f
    cpu.esp -= 4;
    sub_42d75f(app, cpu);
    // 0042d31c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042d31e  8d85ecfdffff           -lea eax, [ebp - 0x214]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-532) /* -0x214 */);
    // 0042d324  ff35cc5a4900           -push dword ptr [0x495acc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */);
    cpu.esp -= 4;
    // 0042d32a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d32b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d32c  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0042d332  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d333  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d334  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d335  ff35e45c4900           -push dword ptr [0x495ce4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */);
    cpu.esp -= 4;
    // 0042d33b  e868050000             -call 0x42d8a8
    cpu.esp -= 4;
    sub_42d8a8(app, cpu);
    // 0042d340  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042d342  8d85ecfcffff           -lea eax, [ebp - 0x314]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-788) /* -0x314 */);
    // 0042d348  ff35cc5a4900           -push dword ptr [0x495acc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807372) /* 0x495acc */);
    cpu.esp -= 4;
    // 0042d34e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d34f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d350  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0042d356  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d357  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d358  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0042d35d  ff35e45c4900           -push dword ptr [0x495ce4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4807908) /* 0x495ce4 */);
    cpu.esp -= 4;
    // 0042d363  e840050000             -call 0x42d8a8
    cpu.esp -= 4;
    sub_42d8a8(app, cpu);
    // 0042d368  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0042d36b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d36d  8d8decfaffff           -lea ecx, [ebp - 0x514]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
L_0x0042d373:
    // 0042d373  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 0042d376  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0042d379  7416                   -je 0x42d391
    if (cpu.flags.zf)
    {
        goto L_0x0042d391;
    }
    // 0042d37b  8088e15b490010         +or byte ptr [eax + 0x495be1], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0042d382  8a9405ecfdffff         -mov dl, byte ptr [ebp + eax - 0x214]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-532) /* -0x214 */ + cpu.eax * 1);
L_0x0042d389:
    // 0042d389  8890e05a4900           -mov byte ptr [eax + 0x495ae0], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807392) /* 0x495ae0 */) = cpu.dl;
    // 0042d38f  eb1c                   -jmp 0x42d3ad
    goto L_0x0042d3ad;
L_0x0042d391:
    // 0042d391  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0042d394  7410                   -je 0x42d3a6
    if (cpu.flags.zf)
    {
        goto L_0x0042d3a6;
    }
    // 0042d396  8088e15b490020         +or byte ptr [eax + 0x495be1], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0042d39d  8a9405ecfcffff         -mov dl, byte ptr [ebp + eax - 0x314]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-788) /* -0x314 */ + cpu.eax * 1);
    // 0042d3a4  ebe3                   -jmp 0x42d389
    goto L_0x0042d389;
L_0x0042d3a6:
    // 0042d3a6  80a0e05a490000         -and byte ptr [eax + 0x495ae0], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807392) /* 0x495ae0 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042d3ad:
    // 0042d3ad  40                     -inc eax
    (cpu.eax)++;
    // 0042d3ae  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d3af  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d3b0  3bc6                   +cmp eax, esi
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
    // 0042d3b2  72bf                   -jb 0x42d373
    if (cpu.flags.cf)
    {
        goto L_0x0042d373;
    }
    // 0042d3b4  eb49                   -jmp 0x42d3ff
    goto L_0x0042d3ff;
L_0x0042d3b6:
    // 0042d3b6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d3b8  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
L_0x0042d3bd:
    // 0042d3bd  83f841                 +cmp eax, 0x41
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
    // 0042d3c0  7219                   -jb 0x42d3db
    if (cpu.flags.cf)
    {
        goto L_0x0042d3db;
    }
    // 0042d3c2  83f85a                 +cmp eax, 0x5a
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
    // 0042d3c5  7714                   -ja 0x42d3db
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042d3db;
    }
    // 0042d3c7  8088e15b490010         -or byte ptr [eax + 0x495be1], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0042d3ce  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0042d3d0  80c120                 +add cl, 0x20
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0042d3d3:
    // 0042d3d3  8888e05a4900           -mov byte ptr [eax + 0x495ae0], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807392) /* 0x495ae0 */) = cpu.cl;
    // 0042d3d9  eb1f                   -jmp 0x42d3fa
    goto L_0x0042d3fa;
L_0x0042d3db:
    // 0042d3db  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d3de  7213                   -jb 0x42d3f3
    if (cpu.flags.cf)
    {
        goto L_0x0042d3f3;
    }
    // 0042d3e0  83f87a                 +cmp eax, 0x7a
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
    // 0042d3e3  770e                   -ja 0x42d3f3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042d3f3;
    }
    // 0042d3e5  8088e15b490020         -or byte ptr [eax + 0x495be1], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807649) /* 0x495be1 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0042d3ec  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0042d3ee  80e920                 +sub cl, 0x20
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042d3f1  ebe0                   -jmp 0x42d3d3
    goto L_0x0042d3d3;
L_0x0042d3f3:
    // 0042d3f3  80a0e05a490000         -and byte ptr [eax + 0x495ae0], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4807392) /* 0x495ae0 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x0042d3fa:
    // 0042d3fa  40                     -inc eax
    (cpu.eax)++;
    // 0042d3fb  3bc6                   +cmp eax, esi
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
    // 0042d3fd  72be                   -jb 0x42d3bd
    if (cpu.flags.cf)
    {
        goto L_0x0042d3bd;
    }
L_0x0042d3ff:
    // 0042d3ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d400  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d401  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d402(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d402  833d085e490000         +cmp dword ptr [0x495e08], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4808200) /* 0x495e08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d409  7512                   -jne 0x42d41d
    if (!cpu.flags.zf)
    {
        goto L_0x0042d41d;
    }
    // 0042d40b  6afd                   -push -3
    app->getMemory<x86::reg32>(cpu.esp-4) = -3 /*-0x3*/;
    cpu.esp -= 4;
    // 0042d40d  e82cfcffff             -call 0x42d03e
    cpu.esp -= 4;
    sub_42d03e(app, cpu);
    // 0042d412  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d413  c705085e490001000000   -mov dword ptr [0x495e08], 1
    app->getMemory<x86::reg32>(x86::reg32(4808200) /* 0x495e08 */) = 1 /*0x1*/;
L_0x0042d41d:
    // 0042d41d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_42d41e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d41e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d41f  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d421  391d68564900           +cmp dword ptr [0x495668], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4806248) /* 0x495668 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d427  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d428  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d429  7542                   -jne 0x42d46d
    if (!cpu.flags.zf)
    {
        goto L_0x0042d46d;
    }
    // 0042d42b  68900e4300             -push 0x430e90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394640 /*0x430e90*/;
    cpu.esp -= 4;
    // 0042d430  ff1554004300           -call dword ptr [0x430054]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4390996) /* 0x430054 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d436  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042d438  3bfb                   +cmp edi, ebx
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
    // 0042d43a  7467                   -je 0x42d4a3
    if (cpu.flags.zf)
    {
        goto L_0x0042d4a3;
    }
    // 0042d43c  8b35f8004300           -mov esi, dword ptr [0x4300f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4391160) /* 0x4300f8 */);
    // 0042d442  68840e4300             -push 0x430e84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394628 /*0x430e84*/;
    cpu.esp -= 4;
    // 0042d447  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d448  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d44a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d44c  a368564900             -mov dword ptr [0x495668], eax
    app->getMemory<x86::reg32>(x86::reg32(4806248) /* 0x495668 */) = cpu.eax;
    // 0042d451  7450                   -je 0x42d4a3
    if (cpu.flags.zf)
    {
        goto L_0x0042d4a3;
    }
    // 0042d453  68740e4300             -push 0x430e74
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394612 /*0x430e74*/;
    cpu.esp -= 4;
    // 0042d458  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d459  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d45b  68600e4300             -push 0x430e60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4394592 /*0x430e60*/;
    cpu.esp -= 4;
    // 0042d460  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d461  a36c564900             -mov dword ptr [0x49566c], eax
    app->getMemory<x86::reg32>(x86::reg32(4806252) /* 0x49566c */) = cpu.eax;
    // 0042d466  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d468  a370564900             -mov dword ptr [0x495670], eax
    app->getMemory<x86::reg32>(x86::reg32(4806256) /* 0x495670 */) = cpu.eax;
L_0x0042d46d:
    // 0042d46d  a16c564900             -mov eax, dword ptr [0x49566c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806252) /* 0x49566c */);
    // 0042d472  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d474  7416                   -je 0x42d48c
    if (cpu.flags.zf)
    {
        goto L_0x0042d48c;
    }
    // 0042d476  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d478  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042d47a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042d47c  740e                   -je 0x42d48c
    if (cpu.flags.zf)
    {
        goto L_0x0042d48c;
    }
    // 0042d47e  a170564900             -mov eax, dword ptr [0x495670]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4806256) /* 0x495670 */);
    // 0042d483  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d485  7405                   -je 0x42d48c
    if (cpu.flags.zf)
    {
        goto L_0x0042d48c;
    }
    // 0042d487  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d488  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d48a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0042d48c:
    // 0042d48c  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d490  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d494  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0042d498  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d499  ff1568564900           -call dword ptr [0x495668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4806248) /* 0x495668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042d49f:
    // 0042d49f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d4a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d4a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d4a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d4a3:
    // 0042d4a3  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042d4a5  ebf8                   -jmp 0x42d49f
    goto L_0x0042d49f;
}

}
